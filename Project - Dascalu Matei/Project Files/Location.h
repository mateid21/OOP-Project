#pragma once
#ifndef LOCATION_H
#define LOCATION_H

class Location {
private:
    char* stadiumName;
    int capacity;
    const int id;
    static int noOfStadiums;

public:
    Location();
    Location(const char* name, int cap);
    Location(const Location& other);
    Location& operator=(const Location& other);
    ~Location();

    void setStadiumName(const char* name);
    const char* getStadiumName() const;
    void setCapacity(int cap);
    int getCapacity() const;
    int getId() const;
    static int getNoOfStadiums();

    friend bool operator>=(const Location& firstLocation, const Location& secondLocation);
    friend int operator-(const Location& first, const Location& second);
};

#endif

