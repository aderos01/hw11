#include <iostream>
#include <string>
#include "card.h"

using namespace std;

Card::Card() {
    sushiType = "";
    makiCount = 0;
}

Card::Card(string type, int count) {
    sushiType = type;
    makiCount = count;
}

string Card::getSushiType() {
    return sushiType;
}

int Card::getMakiCount() {
    return makiCount;
}

bool Card::operator==(const Card& other) const {
    return (sushiType == other.sushiType && makiCount == other.makiCount);
}