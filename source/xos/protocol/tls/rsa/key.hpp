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
///   File: key.hpp
///
/// Author: $author$
///   Date: 2/10/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_PROTOCOL_TLS_RSA_KEY_HPP
#define XOS_PROTOCOL_TLS_RSA_KEY_HPP

#include "xos/base/base.hpp"

namespace xos {
namespace protocol {
namespace tls {
namespace rsa {

/// class keyt
template <class TImplements = implement>
class exported keyt: virtual public TImplements {
public:
    typedef TImplements implements;
    typedef keyt derives; 
    
    /// constructors / destructor
    virtual ~keyt() {
    }

    /// operat...
    virtual ssize_t operate(void* out, size_t outsize, const void* in, size_t inlen) {
        return 0;
    }
    virtual ssize_t operator()(void* out, size_t outsize, const void* in, size_t inlen) {
        return operate(out, outsize, in, inlen);
    }

    /// modulus_size
    virtual size_t modulus_size() const {
        return 0;
    }
}; /// class keyt
typedef keyt<> key;

} /// namespace rsa
} /// namespace tls
} /// namespace protocol
} /// namespace xos

#endif /// XOS_PROTOCOL_TLS_RSA_KEY_HPP
