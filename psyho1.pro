QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Forms/formcomplant.cpp \
    Forms/formpatient.cpp \
    Forms/formdoctor.cpp \
    Forms/formprescription.cpp \
    Forms/formtreatment.cpp \
    List/List.cpp \
    Sales/Sales.cpp \
    QtModels/QTableModel.cpp \
    QtModels/QtModels.cpp \
    Forms/formsales.cpp \
    Models/listmodel.cpp \
    Models/Models.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Forms/formcomplant.h \
    Forms/formpatient.h \
    Forms/formdoctor.h \
    Forms/formprescription.h \
    Forms/formtreatment.h \
    List/List.hpp \
    Sales/Sales.hpp \
    QtModels/QTableModel.h \
    QtModels/QtModels.h \
    Forms/formsales.h \
    Models/listmodel.h \
    Models/Models.hpp \
    mainwindow.h

FORMS += \
    Forms/formcomplant.ui \
    Forms/formpatient.ui \
    Forms/formsales.ui \
    Forms/formdoctor.ui \
    Forms/formprescription.ui \
    Forms/formtreatment.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=
