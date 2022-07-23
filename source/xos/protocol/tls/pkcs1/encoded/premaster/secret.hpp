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
///   File: secret.hpp
///
/// Author: $author$
///   Date: 2/11/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_PROTOCOL_TLS_PKCS1_ENCODED_PREMASTER_SECRET_HPP
#define XOS_PROTOCOL_TLS_PKCS1_ENCODED_PREMASTER_SECRET_HPP

#include "xos/protocol/tls/pkcs1/encoded/message.hpp"
#include "xos/protocol/tls/premaster/secret/message.hpp"

namespace xos {
namespace protocol {
namespace tls {
namespace pkcs1 {
namespace encoded {
namespace premaster {

/// class secrett
template 
<class TPremasterSecret = tls::premaster::secret::message, 
 class TPkcs1EncodedMessage = tls::pkcs1::encoded::message,
 class TMessagePart = tls::message::part, 
 class TExtends = TPkcs1EncodedMessage, class TImplements = typename TExtends::implements>
class exported secrett: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef secrett derives; 
    
    typedef TMessagePart message_part_t;
    typedef TPremasterSecret premaster_secret_t;
    typedef TPkcs1EncodedMessage pkcs1_encoded_message_t;
    typedef typename pkcs1_encoded_message_t::random_reader_t random_reader_t;
    typedef typename pkcs1_encoded_message_t::pseudo_random_reader_t pseudo_random_reader_t;
    
    /// constructors / destructor
    secrett(const secrett& copy): extends(copy) {
    }
    secrett
    (const size_t& modulus_size, 
     const premaster_secret_t& premaster_secret, random_reader_t& random_reader)
    : extends(modulus_size, premaster_secret, random_reader) {
    }
    secrett
    (const size_t& modulus_size, 
     const premaster_secret_t& premaster_secret, 
     pseudo_random_reader_t& pseudo_random_reader)
    : extends(modulus_size, premaster_secret, pseudo_random_reader) {
    }
    secrett(const message_part_t& message_part): extends(message_part) {
    }
    secrett() {
    }
    virtual ~secrett() {
    }

}; /// class secrett
typedef secrett<> secret;

} /// namespace premaster
} /// namespace encoded
} /// namespace pkcs1
} /// namespace tls
} /// namespace protocol
} /// namespace xos

#endif /// XOS_PROTOCOL_TLS_PKCS1_ENCODED_PREMASTER_SECRET_HPP
