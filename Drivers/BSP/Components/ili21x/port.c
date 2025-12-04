#include "port.h"
#include "../../Board/bsp.h"

#define ILITEK_I2C_ADDRESS 	(0x82)

void ilitek_interface_init()
{
	TS_IO_Init();
}

void ilitek_delay(uint32_t msec)
{
	TS_IO_Delay(msec);
}

void ilitek_sleep(uint32_t msec)
{
	TS_IO_Delay(msec);
}

int ilitek_i2c_read(uint8_t * data, int read_len)
{
	if (read_len > 0)
	{
		int8_t status = TS_IO_Receive(ILITEK_I2C_ADDRESS | 0x01, data, read_len);
		if (status != 0) return status;
	}
	return 0;
}

int ilitek_i2c_rw(uint8_t * cmd, int write_len, int delay, uint8_t * data, int read_len)
{
	if (write_len > 0)
	{
		int8_t status = TS_IO_Transmit(ILITEK_I2C_ADDRESS, cmd, write_len);
		if (status != 0) return status;
	}
	if (delay > 0)
	{
		ilitek_delay(delay);
	}
	if (read_len > 0)
	{
		int8_t status = TS_IO_Receive(ILITEK_I2C_ADDRESS | 0x01, data, read_len);
		if (status != 0) return status;
	}
	return 0;
}

void ilitek_gpio_reset_set(uint8_t value)
{
	TS_IO_SetReset(value);
}

uint8_t ilitek_gpio_int_get()
{
	return 0;
}

void ilitek_print ( const char * fmt, ... )
{

}
