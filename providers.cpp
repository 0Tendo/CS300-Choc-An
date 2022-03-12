#include "providers.h"

//Ethan Saftler, Ryan Tran, Cristian Torres Salazar, Matthew Marcellinus, Yuxin Sun, Chentao Ma

//CS300 Term Project - PSU Winter 2022
//Chocoholics Service Terminal Software


//check if array of chars is digits
bool check_if_digit(char * to_check)
{
    int i = 0;
    int len = strlen(to_check);
    while (i < len)
    {
        if (!isdigit(to_check[i])){
            return false;}
        i++;
    }
    return true;
}

//check if array of chars is letters
bool check_if_letter(char * to_check)
{
    int i = 0;
    int len = strlen(to_check);
    while (i < len)
    {
        if (!isalpha(to_check[i])){
            return false;}
        i++;
    }
    return true;
}

void uppercaser(char * to_upper)
{
    int i = 0;
    int len = strlen(to_upper);
    while (i < len){
        to_upper[i] = toupper(to_upper[i]);
        i++;
    }
    return;
}


node::node()
{
    left = NULL;
    right = NULL;
}

node::~node()
{
    left = NULL;
    right = NULL;
}

provider::provider()
{
    name = NULL;
    address = NULL;
    city = NULL;
    state = NULL;
    number = NULL;
    zip = NULL;
    total_consults = 0;
    weekly_fee = 0;
    services = NULL;
}

provider::~provider()
{
    delete name;
    delete address;
    delete city;
    delete state;
    delete number;
    delete zip;
    delete services;
    services = NULL;
}

int provider::create()
{
    char temp_name[NAMESIZE];
    char temp_number[NUMBERSIZE];
    char temp_address[ADDRESSSIZE];
    char temp_city[CITYSIZE];
    char temp_state[STATESIZE];
    char temp_zip[ZIPSIZE];
    cout << "\n\nPlease enter the provider information below\n";
    cout << "name: ";
    cin.get(temp_name, NAMESIZE, '\n');
    cin.ignore(100, '\n');
    cout << "number (9digit): ";
    cin.get(temp_number, NUMBERSIZE, '\n');
    cin.ignore(100, '\n');
    cout << "address: ";
    cin.get(temp_address, ADDRESSSIZE, '\n');
    cin.ignore(100, '\n');
    cout << "city: ";
    cin.get(temp_city, CITYSIZE, '\n');
    cin.ignore(100, '\n');
    cout << "state: ";
    cin.get(temp_state, STATESIZE, '\n');
    cin.ignore(100, '\n');
    cout << "zip: ";
    cin.get(temp_zip, ZIPSIZE, '\n');
    cin.ignore(100, '\n');
    name = new char[strlen(temp_name)+1];
    strcpy(name, temp_name);
    number = new char[strlen(temp_number)+1];
    strcpy(number, temp_number);
    address = new char[strlen(temp_address)+1];
    strcpy(address, temp_address);
    city = new char[strlen(temp_city)+1];
    strcpy(city, temp_city);
    state = new char[strlen(temp_state)+1];
    strcpy(state, temp_state);
    uppercaser(state);
    zip = new char[strlen(temp_zip)+1];
    strcpy(zip, temp_zip);
    return 0;

}

//copies input to current provider
int provider::copy_provider(const provider & to_copy)
{
    name = new char[strlen(to_copy.name)+1];
    address = new char[strlen(to_copy.address)+1];
    city = new char[strlen(to_copy.city)+1];
    state = new char[strlen(to_copy.state)+1];
    zip = new char[strlen(to_copy.zip)+1];
    number = new char[strlen(to_copy.number)+1];
    strcpy(name, to_copy.name);
    strcpy(address, to_copy.address);
    strcpy(city, to_copy.city);
    strcpy(state, to_copy.state);
    strcpy(zip, to_copy.zip);
    strcpy(number, to_copy.number);
    //TODO add copy services function
    if (to_copy.services == NULL){
        services = NULL;
    }else{
    //services = to_copy.services;
    }
    return 0;
}

//display current provider and all service events
int provider::display() const{
    cout << "\n\nProvider name: " << name << endl;
    cout << "Provider address: " << address << "\n\t\t  " << city << ", " << state << " " << zip << endl;
    cout << "Total consults: " << total_consults << endl;
    cout << "Weekly fee: " << weekly_fee << endl;
    cout << "Service Record:";
    service_node * cur = services;
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

//each object member as an associated prime number.
//function returns the associated prime number if the input is bad.
//take the mod of the returned value and check against associated prime number to see fail state 
//display set to true by default
int provider::check_format(bool display)
{
    int i = 1;
    if (name != NULL){
        if (check_if_letter(name) == false){
            i *= 3;
        }
    }
    if (number != NULL){
        if (check_if_digit(number) == false){
            i *= 5;
        }
    }    
    if (city != NULL){
        if (check_if_letter(city) == false){
            i *= 7;
        }
    }
    if (state != NULL){
        if (check_if_letter(state) == false){
            i *= 11;
        }
    }
    if (zip != NULL){
        if (check_if_digit(zip) == false){
            i *= 13;
        }
    }
    if (display == true){
        display_invalidity(i);
    }
    //debugging: cout << "I is: " << i << endl;
    return i;
}

int provider::retrieve_name(char * & name_to_return){
    name_to_return = new char[strlen(name)+1];
    strcpy(name_to_return, name);
    return 1;
}

int provider::retrieve_number(char * & number_to_return){
    number_to_return = new char[strlen(number)+1];
    strcpy(number_to_return, number);
    return 1;
}

//displayed associated error code. use in tandem with check_format
void display_invalidity(int check)
{
    int temp = 0;
    if (check == 0){
        return;
    }else{
        temp = (check % 3);
        if (temp == 0) cerr << "\ninvalid name. ";
        temp = (check % 5);
        if (temp == 0) cerr << "\ninvalid number. ";
        temp = (check % 7);
        if (temp == 0) cerr << "\ninvalid city. ";
        temp = (check % 11);
        if (temp == 0) cerr << "\ninvalid state. ";
        temp = (check % 13);
        if (temp == 0) cerr << "\ninvalid zip. ";
    }
}



providers::providers()
{
    root = NULL;
}

providers::~providers() {}

int providers::insert(provider & provider_to_add){
    return insert(root, provider_to_add);
}

int providers::insert(node * & root, provider & provider_to_add)
{
    if (!root)
    {
        root = new node;
        root->current.cp(provider_to_add);
        root->left = NULL;
        root->right = NULL;
        return 0;
    }else{
        char * tempname;
        char * tempname2;
        int comp = 0;
        provider_to_add.retrieve_name(tempname);
        root->current.retrieve_name(tempname2);
        comp = strcmp(tempname, tempname2);
        if (comp < 0)
        {
            insert(root->left, provider_to_add);
        }else{
            insert(root->right, provider_to_add);
        }
        return 1;
    }
}

//displays info of the provided provider number
int providers::display(char * provider_number){
    return display(root, provider_number);
}

//recursive call
int providers::display(node * root, char * provider_number){
    if (!root) return 0;
    else{
        char * temp_numb;
        int comp = 0;
        int i = 0;
        root->current.retrieve_number(temp_numb);
        comp = strcmp(provider_number, temp_numb);
        if (comp == 0)
        {
            root->current.display();
            i++;
        }
        i += display(root->left, provider_number);
        i += display(root->right, provider_number);
        return i;
    }
}


int providers::display_all(){
    return display_all(root);
}

int providers::display_all(node * root){
    int i = 0;
    if (!root) return i;
    else{
        root->current.display();
        i += display_all(root->left);
        i += display_all(root->right);
        return i;
    }
}


/// <summary>
/// Adds the first node of a service list or invokes recursive method to create
/// a new service node.
/// </summary>
/// <returns>1 indicating successfull add</returns>
/// <remarks>Developer CTS if you have questions</remarks>
/// CTS
int provider::Add_Service() {

    // check if the list is empty
    if (services == NULL) {
        services = new service_node;

        // Gather data \/
        cout << "\n\nEnter the current date: \n\n" << endl;
        getline(cin, services->current_date);

        cout << "Enter the date of service: \n\n" << endl;
        getline(cin, services->service_date);

        cout << "Enter the Provider Number: \n\n" << endl;
        getline(cin, services->provider_number);

        cout << "Enter the Member Number: \n\n" << endl;
        getline(cin, services->member_number);

        cout << "Enter the Service Code: \n\n" << endl;
        getline(cin, services->service_code);

        cout << "Enter the Service Code: \n\n" << endl;
        getline(cin, services->service_name);

        cout << "Enter the Service Fee: \n\n" << endl;
        cin >> services->fee;
        cin.ignore(100, '\n');

        // set next to null (this will be appended to the list)
        services->next = NULL;

        return 1;
    }
    else {
        // invoke recursive method with begining of list if list is not empty
        return AddService(services);
    }

}

/// <summary>
/// This method will recursively add a service to the list of services for 
/// the respective provider. Service data is collected within the method
/// </summary>
/// <param name="service">The starting node of a Linked List</param>
/// <returns>1 indicating successfull add</returns>
/// CTS
int provider::AddService(service_node*& service) {

    // single case checking for the end of the list
    if (service->next == NULL) {

        // create new temp node to add
        service_node* temp = new service_node;

        // gather node data
        cout << "\n\nEnter the current date: \n\n" << endl;
        getline(cin, temp->current_date);

        cout << "Enter the date of service: \n\n" << endl;
        getline(cin, temp->service_date);

        cout << "Enter the Provider Number: \n\n" << endl;
        getline(cin, temp->provider_number);

        cout << "Enter the Member Number: \n\n" << endl;
        getline(cin, temp->member_number);

        cout << "Enter the Service Code: \n\n" << endl;
        getline(cin, temp->service_code);

        cout << "Enter the Service Name: \n\n" << endl;
        getline(cin, temp->service_name);

        cout << "Enter the Service Fee: \n\n" << endl;
        cin >> temp->fee;
        cin.ignore(100, '\n');

        // this will be the last node
        temp->next = NULL;

        // add node to end of list
        service->next = temp;

        // disregard temp
        temp = NULL;

        // unwind recursive stack
        return 1;
    }

    // traverse if we are not at the end
    return AddService(service->next);
}

/// <summary>
/// Deletes all services for the respective provider.
/// Invokes recursive delete all if there are more
/// than one node
/// </summary>
/// <returns>Number of services deleted</returns>
/// CTS
int provider::DeleteAllServices()
{
    int count = 0;

    // Check for empty list
    if (!services) {
        return count;
    }
    // check for a single node
    else if (!services->next) {
        delete services;
        services = NULL;
        return ++count;
    }
    // removes all if there are more than one
    else {
        return DeleteAllServices(services);
    }
}

/// <summary>
/// Recursively deletes all services for the provider
/// </summary>
/// <param name="service">pointer to the service list</param>
/// <returns>Number of services removed</returns>
/// CTS
int provider::DeleteAllServices(service_node*& service)
{
    // check if we are at the end
    if (!service) {
        return 0;
    }

    // traverse to the end of the list
    int count = DeleteAllServices(service->next);

    // Delete nodes at tail end of recursion
    delete service;
    service = NULL;

    // return and increment node count
    return ++count;
}

/// <summary>
/// Deletes a single service matching the key passed in.
/// </summary>
/// <param name="servCode">Service code to look for</param>
/// <returns>-1 OR 0 if list is empty, 1 if success</returns>
/// CTS
int provider::DeleteService(string servCode)
{
    // check for empty list
    if (!services) {
        return -1;
    }
    // check for single node and if a match
    else if ((!services->next) && (services->service_code == servCode)) {
        delete services;
        services = NULL;
        return 1;
    }
    // check rest of the list
    else {
        return DeleteService(services, servCode);
    }
}

/// <summary>
/// Deletes a single service matcing the service code key
/// passed in.
/// </summary>
/// <param name="service">pointer to service list</param>
/// <param name="servCode">Service code key to remove</param>
/// <returns>0 if failed, 1 if successfull</returns>
/// CTS
int provider::DeleteService(service_node*& service, string servCode)
{
    // check for empty list
    if (!service) {
        return 0;
    }

    // recursively traverse list
    int success = DeleteService(service->next, servCode);

    // check if we have a match
    if (service->service_code == servCode) {
        service_node* temp = service->next;
        delete service;
        service = temp;
        temp = NULL;
        ++success;
    }
    return success;
}

/// <summary>
/// Displays all services for a provider.
/// </summary>
/// <returns>Number of nodes displayed</returns>
/// CTS
int provider::DisplayAllService() {

    cout << "\nDisplaying all services...\n\n";

    // check for empty list
    if (!services) {
        return -1;
    }
    // check for one service
    else if (!services->next) {
        // invoke helper to doa ctual displaying
        DisplayService(services);
    }
    // traverse entire list if more than one service
    else {
        return DisplayAllService(services);
    }
}

/// <summary>
/// Helper method takes in a service node and displays it
/// </summary>
/// <param name="serv">Service node to display</param>
/// CTS
void provider::DisplayService(service_node* serv) {
    // check node is not null
    if (serv) {
        cout << "\n\n";
        cout << " Service Name: " << serv->service_name << endl;
        cout << " Service Code: " << serv->service_code << endl;
        cout << "  Service Fee: " << serv->fee << endl << endl;
    }
}

/// <summary>
/// Recursevley traverses the service list and displays all service nodes
/// </summary>
/// <param name="serv">pointer to service node list to display</param>
/// <returns>Number of nodes displayed</returns>
/// CTS
int provider::DisplayAllService(service_node*& serv) {

    // Check that the list is not empty
    if (!serv) {
        return 0;
    }

    // invoke helper method to display service details
    DisplayService(serv);

    int count = 0;
    //traverse the list recursively
    count += DisplayAllService(serv->next);

    return ++count;
}

/// <summary>
/// Looks for a service and if found extracts the service fee
/// </summary>
/// <param name="sCode">Service code to look for</param>
/// <returns>Service Fee if found</returns>
/// CTS
float provider::GetServiceFee(string sCode) {

    if (!services) {
        return -1;
    }
    // Check if there is only one node and if it matches search key
    else if ((!services->next) && (services->service_code == sCode)) {
        DisplayService(services);
        return services->fee;
    }
    else {
        // traverse if more than one node and handle return val
        float success = GetServiceFee(services, sCode);

        if (success != -1) {
            return success;
        }
        else {
            cout << "\n\nError Service# " << sCode << " Not Found, Try Again." << endl;
        }
    }
}

/// <summary>
/// Traverses the service list looking for a service code to extract
/// the fee value.
/// </summary>
/// <param name="service">Pointer to service list</param>
/// <param name="sCode">Service Code value</param>
/// <returns>Service Fee if found.</returns>
/// CTS
float provider::GetServiceFee(service_node* service, string sCode) {

    if (!service) {
        return -1;
    }
    // Look for match ahead of recursion to redice overhead.
    if (service->service_code == sCode) {
        DisplayService(service);
        return service->fee;
    }

    return GetServiceFee(service->next, sCode);
}

int providers::retrieve(char* name_to_get, provider& provider_to_return) {
    if (!root) {
        return -1;
    }
    if (!root->right && !root->left) {
        char* check;
        root->current.retrieve_name(check);

        if (strcmp(check, name_to_get) == 0) {
            root->current.PopulateProvider(provider_to_return);
            return 1;
        }
    }
    return retrieve(root, name_to_get, provider_to_return);
}

int providers::retrieve(node* root, char* name, provider& provider_to_return) {

    if (!root) {
        return -1;
    }
    char* check;
    root->current.retrieve_name(check);

    if (strcmp(check, name) == 0) {
        root->current.PopulateProvider(provider_to_return);
        return 1;
    }

    int result = retrieve(root->right, name, provider_to_return);
    result = retrieve(root->left, name, provider_to_return);

    return result;
}

int provider::PopulateProvider(provider& toPop) {

    toPop.name = new char[strlen(name) + 1];
    strcpy(toPop.name, name);

    toPop.address = new char(strlen(address) + 1);
    strcpy(toPop.address, address);

    toPop.city = new char(strlen(city) + 1);
    strcpy(toPop.city, city);

    toPop.state = new char(strlen(state) + 1);
    strcpy(toPop.state, state);

    toPop.number = new char(strlen(number) + 1);
    strcpy(toPop.number, number);

    toPop.zip = new char(strlen(zip) + 1);
    strcpy(toPop.zip, zip);
    toPop.total_consults = total_consults;
    toPop.weekly_fee = weekly_fee;
    toPop.services = services;
    return 1;
}

void providers::LoadData()
{
    char temp_name[NAMESIZE];
    char temp_number[NUMBERSIZE];
    char temp_address[ADDRESSSIZE];
    char temp_city[CITYSIZE];
    char temp_state[STATESIZE];
    char temp_zip[ZIPSIZE];
    char filename[50] = "providers.txt";
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
        infile.get(temp_number, NUMBERSIZE, '#');
        infile.ignore();
        infile.get(temp_zip, ZIPSIZE, '#');
        infile.ignore();
        provider temp_provider;
        temp_provider.LoadProvider(temp_name, temp_address, temp_city, temp_state, temp_number, temp_zip); 
        insert(temp_provider);
        i++;
    }
    return;
}

int FileSize(char * filename)
{
    int fsize = 0;
    ifstream infile;
    infile.open(filename);
    if (!infile)
    {
        cerr <<"Failed to open " << filename << endl;
    }
    while (infile && !infile.eof())
    {
        infile.ignore(1000,'\n');
        infile.ignore();
        fsize++;
    }

    return fsize;
}

void provider::LoadProvider(char * temp_name, char * temp_address, char * temp_city, char * temp_state, char * temp_number, char * temp_zip)
{
    name = new char[strlen(temp_name)+1];
    strcpy(name, temp_name);
    number = new char[strlen(temp_number)+1];
    strcpy(number, temp_number);
    address = new char[strlen(temp_address)+1];
    strcpy(address, temp_address);
    city = new char[strlen(temp_city)+1];
    strcpy(city, temp_city);
    state = new char[strlen(temp_state)+1];
    strcpy(state, temp_state);
    uppercaser(state);
    zip = new char[strlen(temp_zip)+1];
    strcpy(zip, temp_zip);
    return;
}

/// <summary>
/// Deletes all providers nodes from the list. This method handles base cases
/// for an empty list and a single node and calls the recursive delete_all
/// for all other cases.
/// </summary>
/// <returns>number of nodes removed</returns>
int providers::delete_all() {

    // empty list
    if (!root) {
        return 0;
    }

    // single node
    if (!root->right && !root->left) {
        root->current.DeleteAllServices();
        delete root;
        root = NULL;
        return 1;
    }

    // all other cases
    return delete_all(root);
}

/// <summary>
/// Recursively Deletes all providers nodes withing the tree of records.
/// </summary>
/// <param name="root">pinter to providers list</param>
/// <returns>number of nodes removed</returns>
int providers::delete_all(node*& root) {
    if (!root) {
        return 0;
    }

    int count = 0;
    count += delete_all(root->right);
    count += delete_all(root->left);

    ++count;
    root->current.DeleteAllServices();
    delete root;
    root = NULL;

    return count;
}

void provider::CopyServiceList(provider*& dst) {
    CopyServiceList(services, dst->services);
}
void provider::CopyServiceList(service_node* src, service_node*& dst) {
    if (!src) {
        return;
    }

    dst = new service_node;
    dst->current_date = src->current_date;
    dst->service_date = src->service_date;
    dst->provider_number = src->provider_number;
    dst->member_number = src->member_number;
    dst->service_code = src->service_code;
    dst->service_name = src->service_name;
    dst->fee = src->fee;

    if (!src->next) dst->next = NULL;

    CopyServiceList(src->next, dst->next);
}

int provider::cp(provider& to_copy)
{
    name = new char[strlen(to_copy.name) + 1];
    address = new char[strlen(to_copy.address) + 1];
    city = new char[strlen(to_copy.city) + 1];
    state = new char[strlen(to_copy.state) + 1];
    zip = new char[strlen(to_copy.zip) + 1];
    number = new char[strlen(to_copy.number) + 1];
    strcpy(name, to_copy.name);
    strcpy(address, to_copy.address);
    strcpy(city, to_copy.city);
    strcpy(state, to_copy.state);
    strcpy(zip, to_copy.zip);
    strcpy(number, to_copy.number);

    if (to_copy.services == NULL) {
        services = NULL;
    }
    else {
        provider* t = this;
        to_copy.CopyServiceList(t);
    }
    return 0;
}

int providers::Remove(char* provNumber) {
    if (!root) {
        return 0;
    }
    if (!root->right && !root->left) {

        char* temp;
        root->current.retrieve_number(temp);

        if (strcmp(temp, provNumber) == 0) {
            root->current.DeleteAllServices();
            delete root;
            root = NULL;
            return 1;
        }
    }
}