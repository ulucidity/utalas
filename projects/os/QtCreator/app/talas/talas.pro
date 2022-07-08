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
#   File: talas.pro
#
# Author: $author$
#   Date: 5/11/2022
#
# os specific QtCreator project .pro file for framework utalas executable talas
########################################################################
#
# Debug: utalas/build/os/QtCreator/Debug/bin/talas
# Release: utalas/build/os/QtCreator/Release/bin/talas
# Profile: utalas/build/os/QtCreator/Profile/bin/talas
#
include(../../../../../build/QtCreator/utalas.pri)
include(../../../../QtCreator/utalas.pri)
include(../../utalas.pri)
include(../../../../QtCreator/app/talas/talas.pri)

TARGET = $${talas_TARGET}

########################################################################
# INCLUDEPATH
#
INCLUDEPATH += \
$${talas_INCLUDEPATH} \

# DEFINES
# 
DEFINES += \
$${talas_DEFINES} \

########################################################################
# OBJECTIVE_HEADERS
#
OBJECTIVE_HEADERS += \
$${talas_OBJECTIVE_HEADERS} \

# OBJECTIVE_SOURCES
#
OBJECTIVE_SOURCES += \
$${talas_OBJECTIVE_SOURCES} \

########################################################################
# HEADERS
#
HEADERS += \
$${talas_HEADERS} \
$${talas_OBJECTIVE_HEADERS} \

# SOURCES
#
SOURCES += \
$${talas_SOURCES} \

########################################################################
# FRAMEWORKS
#
FRAMEWORKS += \
$${talas_FRAMEWORKS} \

# LIBS
#
LIBS += \
$${talas_LIBS} \
$${FRAMEWORKS} \

########################################################################

