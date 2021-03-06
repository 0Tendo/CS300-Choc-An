 #include <iostream>
#include <cctype>
#include <string>
#include <fstream>
#include <cstring>
#include "BasicDefinition.h"
using namespace std;




//Ethan Saftler, Ryan Tran, Cristian Torres Salazar, Matthew Marcellinus, Yuxin Sun, Chentao Ma
// we the best
//CS300 Term Project - PSU Winter 2022
//Chocoholics Service Terminal Software



//displays invalidity of inputted data based on its associated prime number
//use in tandem with check_format() functions
void display_invalidity(int check);

//check if array of chars is digits
bool check_if_digit(char * to_check);

//check if array of chars is letters
bool check_if_letter(char * to_check);

//convert array of chars to uppercase
void uppercaser(char * to_upper);

int FileSize(char * filename);

//nodes for service events (used by provider and member class)/
//provider class
struct service_node
{
    service_node * next;
    string current_date;
    string service_date;
    string provider_number;
    string member_number;
    string service_code;
    string service_name;
    float fee;
};

// "CTS" reach out to cristian for questions on these code sections
class provider
{
    public:
        provider();
        ~provider();
        //NOT SURE provider(char * name, char * address, char * city, char * state, char * number, char * zip, int total_consults, int weekly_fee);
        int create();
        int copy_provider(const provider & provider_to_copy);
        int check_format(bool display = true);
        
        int retrieve_name(char * & name_to_return);
        int retrieve_number(char * & numb_to_return);
        int display() const;
        void LoadProvider(char * name, char * address, char * city, char * state, char * number, char * zip);
    
        // CTS - Adds a service
        int Add_Service();
        // CTS - Deletes all services
        int DeleteAllServices();
        // CTS - Deletes a service
        int DeleteService(string key);
        // CTS - Display All Services
        int DisplayAllService();
        // CTS - Gets a service fee
        float GetServiceFee(string sCode);
        // CTS - Populates a provider oobject
        int PopulateProvider(provider&toPop);
        void CopyServiceList(provider*& dst);
        int cp(provider& provider_to_copy);

    private:
        // CTS - Recursively add a service
        int AddService(service_node*& head);
        // CTS - Recursively Delete All
        int DeleteAllServices(service_node*& service);
        // CTS - Deletes a single service
        int DeleteService(service_node*& service, string key);
        // CTS - Display all services
        int DisplayAllService(service_node *& service);
        void DisplayService(service_node * serv);
        float GetServiceFee(service_node* service, string sCode);
        void CopyServiceList(service_node* src, service_node*& dst);

        char * name;
        char * address;
        char * city;
        char * state;
        char * number;
        char * zip;
        int total_consults;
        int weekly_fee;
        service_node * services; //LLL of services provider has provided
};


//nodes for BST	(used by providers and members class)
struct node
{
    node();
    ~node();
    node * left;
    node * right;
    provider current;
};

//BST providers class
class providers
{
        public:
                providers();
                ~providers();

                int delete_all();
                int delete_all(node * & root);

                int insert (provider & provider_to_add);
                int insert (node * & root, provider & provider_to_add);

                int retrieve(char * name_to_get, provider & provider_to_return);
                int retrieve(node * root, char * name, provider & provider_to_return);

                int display(char * prodiver_number_to_display);
                int display(node * root, char * provider_number_to_display);

                int display_all();
                int display_all(node * root);

                int Remove(char* provNumber);

                void LoadData();
                //TO DO int remove(char * name_to_remove);
                //TO DO int remove(node * & root, node * & prev, char * prodiver_to_remove);
                //TO DO int remove(node * & root, char * prodiver_to_remove);

                //TO DO int remove_provider(char * provider_to_remove);//, char * & found_match_name);
                //TO DO int remove_provider(node * & root, char * provider_to_remove, char * & found_match_name);

                //TO DO int height();
                //TO DO int height(node * root);
        private:
                node * root;

};
