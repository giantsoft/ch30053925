vpath %.h include
vpath %.c src
vpath %.o obj

objects = common.o run.o profile.o test_case.o

all: docs $(objects) run profile

$(objects): %.c %.h
	$(cc) $@.c -o lib/$@ $(flags)

%.o: %.c common.h
	$(cc) -c $@.c

run: common.o
	$(cc) run.o 

profile: common.o profile.o

common.h: limits.h  size.h

dev:
	@chmod +x dev
	$(info dev is ready for execution: use ./dev to start watching for changes)
	
docs:
	@doxygen doxygen.conf

.PHONY: docs dev

clean:
	rm -o