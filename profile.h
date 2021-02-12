#pragma once
#include <iostream>

using namespace std;

class Profile
{
private:
    string playerName;
    int playerScore = 0;

public:
    Profile()
    {

    }

    //Accessors
    string getPlayerName()
    {
        return playerName;
    }

    int getPlayerScore()
    {
        return playerScore;
    }

    //Mutators
    string initPlayerName(string newName)
    {
        playerName = newName;
    }

    int initPoints(int newPoints)
    {
        playerScore = newPoints;
    }
};