#Makefile for wordcount 
#Julius Inocencio

wordcount: main.o word_counter.o progress_monitor.o
	g++ -o wordcount main.o word_counter.o progress_monitor.o -lpthread -lrt

main.o: main.cpp progress_monitor.h word_counter.h
	g++ -c main.cpp 

word_counter.o: word_counter.cpp word_counter.h progress_status.h
	g++ -c word_counter.cpp

progress_monitor.o: progress_monitor.cpp progress_monitor.h progress_status.h
	g++ -c progress_monitor.cpp

clean: 
	rm *.o 