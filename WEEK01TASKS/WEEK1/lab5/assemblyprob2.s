.global _start
 
.section .text
my_number: .word 12345 
_start:
    la x4, my_number      
    lw x1, 0(x4)    
    li a0,0
    
    li a1,1

loop_start:
    andi x2,x1,1
    beq  x2,a1,increment
    j continue
 increment:   
    addi a0,a0,1
continue:
    srli x1,x1,1
    bgt x1, zero, loop_start


 done:
    # Signal test pass to Spike
    li t0, 1
    la t1, tohost
    sd t0, (t1)
 
    # Loop forever
1:  j 1b
 
.section .data
message:
    .string "Hello, World!\n"
 
.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0
   
