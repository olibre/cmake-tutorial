BINARIES = trading_sys

TRADING_SYS_SRCS = \
trading_sys.cpp    \
parser.cpp         \

BLDDIR = build

CC = g++
LD = g++
LDFLAGS = 
CFLAGS =  

TRADING_SYS_OBJS := $(patsubst %.cpp, $(BLDDIR)/%.o, $(TRADING_SYS_SRCS))

all: $(patsubst %, $(BLDDIR)/%, $(BINARIES))

clean:
	rm -f $(patsubst %, $(BLDDIR)/%, $(BINARIES))
	rm -f $(TRADING_SYS_OBJS)
	rmdir $(BLDDIR) || true

$(BLDDIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CC) -o $@ $(CFLAGS) -c $<

$(BLDDIR)/trading_sys: $(TRADING_SYS_OBJS)
	$(LD) $(LDFLAGS) $^ -o $@

.PHONY: all clean
