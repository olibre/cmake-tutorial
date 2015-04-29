#ifndef PARSER_H
#define PARSER_H
#include <fstream>
using namespace std;

class Header;
class OrderAck;
class OrderFill;
class OrderEntry;

class Parser {
public:
    static inline void readHeader(Header& h, fstream& fin);
    static inline void readOrderEntry(uint16_t len, fstream& fin, OrderEntry& o);
    static inline void readOrderAck(uint16_t len, fstream& fin, OrderAck& o);
    static inline void readOrderFill(uint16_t len, fstream& fin, OrderFill& o);
private:
    static uint16_t readUInt16(char* buf);
    static uint16_t readUInt8(char* buf);
    static uint64_t readUInt64(char* buf);
    static uint32_t readUInt32(char* buf);
};

#endif
