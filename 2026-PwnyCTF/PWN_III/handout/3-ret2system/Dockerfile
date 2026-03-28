FROM ubuntu:20.04

RUN apt-get update && apt-get install -y socat gcc python make
RUN rm -rf /var/lib/apt/lists/*

RUN mkdir -p /usr/src/pwn
WORKDIR /usr/src/pwn
RUN cd /usr/src/pwn/

COPY flag.txt .
COPY challenge.c .
COPY Makefile .
RUN chmod 444 flag.txt
RUN adduser pwn
RUN make chal
RUN chmod 111 chal
USER pwn
CMD socat -T60 TCP-LISTEN:1337,fork,reuseaddr EXEC:"./chal"
