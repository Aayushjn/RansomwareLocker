#!/usr/bin/env bash

sudo kill -9 `sudo lsof -t /home/aayush/bash-ransomware/crypto.sh`
# pid=`lsof -e /run/user/1000/gvfs /trap_pipe.py | tr -s " " | cut -d " " -f 2`
# echo "$pid"
# sudo kill -9 $pid

notify-send -i applications-development "Process killed"
# kill -9 $pid