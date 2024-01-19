#!/bin/bash

KEYMAP_DIR="qmk_firmware/keyboards/planck/keymaps/palmdrop"

ln -sf "$(realpath keymap)" "${KEYMAP_DIR}"