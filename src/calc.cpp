//
// calc.cpp for calc in /home/kade_c/Trade/trade/src
// 
// Made by Christopher Kade
// Login   <kade_c@epitech.net>
// 
// Started on  Sat May 21 17:01:08 2016 Christopher Kade
// Last update Sat Jun  4 16:35:16 2016 Christopher Kade
//

#include <string.h>
#include <fstream>
#include <iostream>
#include "trade.hpp"
#include "general.hpp"

int	Trade::manageMoney()
{
  return ((this->capital_ / this->currentStock_) / 2);
}

// Exponential Moving Average
// Don't confuse with Moving Average, Exp focuses on the latest value.
float Trade::EMA(int days, std::vector<int> stockPrices)
{
  float exponentialMovingAverage = 0;
  int coeff = 0;
  int i = stockPrices.size() - days;

  for (int n = 0; n < days; n++)
    {
      exponentialMovingAverage += stockPrices[i++] * (n + 1);
      coeff += (n + 1);
    }
  exponentialMovingAverage /= coeff;
  return exponentialMovingAverage;
}

// Moving Average Convergence Divergence
float Trade::MACD(int EMAShort, int EMALong)
{
  return EMA(EMAShort, this->stockPrices_) - EMA(EMALong, this->stockPrices_);
}
