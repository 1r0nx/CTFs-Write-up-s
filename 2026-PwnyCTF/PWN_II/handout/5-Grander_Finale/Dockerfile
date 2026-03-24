FROM ubuntu:20.04

RUN apt-get update && apt-get install -y socat gcc python gdb
RUN rm -rf /var/lib/apt/lists/*

RUN mkdir -p /usr/src/pwn
WORKDIR /usr/src/pwn
RUN cd /usr/src/pwn/

COPY flag.txt .
RUN chmod 444 flag.txt
RUN adduser pwn
COPY grander_finale .
RUN chmod 111 grander_finale
USER pwn
CMD socat -T60 TCP-LISTEN:1337,fork,reuseaddr EXEC:"./grander_finale"
