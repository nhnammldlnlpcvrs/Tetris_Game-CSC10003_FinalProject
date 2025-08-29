FROM ubuntu:22.04

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
    && cmake .. -DBUILD_SHARED_LIBS=ON \
    && make -j$(nproc) \
    && make install \
    && ldconfig \
    && rm -rf /tmp/raylib

RUN g++ -I/app/resource \
    -I/app/resource/App -I/app/resource/Controller -I/app/resource/Core \
    -I/app/resource/Infrastructure -I/app/resource/Model -I/app/resource/View \
    $(find /app/resource -name "*.cpp") -o /app/main -lraylib -lGL -lm -ldl -lpthread -lX11

CMD ["echo", "Build finished"]
