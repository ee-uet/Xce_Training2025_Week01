
.section .text
.global _start
_start:
    # Load numbers
    li t0, 15          # First number
    li t1, 25          # Second number

    # Calculate absolute difference #if t0<t1 then do_subtr  else print_result
    blt t0, t1, do_subtr        
    sub t2, t0, t1     # t2 = t0 - t1
    j done

do_subtr:
    sub t2, t1, t0     # t2 = t1 - t0


# Signal test pass to Spike
done:
    li t0, 1
    la t1, tohost
    sd t0, (t1)

# Loop forever
halt:
    j halt

# Memory for HTIF signaling
.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0
