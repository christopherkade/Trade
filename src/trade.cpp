//
// trade.cpp for trade in /home/kade_c/trade_test/src
// 
// Made by Christopher Kade
// Login   <kade_c@epitech.net>
// 
// Started on  Sun May  8 15:08:48 2016 Christopher Kade
// Last update Wed Sep 14 13:57:19 2016 Christopher Kade
//

#include <string.h>
#include <fstream>
#include <iostream>
#include "trade.hpp"
#include "general.hpp"

Trade::Trade()
{
  this->numOfStocks_ = 0;
  this->daysInTrading_ = 0;
  this->lastStock_ = 0;
  this->lastEMA_ = 0;
}

Trade::~Trade() {}

Trade::Action	Trade::scanTrend()
{
  if (this->daysInTrading_ == this->days_)
    return SELL_EVERYTHING;
  if (this->stockPrices_.size() >= 26)
    {
      float macd = MACD(12, 26);

      this->MACD_.push_back(MACD(12, 26));
      if (this->stockPrices_.size() > 35)
	{
	  float signal = EMA(9, this->MACD_);

	  if (macd <= signal)
	    return BUY;
	  else if (macd >= signal)
	    return SELL;
	  else
	    return WAIT;
	}
      return WAIT;
    }
  return WAIT;
}

void	Trade::action(std::ofstream &file)
{
  switch (scanTrend())
    {
    case BUY: actionBuy(manageMoney(), file);
      break;
    case SELL: actionSell(this->numOfStocks_, file);
      break;
    case WAIT: actionWait(file);
      break;
    case SELL_EVERYTHING: actionSellEverything(file);
      break;
    }
}

void	Trade::start(std::ofstream &file)
{
  std::string input;
  int	i = 1;

  std::cin >> input;
  this->capital_ = stringToFloat(input);
  file << "Capital: " << this->capital_ << std::endl;
  std::cin >> input;
  file << "Total number of days: " << input << std::endl << std::endl;;
  this->days_ = stringToInt(input);
  file << "Stock prices:" << std::endl;
  while (std::cin >> input)
    {
      if (input == "--end--" || input == "--END--")
      	break;
      file << i++ << " - " << input << std::endl;
      this->stockPrices_.push_back(stringToInt(input));
      this->daysInTrading_++;
      this->currentStock_ = stringToInt(input);
      this->action(file);
      this->lastStock_ = this->currentStock_;
    }
}
