# IM lib's path
LIM_PATH         := ./d_im
LIM_INCLUDE_PATH := $(LIM_PATH)/include

.PHONY: all
all:
	x86_64-w64-mingw32-gcc main.c -o main.exe \
	-Wall -static-libgcc -mwindows -fno-pic -no-pie \
	-lim -L$(LIM_PATH) -I$(LIM_INCLUDE_PATH)
