BINARIES = trading_sys

TRADING_SYS_SRCS = \
trading_sys.cpp      \
parser.cpp        \

BLDDIR = build

CC = g++
LD = g++
LDFLAGS = -stdlib=libstdc++
CFLAGS =  -stdlib=libstdc++

TRADING_SYS_OBJS := $(patsubst %.cpp, $(BLDDIR)/%.o, $(TRADING_SYS_SRCS))

# "all" (default target) depends on the built binaries
all: $(patsubst %, $(BLDDIR)/%, $(BINARIES))

clean:
	rm -f $(patsubst %, $(BLDDIR)/%, $(BINARIES))
	rm -f $(TRADING_SYS_OBJS)
	rmdir $(BLDDIR) || true

# dependencies, additional to the recipes below
$(BLDDIR)/trading_sys: $(TRADING_SYS_OBJS)

$(BLDDIR)/%:
	$(LD) -o $@ $(LDFLAGS) $^

$(BLDDIR)/%.o: %.cpp
	$(CC) -o $@ $(CFLAGS) -c $<


$(BLDDIR)/trading_sys: $(TRADING_SYS_OBJS)
$(BLDDIR)/trading_sys.o: packets.h
$(BLDDIR)/parser.o: parser.h

.PHONY: all
