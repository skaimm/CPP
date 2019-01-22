#ifndef STADIUM_H
#define STADIUM_H

#include "stdafx.h"

using namespace std;

class Team;
class Stadium
{
    public:
        //Varlik özellikleri
        int StadiumID;  // Stadyum ismi int olarak gosterilmis ID olmasi gerekiyordu isim ve id karistirilmis.
        string StadiumName;
        int Capacity;
        string Location;
        int YearOfBuild;

        // Diger siniflarla iliskisi

        Team *TeamName;  // Sahibi oldugu takim - takim iliskisi
        vector<Match*> Matches;

        //cons ve decons
        Stadium();
        Stadium(int,string,int,string,int);
        virtual ~Stadium();

};

#endif // STADIUM_H
