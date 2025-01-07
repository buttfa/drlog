all:
	make tutorial_1
	make tutorial_2
	make tutorial_3
	make tutorial_4
	make tutorial_5

tutorial_1:
	g++ -o tutorial_1 tutorial_1.cpp ../drlog/drlog.cpp -I ../drlog/ -std=c++11
	./tutorial_1
	rm tutorial_1

tutorial_2:
	g++ -o tutorial_2 tutorial_2.cpp ../drlog/drlog.cpp -I ../drlog/ -std=c++11
	./tutorial_2
	rm tutorial_2

tutorial_3:
	g++ -o tutorial_3 tutorial_3.cpp ../drlog/drlog.cpp -I ../drlog/ -std=c++11
	./tutorial_3
	rm tutorial_3

tutorial_4:
	@echo "Release"
	g++ -o tutorial_4 tutorial_4.cpp ../drlog/drlog.cpp -I ../drlog/ -O2 -W -Wall -std=c++11 -D DR_NO_DEBUG
	./tutorial_4
	rm tutorial_4
	@echo "Debug"
	g++ -o tutorial_4 tutorial_4.cpp ../drlog/drlog.cpp -I ../drlog/ -g -Og -W -Wall -std=c++11
	./tutorial_4
	rm tutorial_4

tutorial_5:
	g++ -o tutorial_5 tutorial_5.cpp ../drlog/drlog.cpp -I ../drlog/ -std=c++11
	./tutorial_5
	rm tutorial_5