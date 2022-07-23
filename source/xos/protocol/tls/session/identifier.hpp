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
///   File: identifier.hpp
///
/// Author: $author$
///   Date: 2/7/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_PROTOCOL_TLS_SESSION_IDENTIFIER_HPP
#define XOS_PROTOCOL_TLS_SESSION_IDENTIFIER_HPP

#include "xos/protocol/tls/vector.hpp"
#include "xos/protocol/tls/pseudo/random/reader.hpp"

namespace xos {
namespace protocol {
namespace tls {
namespace session {

/// class identifiert
template 
<class TVector = tls::vectort<byte_t, 1, 32, 0>, class TRandomReader = tls::pseudo::random::reader, 
 class TExtends = TVector, class TImplements = typename TExtends::implements>

class exported identifiert: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef identifiert derives; 
    
    typedef TVector vector_t;
    typedef TRandomReader random_reader_t;
    typedef typename extends::length_t length_t;
    enum { length_size = extends::length_size, 
           length_min = extends::length_min, 
           length_max = extends::length_max};
    
    /// constructors / destructor
    identifiert(const identifiert& copy): extends(copy) {
        extends::combine();
    }
    identifiert(random_reader_t &random_reader): extends(length_max) {
        combine(random_reader);
    }
    identifiert() {
    }
    virtual ~identifiert() {
    }

    /// combine / separate
    using extends::combine;
    virtual bool combine(random_reader_t &random_reader) {
        bool success = false;
        byte_t *bytes = 0; size_t length = 0;

        if ((bytes = this->opaque_.has_elements(length))) {
            size_t remain = 0;

            for (remain = length; remain; remain -= length, bytes += length) {
                if (0 < (length = random_reader.read(bytes, remain))) {
                    continue;
                }
                return false;
            }
            success = extends::combine();
        }
        return success;
    }

}; /// class identifiert
typedef identifiert<> identifier;

} /// namespace session
} /// namespace tls
} /// namespace protocol
} /// namespace xos

#endif /// XOS_PROTOCOL_TLS_SESSION_IDENTIFIER_HPP
