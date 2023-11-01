/* SPDX-License-Identifier: GPL-2.0 */
#ifndef __ASM_TOPOLOGY_H
#define __ASM_TOPOLOGY_H

#include <linux/cpumask.h>

#ifdef CONFIG_NUMA

struct pci_bus;
int pcibus_to_node(struct pci_bus *bus);
#define cpumask_of_pcibus(bus)	(pcibus_to_node(bus) == -1 ?		\
				 cpu_all_mask :				\
				 cpumask_of_node(pcibus_to_node(bus)))

#endif 

#include <linux/arch_topology.h>


#define arch_scale_freq_capacity topology_get_freq_scale


#define arch_scale_cpu_capacity topology_get_cpu_scale


#define arch_update_cpu_topology topology_update_cpu_topology

#include <asm-generic/topology.h>

#endif 
