.global _start
.section .text

_start:
    # Example inputs
    li t0, 22       # num = 42  (0b101010)
    li t1, 2        # pos = 2
    li t2, 2 #        # choice = 1 (1=set, 2=clear)

    li t3, 1
    sll t3, t3, t1   # mask = 1 << pos

    
    li t4, 1 # if (choice == 1) to set bit
    beq t2, t4, set_bit

   
    li t4, 2   # else if (choice == 2) to clear bit
    beq t2, t4, clear_bit

    j done

set_bit:
    or t0, t0, t3      # num = num | mask
    j done

clear_bit:
    not t3, t3         # ~mask
    and t0, t0, t3     # num = num & ~mask

done:
    # storin result so can check 
    la t5, result
    sw t0, 0(t5)
 
    li t6, 1
    la t5, tohost
    sd t6, 0(t5)

halt:
    j halt

.section .data
result:  .word 0

.section .tohost
.align 3
tohost:  .dword 0
fromhost: .dword 0
