# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/13 19:49:18 by taemkim           #+#    #+#              #
#    Updated: 2021/05/19 20:13:40 by taemkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

MANDATORY_PATH = ./srcs/mandatory

BONUS_PATH = ./srcs/bonus

CUB_PATH = $(MANDATORY_PATH)

MAKE = make

MAKE_ARGS =

RM=rm -rf

all:
	$(MAKE) -C $(CUB_PATH) $(MAKE_ARGS) all
	@cp $(CUB_PATH)/$(NAME) .

clean:
	$(MAKE) -C $(MANDATORY_PATH) clean
	$(MAKE) -C $(BONUS_PATH) clean

clean_mandatory:
	$(MAKE) -C $(MANDATORY_PATH) fclean
	$(RM) $(NAME)

fclean: clean
	$(MAKE) -C $(MANDATORY_PATH) fclean
	$(MAKE) -C $(BONUS_PATH) fclean
	$(RM) $(NAME)

lilclean:
	$(RM) $(OBJ) $(OBJBONUS)
	$(RM) $(NAME)

re: fclean all

bonus: clean_mandatory
	$(eval CUB_PATH = $(BONUS_PATH))
	$(MAKE) -C $(CUB_PATH) $(MAKE_ARGS) all
	@cp $(CUB_PATH)/$(NAME) .

.PHONY: clean fclean

opti: fclean
	$(eval MAKE_ARGS += opti)

debug:
	$(eval MAKE_ARGS += debug)

QWERTY:
