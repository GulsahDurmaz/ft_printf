NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rcs # r: replace the existed, c: creat if not existed, s: sort
SRC = $(wildcard * .c) # list all .c files
OBJ = $(SRC:.c=.o) #replace .c with .o

all: $(NAME)




