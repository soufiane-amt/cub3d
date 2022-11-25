# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: samajat <samajat@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 11:25:40 by samajat           #+#    #+#              #
#    Updated: 2022/11/25 12:05:43 by samajat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = cc

inc = -I includes/

CFLAGS =  -Wall -Wextra -Werror  -I includes/

MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

RM =  rm -rf

DEFAULTSRC = $(addprefix default_settings/, set_player_to_default)

GRSRC = $(addprefix graphic/rendering/, rendering)\
	 	$(addprefix graphic/eventsListener/, eventsListener , movesListener,  rotationsListener)\
 		$(addprefix graphic/rayCasting/, rays)\
		$(addprefix graphic/, player)
		
MSRC = $(addprefix math/, math)

SRC = cub3d $(GRSRC) $(MSRC) $(DEFAULTSRC)

HEADERS = cub3d.h


OBJ = $(addprefix src/,  $(SRC:=.o))

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(MLXFLAGS) $(OBJ) -o $(NAME)

all : $(NAME)

%.o : %.c $(HEADERS)
	$(CC) -c $< -o $@ $(inc)
	
clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all
