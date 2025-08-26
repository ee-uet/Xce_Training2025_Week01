#!/bin/bash

file_name="date_file.log"

cat > "$file_name" << EOF
2021-01-31 abdul101 login
2021-02-31 abdul102 login
2021-03-31 abdul102 log_off
2021-04-31 abdul104 login
2021-05-31 abdul102 terminate
2021-06-31 abdul101 terminate
EOF


total_count=$(wc -l <"$file_name")
echo "Total Entries :$total_count" 

echo "Unique Username:"
awk '{print $2}' "$file_name" | sort | uniq  


echo "Action Count for user"
awk '{count[$2]++} END {for (user in count) print user, count[user]}' "$file_name"