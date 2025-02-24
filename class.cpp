#include "class.h"
// Person::Person() : last_name(""), first_name(""), patronymic("") {}

Person::Person(const string &ln, const string &fn, const string pn) {
    lastname = ln, firstname = fn, patronymic = pn;
}

void Person::Show()
{ 
    cout<<"Фамилия: "<<lastname<<endl;
    cout<<"Имя: "<<firstname<<endl;
    cout<<endl;
}

void Person::Show_official()
{
    cout<<"ФИО: "<<lastname<< " " <<firstname<<" "<<patronymic<<endl;
    cout<<endl;
}
