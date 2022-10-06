# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dalonso <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/17 04:57:18 by dalonso           #+#    #+#              #
#    Updated: 2020/11/17 04:57:21 by dalonso          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

MAIN = main.c

HEADER		= 	include

OBJ_FILES =             		vecalg1.c\
            			        color.c\
            			        canvas.c\
            			        light.c\
            			        camera.c\
            			        scene.c\
            			        sphere.c\
            			        render.c\
            			        raytrace.c\
            			        object.c\
            			        ray.c\
            			        intersection.c\
            			        plane.c\
            			        square.c\
            			        cylinder.c\
            			        triangle.c\
            			        parse.c\
            			        get_next_line.c\
            			        get_next_line_utils.c\
            			        parse_objects.c\
            			        parse_utils_1.c\
            			        bmp.c\
            			        vecalg2.c\
            			        parse_scene_elems.c\
            			        parse_utils_2.c\
            			        mlx_handle.c\

LIB_MLX = libmlx.a

MLX = minilibx_opengl_20191021

OBSJ_DIR = src

SRCS	= $(addprefix ${OBSJ_DIR}/, ${OBJ_FILES})

RM    = rm -f


CFLAGS = -Wall -Wextra -Werror

FLAG_MLX = libmlx.a -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(SRCS) $(MAIN) $(HEADER)
	make -C $(MLX)
	mv $(MLX)/$(LIB_MLX) ./
	gcc $(FLAG_MLX) $(MAIN) $(SRCS) -o $(NAME)

%.o: %.c
	gcc -g -c $(CFLAGS) -o $@ $<

clean:
	$(RM) *.o
	$(RM) $(MLX)/*.o

fclean: clean
	$(RM) *.bmp
	$(RM) $(NAME) $(MLX_LIB) ./mlx/$(MLX_LIB)

re: fclean all

.PHONY: all clean fclean re
