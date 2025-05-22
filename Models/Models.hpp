#ifndef MODELS_H
#define MODELS_H
#include <string>
#include <iostream>
#include <chrono>
#include <vector>
#include <ctime>
#include <iomanip>
#include "constants/Tables.hpp"

class TableElement {
public:
    virtual std::vector <std::pair<std::string, std::string>> get_row();
    virtual ~TableElement() = default;
};

TableElement* createElem(std::vector<std::pair<std::string, std::string>> vector_labels, ElementType type);
class Doctor: public TableElement
{
public:
Doctor() = default;
~Doctor() = default;
Doctor(std::vector<std::pair<std::string, std::string>> vector_labels);
std::vector <std::pair<std::string, std::string>> get_row();
private:
    int id;
    std::string full_name;
    std::string speciality;
    std::string phone;
    std::string email;
};

class Patient: public TableElement
{
public:
Patient() = default;
~Patient() = default;
Patient(std::vector<std::pair<std::string, std::string>> vector_labels);
std::vector <std::pair<std::string, std::string>> get_row();
private:
    int id;
    std::string full_name;
    std::time_t birth_date;
    bool inpatient;
};

class Prescriotion: public TableElement
{
public:
Prescriotion() = default;
~Prescriotion() = default;
Prescriotion(std::vector<std::pair<std::string, std::string>> vector_labels);
std::vector <std::pair<std::string, std::string>> get_row();
private:
    int id;
    int doctor_id;
    std::string medicine;
    std::time_t issue_date;
    std::time_t issue_time;
    double dossage_mg;
    std::string inclassions;
};

class Treatment: public TableElement
{
public:
Treatment() = default;
~Treatment() = default;
Treatment(std::vector<std::pair<std::string, std::string>> vector_labels);
std::vector <std::pair<std::string, std::string>> get_row();
private:
    int id;
    int patient_id;
    std::time_t start_date;
    std::string diagnosis;
    int prescription_id;
    std::time_t end_date;
    std::string note;
};

class Complant: public TableElement
{
public:
Complant() = default;
~Complant() = default;
Complant(std::vector<std::pair<std::string, std::string>> vector_labels);
std::vector <std::pair<std::string, std::string>> get_row();
private:
    int id;
    int doctor_id;
    int patient_id;
    std::string status;
    std::time_t coplaint_date;
    std::string coplaint_message;
};

#endif // MODELS_H

