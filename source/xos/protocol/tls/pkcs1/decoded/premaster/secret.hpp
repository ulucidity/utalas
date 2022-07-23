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
///   Date: 5/22/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_PROTOCOL_TLS_PKCS1_DECODED_PREMASTER_SECRET_HPP
#define XOS_PROTOCOL_TLS_PKCS1_DECODED_PREMASTER_SECRET_HPP

#include "xos/protocol/tls/pkcs1/decoded/message.hpp"
#include "xos/protocol/tls/pkcs1/encoded/premaster/secret.hpp"
#include "xos/protocol/tls/premaster/secret/message.hpp"

namespace xos {
namespace protocol {
namespace tls {
namespace pkcs1 {
namespace decoded {
namespace premaster {

/// class secrett
template 
<class TPkcs1DecodedMessage = tls::pkcs1::decoded::message, 
 class TPkcs1EncodedPremasterSecret = tls::pkcs1::encoded::premaster::secret, 
 class TPremasterSecret = tls::premaster::secret::message, 
 class TExtends = TPremasterSecret, class TImplements = typename TExtends::implements>

class exported secrett: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef secrett derives; 
    
    typedef TPkcs1DecodedMessage pkcs1_decoded_message_t;
    typedef TPkcs1EncodedPremasterSecret pkcs1_encoded_premaster_secret_t;
    typedef TPremasterSecret premaster_secret_t;

    typedef typename premaster_secret_t::size_of_t premaster_secret_sizeof_t;
    enum { premaster_secret_sizeof = premaster_secret_t::size_of };

    /// constructors / destructor
    secrett(const secrett& copy): extends(copy) {
    }
    secrett(const pkcs1_encoded_premaster_secret_t& pkcs1_encoded_premaster_secret) {
        combine(pkcs1_encoded_premaster_secret);
    }
    secrett() {
    }
    virtual ~secrett() {
    }

    /// combine / separate
    virtual bool combine(const pkcs1_encoded_premaster_secret_t& pkcs1_encoded_premaster_secret) {
        bool success = false;
        pkcs1_decoded_message_t pkcs1_decoded_message(pkcs1_encoded_premaster_secret);
        const byte_t* bytes = 0; size_t length = 0;
        
        this->set_length(0);
        if ((bytes = pkcs1_decoded_message.has_elements(length)) && (premaster_secret_sizeof == length)) {
            this->assign(pkcs1_decoded_message);
            if ((bytes = this->has_elements(length))) {
                success = true;
            }
        }
        return success;
    }
    virtual bool separate() {
        bool success = false;
        return success;
    }

}; /// class secrett
typedef secrett<> secret;

} /// namespace premaster
} /// namespace decoded
} /// namespace pkcs1
} /// namespace tls
} /// namespace protocol
} /// namespace xos

#endif /// ndef XOS_PROTOCOL_TLS_PKCS1_DECODED_PREMASTER_SECRET_HPP
