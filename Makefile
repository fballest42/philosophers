# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fballest <fballest@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/29 14:25:11 by fballest          #+#    #+#              #
#    Updated: 2022/06/09 13:49:11 by fballest         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DELETE_ON_ERROR:

# FILES NAMES #
NAME = philo

# SOURCES #
SRC = philosophers.c utils.c parser.c helpers.c routine.c
OBJS = $(SRC:.c=.o)

# COMPILER #
CC = cc -Wall -Wextra -Werror -O3 #3 -fsanitize=thread -O0
CC2 = -l pthread

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