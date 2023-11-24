#include "Location.h"
#include <iostream>

using namespace std;

int Location::noOfStadiums = 1;

Location::Location() : id(noOfStadiums++) {
	stadiumName = new char[1];
	stadiumName[0] = '\0';
	capacity = 0;
}

Location::Location(const char* name, int cap) : id(noOfStadiums++) {
	stadiumName = new char[strlen(name) + 1];
	strcpy(stadiumName, name);
	capacity = cap;
}

Location::Location(const Location& other) : id(noOfStadiums++) {
	stadiumName = new char[strlen(other.stadiumName) + 1];
	strcpy(stadiumName, other.stadiumName);
	capacity = other.capacity;
}

Location::~Location() {
	delete[] stadiumName;
}

void Location::setStadiumName(const char* name) {
	if (name != nullptr) {
		delete[] stadiumName;
		stadiumName = new char[strlen(name) + 1];
		strcpy(stadiumName, name);
	}
}

const char* Location::getStadiumName() const {
	return stadiumName;
}

void Location::setCapacity(int cap) {
	if (cap >= 0) {
		capacity = cap;
	}
	else {
		throw exception("Capacity has to be a positive number");
	}
}

int Location::getCapacity() const {
	return capacity;
}

int Location::getId() const {
	return id;
}

int Location::getNoOfStadiums() {
	return noOfStadiums;
}

bool operator>=(const Location& firstLocation, const Location& secondLocation) {
	return firstLocation.getCapacity() >= secondLocation.getCapacity();
}

int operator-(const Location& first, const Location& second) {
	return first.capacity - second.capacity;
}

ostream& operator<<(ostream& os, const Location& loc) {
	os << "Stadium Name: " << loc.getStadiumName() << ", Capacity: " << loc.getCapacity() << ", ID: " << loc.getId();
	return os;
}

istream& operator>>(istream& is, Location& loc) {
	char tempName[100];
	int tempCapacity;
	cout << "Enter Stadium Name: ";
	if (is.peek() == '\n') {
		is.ignore();
	}
	is.getline(tempName, 100);

	while (true) {
		cout << "Enter Capacity: ";
		is >> tempCapacity;
		try {
			loc.setCapacity(tempCapacity);
			break; 
		}
		catch (const exception& e) {
			cout << "Input error: " << e.what() << endl;
			is.clear();
			is.ignore(numeric_limits<streamsize>::max(), '\n');
		}		
	}

	loc.setStadiumName(tempName);
	

	return is;
}
