#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <vector>
#include "Card.h"

class Player {
public:
  Player();

  void getPassingHand();
  void getRevealedCards();
  void getPuddingCount();
  void getScore();

private:
  // Data members
  std::vector<Card> hand;
  std::vector<Card> passingHand;
  std::vector<Card> revealedCards;
  int puddingCount;
  int score;
};

#endif