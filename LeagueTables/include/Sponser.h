#ifndef SPONSER_H
#define SPONSER_H

#include "stdafx.h"

class Team;
class Sponser
{
    public:
        //Varlik özellikleri
        int SponserID;
        string SponserName;

        // Diger siniflarla iliskileri
        vector<Team*> TeamName; // sponsor oldugu takimlar - takim iliskisi

        //cons ve decons
        Sponser();
        Sponser(int,string);
        virtual ~Sponser();


};

#endif // SPONSER_H
