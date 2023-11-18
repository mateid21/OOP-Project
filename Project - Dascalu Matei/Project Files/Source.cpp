#include "Location.h"
#include "Event.h"
#include <iostream>

using namespace std;

void testLocationClass() {
    //Testing Location class functions
    Location l1;
    cout << "Location created with ID: " << l1.getId() << endl;
    cout << endl;

    Location stadium("Camp Nou", 50000);
    cout << "Stadium created with ID: " << stadium.getId() << endl;
    cout << endl;

    //changing attributes
    cout << "Initial Details of stadium:" << endl;
    cout << "Name: " << stadium.getStadiumName() << endl;
    cout << "Capacity: " << stadium.getCapacity() << endl;

    stadium.setStadiumName("Stamford Bridge");
    stadium.setCapacity(55000);

    cout << "Updated details of stadium:" << endl;
    cout << "Name: " << stadium.getStadiumName() << endl;
    cout << "Capacity: " << stadium.getCapacity() << endl;
    cout << endl;

    //trying to set an invalid value to capacity
    stadium.setCapacity(-100);
    cout << "Attempted to set negative capacity. Current capacity: " << stadium.getCapacity() << endl;
    cout << endl;

    //getNoOfStadiums()
    cout << "Total Number of stadiums created: " << Location::getNoOfStadiums() << endl;
    cout << endl;

    //>=
    Location stadium2("San Siro", 80018);
    if (stadium >= stadium2) {
        cout << stadium.getStadiumName() << "(" << stadium.getCapacity() << ")" << " has a capacity greater than or equal to "
            << stadium2.getStadiumName() << "(" << stadium2.getCapacity() << ")" << endl;
    }
    else {
        cout << stadium.getStadiumName() << "(" << stadium.getCapacity() << ")" << " has a smaller capacity than "
            << stadium2.getStadiumName() << "(" << stadium2.getCapacity() << ")" << endl;
    }
    cout << endl;

    //-
    cout << "Capacity difference between " << stadium2.getStadiumName() << " and " << stadium.getStadiumName() << ": " << stadium2 - stadium << " seats" << endl;
}

void testEventClass(){
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
}

int main() {

    testLocationClass();
    cout << endl;
    cout << "-------------------------------------------------------------------------------" << endl;
    cout << endl;
    testEventClass();
    cout << endl;
    cout << "-------------------------------------------------------------------------------" << endl;

    return 0;
}
