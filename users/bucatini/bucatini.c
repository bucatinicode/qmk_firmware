#include "bucatini.h"

static bool grave_esc_reverse_was_shifted = false;

bool process_grave_esc_reverse(uint16_t keycode, keyrecord_t *record) {
  uint8_t shifted = get_mods() & (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT));
  if(record->event.pressed) {
    grave_esc_reverse_was_shifted = shifted;
    add_key(shifted ? KC_ESC : KC_GRAVE);
  } else {
    del_key(grave_esc_reverse_was_shifted ? KC_ESC : KC_GRAVE);
  }
  send_keyboard_report();
  return false;
}
