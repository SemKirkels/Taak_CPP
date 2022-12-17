FROM ubuntu:latest
COPY . .
RUN apt-get update && apt-get -y --no-install-recommends install \
    build-essential \
    clang \
    cmake \
    gdb \
    wget
RUN g++ Tic_Tac_Toe/*.cpp -o game 
ENTRYPOINT ["./game"]