#!/bin/bash

cat /sys/devices/system/cpu/cpu0/cpufreq/scaling_available_frequencies | tr -s " " "\n" | wc -l
