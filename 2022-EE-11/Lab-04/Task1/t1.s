# 0 "t1.S"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 0 "<command-line>" 2
# 1 "t1.S"
.section .data
num1: .word 15
num2: .word 7
result: .word 0

.global _start

.section .text
_start:
 la t0, num1
 lw a0, 0(t0) // 15

 la t0, num2
 lw a1, 0(t0) // 7

 sub t1, a0, a1
 sub t2, a1, a0

 bge a0, a1, a0_ge // Absolute difference

 mv a2, t2
 j store


a0_ge:
 mv a2, t1


store:
 la t0, result
 sw a2, 0(t0)

 mv a0, a2

 # Code to exit for Spike (DONT REMOVE IT)
     li t0, 1
     la t1, tohost
 sd t0, (t1)

# Loop forever if spike does not exit
1: j 1b

.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0
