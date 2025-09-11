## C Program: Data Types and Typecasting
This program shows:
- Values of different datatype variables
- Sizes in bytes
- Typecasting between different data types


### Code Explanation
#### Variables Declaration
- `int a = 1;`
- `float b = 1.1f;`
- `double c = 21.132232;`
- `char d = 's';`

#### Printing Values and Sizes
- `%d` :  prints `int`
- `%f` :  prints `float`
- `%.5lf` :  prints `double` upto 5 decimal places
- `%c` :  prints `char`
- `%zu` :  prints size in bytes (returned by `sizeof` i-e unsigned)

#### Typecasting  
1. `int :  float`
2. `float :  int`
3. `double :  int`
4. `int :  double`

---
 
#### Run:
```bash
gcc task1.c -o task1
./task1 
```


