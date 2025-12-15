CC = gcc
CFLAGS = -Iinclude -O2 -DBGLVL=2
TARGET = bin\lab3.exe
SRCDIR = src
OBJDIR = build

SRC = list.c sort.c compare.c inout.c generation.c args.c main.c

OBJ = $(SRC:%.c=%.o)
OBJS = $(OBJ:%=$(OBJDIR)/%) 

$(TARGET): $(OBJS)
	$(CC) $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@


 .PHONY: all clean cleanall

 clean:
	del /f $(TARGET)

cleanall:
	del /f $(TARGET)
	del /f $(OBJDIR)\*.o