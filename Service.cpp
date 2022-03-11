//Record and output single service
#include <cstring>
#include "Service.h"

Service::Service()
{
	service_name = NULL;
	service_code = 0;
	provided_date = NULL;
	logged_date = NULL;
	memberID = 0;
	providerID = 0;
	service_fee = 0.0;
	comments = NULL;
}

Service::Service(char* se_name, int code, char* pr_date, char* lo_date, int memID, int proID, float fee, char * se_comments) {

    service_name = new char[MAX_NAME];
    strcpy(service_name, se_name);

    if (code <= 0 || code > MAX_SERVICE ) {
        service_code = 0;
    } 
    else 
        service_code = code;

    provided_date = new char[MAX_DATE];
    strcpy(provided_date, pr_date);
    /* ToDo Check_data */
    logged_date = new char[MAX_DATE];
    strcpy(logged_date, lo_date);
    /* ToDo Check_data */

    if (proID <= 0 || proID > MAX_ID) {
        providerID = 0;
    } 
    else 
        providerID = proID;

    if (memID <= 0 || memID > MAX_ID) {
        memberID = 0;
    } 
    else 
        memberID = memID;

    if (fee > MAX_FEE || fee <= 0) {
        service_fee = 0.0;
    }
	else 
        service_fee = fee;

	comments = new char[MAX_COMMENT];
	strcpy(comments, se_comments);
}



Service::~Service()
{
	if (service_name)
		delete [] service_name;
	if (provided_date)
		delete [] provided_date;
	if (logged_date)
		delete [] logged_date;
	if (comments)
		delete [] comments;
}

int Service::getService()
{
	char* se_name;
	int code;
	char* pr_date;
	char* lo_date;
	int memID;
	int proID;
	float fee;
	char * se_comments;

	std::cout << "Service ID: " << std::endl;
	std::cin >> code;

	/*se_name = */           //ID matches name 

	std::cout << "Date Provided: " << std::endl;
	std::cin.get(pr_date, 12);

	std::cout << "Date Logged: " << std::endl;
	std::cin.get(lo_date, 12);

	std::cout << "Provider ID: " << std::endl;
	std::cin >> proID;

	/*fee = */              //ID matches  fee
	
	std::cout << "\nWould you like to record comments on this service? Y/N\n";
	if ("Y") {
		do {
			std::cout << "\nEnter your comments (" << MAX_COMMENT - 1 << " characters max)\n";
			std::cin >> se_comments;
			if (strlen(se_comments) > MAX_COMMENT - 1) {
				std::cout << "Comment too long.\n";
			}
		} while (strlen(se_comments) > MAX_COMMENT - 1);
	}
	Service(se_name, code, pr_date, lo_date, memID, proID, fee, se_comments);
	display();
}

int Service::display()
{
	if (!service_name)
		return -1;

	std::cout << "Service Name: " << service_name << std::endl;
	std::cout << "Service ID: " << service_code << std::endl;
	std::cout << "Date Provided: " << provided_date << std::endl;
	std::cout << "Date Logged: " << logged_date << std::endl;
	std::cout << "Member ID: " << memberID << std::endl;
	std::cout << "Provider ID: " << providerID << std::endl;
	std::cout << "Fee: " << service_fee << std::endl;
	std::cout << "Comments: " << comments << std::endl << std::endl;

	return 0;
}

char* Service::getName(){ return service_name; }
int Service::getServiceID(){ return service_code; }
char* Service::getProvidedDate(){ return provided_date; }
char* Service::getLoggedDate(){ return logged_date; }
int Service::getMemberID(){ return memberID; }
int Service::getProviderID(){ return providerID; }
float Service::getFee(){ return service_fee; }
char* Service::getComments(){ return comments; }
