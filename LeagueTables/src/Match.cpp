#include "Match.h"

Match::Match()
{
    MatchID=0;
    HomeScore=0;
    AwayScore=0;

    DateOfMatch={0,0,0};
    StadiumName=NULL;
}

Match::Match(int ID,int HScore,int AScore,Date date)
{
    MatchID=ID;
    HomeScore=HScore;
    AwayScore=AScore;

    DateOfMatch=date;
    StadiumName=NULL;
}

Match::~Match()
{

}
