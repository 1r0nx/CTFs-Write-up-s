
## Buffer Overflow — Everything You Need to Understand

### 1. What is a Buffer Overflow?

A **buffer overflow** happens when a program writes more data into a buffer (a fixed-size memory region) than it can hold.

This overwrites adjacent memory and can lead to:

- Crashes
    
- Unexpected behavior
    
- Code execution (what we/attackers want)
    

---

### 2. Memory Basics

#### Process Memory Layout

Typical program memory is organized like this:

```
[ High Addresses ]
Stack      ↓ (grows down)
Heap       ↑ (grows up)
BSS
Data
Text (code)
[ Low Addresses ]
```

---

### 3. Stack (Most Important for BOF)

The stack stores:

- Local variables
    
- Function arguments
    
- Return addresses
    

Example:

```c
void vuln() {
    char buffer[32];
}
```

---

### 4. Stack Frame Anatomy

When a function is called:

```
| Return Address |  ← saved RIP/EIP
| Saved Base Ptr |  ← RBP/EBP
| Local Variables|
```

So in memory:

```
buffer → [..............]
          [..............]
saved RBP
return address  ← TARGET
```

---

### 5. Why Overflow Happens

Example vulnerable code:

```c
void vuln() {
    char buffer[32];
    gets(buffer);
}
```

`gets()` does NOT check size → dangerous

If you input >32 bytes:

- You overwrite saved RBP
    
- Then overwrite return address
    

---

### 6. Exploitation Goal

👉 Control the **return address**

Instead of returning normally:

- Redirect execution to:
    
    - shellcode
        
    - system("/bin/sh")
        
    - ROP chain
        

---

## 7. Calling Conventions (Important)

### x86 (32-bit)

- Arguments passed on stack  

### x64 (Linux)

 - Arguments are passed in registers in this order:
	 1. RDI 
	 2. RSI 
	 3. RDX 
	 4. RCX 
	 5. R8 
	 6. R9
	 7. ...


Example:

```c
system("/bin/sh")
```

→ "/bin/sh" must be in RDI

---

### 8. Protections You Must Understand

### NX (No eXecute)

- Stack is not executable
    
- No shellcode → use ROP
    

---

### ASLR (Address Space Layout Randomization)

- Randomizes memory addresses
    
- You need leaks
    

---

### Canary (Stack Cookie)

- Detects overflow before return
    
- Must bypass or leak
    

---

### PIE (Position Independent Executable)

- Binary base address is randomized


---

## Final Thought

A buffer overflow is not just "writing too much data"  
👉 It is about **controlling execution flow through memory corruption**

[Bug Bounty 1](./Bug_Bounty_1.md)

