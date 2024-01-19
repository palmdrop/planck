AUDIO_ENABLE = no
RBGLIGHT_ENABLE = no
COMBO_ENABLE = yes
AUTO_SHIFT_ENABLE = yes

ifeq ($(strip $(AUDIO_ENABLE)), yes)
    SRC += muse.c
endif



