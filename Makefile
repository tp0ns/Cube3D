CC = gcc

NAME = Cub3D

#Linux compilation
FLAGS = -Wall -Wextra -Werror -lm -lbsd -lX11 -lXext
# FLAGS = -Wall -Wextra -Werror -lm -lbsd -lX11 -lXext -fsanitize=address

# FLAGS = -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit
# FLAGS = -Wall -Wextra -Werror -fsanitize=address -lmlx -framework OpenGL -framework AppKit

INCLUDE = -I cub.h ./minilibx-linux/libmlx.a Libft/libft.a

SRCS =	main.c leave.c game.c inputs.c screenshot.c\
		parsing/get_param.c parsing/map.c parsing/texture_res.c parsing/colors.c parsing/check_param.c parsing/sprite.c\
		dda/dda.c dda/draw.c dda/draw_texture.c dda/draw_sprite.c

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS) 
		$(MAKE) -C ./Libft/
		gcc -o $(NAME) $(OBJS) $(INCLUDE) $(FLAGS) 

all : $(NAME)

clean :
		rm -f $(OBJS)
		$(MAKE) clean -C ./Libft
fclean : clean
		rm -f $(NAME)
		rm -f libft.a
		$(MAKE) fclean -C ./Libft
re : fclean all

# a enlever
run : all
		./Cub3D map.cub

# %.o: %.c
	# $(CC) $(FLAGS) -I cube3d.h -c $<  -o $(<:.c=.o)


# valgrind --leak-check=full --show-leak-kinds=definite --track-origins=yes --log-file=valgrind-out.txt ./Cub3D map.cub