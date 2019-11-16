#pragma once

#include "quantum.h"

#define CK_GER GRAVE_ESC_REVERSE

enum custom_keycodes {
  GRAVE_ESC_REVERSE = SAFE_RANGE,
};

bool process_grave_esc_reverse(uint16_t keycode, keyrecord_t *record);
