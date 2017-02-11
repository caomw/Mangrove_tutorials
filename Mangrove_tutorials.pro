#####################################################################################################################################################################
# David Canino (canino.david@gmail.com) - February 2017
#
# This QT project file generates the Makefiles for compiling several 'Tutorial Examples' for the 'Mangrove TDS Library' (http://mangrovetds.github.io)
# These programs are distributed independently on the 'Mangrove TDS Library', and can be compiled both in the debug and the release mode.
#
# Mangrove_tutorials.pro
#####################################################################################################################################################################

TEMPLATE = subdirs
LANGUAGE = C++
SUBDIRS = \
		Mangrove_tutorial01 \
		Mangrove_tutorial02
CONFIG += ordered debug_and_release
