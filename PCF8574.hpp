/*
 * PCF8574.hpp
 *
 *  Created on: Oct 2, 2023
 *  Author: Djoum
 *
 *  Just for fun
 */

#pragma once

#include "stm32f1xx_hal.h"

namespace embric
{
class PCF8574
{
public:
   enum class Register
   {
      NONE    = 0
   };

	union Ports
	{
		struct port
		{
			uint8_t p0 : 1;
			uint8_t p1 : 1;
			uint8_t p2 : 1;
			uint8_t p3 : 1;
			uint8_t p4 : 1;
			uint8_t p5 : 1;
			uint8_t p6 : 1;
			uint8_t p7 : 1;
		};
		uint8_t data;
	};

	enum class EPorts : uint8_t
	{
		P0 = 0,
		P1,
		P2,
		P3,
		P4,
		P5,
		P6,
		P7,
	};

	PCF8574(I2C_HandleTypeDef& hi2c, uint8_t address);

	~PCF8574() = default;

	bool Get(EPorts port);
	uint8_t GetAll();
	void Set(EPorts port, bool value);
	void Set(uint8_t portData);
	void Set(uint8_t * data, uint8_t nb);

private:
	I2C_HandleTypeDef& mHi2c; /// Pointer to the handler of the I2C hardware
	uint8_t mSlaveAddress;
};

} /* namespace embric */
