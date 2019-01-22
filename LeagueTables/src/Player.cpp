#include "Player.h"

Player::Player()
{
    PlayerID=0;
    FirstNameOfPlayer='\0';
    LastNameOfPlayer='\0';
    Age=0;
    Country='\0';
    Salary=0;
    Position='\0';

    TeamName=NULL;
}

Player::~Player()
{
    //dtor
}

Player::Player(int ID,string Name,string LastName,int PlayerAge,string CountryOfPlayer,int SalaryOfPlayer,string Pos)
{
    PlayerID=ID;
    FirstNameOfPlayer=Name;
    LastNameOfPlayer=LastName;
    Age=PlayerAge;
    Country=CountryOfPlayer;
    Salary=SalaryOfPlayer;
    Position=Pos;

    TeamName=NULL;
}

