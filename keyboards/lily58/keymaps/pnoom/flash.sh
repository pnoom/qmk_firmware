#!/bin/bash

set -eu
set -o pipefail

KEYBOARD_NOT_RESET="ID 04d8:eb2d Microchip Technology, Inc."
KEYBOARD_RESET="ID 03eb:2ff4 Atmel Corp. atmega32u4 DFU bootloader"

if lsusb | grep "$KEYBOARD_NOT_RESET" &> /dev/null
then
    echo "MUST PRESS RESET BUTTON ON LEFT HALF OF KEYBOARD (WITH THAT SIDE PLUGGED INTO USB) BEFORE RUNNING THIS"
    exit 1
else
    cd /home/andy/qmk_firmware

    echo "Compiling and flashing"

    qmk compile

    sudo dfu-programmer atmega32u4 erase 
    sudo dfu-programmer atmega32u4 flash lily58_rev1_pnoom.hex
    sudo dfu-programmer atmega32u4 reset

    echo "Done"
fi
