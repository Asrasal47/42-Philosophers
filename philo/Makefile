# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/07 22:35:09 by arasal            #+#    #+#              #
#    Updated: 2022/12/20 06:01:41 by arasal           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler Variables
NAME	= philo
B_NAME	= philo_bonus
CFLAGS	= -Werror -Wall -Wextra -pthread

# File Variables
SRCS	= philo.c time.c my_atoi.c my_atoll.c philo_utils.c philo_run.c philo_actions.c
B_SRCS	= philo_bonus.c my_atoi_bonus.c my_atoll_bonus.c philo_utils_bonus.c philo_run_bonus.c
OBJS	= ${SRCS:.c=.o}
B_OBJS	= ${B_SRCS:.c=.o}

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

bonus: $(B_NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "$(MAGENTA)\rCompiling: $(notdir $<)\r\e[35C[OK]\n$(RESET)"

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(BOLD)\033[32mPhilo is Compiled! ༺ (\033[31m♥\033[32m_\033[31m♥\033[32m)༻\n"

$(B_NAME): $(B_OBJS)
	@$(CC) $(CFLAGS) $(B_OBJS) -o $(B_NAME)
	@echo "$(BOLD)\033[32mPhilo bonus is Compiled! ༺ (\033[31m♥\033[32m_\033[31m♥\033[32m)༻\n"

clean:
	@rm -f $(OBJS) $(B_OBJS)

fclean: clean
	@rm -f $(NAME) $(B_NAME)
	@echo "$(BOLD)\033[32mEverything is fcleaned! ✓ (\033[31m>_<\033[32m)\n"

re: clean all

.PHONY: all, clean, fclean, re, libft