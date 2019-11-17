.SUFFIXES: .cpp .o

CXX = g++
TARGET = test
OBJECTS = Integer.o Float.o Complex.o test.o

%.o: %.c
	$(CXX) -c $^ Number.h

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) -o $@ $^

clean:
	rm -rf $(TARGET) $(OBJECTS)
