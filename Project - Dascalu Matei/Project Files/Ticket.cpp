#include "Ticket.h"
#include <iostream>

int Ticket::ticketNumber = 0;

Ticket::Ticket() :ticketId(++ticketNumber) {
	price = 0.0;
	row = 0;
	seatNumbers = nullptr;
	seatCount = 0;
}

Ticket::Ticket(double cost, int r, const int* seats, int count) :ticketId(++ticketNumber) {
	price = cost;
	row = r;
	seatCount = count;
	seatNumbers = new int[count];
	for (int i = 0; i < count; ++i) {
		seatNumbers[i] = seats[i];
	}
}

Ticket::Ticket(const Ticket& other) :ticketId(++ticketNumber) {
	price = other.price;
	row = other.row;
	seatCount = other.seatCount;
	seatNumbers = new int[seatCount];
	for (int i = 0; i < seatCount; ++i) {
		seatNumbers[i] = other.seatNumbers[i];
	}
}

Ticket::~Ticket() {
	delete[] seatNumbers;
}


int Ticket::getTicketId() const {
	return ticketId;
}

double Ticket::getPrice() const {
	return price;
}

int Ticket::getRow() const {
	return row;
}

const int* Ticket::getSeatNumbers() const {
	return seatNumbers;
}

int Ticket::getSeatCount() const {
	return seatCount;
}


void Ticket::setPrice(double cost) {
	price = cost;
}

void Ticket::setRow(int r) {
	row = r;
}

void Ticket::setSeatNumbers(const int* seats, int count) {
	delete[] seatNumbers;
	seatNumbers = new int[count];
	seatCount = count;
	for (int i = 0; i < count; ++i) {
		seatNumbers[i] = seats[i];
	}
}

Ticket& Ticket::operator=(const Ticket& other) {
	if (this != &other) {
		price = other.price;
		row = other.row;
		seatCount = other.seatCount;
		ticketId = ++ticketNumber;

		delete[] seatNumbers;
		seatNumbers = new int[seatCount];
		for (int i = 0; i < seatCount; ++i) {
			seatNumbers[i] = other.seatNumbers[i];
		}
	}
	return *this;
}

Ticket Ticket::operator+(const Ticket& other) const {
	int newCount = seatCount + other.seatCount;
	int* newSeats = new int[newCount];

	for (int i = 0; i < seatCount; ++i) {
		newSeats[i] = seatNumbers[i];
	}

	for (int i = 0; i < other.seatCount; ++i) {
		newSeats[seatCount + i] = other.seatNumbers[i];
	}

	return Ticket(price + other.price, (row + other.row) / 2, newSeats, newCount);
}

ostream& operator<<(ostream& os, const Ticket& ticket) {
	os << "Ticket created with ID: " << ticket.getTicketId() << "\n";
	os << "Price: $" << ticket.getPrice() << ", Row: " << ticket.getRow() << ", Seat Count: " << ticket.getSeatCount() << ", Seats: ";
	for (int i = 0; i < ticket.getSeatCount(); ++i) {
		os << ticket.getSeatNumbers()[i] << (i < ticket.getSeatCount() - 1 ? ", " : "");
	}
	os << "\n";
	return os;
}

istream& operator>>(istream& is, Ticket& ticket) {
	double price;
	int row, seatCount;

	cout << "Creating a new ticket" << endl;
	cout << "Enter price: ";
	is >> price;
	ticket.setPrice(price);

	cout << "Enter row: ";
	is >> row;
	ticket.setRow(row);

	cout << "Enter seat count: ";
	is >> seatCount;
	int* seats = new int[seatCount];
	cout << "Enter seat numbers: ";
	for (int i = 0; i < seatCount; ++i) {
		is >> seats[i];
	}
	ticket.setSeatNumbers(seats, seatCount);

	delete[] seats; 

	return is;
}
