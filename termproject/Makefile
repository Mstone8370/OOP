.SUFFIXES = .cpp .o

CXX = g++
CFLAGS = -g
TARGET = test
OBJECTS = main.o getch.o array_2d.o block.o big_block.o cross_block.o fold_block.o tree_block.o

%.o: %.c
	$(CXX) $(CFLAGS) -c $^

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CFLAGS) -o $@ $^

clean:
	rm -rf $(TARGET) $(OBJECTS)
