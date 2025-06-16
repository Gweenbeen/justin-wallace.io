**06/15/25: Register VM ** 
- A basic register based virtual machine that takes bytecode instructions and does them
- Each bytecode is 16 bits, 4 bytes for the instruction, 4 for arg1 and 8 for arg2
- There are 16 registers: 13 general purpose, 1 flag pointer (unused), 1 instruction pointer, 1 stack pointer
- I was gonna add more things like memory management, function calls and flags, but I didn't feel like doing that so I didnt
- I also wanted to add text parsing so you could import your own vm files to make it more like assrmbly, but didnt do that either
Instruction set:  
CONST add a constant value to a register  
ADD add 2 registers  
SUB subtract 2 registers  
MULT multiply 2 registers  
DIV divide 2 registers  
AND bitwise and  
OR bitwise or  
NOT bitwise not  
JUMP jump to an instruction  
HALT halt the program  
PUSH push from a register to the stack  
POP pop the stack  
CALL unused  
RET unused  
LOAD unused  
STORE unused
