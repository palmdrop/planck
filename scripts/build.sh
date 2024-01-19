#!/bin/bash

. ./scripts/link.sh $1
qmk compile -j4 -kb planck/ez/glow -km palmdrop
. ./scripts/clean.sh
