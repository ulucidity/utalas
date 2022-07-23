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
///   File: time.hpp
///
/// Author: $author$
///   Date: 3/11/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_PROTOCOL_TLS_GMT_UNIX_TIME_HPP
#define XOS_PROTOCOL_TLS_GMT_UNIX_TIME_HPP

#include "xos/protocol/tls/message/part.hpp"

namespace xos {
namespace protocol {
namespace tls {
namespace gmt {
namespace unix {

/// class timet
template 
<class TGmtUnixTime = uint32_t, class TMessagePart = message::part, 
 class TExtends = TMessagePart, class TImplements = typename TExtends::implements>
class exported timet: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef timet derives; 
    
    typedef TMessagePart message_part_t;
    typedef TGmtUnixTime gmt_unix_time_t;
    
    /// constructors / destructor
    timet(const timet& copy): gmt_unix_time_(copy.gmt_unix_time_) {
        combine();
    }
    timet(const gmt_unix_time_t& gmt_unix_time): gmt_unix_time_(gmt_unix_time) {
        combine();
    }
    timet(): gmt_unix_time_(0) {
        set_now();
    }
    virtual ~timet() {
    }

    /// combine / separate
    virtual bool combine() {
        bool success = true;
        this->set_to_msb(gmt_unix_time_);
        return success;
    }
    virtual bool separate(size_t& count, const byte_t *bytes, size_t length) {
        bool success = false;
        size_t gmt_unix_time_sizeof = sizeof(gmt_unix_time_t);

        count = 0;
        this->clear();
        if ((bytes) && (gmt_unix_time_sizeof <= (length))) {
            gmt_unix_time_t gmt_unix_time = 0;
            size_t amount = 0;

            if (gmt_unix_time_sizeof == (amount = this->from_msb
                (gmt_unix_time, gmt_unix_time_sizeof, bytes, length))) {
                this->append(bytes, amount);
                count += amount;
                bytes += amount;
                length -= amount;
                gmt_unix_time_ = gmt_unix_time;
                success = true;
            }
        }
        return success;
    }

    /// ...now
    virtual gmt_unix_time_t set_now() {
        gmt_unix_time_ = now();
        combine();
        return gmt_unix_time_;
    }
    static gmt_unix_time_t now() {
        time_t unix_time = 0;
        gmt_unix_time_t gmt_unix_time = ((gmt_unix_time_t)::time(&unix_time));
        return gmt_unix_time;
    }
    virtual gmt_unix_time_t gmt_unix_time() const {
        return gmt_unix_time_;
    }

protected:
    gmt_unix_time_t gmt_unix_time_;
}; /// class timet
typedef timet<> time;

} /// namespace unix
} /// namespace gmt
} /// namespace tls
} /// namespace protocol
} /// namespace xos

#endif /// XOS_PROTOCOL_TLS_GMT_UNIX_TIME_HPP
