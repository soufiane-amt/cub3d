# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: samajat <samajat@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 11:25:40 by samajat           #+#    #+#              #
#    Updated: 2022/11/23 22:16:37 by samajat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = cc

inc = -I includes/

CFLAGS =  -Wall -Wextra -Werror  -I includes/

MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

RM =  rm -rf

GRSRC = $(addprefix graphic/rendering/, rendering)\
		$(addprefix graphic/, player)
		
MSRC = $(addprefix math/, math)

SRC = cub3d $(GRSRC) $(MSRC)

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
