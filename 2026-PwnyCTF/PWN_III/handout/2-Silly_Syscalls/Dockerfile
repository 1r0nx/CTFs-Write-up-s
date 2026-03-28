FROM ubuntu:20.04

RUN apt-get update && apt-get install -y socat gcc python nasm make gdb
RUN rm -rf /var/lib/apt/lists/*

RUN mkdir -p /usr/src/pwn
WORKDIR /usr/src/pwn
RUN cd /usr/src/pwn/

COPY flag.txt .
COPY chal .
RUN chmod 444 flag.txt
RUN adduser pwn
RUN chmod 111 chal
USER pwn
CMD socat -T60 TCP-LISTEN:1337,fork,reuseaddr EXEC:"./chal"
