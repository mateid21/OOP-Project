#include "Event.h"
#include <iostream>

using namespace std;

Event::Event() {
    matchName = nullptr;
    matchDate = nullptr;
    teams[0] = nullptr;
    teams[1] = nullptr;
}

Event::Event(const char* name, const char* date, const char* team1, const char* team2) {
    if (!isDateValid(date)) {
        throw exception("Date does not respect the YYYY-MM-DD format");
    }

    matchName = new char[strlen(name) + 1];
    strcpy(matchName, name);

    matchDate = new char[strlen(date) + 1];
    strcpy(matchDate, date);

    teams[0] = new char[strlen(team1) + 1];
    strcpy(teams[0], team1);

    teams[1] = new char[strlen(team2) + 1];
    strcpy(teams[1], team2);
}

Event::Event(const Event& other) {
    matchName = new char[strlen(other.matchName) + 1];
    strcpy(matchName, other.matchName);

    matchDate = new char[strlen(other.matchDate) + 1];
    strcpy(matchDate, other.matchDate);

    copyTeams(other.teams);
}

Event::~Event() {
    delete[] matchName;
    delete[] matchDate;
    clearTeams();
}

void Event::copyTeams(char* const sourceTeams[2]) {
    for (int i = 0; i < 2; ++i) {
        if (sourceTeams[i] != nullptr) {
            teams[i] = new char[strlen(sourceTeams[i]) + 1];
            strcpy(teams[i], sourceTeams[i]);
        }
        else {
            teams[i] = nullptr;
        }
    }
}

void Event::clearTeams() {
    for (int i = 0; i < 2; ++i) {
        delete[] teams[i];
    }
}

void Event::setMatchName(const char* name) {
    delete[] matchName;
    matchName = new char[strlen(name) + 1];
    strcpy(matchName, name);
}

void Event::setMatchDate(const char* date) {
    if (!isDateValid(date)) {
        throw exception("Date does not respect the YYYY-MM-DD format");
    }
    delete[] matchDate;
    matchDate = new char[strlen(date) + 1];
    strcpy(matchDate, date);
}

void Event::setTeam(int index, const char* teamName) {
    if (index >= 0 && index < 2) {
        delete[] teams[index];
        teams[index] = new char[strlen(teamName) + 1];
        strcpy(teams[index], teamName);
    }
}

const char* Event::getMatchName() const {
    return matchName;
}

const char* Event::getMatchDate() const {
    return matchDate;
}

const char* Event::getTeam(int index) const {
    return index >= 0 && index < 2 ? teams[index] : nullptr;
}

bool Event::isDateValid(const char* date) {
    if (strlen(date) != 10) return false;

    for (int i = 0; i < 10; ++i) {
        if (i == 4 || i == 7) {
            if (date[i] != '-') return false;
        }
        else {
            if (!isdigit(date[i])) return false;
        }
    }

    return true;
}

bool operator<(const Event& ev1, const Event& ev2) {
    return strcmp(ev1.matchDate, ev2.matchDate) < 0;
}

bool operator==(const Event& ev1, const Event& ev2) {
    return strcmp(ev1.matchName, ev2.matchName) == 0 &&
        strcmp(ev1.matchDate, ev2.matchDate) == 0 &&
        strcmp(ev1.teams[0], ev2.teams[0]) == 0 &&
        strcmp(ev1.teams[1], ev2.teams[1]) == 0;
}

ostream& operator<<(ostream& os, const Event& event) {
    os << "Match Name: " << event.getMatchName() <<endl
        <<"Date: " << event.getMatchDate() << ", Team 1: " << event.getTeam(0) << ", Team 2: " << event.getTeam(1) << endl;
    return os;
}

istream& operator>>(istream& is, Event& event) {
    char name[100], date[11], team1[50], team2[50];

    is.clear();
    is.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter Match Name: ";
    is.getline(name, 100);

    while (true) {
        cout << "Enter Date (YYYY-MM-DD): ";
        is.getline(date, 11);
        try
        {
            event.setMatchDate(date);
            break;
        }
        catch (const exception& e)
        {
            cout << "Input error: " << e.what() << endl;
        }
    }

    cout << "Enter Team 1: ";
    is.getline(team1, 50);

    cout << "Enter Team 2: ";
    is.getline(team2, 50);

    event.setMatchName(name);
    event.setTeam(0, team1);
    event.setTeam(1, team2);

    return is;
}