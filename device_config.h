/*
 * MIT License
 *
 * Copyright (c) 2020 Kirill Kotyagin
 */

#ifndef DEVICE_CONFIG_H
#define DEVICE_CONFIG_H

#include <stdint.h>
#include "gpio.h"
#include "gpion.h"
#include "cdc_config.h"

typedef struct {
    uint32_t        magic;
    cdc_config_t    cdc_config;
    gpio_config_t   gpio_config;
    gpion_pin_t     status_led_pin;
    gpion_pin_t     config_pin;
    uint32_t        crc; /* should be the last member of the struct */
} __wpacked device_config_t;

void device_config_init();
device_config_t *device_config_get();
cdc_port_t *cdc_port_get(int cdc_port);

void device_config_save();
void device_config_reset();

#endif /* DEVICE_CONFIG_H_ */
