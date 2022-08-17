QT       += core gui
QT       += xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Entities/person.cpp \
    Forms/addpersonview.cpp \
    Forms/indexview.cpp \
    Parsers/jsonparser.cpp \
    Parsers/xmlparser.cpp \
    Services/DataBaseService/databasegetservice.cpp \
    Services/DataBaseService/databaseinitservice.cpp \
    Services/DataBaseService/databasepushservice.cpp \
    Services/MessagesService/errormessage.cpp \
    Services/MessagesService/infomessage.cpp \
    Services/tableservice.cpp \
    Tools/filter.cpp \
    main.cpp \

HEADERS += \
    Entities/person.h \
    Forms/addpersonview.h \
    Forms/indexview.h \
    Parsers/jsonparser.h \
    Parsers/xmlparser.h \
    Services/DataBaseService/databasegetservice.h \
    Services/DataBaseService/databaseinitservice.h \
    Services/DataBaseService/databasepushservice.h \
    Services/MessagesService/errormessage.h \
    Services/MessagesService/infomessage.h \
    Services/tableservice.h \
    Tools/filter.h

FORMS += \
    Forms/addpersonview.ui \
    Forms/indexview.ui \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources/MainIcons.qrc

include(..\MyRin\QxOrm\QxOrm.pri)

INCLUDEPATH += ..\MyRin\QxOrm\include\
LIBS += ..\MyRin\QxOrm\lib
