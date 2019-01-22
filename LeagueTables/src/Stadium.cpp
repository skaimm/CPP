#include "Stadium.h"

Stadium::Stadium()
{
    StadiumID=0;
    StadiumName='\0';
    Capacity=0;
    Location='\0';
    YearOfBuild=0;

    TeamName=NULL;
}

Stadium::Stadium(int IDOfStadium, string NameOfStadium , int CapacityOfStadium , string LocationOfStadium, int Year)
{
    StadiumID=IDOfStadium;
    StadiumName=NameOfStadium;
    Capacity=CapacityOfStadium;
    Location=LocationOfStadium;
    YearOfBuild=Year;

    TeamName=NULL;

}
Stadium::~Stadium()
{
    //dtor
}
