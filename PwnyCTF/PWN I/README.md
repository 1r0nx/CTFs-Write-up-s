This part I is focused on buffer overflow vulnerability from basics to advanced concept

**Register and Stack overview**  
Let's start by some simple term clarification and explanation.  

To run instructions a program uses memory and CPU .

Registers:
Registers are very small, very fast storage inside the CPU.
They hold important values like numbers, addresses, or results.
Examples: RAX, RBX, RCX (on x86_64).
They are used constantly during execution.

Stack:
The stack is a part of memory used to store temporary data.
It works like a stack of plates (Last In, First Out).
When a function is called:
- arguments and return address are pushed onto the stack
- local variables are stored there
When the function ends:
- data is removed (popped) from the stack

Summary:
Registers = fast CPU storage (small, limited)  
Stack = organized memory for function calls (larger, slower)

[Bug Bounty 1](./Bug_Bounty_1.md)

