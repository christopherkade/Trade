//
// stringToFloat.cpp for stringToFloat in /home/kade_c/trade_test/src/convert
// 
// Made by Christopher Kade
// Login   <kade_c@epitech.net>
// 
// Started on  Sun May  8 15:20:37 2016 Christopher Kade
// Last update Sun May  8 15:21:03 2016 Christopher Kade
//

#include "general.hpp"

float		stringToFloat(std::string myStream)
{
  float		 value;

  std::istringstream buffer(myStream);
  buffer >> value;
  return (value);
}
