run: test
	clear ; ./a.out

test:
	clang++ driver.cpp -std=c++11

clean:
	rm -r *.o ; rm -r *.out