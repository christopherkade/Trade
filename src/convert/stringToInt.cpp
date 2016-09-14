//
// stringToInt.cpp for stringToInt in /home/kade_c/trade_test/src/convert
// 
// Made by Christopher Kade
// Login   <kade_c@epitech.net>
// 
// Started on  Sun May  8 15:20:50 2016 Christopher Kade
// Last update Sun May  8 15:20:58 2016 Christopher Kade
//

#include "general.hpp"

int		stringToInt(std::string myStream)
{
  int value;

  std::istringstream buffer(myStream);
  buffer >> value;
  return (value);
}
