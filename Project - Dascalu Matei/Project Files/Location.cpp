#include "Location.h"
#include <iostream>

using namespace std;

int Location::noOfStadiums = 0;

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
