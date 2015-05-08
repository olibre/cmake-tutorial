BINARIES = test

LINKEDLIST_SRCS = \
LinearNode.cpp     \
LinkedList.cpp     \
test.cpp

BLDDIR = build

CC = g++
LD = g++
LDFLAGS = #-stdlib=libstdc++
CFLAGS =  #-stdlib=libstdc++

LINKEDLIST_OBJS := $(patsubst %.cpp, $(BLDDIR)/%.o, $(LINKEDLIST_SRCS))

all: $(patsubst %, $(BLDDIR)/%, $(BINARIES))

clean:
	rm -f $(patsubst %, $(BLDDIR)/%, $(BINARIES))
	rm -f $(LINKEDLIST_OBJS)
	rmdir $(BLDDIR) || true

$(BLDDIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CC) -o $@ $(CFLAGS) -c $<

$(BLDDIR)/test: $(LINKEDLIST_OBJS)
	$(LD) $(LDFLAGS) $^ -o $@

.PHONY: all clean

temp:
	@echo $(LINKEDLIST_SRCS)  $(LINKEDLIST_OBJS)
