QT -= gui
QT += network sql
CONFIG += c++11 console
CONFIG -= app_bundle

DEFINES += QT_DEPRECATED_WARNINGS


SOURCES += \
        connectionmanager.cpp \
        main.cpp \
        server.cpp \
        sqlserver.cpp \
        tcpserver.cpp

HEADERS += \
    connection_parameters.h \
    connectionmanager.h \
    server.h \
    sqlserver.h \
    tcpserver.h

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
