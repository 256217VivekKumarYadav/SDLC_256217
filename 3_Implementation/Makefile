PROJ_NAME = AIMatrix
TEST_PROJ_NAME = Test_$(PROJ_NAME)


SRC =	src/build_list.c \
	src/case_matrixgame.c \
	src/chose_alum_nb.c \
	src/chose_game_mode.c \
	src/chose_lvl.c \
	src/game_mode.c \
	src/key_left_right.c \
	src/key_up_down.c \
	src/list_configs.c \
	src/loop.c \
	src/lvl_check.c \
	src/main.c \
	src/matrixgame.c \
	src/my.c \
	src/print_list.c \
	src/print_mode.c \
	src/print_opti.c \
	src/chose_game_structure.c \
	src/chose_alum_per_line.c \
	src/lets_take_a_screenshot.c \
	src/my_double_malloc.c \
	src/show_win.c

CFLAGS += -I./include

LDFLAGS = -W -lncurses

RM =	rm -f

CC = gcc

OBJS=	$(SRC:.c=.o)

COV_SRC =test/test_wmcs.c

TEST_SRC = test/test_playermode.c \
unity/unity.c 
INC_H = include
INC_T = unity

#To check if the OS is Windows or Linux and set the executable file extension and delete command accordingly
ifdef OS
   RM = del 
   FixPath = $(subst /,\,$1)
   EXEC = exe
else
   ifeq ($(shell uname), Linux)
      RM = rm -rf
      FixPath = $1
	  EXEC = out
   endif
endif

all: $(PROJ_NAME)

$(PROJ_NAME): $(OBJS)
	$(CC) -o $(PROJ_NAME) $(OBJS) $(LDFLAGS)
#gcc -I $(INC_H) $(SRC) main.c -o $(call FixPath,$(PROJ_NAME).$(EXEC))

run:
	$(call FixPath,$(PROJ_NAME).$(EXEC))

clean:
	$(RM) $(OBJS)
	$(RM) *.DAT
	$(RM) *.$(EXEC)
	$(RM) *.gcda
	$(RM) *.gcno
	$(RM) *.c.gcov	

test:
	gcc -I $(INC_H) -I $(INC_T) $(TEST_SRC) $(SRC) -o $(call FixPath,$(TEST_PROJ_NAME).$(EXEC))
	./$(call FixPath,$(TEST_PROJ_NAME).$(EXEC))

fclean: clean
	$(RM) $(PROJ_NAME)

re: fclean all

coverage:
	cp test/test_wmcs.c .
	gcc -fprofile-arcs -ftest-coverage -I $(INC_H) -I $(INC_T) unity/unity.c test/test_wmcs.c $(SRC) -o $(call FixPath, $(TEST_PROJ_NAME).$(EXEC))
	$(call FixPath, ./$(TEST_PROJ_NAME).$(EXEC))
	gcov -a $(COV_SRC)
	$(RM) *.$(EXEC)
	$(RM) *.gcda
	$(RM) *.gcno
	$(RM) *.c.gcov
	$(RM) *.DAT
	$(RM) test_wmcs.c


cppcheck:
	cppcheck --enable=all $(SRC)

debug:
	gcc -I $(INC_H) $(SRC) -g -o $(PROJ_NAME).$(EXEC)
	gdb $(PROJ_NAME).$(EXEC)


valgrind:
	valgrind ./$(TEST_PROJ_NAME).$(EXEC)

.PHONY: all clean fclean re run test doc
