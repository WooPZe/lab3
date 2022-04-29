FROM debian
COPY IZ.cpp .
RUN apt-get update
RUN apt-get install -y gcc
RUN apt-get install -y g++
RUN g++ IZ.cpp -static -o IZ
CMD ./IZ
