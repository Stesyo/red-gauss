TARGET = gauss
CC = clang
FLAGS = -Wall --pedantic

SRCDIR = src
BINDIR = bin

SOURCES  := $(wildcard $(SRCDIR)/*.c)
INCLUDES := $(wildcard $(SRCDIR)/*.h)
OBJECTS  := $(SOURCES:$(SRCDIR)/%.c=$(BINDIR)/%.o)


$(BINDIR)/$(TARGET): $(OBJECTS)
	@$(CC) $(OBJECTS) $(FLAGS) -o $@

$(BINDIR)/%.o : $(SRCDIR)/%.c
	@$(CC) $(FLAGS) -c $< -o $@

test: $(BINDIR)/$(TARGET)
	$(BINDIR)/$(TARGET) dane/A dane/b

.PHONY: clean
clean:
	@rm -f $(BINDIR)/*
