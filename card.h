/*
 * card.h
 * COMP11 Sushi Go
 */

#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>

class Card {
public:
  Card();
  Card(std::string, int);
  std::string getSushiType();
  int getMakiCount();

  // overloaded operator ==
  bool operator==(const Card &other) const;

private:
  std::string sushiType;
  int makiCount;
};

#endif