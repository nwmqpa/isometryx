##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## makefile of the lib isometryx
##

SRC_DIR	=	sources

ROOT	=	.

SRC	=	$(SRC_DIR)/utils/my_calloc.c \
		$(SRC_DIR)/isometryx.c	

FUNCS	=	--redefine-sym isometryx_parse_zone=parse_zone

NAME	=	libisometryx.so

OBJS	=	$(SRC:.c=.o)

V	?=	@

CC	=	gcc

CFLAGS	=	-I includes/ -I sfml_includes -fPIC

#-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-


GREEN   =       \e[1;32m

WHITE   =       \e[0m

ORANGE  =       \e[1;33m

RED     =	\e[1;35m

BLUE    =	\e[1;34m

#_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-


.PHONY: 	all
all:		$(NAME)
		$(eval SYSCALLS := $(shell nm $(NAME) | grep " U " | sed -e "s/ //g" | sed -e "s/U//g"))
		$(eval SYSCALLS := $(join $(addprefix --redefine-sym~isometryx_,$(addsuffix =,$(SYSCALLS))), $(SYSCALLS)))
		$(eval SYSCALLS := $(shell echo $(SYSCALLS) | sed -e "s/~/ /g"))
		$(V)objcopy --prefix-symbols=isometryx_ $(NAME)
		$(V)objcopy $(FUNCS) $(SYSCALLS) $(NAME)

$(NAME):	$(OBJS)
		$(V)ld -r -o final.o $(OBJS)
		$(V)gcc -shared -o $(NAME) final.o
		$(V)printf "$(GREEN)Creating isometryx library.\n$(WHITE)"
clean:
		$(V)printf "$(ORANGE)Removing isometryx objects.\n$(WHITE)"
		$(V)rm -f $(OBJS)
		$(V)rm -f final.o

fclean: 	clean
		$(V)printf "$(RED)Removing isometryx library.\n$(WHITE)"
		$(V)rm -f $(NAME)

re:		fclean
		$(V)make --no-print-directory all 

%.o:		%.c
		$(V)printf "$(BLUE)Compiling [$(ORANGE)$(notdir $<)$(BLUE) -> $(RED) $(notdir $@) $(BLUE)]\n$(WHITE)"
		$(V)$(CC) -o $@  -c $< $(CFLAGS)
