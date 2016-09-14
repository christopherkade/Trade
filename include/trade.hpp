//
// trade.hpp for trade in /home/kade_c/trade_test/include
// 
// Made by Christopher Kade
// Login   <kade_c@epitech.net>
// 
// Started on  Sun May  8 14:42:43 2016 Christopher Kade
// Last update Thu Jun  2 11:09:54 2016 Christopher Kade
//

#ifndef _TRADE_HPP_
#define _TRADE_HPP_

#include <fstream>
#include <string>
#include <list>
#include <vector>

class	Trade
{
private:
  int			capital_;	// Our capital
  int			days_;		// Total number of days of available stock prices
  int			daysInTrading_;	// Increments as days go by.
  std::vector<int>	stockPrices_;	// Contains stock prices day after day.
  int			currentStock_;	// Current stock we are dealing with.
  int			lastStock_;	// Last stock dealt with
  int			numOfStocks_;	// Amount of stocks we have in our possession
  float			EMA_;		// Exponential Moving Average
  float			lastEMA_;	// Last EMA
  std::vector<int>	MACD_;		// Moving Average Convergence Divergence

public:
  Trade();
  ~Trade();

  enum Action
    {
      BUY,
      SELL,
      WAIT,
      SELL_EVERYTHING
    };

  // Trade Algorithm
  void	start(std::ofstream &);
  float	calcEMA();
  float	MACD(int, int);
  float	EMA(int, std::vector<int>);
  void	action(std::ofstream &);
  Action scanTrend();
  void	saveTrend(std::ofstream &);
  int	manageMoney();

  // Actions
  void	init();
  void	actionWait(std::ofstream &);
  void	actionSell(int, std::ofstream &);
  void	actionBuy(int, std::ofstream &);
  void	actionSellEverything(std::ofstream &);
  void	addStock(int);
  void	removeStock(int);
};

#endif /* !_TRADE_HPP_ */
