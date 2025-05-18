#ifndef FLIGHT
#define FLIGHT
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <QStringList>
class Flight {
private:
    std::string airline;
    std::string number_of_flight;
    std::string arrival_airport;
    std::string departure_airport;
    std::string departure_date;
    std::string departure_time;
    int number_of_seats;
    int number_of_available_seats;

public:
    Flight() = default;
    Flight(QStringList & newValue);
    ~Flight() = default;
    int get_key();
    std::string get_airline();
    std::string get_number_of_flight();
    std::string get_arrival_airport();
    std::string get_departure_airport();
    std::string get_departure_date();
    std::string get_departure_time();
    int get_number_of_seats();
    int get_number_of_available_seats();
    void set_airline(std::string value);
    void set_number_of_flight(std::string value);
    void set_arrival_airport(std::string value);
    void set_departure_airport(std::string value);
    void set_departure_date(std::string value);
    void set_departure_time(std::string value);
};
#endif
