/*
 * game.cpp
 * CS11 Sushi Go
 */

#include "game.h"
#include <iostream>
#include <fstream>
#include <string>

//constructor
Game::Game(string filename, string play_chopsticks){
    //include chopsticks or not
    if(play_chopsticks == "true"){
        this->play_chopsticks = true;
    }else{
        this->play_chopsticks = false;
    }  

    /*-----------------------------------------------*/
    /*   TODO (Part I): FINISH SETTING UP THE GAME   */
    /*                                               */
    /*   Read from the input file to initialize the  */
    /*   deck.                                       */
    /*-----------------------------------------------*/  
    ifstream file(filename);
    if (!file) {
        cerr << "Error: Cannot open file " << filename << endl;
        exit(EXIT_FAILURE);
    }

    string type;
    string count;
    while (file >> type >> count) {
        // int num = stoi(count);
        // for (int i = 0; i < num; i++) {
        if (type != "type" && count != "count")
           deck.push_back(Card(type, count));
        // }
    }

    //initialize players
    for(int i = 0; i < PLAYER_COUNT; i++){
        players.push_back(Player());
    }
}

//main game loop
void Game::playGame(){
    int card_index;
    string play_on;

    //play three rounds
    for(int round = 0; round < ROUNDS; round++){
        /*   TODO (Part I): Deal 9 cards to each player          */
        // draw 9 cards for each player
        for(int player = 0; player < PLAYER_COUNT; player++){
            for(int card = 0; card < CARD_HAND; card++){
                /*   TODO (Part I): Draw a card from the deck      */
                Card c = deck.back();
                deck.pop_back();
                /*   TODO (Part I): Add card to player's hand      */
                players[player].hand.push_back(c);
            }
        }


        //select and pass all 27 cards
        for(int card = 0; card < CARD_HAND; card++){
            for(int player = 0; player < PLAYER_COUNT; player++){
                board.drawBoard(players, player);

                cout << " Player " << player + 1 << ", select a card: ";
                cin >> card_index;
                if(!cin){ //bail out of game if they enter a non-number
                    cerr << " INVALID INPUT: No game for you!\n";
                    exit(EXIT_FAILURE);
                }

                /*   TODO (Part I): Set aside selected card      */
                // Create a temporary card to store the selected card
                Card temp = players[player].hand[card_index];
                // Remove the selected card from the player's hand
                players[player].hand.erase(players[player].hand.begin() + card_index);
                // Add the selected card to the player's revealed cards
                players[player].selectedCards.push_back(temp);
            }
            /*   TODO (Part I): Reveal selected cards            */
            board.drawBoard(players, round);
            
            /*   TODO (Part I): Pass deck to the right           */
            vector<Vector<Card>> tempHands(PLAYER_COUNT);
            for (int player = 0; player < PLAYER_COUNT; player++) {
                tempHands[player] = players[player].hand;
            }
            for (int player = 0; player < PLAYER_COUNT; player++) {
                int next_player = (player + 1) % PLAYER_COUNT;
                players[player].hand = tempHands[next_player];
            }
        }
        
        break;
        /*   TODO (Part II): Remove the above break statement    */
        /*   TODO (Part II): Update Scores                       */
        /*   TODO (Part II): Call board.drawScore(players);      */
        /*   TODO (Part II): Prompt to go on to next round       
        if(round < 2){
            cout << " End of round! Ready for Round "
                 << round + 2 << " ? (y/n): ";
            cin >> play_on;
            if(play_on != "y"){
                break;
            }
        }                                                        */

        /*   TODO (Part II): Reset for next round                */
    }

    /*   TODO (Part II): Score pudding and determine winner      */
    /*   TODO (Part II): Call board.drawWinner(players, winner); */
}

//destructor
Game::~Game(){
    /*-----------------------------------------------*/
    /*   TODO (Parts I and II): CLEAN UP THE GAME    */
    /*                                               */
    /*   Make sure you are passing valgrind.         */
    /*-----------------------------------------------*/ 
}
