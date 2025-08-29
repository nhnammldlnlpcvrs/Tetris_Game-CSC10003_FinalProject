FROM ubuntu:22.04 AS builder

RUN apt-get update && apt-get install -y \
    build-essential git cmake libglfw3-dev libopenal-dev \
    libudev-dev libx11-dev libxcursor-dev libxinerama-dev libxrandr-dev libxi-dev \
    pkg-config wget ca-certificates \
    && rm -rf /var/lib/apt/lists/*

RUN wget https://github.com/Kitware/CMake/releases/download/v3.28.2/cmake-3.28.2-linux-x86_64.sh \
    && sh cmake-3.28.2-linux-x86_64.sh --skip-license --prefix=/usr/local \
    && rm cmake-3.28.2-linux-x86_64.sh

WORKDIR /app

COPY resource/ /app/resource

RUN git clone https://github.com/raysan5/raylib.git /tmp/raylib \
    && cd /tmp/raylib \
    && mkdir build && cd build \
    && cmake .. -DBUILD_SHARED_LIBS=OFF \
    && make -j$(nproc) \
    && make install \
    && ldconfig \
    && rm -rf /tmp/raylib

RUN g++ -std=c++17 -I/app/resource \
    -I/app/resource/App -I/app/resource/Controller -I/app/resource/Core \
    -I/app/resource/Infrastructure -I/app/resource/Model -I/app/resource/View \
    $(find /app/resource -name "*.cpp") -o /app/main -lraylib -lGL -lm -ldl -lpthread -lX11

FROM ubuntu:22.04

RUN apt-get update && apt-get install -y \
    libglfw3 libopenal1 libx11-6 libxcursor1 libxinerama1 libxrandr2 libxi6 \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY --from=builder /app/main /app/main
COPY --from=builder /usr/local/lib/libraylib.a /usr/local/lib/libraylib.a

RUN chmod +x /app/main

CMD ["/app/main"]
