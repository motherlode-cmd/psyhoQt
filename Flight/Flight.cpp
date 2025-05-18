#include "Flight.hpp"
Flight::Flight(QStringList &newValue) {
    number_of_flight  = newValue.at(0).toStdString();
    arrival_airport  = newValue.at(1).toStdString();
    departure_airport  = newValue.at(2).toStdString();
    airline = newValue.at(3).toStdString();
    departure_date = newValue.at(4).toStdString();
    departure_time = newValue.at(5).toStdString();
    number_of_seats = newValue.at(6).toInt();
    number_of_available_seats = newValue.at(7).toInt();
}

int Flight::get_key() {
    int result = 0;
    for(char c : number_of_flight) {
        if(isdigit(c)) {
            result *= 10;
            result += c - '0';
        }
    }
    return result;
}

std::string Flight::get_airline() {
    return airline;
}
std::string Flight::get_number_of_flight() {
    return number_of_flight;
}
std::string Flight::get_arrival_airport() {
    return arrival_airport;
}
std::string Flight::get_departure_airport() {
    return departure_airport;
}
std::string Flight::get_departure_date() {
    return departure_date;
}

std::string Flight::get_departure_time() {
    return departure_time;
}
int Flight::get_number_of_seats() {
    return number_of_seats;
}
int Flight::get_number_of_available_seats() {
    return number_of_available_seats;
}
void Flight::set_airline(std::string value) {
    airline = value;
}
void Flight::set_number_of_flight(std::string value) {
    number_of_flight = value;
}
void Flight::set_arrival_airport(std::string value) {
    arrival_airport = value;
}
void Flight::set_departure_airport(std::string value) {
    departure_airport = value;
}
void Flight::set_departure_date(std::string value) {
    departure_date = value;
}
void Flight::set_departure_time(std::string value) {
    departure_time = value;
}
