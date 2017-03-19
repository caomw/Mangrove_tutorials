#####################################################################################################################################################################
# David Canino (canino.david@gmail.com) - March 2017
#
# This QT project file generates the Makefiles for compiling the 'Mangrove_tutorial010' program. This latter is one of the custom 'Tutorial Examples' for the 
# 'Mangrove TDS Library' (http://mangrovetds.github.io).
# This program is distributed independently on the 'Mangrove TDS Library', and can be compiled both in the debug and the release mode.
#
# Mangrove_tutorial010.pro
#####################################################################################################################################################################

# Basic options, directories, headers and sources for the 'Mangrove_tutorial010' program.
TEMPLATE = app
LANGUAGE = C++
CONFIG += console c++11 debug_and_release
CONFIG -= app_bundle
TARGET = Mangrove_tutorial010
QT += core
QT -= gui
include(../common_defs)
DESTDIR = ../bin/
MOC_DIR += ./moc/
OBJECTS_DIR += ./obj/
QMAKE_CXXFLAGS_RELEASE += -DNDEBUG -O3 -ansi -w
QMAKE_CXXFLAGS_DEBUG += -ansi -w
SOURCES += Mangrove_tutorial010.cpp
INCLUDEPATH += $${MANGROVE_ALL_INCLUDE}
LIBS += $${MANGROVE_ALL_OPTIONS} -lm
win32 { LIBS+=-lpsapi }
