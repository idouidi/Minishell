# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/08 11:53:56 by idouidi           #+#    #+#              #
#    Updated: 2021/07/07 13:23:26 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = srcs/main.c srcs/minishell.c srcs/builtin/builtin.c \
		srcs/builtin/pwd/pwd.c srcs/pipe/file_exist.c \
		srcs/builtin/echo/echo.c srcs/builtin/exit/exit.c \
		srcs/builtin/cd/cd.c srcs/builtin/export/export.c \
		srcs/builtin/env/env.c srcs/builtin/unset/unset.c srcs/builtin/unset/utils_unset.c \
		srcs/utils/split_minishell.c srcs/utils/split_minishell_utils.c \
		srcs/utils/split_minishell_utils_2.c srcs/utils/split_minishell_utils_3.c \
		srcs/utils/utils_line.c srcs/utils/utils_list.c srcs/builtin/export/export_utils.c \
		srcs/builtin/export/export_utils2.c srcs/builtin/export/export_utils3.c \
		srcs/utils/split_minishell_utils_4.c srcs/utils/split_minishell_utils_5.c srcs/utils/utils_line_2.c \
		srcs/redirection/redirection.c srcs/redirection/open_the_door.c srcs/redirection/utils_redirection.c \
		srcs/pipe/pipe.c srcs/pipe/utils_pipe.c srcs/utils/utils_list_2.c srcs/redirection/utils_open_the_door.c \

LIBFTPATH	= project/libft 
LIBOBJ		= project/libft/libft.a
@OBJS		= $(SRCS:.c=.o)
CFLAGS		= -Wall -Wextra -Werror -g -fsanitize=address
NAME		= minishell

all: $(NAME)


$(NAME): $(@OBJS)
	@echo "\033[33m- Compiling libft..."
	$(MAKE) -C $(LIBFTPATH)
	@echo "\033[32mDone."
	@echo "\033[33m- Compiling minishell..."
	@gcc ${CFLAGS} -o ${NAME} ${@OBJS} $(LIBOBJ) -lreadline 
	#-L /Users/$(USER)/.brew/opt/readline/lib -I/Users/$(USER)/.brew/opt/readline/include
	@echo "\033[32mDone."
	@echo "\033[31m========================"
	@echo "  YOUR SHELL IS READY"
	@echo "========================"



clean:
	rm -rf $(@OBJS)
	@cd $(LIBFTPATH) && make clean

fclean: clean
	@rm -f $(NAME)
	cd $(LIBFTPATH) && make fclean

re: fclean all


.PHONY: libft, all, clean, fclean, re
.SILENT:
