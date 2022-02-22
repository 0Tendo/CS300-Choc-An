#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>
#include <time.h>

const int NAMESIZE = 26;
const int NUMBERSIZE = 10;
const int ADDRESSSIZE = 26;
const int CITYSIZE = 15;
const int STATESIZE = 3;
const int ZIPSIZE = 6;
const int MMDDYY = 7;


//displays invalidity of inputted data based on its associated prime number
//use in tandem with check_format() functions
void display_invalidity(int check);

//check if array of chars is digits
bool check_if_digit(char * to_check);

//check if array of chars is letters
bool check_if_letter(char * to_check);

//convert array of chars to uppercase
void uppercaser(char * to_upper);

//nodes for service events (used by provider and member class)/
//provider class
struct service_node
{
    service_node();
    ~service_node();
    service_node * next;
    char * current_date;
    char * service_date;
    char * provider_number;
    char * member_number;
    char * service_code;
    int fee;
};

class provider
{
    public:
        provider();
        ~provider();
        //NOT SURE provider(char * name, char * address, char * city, char * state, char * number, char * zip, int total_consults, int weekly_fee);
        int create();
        int copy_provider(const provider & provider_to_copy);
        int check_format(bool display = true);
        //TO DO int add_service();
        int retrieve_name(char * & name_to_return);
        int retrieve_number(char * & numb_to_return);
        int display() const;
    private:
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

                //TO DO int delete_all();
                //TO DO int delete_all(node * & root);

                int insert (provider & provider_to_add);
                int insert (node * & root, provider & provider_to_add);

                int retrieve(char * name_to_get, provider & provider_to_return);
                int retrieve(node * root, char * name, provider & provider_to_return);

                int display(char * prodiver_number_to_display);
                int display(node * root, char * provider_number_to_display);

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
