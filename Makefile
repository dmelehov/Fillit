# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibeltek <ibeltek@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/02 20:23:08 by ibeltek           #+#    #+#              #
#    Updated: 2017/02/03 13:54:09 by ibeltek          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = ./read_file.c ./check_file.c ./write_in_lst.c ./create_map.c ./put_figure.c 

SRC2 = ./read_file.o ./check_file.o ./write_in_lst.o ./create_map.o ./put_figure.o 

HEADER = ./header.h

GCC = gcc -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(SRC2)
	$(GCC) $(SRC2) -I $(HEADER) -o $(NAME)

%.o: %.c $(HEADER)
	$(GCC) -c -o $@ $<
	
clean:
	rm -f $(SRC2)

fclean: clean
	rm -f $(NAME) 

re: fclean all