# Variable
CC = g++
CFLAGS = -Wall
exe = hw3
obj = main.o Employee.o Attendance.o sortEmployees.o sortAttendances.o sortResults.o parseCSV.o timeFormat.o tmFormat.o formatResults.o Record.o createAttend.o createResults.o calConWorkday.o compareDay.o compareYearMonth.o

all: main

main: $(obj)
	$(CC) $(CFLAGS) -o $(exe) $(obj)
	rm -f $(obj)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

.PHONY: claen
clean:
	rm -f $(obj)
