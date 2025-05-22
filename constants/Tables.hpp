#include <iostream>
#include <map>

enum class ElementType
{
    Doctor,
    Patient,
    Prescriotion,
    Treatment,
    Complant,
    Unknown
};

const std::map<ElementType, std::vector<std::string>> tableLabels{
    {ElementType::Doctor, {"id", "full_name", "speciality", "phone", "email"}},
    {ElementType::Patient, {"id", "full_name", "birth_date", "inpatient"}},
    {ElementType::Prescriotion, {"id", "doctor_id", "medicine", "issue_date", "issue_time", "dossage_mg", "inclassions"}},
    {ElementType::Treatment, {"id", "patient_id", "start_date", "diagnosis", "prescription_id", "end_date", "note"}},
    {ElementType::Complant, {"id", "doctor_id", "patient_id", "status", "coplaint_date", "coplaint_message"}},
    {ElementType::Unknown, {}}};

const std::map<std::string, std::string> descriptionLabels
{
    {"id", "Уникальный ключ"},
        {"full_name", "ФИО"},
        {"speciality", "Специальность"},
        {"phone", "Номер телефона"},
        {"email", "Почта"},
        {"birth_date", "Дата рождения"},
        {"inpatient", "Импотент?"},
        {"doctor_id", "Уникальный ключ доктора"},
        {"medicine", ""},
        {"issue_date", ""},
        {"issue_time", ""},
        {"dossage_mg", ""},
        {"inclassions", ""},
        {"patient_id", ""},
        {"start_date", ""},
        {"diagnosis", ""},
        {"prescription_id", ""},
        {"end_date", ""},
        {"note", ""},
        {"status", ""},
        {"coplaint_date", ""},
        {"coplaint_message", ""}
};