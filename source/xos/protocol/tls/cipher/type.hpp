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
///   File: type.hpp
///
/// Author: $author$
///   Date: 2/24/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_PROTOCOL_TLS_CIPHER_TYPE_HPP
#define XOS_PROTOCOL_TLS_CIPHER_TYPE_HPP

#include "xos/protocol/tls/message/part.hpp"

namespace xos {
namespace protocol {
namespace tls {
namespace cipher {

typedef uint8_t type_which_t;
enum { 
    type_stream, 
    type_block, 
    type_aead 
};

/// class typet
template 
<typename TWhich = type_which_t, 
 TWhich VStream = type_stream, TWhich VBlock = type_block, TWhich VWhich = VBlock, 
 class TMessagePart = tls::message::part, class TExtends = TMessagePart, class TImplements = typename TExtends::implements>

class exported typet: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef typet derives; 
    
    typedef TWhich which_t;
    enum  { 
        stream = VStream, 
        block = VBlock, 
        which = VWhich 
    };
    
    /// constructors / destructor
    typet(const typet& copy): which_(copy.which_) {
        this->to_msb(which_);
    }
    typet(const which_t& which): which_(which) {
        this->to_msb(which_);
    }
    typet(): which_(which) {
        this->to_msb(which_);
    }
    virtual ~typet() {
    }

    /// ...is
    virtual const which_t& is() const {
        return which_;
    }

protected:
    which_t which_;
}; /// class typet
typedef typet<> type;

} /// namespace cipher
} /// namespace tls
} /// namespace protocol
} /// namespace xos

#endif /// XOS_PROTOCOL_TLS_CIPHER_TYPE_HPP
