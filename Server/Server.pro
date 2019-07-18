QT -= gui
QT += network sql
CONFIG += c++11 console
CONFIG -= app_bundle

DEFINES += QT_DEPRECATED_WARNINGS


SOURCES += \
        client.cpp \
        connectionmanager.cpp \
        main.cpp \
        server.cpp \
        sqlclient.cpp

HEADERS += \
    client.h \
    connection_parameters.h \
    connectionmanager.h \
    server.h \
    sqlclient.h

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
