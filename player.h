/*
 * player.h
 * COMP11 Sushi Go
 */

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <vector>
#include "card.h"

class Player {
public:
  Player();
  Player(std::vector<Card> hand);

  std::vector<Card>* getPassingHand();
  std::vector<Card>* getRevealedCards();
  int getPuddingCount();
  int getScore();

  void setHand(std::vector<Card> hand);
  void setSelectedCards(std::vector<Card> selectedCards);
  void setPuddingCount(int puddingCount);
  void setScore(int score);

  void addCardToHand(Card card);
  void addCardToSelectedCards(Card card);

  void removeCardFromHand(Card card);
  void removeCardFromHand(int index);
  void removeCardFromSelectedCards(Card card);
  void removeCardFromSelectedCards(int index);

  void displaySelectedCards();

private:
  // Data members
  std::vector<Card> hand;
  std::vector<Card> selectedCards;
  int puddingCount;
  int score;
};

#endif