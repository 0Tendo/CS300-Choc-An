#include <iostream>
#include "BasicDefinition.h"

struct Service
{
    char* service_name;
	int service_code;
	char* provided_date;
	char* logged_date;
	int memberID;
	int providerID;
	float service_fee;
	char* comments;
};

class Service
{
public:
	Service();
	getService();
	Service(char* se_name, int code, char* pr_date, char* lo_date, int memID, int proID, float fee, char * se_comments);
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
