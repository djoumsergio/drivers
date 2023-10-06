/*
 * LM75A.cpp
 *
 *  Created on: Apr 27, 2023
 *      Author: Djoum
 */

#include "LM75A.hpp"

using namespace embric;

LM75A::LM75A(I2C_HandleTypeDef * hi2c, uint8_t address):
      mHi2c(hi2c),
      mSlaveAddress(address)
{

}

LM75A::~LM75A()
{
   // TODO Auto-generated destructor stub
}

float LM75A::GetTemperature()
{
   if(mHi2c != NULL)
   {
      uint8_t data[2] = {0, 0};
      uint16_t temp = 0;
      bool negative = false;
      HAL_StatusTypeDef hal_status = HAL_ERROR;
      data[0] = static_cast<uint8_t>(RegisterMaps::TEMPERATURE);

      hal_status = HAL_I2C_Master_Transmit(mHi2c, mSlaveAddress, data, 1, 100);

      if (hal_status != HAL_OK)
      {
         return 0.0;
      }
      else
      {
         hal_status = HAL_I2C_Master_Receive(mHi2c, mSlaveAddress, data, 2, 100);
         negative = (data[0] & 0x80) >> 7;
         temp = ((data[0] & 0x7F) << 1) | ((data[1] & 0x80) >> 7);
         return temp/2;
      }
   }
   else
   {
      //Find a way to notify errors
      return 0.0;
   }
}


void LM75A::SetConfiguration(bool shutdown, bool comp_int, bool os_pol, uint8_t faultQueue)
{

}

uint8_t LM75A::GetConfiguration()
{

}


void LM75A::SetHystheresis(uint8_t newValue)
{

}


uint8_t LM75A::GetHystheresis()
{

}


void LM75A::SetTempOS(uint8_t newValue)
{

}


uint8_t LM75A::GetTempOS()
{

}

