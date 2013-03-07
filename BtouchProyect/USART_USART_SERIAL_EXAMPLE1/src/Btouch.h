
#include "asf.h"
#include "twi_master.h"

#define W_SLAVE_ID	42
#define R_SLAVE_ID	43
#define GP10		1
#define GP11		2
#define GP00		1
#define GP01		2
#define PMW_ENABLE0 0x18
#define PMW_MODE_DC 0x1A
#define GPIO_ENABLE0	0x08
#define CS_ENABLE1	0x07
#define COMMAND_REG	0xA0
#define SAVE_FLASH  1
#define RESET		6
#define PWM_LED_MASK 0b11001001

#define CS_READ_STATUS0	0x88
#define CS_READ_STATUS1	0x89
#define SETUP_MODE		8
#define NORMAL_MODE		7
		
void setup_mode_enable (Twi *p_twi);
void normal_mode_enable (Twi *p_twi);

void GPIO_CS_enable(uint8_t port);
void GPIO_IO_enable(uint8_t port);
void LED_on(void);
uint8_t scan_port (uint32_t port);
void send_inst(uint8_t device, uint8_t port, uint8_t value);
uint8_t ButtonStat (uint8_t device, uint8_t port);



/*
typedef struct twi_packet {
	//! TWI address/commands to issue to the other chip (node).
	uint8_t addr[3];
	//! Length of the TWI data address segment (1-3 bytes).
	uint32_t addr_length;
	//! Where to find the data to be transferred.
	void *buffer;
	//! How many bytes do we want to transfer.
	uint32_t length;
	//! TWI chip address to communicate with.
	uint8_t chip;
} twi_packet_t;
*/

