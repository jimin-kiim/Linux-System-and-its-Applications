/* SPDX-License-Identifier: GPL-2.0
 *
 * soc-component.h
 *
 * Copyright (c) 2019 Kuninori Morimoto <kuninori.morimoto.gx@renesas.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
#ifndef __SOC_COMPONENT_H
#define __SOC_COMPONENT_H

#include <sound/soc.h>


#define SND_SOC_COMP_ORDER_FIRST	-2
#define SND_SOC_COMP_ORDER_EARLY	-1
#define SND_SOC_COMP_ORDER_NORMAL	 0
#define SND_SOC_COMP_ORDER_LATE		 1
#define SND_SOC_COMP_ORDER_LAST		 2

#define for_each_comp_order(order)		\
	for (order  = SND_SOC_COMP_ORDER_FIRST;	\
	     order <= SND_SOC_COMP_ORDER_LAST;	\
	     order++)


struct snd_soc_component_driver {
	const char *name;

	
	const struct snd_kcontrol_new *controls;
	unsigned int num_controls;
	const struct snd_soc_dapm_widget *dapm_widgets;
	unsigned int num_dapm_widgets;
	const struct snd_soc_dapm_route *dapm_routes;
	unsigned int num_dapm_routes;

	int (*probe)(struct snd_soc_component *component);
	void (*remove)(struct snd_soc_component *component);
	int (*suspend)(struct snd_soc_component *component);
	int (*resume)(struct snd_soc_component *component);

	unsigned int (*read)(struct snd_soc_component *component,
			     unsigned int reg);
	int (*write)(struct snd_soc_component *component,
		     unsigned int reg, unsigned int val);

	
	int (*pcm_new)(struct snd_soc_pcm_runtime *rtd);
	void (*pcm_free)(struct snd_pcm *pcm);

	
	int (*set_sysclk)(struct snd_soc_component *component,
			  int clk_id, int source, unsigned int freq, int dir);
	int (*set_pll)(struct snd_soc_component *component, int pll_id,
		       int source, unsigned int freq_in, unsigned int freq_out);
	int (*set_jack)(struct snd_soc_component *component,
			struct snd_soc_jack *jack,  void *data);

	
	int (*of_xlate_dai_name)(struct snd_soc_component *component,
				 struct of_phandle_args *args,
				 const char **dai_name);
	int (*of_xlate_dai_id)(struct snd_soc_component *comment,
			       struct device_node *endpoint);
	void (*seq_notifier)(struct snd_soc_component *component,
			     enum snd_soc_dapm_type type, int subseq);
	int (*stream_event)(struct snd_soc_component *component, int event);
	int (*set_bias_level)(struct snd_soc_component *component,
			      enum snd_soc_bias_level level);

	const struct snd_pcm_ops *ops;
	const struct snd_compr_ops *compr_ops;

	
	int probe_order;
	int remove_order;

	
	unsigned int module_get_upon_open:1;

	
	unsigned int idle_bias_on:1;
	unsigned int suspend_bias_off:1;
	unsigned int use_pmdown_time:1; 
	unsigned int endianness:1;
	unsigned int non_legacy_dai_naming:1;

	
	const char *ignore_machine;
	const char *topology_name_prefix;
	int (*be_hw_params_fixup)(struct snd_soc_pcm_runtime *rtd,
				  struct snd_pcm_hw_params *params);
	bool use_dai_pcm_id;	
	int be_pcm_base;	
};

struct snd_soc_component {
	const char *name;
	int id;
	const char *name_prefix;
	struct device *dev;
	struct snd_soc_card *card;

	unsigned int active;

	unsigned int suspended:1; 

	struct list_head list;
	struct list_head card_aux_list; 
	struct list_head card_list;

	const struct snd_soc_component_driver *driver;

	struct list_head dai_list;
	int num_dai;

	struct regmap *regmap;
	int val_bytes;

	struct mutex io_mutex;

	
	struct list_head dobj_list;

	

	
	struct snd_soc_dapm_context dapm;

	
	int (*init)(struct snd_soc_component *component);

#ifdef CONFIG_DEBUG_FS
	struct dentry *debugfs_root;
	const char *debugfs_prefix;
#endif
};

#define for_each_component_dais(component, dai)\
	list_for_each_entry(dai, &(component)->dai_list, list)
#define for_each_component_dais_safe(component, dai, _dai)\
	list_for_each_entry_safe(dai, _dai, &(component)->dai_list, list)


static inline struct snd_soc_component *snd_soc_dapm_to_component(
	struct snd_soc_dapm_context *dapm)
{
	return container_of(dapm, struct snd_soc_component, dapm);
}


static inline struct snd_soc_dapm_context *snd_soc_component_get_dapm(
	struct snd_soc_component *component)
{
	return &component->dapm;
}


static inline void
snd_soc_component_init_bias_level(struct snd_soc_component *component,
				  enum snd_soc_bias_level level)
{
	snd_soc_dapm_init_bias_level(
		snd_soc_component_get_dapm(component), level);
}


static inline enum snd_soc_bias_level
snd_soc_component_get_bias_level(struct snd_soc_component *component)
{
	return snd_soc_dapm_get_bias_level(
		snd_soc_component_get_dapm(component));
}


static inline int
snd_soc_component_force_bias_level(struct snd_soc_component *component,
				   enum snd_soc_bias_level level)
{
	return snd_soc_dapm_force_bias_level(
		snd_soc_component_get_dapm(component),
		level);
}


static inline struct snd_soc_component *snd_soc_dapm_kcontrol_component(
	struct snd_kcontrol *kcontrol)
{
	return snd_soc_dapm_to_component(snd_soc_dapm_kcontrol_dapm(kcontrol));
}


static inline int snd_soc_component_cache_sync(
	struct snd_soc_component *component)
{
	return regcache_sync(component->regmap);
}


int snd_soc_component_read(struct snd_soc_component *component,
			   unsigned int reg, unsigned int *val);
unsigned int snd_soc_component_read32(struct snd_soc_component *component,
				      unsigned int reg);
int snd_soc_component_write(struct snd_soc_component *component,
			    unsigned int reg, unsigned int val);
int snd_soc_component_update_bits(struct snd_soc_component *component,
				  unsigned int reg, unsigned int mask,
				  unsigned int val);
int snd_soc_component_update_bits_async(struct snd_soc_component *component,
					unsigned int reg, unsigned int mask,
					unsigned int val);
void snd_soc_component_async_complete(struct snd_soc_component *component);
int snd_soc_component_test_bits(struct snd_soc_component *component,
				unsigned int reg, unsigned int mask,
				unsigned int value);


int snd_soc_component_set_sysclk(struct snd_soc_component *component,
				 int clk_id, int source,
				 unsigned int freq, int dir);
int snd_soc_component_set_pll(struct snd_soc_component *component, int pll_id,
			      int source, unsigned int freq_in,
			      unsigned int freq_out);
int snd_soc_component_set_jack(struct snd_soc_component *component,
			       struct snd_soc_jack *jack, void *data);

void snd_soc_component_seq_notifier(struct snd_soc_component *component,
				    enum snd_soc_dapm_type type, int subseq);
int snd_soc_component_stream_event(struct snd_soc_component *component,
				   int event);
int snd_soc_component_set_bias_level(struct snd_soc_component *component,
				     enum snd_soc_bias_level level);

#ifdef CONFIG_REGMAP
void snd_soc_component_init_regmap(struct snd_soc_component *component,
				   struct regmap *regmap);
void snd_soc_component_exit_regmap(struct snd_soc_component *component);
#endif

#define snd_soc_component_module_get_when_probe(component)\
	snd_soc_component_module_get(component, 0)
#define snd_soc_component_module_get_when_open(component)	\
	snd_soc_component_module_get(component, 1)
int snd_soc_component_module_get(struct snd_soc_component *component,
				 int upon_open);
#define snd_soc_component_module_put_when_remove(component)	\
	snd_soc_component_module_put(component, 0)
#define snd_soc_component_module_put_when_close(component)	\
	snd_soc_component_module_put(component, 1)
void snd_soc_component_module_put(struct snd_soc_component *component,
				  int upon_open);

static inline void snd_soc_component_set_drvdata(struct snd_soc_component *c,
						 void *data)
{
	dev_set_drvdata(c->dev, data);
}

static inline void *snd_soc_component_get_drvdata(struct snd_soc_component *c)
{
	return dev_get_drvdata(c->dev);
}

static inline bool snd_soc_component_is_active(
	struct snd_soc_component *component)
{
	return component->active != 0;
}


int snd_soc_component_enable_pin(struct snd_soc_component *component,
				 const char *pin);
int snd_soc_component_enable_pin_unlocked(struct snd_soc_component *component,
					  const char *pin);
int snd_soc_component_disable_pin(struct snd_soc_component *component,
				  const char *pin);
int snd_soc_component_disable_pin_unlocked(struct snd_soc_component *component,
					   const char *pin);
int snd_soc_component_nc_pin(struct snd_soc_component *component,
			     const char *pin);
int snd_soc_component_nc_pin_unlocked(struct snd_soc_component *component,
				      const char *pin);
int snd_soc_component_get_pin_status(struct snd_soc_component *component,
				     const char *pin);
int snd_soc_component_force_enable_pin(struct snd_soc_component *component,
				       const char *pin);
int snd_soc_component_force_enable_pin_unlocked(
	struct snd_soc_component *component,
	const char *pin);


int snd_soc_component_open(struct snd_soc_component *component,
			   struct snd_pcm_substream *substream);
int snd_soc_component_close(struct snd_soc_component *component,
			    struct snd_pcm_substream *substream);
int snd_soc_component_prepare(struct snd_soc_component *component,
			      struct snd_pcm_substream *substream);
int snd_soc_component_hw_params(struct snd_soc_component *component,
				struct snd_pcm_substream *substream,
				struct snd_pcm_hw_params *params);
int snd_soc_component_hw_free(struct snd_soc_component *component,
			      struct snd_pcm_substream *substream);
int snd_soc_component_trigger(struct snd_soc_component *component,
			      struct snd_pcm_substream *substream,
			      int cmd);
void snd_soc_component_suspend(struct snd_soc_component *component);
void snd_soc_component_resume(struct snd_soc_component *component);
int snd_soc_component_is_suspended(struct snd_soc_component *component);
int snd_soc_component_probe(struct snd_soc_component *component);
void snd_soc_component_remove(struct snd_soc_component *component);
int snd_soc_component_of_xlate_dai_id(struct snd_soc_component *component,
				      struct device_node *ep);
int snd_soc_component_of_xlate_dai_name(struct snd_soc_component *component,
					struct of_phandle_args *args,
					const char **dai_name);

int snd_soc_pcm_component_pointer(struct snd_pcm_substream *substream);
int snd_soc_pcm_component_ioctl(struct snd_pcm_substream *substream,
				unsigned int cmd, void *arg);
int snd_soc_pcm_component_copy_user(struct snd_pcm_substream *substream,
				    int channel, unsigned long pos,
				    void __user *buf, unsigned long bytes);
struct page *snd_soc_pcm_component_page(struct snd_pcm_substream *substream,
					unsigned long offset);
int snd_soc_pcm_component_mmap(struct snd_pcm_substream *substream,
			       struct vm_area_struct *vma);
int snd_soc_pcm_component_new(struct snd_pcm *pcm);
void snd_soc_pcm_component_free(struct snd_pcm *pcm);

#endif 
