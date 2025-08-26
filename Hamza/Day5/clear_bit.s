# a0: number
# a1: bit position (0-31)
# a2: 0 to clear, 1 to set
# a0: result

.data
number: .word 10
position: .word 2
action: .word 1  # 1 to set, 0 to clear
.text
.global main
main:
    lw a0, number
    lw a1, position
    lw a2, action

    li t0, 1            # t0 = 1
    sll t0, t0, a1      # t0 = 1 << position (the mask)

    beq a2, x0, clear_bit # If action is 0, jump to clear
    
    or a0, a0, t0       # Set the bit: number | mask
    j end_program

clear_bit:
    not t0, t0          # Invert the mask
    and a0, a0, t0      # Clear the bit: number & ~mask

end_program:
    li a7, 93           # exit syscall
    ecall
