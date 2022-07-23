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
#ifndef XOS_PROTOCOL_CRYPTO_RANDOM_READER_HPP
#define XOS_PROTOCOL_CRYPTO_RANDOM_READER_HPP

#include "xos/io/reader.hpp"

namespace xos {
namespace protocol {
namespace crypto {
namespace random {

typedef xos::io::byte_reader byte_reader_t;

/// class readert
template 
<class TByteReader = byte_reader_t, class TImplements = TByteReader>

class exported readert: virtual public TImplements {
public:
    typedef TImplements implements;
    typedef readert derives; 
    
    typedef typename implements::what_t what_t;
    typedef typename implements::sized_t sized_t;

    /// constructors / destructor
    virtual ~readert() {
    }

    /// read...
    virtual ssize_t read(what_t* what, size_t size) {
        sized_t* sized = 0;
        if ((sized = (sized_t*)what) && (size)) {
            ssize_t amount = 0, count = 0; size_t remain = 0; 
            for (amount = size, remain = size; remain; remain -= amount, sized += amount) {
                if (0 < (amount = read_more(sized, remain))) {
                    count += amount;
                    continue;
                }
                break;
            }
            return count;
        }
        return 0;
    }
    
protected:
    virtual ssize_t read_more(what_t* what, size_t size) {
        return 0;
    }
}; /// class readert
typedef readert<> reader;

} /// namespace random
} /// namespace crypto
} /// namespace protocol
} /// namespace xos

#endif /// ndef XOS_PROTOCOL_CRYPTO_RANDOM_READER_HPP
