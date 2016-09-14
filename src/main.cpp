//
// main.cpp for main in /home/kade_c/trade_test/src
// 
// Made by Christopher Kade
// Login   <kade_c@epitech.net>
// 
// Started on  Sun May  8 15:05:46 2016 Christopher Kade
// Last update Wed May 25 11:10:29 2016 Christopher Kade
//


#include <iostream>
#include <fstream>
#include "trade.hpp"

int	main()
{
  Trade	*trader = new Trade();
  std::ofstream	myFile;

  myFile.open("logs.txt");
  myFile << "[LOGS STARTING]\nStarting our trading routine...\n";
  trader->start(myFile);
  myFile.close();
  return (0);
}
