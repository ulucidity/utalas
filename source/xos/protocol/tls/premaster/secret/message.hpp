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
///   Date: 5/22/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_PROTOCOL_TLS_PREMASTER_SECRET_MESSAGE_HPP
#define XOS_PROTOCOL_TLS_PREMASTER_SECRET_MESSAGE_HPP

#include "xos/protocol/tls/premaster/secret/random.hpp"
#include "xos/protocol/tls/protocol/version.hpp"

namespace xos {
namespace protocol {
namespace tls {
namespace premaster {
namespace secret {

/// class messaget
template 
<class TProtocolVersion = tls::protocol::version, 
 class TRandom = tls::premaster::secret::random, class TRandomReader = tls::pseudo::random::reader, 
 class TMessagePart = tls::message::part, class TExtends = TMessagePart, class TImplements = typename TExtends::implements>

class exported messaget: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef messaget derives; 
    
    typedef TProtocolVersion protocol_version_t;
    typedef TRandomReader random_reader_t;
    typedef TRandom random_t;

    typedef typename random_t::size_of_t size_of_t;
    enum { size_of = (protocol_version_t::size_of + random_t::size_of) };

    /// constructors / destructor
    messaget(const messaget& copy)
    : random_reader_(copy.random_reader_), client_version_(copy.client_version_), random_(copy.random_) {
        combine();
    }
    messaget(const protocol_version_t& client_version, const random_t& random, random_reader_t& random_reader)
    : random_reader_(random_reader), client_version_(client_version), random_(random) {
        combine();
    }
    messaget(const random_t& random, random_reader_t& random_reader)
    : random_reader_(random_reader), random_(random) {
        combine();
    }
    messaget(random_reader_t& random_reader): random_reader_(random_reader), random_(random_reader_) {
        combine();
    }
    messaget(): random_reader_(this_random_reader_), random_(random_reader_) {
        combine();
    }
    virtual ~messaget() {
    }

    /// combine / separate
    virtual bool combine() {
        bool success = false;
        this->set_length(0);
        if ((this->append(client_version_))) {
            if ((this->append(random_))) {
                success = true;
            }
        }
        return success;
    }
    virtual bool separate() {
        bool success = false;
        return success;
    }

protected:
    random_reader_t this_random_reader_, &random_reader_;
    protocol_version_t client_version_;
    random_t random_;
}; /// class messaget
typedef messaget<> message;

} /// namespace secret
} /// namespace premaster
} /// namespace tls
} /// namespace protocol
} /// namespace xos

#endif /// ndef XOS_PROTOCOL_TLS_PREMASTER_SECRET_MESSAGE_HPP
