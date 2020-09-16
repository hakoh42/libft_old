# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hakoh <hakoh@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/05 10:32:27 by hakoh             #+#    #+#              #
#    Updated: 2020/09/11 12:49:39 by hakoh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

FLAGS	=	-Wall -Wextra -Werror

SRCS	=	$(addprefix $(PATHSRCS), \
			ft_strlen.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strncmp.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_strnstr.c \
			ft_atoi.c \
			ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memccpy.c \
			ft_memmove.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_putstr_fd.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_itoa.c \
			ft_split.c \
			ft_strmapi.c \
			ft_strcpy.c \
			ft_strcat.c \
			ft_is_sep.c \
			ft_nb_len.c \
			ft_strncpy.c \
			ft_strndup.c \
			ft_mystrncpy.c \
			c_pos_in_str.c \
			ft_lstnew.c \
			ft_lstadd_back.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c \
			get_next_line.c \
			get_next_line_utils.c \
			ft_strcmp.c)

OBJS	=	$(SRCS:.c=.o)

PATHINC	=	./inc/

HEADERS	=	libft.h get_next_line.h

PATHSRCS=	./src/

all: $(NAME)

$(NAME): $(OBJS) $(addprefix $(PATHINC), $(HEADERS))
		ar rc $(NAME) $(OBJS)
		ranlib $(NAME)

%.o: %.c
		gcc -o $@ -c $< $(FLAGS) -I $(PATHINC)

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re:
		$(MAKE) fclean
		$(MAKE) all

.PHONY		: all clean fclean re