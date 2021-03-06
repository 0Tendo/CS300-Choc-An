#include <iostream>
#include "BasicDefinition.h"



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
