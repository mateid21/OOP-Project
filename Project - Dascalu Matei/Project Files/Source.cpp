#include "Location.h"
#include "Event.h"
#include "Ticket.h"
#include <iostream>

using namespace std;

void testLocationClass() {
	//Testing Location class functions

	Location stadium;
	cout << "Enter details for a new stadium (name and capacity) " << endl;
	cin >> stadium;
	cout << endl;
	cout << "Stadium created: " << endl << stadium << endl;
	cout << endl;

	//changing attributes
	cout << "Enter NEW details for the stadium (name and capacity) ";
	cout << endl;
	cin >> stadium;
	cout << endl;

	cout << "Updated details of stadium: " << endl << stadium << endl;
	cout << endl;

	//getNoOfStadiums()
	cout << "Total Number of stadiums created: " << Location::getNoOfStadiums() << endl;
	cout << endl;

	//>=op
	Location stadium2("San Siro", 80018);
	cout << stadium2;
	cout << endl;

	if (stadium >= stadium2) {
		cout << stadium.getStadiumName() << "(" << stadium.getCapacity() << ")" << " has a capacity greater than or equal to "
			<< stadium2.getStadiumName() << "(" << stadium2.getCapacity() << ")" << endl;
	}
	else {
		cout << stadium.getStadiumName() << "(" << stadium.getCapacity() << ")" << " has a smaller capacity than "
			<< stadium2.getStadiumName() << "(" << stadium2.getCapacity() << ")" << endl;
	}
	cout << endl;

	//-op
	cout << "Capacity difference between " << stadium2.getStadiumName() << " and " << stadium.getStadiumName() << ": " << stadium2 - stadium << " seats" << endl;
}

void testEventClass() {
	Event footballMatch;
	cout << "Enter details for a football match (Match Name, Date, Team 1, Team 2): " << endl;
	cin >> footballMatch;  //operator>> 
	cout << endl;

	cout << "Football Match Details Entered: " << endl << footballMatch << endl;  //operator<< 
	cout << endl;

	//checking if an event happens before or after a different event with <operator
	Event match2("Match 2", "2022-01-24", "Team A", "Team B");
	cout << match2 << endl;
	cout << "Match 1: " << footballMatch.getMatchDate() << "; ";
	cout << "Match 2: " << match2.getMatchDate();
	cout << endl;
	if (footballMatch < match2) {
		cout << "Match 1 occurs before Match 2" << endl;
	}
	else {
		cout << "Match 1 occurs after Match 2" << endl;
	}
	cout << endl;

	//==operator checking if two events are the same
	Event match3("Match 3", "2022-01-25", "Team C", "Team D");
	cout << match3 << endl;
	if (footballMatch == match2) {
		cout << "Match 1 and Match 2 are the same." << endl;
	}
	else {
		cout << "Match 1 and Match 2 are different." << endl;
	}

	if (footballMatch == match3) {
		cout << "Match 1 and Match 3 are the same." << endl;
	}
	else {
		cout << "Match 1 and Match 3 are different." << endl;
	}
}

void testTicketClass() {
	// Testing Ticket class functions
	int seats[] = { 12, 13, 14 };
	Ticket ticket1(100.0, 5, seats, 3);

	// ticket details
	cout << ticket1;
	cout << endl;

	// modify ticket attributes
	cout << "Modifying ticket price and row... " << endl;
	ticket1.setPrice(150.0);
	ticket1.setRow(3);
	int newSeats[] = { 15, 16, 17 };
	ticket1.setSeatNumbers(newSeats, 3);

	// display updated ticket details
	cout << ticket1;
	cout << endl;

	//create a second ticket
	Ticket ticket2;
	cin >> ticket2;
	cout << ticket2<<endl;
	cout << endl;

	//+op and =op
	Ticket combinedTicket = ticket1 + ticket2;

	// display details of the combined ticket
	cout << combinedTicket;
	cout << endl << endl;
}

void showMenu() {
	cout << endl;
	cout << "Ticketing Menu" << endl;
	cout << "1. Test Location Class" << endl;
	cout << "2. Test Event Class" << endl;
	cout << "3. Test Ticket Class" << endl;
	cout << "4. Exit" << endl;
	cout << "Enter your choice: ";
	cout << endl;
}

int main() {
	int choice;

	do {
		showMenu();
		cin >> choice;

		switch (choice) {
		case 1:
			testLocationClass();
			break;
		case 2:
			testEventClass();
			break;
		case 3:
			testTicketClass();
			break;
		case 4:
			cout << "Exiting program..." << endl;
			break;
		default:
			cout << "Invalid choice. Please try again." << endl;
		}
	} while (choice != 4);

	return 0;
}
