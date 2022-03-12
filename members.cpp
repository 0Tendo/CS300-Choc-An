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
    return 1;
}
//for the data structor to search by name
char*member::get_name()
{
    return name;
}
//for to search by ID
int member::get_memberID()
{
    return number;
}

//BST of member
//the function of the node
//constructor
node_member::node_member()
{
	data=NULL;
	left=NULL;
	right=NULL;
}
//default of the node
node_member::~node_member()
{
	delete data;
	data=NULL;

} 
//constructor of the node
node_member::node_member(member*source)
{
	this->data=source;
	left=NULL;
	right=NULL;
}
//copy constructor of the node
node_member::node_member(const node_member&source)
{
	this->data=source.data;
	this->left=source.left;
	this->right=source.right;
}
//operator = overloading
node_member&node_member::operator=(const node_member&source)
{
	if(this==&source)
	return *this;
	if(this->data)
	{
		delete data;
	}
	if(this->right)
	{
		delete right;
	}
	if(this->left)
	{
		delete left;
	}
	this->data=source.data;
	this->left=source.left;
	this->right=source.right;
	return *this;
}
//add the node 
int node_member::insert(member&to_add)
{
	if(strcmp(to_add.get_name(),this->data->get_name())<=0)
	{
		if(!this->left)
		{
			this->left=new node_member(&to_add);
			return 0;
		}
		this->left->insert(to_add);
	}
	else
	{
		if(this->right==NULL)
		{
			this->right=new node_member(&to_add);
			return 0;
		}
		this->left->insert(to_add);
	}
	return 1;
}
//remove a node
node_member*node_member::remove(char*name_rm,node_member *parent, node_member*&root, int path)
{
	if(!this)
		return 0;
	if(strcmp(this->data->get_name(),name_rm)>0)
	{
		node_member*rm=this->left->remove(name_rm,this,root,0);
		if(rm)
		{
			if(!rm->left&&rm->right)
			{
				this->right=rm->right;
				delete rm;
				rm=NULL;
			}
			else if(rm->left&&!rm->right)
			{
				this->left=rm->left;
				delete rm;
				rm=NULL;
			}
			else if(!rm->left&&!rm->right)
			{
				this->left=NULL;
				delete rm;
				rm=NULL;
			}
		}
	}
	else if(strcmp(this->data->get_name(),name_rm)<0)
	{
		node_member*rm=this->right->remove(name_rm,this,root,1);
		if(rm)
		{
			if(!rm->left&&rm->right)
			{
				this->right=rm->right;
				delete rm;
				rm=NULL;
			}
			else if(rm->left&&!rm->right)
			{
				this->left=rm->left;
				delete rm;
				rm=NULL;
			}
			else if(!rm->left&&!rm->right)
			{
				this->left=NULL;
				delete rm;
				rm=NULL;
			}
		}
	}
	else{
		if(this==root)
		{
			if(!root->left&&!root->right)
			{
				delete root;
				root=NULL;
				return root;
			}
			if(!root->right->left)
			{
				node_member*temp=root;
				root=root->right;
				root->left=temp->left;
				delete temp;
				return root;
			}
			else
			{
				node_member*ios=IOS(this->right,this->right);
				ios->right=root->right;
				ios->left=this->left;
				node_member*temp=root;
				root=ios;
				delete temp;
				return root;
			}
		}
		if(!this->left&&!this->right)
		{
			return this;
		}
		if(!this->left)
		{
			return this;
		}
		else if(!this->right)
		{
			parent->left=this->left;
			return this;
		}
		if(!this->right->left)
		{
			if(path==0)
			{
				parent->left=this->left;
				this->right->left=this->left;
			}
			else
			{
				parent->right=this->right;
				this->right->left=this->left;
			}
			return this;
		}
		node_member*ios=IOS(this->right,this->right);
		ios->right=this->right;
		ios->left=this->left;
		if(path==0)
		{
			parent->left=ios;
		}
		else
		{
			parent->right=ios;
		}
		return this;
	}
	return this;
}
//find the ios of the node

node_member*node_member::IOS(node_member*&current,node_member*&parent)
{
	if(!current)
		return NULL;
	if(current->left)
	{
		return IOS(current->left,current);
	}
	node_member*temp=current;
	parent->left=current->right;
	temp->right=NULL;
	temp->left=NULL;
	return temp; 
}
//search the node by name
bool node_member::search(char*name_search, member**i)
{
	if(this==NULL)
		return 0;
	if(strcmp(name_search,this->data->get_name())<0)
	{
		return this->left->search(name_search,i);
	}
	if(strcmp(name_search,this->data->get_name())>0)
	{
		return this->right->search(name_search,i);
	}
	*i=this->data;
	return 1;

}
//delete the whole tree
int node_member::delete_all()
{
	if(this->left)
	{
		this->left->delete_all();
		delete this->left;
		this->left=NULL;
	}
	if(this->right)
	{
		this->right->delete_all();
		delete this->right;
		this->right=NULL;
	}
	return 1;
}
//display the tree
void node_member::display() const
{

	if(this==NULL)
		return ;
	this->left->display();
	this->data->display( );
	this->right->display();
	return ;
}
bool node_member::search_ID(int search_num)
{
	if(this==NULL)
		return 0;
	if(search_num!=this->data->get_memberID())
	{
		this->left->search_ID(search_num)+this->right->search_ID(search_num);
    }
    if(search_num==this->data->get_memberID())
    {
	    this->data->display();
	    return 1;
    }
    return 0;

}



//Tree class
//constructor
tree::tree()
{
	root=NULL;
}
//destructore
tree::~tree()
{
	if(root)
	{
		root->delete_all();
	}
}
//copy constructor
tree::tree(const tree&source)
{
	this->root=source.root;
}
//add a new node to the list
int tree::insert(member*to_add)
{
	if(!root)
	{
		root=new node_member(to_add);
		return 0;
	}
	else
	{
		root->insert(*to_add);
		return 1;
	}
}
//remove the node 
int tree::remove(char*name)
{
	if(!root)
		return 0;
	root->remove(name,NULL,root,0);
	return 1;
}
//search a node in the tree
bool tree::search(char*name, member**i)
{
	if(!root)
		return 0;
	return root->search(name,i);
}
//remove all node in the list
int tree::remove_all()
{
	if(root==NULL)
	{
		return 0;
	}
	root->delete_all();
	delete root;
	root=NULL;
	return 1;
}
//display a tree

int tree::display()
{
	if(root==NULL)
		return 0;
	root->display();
	return 1;
}
bool tree::search_ID(int search_num)
{
	if(!root)
		return 0;
	return root->search_ID(search_num);
}
void tree::LoadData()
{
    char temp_name[NAMESIZE];
    int temp_number;
    char temp_address[ADDRESSSIZE];
    char temp_city[CITYSIZE];
    char temp_state[STATESIZE];
    int temp_zip;
    char filename[50] = "members.txt";
    int fsize = FileSize(filename);
    int i = 0;
    ifstream infile;
    infile.open(filename);
    if (!infile)
    {
        cerr <<"Failed to open " << filename << endl;
    }
    while (infile && !infile.eof())
    {
        infile.ignore(1000, '\n'); 
        infile.get(temp_name, NAMESIZE, '#');
        infile.ignore();
        infile.get(temp_address, ADDRESSSIZE, '#');
        infile.ignore();
        infile.get(temp_city, CITYSIZE, '#');
        infile.ignore();
        infile.get(temp_state, STATESIZE, '#');
        infile.ignore();
        infile>>temp_number;
        infile.ignore();
        infile>>temp_zip;
        infile.ignore();
        member temp_member;
        temp_member.LoadMember(temp_name, temp_address, temp_city, temp_state, temp_number, temp_zip); 
        insert(&temp_member);
        i++;
    }
    return;
}


void member::LoadMember(char * temp_name, char * temp_address, char * temp_city, char * temp_state, int temp_number, int temp_zip)
{
    name = new char[strlen(temp_name)+1];
    strcpy(name, temp_name);
    number = temp_number;
    address = new char[strlen(temp_address)+1];
    strcpy(address, temp_address);
    city = new char[strlen(temp_city)+1];
    strcpy(city, temp_city);
    state = new char[strlen(temp_state)+1];
    strcpy(state, temp_state);
    uppercaser(state);
    zip = temp_zip;
    return;
}