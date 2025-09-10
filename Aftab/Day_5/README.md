# README: RISC-V Assembly Tasks

This README provides an overview of the RISC-V assembly tasks implemented in the provided code, 
detailing their functionality, workings, test cases, and expected outputs. Each task demonstrates fundamental 
assembly programming concepts such as arithmetic operations, loops, conditionals, array handling, and division algorithms.

---

## Problem 1: Absolute Difference
**TODO**: Compute the absolute difference between two numbers.  

**Working**:  
- Loads two numbers (`t2=1`, `t3=2`).  
- Subtracts `t4 = t2 - t3`.  
- If result is negative, negate it to make absolute.  
- Exit with result stored in `t4`.  

**Test Case**: num1=1, num2=2.  

**Output**:  
```
t4 = 1 (result in t4)
```

---

## Problem 2: Count Set Bits in a Word
**TODO**: Count the number of set bits in a 32-bit integer.  

**Working**:  
- Initializes loop with shifting mask (`t6`).  
- ANDs each shifted bit with number (`t2=7`).  
- Increments counter `t5` whenever a bit is set.  
- Loops until all 31 positions checked.  

**Test Case**: Input `7 (0b111)`.  

**Output**:  
```
t5 = 3 (result in t5)
```

---

## Problem 3: Factorial Calculation
**TODO**: Compute factorial of a number.  

**Working**:  
- Initializes number `t2 = 3`.  
- Multiplies decreasing sequence until 1.  
- Stores result in `t5`.  

**Test Case**: Input `3`.  

**Output**:  
```
t5 = 6 (result in t5)
```

---

## Problem 4: Reverse an Array
**TODO**: Reverse the elements of an array in place.  

**Working**:  
- Loads base address of array `{3,7,2,9,1,5,10}`.  
- Swaps elements from start and end, moving inward.  
- Uses counter to stop at halfway point.  

**Test Case**: Input `[3,7,2,9,1,5,10]`.  

**Output**:  
```
[10,5,1,9,2,7,3] (reversed array in memory)
```

---

## Problem 5: Insertion Sort
**TODO**: Sort an array using insertion sort algorithm.  

**Working**:  
- Iterates through elements.  
- Compares each with previous values.  
- Shifts larger values right.  
- Places current element (`key`) at correct sorted position.  

**Test Case**: Input `[3,7,2,9,1,5]`.  

**Output**:  
```
[1,2,3,5,7,9] (sorted array in memory)
```

---

## Task 1: Restoring Division Algorithm
**TODO**: Implement restoring division on two numbers.  

**Working**:  
- Uses registers for dividend (`t0=16`) and divisor (`t1=3`).  
- Performs restoring division steps with shifting, subtracting, and quotient update.  
- Quotient stored in `t0`, remainder in `t2`.  

**Test Case**: 16 ÷ 3.  

**Output**:  
```
Quotient = 5 (in t0), Remainder = 1 (in t2)
```

---

## Task 2: Bit Manipulation
**TODO**: Demonstrate bit set, clear, toggle, and check operations.  

**Working**:  
- Number `t0 = 0x12345678`.  
- Position `t1 = 5`.  
- Uses `or`, `and`, `xor`, `srl` to perform bit operations.  

**Test Case**: Position 5 in `0x12345678`.  

**Output**:  
- **Set Bit Result** → stored in `t3`  
- **Clear Bit Result** → stored in `t4`  
- **Toggle Bit Result** → stored in `t5`  
- **Check Bit Result** → stored in `t6`  

---

## Task 3: Non-Restoring Division Algorithm
**TODO**: Implement non-restoring division on two numbers.  

**Working**:  
- Initializes dividend (`t0=21`), divisor (`t1=3`).  
- Repeatedly shifts, subtracts/adds, and updates quotient bits.  
- Handles correction if remainder negative.  

**Test Case**: 21 ÷ 3.  

**Output**:  
```
Quotient = 7 (in t0), Remainder = 0 (in t2)
```

---

## Notes
- All tasks include Spike exit code (`tohost`) for simulation.  
- Results are stored in registers (`t` or `a` registers) and can be observed in Spike.  
- Arrays are word-aligned in `.data` section.  
- Division algorithms assume 32-bit dividend and divisor.  
