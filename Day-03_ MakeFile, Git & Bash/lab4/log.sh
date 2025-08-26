ls -l --time-style=+%Y-%m-%d | awk '{print $6,$3,$7}'>log.txt

while read -r line;do
 echo "$line"
done <log.txt

cat -n log.txt
