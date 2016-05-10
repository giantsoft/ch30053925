vpath %.h include
vpath %.c src
vpath %.o obj

units	= common run shell_util test_case profile
objects	= $(addsuffix .o, $(units)) 

robj	= $(addprefix obj/, $(addsuffix .o, common run))
pobj	= $(addprefix obj/, $(addsuffix .o, common test_case profile))

libdirs = obj
incdirs	= include

AFLAGS	= -O3 -pthread
CFLAGS	= $(AFLAGS) $(addprefix -I, $(incdirs))
LFLAGS	= $(AFLAGS) -Lobj

all: $(info Making all)
all: run profile

profile.o: test_case.h shell_util.h

run: common.o run.o
	gcc $(LFLAGS) -o run $(robj)

profile: common.o profile.o test_case.o shell_util.o
	gcc $(LFLAGS) -o profile $(pobj) 

%.o: %.c objdir
	gcc $(CFLAGS) -c $< -o obj/$@

objdir:
	mkdir -p obj
dev:
	@chmod +x dev
	$(info dev is ready for execution: use ./dev to start watching for changes)

dev-profile: all
	./profile $1

docs: run profile
	@doxygen doxygen.conf

.PHONY: docs dev clean clean-docs

clean-docs:
	rm -rf docs

clean:
	rm -rf obj run profile