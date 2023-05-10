# Variables
CC = g++
CFLAGS = -Wall -std=c++11  # add -std=c++11 if you're using C++11 or later
exe = hw5
obj = main.o parseText.o

all: $(exe)

$(exe): $(obj)
	$(CC) $(CFLAGS) -o $(exe) $(obj)
	rm -f $(obj)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

.PHONY: clean
clean:
	rm -f $(obj) $(exe)
