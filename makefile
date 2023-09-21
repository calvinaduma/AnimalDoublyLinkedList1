run: compile
	./P1 animals.txt
compile:
	g++ -g -std=c++11 dll_list.cpp mainDriver.cpp dll_list.h -o P1 -Wall
clean:
	rm P1
