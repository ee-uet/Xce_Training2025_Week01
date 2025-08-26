#!/bin/bash
filename="text_file.txt"
n=1
while read -r line; do
    echo "$n: $line"
	n=$((n+1))
done < "$filename"

file="log.txt"
echo "Total entries: $(wc -l < $file)"
echo "Unique users:"
cut -d' ' -f2 $file | sort | uniq
echo "Actions per user:"
cut -d' ' -f2 $file | sort | uniq -c

src_dir="$1"
if [ ! -d "$src_dir" ]; then
    echo "Error: Directory '$src_dir' does not exist."
    exit 1
fi

date_str=$(date +%F)

backup_file="${src_dir##*/}_backup_${date_str}.tar.gz"

tar -czf "$backup_file" -C "$src_dir" .

if [ $? -eq 0 ]; then
    echo "Backup created successfully: $backup_file"
else
    echo "Error: Backup failed."
    exit 1
fi


