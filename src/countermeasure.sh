#!/usr/bin/env bash


sudo /sbin/ausearch -f /home/aayush/trap.py | more | grep -o ' pid=[0-9]* ' | grep -v 'grep' | sed 's/\ pid=//' | tr '\n' ' ' | xargs kill
notify-send -i applications-development "Process killed"

# bash /home/aayush/audit.sh
# sudo find /proc/ -wholename /home/aayush/trap.py > log2.txt
# sudo lsof -t /home/aayush/trap.py > log.txt
# sudo kill -9 `sudo lsof -t /home/aayush/trap.py`
# pid=`lsof -e /run/user/1000/gvfs /trap_pipe.py | tr -s " " | cut -d " " -f 2`
# echo "$pid"
# sudo kill -9 $pid

# notify-send -i applications-development "Process killed"
# kill -9 $pid