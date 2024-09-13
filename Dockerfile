FROM archlinux:latest

RUN pacman -Sy --noconfirm python

RUN pacman -Syu --noconfirm tzdata
