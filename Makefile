all:
	g++ -c main.cpp
	g++ -c command.cpp
	g++ -c menu.cpp
	g++ -o nmapeasy main.o command.o menu.o
	rm main.o
	rm command.o
	rm menu.o
	./nmapeasy