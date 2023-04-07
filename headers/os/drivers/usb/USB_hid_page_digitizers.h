/*
 * Copyright 2004-2010, Haiku Inc. All Rights Reserved.
 * Distributed under the terms of the MIT License.
 */
#ifndef _USB_HID_PAGE_DIGITIZERS_H
#define _USB_HID_PAGE_DIGITIZERS_H


/* Reference:
 *		HID Usage Page 0x0D: DIGITIZERS
 *		HID Usage Tables Ver. 1.3
 *		https://usb.org/sites/default/files/hut1_3_0.pdf
 */

// Usage IDs
enum {
	B_HID_UID_DIG_DIGITIZER = 0x1,
	B_HID_UID_DIG_PEN,
	B_HID_UID_DIG_LIGHT_PEN,
	B_HID_UID_DIG_TOUCH_SCREEN,
	B_HID_UID_DIG_TOUCH_PAD,
	B_HID_UID_DIG_WHITE_BOARD,
	B_HID_UID_DIG_COORDINATE_MEASURING_MACHINE,
	B_HID_UID_DIG_3D_DIGITIZER,
	B_HID_UID_DIG_STEREO_PLOTTER,
	B_HID_UID_DIG_ARTICULATED_ARM,
	B_HID_UID_DIG_ARMATURE,
	B_HID_UID_DIG_MULTIPLE_POINT_DIGITIZER,
	B_HID_UID_DIG_FREE_SPACE_WAND,

	B_HID_UID_DIG_STYLUS = 0x20,
	B_HID_UID_DIG_PUCK,
	B_HID_UID_DIG_FINGER,

	B_HID_UID_DIG_TIP_PRESSURE = 0x30,
	B_HID_UID_DIG_BARREL_PRESSURE,
	B_HID_UID_DIG_IN_RANGE,
	B_HID_UID_DIG_TOUCH,
	B_HID_UID_DIG_UNTOUCH,
	B_HID_UID_DIG_TAP,
	B_HID_UID_DIG_QUALITY,
	B_HID_UID_DIG_DATA_VALID,
	B_HID_UID_DIG_TRANSDUCER_INDEX,
	B_HID_UID_DIG_TABLET_FUNCTION_KEYS,
	B_HID_UID_DIG_PROGRAM_CHANGE_KEYS,
	B_HID_UID_DIG_BATTERY_STRENGTH,
	B_HID_UID_DIG_INVERT,
	B_HID_UID_DIG_X_TILT,
	B_HID_UID_DIG_Y_TILT,
	B_HID_UID_DIG_AZIMUTH,
	B_HID_UID_DIG_ALTITUDE,
	B_HID_UID_DIG_TWIST,
	B_HID_UID_DIG_TIP_SWITCH,
	B_HID_UID_DIG_SECONDARY_TIP_SWITCH,
	B_HID_UID_DIG_BARREL_SWITCH,
	B_HID_UID_DIG_ERASER,
	B_HID_UID_DIG_TABLET_PICK,
	B_HID_UID_DIG_TOUCH_VALID,
	B_HID_UID_DIG_WIDTH,
	B_HID_UID_DIG_HEIGHT,

	B_HID_UID_DIG_CONTACT_IDENTIFIER = 0x51,
	B_HID_UID_DIG_DEVICE_MODE,
	B_HID_UID_DIG_DEVICE_IDENTIFIER,
	B_HID_UID_DIG_CONTACT_COUNT,
	B_HID_UID_DIG_CONTACT_COUNT_MAXIMUM,
	B_HID_UID_DIG_SCAN_TIME,
	B_HID_UID_DIG_SURFACE_SWITCH,
	B_HID_UID_DIG_BUTTON_SWITCH,
	B_HID_UID_DIG_PAD_TYPE,
	B_HID_UID_DIG_SECONDARY_BARREL_SWITCH,
	B_HID_UID_DIG_TRANSDUCER_SERIAL_NUMBER,
	B_HID_UID_DIG_PREFERRED_COLOR,
	B_HID_UID_DIG_PREFERRED_COLOR_IS_LOCKED,
	B_HID_UID_DIG_PREFERRED_LINE_WIDTH,
	B_HID_UID_DIG_PREFERRED_LINE_WIDTH_IS_LOCKED,
	B_HID_UID_DIG_LATENCY_MODE,
	B_HID_UID_DIG_GESTURE_CHARACTER_QUALITY,
	B_HID_UID_DIG_GESTURE_CHARACTER_ENCODING,
	B_HID_UID_DIG_GESTURE_CHARACTER_DATA_LENGTH,
	B_HID_UID_DIG_GESTURE_CHARACTER_DATA,
	B_HID_UID_DIG_UTF8_CHARACTER_GESTURE_ENCODING,
	B_HID_UID_DIG_UTF16_LITTLE_ENDIAN_CHARACTER_GESTURE_ENCODING,
	B_HID_UID_DIG_UTF16_BIG_ENDIAN_CHARACTER_GESTURE_ENCODING,
	B_HID_UID_DIG_UTF32_LITTLE_ENDIAN_CHARACTER_GESTURE_ENCODING,
	B_HID_UID_DIG_UTF32_BIG_ENDIAN_CHARACTER_GESTURE_ENCODING,
	B_HID_UID_DIG_CAPACITIVE_HEAT_MAP_PROTOCOL_VENDOR_ID,
	B_HID_UID_DIG_CAPACITIVE_HEAT_MAP_PROTOCOL_VERSION,
	B_HID_UID_DIG_CAPACITIVE_HEAT_MAP_FRAME_DATA,
	B_HID_UID_DIG_GESTURE_CHARACTER_ENABLE,
	B_HID_UID_DIG_TRANSDUCER_SERIAL_NUMBER_PART_2,
	B_HID_UID_DIG_NO_PREFERRED_COLOR,
	B_HID_UID_DIG_PREFERRED_LINE_STYLE,
	B_HID_UID_DIG_PREFERRED_LINE_STYLE_IS_LOCKED,
	B_HID_UID_DIG_INK,
	B_HID_UID_DIG_PENCIL,
	B_HID_UID_DIG_HIGHLIGHTER,
	B_HID_UID_DIG_CHISEL_MARKER,
	B_HID_UID_DIG_BRUSH,
	B_HID_UID_DIG_NO_PREFERENCE,

	B_HID_UID_DIG_DIGITIZER_DIAGNOSTIC = 0x80,
	B_HID_UID_DIG_DIGITIZER_ERROR,
	B_HID_UID_DIG_ERR_NORMAL_STATUS,
	B_HID_UID_DIG_ERR_TRANSDUCERS_EXCEEDED,
	B_HID_UID_DIG_ERR_FULL_TRANS_FEATURES_UNAVAILABLE,
	B_HID_UID_DIG_ERR_CHARGE_LOW,

	B_HID_UID_DIG_TRANSDUCER_SOFTWARE_INFO = 0x90,
	B_HID_UID_DIG_TRANSDUCER_VENDOR_ID,
	B_HID_UID_DIG_TRANSDUCER_PRODUCT_ID,
	B_HID_UID_DIG_DEVICE_SUPPORTED_PROTOCOLS,
	B_HID_UID_DIG_TRANSDUCER_SUPPORTED_PROTOCOLS,
	B_HID_UID_DIG_NO_PROTOCOL,
	B_HID_UID_DIG_WACOM_AES_PROTOCOL,
	B_HID_UID_DIG_USI_PROTOCOL,
	B_HID_UID_DIG_MICROSOFT_PEN_PROTOCOL,

	B_HID_UID_DIG_SUPPORTED_REPORT_RATES = 0xA0,
	B_HID_UID_DIG_REPORT_RATE,
	B_HID_UID_DIG_TRANSDUCER_CONNECTED,
	B_HID_UID_DIG_SWITCH_DISABLED,
	B_HID_UID_DIG_SWITCH_UNIMPLEMENTED,
	B_HID_UID_DIG_TRANSDUCER_SWITCHES
};


#endif // _USB_HID_PAGE_DIGITIZERS_H
