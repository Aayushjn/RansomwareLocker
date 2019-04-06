#!/usr/bin/env bash

sudo /usr/bin/python create_trap_file.py

sudo ln -s $HOME/.aa.pdf /opt/.aa.pdf
sudo ln -s $HOME/.aa.pdf /var/.aa.pdf
sudo ln -s $HOME/.aa.pdf /bin/.aa.pdf
sudo ln -s $HOME/.aa.pdf /sbin/.aa.pdf
sudo ln -s $HOME/.aa.pdf /usr/.aa.pdf
sudo ln -s $HOME/.aa.pdf /.aa.pdf

sudo /sbin/auditctl -w /home/aayush/aa.pdf -p war

while inotifywait -q -e access,attrib,close,open,modify $HOME/.aa.pdf; do
	sudo /sbin/ausearch -f $HOME/.aa.pdf | more | grep -o ' pid=[0-9]* ' | grep -v 'grep' | sed 's/\ pid=//' | tr '\n' ' ' | xargs sudo kill -9 > /dev/null 2>&1
	notify-send -i applications-development "A potentially malicious program was killed"
done