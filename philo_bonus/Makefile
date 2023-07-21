# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/23 01:59:22 by arasal            #+#    #+#              #
#    Updated: 2022/12/26 15:44:52 by arasal           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler Variables
NAME	= philo_bonus
CFLAGS	= -Werror -Wall -Wextra -pthread

# File Variables
SRCS	= philo_bonus.c time_bonus.c my_atoi_bonus.c my_atoll_bonus.c\
philo_utils_bonus.c philo_run_bonus.c philo_actions_bonus.c
OBJS	= ${SRCS:.c=.o}

BOLD	= \033[1m
BLACK	= \033[30;1m
RED		= \033[31;1m
GREEN	= \033[32;1m
YELLOW	= \033[33;1m
BLUE	= \033[34;1m
MAGENTA	= \033[35;1m
CYAN	= \033[36;1m
WHITE	= \033[37;1m
RESET	= \033[0m

# //= Recipes =//

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< && printf "$(MAGENTA)\rCompiling: $(notdir $<)\r\e[35C[OK]\n$(RESET)"

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(BOLD)\033[32mPhilo is Compiled! ༺ (\033[31m♥\033[32m_\033[31m♥\033[32m)༻\n"

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)
	@echo "$(BOLD)\033[32mEverything is fcleaned! ✓ (\033[31m>_<\033[32m)\n"

re: clean all

.PHONY: all, clean, fclean, re, libft
