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
///   File: suites.hpp
///
/// Author: $author$
///   Date: 4/12/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_PROTOCOL_TLS_CIPHER_SUITES_HPP
#define XOS_PROTOCOL_TLS_CIPHER_SUITES_HPP

#include "xos/protocol/tls/message/part.hpp"
#include "xos/protocol/tls/vector.hpp"
#include "xos/protocol/tls/cipher/suite.hpp"

namespace xos {
namespace protocol {
namespace tls {
namespace cipher {

/// class suitest
template 
<class TSuite = tls::cipher::suite, 
 size_t VSizeof = sizeof(typename TSuite::which_t)+sizeof(typename TSuite::with_t),
 class TVector = tls::vectort<word_t, 2, VSizeof*32, VSizeof>, 
 class TExtends = TVector, class TImplements = typename TExtends::implements>

class exported suitest: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef suitest derives; 
    
    typedef TSuite suite_t;
    typedef TVector vector_t;
    typedef typename extends::length_t length_t;
    enum { length_size = extends::length_size, 
           length_min = extends::length_min, 
           length_max = extends::length_max};

    /// constructors / destructor
    suitest(const suitest& copy): suite_(copy.suite_) {
        combine();
    }
    suitest(const suite_t& suite): suite_(suite) {
        combine();
    }
    suitest() {
        combine();
    }
    virtual ~suitest() {
    }

    /// combine / separate
    virtual bool combine(const suite_t& suite) {
        bool success = false;
        byte_t *bytes = 0; size_t length = 0;
        this->set_length(0);
        if ((bytes = suite.has_elements(length))) {
            this->opaque_.assign(bytes, length);
            success = extends::combine();
        }
        return success;
    }
    virtual bool combine() {
        bool success = false;
        byte_t *bytes = 0; size_t length = 0;
        this->set_length(0);
        if ((bytes = suite_.has_elements(length))) {
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

    /// ...suite
    virtual suite_t& set_suite(const suite_t& suite) {
        suite_.set(suite);
        combine();
        return (suite_t&)suite_;
    }
    virtual suite_t& suite() const {
        return (suite_t&)suite_;
    }

protected:
    suite_t suite_;
}; /// class suitest
typedef suitest<> suites;

} /// namespace cipher
} /// namespace tls
} /// namespace protocol
} /// namespace xos

#endif /// ndef XOS_PROTOCOL_TLS_CIPHER_SUITES_HPP
