# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: samajat <samajat@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 11:25:40 by samajat           #+#    #+#              #
#    Updated: 2022/12/01 11:06:49 by samajat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = gcc

inc = -I includes/

CFLAGS =  -Wall -Wextra -Werror $(inc)

MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

RM =  rm -rf

DEFAULTSRC = $(addprefix default_settings/, set_player_to_default)

GRSRC = $(addprefix graphic/rendering/, rendering)\
	$(addprefix graphic/rayCasting/, rays)\
	$(addprefix graphic/, player)\
	$(addprefix graphic/events/, movesListener eventsListener  rotationsListener)\
	$(addprefix graphic/image/, image)\
		
MSRC = $(addprefix math/, math)

SRC = cub3d $(MSRC) $(DEFAULTSRC) $(GRSRC) 

HEADERS = includes/cub3d.h


OBJ = $(addprefix src/,  $(SRC:=.o))

$(NAME) : $(OBJ)
	@$(CC) $(FLAGS)  $(MLXFLAGS) $(OBJ) -o $(NAME)

all : $(NAME)

%.o:%.c $(HEADERS)
	@$(CC) -c $< -o $@ $(CFLAGS) $(inc)  -g
	
clean :
	@$(RM) $(OBJ)

fclean : clean
	@$(RM) $(NAME)

re : fclean all
