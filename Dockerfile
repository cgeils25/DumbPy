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

RUN pip install --upgrade pip

RUN pip install pybind11

RUN apt-get install python3-dev

RUN apt-get install cmake

COPY . .