#ifndef DEFINITION_H
#define DEFINITION_H

const int MAX_PROVIDER = 299999999;  // Upper bound for provider ID numbers

const int MAX_ID = 999999999;		 // MUST be less than 10 digits

const int MAX_NAME = 26;		// MUST be max of 25 characters
const int MAX_SVC_NAME = 21;    // MUST be max of 20 characters
const int MAX_CITY = 15;        // MUST be max of 14 characters
const int MAX_COMMENT = 101;	// MUST be max of 100 characters

const float MAX_FEE = 999.99;	// MUST be less than $999.99
const int MAX_SERVICE = 999999; // MUST be less than 7 digits
const int MAX_DATE = 11;		// MUST be MM-DD-YYYY format

const int NAMESIZE = 26;
const int NUMBERSIZE = 10;
const int ADDRESSSIZE = 26;
const int CITYSIZE = 15;
const int STATESIZE = 3;
const int ZIPSIZE = 6;
const int MMDDYY = 7;

const int comment = 100;


#endif
