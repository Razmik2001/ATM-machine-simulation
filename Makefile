NAME    = ATM_test

CC      = g++
CFLAGS  = -Wall -Wextra -Werror -std=c++11 -g -ggdb3
RM      = rm -f

# Ищем все .cpp файлы рекурсивно
SRCS    = $(shell find . -name "*.cpp")
OBJS    = $(SRCS:.cpp=.o)
DEPS    = $(OBJS:.o=.d)

# Правило компиляции с генерацией зависимостей
%.o: %.cpp
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

# Подключаем автоматически сгенерированные зависимости
-include $(DEPS)

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
