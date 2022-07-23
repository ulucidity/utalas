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
#ifndef XOS_PROTOCOL_CRYPTO_RANDOM_GENERATOR_HPP
#define XOS_PROTOCOL_CRYPTO_RANDOM_GENERATOR_HPP

#include "xos/base/base.hpp"

namespace xos {
namespace protocol {
namespace crypto {
namespace random {

/// class generatort
template <class TImplements = implement>
class exported generatort: virtual public TImplements {
public:
    typedef TImplements implements;
    typedef generatort derives; 
    
    /// constructors / destructor
    virtual ~generatort() {
    }

    /// generate
    virtual ssize_t generate(void* out, size_t size) {
        return 0;
    }
}; /// class generatort
typedef generatort<> generator;

} /// namespace random
} /// namespace crypto
} /// namespace protocol
} /// namespace xos

#endif /// ndef XOS_PROTOCOL_CRYPTO_RANDOM_GENERATOR_HPP
