.global _start
 
.section .text
_start:
    
    la a1, array_size #a1 = address if array_size
    lw a1, 0(a1) #a1 = value of array_size
    jal ra,cal_fib

    # Signal test pass to Spike
    li t0, 1
    la t1, tohost
    sd t0, (t1)
 
    # Loop forever
1:  j 1b

cal_fib:
    la t0, array # address of array 1st element
    la a0, zero # pointing to address of zero
    li t1, 0 #t1 = 1
    la t2, store_array
    
    
while:
    beq t1, a1, return
    li t5, 0; # initialize t5 = 0 on every iteration
    lw t3, 0(a0) #value of prev element in array
    lw t4, 0(t0) # value of next element in array
    add t5, t3, t4 # sum of two values
    sw t5, 0(t2)
    addi a0, a0, 4 #jump to address of next element
    addi t0, t0, 4
    addi t2, t2, 4

    

return:
    ret



.section .data
zero: .word 0
array: .word 1,2,3,4,5
array_size: .word 5
store_array:
 
