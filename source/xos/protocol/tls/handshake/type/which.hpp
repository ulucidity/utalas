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
///   File: which.hpp
///
/// Author: $author$
///   Date: 2/2/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_PROTOCOL_TLS_HANDSHAKE_TYPE_WHICH_HPP
#define XOS_PROTOCOL_TLS_HANDSHAKE_TYPE_WHICH_HPP

#include "xos/protocol/tls/message/part.hpp"

namespace xos {
namespace protocol {
namespace tls {
namespace handshake {
namespace type {

/// enum which
typedef uint8_t which;
enum {
    hello_request = (0), 
    client_hello = (1), 
    server_hello = (2),
    certificate = (11), 
    server_key_exchange = (12),
    certificate_request = (13), 
    server_hello_done = (14),
    certificate_verify = (15), 
    client_key_exchange = (16),
    finished = (20), 
    none = (255)
}; /// which
     
} /// namespace type
} /// namespace handshake
} /// namespace tls
} /// namespace protocol
} /// namespace xos

#endif /// XOS_PROTOCOL_TLS_HANDSHAKE_TYPE_WHICH_HPP
