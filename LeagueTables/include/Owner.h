#ifndef OWNER_H
#define OWNER_H

#include "stdafx.h"

using namespace std;
class Team;
class Owner
{
    public:
        //Varlik özellikleri
        int OwnerID;
        string FirstNameOfOwner;
        string LastNameOfOwner;

        // Diger siniflarla iliskisi
        Team *TeamName; //Team sınıfından TeamName adında bir değişken tanımladık


        //cons ve decons
        Owner();
        Owner(int,string,string);
        virtual ~Owner();


};

#endif // OWNER_H
