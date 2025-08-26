def sqrt_binary(x, precision=1e-10):
    if x < 0:
        raise ValueError("Cannot compute square root of a negative number.")
    low, high = 0, max(1.0, x)
    while high - low > precision:
        mid = (low + high) / 2
        if mid * mid < x:
            low = mid
        else:
            high = mid
    return (low + high) / 2

# Example usage
print(sqrt_binary(9))  # Approximate value of sqrt(9)
