#include "members.h"
using namespace std;

//Ethan Saftler, Ryan Tran, Cristian Torres Salazar, Matthew Marcellinus, Yuxin Sun, Chentao Ma

//CS300 Term Project - PSU Winter 2022
//Chocoholics Service Terminal Software



int main()
{
	//variables
	char selection = '0';
	char quit = 'a';
	provider * temp_provider = new provider;
	providers * temp_providers = new providers;
	tree* new_tree=new tree;
	int check = 0;

	//welcome message
	cout << "\n\nWelcome to the ChocAn Terminal Manager\n\n\n";

	//while loop for main menu using switch statement for selection
	while (selection != 'Z')
	{
		cout << endl << endl << endl << endl << endl << endl;
		cout << "Chocoholics Anonymous Manager Terminal\n\n";
		cout << "*** Main Menu *** \n";
		cout << "(Make a selection)\n";
		cout << "	1 - Select member by number (Slide member card)\n";
		cout << "	2 - Add service for selected member (Bill ChocAn)\n";
		cout << "	3 - Request Provider Directory\n";
		cout << "	4 - Run weekly report\n";
		cout << "	5 - Add Member\n";
		cout << "	6 - Delete Member\n";
		cout << "	7 - Add Provider\n";
		cout << "	8 - Delete Provider\n";
		cout << "	E - Exit\n ";

		cin >> selection;
		cin.ignore(100, '\n');
		switch(selection)
		{
			case '1':
				//insert case for adding new member here
				//TODO - select current member 
				cout << "\n\nPress enter to return to the main menu...\n";
				cin.get(); 
				break;
			case '2':
				//TODO - add service
				cout << "\n\nPress enter to return to the main menu...\n";
				cin.get(); 
				break;
			case '3':	
				temp_providers->display_all();
				cout << "\n\nPress enter to return to the main menu...\n";
				cin.get(); 
				break;
			case '4':	
				//TODO - display weekly report
				cout << "\n\nPress enter to return to the main menu...\n";
				cin.get(); 
				break;
			case '5':
			{
				member*new_member=new member;
                new_member->create_member();
				new_tree->insert(new_member);
				new_tree->display();
				cout << "\n\nPress enter to return to the main menu...\n";
				cin.get(); 
			}
				break;
			case '6':	
				{
					char * name_todelete;
					cout<<"Please enter the member name you want to delete.\n";
					char temp_name[NAMESIZE];
					cin.get(temp_name, NAMESIZE, '\n');
    				cin.ignore(100, '\n');
					name_todelete = new char[strlen(temp_name)+1];
   				    strcpy(name_todelete, temp_name);
					new_tree->remove(name_todelete);
				}
				cout << "\n\nPress enter to return to the main menu...\n";
				cin.get(); 
				break;
			case '7':
				//TODO - add function to stow data in file
				temp_provider->create();
				check = temp_provider->check_format();
				if (check == 1)
				temp_providers->insert(*temp_provider);
				else{
					cout << "\nIncorrect Info. Provider was not added.";
				}
				cout << "\n\nPress enter to return to the main menu...\n";
				cin.get(); 
				break;
			case '8':
				//TODO - delete provider
				break;
			case 'E':
				cout << endl << "Are you sure you would like to quit?" << endl;
				cout << "Enter 'Y' to quit or any other key to return to the main menu." << endl;
				cin >> quit;
				cin.ignore(100, '\n');
				if ( quit == 'Y' || quit == 'y' )
				{
					selection = 'Z';
				}
				break;
			case 'e':		
				cout << endl << "Are you sure you would like to quit?" << endl;
				cout << "Enter 'Y' to quit or any other key to return to the main menu." << endl;
				cin >> quit;
				cin.ignore(100, '\n');
				if ( quit == 'Y' || quit == 'y' )
				{
					selection = 'Z';
				}
				break;
			case 'Z':
				cerr << "Invalid response.";
				selection = '0';
				break;
			default:
				cerr << "Invalid response.";
				break;
		}


	}

	return 0;
}






		
