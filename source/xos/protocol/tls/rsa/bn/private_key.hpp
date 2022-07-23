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
///   File: private_key.hpp
///
/// Author: $author$
///   Date: 2/11/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_PROTOCOL_TLS_RSA_BN_PRIVATE_KEY_HPP
#define XOS_PROTOCOL_TLS_RSA_BN_PRIVATE_KEY_HPP

#include "xos/protocol/tls/rsa/private_key.hpp"
#include "xos/crypto/rsa/bn/private_key.hpp"

namespace xos {
namespace protocol {
namespace tls {
namespace rsa {
namespace bn {

/// class private_keyt
template 
<class TBnPrivateKey = xos::crypto::rsa::bn::private_key, 
 class TPrivateKey = tls::rsa::private_key, 
 class TExtends = extend, class TImplements = TPrivateKey>

class exported private_keyt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef private_keyt derives; 
    
    typedef TBnPrivateKey bn_private_key_t;
    
    /// constructors / destructor
    private_keyt(const private_keyt& copy): bn_private_key_(copy.bn_private_key_) {
    }
    private_keyt
    (const byte_t *p, const byte_t *q,
     const byte_t *dmp1, const byte_t *dmq1,
     const byte_t *iqmp, size_t p_size)
    : bn_private_key_(p, q, dmp1, dmq1, iqmp, p_size) {
    }
    private_keyt() {
    }
    virtual ~private_keyt() {
    }

    /// operate
    virtual ssize_t operate(void* out, size_t outsize, const void* in, size_t inlen) {
        ssize_t size = bn_private_key_(out, outsize, in, inlen);
        return size;
    }

    /// p_size
    virtual size_t p_size() const {
        size_t size = bn_private_key_.pbytes();
        return size;
    }

protected:
    bn_private_key_t bn_private_key_;
}; /// class private_keyt
typedef private_keyt<> private_key;

} /// namespace bn
} /// namespace rsa
} /// namespace tls
} /// namespace protocol
} /// namespace xos

#endif /// XOS_PROTOCOL_TLS_RSA_BN_PRIVATE_KEY_HPP
