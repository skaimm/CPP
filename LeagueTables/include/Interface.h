#ifndef INTERFACE_H
#define INTERFACE_H

#include "stdafx.h"

using namespace std;

class Fifa;
class Team;
class Database;
class Player;
class Match;
class Manager;
class Owner;
class Stadium;
class Interface
{
    public:
        Interface(Database*,Fifa*);
        virtual ~Interface();

        void Start();
        void MainMenu();

        // Listeleme
        void ListClub();
        void ListPlayer();
        void ListManager();
        void ListOwner();
        void ListStadium();
        void ListMatch();

        // Ekleme
        void AddClub();
        void AddPlayer();
        void AddManager();
        void AddOwner();
        void AddStadium();
        void AddMatch();

        //Silme
        void DeleteClub();
        void DeletePlayer();
        void DeleteManager();
        void DeleteOwner();
        void DeleteStadium();
        void DeleteMatch();

        //Düzenleme
        void EditClub(Team*);
        void EditPlayer(Player*);
        void EditManager(Manager*);
        void EditOwner(Owner*);
        void EditStadium(Stadium*);
        void EditMatch(Match*);

        //Gösterme
        void ShowClub(Team*);
        void ShowPlayer(Player*);
        void ShowManager(Manager*);
        void ShowOwner(Owner*);
        void ShowStadium(Stadium*);
        void ShowMatch(Match*);

        void ShowClubs(vector<Team*> &);
        void ShowPlayers(vector<Player*> &);
        void ShowManagers(vector<Manager*> &);
        void ShowOwners(vector<Owner*> &);
        void ShowStadiums(vector<Stadium*> &);
        void ShowMatches(vector<Match*> &);

        //Arama-Bulma

        void FindClub();
        void FindPlayer();
        void FindManager();
        void FindOwner();
        void FindStadium();
        void FindMatch();


    private:
        Database *database;
        Fifa *Admin;
};

#endif // INTERFACE_H
