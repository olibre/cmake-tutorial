#include "packets.h"
#include "parser.h"
//#define CHECK_BORDER
void Parser::readHeader(Header& h, fstream& fin){
	char		buf[8];
	fin.read((char*)h.marker, 2);
	h.marker[2]	       = 0;
	fin.read((char*)&h.msg_type, 1);
	fin.read(buf, 8);
	h.sequence_id	       = readUInt64(buf);
	fin.read(buf, 8);
	h.timestamp	       = readUInt64(buf);
	fin.read((char*)&h.msg_direction, 1);
	fin.read(buf, 2);
	h.msg_len	       = readUInt16(buf);
}

inline void Parser::readOrderEntry(uint16_t len, fstream& fin, OrderEntry& o){
	char		buf[256+9];
	char term[9]	       = "DBDBDBDB";
	fin.read(buf, 8);
	o.price		       = readUInt64(buf);
	fin.read(buf, 4);
	o.qty		       = readUInt32(buf);
	fin.read(o.instrument, 10);
	o.instrument[10]       = 0;
	fin.read((char*) &o.side, 1);
	fin.read(buf, 8);
	o.client_assigned_id   = readUInt64(buf);
	fin.read((char*) &o.time_in_force, 1);
	fin.read(o.trader_tag, 3);
	o.trader_tag[3]	       = 0;
	fin.read(buf, 1);
	o.firm_id	       = readUInt8(buf);
	int		nread  = 0;
	char		c;
	while(fin.read((char*)&c, 1)){
	    buf[nread++]       = c;
	    if (nread >= 8) {
		int	cnt    = 2;
		while(cnt<=8){
		    if(buf[nread-cnt]=='D' && buf[nread-cnt+1]=='B')
		    {
			cnt   += 2;
		    } else {
			break;
		    }
		}
		if (cnt>8) {
		    break;
		}
	    }
	}
	int		i      = 0;
	for(; i<nread-8; i++){
	    o.firm[i]	       = buf[i];
	}
	o.firm[i]	       = 0;
    }

inline void Parser::readOrderAck(uint16_t len, fstream& fin, OrderAck& o){
	char		buf[8];
	fin.read(buf, 4);
	o.order_id	       = readUInt32(buf);
	fin.read(buf, 8);
	o.client_id	       = readUInt64(buf);
	fin.read(buf, 1);
	o.order_status	       = readUInt8(buf);
	fin.read(buf, 1);
	o.reject_code	       = readUInt8(buf);
	fin.read(buf, 8);	//skip dbdbdbdb
#ifdef CHECK_BORDER
	for(int i = 0; i<8; i+=2){
	    if(buf[i]!='D'&&buf[i+1]!='B'){
		printf("failed parse order fill\n");
	    }
	}
#endif
    }
    
inline void Parser::readOrderFill(uint16_t len, fstream& fin, OrderFill& o){
	char		buf[512];
	fin.read(buf, 4);
	o.order_id	       = readUInt32(buf);
	fin.read(buf, 8);
	o.fill_price	       = readUInt64(buf);
	fin.read(buf, 4);
	o.fill_qty	       = readUInt32(buf);
	fin.read(buf, 1);
	o.no_of_contras	       = readUInt8(buf);
	int		nread  = 0;
	char		c[9];
	for (int j = 0; j<o.no_of_contras; j++){
	    fin.read((char*)c, 1);
	    fin.read(c, 3);
	    c[3]	       = 0;
	    fin.read(c, 4);
	    uint32_t	qty    = readUInt32(c);
	}
	fin.read(c, 8);		// ignore terminated string
#ifdef CHECK_BORDER
	for(int i = 0; i<8; i+=2){
	    if(c[i]!='D'&&c[i+1]!='B'){
		printf("failed parse order fill\n");
	    }
	}
#endif
    }

uint16_t Parser::readUInt16(char* buf){
	
	uint16_t	b0, b1, res;
	b0		       = buf[0];
	b1		       = buf[1];
	res		       = b0 | b1<<8;
	return res;
    }
    
uint16_t Parser::readUInt8(char* buf){
	
	uint16_t	b0, res;
	b0		       = buf[0];
	res		       = b0;
	return res;
    }
    
uint64_t Parser::readUInt64(char* buf){
	uint64_t	sum    = 0;
	uint64_t	b0     = buf[0],b1 = buf[1], b2 = buf[2], b3 = buf[3] ,b4=buf[4] ,b5=buf[5], b6=buf[6] ,b7=buf[7];
	sum		       = b0 | b1<<8 | b2<<16 | b3<<24 | b4<<32 
	    | b5<<40 | b6<<48 | b7<<56;
	return sum;
	
	
    }
    
uint32_t Parser::readUInt32(char* buf){
	uint64_t	sum    = 0;
	uint64_t	b0     = buf[0],b1 = buf[1], b2 = buf[2], b3 = buf[3];
	sum		       = b0 | b1<<8 | b2<<16 | b3<<24;
	return sum;
}



