default: win32

task1: task1.c serial_port_lib_win32.c
	gcc task1.c serial_port_lib_win32.c -o task1.exe -std=c18 -Wall

win32: serial_port_demo.c serial_port_lib_win32.c
	gcc serial_port_demo.c serial_port_lib_win32.c -o demo.exe -std=c18 -Wall
	
ubuntu: serial_port_demo.c serial_port_lib_linux.c
	gcc serial_port_demo.c serial_port_lib_linux.c -o demo -std=c18 -Wall

raspberrypi: serial_port_demo.c serial_port_lib_rpi.c
	gcc serial_port_demo.c serial_port_lib_rpi.c -o demo -std=c18 -Wall -l wiringPi -D RASPBERRY_PI
	
clean: 
	rm -f demo.exe
	rm -f demo
