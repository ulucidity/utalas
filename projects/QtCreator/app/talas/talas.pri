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
#   File: talas.pri
#
# Author: $author$
#   Date: 5/11/2022
#
# generic QtCreator project .pri file for framework utalas executable talas
########################################################################

########################################################################
# talas

# talas TARGET
#
talas_TARGET = talas

# talas INCLUDEPATH
#
talas_INCLUDEPATH += \
$${utalas_INCLUDEPATH} \

# talas DEFINES
#
talas_DEFINES += \
$${utalas_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \
XOS_CONSOLE_MAIN_MAIN \

########################################################################
# talas OBJECTIVE_HEADERS
#
#talas_OBJECTIVE_HEADERS += \
#$${UTALAS_SRC}/xos/app/console/talas/version/main.hh \

# talas OBJECTIVE_SOURCES
#
#talas_OBJECTIVE_SOURCES += \
#$${UTALAS_SRC}/xos/app/console/talas/version/main.mm \

########################################################################
# talas HEADERS
#
talas_HEADERS += \
$${UTALAS_SRC}/xos/app/console/talas/version/main_opt.hpp \
$${UTALAS_SRC}/xos/app/console/talas/version/main.hpp \

# talas SOURCES
#
talas_SOURCES += \
$${UTALAS_SRC}/xos/app/console/talas/version/main_opt.cpp \
$${UTALAS_SRC}/xos/app/console/talas/version/main.cpp \

########################################################################
# talas FRAMEWORKS
#
talas_FRAMEWORKS += \
$${utalas_FRAMEWORKS} \

# talas LIBS
#
talas_LIBS += \
$${utalas_LIBS} \

########################################################################
# NO Qt
QT -= gui core

