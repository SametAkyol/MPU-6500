/*
 * MPU6500_Parameters.h
 *
 *  Created on: 11 May 2023
 *      Author: Samet
 */

#ifndef INC_MPU6500_PARAMETERS_H_
#define INC_MPU6500_PARAMETERS_H_

#define CONFIG 0x1A
#define GYRO_CONFIG 0x1B
#define ACCEL_CONFIG 0x1C
#define ACCEL_CONFIG_2 0x1D
#define ACCEL_XOUT_H 0x3B
#define TEMP_OUT_H 0x41
#define GYRO_XOUT_H 0x43
#define PWR_MGMT_1 0x6B
#define PWR_MGMT_2 0x6C
#define SIGNAL_PATH_RESET 0x68
#define WHO_AM_I 0x75

#define GYRO_FS_SEL_POS 3
#define ACCEL_FS_SEL_POS 3
#define ACCEL_FCHOICE_B_POS 3
#define FCHOICE_B_POS 0

typedef enum {
	dps_250 = 0, dps_500, dps_1000, dps_2000,
} GYRO_FS_SEL;

typedef enum {
	_2g = 0, _4g, _8g, _16g,
} ACCEL_FS_SEL;

typedef struct {
	ACCEL_FS_SEL a_cfg;
	GYRO_FS_SEL g_cfg;
} MPU_Config;

#endif /* INC_MPU6500_PARAMETERS_H_ */
