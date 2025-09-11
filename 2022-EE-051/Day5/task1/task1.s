    .global _start          

    .section .text         
_start:
    li x1,43                # x1 = dividend (43)
    li x2,0                 # x2 = quotient (initially 0)
    li x3,0                 # x3 = remainder (initially 0)
    li x4,4                 # x4 = divisor (4)
    li x5,31                # x5 = loop counter, start from MSB (bit 31)

# Main division loop
loop:
    slli x3,x3,1            # rem <<= 1  (shift remainder left by 1)
    srl  x6,x1,x5           # x6 = (dividend >> i)  (extract current dividend bit)
    andi x6,x6,1            # keep only LSB (current bit value)
    or   x3,x3,x6           # rem = (rem << 1) | current_bit

    slli x2,x2,1            # q <<= 1 

    sub  x7,x3,x4           # x7 = rem - divisor (trial subtraction)
    mv   x3,x7              # rem = trial result (may be negative)
    blt  x7,zero,restore    # if result < 0,subtraction failed, restore remainder

    ori  x2,x2,1            # if subtraction worked then set quotient LSB = 1
    j cont                  # jump to continue

# Restore step
restore:
    add  x3,x3,x4           # rem = rem + divisor (undo subtraction)
                            # quotient bit remains 0 in this case

# Loop control
cont:
    addi x5,x5,-1           
    bge  x5,zero,loop      

done:
    # send quotient to host 
    la   x7,tohost
    sw   x2,0(x7)           # write quotient

    # send remainder to host
    sw   x3,0(x7)           # write remainder 

1:  j 1b

    .section .tohost,"aw",@progbits
    .align 3
tohost:   .dword 0          
fromhost: .dword 0
