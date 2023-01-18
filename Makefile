SRCS = fractol.c init.c utils.c draw.c color.c key.c
OBJS = $(SRCS:.c=.o)
CC = gcc
MFLAGS = ./mlxlib/libmlx.a
AFLAGS =  -Wall -Wextra -Werror -I./mlxlib
RM = rm -rf
NAME = fractol

all :$(MFLAGS) $(NAME)

$(MFLAGS):
	make -C ./mlxlib

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(MFLAGS) $(AFLAGS) -framework OpenGL -framework AppKit -o $(NAME)

fclean : clean
	$(RM) $(NAME)

clean :
	make clean -C ./mlxlib
	$(RM) ./*.o

re : fclean all

.PHONY : all fclean clean re