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
///   File: message.hpp
///
/// Author: $author$
///   Date: 4/10/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_PROTOCOL_TLS_PROTOCOL_VERSION_MESSAGE_HPP
#define XOS_PROTOCOL_TLS_PROTOCOL_VERSION_MESSAGE_HPP

#include "xos/protocol/tls/message/part.hpp"
#include "xos/protocol/tls/protocol/version/part.hpp"
#include "xos/protocol/tls/protocol/version/which.hpp"

namespace xos {
namespace protocol {
namespace tls {
namespace protocol {
namespace version {

/// class messaget
template 
<typename TWhich = tls::protocol::version_which_t, TWhich VWhich = tls::protocol::version_12,
 TWhich VMajorShift = tls::protocol::version_major_shift, TWhich VMajorMask = tls::protocol::version_major_mask,
 TWhich VMinorShift = tls::protocol::version_minor_shift, TWhich VMinorMask = tls::protocol::version_minor_mask,
 typename TValue = tls::protocol::version::part::value_t, TValue VNone = 0,
 class TPart = tls::protocol::version::part, class TMessagePart = tls::message::part, 
 class TExtends = TMessagePart, class TImplements = typename TExtends::implements>

class exported messaget: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef messaget derives; 
    
    typedef TMessagePart message_part_t;
    typedef TPart part_t;
    typedef TValue value_t;
    enum { none = VNone };
    typedef TWhich which_t;
    enum {
        which = VWhich,

        major_shift = VMajorShift,
        major_mask  = VMajorMask,

        minor_shift = VMinorShift,
        minor_mask  = VMinorMask
    };
    
    /// constructors / destructor
    messaget(const messaget& copy): extends(copy) {
        combine();
    }
    messaget(const which_t& which)
    : major_((which >> major_shift) & major_mask), 
      minor_((which >> minor_shift) & minor_mask) {
        combine();
    }
    messaget(const value_t& major, const value_t& minor)
    : major_(major), minor_(minor) {
        combine();
    }
    messaget()
    : major_((which >> major_shift) & major_mask), 
      minor_((which >> minor_shift) & minor_mask) {
        combine();
    }
    virtual ~messaget() {
    }

    /// combine / separate
    virtual bool combine(const value_t& major, const value_t& minor) {
        bool success = false;
        if (sizeof(which_t) == (set_to_msb(major, minor))) {
            success = true;
        }
        return success;
    }
    virtual bool combine() {
        bool success = false;
        const value_t &major = major_.value(), &minor = major_.value();
        if (sizeof(which_t) == (set_to_msb(major, minor))) {
            success = true;
        }
        return success;
    }
    virtual bool separate(size_t& count, const byte_t* bytes, size_t length) {
        bool success = false;

        count = 0;
        if ((bytes) && (length >= part_t::size_of)) {
            size_t amount = 0;
            value_t none = derives::none;
            part_t major(none);
            
            if ((part_t::size_of == (amount = major.set_from_msb(bytes, length)))) {
                const value_t &major_value = major.value();
                part_t minor(none);
                
                count += amount;
                bytes += amount;
                length -= amount;
                if ((part_t::size_of == (amount = minor.set_from_msb(bytes, length)))) {
                    const value_t &minor_value = major.value();
                    
                    count += amount;
                    bytes += amount;
                    length -= amount;
                    if (sizeof(which_t) == (amount = set_to_msb(major_value, minor_value))) {
                        success = true;
                    } else {
                        count = 0;
                    }
                } else {
                    count = 0;
                }
            }
        }
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

    /// ...to_msb
    virtual size_t set_to_msb(const value_t& major, const value_t& minor) {
        size_t length = 0, size = 0;
        
        this->set_length(length = 0);
        if ((part_t::size_of == (size = major_.set_to_msb(major)))) {
            
            length += size;
            this->append(major_);
            if ((part_t::size_of == (size = minor_.set_to_msb(minor)))) {

                length += size;
                this->append(minor_);
            } else {
                this->set_length(length = 0);
            }
        }
        return length;
    }

    /// ...major / minor...
    virtual part_t& major() const {
        return (part_t&)major_;
    }
    virtual part_t& minor() const {
        return (part_t&)minor_;
    }

protected:
    part_t major_, minor_;
}; /// class messaget
typedef messaget<> message;

} /// namespace version
} /// namespace protocol
} /// namespace tls
} /// namespace protocol
} /// namespace xos

#endif /// ndef XOS_PROTOCOL_TLS_PROTOCOL_VERSION_MESSAGE_HPP
