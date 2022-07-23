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
///   File: end.hpp
///
/// Author: $author$
///   Date: 2/24/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_PROTOCOL_TLS_CONNECTION_END_HPP
#define XOS_PROTOCOL_TLS_CONNECTION_END_HPP

#include "xos/protocol/tls/message/part.hpp"

namespace xos {
namespace protocol {
namespace tls {
namespace connection {

typedef uint8_t which_end_t;
enum {
    server_end,
    client_end,
    which_end = client_end
};

/// class endt
template 
<typename TWhich = which_end_t, 
 TWhich VServer = server_end, TWhich VClient = client_end, TWhich VWhich = which_end,
 class TMessagePart = tls::message::part, class TExtends = TMessagePart, class TImplements = typename TExtends::implements>

class exported endt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef endt derives; 
    
    typedef TWhich which_t;
    enum {
        server = VServer,
        client = VClient,
        which = VWhich
    };

    /// constructors / destructor
    endt(const endt& copy): which_(copy.which_) {
        this->to_msb(which_);
    }
    endt(const which_t& which): which_(which) {
        this->to_msb(which_);
    }
    endt(): which_(which) {
        this->to_msb(which_);
    }
    virtual ~endt() {
    }
    
    /// ...is
    virtual const which_t& is() const {
        return which_;
    }

protected:
    which_t which_;
}; /// class endt
typedef endt<> end;

} /// namespace connection
} /// namespace tls
} /// namespace protocol
} /// namespace xos

#endif /// XOS_PROTOCOL_TLS_CONNECTION_END_HPP
