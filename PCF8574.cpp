/*
 * PCF8574.cpp
 *
 *  Created on: Oct 2, 2023
 *  Author: Djoum
 */

#include "PCF8574.hpp"

using embric::PCF8574;

PCF8574::PCF8574(I2C_HandleTypeDef& hi2c, uint8_t address)
: mHi2c(hi2c)
, mSlaveAddress(address)
{

}

/**
 * @brief 	Get the port data
 *
 * @details	The master needs to write 1 to the register to set the port
 * 			as input mode if the device is not in the default power-on
 * 			condition. The master reads the register to check the input
 * 			status.
 *
 * @returns	true if the port is HIGH otherwise false
 */
bool PCF8574::Get(EPorts port)
{
	//TODO implement it later!
	return true;
}

uint8_t PCF8574::GetAll()
{
	uint8_t data = 0;
	HAL_I2C_Master_Receive(&mHi2c, mSlaveAddress, &data, 1, 100);
	return data;
}

/**
 * @brief 	Set the port data
 *
 * @details	The master write 0/1 to the register.
 *
 * @returns	true if the port is HIGH otherwise false
 */
void PCF8574::Set(EPorts port, bool value)
{
	//TODO implement it later!
	//1. Get the current data
	uint8_t currentData = GetAll();

	//2. match the structure
	uint8_t bitPos = static_cast<uint8_t>(port);
	uint8_t mask = (1 << bitPos);
	if ( value )
	{
		currentData |= mask;
	}
	else
	{
		currentData &= ~mask;
	}
	Set(currentData);
}

void PCF8574::Set(uint8_t portData)
{
	HAL_I2C_Master_Transmit(&mHi2c, mSlaveAddress, &portData, 1, 100);
}

void PCF8574::Set(uint8_t * data, uint8_t nb)
{
   if ((data != nullptr) && (nb > 0))
   {
      HAL_I2C_Master_Transmit(&mHi2c, mSlaveAddress, data, nb, 100);
   }
}

