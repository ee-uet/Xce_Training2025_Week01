.global _start
 
.section .text
_start:

#--------------######################---------------------
#--------------------This is code region------------------
 
    # Load constants
    li t1, 37            # dividend
    li t2, 5             # divisor

    li t3, 0             # quotient = 0
    mv t4, t1            # remainder = dividend

loop:
    blt t4, t2, done     # if remainder < divisor -> exit loop
    sub t4, t4, t2       # remainder -= divisor
    addi t3, t3, 1       # quotient += 1
    j loop

done:
    # At this point:
    # t3 = quotient
    # t4 = remainder

    # -------------------- Print / Store Results -------------------
    # (Optional: if you want to store results in memory instead of registers)
    # la t5, quotient
    # sw t3, 0(t5)
    # la t5, remainder
    # sw t4, 0(t5)

#-------------#######################----------------------

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
