#include "Fifa.h"

Fifa::Fifa()
{
    //ctor
}

Fifa::Fifa(Database *datum)
{
    database=datum;
}
Fifa::~Fifa()
{
    //dtor
}


bool Fifa::NewCreateClub(Team* NewTeam)
{
    database->Teams.push_back(NewTeam);
    return true;
}
bool Fifa::NewCreatePlayer(Player* NewPlayer)
{
    database->Players.push_back(NewPlayer);
    return true;
}
bool Fifa::NewCreateManager(Manager* NewManager)
{
    database->Managers.push_back(NewManager);
    return true;
}
bool Fifa::NewCreateOwner(Owner* NewOwner)
{
    database->Owners.push_back(NewOwner);
    return true;
}
bool Fifa::NewCreateStadium(Stadium* NewStadium)
{
    database->Stadiums.push_back(NewStadium);
    return true;
}
bool Fifa::NewCreateMatch(Match* NewMatch)
{
    database->Matches.push_back(NewMatch);
    return true;
}






bool Fifa::DeleteClub(int id)
{
    Team * willbedeleted = database->FindClub(id);

    if(willbedeleted==NULL)
    {
        return false;
    }

    // oyuncularý iliskiden cýkarýlýr
    if(willbedeleted->Players.size()>0)
    {
        vector<Player*> &players = willbedeleted->Players;
        for (int i = 0; i < players.size(); i++)
        {
            PlayerRemovetoTeam(players[i], willbedeleted);
        }
    }

	// stadyum iliskiden cýkarýlýr
	if(willbedeleted->StadiumName!=NULL)
	StadiumRemovetoTeam(willbedeleted->StadiumName, willbedeleted);
	//manager ilskiden cikarilir
	if(willbedeleted->ManagerID!=NULL)
	ManagerRemovetoTeam(willbedeleted->ManagerID, willbedeleted);
	// baskan iliskiden cikarilir
	if(willbedeleted->OwnerID!=NULL)
	OwnerRemovetoTeam(willbedeleted->OwnerID, willbedeleted);

	// takim silinir.
	database->Teams.erase( find( database->Teams.begin(), database->Teams.end(), willbedeleted ) );
	delete willbedeleted;

	return true;
}
bool Fifa::DeletePlayer(int id)
{
    Player* willbedeleted = database->FindPlayer(id);
    if(willbedeleted==NULL)
    {
        return false;
    }
    // takim iliski bozma
    if(willbedeleted->TeamName!=NULL)
    PlayerRemovetoTeam(willbedeleted,willbedeleted->TeamName);

    // oyuncu silinir.
	database->Players.erase( find( database->Players.begin(), database->Players.end(), willbedeleted ) );
	delete willbedeleted;

	return true;
}
bool Fifa::DeleteManager(int id)
{
    Manager* willbedeleted = database->FindManager(id);
    if(willbedeleted==NULL)
    {
        return false;
    }

    // takim iliski bozma
    if(willbedeleted->TeamName!=NULL)
    ManagerRemovetoTeam(willbedeleted,willbedeleted->TeamName);

    // manager silinir.
	database->Managers.erase( find( database->Managers.begin(), database->Managers.end(), willbedeleted ) );
	delete willbedeleted;

	return true;
}
bool Fifa::DeleteOwner(int id)
{
    Owner* willbedeleted = database->FindOwner(id);
    if(willbedeleted==NULL)
    {
        return false;
    }

    // takim iliski bozma
    if(willbedeleted->TeamName!=NULL)
    OwnerRemovetoTeam(willbedeleted,willbedeleted->TeamName);

    // baskan silinir.
	database->Owners.erase( find( database->Owners.begin(), database->Owners.end(), willbedeleted ) );
	delete willbedeleted;

	return true;
}
bool Fifa::DeleteStadium(int id)
{
    Stadium* willbedeleted = database->FindStadium(id);
    if(willbedeleted==NULL)
    {
        return false;
    }

    // takim iliski bozma
    if(willbedeleted->TeamName!=NULL)
    StadiumRemovetoTeam(willbedeleted,willbedeleted->TeamName);

    // stadyum silinir.
	database->Stadiums.erase( find( database->Stadiums.begin(), database->Stadiums.end(), willbedeleted ) );
	delete willbedeleted;

	return true;
}
bool Fifa::DeleteMatch(int id)
{
    Match* willbedeleted = database->FindMatch(id);
    if(willbedeleted==NULL)
    {
        return false;
    }

    // stadium iliski bozma
    if(willbedeleted->StadiumName!=NULL)
    MatchRemovetoStadium(willbedeleted,willbedeleted->StadiumName);

    // takim iliski nozma
    if(willbedeleted->HomeAwayTeam.size()!=0)
    {
        vector<Team*> &teams = willbedeleted->HomeAwayTeam;
        int Size = teams.size();
        for (int i = 0; i < Size; i++)
        {
            MatchRemovetoTeam(willbedeleted,teams[i]);
        }
    }

    // match silinir.
	database->Matches.erase( find( database->Matches.begin(), database->Matches.end(), willbedeleted ) );
	delete willbedeleted;

	return true;
}







bool Fifa::PlayerTransfertoTeam(Player* player,Team* team)
{
    //önceki bað koparýlýr.
    if(player->TeamName!=NULL)
        PlayerRemovetoTeam(player, player->TeamName);

	//yeni bað kurulur
	player->TeamName = team;
	team->Players.push_back(player);

	return true;
}
bool Fifa::ManagerTranfertoTeam(Manager* manager,Team* team)
{
    //önceki bað koparýlýr.
    if(manager->TeamName!=NULL || team->ManagerID!=NULL)
        ManagerRemovetoTeam(manager, manager->TeamName);

	//yeni bað kurulur
	manager->TeamName = team;
	team->ManagerID = manager;

	return true;
}
bool Fifa::OwnerTranfsertoTeam(Owner* owner,Team* team)
{
    //önceki bað koparýlýr.
    if(owner->TeamName!=NULL || team->OwnerID!=NULL)
	OwnerRemovetoTeam(owner, owner->TeamName);

	//yeni bað kurulur
	owner->TeamName = team;
	team->OwnerID=owner;

	return true;
}
bool Fifa::StadiumAssigmenttoTeam(Stadium* stadium ,Team* team)
{
    //önceki bað koparýlýr.
    if(stadium->TeamName!=NULL || team->StadiumName!=NULL)
	StadiumRemovetoTeam(stadium, stadium->TeamName);

	//yeni bað kurulur
	stadium->TeamName = team;
	team->StadiumName= stadium;

	return true;
}
bool Fifa::MatchAssigmenttoTeam(Match* match,Team* team)
{
    if(match->HomeAwayTeam.size()<2)
    {
        match->HomeAwayTeam.push_back(team);
        team->Matches.push_back(match);

        return true;
    }
    else
    {
        return false;
    }
}
bool Fifa::MatchAssigmenttoStadium(Match* match,Stadium* stadium)
{
    if(match->StadiumName!=NULL)
	MatchRemovetoStadium(match, match->StadiumName);

	match->StadiumName=stadium;
	stadium->Matches.push_back(match);

	return true;
}







bool Fifa::PlayerRemovetoTeam(Player* player ,Team* team)
{
    //bire çok iliþki koparma
    player->TeamName = NULL;
	team->Players.erase( find(team->Players.begin(), team->Players.end(), player) );
	return true;
}
bool Fifa::ManagerRemovetoTeam(Manager* manager,Team* team)
{
    //birebir iliþki koparma
    manager->TeamName = NULL;
	team->ManagerID = NULL;
	return true;
}
bool Fifa::OwnerRemovetoTeam(Owner* owner,Team* team)
{
    //birebir iliþki koparma
    owner->TeamName = NULL;
	team->OwnerID = NULL;
	return true;
}
bool Fifa::StadiumRemovetoTeam(Stadium* stadium,Team* team)
{
    //birebir iliþki koparma
    stadium->TeamName = NULL;
	team->StadiumName = NULL;
	return true;
}
bool Fifa::MatchRemovetoTeam(Match* match ,Team* team)
{
    // coka cok iliski koparma
	team->Matches.erase( find(team->Matches.begin(), team->Matches.end(), match)  );
	match->HomeAwayTeam.erase(  find(match->HomeAwayTeam.begin(), match->HomeAwayTeam.end(), team) );

	return true;
}
bool Fifa::MatchRemovetoStadium(Match* match ,Stadium* stadium)
{
    //bire çok iliþki koparma
    match->StadiumName = NULL;
	stadium->Matches.erase( find( stadium->Matches.begin(),stadium->Matches.end(), match) );
	return true;
}

