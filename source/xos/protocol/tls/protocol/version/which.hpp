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
///   Date: 4/10/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_PROTOCOL_TLS_PROTOCOL_VERSION_WHICH_HPP
#define XOS_PROTOCOL_TLS_PROTOCOL_VERSION_WHICH_HPP

#include "xos/protocol/tls/message/part.hpp"

namespace xos {
namespace protocol {
namespace tls {
namespace protocol {

/// enum version_which_t
typedef uint16_t version_which_t;
enum {
    version_10 = 0x0301,
    version_11 = 0x0302,
    version_12 = 0x0303,
    version_13 = 0x0304,
    
    version_major_shift = 8,
    version_major_mask  = 0xff,
    
    version_minor_shift = 0,
    version_minor_mask  = 0xff
}; /// enum version_which_t

} /// namespace protocol
} /// namespace tls
} /// namespace protocol
} /// namespace xos

#endif /// XOS_PROTOCOL_TLS_PROTOCOL_VERSION_WHICH_HPP
