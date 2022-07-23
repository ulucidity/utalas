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
///   Date: 4/12/2022
///////////////////////////////////////////////////////////////////////
///
/// Dierks & Rescorla           Standards Track
/// RFC 5246                          TLS                        August 2008
/// 
/// enum { null, rc4, 3des, aes } BulkCipherAlgorithm;
/// 
///////////////////////////////////////////////////////////////////////
#ifndef XOS_PROTOCOL_TLS_BULK_CIPHER_ALGORITHM_HPP
#define XOS_PROTOCOL_TLS_BULK_CIPHER_ALGORITHM_HPP

#include "xos/protocol/tls/message/part.hpp"

namespace xos {
namespace protocol {
namespace tls {
namespace bulk {
namespace cipher {

/// enum algorithm_which_t
typedef uint8_t algorithm_which_t;
enum { 
    algorithm_none,
    algorithm_rc4,
    algorithm_des3,
    algorithm_aes,
    algorithm_which = algorithm_aes
}; /// enum algorithm_which_t

/// class algorithmt
template 
<typename TWhich = algorithm_which_t, TWhich VWhich = algorithm_which, TWhich VNone = algorithm_none, 
 class TMessagePart = tls::message::part, class TExtends = TMessagePart, class TImplements = typename TExtends::implements>

class exported algorithmt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef algorithmt derives; 
    
    typedef TWhich which_t;
    enum { 
        none = VNone,
        which = VWhich
    };

    /// constructors / destructor
    algorithmt(const algorithmt& copy): which_(copy.which_) {
        combine();
    }
    algorithmt(const which_t& which): which_(which) {
        combine();
    }
    algorithmt(): which_(which) {
        combine();
    }
    virtual ~algorithmt() {
    }

    /// combine / separate
    virtual bool combine(const which_t& which) {
        bool success = false;
        if (sizeof(which_t) == (this->set_to_msb(which))) {
            success = true;
        }
        return success;
    }
    virtual bool combine() {
        bool success = false;
        if (sizeof(which_t) == (this->set_to_msb(which_))) {
            success = true;
        }
        return success;
    }
    virtual bool separate(size_t& count, const byte_t* bytes, size_t length) {
        bool success = false;
        count = 0;
        if ((bytes) && (length >= sizeof(which_t))) {
            which_t which = none;
            size_t amount = 0;
            if (sizeof(which_t) == (amount = this->from_msb(which, bytes, length))) {
                count += amount;
                bytes += amount;
                length -= amount;
                which_ = which;
                success = true;
            }
        }
        return success;
    }
    virtual bool separate() {
        bool success = false;
        const byte_t* bytes = 0; size_t length = 0;        
        if ((bytes = this->has_elements(length))) {
            size_t count = 0;
            success = separate(count, bytes, length);
        }
        return success;
    }

    /// ...is
    virtual const which_t& set_is(const which_t& to) {
        which_ = to;
        return which_;
    }
    virtual const which_t& is() const {
        return which_;
    }

protected:
    which_t which_;
}; /// class algorithmt
typedef algorithmt<> algorithm;

} /// namespace cipher
} /// namespace bulk
} /// namespace tls
} /// namespace protocol
} /// namespace xos

#endif /// XOS_PROTOCOL_TLS_BULK_CIPHER_ALGORITHM_HPP
