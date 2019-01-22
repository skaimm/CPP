#include "Database.h"

Database::Database()
{
    //ctor
}

Database::~Database()
{
    //dtor
}

void Database::Create(string ClubFile,string PlayerFile,string StadiumFile,
                        string ManagerFile,string ChairmanFile,string MatchFile)
{
    ReadClub(ClubFile);
    ReadPlayer(PlayerFile);
    ReadStadium(StadiumFile);
    ReadManager(ManagerFile);
    ReadOwner(ChairmanFile);
    ReadMatch(MatchFile);
    PlayerOfTeams();
    MOSOfTeams();
    MatchesForTS();
}

void Database::Create()
{
   Create("Club.txt","Player.txt","Stadium.txt","Manager.txt","Chairman.txt","Match.txt");
}
bool Database::Save()
{
   return Save("Club.txt","Player.txt","Stadium.txt","Manager.txt","Chairman.txt","Match.txt");
}
bool Database::Save(string ClubFile,string PlayerFile,string StadiumFile,
                        string ManagerFile,string ChairmanFile,string MatchFile )
{
    if(SaveClubs(ClubFile)==false) return false;

	if(SavePlayer(PlayerFile)==false) return false;

	if(SaveStadium(StadiumFile)==false) return false;

	if(SaveManager(ManagerFile)==false) return false;

	if(SaveOwner(ChairmanFile)==false) return false;

	if(SaveMatch(MatchFile)==false) return false;

	return true;
}




void Database::ReadClub(string ClubFile)
{
    ifstream File;
	File.open(ClubFile.c_str());

	if(File.is_open())
	{
		char line[100];
		File.getline(line,100);
		int id , estab , champ ,stadium,manager,owner;
		string name;
		while(!File.eof())
		{
			File >> id>> name>> estab>> champ>> stadium >> manager >> owner;

			for(int i=0;i<=Teams.size();i++)
            {
                Team* team=FindClub(id);
                if(team==NULL)
                {
                    TeamForMOS.push_back(id);
                    Stadiumsid.push_back(stadium);
                    Managersid.push_back(manager);
                    Ownersid.push_back(owner);
                    Teams.push_back(new Team(id,name,estab,champ));
                }
            }
		}

		File.close();
	}
}
void Database::ReadManager(string ManagerFile)
{
    ifstream File;
	File.open(ManagerFile.c_str());

	if(File.is_open())
	{
		char line[1000];
		File.getline(line,1000);
		int id , salary , age ,team ;
		string name,surname,country,tac,unnes;
		while(!File.eof())
		{
			File >> id >> name>> surname>> age>> country>> salary>> team;

			for(int i=0;i<=Managers.size();i++)
            {
                Manager* manager=FindManager(id);
                if(manager==NULL)
                {
                    Managers.push_back(new Manager(id,name,surname,country,age,salary));
                }
            }
		}

		File.close();
	}
}
void Database::ReadOwner(string OwnerFile)
{
    ifstream File;
	File.open(OwnerFile.c_str());

	if(File.is_open())
	{
		char line[1000];
		File.getline(line,1000);
		int id,team;
		string name,surname;
		while(!File.eof())
		{
			File >> id
                >> name
                >> surname
                >> team;

            for(int i=0;i<=Owners.size();i++)
            {
                Owner* owner=FindOwner(id);
                if(owner==NULL)
                {
                   Owners.push_back(new Owner(id,name,surname));
                }
            }
		}

		File.close();
	}
}
void Database::ReadStadium(string StadiumFile)
{
    ifstream File;
	File.open(StadiumFile.c_str());

	if(File.is_open())
	{
		char line[1000];
		File.getline(line,1000);
		int id , year , capacity;
		string name,surname,location,team;
		while(!File.eof())
		{
			File >> id
                >> name
                >> capacity
                >> location
                >> year
                >> team; //team

            for(int i=0;i<=Stadiums.size();i++)
            {
                Stadium* stadium=FindStadium(id);
                if(stadium==NULL)
                {
                   Stadiums.push_back(new Stadium(id,name,capacity,location,year));
                }
            }
		}

		File.close();
	}
}
void Database::ReadPlayer(string PlayerFile)
{
    ifstream File;
	File.open(PlayerFile.c_str());

	if(File.is_open())
	{
		char line[1000];
		File.getline(line,1000);
		int id , salary , age ,team;
		string name,surname,country,pos;
		while(!File.eof())
		{
			File >> id
                >> name
                >> surname
                >> age
                >> country
                >> pos
                >> salary
                >> team; //team
            for(int i=0;i<=Players.size();i++)
            {
                Player* player=FindPlayer(id);
                if(player==NULL)
                {
                    Playersid.push_back(id);
                    TeamForPlayers.push_back(team);
                    Players.push_back(new Player(id,name,surname,age,country,salary,pos));
                }
            }
		}
		File.close();
	}
}
void Database::ReadMatch(string MatchFile)
{
    ifstream File;
	File.open(MatchFile.c_str());

	if(File.is_open())
	{
		char line[1000];
		File.getline(line,1000);
		int id,hscore,ascore,day,month,year,team1,team2,stadium;

		while(!File.eof())
		{
			File >> id>> day >> month >> year>> team1 >> team2 >> hscore >> ascore>> stadium;

                for(int i=0;i<=Matches.size();i++)
                {
                    Match* match=FindMatch(id);
                    if(match==NULL)
                    {
                        Matchesid.push_back(id);
                        HomeTeamid.push_back(team1);
                        AwayTeamid.push_back(team2);
                        StadiumidForMatch.push_back(stadium);
                        Matches.push_back(new Match(id,hscore,ascore,{day,month,year}));
                    }
                }

		}

		File.close();
	}
}






bool Database::SaveClubs(string ClubFile)
{
    ofstream File;
	File.open(ClubFile.c_str());
	string tab="    ";
	if(File.is_open())
	{
	    File <<"Id     Team         Establishment   Champion   Stadium    Manager    Owner"<<endl;
		int Size =Teams.size();
		for (int i = 0; i < Size; i++ )
		{
			File  << Teams[i]->TeamID<<tab
                  << Teams[i]->TeamName<<tab
                  << Teams[i]->YearOfEstablishment<<tab
                  << Teams[i]->NumberOfTrophies<<tab;
                  if(Teams[i]->StadiumName!=NULL)
                    File << Teams[i]->StadiumName->StadiumID<<tab;
                  else
                    File << "-1"<<tab;
                  if(Teams[i]->ManagerID!=NULL)
                    File << Teams[i]->ManagerID->ManagerID<<tab;
                  else
                    File << "-1"<<tab;
                  if(Teams[i]->OwnerID!=NULL)
                    File << Teams[i]->OwnerID->OwnerID<<endl;
                  else
                    File << "-1"<<endl;
		}
		File.close();
		return true;
	}
	else
	{
		return false;
	}
}
bool Database::SavePlayer(string PlayerFile)
{
    ofstream File;
	File.open(PlayerFile.c_str());
	string tab="    ";
	if(File.is_open())
	{
	    File <<"Id     Name    Surname    Age   Country    Position    Salary   Team"<<endl;
		int Size =Players.size();
		for (int i = 0; i < Size; i++)
		{
			File << Players[i]->PlayerID <<tab
                 << Players[i]->FirstNameOfPlayer<<tab
                 << Players[i]->LastNameOfPlayer<<tab
                 << Players[i]->Age <<tab
                 << Players[i]->Country <<tab
                 << Players[i]->Position <<tab
                 << Players[i]->Salary <<tab;
                 if(Players[i]->TeamName!=NULL)
                    File << Players[i]->TeamName->TeamID<<endl;
                 else
                    File << "-1"<<endl;
		}
		File.close();
		return true;
	}
	else
	{
		return false;
	}
}
bool Database::SaveStadium(string StadiumFile)
{
    ofstream File;
	File.open(StadiumFile.c_str());
	string tab="    ";
	if(File.is_open())
	{
	    File <<"Id     Name    Capacity    Location   Year    Team  "<<endl;
		int Size =Stadiums.size();
		for (int i = 0; i < Size; i++)
		{
			File << Stadiums[i]->StadiumID <<tab
                 << Stadiums[i]->StadiumName << tab
                 << Stadiums[i]->Capacity << tab
                 << Stadiums[i]->Location<<tab
                 << Stadiums[i]->YearOfBuild<<tab;
                 if(Stadiums[i]->TeamName!=NULL)
                    File << Stadiums[i]->TeamName->TeamID<<endl;
                 else
                    File << "-1"<<endl;
		}
		File.close();
		return true;
	}
	else
	{
		return false;
	}
}
bool Database::SaveOwner(string OwnerFile)
{
    ofstream File;
	File.open(OwnerFile.c_str());
	string tab="    ";
	if(File.is_open())
	{
	    File <<"Id     Name    Surname   Team"<<endl;
		int Size =Owners.size();
		for (int i = 0; i < Size; i++)
		{
			File << Owners[i]->OwnerID <<tab
                 << Owners[i]->FirstNameOfOwner << tab
                 << Owners[i]->LastNameOfOwner<<tab;
                 if(Owners[i]->TeamName!=NULL)
                    File << Owners[i]->TeamName->TeamID<<endl; //team
                 else
                    File << "-1"<<endl;
		}
		File.close();
		return true;
	}
	else
	{
		return false;
	}
}
bool Database::SaveManager(string ManagerFile)
{
    ofstream File;
	File.open(ManagerFile.c_str());
	string tab="    ";
	if(File.is_open())
	{
	    File <<"Id     Name    Surname    Age   Country    Tactic    Salary   Team"<<endl;
		int Size =Managers.size();
		for (int i = 0; i < Size; i++)
		{
			File << Managers[i]->ManagerID <<tab
                 << Managers[i]->FirstName << tab
                 << Managers[i]->LastName<<tab
                 << Managers[i]->Age <<tab
                 << Managers[i]->Country <<tab
                 << Managers[i]->Salary <<tab;
                 if(Managers[i]->TeamName!=NULL)
                    File << Managers[i]->TeamName->TeamID<<endl;
                 else
                    File << "-1"<<endl;
		}
		File.close();
		return true;
	}
	else
	{
		return false;
	}
}
bool Database::SaveMatch(string MatchFile)
{
    ofstream File;
	File.open(MatchFile.c_str());
	string tab="    ";
	if(File.is_open())
	{
	    File <<"Id     Day    Month    Year   Home    Away    HomeScore   AwayScore Stadium"<<endl;
		int Size =Matches.size();
		for (int i = 0; i < Size; i++)
		{
			File << Matches[i]->MatchID <<tab
                 << Matches[i]->DateOfMatch.Day <<tab
                 << Matches[i]->DateOfMatch.Month<<tab
                 << Matches[i]->DateOfMatch.Year <<tab;
                 if(Matches[i]->HomeAwayTeam.size()==2)
                 {
                     File << Matches[i]->HomeAwayTeam[0]->TeamID <<tab
                          << Matches[i]->HomeAwayTeam[1]->TeamID <<tab;
                 }
                 else
                 {
                     File << "-1"<<tab
                          << "-1"<<tab;
                 }
            File << Matches[i]->HomeScore <<tab
                 << Matches[i]->AwayScore <<tab
                 << Matches[i]->StadiumName->StadiumID<<endl;
		}
		File.close();
		return true;
	}
	else
	{
		return false;
	}
}




Team* Database::FindClub(int id)
{
    Team* team=NULL;
    int Size=Teams.size();
    for (int i = 0; i < Size; i++)
	{
		if(id == Teams[i]->TeamID)
		{
			team = Teams[i];
			break;
		}
	}
    return team;
}
Player* Database::FindPlayer(int id)
{
    Player* player=NULL;
    int Size=Players.size();
    for (int i = 0; i < Size; i++)
	{
		if(id == Players[i]->PlayerID)
		{
			player = Players[i];
			break;
		}

	}
	return player;
}
Manager* Database::FindManager(int id)
{
    Manager* manager=NULL;
    int Size=Managers.size();
    for (int i = 0; i < Size; i++)
	{
		if(id == Managers[i]->ManagerID)
		{
			manager = Managers[i];
			break;
		}
	}
	return manager;
}
Owner* Database::FindOwner(int id)
{
    Owner* owner=NULL;
    int Size=Owners.size();
    for (int i = 0; i < Size; i++)
	{
		if(id == Owners[i]->OwnerID)
		{
			owner = Owners[i];
			break;
		}
	}
	return owner;
}
Stadium* Database::FindStadium(int id)
{
    Stadium* stadium=NULL;
    int Size=Stadiums.size();
    for (int i = 0; i < Size; i++)
	{
		if(id == Stadiums[i]->StadiumID)
		{
			stadium = Stadiums[i];
			break;
		}
	}
	return stadium;
}
Match* Database::FindMatch(int id)
{
	Match *match = NULL;
	int Size = Matches.size();
	for (int i = 0; i < Size; i++)
	{
		if(id == Matches[i]->MatchID)
		{
			match = Matches[i];
			break;
		}

	}
	return match;
}



void Database::MatchesForTS()
{
    int Size=Matchesid.size();

    for(int i=0;i<Size;i++)
    {
        int matchid=Matchesid[i];
        int hteamid=HomeTeamid[i];
        int ateamid=AwayTeamid[i];
        int stadiumid=StadiumidForMatch[i];

        Match* match=FindMatch(matchid);
        Team* hteam=FindClub(hteamid);
        Team* ateam=FindClub(ateamid);
        Stadium* stadium=FindStadium(stadiumid);


        if(hteam!=NULL)
        {
            match->HomeAwayTeam.push_back(hteam);
            hteam->Matches.push_back(match);
        }
        if(ateam!=NULL)
        {
            match->HomeAwayTeam.push_back(ateam);
            ateam->Matches.push_back(match);
        }
        if(stadium!=NULL)
        {
            match->StadiumName=stadium;
            stadium->Matches.push_back(match);
        }
    }
}
void Database::MOSOfTeams()
{
    int Size=TeamForMOS.size();

    for(int i=0;i<Size;i++)
    {
        int teamid=TeamForMOS[i];
        int managerid=Managersid[i];
        int stadiumid=Stadiumsid[i];
        int ownerid=Ownersid[i];

        Team* team=FindClub(teamid);
        Manager* manager=FindManager(managerid);
        Owner* owner=FindOwner(ownerid);
        Stadium* stadium=FindStadium(stadiumid);

        if(manager!=NULL)
        {
            manager->TeamName = team;
            team->ManagerID = manager;
        }
        if(owner!=NULL)
        {
            owner->TeamName = team;
            team->OwnerID = owner;
        }
        if(stadium!=NULL)
        {
            stadium->TeamName = team;
            team->StadiumName = stadium;
        }
    }
}
void Database::PlayerOfTeams()
{
    int Size =Playersid.size();

    for(int i=0;i<Size;i++)
    {
        int teamid=TeamForPlayers[i];
        int playerid=Playersid[i];

        Team* team=FindClub(teamid);
        Player* player=FindPlayer(playerid);

        if(team!=NULL)
        {
            player->TeamName = team;
            team->Players.push_back(player);
        }
    }
}
