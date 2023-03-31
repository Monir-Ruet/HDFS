BINARY=main
CODEDIRS=. src
INCDIRS=. ./include/ # can be list

CC=g++
OPT=-O0
# DEPFLAGS=-MP -MD
CFLAGS= -Wall -g $(foreach D,$(INCDIRS),-I$(D)) $(OPT) -lrocksdb

CFILES=$(foreach D,$(CODEDIRS),$(wildcard $(D)/*.cpp))
# regular expression replacement
OBJECTS=$(patsubst %.cpp,%.o,$(CFILES))
# DEPFILES=$(patsubst %.cpp,%.d,$(CFILES))

all: $(BINARY)

$(BINARY): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

# only want the .c file dependency here, thus $< instead of $^.
#
%.o:%.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(BINARY) $(OBJECTS)
distribute: clean
	tar zcvf dist.tgz *

diff:
	$(info The status of the repository, and the volume of per-file changes:)
	@git status
	@git diff --stat

# include the dependencies
# -include $(DEPFILES)

# add .PHONY so that the non-targetfile - rules work even if a file with the same name exists.
.PHONY: all clean distribute diff
