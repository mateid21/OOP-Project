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
	// Testing Event class functions
	Event footballMatch("El Clasico", "2024-03-02", "Real Madrid", "Barcelona");

	cout << "Football Match: " << footballMatch.getMatchName() << endl;
	cout << "Date: " << footballMatch.getMatchDate() << endl;
	cout << "Team 1: " << footballMatch.getTeam(0) << endl;
	cout << "Team 2: " << footballMatch.getTeam(1) << endl;
	cout << endl;

	// change the date of the match
	footballMatch.setMatchDate("2023-03-03");

	// display updated details
	cout << "Updated Match Details: " << endl;
	cout << "Football Match: " << footballMatch.getMatchName() << endl;
	cout << "New Date: " << footballMatch.getMatchDate() << endl;
	cout << "Team 1: " << footballMatch.getTeam(0) << endl;
	cout << "Team 2: " << footballMatch.getTeam(1) << endl;
	cout << endl;

	// attempting to set an invalid date format
	cout << "Attempting to set an invalid date format..." << endl;
	try {
		footballMatch.setMatchDate("03-03-2023");
	}
	catch (const exception& e) {
		cout << e.what() << endl;
	}
	cout << endl;

	//<checking if an event happens before or after a different event with <operator
	Event match1("Match 1", "2022-01-25", "Team A", "Team B");
	Event match2("Match 2", "2022-01-24", "Team C", "Team D");
	cout << "Match 1: " << match1.getMatchDate() << "; ";
	cout << "Match 2: " << match2.getMatchDate();
	cout << endl;
	if (match1 < match2) {
		cout << "Match 1 occurs before Match 2" << endl;
	}
	else {
		cout << "Match 1 occurs after Match 2" << endl;
	}
	cout << endl;

	//==operator checking if two events are the same
	Event match3("Match 1", "2022-01-25", "Team A", "Team B");

	if (match1 == match2) {
		cout << "Match 1 and Match 2 are the same." << endl;
	}
	else {
		cout << "Match 1 and Match 2 are different." << endl;
	}

	if (match1 == match3) {
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
	cout << "Ticket created with ID: " << ticket1.getTicketId() << endl;
	cout << "Price: $" << ticket1.getPrice() << ", Row: " << ticket1.getRow() << ", Seats: ";
	const int* ticketSeats = ticket1.getSeatNumbers();
	for (int i = 0; i < ticket1.getSeatCount(); i++) {
		cout << ticketSeats[i] << (i < ticket1.getSeatCount() - 1 ? ", " : "");
	}
	cout << endl << endl;

	// modify ticket attributes
	cout << "Modifying ticket price and row... " << endl;
	ticket1.setPrice(150.0);
	ticket1.setRow(3);
	int newSeats[] = { 15, 16, 17 };
	ticket1.setSeatNumbers(newSeats, 3);

	// display updated ticket details
	cout << "Updated Ticket Details: " << endl;
	cout << "Price: $" << ticket1.getPrice() << ", Row: " << ticket1.getRow() << ", Seats: ";
	ticketSeats = ticket1.getSeatNumbers();
	for (int i = 0; i < ticket1.getSeatCount(); i++) {
		cout << ticketSeats[i] << (i < ticket1.getSeatCount() - 1 ? ", " : "");
	}
	cout << endl;
	cout << endl;

	//create a second ticket
	int seats2[] = { 4, 5, 6 };
	Ticket ticket2(60.0, 6, seats2, 3);

	//+op and =op
	Ticket combinedTicket = ticket1 + ticket2;

	// display details of the combined ticket
	cout << "Combined Ticket created with ID: " << combinedTicket.getTicketId() << endl << "Price: $" << combinedTicket.getPrice()
		<< ", Row: " << combinedTicket.getRow() << ", Seats: ";
	const int* combinedSeats = combinedTicket.getSeatNumbers();
	for (int i = 0; i < combinedTicket.getSeatCount(); i++) {
		cout << combinedSeats[i] << (i < combinedTicket.getSeatCount() - 1 ? ", " : "");
	}
	cout << endl << endl;
}

int main() {

	testLocationClass();
	cout << endl;
	cout << "-------------------------------------------------------------------------------" << endl;
	cout << endl;
	testEventClass();
	cout << endl;
	cout << "-------------------------------------------------------------------------------" << endl;
	cout << endl;
	testTicketClass();
	cout << endl;


	return 0;
}
