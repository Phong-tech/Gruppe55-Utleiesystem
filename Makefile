# Makefile for Gruppe55 Utleiesystem

CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

TARGET = prosjekt

SOURCES = main.cpp Funksjoner.cpp Gjenstand.cpp Tralle.cpp Sykkel.cpp \
          Elsparkesykkel.cpp Kunde.cpp Kunder.cpp Sted.cpp \
          Utleiesteder.cpp LesData3.cpp

OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	g++ -std=c++11 -Wall -Wextra -o $(TARGET) $(OBJECTS)

%.o: %.cpp
	g++ -std=c++11 -Wall -Wextra -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
