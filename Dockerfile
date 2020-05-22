FROM archlinux:latest

ADD scripts .

RUN pacman -Sy --noconfirm python

RUN pacman -Syu --noconfirm tzdata
