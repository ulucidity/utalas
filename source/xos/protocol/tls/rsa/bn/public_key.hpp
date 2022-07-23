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
#ifndef XOS_PROTOCOL_TLS_RSA_BN_PUBLIC_KEY_HPP
#define XOS_PROTOCOL_TLS_RSA_BN_PUBLIC_KEY_HPP

#include "xos/protocol/tls/rsa/public_key.hpp"
#include "xos/crypto/rsa/bn/public_key.hpp"

namespace xos {
namespace protocol {
namespace tls {
namespace rsa {
namespace bn {

/// class public_keyt
template 
<class TPublicKey = tls::rsa::public_key, 
 class TBnPublicKey = xos::crypto::rsa::bn::public_key, 
 class TExtends = extend, class TImplements = TPublicKey>

class exported public_keyt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef public_keyt derives; 
    
    typedef TBnPublicKey bn_public_key_t;
    
    /// constructors / destructor
    public_keyt(const public_keyt& copy): bn_public_key_(copy.bn_public_key_) {
    }
    public_keyt
    (const byte_t* modulus, size_t modulus_size, const byte_t* exponent, size_t exponent_size)
    : bn_public_key_(modulus, modulus_size, exponent, exponent_size) {
    }
    public_keyt() {
    }
    virtual ~public_keyt() {
    }
    
    /// operate
    virtual ssize_t operate(void* out, size_t outsize, const void* in, size_t inlen) {
        ssize_t size = bn_public_key_(out, outsize, in, inlen);
        return size;
    }

    /// modulus_size
    virtual size_t modulus_size() const {
        size_t size = bn_public_key_.modbytes();
        return size;
    }

protected:
    bn_public_key_t bn_public_key_;
}; /// class public_keyt
typedef public_keyt<> public_key;

} /// namespace bn
} /// namespace rsa
} /// namespace tls
} /// namespace protocol
} /// namespace xos

#endif /// XOS_PROTOCOL_TLS_RSA_BN_PUBLIC_KEY_HPP
