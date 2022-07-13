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
#   Date: 7/11/2022
#
# generic QtCreator project .pri file for framework utalas executable utalas
########################################################################

########################################################################
# utalas

# utalas_exe TARGET
#
utalas_exe_TARGET = utalas

# utalas_exe INCLUDEPATH
#
utalas_exe_INCLUDEPATH += \
$${utalas_INCLUDEPATH} \

# utalas_exe DEFINES
#
utalas_exe_DEFINES += \
$${utalas_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \
XOS_CONSOLE_MAIN_MAIN \

########################################################################
# utalas_exe OBJECTIVE_HEADERS
#
#utalas_exe_OBJECTIVE_HEADERS += \
#$${UTALAS_SRC}/xos/app/console/utalas/version/main.hh \

# utalas_exe OBJECTIVE_SOURCES
#
#utalas_exe_OBJECTIVE_SOURCES += \
#$${UTALAS_SRC}/xos/app/console/utalas/version/main.mm \

########################################################################
# utalas_exe HEADERS
#
utalas_exe_HEADERS += \
$${UTALAS_SRC}/xos/app/console/utalas/version/main_opt.hpp \
$${UTALAS_SRC}/xos/app/console/utalas/version/main.hpp \

# utalas_exe SOURCES
#
utalas_exe_SOURCES += \
$${UTALAS_SRC}/xos/app/console/utalas/version/main_opt.cpp \
$${UTALAS_SRC}/xos/app/console/utalas/version/main.cpp \

########################################################################
# utalas_exe FRAMEWORKS
#
utalas_exe_FRAMEWORKS += \
$${utalas_rsa_FRAMEWORKS} \

# utalas_exe LIBS
#
utalas_exe_LIBS += \
$${utalas_rsa_LIBS} \

########################################################################
# NO Qt
QT -= gui core
