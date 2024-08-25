QT       += core gui sql network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    disease.cpp \
    doc_edit.cpp \
    doc_information.cpp \
    doc_plat.cpp \
    docmain.cpp \
    handleapment.cpp \
    healthassessment.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    per_information.cpp \
    platform.cpp \
    signup.cpp \
    viewapment.cpp

HEADERS += \
    disease.h \
    doc_edit.h \
    doc_information.h \
    doc_plat.h \
    docmain.h \
    handleapment.h \
    healthassessment.h \
    login.h \
    mainwindow.h \
    per_information.h \
    platform.h \
    signup.h \
    viewapment.h

FORMS += \
    disease.ui \
    doc_edit.ui \
    doc_information.ui \
    doc_plat.ui \
    docmain.ui \
    handleapment.ui \
    healthassessment.ui \
    login.ui \
    mainwindow.ui \
    per_information.ui \
    platform.ui \
    signup.ui \
    viewapment.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
