IDIR = include
CC = gcc
CFLAGS = -I$(IDIR)
SDIR = src
ODIR = obj
EXDIR = examples

_DEPS = easysocket.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = easysocket.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/%.o: $(EXDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $<

easysocket: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)

examples: $(OBJ)
	gcc $(OBJ) -o $@ $^

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
