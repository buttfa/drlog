release:
	g++ -o main main.cpp ../../drlog/drlog.cpp -I../../drlog -O2 -W -Wall -std=c++11 -D DR_NO_DEBUG
	./main
	rm main

debug:
	g++ -o main main.cpp ../../drlog/drlog.cpp -I../../drlog -g -Og -W -Wall -std=c++11
	./main
	rm main