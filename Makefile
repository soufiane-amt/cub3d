# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: samajat <samajat@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 11:25:40 by samajat           #+#    #+#              #
#    Updated: 2023/01/06 19:35:08 by samajat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = cc

inc = -I includes/

CFLAGS =  -Wall -Wextra -Werror -g $(inc)

MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

RM =  rm -rf

DEFAULTSRC = $(addprefix settings/, set_player_to_default ray_settings)

GRSRC = $(addprefix graphic/events/, movesListener eventsListener  rotationsListener buttons)\
	$(addprefix graphic/image/, drawings_image)\
	$(addprefix texture/, texture texture_2)\
	$(addprefix graphic/3d/, project3dReality)\
	$(addprefix parsing/, extract_line fill_data layers map_handling map_utils utils)\
	$(addprefix utils/, ft_atoi get_next_line ft_strjoin ft_split ft_strcmp ft_strlcpy \
					ft_strncmp ft_strtrim ft_isdigit ft_strchr  ft_strdup  ft_strlen  ft_strnstr ft_substr ft_free_data)\

MSRC = $(addprefix math/, math math2 point_of_intersection projectionPlane)

SRC = cub3d $(MSRC) $(DEFAULTSRC) $(GRSRC) 

HEADERS = includes/cub3d.h


OBJ = $(addprefix src/,  $(SRC:=.o))

$(NAME) : $(OBJ)
	@$(CC) $(FLAGS)  $(MLXFLAGS) $(OBJ) -o $(NAME) -g

all : $(NAME)

%.o:%.c $(HEADERS)
	@$(CC) -c $< -o $@ $(CFLAGS) $(inc) 
	
clean :
	@$(RM) $(OBJ)

fclean : clean
	@$(RM) $(NAME)

re : fclean all

bonus : all
