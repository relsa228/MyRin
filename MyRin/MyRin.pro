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
    Parsers/xmlparser.cpp \
    Tools/filter.cpp \
    main.cpp \

HEADERS += \
    Entities/person.h \
    Forms/addpersonview.h \
    Forms/indexview.h \
    Parsers/xmlparser.h \
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
