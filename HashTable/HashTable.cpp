#include "HashTable.hpp"

int Hash_table::hash(std::string value) {
    int res = 0;
    int power = 1;
    for(size_t i = 0; i < value.size(); i++) {
        res += power * ((int)value[i] - (int)'0');
        power *= 2;
    }
    return res % values.size();
}

//расширение размера массива values
void Hash_table::extension() {
    std::vector <Passenger> new_values;
    //расширение
    new_values.resize(values.size() + 10);
    //перезаписываем в новый массив с учетом хэш функции
    for(size_t i = 0; i < values.size(); i++) {
        //Получаем значение хэш функции элемента
        int index = hash(values[i].get_key());
        //Если is_default то ячейка незаполнена, инче - коллизия, нужно сдвинуться на c ячеек
        while (!new_values[index].get_is_default()) {
            index = (index + c) % new_values.size();
        }
        new_values[index] = values[i];
    }
    values.clear();
    values = new_values;
}

//Вставка в талицу
void Hash_table::insert(Passenger & value) {
    //Получение индекса хэш функцией
    int index = hash(value.get_key());
    //Проверка на коллизии, если выполнено, то увеличваем индекс, пока не найдем свободную ячейку
    while (!values[index].get_is_default() && hash(values[index].get_key()) == hash(value.get_key())) {
        index = (index + c) % values.size();
    }
    //Нашлась свободая ячейка
    if(values[index].get_is_default()) {
        values[index] = value;
    } else {
    //Вышли из цикла по причине не совпадения хэш функции со встреченным не пустым значением в массиве,
    //Необходимо расширить массив и попытаться добавить снова
        extension();
        insert(value);
    }
    std::cout<<"INSERT"<<std::endl;
}

//Удаление из таблицы
void Hash_table::delete_value(Passenger value) {
    //Высчитываем значение хэш функции
    int index = hash(value.get_key());
    //Если произошла коллизия, то по индексу будет лежать значение, не равное нужному
    //Поэтому необходим изенить индекс
    while (values[index].get_is_default() == 0 && !values[index].equal(value) && hash(values[index].get_key()) == hash(value.get_key())) {
        index = (index + c) % values.size();
    }
    //Если после выхода из цикла было получено значение, не равное нужному, значит в таблице такого нет
    if(hash(values[index].get_key()) == hash(value.get_key())) {
        //Если значение найдено, необходимо его удалить и сдвинуть остальные, значение хэш функции который такое же
        //как и у удаленного
        values[index].clear();

        while(hash(values[(index + c) % values.size()].get_key()) == hash(value.get_key())) {
            values[index] = values[(index + c) & values.size()];
            values[(index + c) & values.size()].clear();
            index = (index + c) % values.size();
        }
    }
}

//Получение информации по ключу
Passenger Hash_table::get(std::string s) {
    int index = hash(s);
    //Информация по введенному ключу будет лежать по индексу, вычисленному хэш функцией, если коллизии не было
    //Если она произошла, то будет лежать через нескольк шагов с
    //Если элемента нет, то в какой-то момент мы перейдем либо на пустую ячейку, либо на ячейку с другой хэш функцией
    while(values[index].get_is_default() == 0 && values[index].get_key() != s && hash(values[index].get_key()) == hash(s)) {
        index = (index + c) % values.size();
    }
    return values[index];
}

void Hash_table::append_to_list(QStringList &new_list, Passenger & p)
{
    new_list.append(QString::fromStdString(p.get_passport_num()));
    new_list.append(QString::fromStdString(p.get_date_place_issue()));
    new_list.append(QString::fromStdString(p.get_name()));
    new_list.append(QString::fromStdString(p.get_date_of_birth()));
}

QList<QStringList> *Hash_table::get_search_name(const QString &name)
{
    QList<QStringList> * result = new QList<QStringList>;
    for(int i = 0; i < values.size(); i++) {
        if(!values[i].get_is_default() && values[i].get_name() == name.toStdString()) {
            QStringList new_list;
            append_to_list(new_list, values[i]);
            result->append(new_list);
        }
    }
    return result;
}

std::vector <Passenger> Hash_table::get_passangers_vector_by_passport_num(std::string passport_num) {
    int index = hash(passport_num);
    std::vector <Passenger> result;
    while(values[index].get_is_default() == 0 && hash(values[index].get_key()) == hash(passport_num)) {
        result.push_back(values[index]);
        index = (index + c) % values.size();
    }
    return result;
}


QList<QStringList> *Hash_table::get_data()
{
    QList<QStringList> * data = new QList<QStringList>;
    for(int i = 0; i < values.size(); i++) {
        if(!values[i].get_is_default()) {
            QStringList new_list;
            append_to_list(new_list, values[i]);
            data->append(new_list);
        }
    }
    return data;
}

QList<QStringList> * Hash_table::get_search_data(const QString &search)
{
    QList<QStringList> * result = new QList<QStringList>();
    std::vector<Passenger> passengers = get_passangers_vector_by_passport_num(search.toStdString());
    for( auto & p : passengers) {
        QStringList curr_pass;
        append_to_list(curr_pass, p);
        result->append(curr_pass);
    }
    return result;
}

