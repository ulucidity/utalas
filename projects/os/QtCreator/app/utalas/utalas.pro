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
#   File: utalas.pro
#
# Author: $author$
#   Date: 5/11/2022
#
# os specific QtCreator project .pro file for framework utalas executable utalas
########################################################################
#
# Debug: utalas/build/os/QtCreator/Debug/bin/utalas
# Release: utalas/build/os/QtCreator/Release/bin/utalas
# Profile: utalas/build/os/QtCreator/Profile/bin/utalas
#
include(../../../../../build/QtCreator/utalas.pri)
include(../../../../QtCreator/utalas.pri)
include(../../utalas.pri)
include(../../../../QtCreator/app/utalas/utalas.pri)

TARGET = $${utalas_exe_TARGET}

########################################################################
# INCLUDEPATH
#
INCLUDEPATH += \
$${utalas_exe_INCLUDEPATH} \

# DEFINES
# 
DEFINES += \
$${utalas_exe_DEFINES} \

########################################################################
# OBJECTIVE_HEADERS
#
OBJECTIVE_HEADERS += \
$${utalas_exe_OBJECTIVE_HEADERS} \

# OBJECTIVE_SOURCES
#
OBJECTIVE_SOURCES += \
$${utalas_exe_OBJECTIVE_SOURCES} \

########################################################################
# HEADERS
#
HEADERS += \
$${utalas_exe_HEADERS} \
$${utalas_exe_OBJECTIVE_HEADERS} \

# SOURCES
#
SOURCES += \
$${utalas_exe_SOURCES} \

########################################################################
# FRAMEWORKS
#
FRAMEWORKS += \
$${utalas_exe_FRAMEWORKS} \

# LIBS
#
LIBS += \
$${utalas_exe_LIBS} \
$${FRAMEWORKS} \

########################################################################

