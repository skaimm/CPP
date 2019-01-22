#include "Interface.h"

Interface::Interface(Database *Datum, Fifa *Administration)
{
    database=Datum;
    Admin=Administration;
}

Interface::~Interface()
{
    //dtor
}

void Interface::Start()
{
	while(true)
	{
		MainMenu();
		string Operation;
		cin >> Operation;
		system("CLS");

		if(Operation=="1")
        {
            ListMatch();
        }
		if(Operation=="2")
		{
		    ListClub();
		}
		if(Operation=="3")
		{
		    ListPlayer();
		}
        if(Operation=="4")
		{
            ListManager();
		}
        if(Operation=="5")
		{
            ListOwner();
		}
        if(Operation=="6")
		{
            ListStadium();
		}
        if(Operation=="7")
		{
		    database->Save();
		}
        if(Operation=="0")
		{
            exit(0);
			break;
		}
		system("CLS");
	}
}
void Interface:: MainMenu()
{
    cout<< "1 - Fixture " << endl
        << "2 - Clubs" << endl
		<< "3 - Players" << endl
		<< "4 - Managers" << endl
		<< "5 - Chairmans" << endl
		<< "6 - Stadiums" <<endl
		<< "7 - Save"<<endl
		<< "0 - Exit" <<endl
		<< "Please Choose A Number : ";
}


void Interface::ListClub()
{

        ShowClubs(database->Teams);
        cout<<"-------------------------"<<endl;
        cout <<"1 - Create New Team" << endl;
		cout <<"2 - Delete Team" << endl;
		cout <<"3 - Show Information of A Team" <<endl;
		cout <<"0 - Back" << endl;

		string Operation;
        cout << "Your Option : ";

    while(true)
    {
        cin >> Operation;
		if( Operation == "1")
		{
		    AddClub();
			break;
		}
		else if( Operation == "2")
		{
		    if(database->Teams.size()>0)
		    DeleteClub();
			break;
		}
		else if( Operation == "3")
		{
		    ShowClubs(database->Teams);
		    cout<<"-------------------------"<<endl;
		    FindClub();
			break;
		}
		else if(Operation == "0")
        {
            break;
        }
        else
        {
            cout<<endl<<"Please Enter VALID Option : ";
        }

    }
}
void Interface::ListPlayer()
{

        ShowPlayers(database->Players);
        cout<<"-------------------------"<<endl;
        cout <<"1 - Create New Player" << endl;
		cout <<"2 - Delete Player" << endl;
		cout <<"3 - Show Information of A Player" <<endl;
		cout <<"0 - Back" << endl;

		string Operation;
        cout << "Your Option : ";

    while(true)
    {
		cin >> Operation;
		if (Operation == "0")
		{
			break;
		}
		else if( Operation == "1")
		{
		    AddPlayer();
			break;
		}
		else if( Operation == "2")
		{
		    if(database->Players.size()>0)
		    DeletePlayer();
			break;
		}
		else if( Operation == "3")
		{
		    ShowPlayers(database->Players);
		    cout<<"-------------------------"<<endl;
		    FindPlayer();
			break;
		}
		else
        {
            cout<<endl<<"Please Enter VALID Option : ";
        }

    }

}
void Interface::ListManager()
{
        ShowManagers(database->Managers);
        cout<<"-------------------------"<<endl;
        cout <<"1 - Create New Manager" << endl;
		cout <<"2 - Delete Manager" << endl;
		cout <<"3 - Show Information of A Manager" <<endl;
		cout <<"0 - Back" << endl;

		string Operation;
        cout << "Your Option : ";

    while(true)
    {
        cin >> Operation;
		if (Operation == "0")
		{
		    break;
		}
		else if( Operation == "1")
		{
		    AddManager();
			break;
		}
		else if( Operation == "2")
		{
		    if(database->Managers.size()>0)
		    DeleteManager();
			break;
		}
		else if( Operation == "3")
		{
		    ShowManagers(database->Managers);
		    cout<<"-------------------------"<<endl;
		    FindManager();
			break;
		}
		else
        {
            cout<<endl<<"Please Enter VALID Option : ";
        }
    }
}
void Interface::ListOwner()
{
        ShowOwners(database->Owners);
        cout<<"-------------------------"<<endl;
        cout <<"1 - Create New Owner" << endl;
		cout <<"2 - Delete Owner" << endl;
		cout <<"3 - Show Information of An Owner" <<endl;
		cout <<"0 - Back" << endl;

		string Operation;
        cout << "Your Option : ";

    while(true)
    {
        cin >> Operation;
		if (Operation == "0")
		{
		    break;
		}
		else if( Operation == "1")
		{
		    AddOwner();
			break;
		}
		else if( Operation == "2")
		{
		    if(database->Owners.size()>0)
		    DeleteOwner();
			break;
		}
		else if( Operation == "3")
		{
		    ShowOwners(database->Owners);
		    cout<<"-------------------------"<<endl;
		    FindOwner();
			break;
		}
		else
        {
            cout<<endl<<"Please Enter VALID Option : ";
        }
    }

}
void Interface::ListStadium()
{
        ShowStadiums(database->Stadiums);
        cout<<"-------------------------"<<endl;
        cout <<"1 - Create New Stadium" << endl;
		cout <<"2 - Delete Stadium" << endl;
		cout <<"3 - Show Information of A Stadium" <<endl;
		cout <<"0 - Back" << endl;

		string Operation;
        cout << "Your Option : ";

    while(true)
    {
        cin >> Operation;
		if (Operation == "0")
		{
		    break;
		}
		else if( Operation == "1")
		{
		    AddStadium();
			break;
		}
		else if( Operation == "2")
		{
		    if(database->Stadiums.size()>0)
		    DeleteStadium();
			break;
		}
		else if( Operation == "3")
		{
		    ShowStadiums(database->Stadiums);
		    cout<<"-------------------------"<<endl;
		    FindStadium();
			break;
		}
		else
        {
            cout<<endl<<"Please Enter VALID Option : ";
        }
    }

}
void Interface::ListMatch()
{
        ShowMatches(database->Matches);
        cout<<"-----------------------------------"<<endl;
        cout <<"1 - Create New Match" << endl;
		cout <<"2 - Delete Match" << endl;
		cout <<"3 - Show Information of A Match" <<endl;
		cout <<"0 - Back" << endl;

		string Operation;
        cout << "Your Option : ";

    while(true)
    {
        cin >> Operation;
		if( Operation == "1")
		{
		    AddMatch();
			break;
		}
		else if( Operation == "2")
		{
		    if(database->Matches.size()>0)
		    DeleteMatch();
			break;
		}
		else if( Operation == "3")
		{
		    ShowMatches(database->Matches);
		    cout<<"-----------------------------------"<<endl;
		    FindMatch();
			break;
		}
		else if( Operation== "0")
        {
            break;
        }
        else
        {
            cout<<endl<<"Please Enter VALID Option : ";
        }
    }
}


void Interface::AddClub()
{   system("CLS");
    cout << "Create A New Team"<<endl;

	Team *NewTeam = new Team();
    NewTeam->TeamID=database->Teams.size()+100;
	cout<<"Team Name              : ";
    cin>>NewTeam->TeamName;
    cout<<"xxxx Just Enter Year "<<endl;
    cout<<"Year Of Establishment  : ";
    cin>>NewTeam->YearOfEstablishment;
    cout<<"Championship           : ";
    cin>>NewTeam->NumberOfTrophies;

    Admin->NewCreateClub(NewTeam);
	EditClub(NewTeam);
}
void Interface::AddPlayer()
{   system("CLS");
    cout << "Create A New Player"<<endl;

	Player* NewPlayer = new Player();
	NewPlayer->PlayerID=database->Players.size()+100;
	cout<<"Name     : ";
    cin>>NewPlayer->FirstNameOfPlayer;
    cout<<"Surname  : ";
    cin>>NewPlayer->LastNameOfPlayer;
    cout<<"Age      : ";
    cin>>NewPlayer->Age;
    cout<<"Country  : ";
    cin>>NewPlayer->Country;
    cout<<"Forward,Middle,Defense or Goalkeeper" <<endl;
    cout<<"Position : ";
    cin>>NewPlayer->Position;
    cout<<"x xxx 000 £ you will enter 'x' "<<endl;
    cout<<"Salary   : ";
    cin>>NewPlayer->Salary;

    Admin->NewCreatePlayer(NewPlayer);
	EditPlayer(NewPlayer);
}
void Interface::AddManager()
{   system("CLS");
    cout << "Create A New Manager"<<endl;

	Manager* NewManager = new Manager();
	NewManager->ManagerID=database->Managers.size()+100;

	cout<<"Name     : ";
    cin>>NewManager->FirstName;
    cout<<"Surname  : ";
    cin>>NewManager->LastName;
    cout<<"Age      : ";
    cin>>NewManager->Age;
    cout<<"Country  : ";
    cin>>NewManager->Country;
    cout<<"x xxx 000 £ you will enter 'x' "<<endl;
    cout<<"Salary   : ";
    cin>>NewManager->Salary;

    Admin->NewCreateManager(NewManager);
	EditManager(NewManager);
}
void Interface::AddOwner()
{   system("CLS");
    cout << "Create A New Owner"<<endl;

	Owner* NewOwner = new Owner();
    NewOwner->OwnerID=database->Owners.size()+100;
	cout<<"Name     : ";
    cin>>NewOwner->FirstNameOfOwner;
    cout<<"Surname  : ";
    cin>>NewOwner->LastNameOfOwner;

    Admin->NewCreateOwner(NewOwner);
    EditOwner(NewOwner);
}
void Interface::AddStadium()
{   system("CLS");
    cout << "Create A New Stadium"<<endl;

	Stadium* NewStadium = new Stadium();
    NewStadium->StadiumID=database->Stadiums.size()+100;
	cout<<"Name                : ";
    cin>>NewStadium->StadiumName;
    cout<<"xxxx Just Enter Year "<<endl;
    cout<<"Establishment Year  : ";
    cin>>NewStadium->YearOfBuild;
    cout<<"Location            : ";
    cin>>NewStadium->Location;
    cout<<"DONT use \".\" or \",\" "<<endl;
    cout<<"Capacity            : ";
    cin>>NewStadium->Capacity;

    Admin->NewCreateStadium(NewStadium);
	EditStadium(NewStadium);
}
void Interface::AddMatch()
{   system("CLS");
    cout << "Create A New Match"<<endl;

    Match *NewMatch = new Match();

    NewMatch->MatchID=database->Matches.size()+100;
    cout<<" Like 10.09.2017 (day).(month).(year)"<<endl;
    cout<<"Day Of Match   : ";
    cin>>NewMatch->DateOfMatch.Day;
    cout<<"Month Of Match : ";
    cin>>NewMatch->DateOfMatch.Month;
    cout<<"Year Of Match  : ";
    cin>>NewMatch->DateOfMatch.Year;

    Admin->NewCreateMatch(NewMatch);
	EditMatch(NewMatch);
}



void Interface::DeleteClub()
{   system("CLS");
    ShowClubs(database->Teams);
    cout << "--------------------------------------" << endl;
    cout << "If you want to Back, Please Enter \"0\" "<<endl;
    cout << "Please Enter Team ID to Delete : ";

	int id;
    while(true)
    {
        cin>> id;

        if(id==0)
        {
            break;
        }
        else
        {
            if( Admin->DeleteClub(id) == false )
            {
                cout << "Wrong ID"<< endl;
            }
            else
            {
                cout << "Successfully deleted" <<endl;
            }
        }
    }
}
void Interface::DeletePlayer()
{   system("CLS");
    ShowPlayers(database->Players);
    cout << "---------------------------------------" << endl;
    cout << "If you want to Back, Please Enter \"0\""<<endl;
    cout << "Please Enter Player ID to Delete : ";

	int id;
	while(true)
    {
        cin>> id;

        if(id==0)
        {
            break;
        }
        else
        {
            if( Admin->DeletePlayer(id) == false )
            {
                cout << "Wrong ID"<< endl;
            }
            else
            {
                cout << "Successfully deleted" <<endl;
            }
        }
    }
}
void Interface::DeleteManager()
{   system("CLS");
    ShowManagers(database->Managers);
    cout << "---------------------------------------" << endl;
    cout << "If you want to Back, Please Enter \"0\""<<endl;
    cout << "Please Enter Manager ID to Delete : ";
	int id;
	while(true)
    {
        cin>> id;

        if(id==0)
        {
            break;
        }
        else
        {
            if( Admin->DeleteManager(id) == false )
                cout << "Wrong ID"<< endl;
            else
            {
                cout << "Successfully deleted" <<endl;
            }
        }
    }
}
void Interface::DeleteOwner()
{   system("CLS");
    ShowOwners(database->Owners);
    cout << "---------------------------------------" << endl;
    cout << "If you want to Back, Please Enter \"0\""<<endl;
    cout << "Please Enter Owner ID to Delete : ";
    int id;
    while(true)
    {
        cin>> id;

        if(id==0)
        {
            break;
        }
        else
        {
            if( Admin->DeleteOwner(id) == false )
                cout << "Wrong ID"<< endl;
            else
            {
                cout << "Successfully deleted" <<endl;
            }
        }
    }
}
void Interface::DeleteStadium()
{   system("CLS");
    ShowStadiums(database->Stadiums);
    cout << "---------------------------------------" << endl;
    cout << "If you want to Back, Please Enter \"0\""<<endl;
    cout << "Please Enter Stadium ID to Delete : ";

	while(true)
    {
        int id;
        cin>> id;

        if(id==0)
        {
            break;
        }
        else
        {
            if( Admin->DeleteStadium(id) == false )
            {
                cout << "Wrong ID"<< endl;
            }
            else
            {
                cout << "Successfully deleted" <<endl;
            }
        }

    }


}
void Interface::DeleteMatch()
{   system("CLS");
    ShowMatches(database->Matches);
    cout << "--------------------------------------" << endl;
    cout << "If you want to Back, Please Enter \"0\" "<<endl;
    cout << "Please Enter Match ID to Delete : ";
	int id;
    while(true)
    {
        cin>> id;

        if(id==0)
        {
            break;
        }
        else
        {
            if( Admin->DeleteMatch(id) == false )
                cout << "Wrong ID"<< endl;
            else
            {
                cout << "Successfully deleted" <<endl;
            }
        }
    }
}






void Interface::ShowClubs(vector<Team*> &List)
{   system("CLS");
    cout<<"ID  | NAME             "<<endl;
    cout<<"-------------------------"<<endl;
	int Size = List.size();

	for (int i = 0; i < Size; i++)
	{
		cout << List[i]->TeamID << " | "
             << List[i]->TeamName << endl;
	}
	if(Size < 1)
	{
		cout <<"There is No Data" << endl;
	}
}
void Interface::ShowPlayers(vector<Player*> &List)
{   system("CLS");
    cout<<"ID  | NAME SURNAME       "<<endl;
    cout<<"-------------------------"<<endl;
	int Size = List.size();

	for (int i = 0; i < Size; i++)
	{
		cout << List[i]->PlayerID << " | "
			 << List[i]->FirstNameOfPlayer<<" "
			 << List[i]->LastNameOfPlayer
			 << endl;
	}
	if(Size < 1)
	{
		cout <<"There is No Data" << endl;
	}
}
void Interface::ShowManagers(vector<Manager*> &List)
{   system("CLS");
    cout<<"ID  | NAME SURNAME       "<<endl;
    cout<<"-------------------------"<<endl;
	int Size = List.size();

	for (int i = 0; i < Size; i++)
	{
		cout << List[i]->ManagerID << " | "
			 << List[i]->FirstName<<" "
			 << List[i]->LastName
			 << endl;
	}
	if(Size < 1)
	{
		cout <<"There is No Data" << endl;
	}
}
void Interface::ShowOwners(vector<Owner*> &List)
{   system("CLS");
    cout<<"ID  | NAME SURNAME       "<<endl;
    cout<<"-------------------------"<<endl;
	int Size = List.size();

	for (int i = 0; i < Size; i++)
	{
		cout << List[i]->OwnerID << " | "
			 << List[i]->FirstNameOfOwner<<" "
			 << List[i]->LastNameOfOwner
			 << endl;
	}
	if(Size < 1)
	{
		cout <<"There is No Data" << endl;
	}
}
void Interface::ShowStadiums(vector<Stadium*> &List)
{   system("CLS");
    cout<<"ID  | NAME               "<<endl;
    cout<<"-------------------------"<<endl;
	int Size = List.size();

	for (int i = 0; i < Size; i++)
	{
		cout << List[i]->StadiumID << " | "
			 << List[i]->StadiumName<< endl;
	}
	if(Size < 1)
	{
		cout <<"There is No Data" << endl;
	}
}
void Interface::ShowMatches(vector<Match*> &List)
{   system("CLS");
    cout<<"ID  | TEAMS                      | SCORE "<<endl;
    cout<<"-----------------------------------------"<<endl;
	int Size = List.size();

	for (int i = 0; i < Size; i++)
	{
		cout << List[i]->MatchID << " | ";

            int Size2 = List[i]->HomeAwayTeam.size();
            for(int j=0 ; j<Size2 ; j++)
            {
                if(List[i]->HomeAwayTeam[j]==NULL)
                {
                    cout<< List[i]->HomeAwayTeam[j];
                }
                if(List[i]->HomeAwayTeam[j]!=NULL)
                {
                    cout<< List[i]->HomeAwayTeam[j]->TeamName;
                }
                if(j<1)
                {
                    cout << " - ";
                }
            }
            cout<<"    " << List[i]->HomeScore << " - "
                << List[i]->AwayScore <<endl;
	}
	if(Size < 1)
	{
		cout <<"There is No Data" << endl;
	}
}





void Interface::FindClub()
{   system("CLS");
    ShowClubs(database->Teams);
    cout<<"-------------------------"<<endl;
    cout << "If you want to Back, Please Enter \"0\""<<endl;
    cout << "Please Enter Team ID :" <<endl;
		int TeamID = -1;
    while(true)
	{
		cin >> TeamID;

        Team *team = database->FindClub(TeamID);

		if(team!=NULL )
		{
            ShowClub(team);
            break;
        }
		else
		{
		    if(TeamID==0)
                break;
			cout<<"Wrong ID! Please Enter Correct ID : ";
		}
	}
}
void Interface::FindPlayer()
{   system("CLS");
    ShowPlayers(database->Players);
    cout<<"-------------------------"<<endl;
    cout << "If you want to Back, Please Enter \"0\""<<endl;
    cout << "Please Enter Player ID!" <<endl;
		int PlayerID = -1;
    while(true)
	{
		cin >> PlayerID;

		Player* player = database->FindPlayer(PlayerID);

        if( player != NULL )
        {
            ShowPlayer(player);
            break;
        }
        else
        {
            if(PlayerID==0)
                break;
            cout<<"Wrong ID! Please Enter Correct ID : ";
        }
	}
}
void Interface::FindManager()
{   system("CLS");
    ShowManagers(database->Managers);
    cout<<"-------------------------"<<endl;
    cout << "If you want to Back, Please Enter \"0\""<<endl;
    cout << "Please Enter Manager ID!" <<endl;
		int ManagerID = -1;
    while(true)
	{
		cin >> ManagerID;

		Manager* manager = database->FindManager(ManagerID);
        if( manager != NULL )
        {
            ShowManager(manager);
            break;
        }
        else
        {
            if(ManagerID==0)
                break;
            cout<<"Wrong ID! Please Enter Correct ID : ";
        }
	}
}
void Interface::FindOwner()
{   system("CLS");
    ShowOwners(database->Owners);
    cout<<"-------------------------"<<endl;
    cout << "If you want to Back, Please Enter \"0\""<<endl;
    cout << "Please Enter Owner ID!" <<endl;
		int OwnerID = -1;
    while(true)
	{
		cin >> OwnerID;

		Owner* owner = database->FindOwner(OwnerID);
        if( owner != NULL )
        {
            ShowOwner(owner);
            break;
        }
        else
        {
            if(OwnerID==0)
                break;
            cout<<"Wrong ID! Please Enter Correct ID : ";
        }
	}
}
void Interface::FindStadium()
{   system("CLS");
    ShowStadiums(database->Stadiums);
    cout<<"-------------------------"<<endl;
    cout << "If you want to Back, Please Enter \"0\""<<endl;
    cout << "Please Enter Stadium ID!" <<endl;
		int StadiumID = -1;
    while(true)
	{
		cin >> StadiumID;

		Stadium* stadium = database->FindStadium(StadiumID);
        if( stadium != NULL )
        {
            ShowStadium(stadium);
            break;
        }
        else
        {
            if(StadiumID==0)
                break;
            cout<<"Wrong ID! Please Enter Correct ID : ";
        }
	}
}
void Interface::FindMatch()
{   system("CLS");
    ShowMatches(database->Matches);
    cout<<"-----------------------------------"<<endl;
    cout << "If you want to Back, Please Enter \"0\""<<endl;
    cout << "Please Enter Match ID!" <<endl;
		int MatchID = -1;
    while(true)
	{
		cin >> MatchID;

		Match* match = database->FindMatch(MatchID);
        if( match != NULL )
        {
            //düzgün bir Id girilmiş demektir
            ShowMatch(match);
            break;
        }
		else
		{
		    if(MatchID==0)
                break;
			cout<<"Wrong ID! Please Enter Correct ID : ";
		}
	}

}





void Interface::ShowClub(Team* team)
{   system("CLS");
    if(team != NULL)
	{
		//bi team bulduk
		//team bilgileri listelenir
		cout<< "Id            : " << team->TeamID <<endl
            << "Team Name     : " << team->TeamName << endl
			<< "Establishment : " << team->YearOfEstablishment <<endl
			<< "Championship  : " << team->NumberOfTrophies <<endl;
			if(team->StadiumName==NULL)
                cout << "Stadium       : " << team->StadiumName<<endl;
            if(team->StadiumName!=NULL)
                cout << "Stadium       : " << team->StadiumName->StadiumName<<endl;
            if(team->ManagerID==NULL)
                cout<< "Manager       : " << team->ManagerID <<endl;
            if(team->ManagerID!=NULL)
                cout<< "Manager       : " << team->ManagerID->FirstName <<" "<< team->ManagerID->LastName <<endl;
            if(team->OwnerID==NULL)
                cout<< "Owner         : " << team->OwnerID <<endl;
            if(team->OwnerID!=NULL)
                cout<< "Owner         : " << team->OwnerID->FirstNameOfOwner <<" "<< team->OwnerID->LastNameOfOwner <<endl;
            cout<< "-------------------------------------------"<<endl;
		while(true)
		{
			//komutlar listelenir
			cout<< "1 - Show Players Of "<<team->TeamName << endl
                << "2 - Edit "<<team->TeamName << endl
                << "0 - Back " << endl;

			string Operation;
			cin>>Operation;

			if(Operation == "0")
			{   system("CLS");
				//ana iþlemler ekranýna gidiþ mekanizmasý tetiklenir
				break;
			}
			else if(Operation == "1")
			{   system("CLS");
				cout << "Players OF " <<team->TeamName <<endl;
				ShowPlayers(team->Players);
			}
			else if(Operation == "2")
			{   system("CLS");
				cout << "EDIT " <<team->TeamName <<endl;
				EditClub(team);
			}
			else
            {
            }
		}
	}
}
void Interface::ShowPlayer(Player* player)
{   system("CLS");
    if(player != NULL)
	{
		//bi player bulduk
		//player bilgileri listelenir
		cout<< "Id            : " << player->PlayerID <<endl
            << "Name          : " << player->FirstNameOfPlayer << endl
			<< "Surname       : " << player->LastNameOfPlayer<<endl
			<< "Age           : " << player->Age <<endl;
			if(player->TeamName==NULL)
			cout<< "Team          : " << player->TeamName<<endl;
			if(player->TeamName!=NULL)
            cout<< "Team          : " << player->TeamName->TeamName<<endl;
        cout<< "Country       : " << player->Country <<endl
            << "Position      : " << player->Position <<endl
            << "Salary        : " << player->Salary <<endl
            << "-------------------------------------------"<<endl;

        while(true)
		{
			//komutlar listelenir
			cout<< "1 - Edit " <<player->FirstNameOfPlayer <<"  "<<player->LastNameOfPlayer << endl
                << "0 - Back " << endl;

			string Operation;
			cin>>Operation;

			if(Operation == "0")
			{   system("CLS");
				//ana iþlemler ekranýna gidiþ mekanizmasý tetiklenir
				break;
			}
			else if(Operation == "1")
			{   system("CLS");
			    cout<<" EDIT " <<player->FirstNameOfPlayer <<"  "<<player->LastNameOfPlayer<<endl;
				EditPlayer(player);
			}
			else
            {
            }
		}
	}
}
void Interface::ShowManager(Manager* manager)
{   system("CLS");
    if(manager != NULL)
	{
		//bi manager bulduk
		//manager bilgileri listelenir
		cout<< "Id            : " << manager->ManagerID <<endl
            << "Name          : " << manager->FirstName << endl
			<< "Surname       : " << manager->LastName<<endl
			<< "Age           : " << manager->Age <<endl;
			if(manager->TeamName==NULL)
            cout<< "Team          : " << manager->TeamName<<endl;
			if(manager->TeamName!=NULL)
			cout<< "Team          : " << manager->TeamName->TeamName<<endl;
        cout<< "Country       : " << manager->Country <<endl
            << "Salary        : " << manager->Salary <<endl
            << "-------------------------------------------"<<endl;
        while(true)
		{
			//komutlar listelenir
			cout<< "1 - Edit " <<manager->FirstName <<"  "<<manager->LastName<<endl
                << "0 - Back " << endl;

			string Operation;
			cin>>Operation;

			if(Operation == "0")
			{   system("CLS");
				//ana iþlemler ekranýna gidiþ mekanizmasý tetiklenir
				break;
			}
			else if(Operation == "1")
			{   system("CLS");
			    cout<<" EDIT " <<manager->FirstName <<"  "<<manager->LastName<<endl;
				EditManager(manager);
			}
			else
            {
            }
		}
	}
}
void Interface::ShowOwner(Owner* owner)
{   system("CLS");
    if(owner != NULL)
	{
		//bi owner bulduk
		//owner bilgileri listelenir
		cout<< "Id            : " << owner->OwnerID <<endl
            << "Name          : " << owner->FirstNameOfOwner << endl
			<< "Surname       : " << owner->LastNameOfOwner<<endl;
			if(owner->TeamName!=NULL)
			cout<< "Team          : " << owner->TeamName->TeamName<<endl;
			if(owner->TeamName==NULL)
            cout<< "Team          : " << owner->TeamName<<endl;
        cout<< "-------------------------------------------"<<endl;

			//komutlar listelenir
			cout<< "1 - Edit " <<owner->FirstNameOfOwner <<"  "<<owner->LastNameOfOwner<<endl
                << "0 - Back " << endl;
        while(true)
		{
			string Operation;
			cin>>Operation;

			if(Operation == "0")
			{   system("CLS");
				break;
			}
			else if(Operation == "1")
			{   system("CLS");
			    cout<<" EDIT " <<owner->FirstNameOfOwner <<"  "<<owner->LastNameOfOwner<<endl;
				EditOwner(owner);
			}
			else
            {
            }
		}
	}
}
void Interface::ShowStadium(Stadium* stadium)
{   system("CLS");
    if(stadium != NULL)
	{
		//bi stadium bulduk
		//stadium bilgileri listelenir
		cout<< "Id            : " << stadium->StadiumID <<endl
            << "Name          : " << stadium->StadiumName << endl;
            if(stadium->TeamName!=NULL)
                cout<< "Owner         : " << stadium->TeamName->TeamName<<endl;
			if(stadium->TeamName==NULL)
                cout<< "Owner         : " << stadium->TeamName<<endl;
        cout<< "Location      : " << stadium->Location<<endl
			<< "Establishment : " << stadium->YearOfBuild<<endl
			<< "-------------------------------------------"<<endl;
        while(true)
		{
			//komutlar listelenir
			cout<< "1 - Edit " <<stadium->StadiumName << endl
                << "0 - Back " << endl;

			string Operation;
			cin>>Operation;

			if(Operation == "0")
			{   system("CLS");
				break;
			}
			else if(Operation == "1")
			{   system("CLS");
				cout << "EDIT " <<stadium->StadiumName <<endl;
				EditStadium(stadium);
			}
			else{}
        }
	}
}
void Interface::ShowMatch(Match* match)
{   system("CLS");
    if(match != NULL)
	{
		//bi match bulduk
		//match bilgileri listelenir
		cout<< "Id            : " << match->MatchID <<endl
            << match->DateOfMatch.Day <<"."
            << match->DateOfMatch.Month <<"."
            << match->DateOfMatch.Year <<endl;
            if(match->HomeAwayTeam[0]==NULL)
                cout<< "No Team ";
            if(match->HomeAwayTeam[0]!=NULL)
                cout<< match->HomeAwayTeam[0]->TeamName;
            cout << " - ";
            if(match->HomeAwayTeam[1]==NULL)
                cout<< "No Team ";
            if(match->HomeAwayTeam[1]!=NULL)
                cout<< match->HomeAwayTeam[1]->TeamName<<"    ";

            cout<< match->HomeScore << " - "
                << match->AwayScore <<endl;
                cout<< "Stadium : ";
            if(match->StadiumName==NULL)
                cout<< match->StadiumName;
            if(match->StadiumName!=NULL)
                cout<< match->StadiumName->StadiumName;
        cout<<endl;
        cout<< "-------------------------------------------"<<endl;
        while(true)
		{
			//komutlar listelenir
			cout<< "1 - Edit Match" <<endl
                << "0 - Back " << endl;

			char Operation;
			cin>>Operation;

			if(Operation == '0')
			{   system("CLS");
				//ana işlemler ekranına gidiş mekanizması tetiklenir
				break;
			}
			else if(Operation == '1')
			{   system("CLS");
			    cout<<" EDIT MATCH" <<endl;
				EditMatch(match);
			}
			else
            {
            }
		}
	}
}


void Interface::EditClub(Team *club)
{
    while(true)
	{   system("CLS");
        cout <<"EDIT " <<club->TeamName<<endl;
		cout <<"1 - Change Information About Team" <<endl
             <<"2 - Add New Player in Team" <<endl
             <<"3 - Add New Manager in Team" <<endl
             <<"4 - Add New Owner in Team" <<endl
             <<"5 - Add New Stadium in Team" << endl
             <<"6 - Add New Matches Of Team" <<endl
             <<"7 - Remove Player in Team" << endl
             <<"8 - Remove Manager in Team" <<endl
             <<"9 - Remove Owner in Team" << endl
             <<"10- Remove Stadium in Team" <<endl
             <<"11- Remove Matches Of Team" << endl
             <<"0 - Back" <<endl;

        string Operation;
        again : cout <<"Your Option : ";
        cin >> Operation;

            if(Operation=="1")
            {
                system("CLS");
                string name;
                int year,champ;
                cout<<"Please Enter New Information About Team"<<endl;
                cout<<"If you DONT want to change, Please Enter \"0\""<<endl;
                cout<<"Change Team Name       : ";
                cin>>name;
                if(name!="0")
                    club->TeamName=name;
                cout<<"xxxx Just Enter Year "<<endl;
                cout<<"Change Year Of Establishment  : ";
                cin>>year;
                if(year!=0)
                    club->YearOfEstablishment=year;
                cout<<"Change Championship    : ";
                cin>>champ;
                if(champ!=0)
                    club->NumberOfTrophies=champ;

            }
            else if(Operation=="2")
            {
                AddPlayer();
            }
            else if(Operation=="3")
            {
                AddManager();
            }
            else if(Operation=="4")
            {
                AddOwner();
            }
            else if(Operation=="5")
            {
                AddStadium();
            }
            else if(Operation=="6")
            {
                AddMatch();
            }
            else if(Operation=="7")
            {
                while(true)
                {   system("CLS");
                    ShowPlayers(club->Players);
                    cout << "-----------------------------" <<endl;
                    cout << "If you want to Back, Please Enter \"0\""<<endl;
                    cout << "Please Enter Player ID : ";
                    int playerid;
                    cin >> playerid;
                    Player* player=database->FindPlayer(playerid);
                    if(player!=NULL)
                    {
                        Admin->PlayerRemovetoTeam(player,club);
                        cout <<"Succesfully Removed"<<endl;
                    }
                    else if(playerid==0)
                    {
                        break;
                    }
                }
            }
            else if(Operation=="8")
            {
                if(club->ManagerID!=NULL)
                {
                    int managerid=club->ManagerID->ManagerID;
                    Manager *manager=database->FindManager(managerid);
                    Admin->ManagerRemovetoTeam(manager,club);
                    cout <<"Succesfully Removed"<<endl;
                    goto again;
                }
            }
            else if(Operation=="9")
            {
                if(club->OwnerID!=NULL)
                {
                    int ownerid=club->OwnerID->OwnerID;
                    Owner *owner=database->FindOwner(ownerid);
                    Admin->OwnerRemovetoTeam(owner,club);
                    cout <<"Succesfully Removed"<<endl;
                    goto again;
                }
            }
            else if(Operation=="10")
            {
                if(club->StadiumName!=NULL)
                {
                    int stadiumid=club->StadiumName->StadiumID;
                    Stadium *stadium=database->FindStadium(stadiumid);
                    Admin->StadiumRemovetoTeam(stadium,club);
                    cout <<"Succesfully Removed"<<endl;
                    goto again;
                }
            }
            else if(Operation=="11")
            {
                while(true)
                {   system("CLS");
                    ShowMatches(club->Matches);
                    cout << "-----------------------------" <<endl;
                    cout << "If you want to Back, Please Enter \"0\""<<endl;
                    cout << "Please Enter Match ID : ";
                    int matchid;
                    cin >> matchid;
                    Match* match=database->FindMatch(matchid);
                    if(match!=NULL)
                    {
                        Admin->DeleteMatch(matchid);
                        cout <<"Succesfully Removed"<<endl;
                    }
                    else if(matchid==0)
                    {
                        break;
                    }
                }
            }
            else if(Operation=="0")
            {
                break;
            }
            else
            {

            }
    }
}
void Interface::EditPlayer(Player* player)
{
    while(true)
    {   system("CLS");
        cout << "1 - Change Information About Player"<<endl
             << "2 - Assigment to " << player->FirstNameOfPlayer <<endl
             << "3 - Remove " <<player->FirstNameOfPlayer <<" From Team " <<endl
             << "0 - Back " << endl
             << "Please Enter Your Choose : " << endl;
        string Operation;
        again : cin >>Operation;
        if(Operation=="0")
        {
            system("CLS");
            break;
        }
        else if(Operation=="1")
        {
            int age,salary;
            string name,surname,country,pos;
            cout<<"Please Enter New Information About Player"<<endl;
            cout<<"If you DONT want to change, Please Enter \"0\""<<endl;

            cout<<"Change Name     : ";
            cin>>name;
            if(name!="0")
                player->FirstNameOfPlayer=name;
            cout<<"Change Surname  : ";
            cin>>surname;
            if(surname!="0")
                player->LastNameOfPlayer=surname;
            cout<<"Change Age      : ";
            cin>>age;
            if(age!=0)
                player->Age=age;
            cout<<"Change Country  : ";
            cin>>country;
            if(country!="0")
                player->Country=country;
            cout<<"Forward,Middle,Defense or Goalkeeper" <<endl;
            cout<<"Change Position : ";
            cin>>pos;
            if(pos!="0")
                player->Position=pos;
            cout<<"x xxx 000 £ you will enter 'x' "<<endl;
            cout<<"Change Salary   : ";
            cin>>salary;
            if(salary!=0)
                player->Salary=salary;
        }
        else if(Operation=="2")
        {   system("CLS");
            ShowClubs(database->Teams);
            cout << "-------------------------"<<endl;
            cout << "If you want to Back, Please Enter \"0\""<<endl
                 << "Enter Team ID : ";
                int teamid;
                cin >> teamid;
                Team* team;
                team=database->FindClub(teamid);
                if(team!=NULL)
                {
                    Admin->PlayerTransfertoTeam(player,team);
                    cout <<"Succesfully Added"<<endl;
                }
                else if(teamid==0)
                {
                    break;
                }
                else
                {
                    cout <<"Wrong ID"<<endl;
                }
        }
        else if(Operation=="3")
        {
            if(player->TeamName!=NULL)
            {
                int clubid=player->TeamName->TeamID;
                Team *team=database->FindClub(clubid);
                Admin->PlayerRemovetoTeam(player,team);
                cout <<"Succesfully Removed"<<endl;
                goto again;
            }
        }
        else{}
    }
}
void Interface::EditManager(Manager* manager)
{
    while(true)
    {   system("CLS");
        cout << "1 - Change Information About Manager"<<endl
             << "2 - Assigment to " << manager->FirstName <<endl
             << "3 - Remove " << manager->FirstName <<" From Team " <<endl
             << "0 - Back " << endl
             << "Please Enter Your Choose : ";
        again : string Operation;
        cin >>Operation;
        if(Operation=="0")
        {   system("CLS");
            break;
        }
        else if(Operation=="1")
        {
            int age,salary;
            string name,surname,country;

            cout<<"Please Enter New Information About Team"<<endl;
            cout<<"If you DONT want to change, Please Enter \"0\""<<endl;

            	cout<<"Change Name     : ";
                cin>>name;
                if(name!="0")
                    manager->FirstName=name;
                cout<<"Change Surname  : ";
                cin>>surname;
                 if(surname!="0")
                    manager->LastName=surname;
                cout<<"Change Age      : ";
                cin>>age;
                 if(age!=0)
                    manager->Age=age;
                cout<<"Change Country  : ";
                cin>>country;
                 if(country!="0")
                    manager->Country=country;
                cout<<"x xxx 000 £ you will enter 'x' "<<endl;
                cout<<"Change Salary   : ";
                cin>>salary;
                 if(salary!=0)
                    manager->Salary=salary;
        }
        else if(Operation=="2")
        {   system("CLS");
            ShowClubs(database->Teams);
            cout << "-------------------------"<<endl
                 << "If you want to Back, Please Enter \"0\""<<endl
                 << "Enter Team ID : ";
               again2 : int teamid;
                cin >> teamid;
                Team* team;
                team=database->FindClub(teamid);
                if(team!=NULL)
                {
                    if(team->ManagerID==NULL)
                    {
                        Admin->ManagerTranfertoTeam(manager,team);
                        cout <<"Succesfully Added"<<endl;
                    }
                    else
                    {
                        cout<<"Team has A Manager. Please Firstly Remove him."<<endl;
                        goto again2;
                    }
                }
                else if(teamid==0)
                {
                    break;
                }
                else
                {
                    cout <<"Wrong ID"<<endl;
                }
        }
        else if(Operation=="3")
        {
            if(manager->TeamName!=NULL)
            {
                int clubid=manager->TeamName->TeamID;
                Team *team=database->FindClub(clubid);
                Admin->ManagerRemovetoTeam(manager,team);
                cout <<"Succesfully Removed"<<endl;
                goto again;
            }
        }
        else
        {

        }
    }
}
void Interface::EditOwner(Owner* owner)
{
    while(true)
    {
        cout << "1 - Change Information About Owner"<<endl
             << "2 - Assigment to " << owner->FirstNameOfOwner <<endl
             << "3 - Remove " << owner->FirstNameOfOwner <<" From Team " <<endl
             << "0 - Back " << endl
             << "Please Enter Your Choose : " << endl;
        string Operation;
        again : cin >>Operation;
        if(Operation=="0")
        {
            system("CLS");
            break;
        }
        else if(Operation=="1")
        {
            string name,surname;

            cout<<"Please Enter New Information About Owner"<<endl;
            cout<<"If you DONT want to change, Please Enter \"0\""<<endl;

            	cout<<"Change Name     : ";
                cin>>name;
                if(name!="0")
                    owner->FirstNameOfOwner=name;
                cout<<"Change Surname  : ";
                cin>>surname;
                 if(surname!="0")
                    owner->LastNameOfOwner=surname;
        }
        else if(Operation=="2")
        {
            system("CLS");
            ShowClubs(database->Teams);
            cout << "-------------------------"<<endl
                 << "If you want to Back, Please Enter \"0\""<<endl
                 << "Enter Team ID : ";
                again2 : int teamid;
                cin >> teamid;
                Team* team;
                team=database->FindClub(teamid);
                if(team!=NULL)
                {
                    if(team->OwnerID==NULL)
                    {
                        Admin->OwnerTranfsertoTeam(owner,team);
                        cout <<"Succesfully Added"<<endl;
                    }
                    else
                    {
                        cout<<"Team has An Owner. Please Firstly Remove him."<<endl;
                        goto again2;
                    }
                }
                else if(teamid==0)
                {
                    break;
                }
                else
                {
                    cout <<"Wrong ID";
                }
        }
        else if(Operation=="3")
        {
            if(owner->TeamName!=NULL)
            {
                int clubid=owner->TeamName->TeamID;
                Team *team=database->FindClub(clubid);
                Admin->OwnerRemovetoTeam(owner,team);
                cout <<"Succesfully Removed"<<endl;
                goto again;
            }
        }
        else{}
    }
}
void Interface::EditStadium(Stadium* stadium)
{
   while(true)
    {
        cout << "1 - Change Information About Owner"<<endl
             << "2 - Assigment " << stadium->StadiumName << "For Team" <<endl
             << "3 - Assigment " << stadium->StadiumName << "For Match" <<endl
             << "4 - Remove " << stadium->StadiumName <<" From Team " <<endl
             << "5 - Remove " << stadium->StadiumName <<" From Match " <<endl
             << "0 - Back " << endl
             << "Please Enter Your Choose : " << endl;
        string Operation;
        again: cin >>Operation;
        if(Operation=="0")
        {
            system("CLS");
            break;
        }
        else if(Operation=="1")
        {
            int year,cap;
            string name,loca;

            cout<<"Please Enter New Information About Owner"<<endl;
            cout<<"If you DONT want to change, Please Enter \"0\""<<endl;

            cout<<"Change Name                : ";
            cin>>name;
            if(name!="0")
                stadium->StadiumName=name;
            cout<<"xxxx Just Enter Year "<<endl;
            cout<<"Change Establishment Year  : ";
            cin>>year;
            if(year!=0)
                stadium->YearOfBuild=year;
            cout<<"Change Location            : ";
            cin>>loca;
            if(loca!="0")
                stadium->Location=loca;
            cout<<"DONT use \".\" or \",\" "<<endl;
            cout<<"Change Capacity            : ";
            cin>>cap;
            if(cap!=0)
                stadium->Capacity=cap;

        }
        else if(Operation=="2")
        {
            ShowClubs(database->Teams);
            cout << "-------------------------"<<endl
                 << "If you want to Back, Please Enter \"0\""<<endl
                 << "Enter Team ID : ";
                again2 : int teamid;
                cin >> teamid;
                Team* team;
                team=database->FindClub(teamid);
                if(team!=NULL)
                {
                    if(team->StadiumName==NULL)
                    {
                        Admin->StadiumAssigmenttoTeam(stadium,team);
                        cout <<"Succesfully Added"<<endl;
                    }
                    else
                    {
                        cout<<"Team has A Stadium. Please Firstly Remove it."<<endl;
                        goto again2;
                    }
                }
                else if(teamid==0)
                {
                    break;
                }
                else
                {
                    cout <<"Wrong ID"<<endl;
                }
        }
        else if(Operation=="3")
        {
            ShowMatches(database->Matches);
            cout << "-------------------------"<<endl
                 << "If you want to Back, Please Enter \"0\""<<endl
                 << "Enter Match ID : ";
                int matchid;
                cin >> matchid;
                Match* match;
                match=database->FindMatch(matchid);
                if(match!=NULL)
                {
                    Admin->MatchAssigmenttoStadium(match,stadium);
                    cout <<"Succesfully Added"<<endl;
                }
                else if(matchid==0)
                {
                    break;
                }
                else
                {
                    cout <<"Wrong ID"<<endl;
                }
        }
        else if(Operation=="4")
        {
            if(stadium->TeamName!=NULL)
            {
                int clubid=stadium->TeamName->TeamID;
                Team *team=database->FindClub(clubid);
                Admin->StadiumRemovetoTeam(stadium,team);
                cout <<"Succesfully Removed";
                goto again;
            }
        }
        else if(Operation=="5")
        {
            ShowMatches(stadium->Matches);
            cout << "-------------------------"<<endl
                 << "Enter Team ID : ";
                int matchid;
                cin >> matchid;
                Match* match;
                match=database->FindMatch(matchid);
                if(match!=NULL)
                {
                    Admin->MatchRemovetoStadium(match,stadium);
                    cout <<"Succesfully Removed"<<endl;
                }
                else if(matchid==0)
                {
                    break;
                }
                else
                {
                    cout <<"Wrong ID"<<endl;
                }
        }
        else{}
    }
}
void Interface::EditMatch(Match *match)
{
    while(true)
    {
        cout << "1 - Assigment Match For Teams" <<endl
             << "2 - Assigment Match For Stadium" <<endl
             << "3 - Remove Match From Team " <<endl
             << "4 - Remove Match From Stadium " <<endl
             << "0 - Back " << endl
             << "Please Enter Your Choose : " << endl;
        string Operation;
        again : cin >>Operation;
        if(Operation=="0")
        {
            system("CLS");
            break;
        }
        else if(Operation=="1")
        {
            ShowClubs(database->Teams);
            cout <<"-------------------------"<<endl
                 << "Enter Home Team ID : ";
                 while(true)
                 {
                    int hteamid;
                    cin >> hteamid;
                    Team* hteam;
                    hteam=database->FindClub(hteamid);
                    if(hteam!=NULL)
                    {
                        cout << "If NOT Played, Please Enter \"-1\" for Team's Score"<<endl;
                        cout << hteam->TeamName <<" score : ";
                        int hscore;
                        cin >> hscore;
                        match->HomeScore=hscore;
                        Admin->MatchAssigmenttoTeam(match,hteam);
                        cout <<"Succesfully Added"<<endl;
                        break;
                    }
                    else
                    {
                        cout <<"Wrong ID! Please Enter Correct ID : ";
                    }
                 }
                 cout << "Enter Away Team ID : ";
                 while(true)
                 {
                    int teamid;
                    cin >> teamid;
                    Team* team;
                    team=database->FindClub(teamid);
                    if(team!=NULL)
                    {
                        cout << "If NOT Played, Please Enter \"-1\" for Team's Score"<<endl;
                        cout << team->TeamName <<" score : ";
                        int score;
                        cin >> score;
                        match->AwayScore=score;
                        Admin->MatchAssigmenttoTeam(match,team);
                        cout <<"Succesfully Added"<<endl;
                        break;
                    }
                    else
                    {
                        cout <<"Wrong ID! Please Enter Correct ID : ";
                    }
                 }

        }
        else if(Operation=="2")
        {
            ShowStadiums(database->Stadiums);
            cout << "-------------------------"<<endl
                 << "If you want to Back, Please Enter \"0\""<<endl
                 << "Enter Stadium ID : ";
                int stadiumid;
                cin >> stadiumid;
                Stadium* stadium;
                stadium=database->FindStadium(stadiumid);
                if(stadium!=NULL)
                {
                    Admin->MatchAssigmenttoStadium(match,stadium);
                    cout <<"Succesfully Added"<<endl;
                }
                else if(stadiumid ==0)
                {
                    break;
                }
                else
                {
                    cout <<"Wrong ID"<<endl;
                }
        }
        else if(Operation=="3")
        {
            ShowClubs(match->HomeAwayTeam);
            cout << "-------------------------"<<endl
                 << "If you want to Back, Please Enter \"0\""<<endl
                 << "Enter Team ID : ";
                int teamid;
                cin >> teamid;
                Team* team;
                team=database->FindClub(teamid);
                if(team!=NULL)
                {
                    Admin->MatchRemovetoTeam(match,team);
                    cout <<"Succesfully Removed"<<endl;
                }
                else if(teamid ==0)
                {
                    break;
                }
                else
                {
                    cout <<"Wrong ID"<<endl;
                }
        }
        else if(Operation=="4")
        {
            if(match->StadiumName!=NULL)
            {
                int stadiumid=match->StadiumName->StadiumID;
                Stadium *stadium=database->FindStadium(stadiumid);
                Admin->MatchRemovetoStadium(match,stadium);
                cout <<"Succesfully Removed";
                goto again;
            }
        }
        else{}
    }
}
