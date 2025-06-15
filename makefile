CXX = g++
CXXFLAGS = -Wall -Werror -Wextra -O1 $(SRCS) -o 

SRCS = main.cpp ./lib/arguments.cpp ./lib/scan.cpp ./lib/banner.cpp
OBJS = $(SRCS:.cpp=.o)
PROJ = cplusmap.bin

all: $(PROJ)

$(PROJ): 
	$(CXX) $(CXXFLAGS) $(PROJ)

clean:
	rm -f $(OBJS) $(TARGET)