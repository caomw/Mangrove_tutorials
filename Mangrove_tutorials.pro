#####################################################################################################################################################################
# David Canino (canino.david@gmail.com) - March 2017
#
# This QT project file generates the Makefiles for compiling several 'Tutorial Examples' for the 'Mangrove TDS Library' (http://mangrovetds.github.io)
# These programs are distributed independently on the 'Mangrove TDS Library', and can be compiled both in the debug and the release mode.
#
# Mangrove_tutorials.pro
#####################################################################################################################################################################

TEMPLATE = subdirs
LANGUAGE = C++
SUBDIRS = \
		Mangrove_tutorial001 \
		Mangrove_tutorial002 \
		Mangrove_tutorial003 \
		Mangrove_tutorial004 \
		Mangrove_tutorial005 \
		Mangrove_tutorial006 \
		Mangrove_tutorial007 \
		Mangrove_tutorial008 \
		Mangrove_tutorial009 \
		Mangrove_tutorial010 \
		Mangrove_tutorial011 \
		Mangrove_tutorial012 \
		Mangrove_tutorial013 \
		Mangrove_tutorial014 \
		Mangrove_tutorial015 \
		Mangrove_tutorial016 \
		Mangrove_tutorial017 \
		Mangrove_tutorial018 \
		Mangrove_tutorial019 \
		Mangrove_tutorial020 \
		Mangrove_tutorial021 \
		Mangrove_tutorial022 \
		Mangrove_tutorial023 \
		Mangrove_tutorial024 \
		Mangrove_tutorial025 \
		Mangrove_tutorial026
CONFIG += ordered debug_and_release
