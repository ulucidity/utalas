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
#   File: ursa.pri
#
# Author: $author$
#   Date: 7/11/2022
#
# generic QtCreator project .pri file for framework utalas executable ursa
########################################################################

########################################################################
# ursa

# ursa TARGET
#
ursa_TARGET = ursa

# ursa INCLUDEPATH
#
ursa_INCLUDEPATH += \
$${utalas_INCLUDEPATH} \

# ursa DEFINES
#
ursa_DEFINES += \
$${utalas_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \
XOS_CONSOLE_MAIN_MAIN \

########################################################################
# ursa OBJECTIVE_HEADERS
#
#ursa_OBJECTIVE_HEADERS += \
#$${UTALAS_SRC}/xos/app/console/ursa/main.hh \

# ursa OBJECTIVE_SOURCES
#
#ursa_OBJECTIVE_SOURCES += \
#$${UTALAS_SRC}/xos/app/console/ursa/main.mm \

########################################################################
# ursa HEADERS
#
ursa_HEADERS += \
$${UCIFRA_SRC}/xos/crypto/random/prime/small_primes.hpp \
\
$${UTALAS_CRD_SRC}/xos/app/console/crypto/rsa/key_pair.hpp \
$${UTALAS_CRD_SRC}/xos/app/console/crypto/rsa/key_pair_const.hpp \
$${UTALAS_CRD_SRC}/xos/app/console/crypto/rsa/private_key.hpp \
$${UTALAS_CRD_SRC}/xos/app/console/crypto/rsa/private_key_const.hpp \
$${UTALAS_CRD_SRC}/xos/app/console/crypto/rsa/public_key.hpp \
$${UTALAS_CRD_SRC}/xos/app/console/crypto/rsa/public_key_const.hpp \
$${UTALAS_CRD_SRC}/xos/app/console/crypto/rsa/public_exponent_const.hpp \
\
$${UTALAS_SRC}/xos/app/console/crypto/rsa/base/main_opt.hpp \
$${UTALAS_SRC}/xos/app/console/crypto/rsa/base/main.hpp \
\
$${UTALAS_SRC}/xos/app/console/crypto/rsa/pair/key_define.hpp \
$${UTALAS_SRC}/xos/app/console/crypto/rsa/pair/main_opt.hpp \
$${UTALAS_SRC}/xos/app/console/crypto/rsa/pair/main.hpp \
\
$${UTALAS_SRC}/xos/app/console/crypto/rsa/operate/main_opt.hpp \
$${UTALAS_SRC}/xos/app/console/crypto/rsa/operate/main.hpp \
\
$${UTALAS_SRC}/xos/app/console/crypto/rsa/test/main_opt.hpp \
$${UTALAS_SRC}/xos/app/console/crypto/rsa/test/main.hpp \

# ursa SOURCES
#
ursa_SOURCES += \
$${UCIFRA_SRC}/xos/crypto/random/prime/small_primes.cpp \
\
$${UTALAS_CRD_SRC}/xos/app/console/crypto/rsa/key_pair.cpp \
$${UTALAS_CRD_SRC}/xos/app/console/crypto/rsa/private_key.cpp \
$${UTALAS_CRD_SRC}/xos/app/console/crypto/rsa/public_key.cpp \
$${UTALAS_CRD_SRC}/xos/app/console/crypto/rsa/public_exponent_const.cpp \
\
$${UTALAS_SRC}/xos/app/console/crypto/rsa/pair/key_define.cpp \
$${UTALAS_SRC}/xos/app/console/crypto/rsa/test/main_opt.cpp \
$${UTALAS_SRC}/xos/app/console/crypto/rsa/test/main.cpp \

########################################################################
# ursa FRAMEWORKS
#
ursa_FRAMEWORKS += \
$${utalas_rsa_FRAMEWORKS} \

# ursa LIBS
#
ursa_LIBS += \
$${utalas_rsa_LIBS} \

########################################################################
# NO Qt
QT -= gui core

