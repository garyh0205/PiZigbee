#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <xbee.h>

void myCB(struct xbee *xbee, struct xbee_con *con, struct xbee_pkt **pkt, void **data) {
	if ((*pkt)->dataLen == 0) {
		printf("too short...\n");
		return;
	}
	printf("rx: [%s]\n", (*pkt)->data);
}

int main(void) {
	void *d;
	struct xbee *xbee;
	struct xbee_con *con;
	struct xbee_conAddress address;
	unsigned char txRet;
	xbee_err ret;

	if ((ret = xbee_setup(&xbee, "xbeeZB", "/dev/ttyAMA0", 9600)) != XBEE_ENONE) {
		printf("ret: %d (%s)\n", ret, xbee_errorToStr(ret));
		return ret;
	}

	/* this is the 64-bit address of the remote XBee module
	   it should be entered with the MSB first, so the address below is
	   SH = 0x0013A200    SL = 0x40081826 */
	memset(&address, 0, sizeof(address));
	address.addr64_enabled = 1;

	sscanf("000000000000FFFF", "%2x%2x%2x%2x%2x%2x%2x%2x", &address.addr64[0], &address.addr64[1], &address.addr64[2], &address.addr64[3],
                                                               &address.addr64[4], &address.addr64[5], &address.addr64[6], &address.addr64[7]   );
        /*
        address.addr64[0] = 0x00;
        address.addr64[1] = 0x13;
        address.addr64[2] = 0xA2;
        address.addr64[3] = 0x00;
        address.addr64[4] = 0x40;
        address.addr64[5] = 0x89;
        address.addr64[6] = 0x16;
        address.addr64[7] = 0x5F;
        */

	if ((ret = xbee_conNew(xbee, &con, "Remote AT", &address)) != XBEE_ENONE) {
		xbee_log(xbee, -1, "xbee_conNew() returned: %d (%s)", ret, xbee_errorToStr(ret));
		return ret;
	}

	if ((ret = xbee_conCallbackSet(con, myCB, NULL)) != XBEE_ENONE) {
		xbee_log(xbee, -1, "xbee_conCallbackSet() returned: %d", ret);
		return ret;
	}
	
	ret = xbee_conTx(con, &txRet, "NI");
	printf("tx: %d\n", ret);
	if (ret) {
		printf("txRet: %d\n", txRet);
	} else {
		usleep(1000000);
	}
	
	if ((ret = xbee_conEnd(con)) != XBEE_ENONE) {
		xbee_log(xbee, -1, "xbee_conEnd() returned: %d", ret);
		return ret;
	}

	xbee_shutdown(xbee);

	return 0;
}
