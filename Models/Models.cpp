#include "Models/Models.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <sstream>

std::time_t string_to_time_t(const std::string &time_str, const std::string &format = "%Y-%m-%d %H:%M:%S")
{
    std::tm tm = {};
    std::istringstream ss(time_str);
    ss >> std::get_time(&tm, format.c_str());
    if (ss.fail())
    {
        throw std::runtime_error("Failed to parse time string");
    }
    return std::mktime(&tm);
}

std::string time_t_to_string(std::time_t time, const std::string &format = "%Y-%m-%d %H:%M:%S")
{
    std::tm tm = *std::localtime(&time);
    char buffer[80];
    std::strftime(buffer, sizeof(buffer), format.c_str(), &tm);
    return std::string(buffer);
}

TableElement* createElem(std::vector<std::pair<std::string, std::string>> vector_labels, ElementType type){
    switch (type)
    {
    case ElementType::Doctor:
        return new Doctor(vector_labels);
    case ElementType::Patient:
        return new Patient(vector_labels);
    case ElementType::Prescriotion:
        return new Prescriotion(vector_labels);
    case ElementType::Treatment:
        return new Treatment(vector_labels);
    case ElementType::Complant:
        return new Complant(vector_labels);
    case ElementType::Unknown:
        return nullptr;
    default:
        return nullptr;
    }
}

Doctor::Doctor(std::vector<std::pair<std::string, std::string>> labels_values)
{
    for (const auto &pair : labels_values)
    {
        if (pair.first == "id")
        {
            try
            {
                id = std::stoi(pair.second);
            }
            catch (const std::invalid_argument &e)
            {
                std::cout << "Неверный ID: " << e.what() << std::endl;
            }
            catch (const std::out_of_range &e)
            {
                std::cout << "Ошибка: значение вне диапазона" << std::endl;
            };
        }
        if (pair.first == "full_name")
        {
            full_name = pair.second;
        }
        if (pair.first == "speciality")
        {
            speciality = pair.second;
        }
        if (pair.first == "phone")
        {
            phone = pair.second;
        }
        if (pair.first == "email")
        {
            email = pair.second;
        }
    }
}

std::vector<std::pair<std::string, std::string>> Doctor::get_row()
{
    std::vector<std::pair<std::string, std::string>> labels_values;
    labels_values.push_back(std::pair{"id", std::to_string(id)});
    labels_values.push_back(std::pair{"full_name", full_name});
    labels_values.push_back(std::pair{"speciality", speciality});
    labels_values.push_back(std::pair{"phone", phone});
    labels_values.push_back(std::pair{"email", email});
    return labels_values;
}




Patient::Patient(std::vector<std::pair<std::string, std::string>> labels_values)
{
    for (const auto &pair : labels_values)
    {
        if (pair.first == "id")
        {
            try
            {
                id = std::stoi(pair.second);
            }
            catch (const std::invalid_argument &e)
            {
                std::cout << "Неверный ID: " << e.what() << std::endl;
            }
            catch (const std::out_of_range &e)
            {
                std::cout << "Ошибка: значение вне диапазона" << std::endl;
            };
        }
        if (pair.first == "full_name")
        {
            full_name = pair.second;
        }
        if (pair.first == "birth_date")
        {
            try
            {
                birth_date = string_to_time_t(pair.second);
            }
            catch (const std::runtime_error &e)
            {
                std::cout << "Ошибка: формат даты не верный" << std::endl;
            }
        }
        if (pair.first == "inpatient")
        {
            inpatient = pair.second == "0" ? false : true;
        }
    }
}

std::vector<std::pair<std::string, std::string>> Patient::get_row()
{
    std::vector<std::pair<std::string, std::string>> labels_values;
    labels_values.push_back(std::pair{"id", std::to_string(id)});
    labels_values.push_back(std::pair{"full_name", full_name});
    labels_values.push_back(std::pair{"birth_date", time_t_to_string(birth_date)});
    labels_values.push_back(std::pair{"inpatient", inpatient == false ? "0" : "1"});
    return labels_values;
}




Prescriotion::Prescriotion(std::vector<std::pair<std::string, std::string>> labels_values)
{
    for (const auto &pair : labels_values)
    {
        if (pair.first == "id")
        {
            try
            {
                id = std::stoi(pair.second);
            }
            catch (const std::invalid_argument &e)
            {
                std::cout << "Неверный ID: " << e.what() << std::endl;
            }
            catch (const std::out_of_range &e)
            {
                std::cout << "Ошибка: значение вне диапазона" << std::endl;
            };
        }
        if (pair.first == "doctor_id")
        {
            try
            {
                doctor_id = std::stoi(pair.second);
            }
            catch (const std::invalid_argument &e)
            {
                std::cout << "Неверный ID: " << e.what() << std::endl;
            }
            catch (const std::out_of_range &e)
            {
                std::cout << "Ошибка: значение вне диапазона" << std::endl;
            };
        }
        if (pair.first == "medicine")
        {
            medicine = pair.second;
        }
        if (pair.first == "issue_date")
        {
            try
            {
                issue_date = string_to_time_t(pair.second);
            }
            catch (const std::runtime_error &e)
            {
                std::cout << "Ошибка: формат даты не верный" << std::endl;
            }
        }
        if (pair.first == "issue_time")
        {
            try
            {
                issue_date = string_to_time_t(pair.second);
            }
            catch (const std::runtime_error &e)
            {
                std::cout << "Ошибка: формат даты не верный" << std::endl;
            }
        }
        if (pair.first == "dossage_mg")
        {
            try
            {
                dossage_mg = std::stof(pair.second);
            }
            catch (const std::invalid_argument &e)
            {
                std::cout << "Неверный ID: " << e.what() << std::endl;
            }
            catch (const std::out_of_range &e)
            {
                std::cout << "Ошибка: значение вне диапазона" << std::endl;
            };
        }
        if (pair.first == "inclassions")
        {
            inclassions = pair.second;
        }
    }
}

std::vector<std::pair<std::string, std::string>> Prescriotion::get_row()
{
    std::vector<std::pair<std::string, std::string>> labels_values;
    labels_values.push_back(std::pair{"id", std::to_string(id)});
    labels_values.push_back(std::pair{"doctor_id", std::to_string(doctor_id)});
    labels_values.push_back(std::pair{"medicine", medicine});
    labels_values.push_back(std::pair{"issue_date", time_t_to_string(issue_date)});
    labels_values.push_back(std::pair{"issue_time", time_t_to_string(issue_time)});
    labels_values.push_back(std::pair{"dossage_mg", std::to_string(dossage_mg)});
    labels_values.push_back(std::pair{"inclassions", inclassions});
    return labels_values;
}




Treatment::Treatment(std::vector<std::pair<std::string, std::string>> labels_values)
{
    for (const auto &pair : labels_values)
    {
        if (pair.first == "id")
        {
            try
            {
                id = std::stoi(pair.second);
            }
            catch (const std::invalid_argument &e)
            {
                std::cout << "Неверный ID: " << e.what() << std::endl;
            }
            catch (const std::out_of_range &e)
            {
                std::cout << "Ошибка: значение вне диапазона" << std::endl;
            };
        }
        if (pair.first == "patient_id")
        {
            try
            {
                patient_id = std::stoi(pair.second);
            }
            catch (const std::invalid_argument &e)
            {
                std::cout << "Неверный ID: " << e.what() << std::endl;
            }
            catch (const std::out_of_range &e)
            {
                std::cout << "Ошибка: значение вне диапазона" << std::endl;
            };
        }
        if (pair.first == "start_date")
        {
            try
            {
                start_date = string_to_time_t(pair.second);
            }
            catch (const std::runtime_error &e)
            {
                std::cout << "Ошибка: формат даты не верный" << std::endl;
            }
        }
        if (pair.first == "diagnosis")
        {
            diagnosis = pair.second;
        }
        if (pair.first == "prescription_id")
        {
            try
            {
                prescription_id = std::stoi(pair.second);
            }
            catch (const std::invalid_argument &e)
            {
                std::cout << "Неверный ID: " << e.what() << std::endl;
            }
            catch (const std::out_of_range &e)
            {
                std::cout << "Ошибка: значение вне диапазона" << std::endl;
            };
        }
        if (pair.first == "end_date")
        {
            try
            {
                end_date = string_to_time_t(pair.second);
            }
            catch (const std::runtime_error &e)
            {
                std::cout << "Ошибка: формат даты не верный" << std::endl;
            }
        }
        if (pair.first == "note")
        {
            note = pair.second;
        }
    }
}

std::vector<std::pair<std::string, std::string>> Treatment::get_row()
{
    std::vector<std::pair<std::string, std::string>> labels_values;
    labels_values.push_back(std::pair{"id", std::to_string(id)});
    labels_values.push_back(std::pair{"patient_id", std::to_string(patient_id)});
    labels_values.push_back(std::pair{"start_date", time_t_to_string(start_date)});
    labels_values.push_back(std::pair{"diagnosis", diagnosis});
    labels_values.push_back(std::pair{"prescription_id", time_t_to_string(prescription_id)});
    labels_values.push_back(std::pair{"end_date", std::to_string(end_date)});
    labels_values.push_back(std::pair{"note", note});
    return labels_values;
}




Complant::Complant(std::vector<std::pair<std::string, std::string>> labels_values)
{
    for (const auto &pair : labels_values)
    {
        if (pair.first == "id")
        {
            try
            {
                id = std::stoi(pair.second);
            }
            catch (const std::invalid_argument &e)
            {
                std::cout << "Неверный ID: " << e.what() << std::endl;
            }
            catch (const std::out_of_range &e)
            {
                std::cout << "Ошибка: значение вне диапазона" << std::endl;
            };
        }
        if (pair.first == "doctor_id")
        {
            try
            {
                doctor_id = std::stoi(pair.second);
            }
            catch (const std::invalid_argument &e)
            {
                std::cout << "Неверный ID: " << e.what() << std::endl;
            }
            catch (const std::out_of_range &e)
            {
                std::cout << "Ошибка: значение вне диапазона" << std::endl;
            };
        }
        if (pair.first == "patient_id")
        {
            try
            {
                patient_id = std::stoi(pair.second);
            }
            catch (const std::invalid_argument &e)
            {
                std::cout << "Неверный ID: " << e.what() << std::endl;
            }
            catch (const std::out_of_range &e)
            {
                std::cout << "Ошибка: значение вне диапазона" << std::endl;
            };
        }
        if (pair.first == "status")
        {
            status = pair.second;
        }
        if (pair.first == "coplaint_date")
        {
            try
            {
                coplaint_date = string_to_time_t(pair.second);
            }
            catch (const std::runtime_error &e)
            {
                std::cout << "Ошибка: формат даты не верный" << std::endl;
            }
        }
        if (pair.first == "coplaint_message")
        {
            coplaint_message = pair.second;
        }
    }
}

std::vector<std::pair<std::string, std::string>> Complant::get_row()
{
    std::vector<std::pair<std::string, std::string>> labels_values;
    labels_values.push_back(std::pair{"id", std::to_string(id)});
    labels_values.push_back(std::pair{"doctor_id", std::to_string(doctor_id)});
    labels_values.push_back(std::pair{"patient_id", std::to_string(patient_id)});
    labels_values.push_back(std::pair{"status", status});
    labels_values.push_back(std::pair{"coplaint_date", time_t_to_string(coplaint_date)});
    labels_values.push_back(std::pair{"coplaint_message", coplaint_message});
    return labels_values;
}