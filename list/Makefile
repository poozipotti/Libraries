SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Werror --pedantic -I$(IDIR) 
CC  = gcc
IDIR = ../../include
LDIR = ../../lib/

all: $(OBJ)
	ar -rc libmylist.a $(OBJ)
	ranlib libmylist.a
	mv libmylist.a $(LDIR)

clean: 
	-rm -f $(wildcard *.o)
fclean: clean
	rm -f $(LDIR)libmylist.a

re: fclean all

