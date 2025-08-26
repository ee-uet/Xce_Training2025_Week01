.globl _start
.section .data
array:
    .word 5, 3, 4, 1, 2         

.section .text
_start:
    la t0, array         
    li t2, 5             
    li t1, 1             

outer_loop:
    bge t1, t2, done     

    # key = arr[i]
    slli s1, t1, 2       
    add s2, t0, s1       
    lw t3, 0(s2)         

    addi t4, t1, -1      

inner_loop:
    blt t4, zero, insert_key     
    slli s3, t4, 2               
    add s4, t0, s3             
    lw t5, 0(s4)                

    ble t5, t3, insert_key      

    sw t5, 4(s4)                
    addi t4, t4, -1             
    j inner_loop

insert_key:
    slli s3, t4, 2
    add s4, t0, s3
    sw t3, 4(s4)                

    addi t1, t1, 1              
    j outer_loop

done:
    # HTIF exit for Spike
    li t0, 1
    la t1, tohost
    sd t0, 0(t1)

1:  j 1b                       


.section .tohost
.align 3
tohost:   .dword 0
fromhost: .dword 0


