AUDIO_ENABLE = no

RGB_MATRIX_ENABLE = no

COMBO_ENABLE = yes
AUTO_SHIFT_ENABLE = yes

ifeq ($(strip $(AUDIO_ENABLE)), yes)
    SRC += muse.c
endif