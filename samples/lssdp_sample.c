/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: MIT License
 *
 * Change Logs:
 * Date           Author       Notes
 * 2019-05-11     SummerGift   first version
 */

#include <stdio.h>
#include <string.h>
#include "lssdp_service.h"

#define DBG_SECTION_NAME  "lssdp example"
#define DBG_LEVEL         DBG_INFO
#include <rtdbg.h>

// lssdp service add example
static int lssdp_add_example(void)
{
    struct lssdp_service service;
    char service_name        [LSSDP_FIELD_LEN] = "service_name";                // local service name
    char search_target       [LSSDP_FIELD_LEN] = "urn:rt-thread:service:ssdp";  // search name in network
    char unique_service_name [LSSDP_FIELD_LEN] = "unique service name";         // unique service name
    char sm_id               [LSSDP_FIELD_LEN] = "700000123";                   // device id
    char device_type         [LSSDP_FIELD_LEN] = "RT-Thread device";            // device type
    char suffix              [LSSDP_FIELD_LEN] = ":5555";                       // service port

    memcpy(service.name,                      service_name,        LSSDP_FIELD_LEN);
    memcpy(service.info.search_target,        search_target,       LSSDP_FIELD_LEN);
    memcpy(service.info.unique_service_name,  unique_service_name, LSSDP_FIELD_LEN);
    memcpy(service.info.sm_id,                sm_id,               LSSDP_FIELD_LEN);
    memcpy(service.info.device_type,          device_type,         LSSDP_FIELD_LEN);
    memcpy(service.info.suffix,               suffix,              LSSDP_FIELD_LEN);

    if (lssdp_service_add(&service) != 0)
    {
        LOG_E("service %s add failed!", service_name );
    }

    return RT_EOK;
}
MSH_CMD_EXPORT(lssdp_add_example, lssdp add service example);

// lssdp service del example
static int lssdp_del_example(void)
{
    struct lssdp_service service;
    char service_name[LSSDP_FIELD_LEN] = "service_name";
    memcpy(service.name,                      service_name,        LSSDP_FIELD_LEN);
    lssdp_service_del(&service);

    return RT_EOK;
}
MSH_CMD_EXPORT(lssdp_del_example, lssdp del service example);
