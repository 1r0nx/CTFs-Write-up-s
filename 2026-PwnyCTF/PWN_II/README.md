 
A format string vulnerability happens when a program uses user input directly as the format argument in functions like `printf`, `fprintf`, or `sprintf`.

Example of vulnerable code:
```c
printf(user_input);
```

Instead of treating the input as plain text, the function interprets format specifiers (like %p).

Common format specifiers used in exploitation:

%p   -> prints a pointer (useful for leaking addresses)  
%x   -> prints data in hexadecimal 32 bits size  (stack dumping)  
%lx  -> prints data in hexadecimal 64 bits size  (stack dumping)  
%s   -> treats value as a pointer and reads memory (arbitrary read)  
%n   -> writes the number of printed bytes to an address (arbitrary write)  

Impact:
- Information leak (reading memory)
- Arbitrary memory read
- Arbitrary memory write (with %n)
- Can lead to full code execution

Examples:

1. Stack leak:  
Input: "%p %p %p %p"  
Output: leaks stack values

2. Finding offset:  
Input: "AAAA %p %p %p"  
Look for 0x41414141 in output  

3. Arbitrary read:  
Input: "%7$s" + address  
Reads memory at given address  

4. Arbitrary write:  
Input: "%1234x%10$n"  
Writes 1234 to the address at position 10 on the stack  

5. Precise write (byte-wise):  
Use %hhn, %hn, %n to control write size  

Summary:  
Format string vulnerabilities allow attackers to read and write memory by abusing printf-style functions when input is not properly sanitized.

Let's start with the first challenge [0-Stack_Read](./0-Stack_Read.md)
