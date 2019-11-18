.SUFFIXES: .cpp .o

CXX = g++
TARGET = test
OBJECTS = human.o student.o smart_obj.o shared_ref.o weak_pointer.o test.o

%.o: %.cpp
	$(CXX) -c $^

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) -o $@ $^

clean:
	rm -rf $(TARGET) $(OBJECTS)
