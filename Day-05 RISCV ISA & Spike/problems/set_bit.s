.data
 word: .word 15
.text
.global _start
_start:
 lw t0, word
 li t2, 1
 li t3, 0
 li t4, 0

loop:
  and t3, t0,t2
  add t4, t4,t3
  srl t0, t0,t2
  beq t0, zero, end
  j loop 
end:
  li t3, 1
  la t0, tohost
  sd t3,0(t0)
.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0
