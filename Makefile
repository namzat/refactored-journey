CC=gcc
CFLAGS=-Wall -std=gnu99
LDLIBS=-pthread -lcheck_pic -lrt -lm -lbsd
SRCDIR=src
TESTDIR=tests
BINDIR=bin

source=$(addprefix $(SRCDIR)/, calculator.c roman_numeral.c)
tests=$(addprefix $(TESTDIR)/, roman_numeral_should.c calculator_should.c check_runner.c)

all: clean $(BINDIR)
	$(CC) $(CFLAGS) $(source) $(tests) -o $(BINDIR)/check_runner $(LDLIBS)

clean:
	if [ -d "./bin" ]; then rm -rf ./bin; fi

check: all
	./bin/check_runner

$(BINDIR):
	if [ ! -d "./bin" ]; then mkdir $(BINDIR); fi
