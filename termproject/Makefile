.SUFFIXES = .cpp .o

CXX = g++
TARGET = test
OBJECTS = main.o getch.o array_2d.o block.o big_block.o cross_block.o

%.o: %.c
	$(CXX) -c $^

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) -o $@ $^

clean:
	rm -rf $(TARGET) $(OBJECTS)
