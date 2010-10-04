TEMPLATE=subdirs
CONFIG += ordered\
	x86
include(common.pri)
qtstatemachine-uselib: SUBDIRS=buildlib
SUBDIRS+=examples
