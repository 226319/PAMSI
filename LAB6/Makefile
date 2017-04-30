# TODO: Move `libmongoclient.a` to /usr/local/lib so this can work on production servers
#
 
CC := g++ # This is the main compiler
# CC := clang --analyze # and comment out the linker last line for sanity
SRCDIR := src
OBJECTDIR := obj
HEADERDIR := inc
TARGET := lab6
 
SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(OBJECTDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
HEADERS := $(patsubst $(SRCDIR)/%,$(HEADERDIR)/%,$(SOURCES:.$(SRCEXT)=.hh))
CFLAGS := -g  -Wall -pedantic -std=c++11
LIB := -l lboost_unit_test_framework-mt 
INC := -I $(HEADERDIR)

$(TARGET): $(OBJECTS)
	@echo " Linking...";
	@echo " $(CC) $^ -o $(TARGET) $(LIB)"; $(CC) $^ -o $(TARGET) $(LIB)

$(OBJECTDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(OBJECTDIR)
	@echo " $(CC) $(CFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	@echo " Cleaning..."; 
	@echo " $(RM) -r $(OBJECTDIR) $(TARGET)"; $(RM) -r $(OBJECTDIR) $(TARGET)

# Tests
tester:
	$(CC) $(CFLAGS) test/tester.cpp $(INC) $(LIB) -o tester

.PHONY: clean
