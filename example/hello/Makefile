release:
	g++ -o main main.cpp ../../drlog/drlog.cpp -I../../ -O2 -W -Wall -D DR_NO_DEBUG
	./main
	rm main

debug:
	g++ -o main main.cpp ../../drlog/drlog.cpp -I../../ -g -Og -W -Wall -std=c++11
	./main
	rm main