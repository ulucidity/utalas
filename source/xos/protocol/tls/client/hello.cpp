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
///   File: hello.cpp
///
/// Author: $author$
///   Date: 3/11/2022
///////////////////////////////////////////////////////////////////////
#include "xos/protocol/tls/client/hello.hpp"

#if !defined(XOS_PROTOCOL_TLS_CLIENT_HELLO_INSTANCE)
///#define XOS_PROTOCOL_TLS_CLIENT_HELLO_INSTANCE
#endif /// !defined(XOS_PROTOCOL_TLS_CLIENT_HELLO_INSTANCE)

namespace xos {
namespace protocol {
namespace tls {
namespace client {

///  Class: hellot
#if defined(XOS_PROTOCOL_TLS_CLIENT_HELLO_INSTANCE)
static hello the_hello;
#endif /// defined(XOS_PROTOCOL_TLS_CLIENT_HELLO_INSTANCE)

} /// namespace client
} /// namespace tls
} /// namespace protocol
} /// namespace xos
