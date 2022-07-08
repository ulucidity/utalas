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
#   File: libutalas.pro
#
# Author: $author$
#   Date: 4/1/2022
#
# os specific QtCreator project .pro file for framework utalas static library libutalas
########################################################################
#
# Debug: utalas/build/os/QtCreator/Debug/lib/libutalas
# Release: utalas/build/os/QtCreator/Release/lib/libutalas
# Profile: utalas/build/os/QtCreator/Profile/lib/libutalas
#
include(../../../../../build/QtCreator/utalas.pri)
include(../../../../QtCreator/utalas.pri)
include(../../utalas.pri)
include(../../../../QtCreator/lib/libutalas/libutalas.pri)

TARGET = $${libutalas_TARGET}
TEMPLATE = $${libutalas_TEMPLATE}
CONFIG += $${libutalas_CONFIG}

########################################################################
# INCLUDEPATH
#
INCLUDEPATH += \
$${libutalas_INCLUDEPATH} \

# DEFINES
# 
DEFINES += \
$${libutalas_DEFINES} \

########################################################################
# OBJECTIVE_HEADERS
#
OBJECTIVE_HEADERS += \
$${libutalas_OBJECTIVE_HEADERS} \

# OBJECTIVE_SOURCES
#
OBJECTIVE_SOURCES += \
$${libutalas_OBJECTIVE_SOURCES} \

########################################################################
# HEADERS
#
HEADERS += \
$${libutalas_HEADERS} \
$${libutalas_OBJECTIVE_HEADERS} \

# SOURCES
#
SOURCES += \
$${libutalas_SOURCES} \

########################################################################

