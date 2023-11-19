#pragma once
#ifndef TICKET_H
#define TICKET_H

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
};

#endif 
