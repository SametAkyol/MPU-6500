# MPU-6500
> replace the "PROTOCOL" macro in the MPU6500.h file with the communication protocol you are using (I2C or SPI), 
> and modify the constructor method accordingly, you can follow the steps below. 
> Please note that the example provided assumes you are using I2C, but you can replace it with SPI if that's the protocol you're using.

Open the MPU6500.h file in your preferred text editor.

Locate the line containing the "PROTOCOL" macro, and replace it with the appropriate communication protocol.

if you are using I2C, replace the line with:
> #define PROTOCOL I2C

If you are using SPI, replace it with:
> #define PROTOCOL SPI



Modify the constructor method according to the selected communication protocol. 

>(SPI_HandleTypeDef *hspi, GPIO_TypeDef *GPIOX, uint16_t CsPin);

hspi---> SPIHandleTypedef.
GPIOX---> GPIO peripheral of Chip Select pin .
CsPin ---> GPIO pin of Chip Select pin.



>(I2C_HandleTypeDef* _hi2c,uint8_t _devAddr);

_hi2c = I2C handle.
_devAddr =I2C device address.
