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
#   File: libutalas.pri
#
# Author: $author$
#   Date: 4/1/2022, 5/11/2022
#
# generic QtCreator project .pri file for framework utalas static library libutalas
########################################################################

########################################################################
# libutalas
XOS_LIB_UTALAS_VERSION_BUILD_DATE = 5/11/2022 #$$system(~/bin/utility/tdate)

# libutalas TARGET
#
libutalas_TARGET = utalas
libutalas_TEMPLATE = lib
libutalas_CONFIG += staticlib

# libutalas INCLUDEPATH
#
libutalas_INCLUDEPATH += \
$${utalas_INCLUDEPATH} \

# libutalas DEFINES
#
libutalas_DEFINES += \
$${utalas_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \
XOS_LIB_UTALAS_VERSION_BUILD_DATE=$${XOS_LIB_UTALAS_VERSION_BUILD_DATE} \

########################################################################
# libutalas OBJECTIVE_HEADERS
#
#libutalas_OBJECTIVE_HEADERS += \
#$${UTALAS_SRC}/xos/lib/utalas/version.hh \

# libutalas OBJECTIVE_SOURCES
#
#libutalas_OBJECTIVE_SOURCES += \
#$${UTALAS_SRC}/xos/lib/utalas/version.mm \

########################################################################
# libutalas HEADERS
#
libutalas_HEADERS += \
$${TALAS_SRC}/xos/lib/talas/version.hpp \
$${UTALAS_SRC}/xos/lib/utalas/version.hpp \
$${UTALAS_SRC}/xos/lib/utalas/versions.hpp \

# libutalas SOURCES
#
libutalas_SOURCES += \
$${UTALAS_SRC}/xos/lib/utalas/versions.cpp \

########################################################################

