#ifndef FIFA_H
#define FIFA_H

#include "stdafx.h"

class Database;
class Fifa
{
    public:
        Fifa();
        Fifa(Database*);
        virtual ~Fifa();

        Database *database;

        bool NewCreateClub(Team*);
        bool NewCreatePlayer(Player*);
        bool NewCreateManager(Manager*);
        bool NewCreateOwner(Owner*);
        bool NewCreateStadium(Stadium*);
        bool NewCreateMatch(Match*);


        bool DeleteClub(int);
        bool DeletePlayer(int);
        bool DeleteManager(int);
        bool DeleteOwner(int);
        bool DeleteStadium(int);
        bool DeleteMatch(int);

        //iliski kurma

        bool PlayerTransfertoTeam(Player*,Team*);
        bool ManagerTranfertoTeam(Manager*,Team*);
        bool OwnerTranfsertoTeam(Owner*,Team*);
        bool StadiumAssigmenttoTeam(Stadium*,Team*);
        bool MatchAssigmenttoTeam(Match*,Team*);
        bool MatchAssigmenttoStadium(Match*,Stadium*);

        //iliski yikma

        bool PlayerRemovetoTeam(Player*,Team*);
        bool ManagerRemovetoTeam(Manager*,Team*);
        bool OwnerRemovetoTeam(Owner*,Team*);
        bool StadiumRemovetoTeam(Stadium*,Team*);
        bool MatchRemovetoTeam(Match*,Team*);
        bool MatchRemovetoStadium(Match*,Stadium*);






    private:
};

#endif // FIFA_H
