SRCS =	src/main.c \
		src/get_next_line_utils.c \
		src/get_next_line.c \
		src/validate_and_read_map.c \
		src/validate_letters_map.c \
		src/error.c \
		src/mover.c \
		src/split_map.c \
		src/validateMap.c \
		src/validateMap2.c \
		src/validateMap3.c \
		src/validate_textures.c \
		src/validate_colors.c \
		src/raycasting.c\
		src/raycasting2.c\
		src/key_move.c\
		src/utils.c\
		src/utils2.c \
		src/key_move_vision.c\
		src/ft_directions.c\
		src/ft_memset.c \
		src/ft_bzero.c \
		src/ft_memcpy.c \
		src/ft_memmove.c \
		src/ft_memchr.c \
		src/ft_memcmp.c \
		src/ft_strlen.c \
		src/ft_strlcpy.c \
		src/ft_strlcat.c \
		src/ft_strchr.c \
		src/ft_strrchr.c \
		src/ft_strnstr.c \
		src/ft_strncmp.c \
		src/ft_atoi.c \
		src/ft_isalpha.c \
		src/ft_split.c \
		src/ft_isdigit.c \
		src/ft_isalnum.c \
		src/ft_isascii.c \
		src/ft_isprint.c \
		src/ft_toupper.c \
		src/ft_tolower.c \
		src/ft_calloc.c \
		src/ft_strdup.c \
		src/ft_substr.c \
		src/ft_strjoin.c \
		src/ft_strtrim.c \
		src/ft_itoa.c \
		src/ft_strmapi.c \
		src/ft_striteri.c \
		src/ft_putchar_fd.c \
		src/ft_putstr_fd.c \
		src/ft_putendl_fd.c \
		src/ft_putnbr_fd.c \
		src/ft_lstnew.c	 \
		src/ft_lstadd_front.c \
		src/ft_lstsize.c \
		src/ft_lstlast.c \
		src/ft_lstadd_back.c \
		src/ft_lstdelone.c \
		src/ft_lstclear.c \
		src/ft_lstiter.c \
		src/ft_lstmap.c

OBJS = ${SRCS:.c=.o}
NAME = cub3d

MLXLINK = -L mlx
MINILIBX = -I mlx
OPENGL = -lmlx -framework OpenGL -framework AppKit

HEADER = include/cub3d.h
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
COMFILE_FLAGS = -I${HOME}/.brew/opt/readline/include
.c.o:
	${CC} ${CFLAGS} $(COMFILE_FLAGS) -I ${HEADER} -c $< -o ${<:.c=.o}
	
${NAME}:	${OBJS} ${HEADER}
			make -C mlx
			${CC} ${CFLAGS} $(COMFILE_FLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit ${OBJS} -o ${NAME}
all:		${NAME}

test:		${OBJS} ${HEADER}
			${CC}  ${CFLAGS} $(COMFILE_FLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit ${OBJS} -o ${NAME} && ./cub3d
clean: 		
			${RM} ${OBJS}
fclean: 	clean
			${RM} ${NAME}
			${RM} bonus
re:			fclean all
.PHONY: all clean fclean re
