CXX = g++
CXXFLAGS = -Wall -Werror -Wextra -O1 $(SRCS) -o 

SRCS = main.cpp ./lib/ft_arguments.cpp ./lib/ft_scan.cpp ./lib/ft_banner.cpp ./lib/ft_check_ipv4.cpp
OBJS = $(SRCS:.cpp=.o)
PROJ = cplusmap.bin

all: $(PROJ)

$(PROJ): 
	$(CXX) $(CXXFLAGS) $(PROJ)

clean:
	rm -f $(OBJS) $(TARGET)

fclean: clean
	rm -f $(PROJ)

re: fclean

.PHONY: all clean fclean re