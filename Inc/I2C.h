/*
 * I2C.h
 *
 *  Created on: 11 May 2023
 *      Author: Samet
 */

#ifndef INC_I2C_H_
#define INC_I2C_H_
#include "stdint.h"
#include "main.h"
class I2C {
public:

private:

protected:
	HAL_StatusTypeDef writeReg8(uint8_t regAddr, uint8_t val);
	HAL_StatusTypeDef writeRegMulti(uint8_t regAddr, uint8_t *val,
			uint32_t len);
	HAL_StatusTypeDef readReg8(uint8_t regAddr, uint8_t *buffer);
	HAL_StatusTypeDef readReg16(uint8_t regAddr, uint8_t *buffer);
	HAL_StatusTypeDef readRegMulti(uint8_t regAddr, uint8_t *buffer,
			uint32_t len);
	I2C_HandleTypeDef *hi2c;
	uint8_t devAddr;

};

#endif /* INC_I2C_H_ */
