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
///   File: code.hpp
///
/// Author: $author$
///   Date: 5/16/2022
///////////////////////////////////////////////////////////////////////
///
/// Dierks & Rescorla           Standards Track
/// RFC 5246                          TLS                        August 2008
/// 
/// enum {
///     none(0), md5(1), sha1(2), sha224(3), sha256(4), sha384(5),
///     sha512(6), (255)
/// } HashAlgorithm;
/// 
///////////////////////////////////////////////////////////////////////
#ifndef XOS_PROTOCOL_TLS_HASH_ALGORITHM_CODE_HPP
#define XOS_PROTOCOL_TLS_HASH_ALGORITHM_CODE_HPP

#include "xos/protocol/tls/message/part.hpp"

namespace xos {
namespace protocol {
namespace tls {
namespace hash {
namespace algorithm {

/// class codet
template 
<class TMessagePart = message::part, 
 class TExtends = TMessagePart, class TImplements = typename TExtends::implements>

class exported codet: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef codet derives; 
    
    /// constructors / destructor
    codet(const codet& copy): extends(copy) {
        combine();
    }
    codet() {
        combine();
    }
    virtual ~codet() {
    }

    /// combine / separate
    virtual bool combine() {
        bool success = false;
        return success;
    }
    virtual bool separate(size_t& count, const byte_t* bytes, size_t length) {
        bool success = false;
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

protected:
}; /// class codet
typedef codet<> code;

} /// namespace algorithm
} /// namespace hash
} /// namespace tls
} /// namespace protocol
} /// namespace xos

#endif /// ndef XOS_PROTOCOL_TLS_HASH_ALGORITHM_CODE_HPP
