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

bool Event::operator<(const Event& other) const {
    return strcmp(matchDate, other.matchDate) < 0;
}

