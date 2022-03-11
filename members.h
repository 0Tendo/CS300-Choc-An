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
        char * get_name();
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
class node_member
{
	public:
	node_member();
	~node_member();
	node_member(member*source);
	node_member(const node_member&source);
	node_member&operator=(const node_member&);
	int insert(member&to_add);
	node_member*remove(char*name,node_member *parent, node_member*&root, int path);
	node_member*IOS(node_member*&current,node_member*&parent);
	bool search(char*name, member**i);
	int delete_all();
	void display() const;
	friend ostream&operator<<(ostream &out,const node_member&to_display);
                 
	protected:
		member*data;
		node_member*left;
		node_member*right;
};

class tree
{
	public:
		tree();
		~tree();
		tree(const tree&source);
		tree&operator=(const tree&t1);
		int insert(member*to_add);
		int remove(char*name);
		bool search(char*name, member**i);
		int remove_all();
		int display();
	private:
		node_member*root;
};
