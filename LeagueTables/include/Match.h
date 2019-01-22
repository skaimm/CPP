#ifndef MATCH_H
#define MATCH_H

#include "stdafx.h"

typedef struct {
    int Day;
    int Month;
    int Year;
    }Date;

using namespace std;

class Team;
class Stadium;
class Match
{
    public:
        //Varlik özellikleri
        int MatchID;
        Date DateOfMatch;
        // match sinifini yetersiz gordugum icin rakip ve mac sonucunu ekledim.

        int HomeScore;
        int AwayScore;
        // Diger siniflarla iliskisi
        vector<Team*>HomeAwayTeam;
        Stadium *StadiumName; // karsilasmanin oynandigi stad - stadyum iliskisi
        //cons ve decons
        Match();
        Match(int,int,int,Date);
        virtual ~Match();



};

#endif // MATCH_H
