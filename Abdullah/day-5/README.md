# Complete RISC-V Assembly Lab Project Structure

## **FULL PROJECT ORGANIZATION CREATED:**

```
/riscv-lab/
├── README.md                          
├── problem-1/                         
│   ├── p1.s                            
│   ├── linker.ld                      
│   ├── Makefile                       
│   └── README.md                      
├── problem-2/                         
│   ├── p2.s                           
│   ├── linker.ld                      
│   ├── Makefile                       
│   └── README.md                      
├── problem-3/                         
│   ├── p3.s                           
│   ├── linker.ld                      
│   ├── Makefile                       
│   └── README.md                      
├── problem-4/                         
│   ├── p4.s                           
│   ├── linker.ld                      
│   ├── Makefile                      
│   └── README.md                      
├── problem-5/                         
│   ├── p5.s                           
│   ├── linker.ld                      
│   ├── Makefile                      
│   └── README.md                      
├── task-1/                            
│   ├── restoring_division.s           
│   ├── restoring_division.c           
│   ├── restoring_division_generated.s 
│   ├── start.s                        
│   ├── linker.ld                      
│   ├── Makefile                       
│   └── README.md                      
├── task-2/                             
│   ├── task_2.s                        
│   ├── task_2.c                        
│   ├── task_2_generated.s              
│   ├── start.s                        
│   ├── linker.ld                      
│   ├── Makefile                      
│   └── README.md                     
└── task-3/                             
    ├── non_restoring_division.s       
    ├── non_restoring_division.c       
    ├── non_restoring_division_generated.s 
    ├── start.s                        
    ├── linker.ld                      
    ├── Makefile                       
    └── README.md                       
```

##  **FILES CREATED AND PROVIDED:**

### ** Documentation Files (COMPLETE):**
-  **1 Main README**: Complete project overview with installation and usage
-  **5 Problem READMEs**: Detailed documentation for each problem with algorithms, examples
-  **3 Task READMEs**: Comprehensive analysis including optimization comparisons
-  **Total**: 9 comprehensive README files

### ** Source Code Files (COMPLETE):**
-  **5 Problem Assembly Files**: Fully commented with your commenting style
-  **3 Task Assembly Files**: Hand-written versions with detailed comments
-  **3 Task C Files**: Equivalent C implementations with comprehensive comments
-  **1 Start.s File**: C runtime support for compiler-generated code
-  **Total**: 12 fully commented source files

### ** Build System Files (TEMPLATES PROVIDED):**
-  **Basic Makefile Template**: For problems 1-5 (simple assembly prorams)
-  **Advanced Makefile Template**: For tasks 1-3 (assembly/C comparison)
-  **Linker Script Template**: Standard for all problems and tasks
-  **Total**: 3 build system templates

##  **WHAT YOU NEED TO DO:**

### **1. Copy Templates to Each Folder:**
- **linker.ld**: Same file for all 8 folders (use provided template)
- **Makefile**: Basic version for problems 1-5, advanced version for tasks 1-3
- **start.s**: Copy to task folders (task-1, task-2, task-3)

### **2. Use Your Existing Generated Files:**
- **restoring_division_generated.s**: Copy from your task1.txt
- **task_2_generated.s**: Copy from your task2.txt  
- **non_restoring_division_generated.s**: Copy from your task3.txt

### **3. Adjust Makefile Program Names:**
Each folder needs the program name updated in Makefile:
- **problem-1**: `PROG = p1`
- **problem-2**: `PROG = p2`
- **task-1**: `PROG1 = restoring_division`, `PROG2 = restoring_division_generated`

## **READY-TO-USE FEATURES:**

### **Comprehensive Documentation:**
- **Algorithm explanations** with step-by-step breakdowns
- **RISC-V instruction usage** with register allocation details
- **Performance analysis** and optimization comparisons
- **Debugging guides** with Spike simulator usage
- **Code analysis** including bug identification and fixes

### **Complete Build System:**
- **Individual compilation** for each problem/task
- **Debug support** with Spike simulator integration
- **Comparison tools** for analyzing hand-written vs compiler-generated code
- **Clean targets** for proper project maintenance
