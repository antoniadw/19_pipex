# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ade-woel <ade-woel@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/03 12:15:55 by ade-woel          #+#    #+#              #
#    Updated: 2025/02/03 16:23:48 by ade-woel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Definition 
NAME = pipex
CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

#Directories
SRCDIR = srcs/
OBJDIR = objs/
INCDIR = incl/
LIBFTDIR = incl/libft/
LIBFT = $(LIBFTDIR)/libft.a

#Sources and objects
SRC = 	paths.c \
		pipex.c \
		utils.c \

SRCS = $(addprefix $(SRCDIR), $(SRC))
OBJS = $(addprefix $(OBJDIR), $(SRC:.c=.o))

#Rules
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(OBJS) -o $(NAME) -L$(LIBFTDIR) -lft

$(OBJDIR)%.o : $(SRCDIR)%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -I$(INCDIR) -I$(LIBFTDIR) -c $< -o $@

#Libft compilation
$(LIBFT):
	@$(MAKE) -C $(LIBFTDIR)

clean:
	$(MAKE) clean -C $(LIBFTDIR)
	$(RM) $(OBJDIR)

fclean: clean
	$(MAKE) fclean -C $(LIBFTDIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
