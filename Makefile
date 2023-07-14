NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rcs # r: replace the existed, c: creat if not existed, s: sort
SRCS = $(wildcard *.c) # list all .c files
OBJS = $(patsubst %.c, %.o, $(SRCS)) #replace .c with .o
#HEADS = $(wildcard *.h)
# Compilation target and dependencies
all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)
# Patern rule
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
# Clean target
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re test
