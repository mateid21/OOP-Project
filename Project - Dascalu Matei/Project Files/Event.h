#pragma once
#ifndef EVENT_H
#define EVENT_H
#include <iostream>

using namespace std;

class Event {
private:
    char* matchName;  
    char* matchDate;//(YYYY-MM-DD)
    char* teams[2];    

public:
    Event();
    Event(const char* name, const char* date, const char* team1, const char* team2);
    Event(const Event& other); 
    ~Event();

    const char* getMatchName() const;
    const char* getMatchDate() const;
    const char* getTeam(int index) const;

    void setMatchName(const char* name);
    void setMatchDate(const char* date);
    void setTeam(int index, const char* teamName);

    friend bool operator<(const Event& ev1, const Event& ev2);
    friend bool operator==(const Event& ev1, const Event& ev2);
    friend ostream& operator<<(ostream& os, const Event& event);
    friend istream& operator>>(istream& is, Event& event);

private:
    void copyTeams(char* const teams[2]);
    void clearTeams();
    bool isDateValid(const char* date);
};

#endif 
