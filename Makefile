# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fballest <fballest@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/29 14:25:11 by fballest          #+#    #+#              #
#    Updated: 2021/12/21 12:39:43 by fballest         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DELETE_ON_ERROR:

# FILES NAMES #
NAME = philo

# SOURCES #
SRC = philosophers.c utils.c parser.c
OBJS = $(SRC:.c=.o)

# COMPILER #
CC = cc -Wall -Wextra -Werror -g3 -fsanitize=address -O0
CC2 = -l pthreaad

# COLOUR DEFINITION #
BLUE = \033[0;34m
GREEN = \033[1;32m
RESET = \033[0m

# COMPILING AND CLEANING INSTRUCTIONS #
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(BLUE)==========CREATING PHILO==========$(RESET)"
	@$(CC) ${OBJS} -o ${NAME}
	@echo "Philo file done"
	@echo "$(GREEN)==========WELLDONE==========$(RESET)"
	@echo "Success creating philo file"

clean:
	@$(RM) $(OBJS)
	@echo "$(GREEN)==========REMOVED==========$(RESET)"
	@echo "Success normal cleaning of philo"

fclean: clean
	@$(RM) $(OBJS)
	@$(RM) ${NAME}
	@echo "$(GREEN)==========TOTALLY REMOVED==========$(RESET)"
	@echo "Success deepest cleaning of philo"

re : clean all

.PHONY: all clean fclean re shell addsuffix