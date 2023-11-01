// SPDX-License-Identifier: GPL-2.0

#ifndef __LINUX_USB_ROLE_H
#define __LINUX_USB_ROLE_H

#include <linux/device.h>

struct usb_role_switch;

enum usb_role {
	USB_ROLE_NONE,
	USB_ROLE_HOST,
	USB_ROLE_DEVICE,
};

typedef int (*usb_role_switch_set_t)(struct device *dev, enum usb_role role);
typedef enum usb_role (*usb_role_switch_get_t)(struct device *dev);


struct usb_role_switch_desc {
	struct fwnode_handle *fwnode;
	struct device *usb2_port;
	struct device *usb3_port;
	struct device *udc;
	usb_role_switch_set_t set;
	usb_role_switch_get_t get;
	bool allow_userspace_control;
};


#if IS_ENABLED(CONFIG_USB_ROLE_SWITCH)
int usb_role_switch_set_role(struct usb_role_switch *sw, enum usb_role role);
enum usb_role usb_role_switch_get_role(struct usb_role_switch *sw);
struct usb_role_switch *usb_role_switch_get(struct device *dev);
struct usb_role_switch *fwnode_usb_role_switch_get(struct fwnode_handle *node);
void usb_role_switch_put(struct usb_role_switch *sw);

struct usb_role_switch *
usb_role_switch_register(struct device *parent,
			 const struct usb_role_switch_desc *desc);
void usb_role_switch_unregister(struct usb_role_switch *sw);
#else
static inline int usb_role_switch_set_role(struct usb_role_switch *sw,
		enum usb_role role)
{
	return 0;
}

static inline enum usb_role usb_role_switch_get_role(struct usb_role_switch *sw)
{
	return USB_ROLE_NONE;
}

static inline struct usb_role_switch *usb_role_switch_get(struct device *dev)
{
	return ERR_PTR(-ENODEV);
}

static inline struct usb_role_switch *
fwnode_usb_role_switch_get(struct fwnode_handle *node)
{
	return ERR_PTR(-ENODEV);
}

static inline void usb_role_switch_put(struct usb_role_switch *sw) { }

static inline struct usb_role_switch *
usb_role_switch_register(struct device *parent,
			 const struct usb_role_switch_desc *desc)
{
	return ERR_PTR(-ENODEV);
}

static inline void usb_role_switch_unregister(struct usb_role_switch *sw) { }
#endif

#endif 
