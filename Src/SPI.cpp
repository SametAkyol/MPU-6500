/*
 * SPI.cpp
 *
 *  Created on: May 4, 2023
 *      Author: Samet
 */
#include <SPI.h>

void SPI::csHigh() {

	HAL_GPIO_WritePin(spix.gpiox, spix.pin, GPIO_PIN_SET);
}

void SPI::csLow() {
	HAL_GPIO_WritePin(spix.gpiox, spix.pin, GPIO_PIN_RESET);
}

void SPI::writeRegMulti(uint8_t regAddr, uint8_t *val, int len) {
	csLow();
	HAL_SPI_Transmit(hspix, &regAddr, 1, 1);
	HAL_SPI_Transmit(hspix, val, len, 10);
	csHigh();
}

void SPI::readReg8(uint8_t regAddr, uint8_t *buffer) {
	regAddr |= SPI_READ_CMD;
	csLow();

	HAL_SPI_Transmit(hspix, &regAddr, 1, 1);
	HAL_SPI_Receive(hspix, buffer, 1, 1);
	csHigh();

}

void SPI::readReg16(uint8_t regAddr, uint8_t *buffer) {
	regAddr |= SPI_READ_CMD;
	csLow();
	HAL_SPI_Transmit(hspix, &regAddr, 1, 1);
	HAL_SPI_Receive(hspix, buffer, 2, 1);
	csHigh();
}

void SPI::readRegMulti(uint8_t regAddr, uint8_t *buffer, int len) {
	regAddr |= SPI_READ_CMD;
	csLow();
	HAL_SPI_Transmit(hspix, &regAddr, 1, 1);
	HAL_SPI_Receive(hspix, buffer, len, 1);
	csHigh();
}

