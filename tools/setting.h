#include <stdio.h>
#include <stdlib.h>
#include <xbee.h>

//For xbee_setup
const char *mode = "xbeeZB";
char *device = "/dev/ttyAMA0";
int baudrate = 9600;
int LogLevel =  0; //0:disable Log, 100:enable Log
int Brocast = 1; 	//0:For Brocast or a Coordinator, 1:Send to cooedinator or a endpoint
int get_address = 3; //A flag for check if all part of address are get. 3 send first address 2 send second address 0 success
char* Local_Address = "";

/* queue for sending data */
struct pkt { 
	char *type;                 //"Data" or "AT"
	char *address;   			//Brocast:000000000000FFFF;Coordinator:0000000000000000
	char *content;              // "Data":Data;"AT":Command for dest device (the address you assigned) e.g for AT: NICoordinator
    struct pkt *next; 
}; 

typedef struct pkt pPkt; 

pPkt *front, *rear;

/* Connector for setup xbee connection */
xbee_err xbee_connector(struct xbee **xbee,	struct xbee_con **con, char *conMode);

/* Create Packet Queue Header */
void init_Queue();

/* Add new Packet to the end of Queue */ 
void addpkt(char *raw_addr, char *type,char *content);

/* Delete the end of Queue */ 
void delq();

/* Fill the address from raw(char) to addr(Hex) */
void Fill_Address(char *raw,unsigned char addr[8]);

/* Copy raw(char) to dest(char) for addpkt */
void AddressCopy(char *raw,char *dest,int size);

void CallBack_for_Data(struct xbee *xbee, struct xbee_con *con, struct xbee_pkt **pkt, void **data);

void CallBack_for_get_address(struct xbee *xbee, struct xbee_con *con, struct xbee_pkt **pkt, void **data);
