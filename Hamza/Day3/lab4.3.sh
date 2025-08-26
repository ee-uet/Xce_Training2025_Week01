#!/bin/bash
if [ -z "$1" ]; then
    echo "Kahan ka backup chahiye? Directory ka naam batao."
    exit 1
fi

if [ ! -d "$1" ]; then
    echo "Arey bhai, ye directory to hai hi nahi!"
    exit 1
fi

backup_dir="backup-$(date +%Y-%m-%d)"
tar -czf "$backup_dir.tar.gz" "$1"

echo "Mubarak ho! $1 ka backup ban gaya, naam hai: $backup_dir.tar.gz"
