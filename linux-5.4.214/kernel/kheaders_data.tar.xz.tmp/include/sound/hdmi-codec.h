/* SPDX-License-Identifier: GPL-2.0-only */


#ifndef __HDMI_CODEC_H__
#define __HDMI_CODEC_H__

#include <linux/of_graph.h>
#include <linux/hdmi.h>
#include <drm/drm_edid.h>
#include <sound/asoundef.h>
#include <sound/soc.h>
#include <uapi/sound/asound.h>


struct hdmi_codec_daifmt {
	enum {
		HDMI_I2S,
		HDMI_RIGHT_J,
		HDMI_LEFT_J,
		HDMI_DSP_A,
		HDMI_DSP_B,
		HDMI_AC97,
		HDMI_SPDIF,
	} fmt;
	unsigned int bit_clk_inv:1;
	unsigned int frame_clk_inv:1;
	unsigned int bit_clk_master:1;
	unsigned int frame_clk_master:1;
};


struct hdmi_codec_params {
	struct hdmi_audio_infoframe cea;
	struct snd_aes_iec958 iec;
	int sample_rate;
	int sample_width;
	int channels;
};

typedef void (*hdmi_codec_plugged_cb)(struct device *dev,
				      bool plugged);

struct hdmi_codec_pdata;
struct hdmi_codec_ops {
	
	int (*audio_startup)(struct device *dev, void *data);

	
	int (*hw_params)(struct device *dev, void *data,
			 struct hdmi_codec_daifmt *fmt,
			 struct hdmi_codec_params *hparms);

	
	void (*audio_shutdown)(struct device *dev, void *data);

	
	int (*digital_mute)(struct device *dev, void *data, bool enable);

	
	int (*get_eld)(struct device *dev, void *data,
		       uint8_t *buf, size_t len);

	
	int (*get_dai_id)(struct snd_soc_component *comment,
			  struct device_node *endpoint);

	
	int (*hook_plugged_cb)(struct device *dev, void *data,
			       hdmi_codec_plugged_cb fn,
			       struct device *codec_dev);
};


struct hdmi_codec_pdata {
	const struct hdmi_codec_ops *ops;
	uint i2s:1;
	uint spdif:1;
	int max_i2s_channels;
	void *data;
};

struct snd_soc_component;
struct snd_soc_jack;

int hdmi_codec_set_jack_detect(struct snd_soc_component *component,
			       struct snd_soc_jack *jack);

#define HDMI_CODEC_DRV_NAME "hdmi-audio-codec"

#endif 