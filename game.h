/*
 * game.h
 * COMP11 Sushi Go
 */

#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <fstream>
#include <string>
#include "termfuncs.h"
#include "board.h"
#include "player.h"
#include "card.h"

using namespace std;

class Game{
    public:
        //constructor/destructor
        Game(string filename, string play_chopsticks);
        ~Game();

        //main gameplay
        void playGame();

    private:
        //constants
        static const int PLAYER_COUNT = 3;
        static const int ROUNDS = 3;
        static const int CARD_HAND = 9;

        //chopsticks activated true/false
        bool play_chopsticks;

        //card deck
        vector<Card> deck;

        //game objects
        Board board;
        Player players[PLAYER_COUNT];
};

#endif
