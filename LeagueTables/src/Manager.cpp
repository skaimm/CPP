#include "Manager.h"

Manager::Manager()
{
    ManagerID=0;
    FirstName='\0';
    LastName='\0';
    Country='\0';
    Age=0;
    Salary=0;

    TeamName=NULL;
}

Manager::Manager(int ID,string Name,string LName,string MCountry,int MAge,int MSalary)
{
    ManagerID=ID;
    FirstName=Name;
    LastName=LName;
    Country=MCountry;
    Age=MAge;
    Salary=MSalary;

    TeamName=NULL;
}
Manager::~Manager()
{
    //dtor
}
