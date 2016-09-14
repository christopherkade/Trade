//
// floatToString.cpp for floatToString in /home/kade_c/trade_test/src/convert
// 
// Made by Christopher Kade
// Login   <kade_c@epitech.net>
// 
// Started on  Sun May  8 15:20:27 2016 Christopher Kade
// Last update Sun May  8 15:20:27 2016 Christopher Kade
//

#include "general.hpp"

std::string		floatToString(float val)
{
  std::stringstream convert;

  convert << val;
  return (convert.str());
}
