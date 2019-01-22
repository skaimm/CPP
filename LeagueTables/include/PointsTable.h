#ifndef POINTSTABLE_H
#define POINTSTABLE_H

#include "stdafx.h"

using namespace std;

class Team;
class PointsTable
{
    public:
    //Varlik ozellikleri
        int Position;
        int Won;
        int Losses;
        int Draw;   // unutulmus- Beraberlik sayisi
        int GoalsScored;
        int GoalsAgainst;
        int GoalDifference;
        int GamesPlayed;
        int Points;

        // Diðer siniflarla iliskisi
        vector<Team*> TeamName; // Ligde bulunan takimlar - takim iliskisi



        //cons ve decons
        PointsTable();
        PointsTable(int,int,int,int,int,int,int,int,int);
        virtual ~PointsTable();


};

#endif // POINTSTABLE_H
