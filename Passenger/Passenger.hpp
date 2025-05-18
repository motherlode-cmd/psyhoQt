#ifndef PASSENGER
#define PASSENGER
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <QStringList>
class Passenger {
private:
    std::string passport_number;
    std::string date_place_issue;
    std::string name;
    std::string date_of_birth;
    int is_default = 1;
public:
    Passenger() = default;
    Passenger(QStringList & list);
    ~Passenger() = default;
    std::string & get_key();
    std::string & get_passport_num();
    std::string & get_name();
    std::string & get_date_of_birth();
    std::string & get_date_place_issue();
    void set_date_place_issue(std::string & value);
    void set_passport_num(std::string & value);
    void set_name(std::string & value);
    void set_date_of_birth(std::string & value);
    void clear();
    int get_is_default();
    bool equal(Passenger & p);
};

#endif

