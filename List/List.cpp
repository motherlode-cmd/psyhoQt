#include "List.hpp"
#include <iostream>

//Ключ для продаж и возвратов - номер билета - строка из 9 цифр
int List::str_to_int(Sales sale) {
    if(sale.get_key().length() > 0)
        return std::stoi(sale.get_key());
    else return 0;
}

void List::insert(Sales & value) {
    Node *new_node = new Node;
    new_node->data = value;
    new_node->next = nullptr;

    // Если список пуст, вставляем новый узел и делаем его головой
    if (size == 0) {
        head = new_node;
        size++;
        return;
    }

    // Если новый узел должен стать новой головой списка
    if (str_to_int(value) < str_to_int(head->data)) {
        new_node->next = head;
        head = new_node;
        size++;
        return;
    }

    Node *current = head;

    // Просматриваем список, пока не найдем узел, после которого нужно вставить новый
    while (current->next != nullptr && str_to_int(current->next->data) < str_to_int(value)) {
        current = current->next;
    }

    // Если новый узел должен быть вставлен в середину или в конец списка
    if (current->next == nullptr || str_to_int(current->next->data) > str_to_int(value)) {
        new_node->next = current->next;
        current->next = new_node;
        size++;
    } else if (str_to_int(current->next->data) == str_to_int(value)) {
        // Если такой же номер уже существует, освобождаем память и выходим
        delete new_node;
    }
}
void List::delete_value(std::string value) {
    // Если список пуст, выходим
    if (size == 0)
        return;

    // Если нужно удалить голову списка
    if (head->data.get_key() == value) {
        Node *temp = head;
        head = head->next;
        delete temp;
        size--;
        return;
    }

    Node *current = head;

    // Ищем узел, который следует за тем, который нужно удалить
    while (current->next != nullptr && current->next->data.get_key() != value)
        current = current->next;

    // Если нашли узел для удаления
    if (current->next != nullptr && current->next->data.get_key() == value) {
        Node *temp = current->next;
        current->next = current->next->next;
        delete temp;
        size--;
    }
    // Иначе узел не найден, и мы ничего не делаем
}


Sales List::get_value(std::string value) {
    Node * current = head;
    //Обходим список. пока не встретим конец, либо пока не упремся в следующий по порядку
    while (current->next != nullptr && current->data.get_key() != value )
        current = head->next;
    //Если не нашли нужный, значит его нет в списке, выходим
    if(current->data.get_key() != value) {
        return Sales();
    }
    return current->data;
}

QList<QStringList> *List::get_data()
{
    QList<QStringList> * data = new QList<QStringList>;
    Node * curr = head;
    while(curr != nullptr) {
        QStringList new_list;
        new_list.append(QString::fromStdString(curr->data.get_passport_num()));
        new_list.append(QString::fromStdString(curr->data.get_number_of_ticket()));
        new_list.append(QString::fromStdString(curr->data.get_number_of_flight()));
        data->append(new_list);
        curr = curr->next;
    }
    return data;
}



