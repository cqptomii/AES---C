CC=gcc
EXT=c
CCFLAGS= -Wall
LDFLAGS=
OBJDIR= obj/
EXEDIR= bin/

AES: $(OBJDIR)main.o $(OBJDIR)Route.o $(OBJDIR)hub.o $(OBJDIR)file.o $(OBJDIR)keySchedule.o $(OBJDIR)mixColumn.o $(OBJDIR)ShiftRows.o $(OBJDIR)Subbyte.o
	$(CC) -o $(EXEDIR)$@ $^
%.o: %.$(EXT)
	$(CC) $(CCFLAGS) -o $(OBJDIR)$@ -c $<

