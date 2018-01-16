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

CPDIR	=	include/printf.h

MY	=	lib/printf.h

SRC	=	my_printf.c			\
		big_s.c				\
		put_bases.c			\
		put_functions.c			\
		str_functions.c

OBJDIR	=	lib/obj/

SRCDIR = 	lib/src/

OBJ	=	$(addprefix $(OBJDIR), $(SRC:.c=.o))

CLFAG	+=	-W
CFLAG	+=	-Wall
CFLAG	+=	-Wextra
CFLAG	+=	-g3

INC	=	-Ilib/

NAME	=	libprtf.a

$(OBJDIR)%.o:	$(SRCDIR)%.c
	$(MK) $(OBJDIR)
	$(CC) $(CFLAG) $(INC) -c $< -o $@

all:	$(NAME)

$(NAME):	$(OBJ)
	$(AR) $(NAME) $(OBJ)
	$(CP) $(MY) $(CPDIR)

clean:
	$(RM) -r $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: clean fclean re all
