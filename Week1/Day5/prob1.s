    .section .text
    .globl _start

_start:
    # Load two numbers into t0 and t1
    li t0, 40       # First number
    li t1, 15       # Second number

    # Subtract (t0 - t1) and store in t2
    sub t2, t0, t1  

    # If result >= 0, jump to done
    bge t2, x0, done  

    # Else negate to make it positive
    neg t2, t2      

done:
    # Store "test passed" signal into tohost (for Spike)
    li t0, 1
    la t1, tohost
    sd t0, (t1)

    # Infinite loop so Spike doesn’t go crazy
1:  j 1b

# Special section for host communication
.section .tohost
    .align 3
tohost:   .dword 0
fromhost: .dword 0

