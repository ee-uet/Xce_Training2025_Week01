.data
 word: .word 15
 clear_bit: .word 3 #starting from zero
.text
.global _start
_start:
 lw t0, word
 lw t1, clear_bit
 li t2, 1
 li t3, 0
 la t4, word
clear:
  sll t3, t2,t1
  not t3, t3
  and t3, t3,t0
  sw  t3, 0(t4)
end:
  li t3, 1
  la t0, tohost
  sd t3,0(t0)
.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0
