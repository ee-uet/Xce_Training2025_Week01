.text
.global _countbits

count_bits:
    addi t0, x0, 0      
    addi t1, x0, 32   

loop:
    andi t2, a0, 1   
    add  t0, t0, t2  
    srli a0, a0, 1 
    addi t1, t1, -1 
    bnez t1, loop

    mv a0, t0 
    ret