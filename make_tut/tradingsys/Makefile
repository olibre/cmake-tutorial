BINARIES = trading_sys

TRADING_SYS_SRCS = \
trading_sys.cpp    \
parser.cpp         \

BLDDIR = build

CC = g++
LD = g++
LDFLAGS = #-stdlib=libstdc++
CFLAGS =  #-stdlib=libstdc++

TRADING_SYS_OBJS := $(patsubst %.cpp, $(BLDDIR)/%.o, $(TRADING_SYS_SRCS))

# "all" (default target) depends on the built binaries
all: $(patsubst %, $(BLDDIR)/%, $(BINARIES))

clean:
	rm -f $(patsubst %, $(BLDDIR)/%, $(BINARIES))
	rm -f $(TRADING_SYS_OBJS)
	rmdir $(BLDDIR) || true

# dependencies, additional to the recipes below
#$(BLDDIR)/%: $(TRADING_SYS_OBJS)
$(BLDDIR)/trading_sys: $(TRADING_SYS_OBJS)
<<<<<<< HEAD
	$(LD) -o $@ $(LDFLAGS) $^
=======
	$(LD) $(LDFLAGS) $^ -o $@
>>>>>>> 692cea5df32b2490efaff320f418ddb3a52a4723

$(BLDDIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CC) -o $@ $(CFLAGS) -c $<


$(BLDDIR)/trading_sys: $(TRADING_SYS_OBJS)
<<<<<<< HEAD

=======
$(BLDDIR)/trading_sys.o: parser.h packets.h
$(BLDDIR)/parser.o: packets.h
>>>>>>> 692cea5df32b2490efaff320f418ddb3a52a4723

.PHONY: all
