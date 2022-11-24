/*
 * Copyright (c) 2016-2019, The Linux Foundation. All rights reserved.
 * Copyright (C) 2021 XiaoMi, Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#ifndef _DSI_PANEL_MI_H_
#define _DSI_PANEL_MI_H_

#define PANEL_COMMAND_MAX	38

enum bkl_dimming_state {
	STATE_NONE,
	STATE_DIM_BLOCK,
	STATE_DIM_RESTORE,
	STATE_ALL
};

enum panel_type {
	PANEL_CSOT_NT36672A,
	PANEL_TIANMA_NT36672A,
	PANEL_EBBG_FT8719,
	PANEL_TPYE_MAX
};

enum DISPPARAM_MODE {
	DISPPARAM_WARM = 0x1,
	DISPPARAM_DEFAULT = 0x2,
	DISPPARAM_COLD = 0x3,
	DISPPARAM_PAPERMODE8 = 0x5,
	DISPPARAM_PAPERMODE1 = 0x6,
	DISPPARAM_PAPERMODE2 = 0x7,
	DISPPARAM_PAPERMODE3 = 0x8,
	DISPPARAM_PAPERMODE4 = 0x9,
	DISPPARAM_PAPERMODE5 = 0xA,
	DISPPARAM_PAPERMODE6 = 0xB,
	DISPPARAM_PAPERMODE7 = 0xC,
	DISPPARAM_WHITEPOINT_XY = 0xE,
	DISPPARAM_CE_ON = 0x10,
	DISPPARAM_CE_OFF = 0xF0,
	DISPPARAM_CABCUI_ON = 0x100,
	DISPPARAM_CABCSTILL_ON = 0x200,
	DISPPARAM_CABCMOVIE_ON = 0x300,
	DISPPARAM_CABC_OFF = 0x400,
	DISPPARAM_SKIN_CE_CABCUI_ON = 0x500,
	DISPPARAM_SKIN_CE_CABCSTILL_ON = 0x600,
	DISPPARAM_SKIN_CE_CABCMOVIE_ON = 0x700,
	DISPPARAM_SKIN_CE_CABC_OFF = 0x800,
	DISPPARAM_DIMMING_OFF = 0xE00,
	DISPPARAM_DIMMING = 0xF00,
	DISPPARAM_ACL_L1 = 0x1000,
	DISPPARAM_ACL_L2 = 0x2000,
	DISPPARAM_ACL_L3 = 0x3000,
	DISPPARAM_ACL_OFF = 0xF000,
	DISPPARAM_HBM_ON = 0x10000,
	DISPPARAM_HBM_FOD_ON = 0x20000,
	DISPPARAM_HBM_FOD2NORM = 0x30000,
	DISPPARAM_LCD_HBM_L1_ON = 0xB0000,
	DISPPARAM_LCD_HBM_L2_ON = 0xC0000,
	DISPPARAM_LCD_HBM_L3_ON = 0xD0000,
	DISPPARAM_LCD_HBM_OFF = 0xE0000,
	DISPPARAM_HBM_OFF = 0xF0000,
	DISPPARAM_NORMALMODE1 = 0x100000,
	DISPPARAM_P3 = 0x200000,
	DISPPARAM_SRGB = 0x300000,
	DISPPARAM_SKIN_CE = 0x400000,
	DISPPARAM_SKIN_CE_OFF = 0x500000,
	DISPPARAM_DOZE_BRIGHTNESS_HBM = 0x600000,
	DISPPARAM_DOZE_BRIGHTNESS_LBM = 0x700000,
	DISPPARAM_DOZE_OFF = 0x800000,
	DISPPARAM_HBM_BACKLIGHT_RESEND = 0xA00000,
	DISPPARAM_FOD_BACKLIGHT = 0xD00000,
	DISPPARAM_CRC_OFF = 0xF00000,
	DISPPARAM_FOD_BACKLIGHT_ON = 0x1000000,
	DISPPARAM_FOD_BACKLIGHT_OFF = 0x2000000,
};

struct LCM_setting_table {
	unsigned int cmd;
	unsigned char count;
	unsigned char para_list[64];
};

typedef void (*send_cmd)(void *cmdq, struct LCM_setting_table *table, unsigned int count, unsigned char force_update);
extern int panel_disp_param_send_lock(enum panel_type panel_type,unsigned int param, send_cmd p_func);
#endif /* _DSI_PANEL_MI_H_ */
