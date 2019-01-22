#ifndef TEAM_H
#define TEAM_H

#include <string>
#include <list>
/* Date tipi bir degisken tanımlanmis, c++ da olmadigi icin
struct olusturdum.
*/
#include "stdafx.h"


using namespace std;

// date olarak girilmis deger icin struct olusturdum
class Database;
class Interface;
class Player;
class Stadium;
class Owner;
class Manager;
class Match;
class Team
{
    public:
        //Varlik özellikleri
        int TeamID;
        string TeamName;
        int YearOfEstablishment;
        int NumberOfTrophies; // takim sampiyonluk sayisi girilecek

        // Diger Siniflarla iliskisi
        Manager *ManagerID; // Takimin Manageri - manager iliskisi
        vector<Player*> Players; // Takimin oyunculari - player iliskisi
        Stadium *StadiumName; // Takimin stadyumu - stadium iliskisi
        Owner *OwnerID; // Takimin baskani - owner iliskisi
        vector<Match*> Matches;


        //cons ve decons
        Team();
        Team(int,string,int,int);
        virtual ~Team();

        // takimin metodlari - sinif iliskisi
};

#endif // TEAM_H
