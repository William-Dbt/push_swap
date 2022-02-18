# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/18 14:12:28 by wdebotte          #+#    #+#              #
#    Updated: 2022/02/18 16:32:47 by wdebotte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
# => TEXT
################################################################################

END		= \033[0m
BOLD	= \033[1m

RED		= \033[91m
GREEN	= \033[92m
YELLOW	= \033[93m

################################################################################
# => VARIABLES
################################################################################

NAME		= push_swap

PATHSRCS	= ./srcs/
PATHHEADERS	= ./includes/
PATHLIBFT	= ./libft/
PATHNULL	= /dev/null

SRCS		= ${PATHSRCS}push_swap.c
OBJS		= ${SRCS:.c=.o}
HEADERS		= ${PATHHEADERS}push_swap.h

CC			= clang
CFLAGS		= -Wall -Wextra -Werror
INCS		= -I${PATHHEADERS} -I${PATHLIBFT}${PATHHEADERS}

RM			= rm -rf
MAKE		= make -C

NORM		= norminette
FLAGNORMC	= -R CheckForbiddenSourceHeader
FLAGNORMH	= -R CheckDefine

LIBFT		= -L${PATHLIBFT} -lft

################################################################################
# => RULES
################################################################################

.c.o:
				@echo "${BOLD}${YELLOW}Compiling:${END}\t$<"
				@${CC} ${CFLAGS} ${INCS} -c $< -o ${<:.c=.o} >${PATHNULL}

all:		${NAME}

${NAME}:	${OBJS}
				@echo "${BOLD}${GREEN}Building:${END}\tlibft.a"
				@${MAKE} ${PATHLIBFT} >${PATHNULL}
				@echo "${BOLD}${GREEN}Building:${END}\t${NAME}"
				@${CC} ${OBJS} ${INCS} ${LIBFT} -o ${NAME} >${PATHNULL}

clean:
				@echo "${BOLD}${RED}Removing:${END}\tAll .o files"
				@${RM} ${OBJS} >${PATHNULL}

fclean:		clean
				@${MAKE} ${PATHLIBFT} fclean >${PATHNULL}
				@echo "${BOLD}${RED}Removing:${END}\t${NAME}"
				@${RM} ${NAME} >${PATHNULL}

re:			fclean all

norminette:
				@echo "${BOLD}${YELLOW}Norminette:${END}\tAll .c files"
				${NORM} ${FLAGNORMC} ${SRCS}
				@echo "${BOLD}${GREEN}Norminette:${END}\tOK !"
				@echo "${BOLD}${YELLOW}Norminette:${END}\tAll .h files"
				${NORM} ${FLAGNORMH} ${HEADERS}
				@echo "${BOLD}${GREEN}Norminette:${END}\tOK !"

.PHONY:		all clean fclean re norminette

################################################################################
