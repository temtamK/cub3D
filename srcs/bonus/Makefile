# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/18 00:54:15 by taemkim           #+#    #+#              #
#    Updated: 2021/06/15 21:55:24 by taemkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = gcc

HEADERS_PATH = ./includes/

INCLUDES = -I$(HEADERS_PATH)

CFLAGS = -Wall -Wextra -Werror -O3 -fsanitize=address
RM = rm -rf

DIR = $(shell pwd)

DIRSRC = src

MLX_OPENGL_PATH = ../../minilibx_opengl
MLX_LINUX_PATH = ../../minilibx_linux

MLX_PATH =

libftprintf = libft/libftprintf.a

LIB_ARG =

frameWORKS =

LINKS =

UNAME = $(shell uname)

OS_DIR =
ifeq ($(UNAME),Darwin)
	MLX_PATH = $(MLX_OPENGL_PATH)
	MLX_NAME = libmlx.dylib
	MLX_LIB = $(MLX_PATH)/$(MLX_NAME)
	LINKS = -L$(MLX_PATH)/
	frameWORKS += -framework OpenGL -framework Appkit
	INCLUDES += -I$(MLX_OPENGL_PATH)
	LOAD_DYLIB = install_name_tool -change $(MLX_NAME) $(DIR)/$(MLX_LIB) $(NAME)
	OS_DIR = osx
else ifeq ($(UNAME),Linux)
	MLX_PATH = $(MLX_LINUX_PATH)
	MLX_NAME = libmlx.a
	INCLUDES += -I$(MLX_LINUX_PATH)
	LINKS += -L$(MLX_PATH) -lXext -lX11 -lxcb -lXau -lXdmcp -lm
	MLX_LIB = $(MLX_PATH)/$(MLX_NAME)
	OS_DIR = linux
endif

SRC = $(addprefix $(DIRSRC)/, \
			main.c \
\
			$(addprefix parsing/,\
			backend.c  init.c images.c map.c sprites_parsing.c bmp.c\
			map_utils.c color.c resolution.c) \
\
			raycasting/raycast.c raycasting/walls.c\
\
			$(addprefix frontend/,\
			colors_handling.c frontend.c draw_scene.c minimap.c)\
\
			$(addprefix sprites/,\
			sprites_sort.c  init_sprites.c sprites.c)\
\
			garbage_collection/garbage_collector.c \
\
			$(addprefix events/,\
			loop.c  handlers.c keyboard_handler.c keyboard.c movements.c ennemies.c \
			mouse.c collisions.c handlers_2.c $(OS_DIR)/mouse_move.c \
			$(OS_DIR)/sound.c singletons.c\
	)\
\
			debug/debug_map.c debug/errors.c \
		)

OBJDIR = obj

OBJ = $(SRC:$(DIRSRC)/%.c= $(OBJDIR)/%.o)

OBJ_PATHS = $(shell ls -R $(DIRSRC) | grep / | sed 's/://g' | sed 's/src/$(OBJDIR)/g')

HEADERS = $(addprefix $(HEADERS_PATH), \
				cub3d.h events.h frontend.h \
				garbage_collection.h parsing.h raycast.h sprites.h\
			)

OBJBONUS = $(SRCBONUS:.c=.o)

all: $(NAME) $(HEADERS)

$(NAME): $(MLX_LIB) $(libftprintf) $(OBJ)
	@echo MLX : $(MLX_LIB)
	@echo COMPILING $(NAME)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(libftprintf) $(MLX_LIB) -o $(NAME) $(LINKS) $(frameWORKS)
	$(LOAD_DYLIB)


$(libftprintf):
	@echo "COMPILING libft"
	$(MAKE) $(LIB_ARG) all -C libft/ --quiet

$(MLX_LIB):
	@echo "COMPILING MLX"
	$(MAKE) -C $(MLX_PATH)/ --quiet

$(OBJDIR)/%.o: $(DIRSRC)/%.c $(HEADERS) $(MLX_LIB)
	@mkdir -p $(OBJ_PATHS)
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

clean:
	$(MAKE) -C libft/ clean
	$(MAKE) -C $(MLX_PATH) clean
	$(RM) $(OBJ) $(OBJBONUS)

fclean: clean
	$(MAKE) -C libft/ fclean
	$(RM) $(NAME)

lilclean:
	$(RM) $(OBJ) $(OBJBONUS)
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean

shadow_off:
	$(eval CFLAGS += -D SHADOW_MODE=0)

opti:
	$(eval CFLAGS += -O3)
	$(eval LIB_ARG += opti)

debug:
	$(eval CFLAGS += -g3 -fsanitize=address)
	$(eval LIB_ARG += debug)

QWERTY:
	$(eval CFLAGS += -D QWERTY=1)
