## Introduction to RISCV Assembly Programming

Spike (the RISC-V ISA Simulator) was installed using the manual.  
For compilation, the `riscv64-unknown-elf-*` toolchain was used.

**`link.ld` linker script** provided in the manual was used along with the following **Makefile**:
```
# Program name
PROG = restoring_division


# Tools
AS = riscv64-unknown-elf-as
LD = riscv64-unknown-elf-ld
SPIKE = spike
# Default target
all: $(PROG).elf

# Assemble and link
$(PROG).elf: $(PROG).s link.ld
        $(AS) -o $(PROG).o $(PROG).s
        $(LD) -T link.ld -o $@ $(PROG).o

# Run with Spike (bare-metal)
run: $(PROG).elf
        $(SPIKE) $(PROG).elf

# Clean build files
clean:
        rm -f *.o *.elf

.PHONY: all run clean
```
## PROBLEMS
## 📌 Problem 1: Absolute Difference of Two Numbers
Assembly code:
```.section .text
    .globl _start

_start:
    li t0, 40       # First number
    li t1, 15       # Second number

    sub t2, t0, t1  # difference = t0 - t1
    bge t2, x0, done
    neg t2, t2      # if negative, make it positive

done:
    li t0, 1
    la t1, tohost
    sd t0, (t1)

1:  j 1b

.section .tohost
    .align 3
tohost: .dword 0
fromhost: .dword 0
```
Explanation:
- loaded two numbers
- Subtracted them and checked if the result was negative.
- If the result was negative, it was negated → this gives the absolute value.

## 📌 Problem 2: Count Set Bits in a 32-bit Word
Assembly code:
```
.section .text
    .globl _start
_start:
    li t0, 0xF1F0F0F0   # Input number
    li t1, 0            # Counter = 0

count_loop:
    beqz t0, done       # if t0 == 0 exit
    andi t2, t0, 1      # extract LSB
    add t1, t1, t2      # add to counter
    srli t0, t0, 1      # shift right
    j count_loop

done:
    mv a0, t1           # result in a0
    li t0, 1
    la t1, tohost
    sd t0, (t1)

1:  j 1b

.section .tohost
    .align 3
tohost: .dword 0
fromhost: .dword 0
```
Explanation:
- In each iteration, the LSB of the input is extracted.
- If the bit is set, the counter is incremented.
- Then the input is right-shifted to check the next bit.
- The loop continues until `t0 = 0`.

## 📌 Problem 3: Factorial of a number
Assembly code:
```
.section .text
    .globl _start
_start:
    li t0, 5        # number
    li t1, 1        # result = 1

fact_loop:
    beqz t0, done
    mul t1, t1, t0  # result *= t0
    addi t0, t0, -1
    j fact_loop

done:
    mv a0, t1
    li t0, 1
    la t1, tohost
    sd t0, (t1)

1:  j 1b

.section .tohost
    .align 3
tohost: .dword 0
fromhost: .dword 0
```
Explanation:
- The factorial loop is implemented by repeatedly multiplying.
- As long as `t0 ≠ 0`, keep multiplying into the result.
- When `t0 = 0`, the factorial result is ready.

## 📌 Problem 4: Reverse an array
Assembly code:
```
.section .text
    .globl _start
_start:
    la t0, array
    li t1, 5

    add t2, t0, t1
    addi t2, t2, -1

reverse_loop:
    blt t2, t0, done
    lb t3, 0(t0)
    lb t4, 0(t2)
    sb t4, 0(t0)
    sb t3, 0(t2)
    addi t0, t0, 1
    addi t2, t2, -1
    j reverse_loop

done:
    la a0, array
    li t0, 1
    la t1, tohost
    sd t0, 0(t1)

1:  j 1b

.section .data
array:
    .byte 1, 2, 3, 4, 5

.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0
```
Explanation:
- Took start and end pointers.
- Swapped their values and updated the pointers
- The loop continued as long as `start < end`.

## 📌 Problem 5: Insertion Sort
```
.global _start
.section .text
_start:
    la t0, array
    li t1, 6
    li t2, 1

outer_loop:
    bge t2, t1, done
    slli a0, t2, 2
    add a1, t0, a0
    lw a2, 0(a1)

    addi a3, t2, -1

inner_loop:
    blt a3, x0, insert
    slli a4, a3, 2
    add a5, t0, a4
    lw a6, 0(a5)
    bge a2, a6, insert
    sw a6, 4(a5)
    addi a3, a3, -1
    j inner_loop

insert:
    addi a3, a3, 1
    slli a4, a3, 2
    add a5, t0, a4
    sw a2, 0(a5)
    addi t2, t2, 1
    j outer_loop

print_array:
    la t0, array
    li t1, 6
    li t2, 0

print_loop:
    bge t2, t1, done
    slli t3, t2, 2
    add t4, t0, t3
    lw t5, 0(t4)
    addi t5, t5, 48
    li t6, 0x10000000
    sb t5, 0(t6)
    addi t2, t2, 1
    j print_loop

done:
    li t0, 1
    la t1, tohost
    sd t0, 0(t1)

halt:
    j halt

.section .data
array:
    .word 5, 2, 9, 1, 5, 6

.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0
```
Explanation:
- Inserted each element into the sorted sub-array.
- Inner loop shifts elements until the correct position is found.

# TASKS
- Use the toolchain to build the assembly file from your C file. 
- Compare the two assembly files. Which is more optimized? 
- Run both on spike and see their working.
#
The assembly file of the C code built using the toolchain was generated with the command `gcc -S file.c -o file_toolchain` and then examined.
Command to compile C code is `gcc file.c -o file`
## 📌 Task 1: Write an assembly program for restoring division algorithm in RISC-V assembly language.
C code (restoring_division.c):
```
#include <stdio.h>
#include <stdint.h>

int main() {
    int dividend = 13;   // number to be divided (N)
    int divisor = 3;     // number that divides (D)

    int n = 4;
    int quotient = 0;
    int remainder = 0;

    for (int i = n - 1; i >= 0; i--) {
        // Left shift remainder by 1 and bring down next bit of dividend
        remainder = (remainder << 1) | ((dividend >> i) & 1);

        // Subtract divisor
        remainder = remainder - divisor;

        if (remainder < 0) {
            // Restore (undo subtraction)
            remainder = remainder + divisor;
            quotient = (quotient << 1) | 0;
        } else {
            quotient = (quotient << 1) | 1;
        }
    }

    printf("Dividend = %d, Divisor = %d\n", dividend, divisor);
    printf("Quotient = %d, Remainder = %d\n", quotient, remainder);

    return 0;
}
```

Tool-chain built assembly code:
```
       .file   "restoring_division.c"
        .text
        .section        .rodata
.LC0:
        .string "Dividend = %d, Divisor = %d\n"
        .align 8
.LC1:
        .string "Quotient = %d, Remainder = %d\n"
        .text
        .globl  main
        .type   main, @function
main:
.LFB0:
        .cfi_startproc
        endbr64
        pushq   %rbp
        .cfi_def_cfa_offset 16
        .cfi_offset 6, -16
        movq    %rsp, %rbp
        .cfi_def_cfa_register 6
        subq    $32, %rsp
        movl    $13, -12(%rbp)
        movl    $3, -8(%rbp)
        movl    $4, -4(%rbp)
        movl    $0, -24(%rbp)
        movl    $0, -20(%rbp)
        movl    -4(%rbp), %eax
        subl    $1, %eax
        movl    %eax, -16(%rbp)
        jmp     .L2
.L5:
        movl    -20(%rbp), %eax
        leal    (%rax,%rax), %esi
        movl    -16(%rbp), %eax
        movl    -12(%rbp), %edx
        movl    %eax, %ecx
        sarl    %cl, %edx
        movl    %edx, %eax
        andl    $1, %eax
        orl     %esi, %eax
        movl    %eax, -20(%rbp)
        movl    -8(%rbp), %eax
        subl    %eax, -20(%rbp)
        cmpl    $0, -20(%rbp)
        jns     .L3
        movl    -8(%rbp), %eax
        addl    %eax, -20(%rbp)
        sall    -24(%rbp)
        jmp     .L4
.L3:
        movl    -24(%rbp), %eax
        addl    %eax, %eax
        orl     $1, %eax
        movl    %eax, -24(%rbp)
.L4:
        subl    $1, -16(%rbp)
.L2:
        cmpl    $0, -16(%rbp)
        jns     .L5
        movl    -8(%rbp), %edx
        movl    -12(%rbp), %eax
        movl    %eax, %esi
        leaq    .LC0(%rip), %rax
        movq    %rax, %rdi
        movl    $0, %eax
        call    printf@PLT
        movl    -20(%rbp), %edx
        movl    -24(%rbp), %eax
        movl    %eax, %esi
        leaq    .LC1(%rip), %rax
        movq    %rax, %rdi
        movl    $0, %eax
        call    printf@PLT
        movl    $0, %eax
        leave
        .cfi_def_cfa 7, 8
        ret
        .cfi_endproc
.LFE0:
        .size   main, .-main
        .ident  "GCC: (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0"
        .section        .note.GNU-stack,"",@progbits
        .section        .note.gnu.property,"a"
        .align 8
        .long   1f - 0f
        .long   4f - 1f
        .long   5
0:
        .string "GNU"
1:
        .align 8
        .long   0xc0000002
        .long   3f - 2f
2:
        .long   0x3
3:
        .align 8
4:
```

My assembly code:
```
.global _start
.section .text
_start:
    li x1,13     # dividend
    li x2,0       # quotient
    li x3,0       # remainder
    li x4,3       # divisor
    li x5,4      # size 
loop:
     slli x3,x3,1
     srl  x6,x1,x5
     andi x6,x6,1
     or   x3,x3,x6
     sub  x7,x3,x4      # temp = remainder - divisor
     blt  x7,zero,restore
     mv   x3,x7         # remainder = temp
     li   x8,1
     sll  x8,x8,x5      # shift for quotient
     or x2,x2,x8        # set quotient bit = 1
restore:
     add x3,x3,x4       # restore remainder if negative
     li x8,0
     sll x8,x8,x5
     or x2,x2,x8        # quotient bit = 0
     addi x5,x5,-1
     bge x5,zero,loop  # loop until x5 < 0
done:
    # Signal test pass to Spike
    li x6, 1
    la x7, tohost
    sd x6, 0(x7)
1: j 1b
.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0
```
### Comparison
Manual assembly code is more optimized in terms of:
- Instruction count
- Register usage (no memory loads/stores except final host write)
- Direct control flow (no extra prologue or stack ops)

GCC version is more general purpose:
- It integrates with C runtime (so we can print, debug, link with libraries, etc.).
- Manual version is bare-metal optimized for testing in Spike.
  
## 📌 Task 2: Write an assembly program for setting or clearing any bit in a 32-bit number in RISC-V assembly language.

C code (clear_set_bit.c):
```
#include <stdio.h>
#include <stdint.h>

int main() {
    uint32_t num = 0x12345678;  // Example number
    int bitpos = 5;             // Bit position (0–31)
    int choice = 1;             // 1 = Set bit, 0 = Clear bit
    uint32_t result;

    if (choice == 1) {
        // Set bit
        result = num | (1U << bitpos);
    } else {
        // Clear bit
        result = num & ~(1U << bitpos);
    }

    printf("Original: 0x%08X\n", num);
    printf("Modified: 0x%08X\n", result);

    return 0;
}
```

Tool-chain built assembly code:
```
        .file   "clear_set_bit.c"
        .text
        .section        .rodata
.LC0:
        .string "Original: 0x%08X\n"
.LC1:
        .string "Modified: 0x%08X\n"
        .text
        .globl  main
        .type   main, @function
main:
.LFB0:
        .cfi_startproc
        endbr64
        pushq   %rbp
        .cfi_def_cfa_offset 16
        .cfi_offset 6, -16
        movq    %rsp, %rbp
        .cfi_def_cfa_register 6
        subq    $16, %rsp
        movl    $305419896, -12(%rbp)
        movl    $5, -8(%rbp)
        movl    $1, -4(%rbp)
        cmpl    $1, -4(%rbp)
        jne     .L2
        movl    -8(%rbp), %eax
        movl    $1, %edx
        movl    %eax, %ecx
        sall    %cl, %edx
        movl    %edx, %eax
        orl     -12(%rbp), %eax
        movl    %eax, -16(%rbp)
        jmp     .L3
.L2:
        movl    -8(%rbp), %eax
        movl    $1, %edx
        movl    %eax, %ecx
        sall    %cl, %edx
        movl    %edx, %eax
        notl    %eax
        andl    -12(%rbp), %eax
        movl    %eax, -16(%rbp)
.L3:
        movl    -12(%rbp), %eax
        movl    %eax, %esi
        leaq    .LC0(%rip), %rax
        movq    %rax, %rdi
        movl    $0, %eax
        call    printf@PLT
        movl    -16(%rbp), %eax
        movl    %eax, %esi
        leaq    .LC1(%rip), %rax
        movq    %rax, %rdi
        movl    $0, %eax
        call    printf@PLT
        movl    $0, %eax
        leave
        .cfi_def_cfa 7, 8
        ret
        .cfi_endproc
.LFE0:
        .size   main, .-main
        .ident  "GCC: (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0"
        .section        .note.GNU-stack,"",@progbits
        .section        .note.gnu.property,"a"
        .align 8
        .long   1f - 0f
        .long   4f - 1f
        .long   5
0:
        .string "GNU"
1:
        .align 8
        .long   0xc0000002
        .long   3f - 2f
2:
        .long   0x3
3:
        .align 8
4:
```
My assembly code:
```
.section .text
.global _start
_start:
    li x1, 32
    li x2, 6
    li x3, 0

    li x4, 1
    sll x4, x4, x2

    beq x3, x0, clear_bit
set_bit:
    or x1, x1, x4
    j done

clear_bit:
    xori x4, x4, -1
    and x1, x1, x4

done:
    li t0, 1
    la t1, tohost
    sd t0, 0(t1)
1:  j 1b

.section .data
n: .word 7
my_array: .word 1,2,3,4,5,6,7

.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0
```
## 📌 Task 3: Write an assembly program for non-restoring 32-bit unsigned division in RISC-V assembly language.
C code (non_restoring.c):
```
#include <stdio.h>
#include <stdint.h>

void nonRestoringDivision(uint32_t dividend, uint32_t divisor, uint32_t *quotient, uint32_t *remainder) {
    int32_t rem = 0;  // signed to allow negative values during iterations
    uint32_t q = 0;

    for (int i = 31; i >= 0; i--) {
        rem = (rem << 1) | ((dividend >> i) & 1);  // shift remainder left and bring down bit
        q <<= 1;

        if (rem >= 0) {
            rem = rem - divisor;
            if (rem >= 0)
                q |= 1;
        } else {
            rem = rem + divisor;
            if (rem >= 0)
                q |= 1;
        }
    }

    // If remainder is negative, correct it
    if (rem < 0)
        rem += divisor;

    *quotient = q;
    *remainder = (uint32_t)rem;
}

int main() {
    uint32_t dividend, divisor, quotient, remainder;

    printf("Enter Dividend: ");
    scanf("%u", &dividend);
    printf("Enter Divisor: ");
    scanf("%u", &divisor);

    nonRestoringDivision(dividend, divisor, &quotient, &remainder);

    printf("Quotient = %u, Remainder = %u\n", quotient, remainder);
    return 0;
}
```

Tool-chain built assembly code:
```
        .file   "non_restoring.c"
        .text
        .globl  nonRestoringDivision
        .type   nonRestoringDivision, @function
nonRestoringDivision:
.LFB0:
        .cfi_startproc
        endbr64
        pushq   %rbp
        .cfi_def_cfa_offset 16
        .cfi_offset 6, -16
        movq    %rsp, %rbp
        .cfi_def_cfa_register 6
        movl    %edi, -20(%rbp)
        movl    %esi, -24(%rbp)
        movq    %rdx, -32(%rbp)
        movq    %rcx, -40(%rbp)
        movl    $0, -12(%rbp)
        movl    $0, -8(%rbp)
        movl    $31, -4(%rbp)
        jmp     .L2
.L5:
        movl    -12(%rbp), %eax
        leal    (%rax,%rax), %esi
        movl    -4(%rbp), %eax
        movl    -20(%rbp), %edx
        movl    %eax, %ecx
        shrl    %cl, %edx
        movl    %edx, %eax
        andl    $1, %eax
        orl     %esi, %eax
        movl    %eax, -12(%rbp)
        sall    -8(%rbp)
        cmpl    $0, -12(%rbp)
        .file   "non_restoring.c"
        .text
        .globl  nonRestoringDivision
        .type   nonRestoringDivision, @function
nonRestoringDivision:
.LFB0:
        .cfi_startproc
        endbr64
        pushq   %rbp
        .cfi_def_cfa_offset 16
        .cfi_offset 6, -16
        movq    %rsp, %rbp
        .cfi_def_cfa_register 6
        movl    %edi, -20(%rbp)
        movl    %esi, -24(%rbp)
        movq    %rdx, -32(%rbp)
        movq    %rcx, -40(%rbp)
        movl    $0, -12(%rbp)
        movl    $0, -8(%rbp)
        movl    $31, -4(%rbp)
        jmp     .L2
.L5:
       movl    -12(%rbp), %eax
        leal    (%rax,%rax), %esi
        movl    -4(%rbp), %eax
        movl    -20(%rbp), %edx
        movl    %eax, %ecx
        shrl    %cl, %edx
        movl    %edx, %eax
        andl    $1, %eax
        orl     %esi, %eax
        movl    %eax, -12(%rbp)
        sall    -8(%rbp)
        cmpl    $0, -12(%rbp)
        js      .L3
        movl    -12(%rbp), %eax
        subl    -24(%rbp), %eax
        movl    %eax, -12(%rbp)
        cmpl    $0, -12(%rbp)
        js      .L4
        orl     $1, -8(%rbp)
        jmp     .L4
.L3:
        movl    -12(%rbp), %edx
        movl    -24(%rbp), %eax
        addl    %edx, %eax
        movl    %eax, -12(%rbp)
        cmpl    $0, -12(%rbp)
        js      .L4
        orl     $1, -8(%rbp)
.L4:
        subl    $1, -4(%rbp)
.L2:
        cmpl    $0, -4(%rbp)
        jns     .L5
        cmpl    $0, -12(%rbp)
        jns     .L6
        movl    -12(%rbp), %edx
        movl    -24(%rbp), %eax
        addl    %edx, %eax
        movl    %eax, -12(%rbp)
.L6:
        movq    -32(%rbp), %rax
        movl    -8(%rbp), %edx
        movl    %edx, (%rax)
        movl    -12(%rbp), %edx
        movq    -40(%rbp), %rax
        movl    %edx, (%rax)
        nop
        popq    %rbp
        .cfi_def_cfa 7, 8
        ret
        .cfi_endproc
.LFE0:
        .size   nonRestoringDivision, .-nonRestoringDivision
        .section        .rodata
.LC0:
        .string "Enter Dividend: "
.LC1:
        .string "%u"
.LC2:
        .string "Enter Divisor: "
        .align 8
.LC3:
        .string "Quotient = %u, Remainder = %u\n"
        .text
        .globl  main
        .type   main, @function
main:
.LFB1:
        .cfi_startproc
        endbr64
        pushq   %rbp
        .cfi_def_cfa_offset 16
        .cfi_offset 6, -16
        movq    %rsp, %rbp
        .cfi_def_cfa_register 6
        subq    $32, %rsp
        movq    %fs:40, %rax
        movq    %rax, -8(%rbp)
        xorl    %eax, %eax
        leaq    .LC0(%rip), %rax
        movq    %rax, %rdi
        movl    $0, %eax
        call    printf@PLT
        leaq    -24(%rbp), %rax
        movq    %rax, %rsi
        leaq    .LC1(%rip), %rax
        movq    %rax, %rdi
        movl    $0, %eax
        call    __isoc99_scanf@PLT
        leaq    .LC2(%rip), %rax
        movq    %rax, %rdi
        movl    $0, %eax
        call    printf@PLT
        leaq    -20(%rbp), %rax
        movq    %rax, %rsi
        leaq    .LC1(%rip), %rax
        movq    %rax, %rdi
        movl    $0, %eax
        call    __isoc99_scanf@PLT
        movl    -20(%rbp), %esi
       movl    -24(%rbp), %eax
        leaq    -12(%rbp), %rcx
        leaq    -16(%rbp), %rdx
        movl    %eax, %edi
        call    nonRestoringDivision
        movl    -12(%rbp), %edx
        movl    -16(%rbp), %eax
        movl    %eax, %esi
        leaq    .LC3(%rip), %rax
        movq    %rax, %rdi
        movl    $0, %eax
        call    printf@PLT
        movl    $0, %eax
        movq    -8(%rbp), %rdx
        subq    %fs:40, %rdx
        je      .L9
        call    __stack_chk_fail@PLT
.L9:
        leave
        .cfi_def_cfa 7, 8
        ret
        .cfi_endproc
.LFE1:
        .size   main, .-main
        .ident  "GCC: (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0"
        .section        .note.GNU-stack,"",@progbits
        .section        .note.gnu.property,"a"
        .align 8
        .long   1f - 0f
        .long   4f - 1f
        .long   5
0:
        .string "GNU"
1:
        .align 8
        .long   0xc0000002
        .long   3f - 2f
2:
        .long   0x3
3:
        .align 8
4:
```
Manual Assembly code:
```
.global _start
 
.section .text
 
_start:#include <stdio.h>
#include <stdint.h>

int main() {
    int dividend = 13;   // number to be divided (N)
    int divisor = 3;     // number that divides (D)

    int n = 4;
    int quotient = 0;
    int remainder = 0;

    for (int i = n - 1; i >= 0; i--) {
        // Left shift remainder by 1 and bring down next bit of dividend
        remainder = (remainder << 1) | ((dividend >> i) & 1);

        // Subtract divisor
        remainder = remainder - divisor;

        if (remainder < 0) {
            // Restore (undo subtraction)
            remainder = remainder + divisor;
            quotient = (quotient << 1) | 0;
        } else {
            quotient = (quotient << 1) | 1;
        }
    }

    printf("Dividend = %d, Divisor = %d\n", dividend, divisor);
    printf("Quotient = %d, Remainder = %d\n", quotient, remainder);

    return 0;
}

    li x1,43      # dividend
    li x2,0       # quotient
    li x3,0       # remainder
    li x4,4       # divisor
    li x5,31      # size 

loop:
     slli x3,x3,1       
     srl  x6,x1,x5     
     andi x6,x6,1       
     or   x3,x3,x6      

     bgez x3,sub_divisor   # if remainder >= 0
     add x3,x3,x4          # if remainder < 0, add divisor
     j set_quotient

sub_divisor:
     sub x3,x3,x4          # remainder >= 0, subtract divisor

set_quotient:
     bgez x3,quotient_bit_set
     li x8,0
     sll x8,x8,x5
     or x2,x2,x8
     j loop_continue

quotient_bit_set:
     li x8,1
     sll x8,x8,x5
     or x2,x2,x8

loop_continue:
     addi x5,x5,-1
     bge x5,zero,loop

# Final remainder adjustment if negative
bltz x3, add_divisor_final
j done

add_divisor_final:
add x3,x3,x4

done:
    li x6,1
    la x7,tohost
    sd x6,0(x7)

1: j 1b

.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0
```