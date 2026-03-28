================================================================================
# RE-TURN ORIENTED PROGRAMMING (ROP) -

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
Example:  pop rdi ; ret

- pop rdi: Takes the value currently on top of the stack and puts it into RDI register
- ret:     Pops the next address from the stack into the Instruction Pointer (RIP).

### 3. THE ROP CHAIN STRUCTURE
--------------------------
When a function returns, it looks at the stack to find the "Return Address". 
We overwrite this address and the memory following it to chain gadgets.

[ STACK LAYOUT ]
```text

Address | Content | Description

--------|------------------------|-----------------------------------------

High | [ GADGET 3 / FUNC ] | Next step (e.g., system() address)

↑ | [ DATA FOR GADGET 2 ] | Value popped into RSI (e.g., 0x0)

| | [ GADGET 2 ] | e.g., pop rsi; ret

| | [ DATA FOR GADGET 1 ] | Value popped into RDI (e.g., &"/bin/sh")

| | [ GADGET 1 ] | RIP starts here (e.g., pop rdi; ret)

| | [ Saved RBP ] | 8 bytes of junk data (e.g., b"B"*8)

| | [ STACK CANARY ] | 8 bytes (Must be leaked & restored)

Low | [ Padding / Buffer ] | N bytes to reach Canary (use cyclic(N))

```
### 4. ESSENTIAL TOOLS
------------------
- Find gadgets:  `ropper --file libc.so.6 --search "pop rdi"` 
- Find strings:  `strings -tx libc.so.6 | grep "/bin/sh"` 
- PwnTools ROP:  rop = ROP(libc); rop.find_gadget(['pop rdi', 'ret'])
