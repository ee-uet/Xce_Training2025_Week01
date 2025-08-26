       .global _start

    .section .text
_start:
    # Load test values
    li x1, 10          
    li x3, 25         

    sub x2, x1, x3     
    bge x2, x0, done   
    sub x2, x0, x2   

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
tohost:    .dword 0
fromhost:  .dword 0
