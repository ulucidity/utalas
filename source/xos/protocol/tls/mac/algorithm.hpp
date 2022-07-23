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
///   File: algorithm.hpp
///
/// Author: $author$
///   Date: 2/24/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_PROTOCOL_TLS_MAC_ALGORITHM_HPP
#define XOS_PROTOCOL_TLS_MAC_ALGORITHM_HPP

#include "xos/protocol/tls/message/part.hpp"

namespace xos {
namespace protocol {
namespace tls {
namespace mac {

typedef uint8_t algorithm_which_t;
enum { 
    algorithm_none,
    algorithm_hmac_md5, 
    algorithm_hmac_sha1, 
    algorithm_hmac_sha256, 
    algorithm_hmac_sha384,
    algorithm_hmac_sha512,
    algorithm_which = algorithm_hmac_sha256
};

/// class algorithmt
template 
<typename TWhich = algorithm_which_t, TWhich VWhich = algorithm_which,
 class TMessagePart = tls::message::part, class TExtends = TMessagePart, class TImplements = typename TExtends::implements>

class exported algorithmt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef algorithmt derives; 
    
    typedef TWhich which_t;
    enum { 
        which = VWhich
    };

    /// constructors / destructor
    algorithmt(const algorithmt& copy): which_(copy.which_) {
        this->to_msb(which_);
    }
    algorithmt(const which_t& which): which_(which) {
        this->to_msb(which_);
    }
    algorithmt(): which_(which) {
        this->to_msb(which_);
    }
    virtual ~algorithmt() {
    }

    /// ...is
    virtual const which_t& is() const {
        return which_;
    }

protected:
    which_t which_;
}; /// class algorithmt
typedef algorithmt<> algorithm;

} /// namespace mac
} /// namespace tls
} /// namespace protocol
} /// namespace xos

#endif /// XOS_PROTOCOL_TLS_MAC_ALGORITHM_HPP
