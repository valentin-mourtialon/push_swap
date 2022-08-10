# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmourtia <vmourtia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/10 11:13:46 by vmourtia          #+#    #+#              #
#    Updated: 2022/08/10 17:46:05 by vmourtia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 		srcs/arguments_checker.c \
			srcs/stack_manipulation.c \
			srcs/sort_input_stack.c \
			srcs/main.c

UTILS = 	utils/ft_isdigit.c \
			utils/ft_itoa.c \
			utils/ft_putstr_fd.c \
			utils/ft_strlen.c \
			utils/ft_swap.c

# Take the variable ${SRCS} which is a string composed of words separeted
# by spaces, and for each word, replace the suffix "c" with "o".
OBJS = 		${SRCS:c=o} ${UTILS:c=o}

NAME =		push_swap

CC = 		gcc

CFLAGS = 	-Wall -Werror -Wextra

# Give the path to find our headers.
INC = 		-I includes/

RM = 		rm -f

all : 		${NAME}

# .c.o: 
# is equal to
# %.o : %.c 
# so the "$<" refers to "%.c"
# A pattern rule %.o : %.c says how to make any file stem.o from another file stem.c.
%.o : %.c
			${CC} ${CFLAGS} ${INC} -c $< -o $@ -g
# The recipe uses the automatic variables ‘$@’ and ‘$<’ 
# to substitute the names of the target file and the 
# source file in each case WHERE THE RULE APPLIE.


${NAME} :	${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS}

clean:
			${RM} ${OBJS}

# fclean executes clean then remove the program.
fclean:		clean
			${RM} ${NAME}

# "re" compile all the project after deleting all the file that had been created.
re:			fclean 
			all

# All the targets that are not meant to be created once the commands are executed.
# For example, ther's no file "clean" created after the command rm -f *.o is executed.
# So, if a file in the same directory than the Makefile is called "clean", 
# the command will never be executed. 
.PHONY:		all clean fclean re
