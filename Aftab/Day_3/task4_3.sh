#!/bin/bash

#Creating a sample folder to back up
mkdir -p myfolder
echo "sample file 1" > myfolder/file1.txt
echo "sample file 2" > myfolder/file2.txt

#Backing up
backup_name="myfolder_backup_$(date +%Y%m%d).tar.gz"

tar -czf "$backup_name" myfolder
echo "Backup created: $backup_name"