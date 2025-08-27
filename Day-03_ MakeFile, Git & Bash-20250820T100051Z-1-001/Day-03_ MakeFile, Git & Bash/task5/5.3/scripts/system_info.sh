#!/bin/bash
# System information script

show_system_info() {
    echo "=== System Information ==="
    echo "Hostname: $(hostname)"
    echo "OS: $(uname -s)"
    echo "Kernel: $(uname -r)"
    echo "Architecture: $(uname -m)"
    echo "Uptime: $(uptime -p 2>/dev/null || uptime)"
    echo "Memory: $(free -h 2>/dev/null | grep Mem || echo 'Memory info not available')"
    echo "Disk: $(df -h / | tail -1)"
}

show_system_info