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
///   File: methods.hpp
///
/// Author: $author$
///   Date: 4/12/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_PROTOCOL_TLS_COMPRESSION_METHODS_HPP
#define XOS_PROTOCOL_TLS_COMPRESSION_METHODS_HPP

#include "xos/protocol/tls/message/part.hpp"
#include "xos/protocol/tls/vector.hpp"
#include "xos/protocol/tls/compression/method.hpp"

namespace xos {
namespace protocol {
namespace tls {
namespace compression {

/// class methodst
template
<class TMethod = tls::compression::method, class TVector = tls::vectort<byte_t, 1, 1, 1>, 
 class TExtends = TVector, class TImplements = typename TExtends::implements>

class exported methodst: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef methodst derives;

    typedef TMethod method_t;
    typedef TVector vector_t;
    typedef typename extends::length_t length_t;
    enum { length_size = extends::length_size, 
           length_min = extends::length_min, 
           length_max = extends::length_max};

    /// constructors / destructor
    methodst(const methodst& copy): method_(copy.method_) {
        combine();
    }
    methodst(const method_t& method): method_(method) {
        combine();
    }
    methodst() {
        combine();
    }
    virtual ~methodst() {
    }

    /// combine / separate
    virtual bool combine(const method_t& method) {
        bool success = false;
        byte_t *bytes = 0; size_t length = 0;
        this->set_length(0);
        if ((bytes = method.has_elements(length))) {
            this->opaque_.assign(bytes, length);
            success = extends::combine();
        }
        return success;
    }
    virtual bool combine() {
        bool success = false;
        byte_t *bytes = 0; size_t length = 0;
        this->set_length(0);
        if ((bytes = method_.has_elements(length))) {
            this->opaque_.assign(bytes, length);
            success = extends::combine();
        }
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

    /// ...method
    virtual method_t& set_method(const method_t& to) {
        method_.set(to);
        combine();
        return (method_t&)method_;
    }
    virtual method_t& method() const {
        return (method_t&)method_;
    }

protected:
    method_t method_;
}; /// class methodst
typedef methodst<> methods;

} /// namespace compression
} /// namespace tls
} /// namespace protocol
} /// namespace xos

#endif /// ndef XOS_PROTOCOL_TLS_COMPRESSION_METHODS_HPP
