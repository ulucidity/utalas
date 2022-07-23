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
#   File: ursa.pro
#
# Author: $author$
#   Date: 7/11/2022
#
# os specific QtCreator project .pro file for framework utalas executable ursa
########################################################################
#
# Debug: utalas/build/os/QtCreator/Debug/bin/ursa
# Release: utalas/build/os/QtCreator/Release/bin/ursa
# Profile: utalas/build/os/QtCreator/Profile/bin/ursa
#
include(../../../../../build/QtCreator/utalas.pri)
include(../../../../QtCreator/utalas.pri)
include(../../utalas.pri)
include(../../../../QtCreator/app/ursa/ursa.pri)

TARGET = $${ursa_TARGET}

########################################################################
# INCLUDEPATH
#
INCLUDEPATH += \
$${ursa_INCLUDEPATH} \

# DEFINES
# 
DEFINES += \
$${ursa_DEFINES} \

########################################################################
# OBJECTIVE_HEADERS
#
OBJECTIVE_HEADERS += \
$${ursa_OBJECTIVE_HEADERS} \

# OBJECTIVE_SOURCES
#
OBJECTIVE_SOURCES += \
$${ursa_OBJECTIVE_SOURCES} \

########################################################################
# HEADERS
#
HEADERS += \
$${ursa_HEADERS} \
$${ursa_OBJECTIVE_HEADERS} \

# SOURCES
#
SOURCES += \
$${ursa_SOURCES} \

########################################################################
# FRAMEWORKS
#
FRAMEWORKS += \
$${ursa_FRAMEWORKS} \

# LIBS
#
LIBS += \
$${ursa_LIBS} \
$${FRAMEWORKS} \

########################################################################

