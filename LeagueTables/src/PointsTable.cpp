#include "PointsTable.h"

PointsTable::PointsTable()
{
    Position=1;
    Won=0;
    Losses=0;
    Draw=0;
    GoalsScored=0;
    GoalsAgainst=0;
    GoalDifference=0;
    GamesPlayed=0;
    Points=0;
}

PointsTable::PointsTable(int Pos,int W,int D,int L,int Score,int Against,int Dif, int Game,int Point)
{
    Position=Pos;
    Won=W;
    Losses=L;
    Draw=D;
    GoalDifference=Dif;
    GoalsScored=Score;
    GoalsAgainst=Against;
    GamesPlayed=Game;
    Points=Point;
}

PointsTable::~PointsTable()
{
    //dtor
}

