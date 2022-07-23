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
///   Date: 2/11/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_PROTOCOL_TLS_RSA_IMPLEMENTED_PUBLIC_KEY_HPP
#define XOS_PROTOCOL_TLS_RSA_IMPLEMENTED_PUBLIC_KEY_HPP

#include "xos/protocol/tls/rsa/bn/public_key.hpp"
#include "xos/protocol/tls/rsa/gmp/public_key.hpp"

namespace xos {
namespace protocol {
namespace tls {
namespace rsa {
namespace implemented {

typedef int which_public_key_t;
enum {
    bn_public_key,
    gmp_public_key
};

/// class public_keyt
template 
<typename TWhichPublicKey = which_public_key_t, 
 TWhichPublicKey VBnPublicKey = bn_public_key, 
 TWhichPublicKey VGmpPublicKey = gmp_public_key, 
 TWhichPublicKey VWhichPublicKey = VBnPublicKey, 
 class TPublicKey = tls::rsa::public_key, 
 class TBnPublicKey = tls::rsa::bn::public_key, 
 class TGmpPublicKey = tls::rsa::gmp::public_key, 
 class TExtends = extend, class TImplements = TPublicKey>

class exported public_keyt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef public_keyt derives; 
    
    typedef TPublicKey public_key_t;
    typedef TBnPublicKey bn_public_key_t;
    typedef TGmpPublicKey gmp_public_key_t;
    typedef TWhichPublicKey which_public_key_t;
    enum { 
        bn_public_key = VBnPublicKey, 
        gmp_public_key = VGmpPublicKey,
        which_public_key = VWhichPublicKey
    };
    
    /// constructors / destructor
    public_keyt(const public_keyt& copy): extends(copy) {
    }
    public_keyt
    (const byte_t* modulus, size_t modulus_size, 
     const byte_t* exponent, size_t exponent_size, const which_public_key_t& which_public_key)
    : which_public_key_(which_public_key), 
      bn_public_key_(modulus, modulus_size, exponent, exponent_size),
      gmp_public_key_(modulus, modulus_size, exponent, exponent_size) {
    }
    public_keyt
    (const byte_t* modulus, size_t modulus_size, const byte_t* exponent, size_t exponent_size)
    : which_public_key_(which_public_key), 
      bn_public_key_(modulus, modulus_size, exponent, exponent_size),
      gmp_public_key_(modulus, modulus_size, exponent, exponent_size) {
    }
    public_keyt(): which_public_key_(which_public_key) {
    }
    virtual ~public_keyt() {
    }
    
    /// operate
    virtual ssize_t operate(void* out, size_t outsize, const void* in, size_t inlen) {
        ssize_t size = 0;
        size = bn_public_key_(out, outsize, in, inlen);
        return size;
    }

    /// modulus_size
    virtual size_t modulus_size() const {
        size_t size = 0;
        size = bn_public_key_.modulus_size();
        return size;
    }

protected:
    which_public_key_t which_public_key_;
    bn_public_key_t bn_public_key_;
    gmp_public_key_t gmp_public_key_;
}; /// class public_keyt
typedef public_keyt<> public_key;

} /// namespace implemented
} /// namespace rsa
} /// namespace tls
} /// namespace protocol
} /// namespace xos

#endif /// XOS_PROTOCOL_TLS_RSA_IMPLEMENTED_PUBLIC_KEY_HPP
