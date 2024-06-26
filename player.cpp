#include <iostream>
#include <string>
#include "player.h"
#include "board.h"

using namespace std;

Player::Player() {
  puddingCount = 0;
  score = 0;
}

vector<Card>* Player::getHand() {
  return &hand;
}

vector<Card>* Player::getSelectedCards() {
  return &selectedCards;
}

vector<Card>* Player::getPassingHand() {
  return &passingHand;
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

void Player::setSelectedCards(vector<Card> selectedCards) {
  this->selectedCards = selectedCards;
}

void Player::setPassingHand(vector<Card> passingHand) {
  this->passingHand = passingHand;
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

void Player::addCardToSelectedCards(Card card) {
  this->selectedCards.push_back(card);
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

void Player::removeCardFromSelectedCards(Card card) {
  for (int i = 0; i < selectedCards.size(); i++) {
    if (selectedCards[i] == card) {
      selectedCards.erase(selectedCards.begin() + i);
      break;
    }
  }
}

void Player::removeCardFromSelectedCards(int index) {
  selectedCards.erase(selectedCards.begin() + index);
}

void Player::displaySelectedCards() {

}

Card Player::getCardFromHand(int index) {
  return hand[index];
}