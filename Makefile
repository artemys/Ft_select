# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aliandie <aliandie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/26 13:38:59 by aliandie          #+#    #+#              #
#    Updated: 2015/06/13 19:22:52 by aliandie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select
CCLIB =  -lncurses libft/libft.a
CCFLAGS = -Wall -Werror -Wextra  -I ./includes
SRCDIR = src
OBJDIR = obj
INCDIR = includes libft/includes

SRC = 	main.c\
		delete_list.c\
		getkey.c\
		getwinsize.c\
		print_list.c\
		term_rest.c\
		tools_init.c\
		signal_handler.c\
		exit_select.c\
		error.c\

SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJS = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))
INCS = $(addprefix -I , $(INCDIR))

all: $(NAME)
$(NAME): build $(OBJS)
		@make -C libft
		@gcc $(CCLIB) -o $(NAME) $(OBJS)
build:
		@mkdir -p $(OBJDIR)
clean:
		@make -C libft clean
		@rm -f $(OBJS)
fclean: clean
		@make -C libft fclean
		@rm -f $(NAME)
re: fclean all

dev : all
		@./$(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
		@gcc -c $(CCFLAGS) $(INCS) -o $@ $<
