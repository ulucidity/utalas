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
///   File: vector.hpp
///
/// Author: $author$
///   Date: 4/12/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_PROTOCOL_TLS_VECTOR_HPP
#define XOS_PROTOCOL_TLS_VECTOR_HPP

#include "xos/protocol/tls/message/part.hpp"

namespace xos {
namespace protocol {
namespace tls {

/// class vectort
template 
<typename TLength = byte_t, TLength VLengthSize = 1, TLength VLengthMax = 255, TLength VLengthMin = 0, 
 class TMessagePart = tls::message::part, class TExtends = TMessagePart, class TImplements = typename TExtends::implements>

class exported vectort: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef vectort derives; 
    
    typedef TMessagePart part_t;
    typedef TLength length_t;
    enum { length_size = VLengthSize, 
           length_min = VLengthMin, 
           length_max = VLengthMax};

    /// constructors / destructor
    vectort(const vectort& copy): length_(copy.length_), opaque_(copy.opaque_) {
        combine();
    }
    vectort(const length_t &length): length_(length) {
        opaque_.set_length(length_);
        combine();
    }
    vectort(): length_(length_min) {
        opaque_.set_length(length_);
        combine();
    }
    virtual ~vectort() {
    }

    /// combine / separate
    virtual bool combine() {
        bool success = false;
        if (length_size == (this->set_to_msb(length_), length_size)) {
            if ((length_)) {
                const byte_t* elements = 0; size_t length = 0;
                if ((elements = opaque_.has_elements(length))) {
                    this->append(elements, length);
                    success = true;
                }
            } else {
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
    length_t length_;
    part_t opaque_;
}; /// class vectort
typedef vectort<> vector;

} /// namespace tls
} /// namespace protocol
} /// namespace xos

#endif /// ndef XOS_PROTOCOL_TLS_VECTOR_HPP
