.global _start
 
.section .text
_start:
    # Any code here
    li a0, 42
    li a1,-46
    sub a2, a0, a1
    blt a2, 0, make_positive
    j done

    make_positive:
    sub a2, x0, a2

    done:
    
    # Code to exit for Spike (DONT REMOVE IT)
    li t0, 1
    la t1, tohost
    sd t0, (t1)
 
    # Loop forever if spike does not exit
1:  j 1b
 
.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0
