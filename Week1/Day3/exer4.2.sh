#!/bin/bash

logfile="log.txt"

echo "Total entries: $(grep -cve '^\s*$' "$logfile")"
echo "Unique usernames:"
awk '{print $2}' "$logfile" | grep -v '^$' | sort -u
echo "Actions per user:"
awk '{print $2}' "$logfile" | grep -v '^$' | sort | uniq -c

