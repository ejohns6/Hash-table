CXX = g++
CXXFLAGS = -ansi -Wall -g
TARGET = Project5.o mainHashTable.o secondaryHashTable.o

all: $(TARGET)
	$(CXX) $(CXXFLAGS) $(TARGET) -o Project5.out

mainHashTable.o: mainHashTable.cpp
	$(CXX) $(CXXFLAGS) -c mainHashTable.cpp

secondaryHashTable.o: secondaryHashTable.cpp
	$(CXX) $(CXXFLAGS) -c secondaryHashTable.cpp


Project5.o: Project5.cpp
	$(CXX) $(CXXFLAGS) -c Project5.cpp

run:
	./Project5.out $(FILE)
val:
	valgrind ./Project5.out $(FILE)
clean:
	rm -f *.o
	rm -f *.out
	rm -f *~ *.h.gch *#