#!/bin/bash

. ./scripts/link.sh
qmk compile -j4 -kb planck/ez/glow -km palmdrop
. ./scripts/clean.sh
