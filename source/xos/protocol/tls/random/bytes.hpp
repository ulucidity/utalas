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
///   File: bytes.hpp
///
/// Author: $author$
///   Date: 3/11/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_PROTOCOL_TLS_RANDOM_BYTES_HPP
#define XOS_PROTOCOL_TLS_RANDOM_BYTES_HPP

#include "xos/protocol/tls/message/part.hpp"
#include "xos/protocol/tls/pseudo/random/reader.hpp"

namespace xos {
namespace protocol {
namespace tls {
namespace random {

/// class bytest
template 
<size_t VSize = 28, 
 class TRandomReader = tls::pseudo::random::reader, class TMessagePart = tls::message::part, 
 class TExtends = TMessagePart, class TImplements = typename TExtends::implements>

class exported bytest: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef bytest derives; 
    
    enum { size = VSize };
    typedef TRandomReader random_reader_t;
    typedef TMessagePart message_part_t;

    /// constructors / destructor
    bytest(const bytest& copy): extends(copy), random_reader_(copy.random_reader_) {
    }
    bytest(random_reader_t& random_reader): random_reader_(random_reader) {
        combine();
    }
    bytest(): random_reader_(this_random_reader_) {
        combine();
    }
    virtual ~bytest() {
    }

    /// combine / separate
    virtual bool combine() {
        bool success = true;
        size_t remain = 0, length = 0;

        if (size <= (this->set_length(length = size))) {
            byte_t* bytes = 0;

            if ((bytes = this->has_elements(length))) {
                
                for (remain = length; remain; remain -= length, bytes += length) {

                    if (0 < (length = random_reader_.read(bytes, remain))) {
                        continue;
                    }
                    this->set_length(0);
                    return false;
                }
            }
        }
        return success;
    }
    virtual bool separate(size_t& count, const byte_t *bytes, size_t length) {
        bool success = false;
        size_t amount = 0;
        count = 0;
        if ((bytes) && (size <= (length))) {
            this->assign(bytes, size);
            if (size == (this->length())) {
                count += size;
                bytes += size;
                length -= size;
                success = true;
            }
        }
        return success;
    }

protected:
    random_reader_t this_random_reader_, &random_reader_;
}; /// class bytest
typedef bytest<> bytes;

} /// namespace random
} /// namespace tls
} /// namespace protocol
} /// namespace xos

#endif /// XOS_PROTOCOL_TLS_RANDOM_BYTES_HPP
