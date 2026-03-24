FROM ubuntu:20.04

RUN apt-get update && apt-get install -y socat gcc python3 gdb
RUN rm -rf /var/lib/apt/lists/*

RUN mkdir -p /usr/src/pwn
WORKDIR /usr/src/pwn
RUN cd /usr/src/pwn/

RUN adduser pwn
COPY flag.txt .
COPY challenge .
RUN chmod 111 challenge
USER pwn
CMD socat -T60 TCP-LISTEN:1337,fork,reuseaddr EXEC:"./challenge"
