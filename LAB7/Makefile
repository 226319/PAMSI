 
CC := g++ # This is the main compiler

SRCDIR := src
OBJECTDIR := obj
HEADERDIR := inc
TARGET := lab7

SRCEXT := cpp
HEADEREXT := hh
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(OBJECTDIR)/%,$(SOURCES:.$(SRCEXT)=.o))


# objects for unit_test program
TEST_SRCEXT := cxx
OBJECTS2 := $(patsubst $(OBJECTDIR)/main.o, , $(OBJECTS) )
TEST_SOURCES := $(shell find $(SRCDIR) -type f -name *.$(TEST_SRCEXT))
TEST_OBJECTS := $(patsubst $(SRCDIR)/%,$(OBJECTDIR)/%,$(TEST_SOURCES:.$(TEST_SRCEXT)=.o))

# options
CFLAGS := -Wall -pedantic -std=c++11
LIB := 
LIBT := -L -lboost_unit_test_framework 
INC := -I $(HEADERDIR)


$(TARGET): $(OBJECTS) 
	@echo " Linking...";
	@echo " $(CC) $^  $(TARGET) $(LIB)"; $(CC) $^ -o $(TARGET) $(LIB)

$(OBJECTDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(OBJECTDIR)
	@echo " $(CC) $(CFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

$(OBJECTDIR)/%.o: $(SRCDIR)/%.$(TEST_SRCEXT)
	@echo " $(CC) $(CFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	@echo " Cleaning..."; 
	@echo " $(RM) -r $(OBJECTDIR) $(TARGET) tester"; $(RM) -r $(OBJECTDIR) $(TARGET) tester

# Tests
tester: $(OBJECTS2) $(TEST_OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS2) $(TEST_OBJECTS) test/tester.cpp $(INC) $(LIBT) -o tester
	@./tester --log_level=test_suite

.PHONY: clean
