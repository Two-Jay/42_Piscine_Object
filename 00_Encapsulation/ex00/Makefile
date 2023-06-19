CC = c++
CFLAGS = -Wall -Wextra -Werror
VERSION = -std=c++98

NAME = DivideAndConquer
OBJ_DIR = ./obj

SOURCE = main.cpp \
		Bank.cpp \
		Account.cpp \

OBJ = $(addprefix $(OBJ_DIR)/, $(SOURCE:.cpp=.o))

$(OBJ_DIR)/%.o : %.cpp
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(VERSION) -c $< -o $@

all :
	@$(MAKE) $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(VERSION) $(OBJ) -o $(NAME)

clean :
	rm -rf $(OBJ)

fclean :
	@$(MAKE) clean
	rm -rf $(NAME)

re :
	@$(MAKE) clean
	@$(MAKE) all