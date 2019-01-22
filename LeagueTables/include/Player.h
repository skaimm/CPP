#ifndef PLAYER_H
#define PLAYER_H

#include "stdafx.h"

using namespace std;

class Team;
class Player
{
    public:
        //Varlik �zellikleri
        int PlayerID;
        string FirstNameOfPlayer;
        string LastNameOfPlayer;
        int Age;
        string Country; // oyuncunun ulkesi
        int Salary;  // birimi euro olacak
        string Position; // Position de�erinin yanlis yazilmis.

        // Diger siniflarla iliskisi
        Team *TeamName; // oyunucunun takimi - takim iliskisi


        //cons ve decons
        Player();
        Player(int,string,string,int,string,int,string);
        virtual ~Player();


};

#endif // PLAYER_H
