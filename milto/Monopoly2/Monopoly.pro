#-------------------------------------------------
#
# Project created by QtCreator 2012-11-17T11:10:06
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = Monopoly
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += src/main.cpp \
    src/Tile.cpp \
    src/Property.cpp \
    src/Order.cpp \
    src/Station.cpp \
    src/NormalProperty.cpp \
    src/Game.cpp \
    src/Dice.cpp \
    src/Utility.cpp \
    src/Board.cpp \
    src/Card.cpp \
    src/CardStreetRepairs.cpp \
    src/CardMovePlayerToPosition.cpp \
    src/CardsManager.cpp \
    src/CardTakeMoney.cpp \
    src/CardReceiveMoney.cpp \
    src/CardMovePlayerBack.cpp \
    src/CardGoToJail.cpp \
    src/CardGetOutOfJail.cpp \
    src/CardChanceOrLoseMoney.cpp \
    src/GroupOfProperties.cpp \
    src/GroupsManager.cpp \
    src/CardReceiveMoneyFromPlayers.cpp \
    src/Player.cpp \
    src/PlayerManager.cpp \
    src/Jail.cpp

INCLUDEPATH+=./include

OBJECTS_DIR=obj
OBJECTS_DIR=./obj/

HEADERS += include/Tile.h \
    include/Property.h \
    include/Order.h \
    include/Station.h \
    include/NormalProperty.h \
    include/Game.h \
    include/Player.h \
    include/Dice.h \
    include/Utility.h \
    include/Board.h \
    include/CardsManager.h \
    include/Card.h \
    include/CardStreetRepairs.h \
    include/CardMovePlayerToPosition.h \
    include/CardTakeMoney.h \
    include/CardMovePlayerBack.h \
    include/CardGoToJail.h \
    include/CardGetOutOfJail.h \
    include/CardChanceOrLoseMoney.h \
    include/GroupOfProperties.h \
    include/GroupsManager.h \
    include/CardReceiveMoneyFromPlayers.h \
    include/CardReceiveMoney.h \
    include/PlayerManager.h \
    include/Jail.h
