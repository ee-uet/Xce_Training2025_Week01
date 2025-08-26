.data
my_array: .word 12, 11, 13, 5, 6
n:        .word 5

.text
.globl _start
_start:
    la x5, my_array       #base address
    lw x6, n              #  size
    li x7, 4              # second el

loop1:
    
  li x9, 4        
  mul x8, x6, x9  #  n* 4

   bge x7, x8, done    # if i >= n*4, exit


    add x10, x5, x7       
    lw x11, 0(x10)        # key = arr[i]
    addi x12, x7, -4      # j = i - 4

loop2:
    blt x12, zero, insert #  j 
    add x13, x5, x12      #  &arr[j]
    lw x14, 0(x13)        # arr[j]
    sub x15, x14, x11     # compare arr[j] - key
    
    
    ble x15, zero, insert #  arr[j] <= key, 
    sw x14, 4(x13)        # arr[j+1] = arr[j]
    addi x12, x12, -4     # j -= 4
    j loop2

insert:
    add x13, x5, x12
    sw x11, 4(x13)        # arr[j+1] = key
    addi x7, x7, 4        # i += 4
    j loop1

done:
    # Signal test pass to Spike
    li x6, 1
    la x7, tohost
    sd x6, 0(x7)

# Loop forever
1: j 1b

.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0

