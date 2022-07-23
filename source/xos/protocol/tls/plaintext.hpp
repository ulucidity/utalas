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
///   File: plaintext.hpp
///
/// Author: $author$
///   Date: 3/8/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_PROTOCOL_TLS_PLAINTEXT_HPP
#define XOS_PROTOCOL_TLS_PLAINTEXT_HPP

#include "xos/protocol/tls/message/part.hpp"
#include "xos/protocol/tls/protocol/version.hpp"
#include "xos/protocol/tls/content/type.hpp"
#include "xos/protocol/tls/uinteger.hpp"

namespace xos {
namespace protocol {
namespace tls {

/// class plaintextt
template 
<class TContentType = tls::content::type, 
 class TProtocolVersion = tls::protocol::version, 
 class TUInteger16 = tls::uintegert<uint16_t>,
 class TMessagePart = tls::message::part, class TExtends = TMessagePart, class TImplements = typename TExtends::implements>

class exported plaintextt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef plaintextt derives; 
    
    typedef TContentType type_t;
    typedef TProtocolVersion version_t;
    typedef TUInteger16 fragment_length_t;
    typedef TMessagePart fragment_t;
    
    /// constructors / destructor
    plaintextt(const plaintextt& copy): extends(copy) {
    }
    plaintextt(const type_t& type, const version_t& version, const fragment_t& fragment) {
        combine(type, version, fragment);
    }
    plaintextt() {
    }
    virtual ~plaintextt() {
    }

    /// combine / separate
    virtual bool combine(const type_t& type, const version_t& version, const fragment_t& fragment) {
        bool success = false;
        fragment_length_t fragment_length(fragment.length());
        const byte_t* bytes = 0; size_t length = 0;
        
        this->set_length(0);
        if ((bytes = fragment_length.has_elements(length))) {

            if ((bytes = version.has_elements(length))) {

                if ((bytes = type.has_elements(length))) {

                    this->append(type);
                    this->append(version);
                    this->append(fragment_length);
                    if (0 < (fragment_length.value())) {

                        this->append(fragment);
                    }
                    success = true;
                }
            }
        }
        return success;
    }
    virtual bool separate() {
        bool success = false;
        const byte_t* bytes = 0; size_t length = 0;

        if ((bytes = this->has_elements(length))) {
            size_t count = 0;

            if ((type_.separate(count, bytes, length))) {
                size_t amount = 0;
    
                bytes += count;
                length -= count;
                if ((version_.separate(amount, bytes, length))) {

                    count += amount;
                    bytes += amount;
                    length -= amount;
                    if ((fragment_length_.separate(amount, bytes, length))) {
    
                        count += amount;
                        bytes += amount;
                        length -= amount;
                        if ((fragment_.separate(amount, bytes, length))) {
        
                            count += amount;
                            bytes += amount;
                            length -= amount;
                            success = true;
                        }
                    }
                }
            }
        }
        return success;
    }

    /// ...
    virtual type_t& type() const {
        return (type_t&)type_;
    }
    virtual version_t& version() const {
        return (version_t&)version_;
    }
    virtual fragment_length_t& fragment_length() const {
        return (fragment_length_t&)fragment_length_;
    }
    virtual fragment_t& fragment() const {
        return (fragment_t&)fragment_;
    }

protected:
    type_t type_;
    version_t version_;
    fragment_length_t fragment_length_;
    fragment_t fragment_;
}; /// class plaintextt

typedef plaintextt<> plaintextExtends;
typedef plaintextExtends::implements plaintextImplements;
/// class plaintext
class exported plaintext: virtual public plaintextImplements, public plaintextExtends {
public:
    typedef plaintextImplements implements;
    typedef plaintextExtends extends;
    typedef plaintext derives; 
    
    typedef derives plaintext_t;
    typedef typename extends::type_t type_t;
    typedef typename extends::version_t version_t;
    typedef typename extends::fragment_length_t fragment_length_t;
    typedef typename extends::fragment_t fragment_t;
    
    /// constructors / destructor
    plaintext
    (const type_t& type, const version_t& version, const fragment_t& fragment)
    : extends(type, version, fragment) {
    }
    plaintext(const plaintext& copy): extends(copy) {
    }
    plaintext() {
    }
    virtual ~plaintext() {
    }

    /// plaintext
    virtual plaintext_t* is_plaintext() const {
        return (plaintext*)this;
    }
}; /// class plaintext

typedef plaintext ciphertextExtends;
typedef ciphertextExtends::implements ciphertextImplements;
/// class ciphertext
class exported ciphertext: virtual public ciphertextImplements, public ciphertextExtends {
public:
    typedef ciphertextImplements implements;
    typedef ciphertextExtends extends;
    typedef ciphertext derives; 
    
    typedef derives ciphertext_t;
    typedef typename extends::type_t type_t;
    typedef typename extends::version_t version_t;
    typedef typename extends::fragment_length_t fragment_length_t;
    typedef typename extends::fragment_t fragment_t;
    
    /// constructors / destructor
    ciphertext
    (const type_t& type, const version_t& version, const fragment_t& fragment)
    : extends(type, version, fragment) {
    }
    ciphertext(const ciphertext& copy): extends(copy) {
    }
    ciphertext() {
    }
    virtual ~ciphertext() {
    }

    /// ciphertext
    virtual ciphertext_t* is_ciphertext() const {
        return (ciphertext*)this;
    }
}; /// class ciphertext

} /// namespace tls
} /// namespace protocol
} /// namespace xos

#endif /// XOS_PROTOCOL_TLS_PLAINTEXT_HPP
