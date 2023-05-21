/*
 * mpu6500.h
 *
 *  Created on: May 4, 2023
 *      Author: Samet
 */

#ifndef INC_MPU6500_H_
#define INC_MPU6500_H_
#include  <stdint.h>
#include "SPI.h"
#include "I2C.h"
#include "MPU6500_Parameters.h"
#include "main.h"

#define PROTOCOL SPI
class MPU_6500: public SPI ,I2C {

public:
	MPU_6500(SPI_HandleTypeDef *hspi, GPIO_TypeDef *GPIOX, uint16_t CsPin);

	MPU_6500(I2C_HandleTypeDef*hi2c,uint8_t _devAddr);

	~MPU_6500();
	void init(MPU_Config &cfg);
	uint8_t readID();
	float ReadTemp();
	void readAccel(int16_t *ax, int16_t *ay, int16_t *az);
	void readGyro(int16_t *gx, int16_t *gy, int16_t *gz);
	void reset();
protected:

private:

};

#endif /* INC_MPU6500_H_ */
