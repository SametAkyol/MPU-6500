/*
 * SpiCom.h
 *
 *  Created on: May 4, 2023
 *      Author: Samet
 */

#ifndef INC_SPI_H_
#define INC_SPI_H_
#include "main.h"


#define SPI_READ_CMD 0x80


typedef struct GPIO{
	GPIO_TypeDef * gpiox;
	uint16_t pin;
}SPI_PinBank;


class SPI {
public:
private:
protected:
	void csHigh();
	void csLow();
	void writeRegMulti(uint8_t regAddr, uint8_t *val, int len);
	void readRegMulti(uint8_t regAddr, uint8_t *buffer, int len);
	void readReg8(uint8_t regAddr, uint8_t *buffer);
	void readReg16(uint8_t regAddr, uint8_t *buffer);
	SPI_HandleTypeDef *hspix;
	SPI_PinBank spix;
};

#endif /* INC_SPI_H_ */
