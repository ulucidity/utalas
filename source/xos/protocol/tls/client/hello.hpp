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
///   File: hello.hpp
///
/// Author: $author$
///   Date: 3/11/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_PROTOCOL_TLS_CLIENT_HELLO_HPP
#define XOS_PROTOCOL_TLS_CLIENT_HELLO_HPP

#include "xos/protocol/tls/message/part.hpp"
#include "xos/protocol/tls/protocol/version.hpp"
#include "xos/protocol/tls/pseudo/random/reader.hpp"
#include "xos/protocol/tls/hello/random.hpp"
#include "xos/protocol/tls/session/identifier.hpp"
#include "xos/protocol/tls/cipher/suites.hpp"
#include "xos/protocol/tls/compression/methods.hpp"

namespace xos {
namespace protocol {
namespace tls {
namespace client {

/// class hellot
template 
<class TProtocolVersion = tls::protocol::version, 
 class THelloRandom = tls::hello::random,
 class TSessionIdentifier = tls::session::identifier,
 class TCipherSuites = tls::cipher::suites,
 class TCompressionMethods = tls::compression::methods,
 class TRandomReader = tls::pseudo::random::reader,
 class TMessagePart = tls::message::part, class TExtends = TMessagePart, class TImplements = typename TExtends::implements>

class exported hellot: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef hellot derives; 
    
    typedef TRandomReader random_reader_t;
    typedef TProtocolVersion protocol_version_t;
    typedef THelloRandom hello_random_t;
    typedef TSessionIdentifier session_identifier_t;
    typedef TCipherSuites cipher_suites_t;
    typedef typename cipher_suites_t::suite_t cipher_suite_t;
    typedef TCompressionMethods compression_methods_t;
    typedef typename compression_methods_t::method_t compression_method_t;
    
    /// constructors / destructor
    hellot(const hellot& copy)
    : random_reader_(copy.random_reader_), 
      protocol_version_(copy.protocol_version_), 
      hello_random_(copy.hello_random_), 
      session_identifier_(copy.session_identifier_),
      cipher_suites_(copy.cipher_suites_),
      compression_methods_(copy.compression_methods_) {
        combine();
    }
    hellot
    (const protocol_version_t& protocol_version, const hello_random_t& hello_random, const session_identifier_t& session_identifier, 
     const cipher_suites_t& cipher_suites, const compression_methods_t& compression_methods, random_reader_t& random_reader)
    : random_reader_(random_reader), 
      protocol_version_(protocol_version), 
      hello_random_(hello_random), 
      session_identifier_(session_identifier),
      cipher_suites_(cipher_suites),
      compression_methods_(compression_methods) {
        combine();
    }
    hellot(const hello_random_t& hello_random, const session_identifier_t& session_identifier, random_reader_t& random_reader)
    : random_reader_(random_reader), 
      hello_random_(hello_random), 
      session_identifier_(session_identifier),
      cipher_suites_(cipher_suite_),
      compression_methods_(compression_method_) {
        combine();
    }
    hellot(const session_identifier_t& session_identifier, random_reader_t& random_reader)
    : random_reader_(random_reader), 
      hello_random_(random_reader_), 
      session_identifier_(session_identifier),
      cipher_suites_(cipher_suite_),
      compression_methods_(compression_method_) {
        combine();
    }
    hellot(random_reader_t& random_reader)
    : random_reader_(random_reader), 
      hello_random_(random_reader_), 
      session_identifier_(random_reader_),
      cipher_suites_(cipher_suite_),
      compression_methods_(compression_method_) {
        combine();
    }
    hellot()
    : random_reader_(this_random_reader_), 
      hello_random_(random_reader_), 
      session_identifier_(random_reader_),
      cipher_suites_(cipher_suite_),
      compression_methods_(compression_method_) {
        combine();
    }
    virtual ~hellot() {
    }

    /// combine / separate
    virtual bool combine() {
        bool success = true;
        byte_t *bytes = 0; size_t length = 0;
        this->set_length(0);
        if ((bytes = protocol_version_.has_elements(length))) {
            this->append(bytes, length);
            if ((bytes = hello_random_.has_elements(length))) {
                this->append(bytes, length);
                if ((bytes = session_identifier_.has_elements(length))) {
                    this->append(bytes, length);
                    if ((bytes = cipher_suites_.has_elements(length))) {
                        this->append(bytes, length);
                        if ((bytes = compression_methods_.has_elements(length))) {
                            this->append(bytes, length);
                        }
                    }
                }
            }
        }
        return success;
    }
    virtual bool separate(size_t& count, const byte_t *bytes, size_t length) {
        bool success = false;
        size_t amount = 0;
        count = 0;
        if ((bytes) && (length)) {
            if ((protocol_version_.separate(amount, bytes, length))) {
                count += amount;
                bytes += amount;
                length -= amount;
                if ((bytes) && (length)) {
                    if ((hello_random_.separate(amount, bytes, length))) {
                        count += amount;
                        bytes += amount;
                        length -= amount;
                        success = true;
                    }
                }
            }
        }
        return success;
    }

    /// ...
    virtual protocol_version_t& protocol_version() const {
        return (protocol_version_t&)protocol_version_;
    }
    virtual hello_random_t& hello_random() const {
        return (hello_random_t&)hello_random_;
    }

protected:
    random_reader_t this_random_reader_, &random_reader_;
    protocol_version_t protocol_version_;
    hello_random_t hello_random_;
    session_identifier_t session_identifier_;
    cipher_suite_t cipher_suite_;
    cipher_suites_t cipher_suites_;
    compression_method_t compression_method_;
    compression_methods_t compression_methods_;
}; /// class hellot
typedef hellot<> hello;

} /// namespace client
} /// namespace tls
} /// namespace protocol
} /// namespace xos

#endif /// XOS_PROTOCOL_TLS_CLIENT_HELLO_HPP
