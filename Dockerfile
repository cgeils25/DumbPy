FROM python:3.13.2-slim

WORKDIR /usr/local/DumbPy

COPY . .

RUN sudo apt-get install gpp
