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
///   Date: 6/1/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_PROTOCOL_CRYPTO_PSEUDO_RANDOM_READER_HPP
#define XOS_PROTOCOL_CRYPTO_PSEUDO_RANDOM_READER_HPP

#include "xos/protocol/crypto/random/reader.hpp"
#include "xos/protocol/crypto/pseudo/random/generator.hpp"

namespace xos {
namespace protocol {
namespace crypto {
namespace pseudo {
namespace random {

/// class readert
template 
<class TGenerator = xos::protocol::crypto::pseudo::random::generator,
 class TReader = xos::protocol::crypto::random::reader, 
 class TExtends = extend, class TImplements = TReader>

class exported readert: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef readert derives; 
    
    typedef unsigned seed_t;
    typedef TGenerator generator_t;
    typedef typename implements::what_t what_t;
    typedef typename implements::sized_t sized_t;

    /// constructors / destructor
    readert(const readert& copy): extends(copy) {
    }
    readert(const seed_t& seed): generator_(seed) {
    }
    readert() {
    }
    virtual ~readert() {
    }

protected:
    /// read...
    virtual ssize_t read_more(what_t* what, size_t size) {
        void* out = 0;
        if ((out = (void*)what) && (size)) {
            generator_t& generator = this->generator();
            ssize_t count = generator.generate(out, size);
            return count;
        }
        return 0;
    }

    /// generator...
    virtual generator_t& generator() const {
        return (generator_t&)generator_;
    }

protected:
    generator_t generator_;
}; /// class readert
typedef readert<> reader;

} /// namespace random
} /// namespace pseudo
} /// namespace crypto
} /// namespace protocol
} /// namespace xos

#endif /// ndef XOS_PROTOCOL_CRYPTO_PSEUDO_RANDOM_READER_HPP
