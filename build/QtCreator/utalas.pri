########################################################################
# Copyright (c) 1988-2022 $organization$
#
# This software is provided by the author and contributors ``as is''
# and any express or implied warranties, including, but not limited to,
# the implied warranties of merchantability and fitness for a particular
# purpose are disclaimed. In no event shall the author or contributors
# be liable for any direct, indirect, incidental, special, exemplary,
# or consequential damages (including, but not limited to, procurement
# of substitute goods or services; loss of use, data, or profits; or
# business interruption) however caused and on any theory of liability,
# whether in contract, strict liability, or tort (including negligence
# or otherwise) arising in any way out of the use of this software,
# even if advised of the possibility of such damage.
#
#   File: utalas.pri
#
# Author: $author$
#   Date: 4/1/2022, 7/5/2022
#
# build specific QtCreator project .pri file for framework utalas
########################################################################
# Repository Depends: vmachinae
# Depends: ubn;ump;urostra;unadir;ufila;ucrono;ucifra;urete;ustara;umedusade

contains(BUILD_OS,Uname) {
UNAME = $$system(uname)

contains(UNAME,Darwin) {
BUILD_OS = macosx
} else {
contains(UNAME,Linux) {
BUILD_OS = linux
} else {
contains(UNAME,Windows) {
BUILD_OS = windows
} else {
BUILD_OS = os
} # contains(UNAME,Windows)
} # contains(UNAME,Linux)
} # contains(UNAME,Darwin)
} else {
contains(BUILD_OS,UTALAS_OS) {
} else {
BUILD_OS = os
} # contains(BUILD_OS,UTALAS_OS)
} # contains(BUILD_OS,Uname)

#BUILD_CPP_VERSION = 11

########################################################################
# ubn
#
# pkg-config --cflags --libs ubn
#

# build ubn INCLUDEPATH
#
build_ubn_INCLUDEPATH += \

# build ubn DEFINES
#
build_ubn_DEFINES += \

# build ubn FRAMEWORKS
#
build_ubn_FRAMEWORKS += \

# build ubn LIBS
#
build_ubn_LIBS += \

########################################################################
# ump
#
# pkg-config --cflags --libs ump
#

# build ump INCLUDEPATH
#
build_ump_INCLUDEPATH += \

# build ump DEFINES
#
build_ump_DEFINES += \

# build ump FRAMEWORKS
#
build_ump_FRAMEWORKS += \

# build ump LIBS
#
build_ump_LIBS += \

########################################################################
# urostra
#
# pkg-config --cflags --libs urostra
#

# build urostra INCLUDEPATH
#
build_urostra_INCLUDEPATH += \

# build urostra DEFINES
#
build_urostra_DEFINES += \

# build urostra FRAMEWORKS
#
build_urostra_FRAMEWORKS += \

# build urostra LIBS
#
build_urostra_LIBS += \

########################################################################
# unadir
#
# pkg-config --cflags --libs unadir
#

# build unadir INCLUDEPATH
#
build_unadir_INCLUDEPATH += \

# build unadir DEFINES
#
build_unadir_DEFINES += \

# build unadir FRAMEWORKS
#
build_unadir_FRAMEWORKS += \

# build unadir LIBS
#
build_unadir_LIBS += \

########################################################################
# ufila
#
# pkg-config --cflags --libs ufila
#

# build ufila INCLUDEPATH
#
build_ufila_INCLUDEPATH += \

# build ufila DEFINES
#
build_ufila_DEFINES += \

# build ufila FRAMEWORKS
#
build_ufila_FRAMEWORKS += \

# build ufila LIBS
#
build_ufila_LIBS += \

########################################################################
# ucrono
#
# pkg-config --cflags --libs ucrono
#

# build ucrono INCLUDEPATH
#
build_ucrono_INCLUDEPATH += \

# build ucrono DEFINES
#
build_ucrono_DEFINES += \

# build ucrono FRAMEWORKS
#
build_ucrono_FRAMEWORKS += \

# build ucrono LIBS
#
build_ucrono_LIBS += \

########################################################################
# ucifra
#
# pkg-config --cflags --libs ucifra
#

# build ucifra INCLUDEPATH
#
build_ucifra_INCLUDEPATH += \

# build ucifra DEFINES
#
build_ucifra_DEFINES += \

# build ucifra FRAMEWORKS
#
build_ucifra_FRAMEWORKS += \

# build ucifra LIBS
#
build_ucifra_LIBS += \

########################################################################
# urete
#
# pkg-config --cflags --libs urete
#

# build urete INCLUDEPATH
#
build_urete_INCLUDEPATH += \

# build urete DEFINES
#
build_urete_DEFINES += \

# build urete FRAMEWORKS
#
build_urete_FRAMEWORKS += \

# build urete LIBS
#
build_urete_LIBS += \

########################################################################
# ustara
#
# pkg-config --cflags --libs ustara
#

# build ustara INCLUDEPATH
#
build_ustara_INCLUDEPATH += \

# build ustara DEFINES
#
build_ustara_DEFINES += \

# build ustara FRAMEWORKS
#
build_ustara_FRAMEWORKS += \

# build ustara LIBS
#
build_ustara_LIBS += \

########################################################################
# umedusade
#
# pkg-config --cflags --libs umedusade
#

# build umedusade INCLUDEPATH
#
build_umedusade_INCLUDEPATH += \

# build umedusade DEFINES
#
build_umedusade_DEFINES += \

# build umedusade FRAMEWORKS
#
build_umedusade_FRAMEWORKS += \

# build umedusade LIBS
#
build_umedusade_LIBS += \

########################################################################
# utalas

# build utalas INCLUDEPATH
#
build_utalas_INCLUDEPATH += \
$${build_umedusade_INCLUDEPATH} \
$${build_ustara_INCLUDEPATH} \
$${build_urete_INCLUDEPATH} \
$${build_ucifra_INCLUDEPATH} \
$${build_ucrono_INCLUDEPATH} \
$${build_ufila_INCLUDEPATH} \
$${build_unadir_INCLUDEPATH} \
$${build_urostra_INCLUDEPATH} \
$${build_ump_INCLUDEPATH} \
$${build_ubn_INCLUDEPATH} \


# build utalas DEFINES
#
build_utalas_DEFINES += \
$${build_ubn_DEFINES} \
$${build_ump_DEFINES} \
$${build_urostra_DEFINES} \
$${build_unadir_DEFINES} \
$${build_ufila_DEFINES} \
$${build_ucrono_DEFINES} \
$${build_ucifra_DEFINES} \
$${build_urete_DEFINES} \
$${build_ustara_DEFINES} \
$${build_umedusade_DEFINES} \


# build utalas FRAMEWORKS
#
build_utalas_FRAMEWORKS += \
$${build_umedusade_FRAMEWORKS} \
$${build_ustara_FRAMEWORKS} \
$${build_urete_FRAMEWORKS} \
$${build_ucifra_FRAMEWORKS} \
$${build_ucrono_FRAMEWORKS} \
$${build_ufila_FRAMEWORKS} \
$${build_unadir_FRAMEWORKS} \
$${build_urostra_FRAMEWORKS} \
$${build_ump_FRAMEWORKS} \
$${build_ubn_FRAMEWORKS} \


# build utalas LIBS
#
build_utalas_LIBS += \
$${build_umedusade_LIBS} \
$${build_ustara_LIBS} \
$${build_urete_LIBS} \
$${build_ucifra_LIBS} \
$${build_ucrono_LIBS} \
$${build_ufila_LIBS} \
$${build_unadir_LIBS} \
$${build_urostra_LIBS} \
$${build_ump_LIBS} \
$${build_ubn_LIBS} \

########################################################################
