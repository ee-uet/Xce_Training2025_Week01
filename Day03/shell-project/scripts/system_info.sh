#!/bin/bash

get_disk_usage() {
    df -h | head -n 5
}

get_memory_info() {
    free -h
}