///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2022 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: logger.hpp
///
/// Author: $author$
///   Date: 5/2/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_PROTOCOL_TLS_IO_LOGGER_HPP
#define XOS_PROTOCOL_TLS_IO_LOGGER_HPP

#include "xos/protocol/tls/io/io.hpp"
#include "xos/base/logged.hpp"
#include "xos/io/logger.hpp"

#define TLS_LOG_ANY XOS_LOG_ANY
#define TLS_LOG_FATAL XOS_LOG_FATAL
#define TLS_LOG_ERROR XOS_LOG_ERROR
#define TLS_LOG_WARN XOS_LOG_WARN
#define TLS_LOG_INFO XOS_LOG_INFO
#define TLS_LOG_DEBUG XOS_LOG_DEBUG
#define TLS_LOG_TRACE XOS_LOG_TRACE

#define TLS_LOG_ANYF XOS_LOG_ANYF
#define TLS_LOG_FATALF XOS_LOG_FATALF
#define TLS_LOG_ERRORF XOS_LOG_ERRORF
#define TLS_LOG_WARNF XOS_LOG_WARNF
#define TLS_LOG_INFOF XOS_LOG_INFOF
#define TLS_LOG_DEBUGF XOS_LOG_DEBUGF
#define TLS_LOG_TRACEF XOS_LOG_TRACEF

#define TLS_LOG_MESSAGE_ANY XOS_LOG_MESSAGE_ANY
#define TLS_LOG_MESSAGE_FATAL XOS_LOG_MESSAGE_FATAL
#define TLS_LOG_MESSAGE_ERROR XOS_LOG_MESSAGE_ERROR
#define TLS_LOG_MESSAGE_WARN XOS_LOG_MESSAGE_WARN
#define TLS_LOG_MESSAGE_INFO XOS_LOG_MESSAGE_INFO
#define TLS_LOG_MESSAGE_DEBUG XOS_LOG_MESSAGE_DEBUG
#define TLS_LOG_MESSAGE_TRACE XOS_LOG_MESSAGE_TRACE

#define TLS_LOG_MESSAGE_ANYF XOS_LOG_MESSAGE_ANYF
#define TLS_LOG_MESSAGE_FATALF XOS_LOG_MESSAGE_FATALF
#define TLS_LOG_MESSAGE_ERRORF XOS_LOG_MESSAGE_ERRORF
#define TLS_LOG_MESSAGE_WARNF XOS_LOG_MESSAGE_WARNF
#define TLS_LOG_MESSAGE_INFOF XOS_LOG_MESSAGE_INFOF
#define TLS_LOG_MESSAGE_DEBUGF XOS_LOG_MESSAGE_DEBUGF
#define TLS_LOG_MESSAGE_TRACEF XOS_LOG_MESSAGE_TRACEF

namespace xos {
namespace protocol {
namespace tls {
namespace io {

typedef xos::base::logged logged;

} /// namespace io
} /// namespace tls
} /// namespace protocol
} /// namespace xos

#endif /// ndef XOS_PROTOCOL_TLS_IO_LOGGER_HPP
