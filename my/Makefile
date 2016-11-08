SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Werror --pedantic -I$(IDIR)
CC  = gcc
IDIR = ../../include
LDIR = ../../lib/

all: $(OBJ) 
	clear
	ar -rc libmy.a $(OBJ)
	ranlib libmy.a
	mv libmy.a $(LDIR)

clean: 
	-rm -f $(wildcard *.o)
fclean: clean
	rm -f $(LDIR)libmy.a

re: fclean all



