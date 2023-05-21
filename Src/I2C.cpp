/*
 * I2C.cpp
 *
 *  Created on: 11 May 2023
 *      Author: Samet
 */
#include "I2C.h"

HAL_StatusTypeDef I2C::writeReg8(uint8_t regAddr, uint8_t val) {
	return (HAL_I2C_Mem_Write(hi2c,devAddr , regAddr, 1, &val, 1, 10));
}

HAL_StatusTypeDef I2C::writeRegMulti(uint8_t regAddr, uint8_t *val, uint32_t len) {
	return (HAL_I2C_Mem_Write(hi2c,devAddr , regAddr, 1, val, len, 10));
}

HAL_StatusTypeDef  I2C::readReg8(uint8_t regAddr, uint8_t *buffer) {
 return(HAL_I2C_Mem_Read(hi2c, devAddr, regAddr, 1, buffer, 1, 10));
}

HAL_StatusTypeDef  I2C::readReg16(uint8_t regAddr, uint8_t *buffer) {
	return(HAL_I2C_Mem_Read(hi2c, devAddr, regAddr, 1, buffer, 2, 10));
}

HAL_StatusTypeDef  I2C::readRegMulti(uint8_t regAddr, uint8_t *buffer, uint32_t len) {
	return(HAL_I2C_Mem_Read(hi2c, devAddr, regAddr, 1, buffer, len, 10));
}

