#include "Passenger.hpp"

Passenger::Passenger(QStringList &list) {
    is_default = 0;
    passport_number = list.at(0).toStdString();
    date_place_issue = list.at(1).toStdString();
    name = list.at(2).toStdString();
    date_of_birth = list.at(3).toStdString();
}

std::string & Passenger::get_key() {
    return passport_number;
}
std::string & Passenger::get_passport_num() {
    return passport_number;
}
std::string & Passenger::get_name() {
    return name;
}
std::string & Passenger::get_date_of_birth() {
    return date_of_birth;
}
std::string & Passenger::get_date_place_issue() {
    return date_place_issue;
}
void Passenger::set_date_place_issue(std::string & value) {
    date_place_issue = value;
}
void Passenger::set_passport_num(std::string & value) {
    passport_number = value;
}
void Passenger::set_name(std::string & value) {
    name = value;
}
void Passenger::set_date_of_birth(std::string & value) {
    date_of_birth = value;
}

void Passenger::clear() {
    is_default = 1;
    passport_number.clear();
    date_of_birth.clear();
    name.clear();
    date_place_issue.clear();
}

int Passenger::get_is_default() {
    return is_default;
}

bool Passenger::equal(Passenger & p) {
    return name == p.name && passport_number == p.passport_number && date_place_issue == p.date_place_issue && date_of_birth == p.date_of_birth;
}
