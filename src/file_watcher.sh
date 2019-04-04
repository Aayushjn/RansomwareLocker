while inotifywait -q -m -e access,attrib,modify /home/aayush/aa.pdf; do
	lsof -t /home/aayush/aa.pdf > log.txt
	notify-send -i applications-development "Accessed"
done