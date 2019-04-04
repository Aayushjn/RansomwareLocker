#!/usr/bin/env bash

sudo lsof -t /home/trap.py > log.txt
sudo kill -9 `sudo lsof -t /home/trap.py`
# pid=`lsof -e /run/user/1000/gvfs /trap_pipe.py | tr -s " " | cut -d " " -f 2`
# echo "$pid"
# sudo kill -9 $pid

notify-send -i applications-development "Process killed"
# kill -9 $pid