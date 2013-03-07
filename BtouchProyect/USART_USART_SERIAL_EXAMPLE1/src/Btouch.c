#include "Btouch.h" 

void LED_on(void){
	
	send_inst(W_SLAVE_ID,PMW_MODE_DC,PWM_LED_MASK);
}


void GPIO_CS_enable(uint8_t port){

	send_inst(W_SLAVE_ID,COMMAND_REG, SETUP_MODE);
	send_inst(W_SLAVE_ID,CS_ENABLE1, port);
	send_inst(W_SLAVE_ID,COMMAND_REG, SAVE_FLASH);
	send_inst(W_SLAVE_ID,COMMAND_REG, RESET);
}

void GPIO_IO_enable(uint8_t port){

	send_inst(W_SLAVE_ID,COMMAND_REG, SETUP_MODE);
	send_inst(W_SLAVE_ID,GPIO_ENABLE0, port);
	send_inst(W_SLAVE_ID,COMMAND_REG, SAVE_FLASH);
	send_inst(W_SLAVE_ID,COMMAND_REG, RESET);
}

uint8_t scan_port (uint32_t port){

	twi_write_byte(TWI_EXAMPLE, port);
	
	return twi_read_byte(TWI_EXAMPLE);
}

uint8_t ButtonStat (uint8_t device, uint8_t port){
	
	uint8_t butt=0;
	
	butt=butt & (scan_port(GP10));
	butt=butt & (scan_port(GP11)<<1);
	//but=but & (scan_port(BOARD_BASE_TWI_SLAVE,GP00)<<2);
	//but=but & (scan_port(BOARD_BASE_TWI_SLAVE,GP00)<<3);
	
	return butt;
}

void send_inst(uint8_t device, uint8_t reg, uint8_t value){

	uint8_t *p_value=value;
	twi_packet_t data;
uint8_t regaddr[3]={reg};

data.addr[0]=regaddr[0];
data.addr_length=1;
data.buffer=p_value;
data.length=1;
data.chip=device;

twi_master_write(TWI_EXAMPLE, &data);

}

		
void setup_mode_enable (Twi *p_twi){
	
	send_inst(W_SLAVE_ID,COMMAND_REG,SETUP_MODE);
}



void normal_mode_enable (Twi *p_twi){
	
	send_inst(W_SLAVE_ID,COMMAND_REG,NORMAL_MODE);
}
