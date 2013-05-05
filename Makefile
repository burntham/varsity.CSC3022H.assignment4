run: test
	clear ; ./a.out

test:
	g++ driver.cpp -std=c++11

clean:
	rm -r *.o ; rm -r *.out