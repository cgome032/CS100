#---------------------------------
# Variables, Directories, Commands
#---------------------------------
CC = g++
CC_FLAGS = -Wall -Werror -ansi -pedantic
FILEXEC = rshell
DIRCMD = mkdir -p
OUTDIR = bin
EXEC = $(OUTDIR)/$(FILEXEC)
SOURCDIR = src
SOURCES = $(wildcard $(SOURCDIR)/*.cpp) 
_OBJECTS = $(SOURCES:.cpp=.o)
OBJECTS = $(patsubst $(SOURCDIR)/%.o,$(OUTDIR)/%.o,$(_OBJECTS))

#---------------------------------
# TARGET: DEPENDENCIES
# 	ACTIONS
#---------------------------------
$(EXEC): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXEC) 

$(OUTDIR)/%.o: $(SOURCDIR)/%.cpp
	$(CC) -c $(CC_FLAGS) $< -o $@

all: $(OBJECTS)

$(OBJECTS): | $(OUTDIR)

$(OUTDIR):
	$(DIRCMD) $(OUTDIR) 
#---------------------------------
# CLEAN 
#---------------------------------
clean:
	rm -f $(EXEC) $(OBJECTS)
