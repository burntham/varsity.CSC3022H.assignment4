LIBS = -lboost_program_options
CC = g++
ARGS = -o out.txt -i in.txt -c 2 -e
HEADERS = crypt.h CypherPolicies.h CypherTraits.h cyphers.h crypt_trait.h crypt_policy.h
EXEC = a.out

runs: test 
	clear ; ./$(EXEC) $(ARGS)

run:
	clear ; ./$(EXEC) $(ARGS)

runinv:
	clear ; ./$(EXEC)

test: driver.o cmdline_parser.o 
	g++ cmdline_parser.o driver.o $(LIBS) -std=c++11 -o $(EXEC)

driver.o:$(HEADERS) cmdline_parser.o driver.cpp
	g++ driver.cpp -c -std=c++11

cmdline_parser.o: cmdline_parser.h cmdline_parser.cpp
	g++ cmdline_parser.cpp -c 

clean:
	rm -r *.o ; rm -r *.out

