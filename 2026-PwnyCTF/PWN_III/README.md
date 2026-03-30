================================================================================
# RE-TURN ORIENTED PROGRAMMING (ROP)
================================================================================

### 1. WHAT IS ROP?
---------------
ROP is an exploit technique used to execute code in the presence of security 
protections like NX (No-Execute) or DEP (Data Execution Prevention). 
Instead of injecting shellcode, we reuse small snippets of existing executable 
code found in the binary or libraries (libc). These snippets are called "Gadgets".

### 2. ANATOMY OF A GADGET
----------------------
A gadget is a sequence of instructions ending in a 'ret' (return) instruction.  
Example:  `pop rdi ; ret`

- `pop rdi`: Takes the value currently on top of the stack and puts it into RDI register
- `ret`:     Pops the next address from the stack into the Instruction Pointer (RIP).

### 3. THE ROP CHAIN STRUCTURE
--------------------------
When a function returns, it looks at the stack to find the "Return Address". 
We overwrite this address and the memory following it to chain gadgets.

[ STACK LAYOUT ]
```text
+-------------------------+
|  Padding / Buffer       | <- Overwritten by cyclic(N)
+-------------------------+
|  Canary (if enabled)    | <- Must be leaked and restored
+-------------------------+
|  Saved RBP (8 bytes)    | <- Junk data (e.g., b"B"*8)
+-------------------------+
|  GADGET 1 ADDRESS       | <- RIP starts here (e.g., POP RDI; RET)
+-------------------------+
|  DATA FOR GADGET 1      | <- This value is "popped" into RDI
+-------------------------+
|  GADGET 2 ADDRESS       | <- Next link (e.g., system() address)
+-------------------------+
```
### 4. ESSENTIAL TOOLS
------------------
- Find gadgets:  `ROPgadget --binary chal ` 
- Find strings:  `strings -tx libc.so.6 | grep "/bin/sh"` 
- PwnTools ROP:  rop = ROP(libc); rop.find_gadget(['pop rdi', 'ret'])


[1-ret2win_v2](./1-ret2win_v2.md)

