#ifndef MODELS_H
#define MODELS_H
#include <string>
#include <iostream>
#include <chrono>
#include <vector>
#include <ctime>
#include <iomanip>

class TableElement {
public:
    virtual std::vector <std::pair<std::string, std::string>> get_row();
};

class Doctor: TableElement
{
public:
Doctor() = default;
Doctor(std::vector<std::pair<std::string, std::string>> vector_labels);
std::vector <std::pair<std::string, std::string>> get_row();
private:
    int id;
    std::string full_name;
    std::string speciality;
    std::string phone;
    std::string email;
};

class Patient: TableElement
{
public:
Patient() = default;
Patient(std::vector<std::pair<std::string, std::string>> vector_labels);
std::vector <std::pair<std::string, std::string>> get_row();
private:
    int id;
    std::string full_name;
    std::time_t birth_date;
    bool inpatient;
};

class Prescriotion: TableElement
{
public:
Prescriotion() = default;
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

class Treatment: TableElement
{
public:
Treatment() = default;
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

class Complant: TableElement
{
public:
Complant() = default;
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

