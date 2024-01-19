#!/bin/bash

KEYMAP_DIR="qmk_firmware/keyboards/planck/keymaps/palmdrop"

ln -sf "$(realpath keymaps/$1)" "${KEYMAP_DIR}"