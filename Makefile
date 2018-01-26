##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

CC	=	gcc

AR	=	ar rc

RM 	=	rm -f

MK	=	mkdir -p

CP	=	cp

SRC	=	my_printf.c			\
		conv_base.c			\
		base_flags.c			\
		put_functions.c			\
		str_functions.c			\
		put_unsigned.c			\
		big_s.c

OBJDIR	=	lib/obj/

SRCDIR = 	lib/src/

OBJ	=	$(addprefix $(OBJDIR), $(SRC:.c=.o))

CLFAG	+=	-W
CFLAG	+=	-Wall
CFLAG	+=	-Wextra
CFLAG	+=	-g3

LDLIB	=	-Iinclude/

NAME	=	libmy.a

$(OBJDIR)%.o:	$(SRCDIR)%.c
	$(MK) $(OBJDIR)
	$(CC) $(CFLAG) $(LDLIB) -c $< -o $@

all:	$(NAME)

$(NAME):	$(OBJ)
	$(AR) $(NAME) $(OBJ)

clean:
	$(RM) -r $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: clean fclean re all
