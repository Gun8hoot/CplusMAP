CXX = g++
CXXFLAGS = -Wall -o cplusmap

SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = myprogram

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(OBJS) $(TARGET)