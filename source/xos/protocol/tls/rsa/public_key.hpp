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
///   File: public_key.hpp
///
/// Author: $author$
///   Date: 2/10/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_PROTOCOL_TLS_RSA_PUBLIC_KEY_HPP
#define XOS_PROTOCOL_TLS_RSA_PUBLIC_KEY_HPP

#include "xos/protocol/tls/rsa/key.hpp"

namespace xos {
namespace protocol {
namespace tls {
namespace rsa {

/// class public_keyt
template <class TKey = tls::rsa::key, class TImplements = TKey>
class exported public_keyt: virtual public TImplements {
public:
    typedef TImplements implements;
    typedef public_keyt derives; 
    
    /// constructors / destructor
    virtual ~public_keyt() {
    }

    /// exponent_size
    virtual size_t exponent_size() const {
        return 0;
    }
}; /// class public_keyt
typedef public_keyt<> public_key;

} /// namespace rsa
} /// namespace tls
} /// namespace protocol
} /// namespace xos

#endif /// XOS_PROTOCOL_TLS_RSA_PUBLIC_KEY_HPP
