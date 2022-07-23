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
#ifndef XOS_PROTOCOL_TLS_RSA_IMPLEMENTED_PRIVATE_KEY_HPP
#define XOS_PROTOCOL_TLS_RSA_IMPLEMENTED_PRIVATE_KEY_HPP

#include "xos/protocol/tls/rsa/bn/private_key.hpp"
#include "xos/protocol/tls/rsa/gmp/private_key.hpp"

namespace xos {
namespace protocol {
namespace tls {
namespace rsa {
namespace implemented {

typedef int which_private_key_t;
enum {
    bn_private_key,
    gmp_private_key
};

/// class private_keyt
template 
<typename TWhichPrivateKey = which_private_key_t, 
 TWhichPrivateKey VBnPrivateKey = bn_private_key, 
 TWhichPrivateKey VGmpPrivateKey = gmp_private_key, 
 TWhichPrivateKey VWhichPrivateKey = VBnPrivateKey, 
 class TBnPrivateKey = tls::rsa::bn::private_key, 
 class TGmpPrivateKey = tls::rsa::gmp::private_key, 
 class TPrivateKey = tls::rsa::private_key, 
 class TExtends = extend, class TImplements = TPrivateKey>

class exported private_keyt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef private_keyt derives; 
    
    typedef TPrivateKey private_key_t;
    typedef TBnPrivateKey bn_private_key_t;
    typedef TGmpPrivateKey gmp_private_key_t;
    typedef TWhichPrivateKey which_private_key_t;
    enum { 
        bn_private_key = VBnPrivateKey, 
        gmp_private_key = VGmpPrivateKey,
        which_private_key = VWhichPrivateKey
    };

    /// constructors / destructor
    private_keyt(const private_keyt& copy): extends(copy) {
    }
    private_keyt
    (const byte_t *p, const byte_t *q,
     const byte_t *dmp1, const byte_t *dmq1,
     const byte_t *iqmp, size_t p_size)
     : which_private_key_(which_private_key),
       bn_private_key_(p, q, dmp1, dmq1, iqmp, p_size/*),
       gmp_private_key_(p, q, dmp1, dmq1, iqmp, p_size*/) {
    }
    private_keyt(): which_private_key_(which_private_key) {
    }
    virtual ~private_keyt() {
    }

    /// operate
    virtual ssize_t operate(void* out, size_t outsize, const void* in, size_t inlen) {
        ssize_t size = 0;
        size = bn_private_key_(out, outsize, in, inlen);
        return size;
    }

    /// p_size
    virtual size_t p_size() const {
        size_t size = 0;
        size = bn_private_key_.p_size();
        return size;
    }

protected:
    which_private_key_t which_private_key_;
    bn_private_key_t bn_private_key_;
    //gmp_private_key_t gmp_private_key_;
}; /// class private_keyt
typedef private_keyt<> private_key;

} /// namespace implemented
} /// namespace rsa
} /// namespace tls
} /// namespace protocol
} /// namespace xos

#endif /// XOS_PROTOCOL_TLS_RSA_IMPLEMENTED_PRIVATE_KEY_HPP
