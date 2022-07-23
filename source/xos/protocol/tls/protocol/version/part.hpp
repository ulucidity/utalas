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
///   File: part.hpp
///
/// Author: $author$
///   Date: 4/10/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_PROTOCOL_TLS_PROTOCOL_VERSION_PART_HPP
#define XOS_PROTOCOL_TLS_PROTOCOL_VERSION_PART_HPP

#include "xos/protocol/tls/message/part.hpp"
#include "xos/protocol/tls/uinteger.hpp"

namespace xos {
namespace protocol {
namespace tls {
namespace protocol {
namespace version {

/// class partt
template 
<class TMessagePart = tls::uint8,
 class TExtends = TMessagePart, class TImplements = typename TExtends::implements>

class exported partt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef partt derives; 
    
    typedef TMessagePart part_t;
    typedef typename part_t::value_t value_t;
    
    /// constructors / destructor
    partt(const partt& copy): extends(copy) {
    }
    partt(const part_t& copy): extends(copy) {
    }
    partt(const value_t& copy): extends(copy) {
    }
    partt() {
    }
    virtual ~partt() {
    }

protected:
}; /// class partt
typedef partt<> part;

} /// namespace version
} /// namespace protocol
} /// namespace tls
} /// namespace protocol
} /// namespace xos

#endif /// ndef XOS_PROTOCOL_TLS_PROTOCOL_VERSION_PART_HPP
