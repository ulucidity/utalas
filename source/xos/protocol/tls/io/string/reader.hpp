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
///   File: reader.hpp
///
/// Author: $author$
///   Date: 5/1/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_PROTOCOL_TLS_IO_STRING_READER_HPP
#define XOS_PROTOCOL_TLS_IO_STRING_READER_HPP

#include "xos/io/string/reader.hpp"
#include "xos/protocol/tls/string.hpp"

namespace xos {
namespace protocol {
namespace tls {
namespace io {
namespace string {

/// class readert
template 
<typename TString = xos::protocol::tls::string_t, 
 class TExtends = xos::io::string::readert<TString>, class TImplements = typename TExtends::Implements>

class exported readert: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements, implements;
    typedef TExtends Extends, extends;
    typedef readert Derives, derives; 
    
    typedef TString string_t;

    /// constructors / destructor
    readert(const readert& copy): extends(copy) {
    }
    readert(string_t& string): extends(string) {
    }
    readert() {
    }
    virtual ~readert() {
    }
}; /// class readert

typedef readert<> reader;

} /// namespace string
} /// namespace io
} /// namespace tls
} /// namespace protocol
} /// namespace xos

#endif /// ndef XOS_PROTOCOL_TLS_IO_STRING_READER_HPP
