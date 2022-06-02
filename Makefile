NAME = push_swap.a

AR = ar
ARFLAGS = crs

RM = rm
RMFLAG = -f

INCLUDES = ./push_swap.h

SRCS= \
	./check.c	\
	./get_num.c	\
	./helper.c	\
	./init.c	\
	./sort_helper.c	\
	./sort_helper2.c	\
	./sorter.c	\
	./operations/push_set.c	\
	./operations/reverse_set.c	\
	./operations/rotate_set.c	\
	./operations/swap_set.c	\

EXE = push_swap

OBJS = $(SRCS:.c=.o)

CC		= gcc
RM		= rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}

		${CC} ${CFLAGS} ./push_swap.c ${OBJS} -o ${EXE}

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${EXE}

re:		fclean all
