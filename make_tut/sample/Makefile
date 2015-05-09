BLDDIR = build
INCLUDE = src #there are some .h files here
CXX=g++


CXXFLAGS:= -g -I$(INCLUDE)
CXXFLAGS+=$(shell pkg-config --cflags opencv)

LIBS+=$(shell pkg-config --libs opencv)

SRCS:=$(shell echo src/*.cpp)
OBJS:=$(patsubst src/%.cpp, $(BLDDIR)/%.o, $(SRCS))

TARGETS:= main

all: $(patsubst %, $(BLDDIR)/%, $(TARGETS))

$(BLDDIR)/%.o: src/%.cpp
	$(CXX) -o $@ $(CXXFLAGS) -c $<

$(BLDDIR)/%.o: %.cpp
	$(CXX) -o $@ $(CXXFLAGS) -c $<

$(BLDDIR)/main: $(OBJS) $(BLDDIR)/main.o $(BLDDIR)/idcard.o 
	$(CXX)  $(CXXFLAGS) $(LDFLAGS) -o $@ $^ $(LIBS)

clean:
	rm -f ${BLDDIR}/*
	rm -f *.o

temp:
	@echo $(SRCS)
	@echo $(OBJS)

.PHONY: clean all temp
