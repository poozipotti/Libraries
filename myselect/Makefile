NAME = myselect
SRC = myselect.c 
IRDIR = ../../include
LIB = ../../lib -lncurses -lmy 
CFLAGS =  -I$(IRDIR) -L$(LIB)
all: 
	clear
	gcc $(SRC) -o $(NAME) $(CFLAGS)
clean:
	rm -f *.o
fclean:
	rm -f $(NAME)
re: fclean all

debug: fclean
	gcc $(SRC) -o $(NAME) -ggdb $(CFLAGS)
