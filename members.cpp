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
    number=0;
    zip=0;
    service=NULL;
}
//destructor
member::~member()
{
    delete []name;
    delete []address;
    delete []city;
    delete []state;
    number=0;
    zip=0;
    delete service;
    service=NULL;
}
//create a member
int member::create_member()
{
    bool bad=false;
    do
    {
        cout<<"Please enter the member ID (9digit)"<<endl;
        cin>>number;
        bad=cin.fail();
        if(bad)
            cout<<"The Id need to be 9 digits"<<endl;
        cin.clear();
        cin.ignore(100,'\n');   
    } while (bad||number>999999999||number<0);
    

    char temp_name[NAMESIZE];
    char temp_address[ADDRESSSIZE];
    char temp_city[CITYSIZE];
    char temp_state[STATESIZE];
    cout << "Please enter the member name: ";
    cin.get(temp_name, NAMESIZE, '\n');
    cin.ignore(100, '\n');
    cout << "Please enter the member address: ";
    cin.get(temp_address, ADDRESSSIZE, '\n');
    cin.ignore(100, '\n');
    cout << "Please enter the member city: ";
    cin.get(temp_city, CITYSIZE, '\n');
    cin.ignore(100, '\n');
    cout << "Please enter the member state: ";
    cin.get(temp_state, STATESIZE, '\n');
    cin.ignore(100, '\n');
    name = new char[strlen(temp_name)+1];
    strcpy(name, temp_name);
    address = new char[strlen(temp_address)+1];
    strcpy(address, temp_address);
    city = new char[strlen(temp_city)+1];
    strcpy(city, temp_city);
    state = new char[strlen(temp_state)+1];
    strcpy(state, temp_state);
    uppercaser(state);
    bool bad1=false;
    do
    {
        cout<<"Please enter the member zip (5digit)"<<endl;
        cin>>zip;
        bad=cin.fail();
        if(bad)
            cout<<"The zip need to be 5 digits"<<endl;
        cin.clear();
        cin.ignore(100,'\n');   
    } while (bad1||number>99999||number<0);
    return 0;
}
//copy a member
int member::copy_member(const member & member_to_copy)
{
    name = new char[strlen(member_to_copy.name)+1];
    address = new char[strlen(member_to_copy.address)+1];
    city = new char[strlen(member_to_copy.city)+1];
    state = new char[strlen(member_to_copy.state)+1];
    strcpy(name, member_to_copy.name);
    strcpy(address, member_to_copy.address);
    strcpy(city, member_to_copy.city);
    strcpy(state, member_to_copy.state);
    zip=member_to_copy.zip;
    number=member_to_copy.number;
    //TODO add copy services function
    if (member_to_copy.service == NULL){
        service = NULL;
    }else{
    //services = to_copy.services;
    }
    return 0;

}
//display a member
int member::display() const
{
    cout << "\n\nMember name: " << name << endl;
    cout << "\n\nMember ID: " << number << endl;
    cout << "\n\nMember address: " << address << "\n\t\t  " << city << ", " << state << " " << zip << endl;
    cout << "\n\nService Record:";
    service_node * cur = service;
    int i = 1;
    while (cur != NULL)
    {
        cout << "\n" << i << ".";
        cout << "\nService date: " << cur->service_date;
        cout << "\nTime of entry: " << cur->current_date;
        cout << "\nProvider number: " << cur->provider_number;
        cout << "\nMember number: " << cur->member_number;
        cout << "\nService code: " << cur->service_code;
        i++;
        cur = cur->next;
    }
    return 0;
}

//change the name
int member::retrieve_name(char * & name_to_ret)
{
    if(name)
    {
        delete [] name;
    }
    name = new char[strlen(name_to_ret)+1];
    strcpy(name, name_to_ret);
}


