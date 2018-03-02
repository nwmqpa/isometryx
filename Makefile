##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## makefile of the lib isometryx
##

SRC_DIR	=	sources

ROOT	=	.

SRC	=	$(SRC_DIR)/utils/my_calloc.c 		\
		$(SRC_DIR)/utils/my_memcpy.c		\
		$(SRC_DIR)/zones/memory_management.c	\
		$(SRC_DIR)/zones/zone_loading.c

FUNCS	=	--redefine-sym isometryx_create_zone=create_zone 		\
		--redefine-sym isometryx_create_tiled_zone=create_tiled_zone 	\
		--redefine-sym isometryx_destroy_zone=destroy_zone		\
		--redefine-sym isometryx_copy_zone=copy_zone			\
		--redefine-sym isometryx_load_tiles_in=load_tiles_in		\
		--redefine-sym isometryx_add_layer=add_layer			\
		--redefine-sym isometryx_add_column=add_column			\
		--redefine-sym isometryx_add_row=add_row			\
		--redefine-sym isometryx_copy_tiles=copy_tiles			\
		

NAME	=	libisometryx.so

OBJS	=	$(SRC:.c=.o)

V	?=	@

CC	=	gcc

CFLAGS	=	-I includes/ -I sfml_includes -fPIC -std=c99

LDFLAGS =	-shared

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
		$(V)gcc -o $(NAME) $(LDFLAGS) final.o
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
