#pragma once
#ifndef TICKET_H
#define TICKET_H
#include <iostream>

using namespace std;

class Ticket {
private:
    static int ticketNumber;
    int ticketId;
    double price;
    int row;
    int* seatNumbers;
    int seatCount;

public:
    Ticket();
    Ticket(double cost, int row, const int* seats, int count);
    Ticket(const Ticket& other);
    ~Ticket();

    int getTicketId() const;
    double getPrice() const;
    int getRow() const;
    const int* getSeatNumbers() const;
    int getSeatCount() const;

    void setPrice(double cost);
    void setRow(int row);
    void setSeatNumbers(const int* seats, int count);

    Ticket& operator=(const Ticket& other);
    Ticket operator+(const Ticket& other) const;
    friend ostream& operator<<(ostream& os, const Ticket& ticket);
    friend istream& operator>>(istream& is, Ticket& ticket);

};

#endif 
