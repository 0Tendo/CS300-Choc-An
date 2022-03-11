#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>
#include <time.h>
#include "providers.h" //uses node and service_node

//Ethan Saftler, Ryan Tran, Cristian Torres Salazar, Matthew Marcellinus, Yuxin Sun, Chentao Ma

//CS300 Term Project - PSU Winter 2022
//Chocoholics Service Terminal Software


//member class
class member
{
    public:
        member();
        ~member();
        int create_member();
        int copy_member(const member & member_to_copy);
        int retrieve_name(char * & name_to_ret);
        int display() const;
        int delete_all();
    private:
        char * name;
        char * address;
        char * city;
        char * state;
        int number;
        int zip;
        service_node * service; //LLL of services member has provided
};


//BST members class
class members
{
        public:
                members();
                ~members();

                int delete_all();
                int delete_all(node * & root);

                int insert (member & member_to_insert);
                int insert (node * & root, member & member_to_insert);

                int retrieve (char * name_to_get, member & member_to_return);
                int retrieve(node * root, char * name, member & member_to_return);

                int display(char * prodiver_todisplay);
                int display(node * root, char * member_todisplay);

                int remove(char * name_to_remove);
                int remove(node * & root, node * & prev, char * prodiver_to_remove);
                int remove(node * & root, char * prodiver_to_remove);

                int remove_member(char * member_to_remove);//, char * & found_match_name);
                int remove_member(node * & root, char * member_to_remove, char * & found_match_name);

                int height();
                int height(node * root);
        private:
                node * root;

};
