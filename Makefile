MUTE		=
NAME		=	cub3D
BMP_FILE	=	./screenshot.bmp
MLIBX		=	libmlx.dylib

SRCS			=	cub3d.c \
					utils/*.c \
					parse/*.c \
					GNL/*.c \
					display/*.c \

SRCS_BONUS		=	bonus/cub3d.c \
					bonus/utils/*.c \
					bonus/parse/*.c \
					bonus/GNL/*.c \
					bonus/display/*.c \

CC			=	clang
CFLAGS		=	-Wall -Wextra -Werror -fsanitize=address
RM			=	rm -f
RMRF		=	rm -rf

UNAME		:=	$(shell uname)

ifeq ($(UNAME), Darwin)
$(NAME):
			@echo "\033[33m[Cub3D MACOS compilation...]"
			$(MUTE) $(MAKE) -C mlx all
			$(MUTE) cp ./mlx/$(MLIBX) .
			$(CC) $(CFLAGS) -g3 -Ofast -o $(NAME) -Imlx $(SRCS) -Lmlx -lmlx -lm -framework OpenGL -framework AppKit
			@echo "\033[32m[ ./cub3D created ]"
endif

ifeq ($(UNAME), Linux)
$(NAME):
			$(MUTE)echo "\033[31;1mCompiling for Linux...\033[0m"
			$(MUTE)chmod 777 mlx_linux/configure
			$(MUTE) $(MAKE) -C mlx_linux all
			$(MUTE) $(CC) $(CFLAGS) -g3 -o $(NAME) $(SRCS) -Imlx_linux -Lmlx_linux -lmlx -lmlx_Linux -L/usr/lib -lXext -lX11 -lm
			$(MUTE)echo "\033[32m[ ./cub3D created ]"
endif

all:		$(NAME)

ifeq ($(UNAME), Darwin)
bonus:		$(NAME_BONUS)
				@echo "\033[33m[Cub3D MACOS compilation with bonus...]"
				$(MUTE) $(MAKE) -C mlx all
				$(MUTE) cp ./mlx/$(MLIBX) .
				$(MUTE) $(CC) $(CFLAGS) -g3 -Ofast -o cub3D_bonus -Imlx $(SRCS_BONUS) -Lmlx -lmlx -lm -framework OpenGL -framework AppKit
				@echo "\033[32m[ ./Cub3D_bonus created ]"
endif

ifeq ($(UNAME), Linux)
bonus:		$(NAME_BONUS)
				$(MUTE)echo "\033[33m[Cub3D Linux compilation with bonus...]"
				$(MUTE)chmod 777 mlx_linux/configure
				$(MUTE) $(MAKE) -C mlx_linux all
				$(MUTE) $(CC) $(CFLAGS) -g3 -o cub3D_bonus $(SRCS_BONUS) -Imlx_linux -Lmlx_linux -lmlx -lmlx_Linux -L/usr/lib -lXext -lX11 -lm
				$(MUTE)echo "\033[32m[ ./cub3D_bonus created ]"
endif

ifeq ($(UNAME), Darwin)
clean:
			$(MUTE) echo "\033[31m[Remove last version...]"
			$(MUTE) $(MAKE) -C mlx clean
			$(MUTE) $(RMRF) Cub3D.dSYM cub3D_bonus.dSYM
			$(MUTE) $(RM) $(BMP_FILE)
endif

ifeq ($(UNAME), Linux)
clean:
			$(MUTE) echo "\033[31m[Remove last version...]"
			$(MUTE) chmod 777 mlx_linux/configure
			$(MUTE) $(MAKE) -C mlx_linux clean
			$(MUTE) $(RMRF) Cub3D.dSYM cub3D_bonus.dSYM
			$(MUTE) $(RM) $(BMP_FILE)
endif

fclean:		clean
			$(MUTE)$(RM) $(MLIBX)
			$(RM) $(NAME)
			$(RM) cub3D_bonus


re:			fclean all

.PHONY:		$(NAME) all bonus test clean fclean re

