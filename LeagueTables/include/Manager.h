#ifndef MANAGER_H
#define MANAGER_H

#include "stdafx.h"

using namespace std;

class Team;
class Manager
{
     public:
        //Varlik özellikleri
        int ManagerID;
        string FirstName;
        string LastName;
        string Country;
        int Age;
        int Salary; // birimi euro olacak

        // diger siniflarla iliskisi
        Team *TeamName; // managerin takimi - takim iliskisi



        //cons ve decons
        Manager();
        Manager(int,string,string,string,int,int);
        virtual ~Manager();

        // manager metodlari

};

#endif // MANAGER_H
