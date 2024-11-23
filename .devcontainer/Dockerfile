FROM gcc:14.2.0

RUN apt-get update && apt-get install -y \
    cmake \
    fish \
    libgtest-dev \
    && rm -rf /var/lib/apt/lists/*

RUN cd /usr/src/gtest && cmake . && make && mv lib/*.a /usr/lib && export PATH_TO_CHILD1="/workspaces/OSystems/build/lab1/child1" && export PATH_TO_CHILD2="/workspaces/OSystems/build/lab1/child2"

WORKDIR /workspaces/OSystems
