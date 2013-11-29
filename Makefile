CC=g++
CFLAGS=-c -Wall -std=c++11
LDFLAGS=
SOURCES=./Timer/main.cpp ./Timer/timer.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=TimerEx

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
