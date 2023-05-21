QT       += core gui\
        multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    apple.cpp \
    buttons.cpp \
    game.cpp \
    main.cpp \
    score.cpp \
    snake_move.cpp \
    snakepart.cpp

HEADERS += \
    apple.h \
    buttons.h \
    game.h \
    score.h \
    snake_move.h \
    snakepart.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    snake.qrc
