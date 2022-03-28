default: example02

example01: L04_Example_01.c
	gcc L04_Example_01.c -o example01.exe -std=c18 -Wall -pedantic	

example02: L04_Example_02.c
	gcc L04_Example_02.c -o example02.exe -std=c18 -Wall -pedantic	

example02cpp: L04_Example_02.cpp
	g++ L04_Example_02.cpp -o example02cpp.exe -std=c++17 -Wall -pedantic	
	
clean: 
	rm -f example01.exe
	rm -f example02.exe
	rm -f example02cpp.exe
