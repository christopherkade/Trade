//
// actions.cpp for actions in /home/kade_c/Trade/trade/Chris/src
// 
// Made by Christopher Kade
// Login   <kade_c@epitech.net>
// 
// Started on  Wed May 18 14:43:30 2016 Christopher Kade
// Last update Mon May 30 10:30:57 2016 Christopher Kade
//

#include <string.h>
#include <fstream>
#include <iostream>
#include "trade.hpp"
#include "general.hpp"

void	Trade::addStock(int num)
{
  this->numOfStocks_ = this->numOfStocks_ + num;
}

void	Trade::removeStock(int num)
{
  this->numOfStocks_ = this->numOfStocks_ - num;
}

void	Trade::actionSell(int num, std::ofstream &file)
{
  if (numOfStocks_ >= num && num > 0)
    {
      file << "Selling " << num << " stock options..." << std::endl;
      std::cout << "sell " << num << std::endl;
      this->removeStock(num);
      capital_ += num * currentStock_;
      capital_ = capital_ - (0.15 / 100 * (num * currentStock_));
    }
  else
    actionWait(file);
}

void	Trade::actionBuy(int num, std::ofstream &file)
{
  if ((capital_ - (0.15 / 100 * capital_)) >= num * currentStock_ && num > 0)
    {
      file << "Buying " << num << " stock options..." << std::endl;
      std::cout << "buy " << num << std::endl;
      this->addStock(num);
      capital_ -= num * currentStock_;
      capital_ = capital_ - (0.15 / 100 * (num * currentStock_));
    }
  else
    actionWait(file);
}

void	Trade::actionWait(std::ofstream &file)
{
  file << "Waiting..." << std::endl;
  std::cout << "wait" << std::endl;
}

void	Trade::actionSellEverything(std::ofstream &file)
{
  int	gains;

  std::cout << "sell " << this->numOfStocks_ << std::endl;
  this->removeStock(this->numOfStocks_);
  file << "Selling Everything..." << std::endl;
  gains = this->currentStock_ * this->numOfStocks_;
  gains = gains + (gains * 0.15);
  this->capital_ = this->capital_ + gains;
}
