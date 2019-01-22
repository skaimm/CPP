#include "Sponser.h"

Sponser::Sponser()
{
    SponserID=0;
    SponserName='\0';
}

Sponser::Sponser(int IDOfSponser , string NameOfSponser)
{
    SponserID=IDOfSponser;
    SponserName=NameOfSponser;
}

Sponser::~Sponser()
{
    //dtor
}
