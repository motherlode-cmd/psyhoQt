#ifndef HASHTABLE
#define HASHTABLE
#include <string>
#include <vector>
#include "../Passenger/Passenger.hpp"

class Hash_table {
private:
    int size = 0;
    int c = 1;
    std::vector <Passenger> values;
    int hash(std::string value);
    void extension();
    std::vector <Passenger> get_passangers_vector_by_passport_num(std::string passport_num);
    void append_to_list(QStringList & newValue, Passenger & p);
public:
    Hash_table() {values.resize(100);}
    void insert(Passenger &value);
    void delete_value(Passenger value);
    Passenger get(std::string s);
    QList <QStringList> * get_search_name(const QString & name);
    QList <QStringList> * get_data();
    QList <QStringList> * get_search_data(const QString & search);
};

#endif


