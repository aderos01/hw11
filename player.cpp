#include <iostream>
#include <string>
#include "player.h"
#include "board.h"

using namespace std;

Player::Player() {
  puddingCount = 0;
  score = 0;
}

vector<Card>* Player::getPassingHand() {
  return &passingHand;
}

vector<Card>* Player::getSelectedCards() {
  return &revealedCards;
}

int Player::getPuddingCount() {
  return puddingCount;
}

int Player::getScore() {
  return score;
}

void Player::setHand(vector<Card> hand) {
  this->hand = hand;
}

void Player::setSelectedCards(vector<Card> revealedCards) {
  this->revealedCards = revealedCards;
}

void Player::setPuddingCount(int puddingCount) {
  this->puddingCount = puddingCount;
}

void Player::setScore(int score) {
  this->score = score;
}

void Player::addCardToHand(Card card) {
  this->hand.push_back(card);
}

void Player::addCardToPassingHand(Card card) {
  this->passingHand.push_back(card);
}

void Player::removeCardFromHand(Card card) {
  for (int i = 0; i < hand.size(); i++) {
    if (hand[i] == card) {
      hand.erase(hand.begin() + i);
      break;
    }
  }
}

void Player::removeCardFromHand(int index) {
  hand.erase(hand.begin() + index);
}

void Player::removeCardFromPassingHand(Card card) {
  for (int i = 0; i < passingHand.size(); i++) {
    if (passingHand[i] == card) {
      passingHand.erase(passingHand.begin() + i);
      break;
    }
  }
}

void Player::removeCardFromPassingHand(int index) {
  passingHand.erase(passingHand.begin() + index);
}

void Player::displaySelectedCards() {
  
}