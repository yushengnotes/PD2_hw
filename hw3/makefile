# Variable
CC = g++
CFLAGS = -Wall
exe = hw3
obj = main.o Employee.o insertSort.o parseCSV.o tmFormat.o 

all: main

main: $(obj)
	$(CC) $(CFLAGS) -o $(exe) $(obj)
	rm -f $(obj)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

.PHONY: claen
clean:
	rm -f $(obj)
