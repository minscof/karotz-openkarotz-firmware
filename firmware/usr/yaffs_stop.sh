#!/bin/bash
. /karotz/scripts/led_functions.sh

logger -s "Stopping yaffs"
killall immortaldog
if [ $(ls /var/run/karotz/ | wc -w) -gt 0 ]; then
    rm /var/run/karotz/*.pid
fi
led_fixe 000000 

exit 0
