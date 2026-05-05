SRC += elpfen.c layer_helpers.c layer_sticky_mods.c switchboard.c lenient_tri_layer.c tap_hold.c

ifeq ($(strip $(TAP_DANCE_ENABLE)), yes)
	SRC += td_helpers.c
endif

COMBO_ENABLE ?= yes
ifeq ($(strip $(COMBO_ENABLE)), yes)
	INTROSPECTION_KEYMAP_C = combos.c
endif

CAPS_WORD_ENABLE = yes

REPEAT_KEY_ENABLE = yes
