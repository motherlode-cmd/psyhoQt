#ifndef LIST
#define LIST
#include "../Sales/Sales.hpp"
typedef struct Node {
public:
    Sales data;
    Node * next = nullptr;
} Node;

class List {
private:
    Node * head;
    int size = 0;
    int str_to_int(Sales sale);
public:
    List() = default;
    void insert(Sales & value);
    void delete_value(std::string value);
    Sales get_value(std::string value);
    QList <QStringList> * get_data();
    QList <QStringList> * get_search_data();
};

#endif

