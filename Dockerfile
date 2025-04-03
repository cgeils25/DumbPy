FROM ubuntu:latest
FROM python:3.13.2-slim

WORKDIR /usr/local/DumbPy

# Update package list and install g++
RUN apt-get update && \
    apt-get install -y --no-install-recommends g++

# Clean up apt cache
RUN apt-get clean && rm -rf /var/lib/apt/lists/*

# Update package lists and install Git
RUN apt-get update && apt-get install -y git

RUN git --version

RUN apt-get update && apt-get install cmake

RUN apt-get update && apt-get install make

RUN source build.sh

COPY . .