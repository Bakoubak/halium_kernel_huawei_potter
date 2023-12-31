/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2012-2015. All rights reserved.
 * foss@huawei.com
 *
 * If distributed as part of the Linux kernel, the following license terms
 * apply:
 *
 * * This program is free software; you can redistribute it and/or modify
 * * it under the terms of the GNU General Public License version 2 and
 * * only version 2 as published by the Free Software Foundation.
 * *
 * * This program is distributed in the hope that it will be useful,
 * * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * * GNU General Public License for more details.
 * *
 * * You should have received a copy of the GNU General Public License
 * * along with this program; if not, write to the Free Software
 * * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA
 *
 * Otherwise, the following license terms apply:
 *
 * * Redistribution and use in source and binary forms, with or without
 * * modification, are permitted provided that the following conditions
 * * are met:
 * * 1) Redistributions of source code must retain the above copyright
 * *    notice, this list of conditions and the following disclaimer.
 * * 2) Redistributions in binary form must reproduce the above copyright
 * *    notice, this list of conditions and the following disclaimer in the
 * *    documentation and/or other materials provided with the distribution.
 * * 3) Neither the name of Huawei nor the names of its contributors may
 * *    be used to endorse or promote products derived from this software
 * *    without specific prior written permission.
 *
 * * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef __DUMP_MODEM_SAVE_H__
#define __DUMP_MODEM_SAVE_H__
#include <linux/semaphore.h>
#include "osl_types.h"
#include "mdrv_rfile_common.h"


#define OM_DUMP_PATH            (MODEM_LOG_ROOT"/drv/onoff/")
#define OM_RESET_LOG            (MODEM_LOG_ROOT"/drv/onoff/reset.log")
#define OM_RESET_LOG_MAX        2048

#define DUMP_TASK_JOB_RESET_LOG             (0x00000001)
#define DUMP_TASK_JOB_SAVE                  (0x00000002)
#define DUMP_TASK_JOB_INIT                  (0x00000004)
#define DUMP_TASK_JOB_REBOOT                (0x00000008)
#define DUMP_TASK_JOB_SAVE_INIT             (DUMP_TASK_JOB_SAVE | DUMP_TASK_JOB_INIT)
#define DUMP_TASK_JOB_SAVE_REBOOT           (DUMP_TASK_JOB_SAVE | DUMP_TASK_JOB_REBOOT)


typedef struct _dump_ctrl_s
{
    uintptr_t dump_task_id;
    u32 dump_task_job;
    u32 current_task_info;           /*0xA0 */
    struct semaphore sem_dump_task;
}modem_dump_ctrl_s;
void dump_map_mdm_ddr(void);
void dump_save_mdm_ddr_file(char* dir_name);
void dump_save_mdm_dts_file(char* dir_name);
void dump_save_mdm_sram_file(char* dir_name);
void dump_save_mdm_secshare_file(char* dir_name);
void dump_save_mdm_share_file(char* dir_name);
void dump_save_mdm_llram_file(char* dir_name);
void dump_optional_log_init(void);


void dump_save_mandatory_logs(char* dir_name);
void dump_save_mntn_bin(char* dir_name);

#endif

