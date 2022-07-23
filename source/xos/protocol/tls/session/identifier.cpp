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
///   File: identifier.cpp
///
/// Author: $author$
///   Date: 2/7/2022
///////////////////////////////////////////////////////////////////////
#include "xos/protocol/tls/session/identifier.hpp"

#if !defined(XOS_PROTOCOL_TLS_SESSION_IDENTIFIER_INSTANCE)
///#define XOS_PROTOCOL_TLS_SESSION_IDENTIFIER_INSTANCE
#endif /// !defined(XOS_PROTOCOL_TLS_SESSION_IDENTIFIER_INSTANCE)

namespace xos {
namespace protocol {
namespace tls {
namespace session {

///  Class: identifiert
#if defined(XOS_PROTOCOL_TLS_SESSION_IDENTIFIER_INSTANCE)
static identifier the_identifier;
#endif /// defined(XOS_PROTOCOL_TLS_SESSION_IDENTIFIER_INSTANCE)


} /// namespace session
} /// namespace tls
} /// namespace protocol
} /// namespace xos
