# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: samajat <samajat@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 11:25:40 by samajat           #+#    #+#              #
#    Updated: 2022/11/23 12:08:04 by samajat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = cc

inc = -I includes/

FLAGS =  -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit $(inc)


RM =  rm -rf


SRC = cub3d

HEADERS = cub3d.h

OBJ = $(addprefix src/,  $(SRC:=.o))

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

all : $(NAME)

%.o : %.c $(HEADERS)
	$(CC) $(FLAGS) -c $< -o $@ $(inc)
	
clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all
