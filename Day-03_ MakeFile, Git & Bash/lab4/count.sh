ls -l --time-style=+%Y-%m-%d | awk '{print $6,$3,$7}'>log.txt
echo "number of lines:"
wc -l <log.txt
echo "number of words:"
wc -w <log.txt
echo "number of bytes:"
wc -c <log.txt
echo "user names in log.txt"
awk '{print $2}' log.txt | sort -u
echo "actions:"
awk '{print $2}' log.txt | sort | uniq -c


