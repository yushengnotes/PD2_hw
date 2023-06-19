# Variables
CC = g++
CFLAGS = -Wall -std=c++11  # add -std=c++11 if you're using C++11 or later
exe = hw7
obj = main.o parseCorpus.o parseQuery.o stringToNum.o calculateIDF.o findKeyWord.o findTop3IDFword.o searchOccurNum.o processIDF.o sortSumIDF.o MurmurHash3.o

all: $(exe)

$(exe): $(obj)
	$(CC) $(CFLAGS) -o $(exe) $(obj)
	rm -f $(obj)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

.PHONY: clean
clean:
	rm -f $(obj) $(exe)
