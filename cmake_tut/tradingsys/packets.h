#ifndef PACKET_H
#define PACKET_H
#include <stdint.h>

class Header{
public:
    char marker[3];
    uint8_t msg_type;
    uint64_t sequence_id;
    uint64_t timestamp;
    uint8_t msg_direction;
    uint16_t msg_len;
};

class OrderEntry{
public:
    uint64_t price;
    uint32_t qty;
    char instrument[11];
    uint8_t side;
    uint64_t client_assigned_id;
    uint8_t time_in_force;
    char trader_tag[4];
    uint8_t firm_id;
    char firm[257];//via
};

class OrderAck{
public:
    uint32_t order_id;
    uint64_t client_id;
    uint8_t order_status;
    uint8_t reject_code;
};

class OrderFill{
public:
    uint32_t order_id;
    uint64_t fill_price;
    uint32_t fill_qty;
    uint8_t no_of_contras;
//reapeating group ignored
};
#endif
