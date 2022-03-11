#include <iostream>
#include "BasicDefinition.h"



const int comment = 100;
const int MMDDYY = 7;
const int NAMESIZE = 7;

class Service
{
public:
	Service();
	int getService();
	Service(const Service* To_Add);
	~Service();

	int display();
    char* getName();
	int getServiceID();
	char* getProvidedDate();
	char* getLoggedDate();
	int getMemberID();
	int getProviderID();
	float getFee();
	char* getComments();

protected:
	char* service_name;
	int service_code;
	char* provided_date;
	char* logged_date;
	int memberID;
	int providerID;
	float service_fee;
	char* comments;
};
