#!/usr/bin/env bash

ps aux | grep "/tmp/trap_pipe" | grep -v "grep" | tr -s " " | cut -d " " -f 2 | xargs kill

notify-send -i applications-development "Ransomware killed"