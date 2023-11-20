#pragma once
#ifndef EVENT_H
#define EVENT_H

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
    bool operator<(const Event& other) const;

private:
    void copyTeams(char* const teams[2]);
    void clearTeams();
    bool isDateValid(const char* date);
};

#endif 
