#include "Team.h"

Team::Team()
{
    TeamID=-1;
    TeamName='\0';
    NumberOfTrophies=0;

    YearOfEstablishment=0;
    ManagerID=NULL;
    OwnerID=NULL;
    StadiumName=NULL;
}

Team::Team(int IDofTeam,string NameOfTeam, int Year, int Trophies)
{
    TeamID=IDofTeam;
    TeamName=NameOfTeam;
    NumberOfTrophies=Trophies;
    YearOfEstablishment=Year;

    ManagerID=NULL;
    OwnerID=NULL;
    StadiumName=NULL;
}

Team::~Team()
{
    //dtor
}
