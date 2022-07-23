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
///   File: ciphertext.hpp
///
/// Author: $author$
///   Date: 2/25/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_PROTOCOL_TLS_CIPHERTEXT_HPP
#define XOS_PROTOCOL_TLS_CIPHERTEXT_HPP

#include "xos/protocol/tls/message/part.hpp"

namespace xos {
namespace protocol {
namespace tls {

/// class ciphertextt
template <class TMessagePart = tls::message::part, class TExtends = TMessagePart, class TImplements = typename TExtends::implements>
class exported ciphertextt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef ciphertextt derives; 
    
    /// constructors / destructor
    ciphertextt(const ciphertextt& copy): extends(copy) {
    }
    ciphertextt() {
    }
    virtual ~ciphertextt() {
    }
}; /// class ciphertextt
typedef ciphertextt<> ciphertext;

} /// namespace tls
} /// namespace protocol
} /// namespace xos

#endif /// XOS_PROTOCOL_TLS_CIPHERTEXT_HPP
