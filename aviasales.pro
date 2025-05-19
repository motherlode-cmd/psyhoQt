QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    FormFlight/formflight.cpp \
    FormSales/formcomplant.cpp \
    FormSales/formpatient.cpp \
    HashTable/HashTable.cpp \
    Flight/Flight.cpp \
    List/List.cpp \
    Passenger/Passenger.cpp \
    Sales/Sales.cpp \
    Tree/AVLTree.cpp \
    Models/QTableModel.cpp \
    Models/avltreemodel.cpp \
    FormPassanger/formpassanger.cpp \
    FormSales/formsales.cpp \
    Models/hashtablemodel.cpp \
    Models/listmodel.cpp \
    Models/Models.cpp \
    formdoctor.cpp \
    formprescription.cpp \
    formtreatment.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Flight/Flight.hpp \
    FormFlight/formflight.h \
    FormSales/formcomplant.h \
    FormSales/formpatient.h \
    HashTable/HashTable.hpp \
    List/List.hpp \
    Passenger/Passenger.hpp \
    Sales/Sales.hpp \
    Tree/AVLTree.hpp \
    Models/QTableModel.h \
    Models/avltreemodel.h \
    FormPassanger/formpassanger.h \
    FormSales/formsales.h \
    Models/hashtablemodel.h \
    Models/listmodel.h \
    Models/Models.hpp \
    formdoctor.h \
    formprescription.h \
    formtreatment.h \
    mainwindow.h

FORMS += \
    FormFlight/formflight.ui \
    FormPassanger/formpassanger.ui \
    FormSales/formcomplant.ui \
    FormSales/formpatient.ui \
    FormSales/formsales.ui \
    FormSales/formdoctor.ui \
    FormSales/formprescription.ui \
    FormSales/formtreatment.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=
