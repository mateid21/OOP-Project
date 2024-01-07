#include "Ticket.h"
#include <iostream>
#include <fstream>

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
	if (cost < 0.0) {
		throw exception("Price cannot be negative.");
	}
	else {
		price = cost;
	}
}

void Ticket::setRow(int r) {
	if (r <= 0) {
		throw exception("Row number must be positive.");
	}
	else {
		row = r;
	}
}

void Ticket::setSeatNumbers(const int* seats, int count) {
	for (int i = 0; i < count; ++i) {
		if (seats[i] <= 0) {
			throw exception("Seat numbers must be positive.");
		}
		for (int j = i + 1; j < count; ++j) {
			if (seats[i] == seats[j]) {
				throw exception("Duplicate seat numbers are not allowed.");
			}
		}
	}
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

	
	while (true) {
		cout << "Enter price: ";
		is >> price;
		try {
			ticket.setPrice(price);
			break;
		}
		catch (const exception& e) {
			cout << "Input error: " << e.what() << endl;
			is.clear();
			is.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}


	while (true) {
		cout << "Enter row: ";
		is >> row;
		try {
			ticket.setRow(row);
			break;
		}
		catch (const exception& e) {
			cout << "Input error: " << e.what() << endl;
			is.clear();
			is.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}

	while (true) {
		cout << "Enter seat count: ";
		if (is >> seatCount && seatCount>0) {
			int* seats = new int[seatCount];
			cout << "Enter seat numbers: ";
			for (int i = 0; i < seatCount; ++i) {
				is >> seats[i];
			}
			try {
				ticket.setSeatNumbers(seats, seatCount);
				delete[] seats;
				break;
			}
			catch (const exception& e) {
				cout << "Input error: " << e.what() << endl;
				is.clear();
				is.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}
		else {
			cout << "Seat count must be a positive number." << endl;
			is.clear();
			is.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}

	return is;
}

void Ticket::serialize(ofstream& out) const {
	out.write(reinterpret_cast<const char*>(&ticketId), sizeof(ticketId));
	out.write(reinterpret_cast<const char*>(&price), sizeof(price));
	out.write(reinterpret_cast<const char*>(&row), sizeof(row));
	out.write(reinterpret_cast<const char*>(&seatCount), sizeof(seatCount));
	out.write(reinterpret_cast<const char*>(seatNumbers), seatCount * sizeof(int));
}

void Ticket::deserialize(ifstream& in) {
	in.read(reinterpret_cast<char*>(&ticketId), sizeof(ticketId));
	in.read(reinterpret_cast<char*>(&price), sizeof(price));
	in.read(reinterpret_cast<char*>(&row), sizeof(row));
	in.read(reinterpret_cast<char*>(&seatCount), sizeof(seatCount));

	delete[] seatNumbers;
	seatNumbers = new int[seatCount];
	for (int i = 0; i < seatCount; i++) {
		in.read(reinterpret_cast<char*>(&seatNumbers[i]), sizeof(seatNumbers[i]));
	}
}

