NAME = minia

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include

SRCS =	src/data/mnist_loader.c \
		src/data/mnist_utils.c \
		src/network/activ_utils.c \
		src/network/init_reseau.c \
		src/network/mat_utils.c \
		src/network/math_utils.c \
		src/network/propagation.c \
		src/network/reseau_utils.c \
		src/train/train_utils.c \
		src/train/trainer.c \
		src/test/test_data.c \
		src/test/test_network.c \
		src/test/test_reseau.c \
		src/test/test_train.c \
		src/main.c

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CC ?= clang
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = $(addprefix -I, $(INC_DIR)) -MMD
LDLIBS = -lm

ECHO = printf
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
RED = \033[1;31m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@$(ECHO) "$(YELLOW)🔧 Édition des liens...$(RESET)\n"
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(LDLIBS) $(OBJS) -o $(NAME)
	@$(ECHO) "$(GREEN)Compilation terminée !$(RESET)\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(ECHO) "$(BLUE) Compilation de $<...$(RESET)\n"
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	@$(ECHO) "$(RED) Suppression des fichiers objets...$(RESET)\n"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@$(ECHO) "$(RED) Suppression de l'exécutable...$(RESET)\n"
	@rm -f $(NAME)

re: fclean all

clangd:
	@printf "CompileFlags:\n" > ./.clangd
	@printf "  Add:\n" >> ./.clangd
	@printf "    - \"-xc\"\n" >> ./.clangd
	@for FLAG in $(CFLAGS); do \
		printf "    - \"$$FLAG\"\n" >> ./.clangd; \
	done
	@for FLAG in $(CPPFLAGS); do \
		printf "    - \"$$FLAG\"\n" >> ./.clangd; \
	done
	@for FLAG in $(LDLIBS); do \
		printf "    - \"$$FLAG\"\n" >> ./.clangd; \
	done
	@for file in $(INC_DIR); do \
		printf "    - \"-I"$(shell pwd)"/"$$file"\"\n" >> .clangd; \
	done
	@printf "\n" >> ./.clangd
	@printf '$(BLUE)Les reglages de clangd sont maintenant disponible dans ./.clangd$(END)\n'

.PHONY: all clean fclean re

-include $(OBJS:.o=.d)
