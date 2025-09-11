    .global _start

    .section .text
_start:
    
    li t0, 0x55AA55AA       


    li t1, 3

    li t2, 1
    sll t2, t2, t1          
    or  t0, t0, t2        

    li t2, 1
    sll t2, t2, t1         
    not t2, t2              
    and t0, t0, t2          

    li t3, 1
    la t4, tohost
    sd t3, (t4)

    
1:  j 1b

    .section .tohost
    .align 3
tohost:    .dword 0
fromhost:  .dword 0
