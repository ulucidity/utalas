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
///   File: generator.hpp
///
/// Author: $author$
///   Date: 6/1/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_PROTOCOL_CRYPTO_PSEUDO_RANDOM_GENERATOR_HPP
#define XOS_PROTOCOL_CRYPTO_PSEUDO_RANDOM_GENERATOR_HPP

#include "xos/protocol/crypto/random/generator.hpp"

#if defined(WINDOWS)
#include "rand_r.h"
#endif // defined(WINDOWS)

namespace xos {
namespace protocol {
namespace crypto {
namespace pseudo {
namespace random {

/// class generatort
template 
<class TRandomGenerator = xos::protocol::crypto::random::generator, 
 class TExtends = extend, class TImplements = TRandomGenerator>

class exported generatort: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef generatort derives; 
    
    typedef unsigned seed_t;
    enum { seed_default = 0 };
    
    /// constructors / destructor
    generatort(const generatort& copy): m_avail(0), m_seed(copy.m_seed), m_rand(0) {
    }
    generatort(const seed_t& seed): m_avail(0), m_seed(seed), m_rand(0) {
    }
    generatort(): m_avail(0), m_seed(seed_default), m_rand(0) {
    }
    virtual ~generatort() {
    }

    /// generate
    virtual ssize_t generate(void* out, size_t size) {
        byte_t* bytes = 0;

        if ((bytes = (byte_t*)(out))) {
            size_t i = 0, j = 0, count = 0, length = 0;

            for (length = 0; length < size; ) {
                if (1 > m_avail) {
                    if (!(m_seed)) {
                        time_t t = time(&t);
                        m_seed = (unsigned)(t);
					}
                    m_rand = (unsigned)rand_r(&m_seed);
                    m_avail = sizeof(m_rand);
                }
                if ((count = size-length) > m_avail) {
                    count = m_avail;
                }
                for (j = 0, i = 0; i < count; ++i) {
                    if ((bytes[length+j] = (byte_t)(m_rand & 0xff))) {
                        ++j;
                    }
                    m_rand >>= 8;
                }
                length += j;
                m_avail -= count;
            }
            return size;
        }
        return 0;
    }

    /// seed
    virtual unsigned seed(unsigned seed) {
        m_seed = seed;
        m_avail = 0;
        m_rand = 0;
        return m_seed;
    }

protected:
    size_t m_avail;
    unsigned m_seed;
    unsigned m_rand;
}; /// class generatort
typedef generatort<> generator;

} /// namespace random
} /// namespace pseudo
} /// namespace crypto
} /// namespace protocol
} /// namespace xos

#endif /// ndef XOS_PROTOCOL_CRYPTO_PSEUDO_RANDOM_GENERATOR_HPP
