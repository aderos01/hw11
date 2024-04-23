/*
 * game.cpp
 * CS11 Sushi Go
 */

#include "game.h"
#include <iostream>
#include <fstream>
#include <sstream>
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
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error: Cannot open file " << filename << std::endl;
        exit(EXIT_FAILURE);
    }

    std::string line;
    getline(file, line); // Skip the header line

    while (getline(file, line)) {
        std::istringstream iss(line);
        std::string type;
        std::string countStr;
        int count = 0; // Default count

        iss >> type;
        if (iss >> countStr) { // Attempt to read the count
            try {
                count = std::stoi(countStr);
            } catch (const std::invalid_argument& e) {
                std::cerr << "Invalid number format for count in line: " << line << std::endl;
                // Assume default count = 1 if conversion fails
            } catch (const std::out_of_range& e) {
                std::cerr << "Number out of range for count in line: " << line << std::endl;
                // Assume default count = 1 if conversion fails
            }
        }

        if (!type.empty()) {
            Card c(type, count);
            deck.push_back(c);
        }
    }

    file.close();

    //initialize players
    // Make a temporary array of players
    // Player temp_players[PLAYER_COUNT] = {Player(), Player(), Player()};
    // Set the players array to the temporary array
    for (int i = 0; i < PLAYER_COUNT; i++) {
        players[i] = Player();
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
                players[player].addCardToHand(c);
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
                Card temp = players[player].getCardFromHand(card_index);
                // Remove the selected card from the player's hand
                players[player].removeCardFromHand(card_index);
                // Add the selected card to the player's revealed cards
                players[player].addCardToSelectedCards(temp);
            }
            /*   TODO (Part I): Reveal selected cards            */
            board.drawBoard(players, round);
            
            /*   TODO (Part I): Pass deck to the right           */
            // set all players passingHands to their hands
            for (int player = 0; player < PLAYER_COUNT; player++) {
                players[player].setPassingHand(*players[player].getHand());
            }
            // set each player's hand to the passingHand of the previous player
            for (int player = 0; player < PLAYER_COUNT; player++) {
                players[(player + 1) % PLAYER_COUNT].setHand(*players[player].getPassingHand());
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
