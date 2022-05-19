default: win32

win32: serial_port_demo.c serial_port_lib_win32.c
	gcc serial_port_demo.c serial_port_lib_win32.c -o demo.exe -std=c18 -Wall
	
ubuntu: serial_port_demo.c serial_port_lib_linux.c
	gcc serial_port_demo.c serial_port_lib_linux.c -o demo.exe -std=c18 -Wall

raspberrypi: serial_port_demo.c serial_port_lib_rpi.c
	gcc serial_port_demo.c serial_port_lib_rpi.c -o demo -std=c18 -Wall -l wiringPi -D RASPBERRY_PI
	
clean: 
	rm -f demo.exe
