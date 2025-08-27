PATH_TO_BACKUP=$1
CUR_DIR=$(pwd)

if [ -d "$PATH_TO_BACKUP" ]; then
    DATE=$(date +%Y-%m-%d)
    backup="$(basename "$CUR_DIR")-backup-$DATE.tar.gz"
    tar -czf "$backup" -C "$(dirname "$CUR_DIR")" "$(basename "$CUR_DIR")"
    mv "$backup" "$PATH_TO_BACKUP"
else
    echo "no directory found"
fi


