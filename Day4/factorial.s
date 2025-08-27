.section .text
.global _start

_start:

    li a0, 5            # load 5 to a0
    li a1, 1            # load 1 to result (a1)
    li a2, 1            # load 1 to counter (a2)

    loop:
        mul a1, a1, a2              # result = result * counter
        addi a2, a2, 1              # counter += 1
        ble a2, a0, loop            # if counter <= a0 then continue looping
        
    j done                      # jump to done

done:
    # Exit code for Spike
    li t0, 1
    la t1, tohost
    sd t0, (t1)

.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0
