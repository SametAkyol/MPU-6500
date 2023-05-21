/*
 * mpu6500.cpp
 *
 *  Created on: May 4, 2023
 *      Author: Samet
 */
#include "mpu6500.h"

MPU_6500::MPU_6500(SPI_HandleTypeDef *hspi, GPIO_TypeDef *GPIOX,
		uint16_t CsPin) {
	this->hi2c=NULL;
	this->spix.gpiox = GPIOX;
	this->spix.pin = CsPin;
	this->hspix = hspi;
}

MPU_6500::MPU_6500(I2C_HandleTypeDef* _hi2c,uint8_t _devAddr){
	this->hspix=NULL;
	this->hi2c= _hi2c;
	this->devAddr=_devAddr;
}

MPU_6500::~MPU_6500() {

}
uint8_t MPU_6500::readID() {
	uint8_t buffer;
	PROTOCOL::readReg8(WHO_AM_I, &buffer);
	return buffer;
}

float MPU_6500::ReadTemp() {
	uint8_t buffer[2];

	PROTOCOL::readReg16(TEMP_OUT_H, buffer);

	uint16_t TEMP_OUT = (buffer[0] << 8) | buffer[1];
	return ((((float) TEMP_OUT - 0) / 321.0f) + 21.0f);

}

void MPU_6500::readAccel(int16_t *ax, int16_t *ay, int16_t *az) {
	uint8_t buffer[6];

	PROTOCOL::readRegMulti(ACCEL_XOUT_H, buffer, sizeof(buffer));

	*ax = (int16_t) (buffer[0] << 8) | buffer[1];
	*ay = (int16_t) (buffer[2] << 8) | buffer[3];
	*az = (int16_t) (buffer[4] << 8) | buffer[5];
}

void MPU_6500::readGyro(int16_t *gx, int16_t *gy, int16_t *gz) {
	uint8_t buffer[6];

	PROTOCOL::readRegMulti(GYRO_XOUT_H, buffer, sizeof(buffer));

	*gx = (int16_t) (buffer[0] << 8) | buffer[1];
	*gy = (int16_t) (buffer[2] << 8) | buffer[3];
	*gz = (int16_t) (buffer[4] << 8) | buffer[5];
}

void MPU_6500::init(MPU_Config &cfg) {
	reset();
	uint8_t buffer[3];
	buffer[0] = (cfg.g_cfg << GYRO_FS_SEL_POS) | 1 << FCHOICE_B_POS;
	buffer[1] = (cfg.a_cfg << ACCEL_FS_SEL_POS);
	buffer[2] = (1 << ACCEL_FCHOICE_B_POS);
	PROTOCOL::writeRegMulti(GYRO_CONFIG, buffer, sizeof(buffer));
}

void MPU_6500::reset() {
	uint8_t val = 0x01;
	PROTOCOL::writeRegMulti(PWR_MGMT_1, &val, 1);
	HAL_Delay(100);
	val = 0x00;
	PROTOCOL::writeRegMulti(SIGNAL_PATH_RESET, &val, 1);
	HAL_Delay(100);

}
