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
///   File: array.hpp
///
/// Author: $author$
///   Date: 5/19/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_PROTOCOL_TLS_ARRAY_HPP
#define XOS_PROTOCOL_TLS_ARRAY_HPP

#include "xos/base/array.hpp"
#include "xos/base/arrays.hpp"
#include "xos/base/logged.hpp"
#include "xos/base/logger.hpp"
#include "xos/io/sequence.hpp"
#include "xos/io/seeker.hpp"
#include "xos/io/reader.hpp"
#include "xos/io/writer.hpp"

namespace xos {
namespace protocol {
namespace tls {

class exported plaintext;

/// class arrayt
template 
<class TArray, 
 class TPlaintext = xos::protocol::tls::plaintext,
 class TExtends = TArray, class TImplements = typename TExtends::implements>

class exported arrayt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef arrayt derives;

    typedef TPlaintext plaintext_t;
    typedef typename extends::what_t what_t;
    enum { default_size = extends::default_size };

    /// constructor / destructor
    arrayt(const what_t* elements, size_t length): extends(elements, length) {
    }
    arrayt(ssize_t length): extends(length) {
    }
    arrayt(const arrayt& copy): extends(copy) {
    }
    arrayt() {
    }
    virtual ~arrayt() {
        this->clear();
    }

    /// plaintext
    virtual plaintext_t* is_plaintext() const {
        return 0;
    }

    /// compare
    virtual int compare(const arrayt& to) const {
        return compare(to.elements(), to.length());
    }
    virtual int compare(const what_t* to_elements, size_t to_length) const {
        const what_t *this_elements = 0; what_t this_what = 0, to_what = 0;
        size_t this_length = 0; ssize_t lendiff = 0; 
        int unequal = 0;

        if (!(this_elements = (this->elements(this_length)))) {
            return (to_elements)?(-1):(1);
        }
        if (0 < (lendiff = (to_length - (this_length)))) {
            to_length = this_length;
            unequal = -1;
        } else {
            if (lendiff) {
                unequal = 1;
            }
        }
        if ((to_elements) && (to_length > 0)) {
            do {
                if ((this_what = *(this_elements++)) > (to_what = *(to_elements++))) {
                    return 1;
                } else {
                    if (this_what < to_what) {
                        return -1;
                    }
                }
            } while (--to_length > 0);
        }
        return unequal;
    }

}; /// class arrayt

typedef arrayt<xos::byte_array> byte_array_t;
typedef xos::arrayst<byte_array_t> byte_arrays_t;

} /// namespace tls
} /// namespace protocol
} /// namespace xos

#endif /// ndef XOS_PROTOCOL_TLS_ARRAY_HPP
