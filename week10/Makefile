.SUFFIXES: .cpp .o

TARGET = test
OBJECTS = vehicle.o car.o bike.o main.o
CXX = g++

%.o: %.cpp
	$(CXX) -c $^

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) -o $@ $^

clean:
	rm -rf $(TARGET) $(OBJECTS)
