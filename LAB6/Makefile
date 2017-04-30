 
CC := g++ # This is the main compiler

SRCDIR := src
OBJECTDIR := obj
HEADERDIR := inc
TESTDIR := obj/test
TARGET := lab6
 
SRCEXT := cpp
HEADEREXT := hh
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(OBJECTDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
OBJECTS2 := $(patsubst $(OBJECTDIR)/main.o, , $(OBJECTS) )


CFLAGS := -g  -Wall -pedantic -std=c++11
LIB := -lboost_unit_test_framework 
INC := -I $(HEADERDIR)

_start_: tester
	./tester --log_level=test_suite

$(TARGET): $(OBJECTS) 
	@echo " Linking...";
	@echo " $(CC) $^  $(TARGET) $(LIB)"; $(CC) $^ -o $(TARGET) $(LIB)

$(OBJECTDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(OBJECTDIR)
	@echo " $(CC) $(CFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	@echo " Cleaning..."; 
	@echo " $(RM) -r $(OBJECTDIR) $(TARGET) tester"; $(RM) -r $(OBJECTDIR) $(TARGET) tester

# Tests
tester: $(OBJECTS2)
	$(CC) $(CFLAGS) $(OBJECTS2) test/tester.cpp $(INC) $(LIB) -o tester

.PHONY: clean
