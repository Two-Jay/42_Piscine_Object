
NAME			= ex01
CXX				= c++
CXXFLAGS		= -Wall -Wextra -Werror -std=c++98

RM				= rm -rf
OBJDIR			= ./obj/
SRCS			= $(wildcard *.cpp)
					
OBJS_FILE		= $(SRCS:.cpp=.o)
OBJS			= $(addprefix $(OBJDIR), $(OBJS_FILE))

all:			$(NAME)

$(NAME):		check_obj $(OBJS)
				$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
				@echo "\033[0;92m* $(NAME) was created *\033[0m"
				@./$(NAME)

$(OBJDIR)%.o : %.cpp
				$(CXX) $(CXXFLAGS) $< -c -o $@

check_obj:
				@mkdir $(OBJDIR)
clean:
				@$(RM) $(OBJDIR)/*.o
				@$(RM) $(OBJDIR)

fclean:			
				@$(RM) $(OBJDIR)/*.o
				@$(RM) $(OBJDIR)
				@$(RM) $(NAME)
				@echo "\033[0;91m* $(NAME) was removed *\033[0m"

re:				fclean all

.PHONY:			all clean fclean re