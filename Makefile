NAME = fdf
INCLUDEPEATH = libft/
LIBFT = libft.a
SRCS = main.c\
	read_parse.c\
	push_key.c\
	draw.c\
	bonus.c\
	init.c\
	matrice.c\
	push_line.c\
	image.c\
	
SCHOOL= -I /usr/local/include
HOOSE= libmlx.a
DSRCS=./srcs/
FLAGS = -framework OpenGL -framework AppKit
OBJS= $(SRCS:.c=.o)

all:$(NAME)
%.o:$(DSRCS)%.c
	@gcc -Wall -Werror -Wextra -o $@ -c $<
$(NAME): $(LIBFT) $(OBJS)
	cc $(SCHOOL) -o $(NAME) $(INCLUDEPEATH)$(LIBFT) $(OBJS) -L /usr/local/lib/ -lmlx $(FLAGS)
$(LIBFT):
	@cd libft && make
clean:
	@cd libft && make clean
	@rm -rf $(OBJS)
fclean: clean
	@cd libft && make fclean
	@rm -rf $(NAME)
re: fclean all
