QT       += core gui
QT       += xml
QT       += printsupport

VERSION = 1.0.0
QMAKE_TARGET_COMPANY = relTech
QMAKE_TARGET_PRODUCT = myRin
QMAKE_TARGET_ORIGINAL_FILENAME = myRin.exe
QMAKE_TARGET_COPYRIGHT = Copyright (C) 2022, relTech
RC_ICONS += $$PWD/Resources/Icons/MainIcons/table.ico

#*****************************************************
include(..\MyRin\QxOrm\QxOrm.pri)

TEMPLATE = app
DEFINES += _BUILDING_MYRIN
INCLUDEPATH += $$PWD\QxOrm\include\
LIBS += $$PWD\QxOrm\lib

!contains(DEFINES, _QX_NO_PRECOMPILED_HEADER) {
PRECOMPILED_HEADER = ./precompiled.h
}

macx:CONFIG-=app_bundle

CONFIG(debug, debug|release) {
TARGET = MyRind
LIBS += -L$$PWD/QXOrm/lib/ -lQxOrmd
} else {
TARGET = MyRin
LIBS += -L$$PWD/QXOrm/lib/ -lQxOrmd
}
#*****************************************************

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Forms/MiniForms/deletedialog.cpp \
    Forms/addpersonview.cpp \
    Forms/indexview.cpp \
    Forms/redactpersonview.cpp \
    Models/personmodel.cpp \
    Parsers/configworker.cpp \
    Parsers/jsonparser.cpp \
    Parsers/xmlparser.cpp \
    Services/DataBaseService/databasegetservice.cpp \
    Services/DataBaseService/databaseinitservice.cpp \
    Services/DataBaseService/databasepushservice.cpp \
    Services/MessagesService/errormessage.cpp \
    Services/MessagesService/infomessage.cpp \
    Services/tableservice.cpp \
    main.cpp

HEADERS += \
    Forms/MiniForms/deletedialog.h \
    Forms/addpersonview.h \
    Forms/indexview.h \
    Forms/redactpersonview.h \
    Models/personmodel.h \
    Parsers/configworker.h \
    Parsers/jsonparser.h \
    Parsers/xmlparser.h \
    Services/DataBaseService/databasegetservice.h \
    Services/DataBaseService/databaseinitservice.h \
    Services/DataBaseService/databasepushservice.h \
    Services/MessagesService/errormessage.h \
    Services/MessagesService/infomessage.h \
    Services/tableservice.h \
    export.h \
    precompiled.h

FORMS += \
    Forms/MiniForms/deletedialog.ui \
    Forms/addpersonview.ui \
    Forms/indexview.ui \
    Forms/redactpersonview.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources/MainIcons.qrc \
    Resources/ToolIcons.qrc
