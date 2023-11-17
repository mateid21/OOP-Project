#include "Location.h"
#include <iostream>

using namespace std;

int main() {

    //Testing Location class functions
    Location l1;
    cout << "Location created with ID: " << l1.getId() << endl;
    cout << endl;

    Location stadium("Arena Nationala", 50000);
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
    cout << endl;

    cout << endl;
    return 0;
}
