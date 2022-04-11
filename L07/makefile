default: example

example: L07_Example.c
	gcc L07_Example.c -o example.exe -std=c18 -Wall -pedantic	
	
mealy: mealy_machine_test.c
	gcc mealy_machine_test.c -o mealy.exe -std=c18 -Wall -pedantic

moore: moore_machine_test.c
	gcc moore_machine_test.c -o moore.exe -std=c18 -Wall -pedantic	
	
clean: 
	rm -f example.exe
	rm -f mealy.exe
	rm -f moore.exe
