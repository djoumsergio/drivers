/*
 * LM75A.hpp
 *
 *  Created on: Apr 27, 2023
 *  Author: Djoum
 */

#ifndef LM75A_HPP_
#define LM75A_HPP_

#include "stm32f1xx_hal.h"

namespace embric
{

enum class RegisterMaps
{
   TEMPERATURE    = 0,
   CONFIGURATION  = 1,
   T_HYST         = 2,
   T_OS           = 3,
   PRODUCT_ID     = 4
};

class LM75A
{
public:
   LM75A(I2C_HandleTypeDef * hi2c, uint8_t address);

   float GetTemperature();
   void SetConfiguration(bool shutdown, bool comp_int, bool os_pol, uint8_t faultQueue);
   uint8_t GetConfiguration();

   void SetHystheresis(uint8_t newValue);
   uint8_t GetHystheresis();

   void SetTempOS(uint8_t newValue);
   uint8_t GetTempOS();

   ~LM75A();

private:
   I2C_HandleTypeDef * mHi2c; /// Pointer to the handler of the I2C hardware
   uint8_t mSlaveAddress;

};

} /* namespace embric */

#endif /* LM75A_HPP_ */
