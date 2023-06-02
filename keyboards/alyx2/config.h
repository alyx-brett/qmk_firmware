// Copyright 2023 alyx-brett (@alyx-brett)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_ONESHOT

#define ENCODERS_PAD_A { B3 }
#define ENCODERS_PAD_B { B1 }

#define MOUSEKEY_MOVE_DELTA 20

#define CIRQUE_PINNACLE_TAP_ENABLE
#define CIRQUE_PINNACLE_SECONDARY_TAP_ENABLE
#define POINTING_DEVICE_GESTURES_SCROLL_ENABLE
#define POINTING_DEVICE_GESTURES_CURSOR_GLIDE_ENABLE
#define CIRQUE_PINNACLE_POSITION_MODE CIRQUE_PINNACLE_RELATIVE_MODE
