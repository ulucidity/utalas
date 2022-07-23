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
///   Date: 2/11/2022, 6/1/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_PROTOCOL_TLS_PKCS1_ENCODED_MESSAGE_HPP
#define XOS_PROTOCOL_TLS_PKCS1_ENCODED_MESSAGE_HPP

#include "xos/protocol/tls/message/part.hpp"
#include "xos/protocol/tls/pseudo/random/reader.hpp"
#include "xos/protocol/crypto/random/reader.hpp"

namespace xos {
namespace protocol {
namespace tls {
namespace pkcs1 {
namespace encoded {

/// class messaget
template 
<class TRandomReader = xos::protocol::crypto::random::reader, 
 class TPseudoRandomReader = tls::pseudo::random::reader, 
 class TMessagePart = tls::message::part, class TExtends = TMessagePart, class TImplements = typename TExtends::implements>

class exported messaget: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef messaget derives; 
    
    typedef TRandomReader random_reader_t;
    typedef TPseudoRandomReader pseudo_random_reader_t;
    typedef TMessagePart message_part_t;
    
    /// constructors / destructor
    messaget(const messaget& copy): extends(copy) {
    }
    messaget(const size_t& modulus_size, const message_part_t& message, random_reader_t& random_reader) {
        combine(modulus_size, message, random_reader);
    }
    messaget(const size_t& modulus_size, const message_part_t& message, pseudo_random_reader_t& pseudo_random_reader) {
        combine(modulus_size, message, pseudo_random_reader);
    }
    messaget(const message_part_t& message_part): extends(message_part) {
    }
    messaget() {
    }
    virtual ~messaget() {
    }
    
    /// combine / separate
    virtual bool combine(const size_t& modulus_size, const message_part_t& message, random_reader_t& random_reader) {
        bool success = combine<random_reader_t>(modulus_size, message, random_reader);
        return success;
    }
    virtual bool combine(const size_t& modulus_size, const message_part_t& message, pseudo_random_reader_t& pseudo_random_reader) {
        bool success = combine<pseudo_random_reader_t>(modulus_size, message, pseudo_random_reader);
        return success;
    }
    template <class pseudo_random_reader_t>
    bool combine(const size_t& modulus_size, const message_part_t& message, pseudo_random_reader_t& pseudo_random_reader) {
        bool success = false;
        const byte_t* message_bytes = 0; size_t message_length = 0;

        if ((modulus_size) && (message_bytes = message.has_elements(message_length))) {

            if (message_length <= (modulus_size - 11)) {
                size_t pseudo_random_length = (modulus_size - message_length - 3);

                if ((pseudo_random_.set_length(pseudo_random_length))) {
                    byte_t* pseudo_random_bytes = 0;
                    
                    if ((pseudo_random_bytes = pseudo_random_.has_elements(pseudo_random_length))) {
                        
                        if (pseudo_random_length <= (pseudo_random_reader.read(pseudo_random_bytes, pseudo_random_length))) {
                            const byte_t b00 = 0x00, b02 = 0x02;

                            this->assign(&b00, 1);
                            this->append(&b02, 1);
                            this->append(pseudo_random_bytes, pseudo_random_length);
                            this->append(&b00, 1);
                            this->append(message_bytes, message_length);
                            success = true;
                        }
                    }
                }
            }
        }
        return success;
    }
    virtual bool separate() {
        bool success = false;
        return success;
    }

protected:
    message_part_t pseudo_random_;
}; /// class messaget
typedef messaget<> message;

} /// namespace encoded
} /// namespace pkcs1
} /// namespace tls
} /// namespace protocol
} /// namespace xos

#endif /// XOS_PROTOCOL_TLS_PKCS1_ENCODED_MESSAGE_HPP
