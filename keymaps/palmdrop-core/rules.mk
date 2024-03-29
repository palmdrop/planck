include keyboards/planck/keymaps/$(KEYMAP)/qmk-vim/rules.mk

AUDIO_ENABLE = no

# RGB_MATRIX_ENABLE = no

MOUSEKEY_ENABLE = yes
COMBO_ENABLE = yes
TAP_DANCE_ENABLE = yes 
AUTO_SHIFT_ENABLE = yes
REPEAT_KEY_ENABLE = yes
DYNAMIC_MACRO_ENABLE = yes
CAPS_WORD_ENABLE = yes
LEADER_ENABLE = yes

CONSOLE_ENABLE = yes

SRC += features/layer_lock.c
SRC += features/sentence_case.c

ifeq ($(strip $(AUDIO_ENABLE)), yes)
    SRC += muse.c
endif