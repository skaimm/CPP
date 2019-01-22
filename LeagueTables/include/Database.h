#ifndef DATABASE_H
#define DATABASE_H

#include "stdafx.h"

using namespace std;

class Fifa;
class Team;
class Interface;
class Manager;
class Owner;
class Player;
class Stadium;
class Match;
class Database
{
    public:
        Database();
        virtual ~Database();

        //veriler
        vector<Team*> Teams;
        vector<Player*> Players;
        vector<Manager*> Managers;
        vector<Owner*> Owners;
        vector<Stadium*> Stadiums;
        vector<Match*> Matches;

        vector<int>TeamForMOS;
        vector<int>Managersid;
        vector<int>Ownersid;
        vector<int>Stadiumsid;

        vector<int>Playersid;
        vector<int>TeamForPlayers;

        vector<int>Matchesid;
        vector<int>HomeTeamid;
        vector<int>AwayTeamid;
        vector<int>StadiumidForMatch;

        Team *FindClub(int);
        Player *FindPlayer(int);
        Manager *FindManager(int);
        Owner *FindOwner(int);
        Stadium *FindStadium(int);
        Match *FindMatch(int);

        void Create();
        void Create(string,string,string,string,string,string);

        bool Save();
        bool Save(string,string,string,string,string,string);

        //veri yukleme
        void ReadClub(string);
        void ReadPlayer(string);
        void ReadStadium(string);
        void ReadOwner(string);
        void ReadManager(string);
        void ReadMatch(string);

        //kaydetme
        bool SaveClubs(string);
        bool SavePlayer(string);
        bool SaveStadium(string);
        bool SaveOwner(string);
        bool SaveManager(string);
        bool SaveMatch(string);

        //iliski kurma

        void PlayerOfTeams();
        void MOSOfTeams();
        void MatchesForTS();




    private:
};

#endif // DATABASE_H
