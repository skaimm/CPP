#include "Owner.h"

Owner::Owner()
{
    OwnerID=0;
    FirstNameOfOwner='\0';
    LastNameOfOwner='\0';

    TeamName=NULL;
}
Owner::Owner(int ID, string Name, string LastName)
{
    OwnerID=ID;
    FirstNameOfOwner=Name;
    LastNameOfOwner=LastName;

    TeamName=NULL;
}
Owner::~Owner()
{
    //dtor
}
