#include <iostream>
#include <fstream>
#include <string>

#include "stdafx.h"

using namespace std;

int main()
{
	Database Data;

    Data.Create();

    Fifa Admin(&Data);

    Interface Windows(&Data,&Admin);

    Windows.Start();




//	OgrenciIsleri Uygulama(&veri);

//	AraYuz Pencereler(&veri, &Uygulama);

//	Pencereler.Baslat();


    return 0;
}
