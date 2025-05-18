QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    /Users/oksanafedorova/Downloads/Telegram Desktop/aviasales/Flight/Flight.cpp \
    /Users/oksanafedorova/Downloads/Telegram Desktop/aviasales/FormFlight/formflight.cpp \
    /Users/oksanafedorova/Downloads/Telegram Desktop/aviasales/HashTable/HashTable.cpp \
    /Users/oksanafedorova/Downloads/Telegram Desktop/aviasales/List/List.cpp \
    /Users/oksanafedorova/Downloads/Telegram Desktop/aviasales/Passenger/Passenger.cpp \
    /Users/oksanafedorova/Downloads/Telegram Desktop/aviasales/Sales/Sales.cpp \
    /Users/oksanafedorova/Downloads/Telegram Desktop/aviasales/Tree/AVLTree.cpp \
    /Users/oksanafedorova/Downloads/Telegram Desktop/aviasales/Models/QTableModel.cpp \
    /Users/oksanafedorova/Downloads/Telegram Desktop/aviasales/Models/avltreemodel.cpp \
    /Users/oksanafedorova/Downloads/Telegram Desktop/aviasales/FormPassanger/formpassanger.cpp \
    /Users/oksanafedorova/Downloads/Telegram Desktop/aviasales/FormSales/formsales.cpp \
    /Users/oksanafedorova/Downloads/Telegram Desktop/aviasales/Models/hashtablemodel.cpp \
    /Users/oksanafedorova/Downloads/Telegram Desktop/aviasales/Models/listmodel.cpp \
    /Users/oksanafedorova/Downloads/Telegram Desktop/aviasales/main.cpp \
    /Users/oksanafedorova/Downloads/Telegram Desktop/aviasales/mainwindow.cpp

HEADERS += \
    /Users/oksanafedorova/Downloads/Telegram Desktop/aviasales/Flight/Flight.hpp \
    /Users/oksanafedorova/Downloads/Telegram Desktop/aviasales/FormFlight/formflight.h \
    /Users/oksanafedorova/Downloads/Telegram Desktop/aviasales/HashTable/HashTable.hpp \
    /Users/oksanafedorova/Downloads/Telegram Desktop/aviasales/List/List.hpp \
    /Users/oksanafedorova/Downloads/Telegram Desktop/aviasales/Passenger/Passenger.hpp \
    /Users/oksanafedorova/Downloads/Telegram Desktop/aviasales/Sales/Sales.hpp \
    /Users/oksanafedorova/Downloads/Telegram Desktop/aviasales/Tree/AVLTree.hpp \
    /Users/oksanafedorova/Downloads/Telegram Desktop/aviasales/Models/QTableModel.h \
    /Users/oksanafedorova/Downloads/Telegram Desktop/aviasales/Models/avltreemodel.h \
    /Users/oksanafedorova/Downloads/Telegram Desktop/aviasales/FormPassanger/formpassanger.h \
    /Users/oksanafedorova/Downloads/Telegram Desktop/aviasales/FormSales/formsales.h \
    /Users/oksanafedorova/Downloads/Telegram Desktop/aviasales/Models/hashtablemodel.h \
    /Users/oksanafedorova/Downloads/Telegram Desktop/aviasales/Models/listmodel.h \
    /Users/oksanafedorova/Downloads/Telegram Desktop/aviasales/mainwindow.h

FORMS += \
    /Users/oksanafedorova/Downloads/Telegram Desktop/aviasales/FormFlight/formflight.ui \
    /Users/oksanafedorova/Downloads/Telegram Desktop/aviasales/FormPassanger/formpassanger.ui \
    /Users/oksanafedorova/Downloads/Telegram Desktop/aviasales/FormSales/formsales.ui \
    /Users/oksanafedorova/Downloads/Telegram Desktop/aviasales/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
