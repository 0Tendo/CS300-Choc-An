#include "members.h"
using namespace std;


//Ethan Saftler, Ryan Tran, Cristian Torres Salazar, Matthew Marcellinus, Yuxin Sun, Chentao Ma

//CS300 Term Project - PSU Winter 2022
//Chocoholics Service Terminal Software
//constructor
member::member()
{
    name=NULL;
    address=NULL;
    city=NULL;
    state=NULL;
    number=NULL;
    zip=NULL;
    service=NULL;
}
//destructor
member::~member()
{
    name=NULL;
    address=NULL;
    city=NULL;
    state=NULL;
    number=NULL;
    zip=NULL;
    service=NULL;
}