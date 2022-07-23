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
///   File: message.hpp
///
/// Author: $author$
///   Date: 2/16/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_PROTOCOL_TLS_PKCS1_DECODED_MESSAGE_HPP
#define XOS_PROTOCOL_TLS_PKCS1_DECODED_MESSAGE_HPP

#include "xos/protocol/tls/pkcs1/encoded/message.hpp"

namespace xos {
namespace protocol {
namespace tls {
namespace pkcs1 {
namespace decoded {

/// class messaget
template 
<class TPkcs1EncodedMessage = tls::pkcs1::encoded::message, 
 class TMessagePart = tls::message::part, class TExtends = TMessagePart, class TImplements = typename TExtends::implements>

class exported messaget: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef messaget derives; 
    
    typedef TPkcs1EncodedMessage pkcs1_encoded_message_t;
    typedef TMessagePart message_part_t;

    /// constructors / destructor
    messaget(const messaget& copy): extends(copy), combine_(0) {
    }
    messaget(const pkcs1_encoded_message_t& pkcs1_encoded_message): combine_(0) {
        combine(pkcs1_encoded_message);
    }
    messaget(): combine_(0) {
    }
    virtual ~messaget() {
    }

    /// combine / separate
    virtual bool combine(const pkcs1_encoded_message_t& pkcs1_encoded_message) {
        bool success = false;
        const byte_t* bytes = 0; size_t length = 0;

        this->set_length(0);
        if ((bytes = pkcs1_encoded_message.has_elements(length))) {
            byte_t byte = 0;

            combine_ = 0;
            for (size_t remain = length; remain; --remain, ++bytes) {
                if ((combine(byte = *bytes))) {
                    continue;
                }
                return false;
            }
            success = true;
        }
        return success;
    }
    virtual bool separate() {
        bool success = false;
        return success;
    }

protected:
    bool (derives::*combine_)(const byte_t& byte);
    virtual bool combine(const byte_t& byte) {
        bool success = false;
        if ((combine_)) {
            success = (this->*combine_)(byte);
        } else {
            if (!(0x00 != byte)) {
                combine_ = &derives::combine_0x00;
                success = true;
            }
        }
        return success;
    }
    virtual bool combine_0x00(const byte_t& byte) {
        bool success = false;
        if (!(0x02 != byte)) {
            combine_ = &derives::combine_0x02;
            success = true;
        }
        return success;
    }
    virtual bool combine_0x02(const byte_t& byte) {
        bool success = true;
        if (!(0x00 != byte)) {
            combine_ = &derives::combine_message;
        }
        return success;
    }
    virtual bool combine_message(const byte_t& byte) {
        bool success = true;
        this->append(&byte, 1);
        return success;
    }
}; /// class messaget
typedef messaget<> message;

} /// namespace decoded
} /// namespace pkcs1
} /// namespace tls
} /// namespace protocol
} /// namespace xos

#endif /// XOS_PROTOCOL_TLS_PKCS1_DECODED_MESSAGE_HPP
