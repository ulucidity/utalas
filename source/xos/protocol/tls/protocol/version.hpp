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
///   File: version.hpp
///
/// Author: $author$
///   Date: 5/22/2022
/// 
///////////////////////////////////////////////////////////////////////
///
/// Dierks & Rescorla           Standards Track
/// RFC 5246                          TLS                        August 2008
/// 
///      struct {
///          uint8 major;
///          uint8 minor;
///      } ProtocolVersion;
///
///      version
///         The version of the protocol being employed.  This document
///         describes TLS Version 1.2, which uses the version { 3, 3 }.  The
///         version value 3.3 is historical, deriving from the use of {3, 1}
///         for TLS 1.0.  (See Appendix A.1.)  Note that a client that
///         supports multiple versions of TLS may not know what version will
///         be employed before it receives the ServerHello.  See Appendix E
///         for discussion about what record layer version number should be
///         employed for ClientHello.
///
///////////////////////////////////////////////////////////////////////
#ifndef XOS_PROTOCOL_TLS_PROTOCOL_VERSION_HPP
#define XOS_PROTOCOL_TLS_PROTOCOL_VERSION_HPP

#include "xos/protocol/tls/message/part.hpp"
#include "xos/protocol/tls/uinteger.hpp"

namespace xos {
namespace protocol {
namespace tls {
namespace protocol {

/// version_part_t
typedef uint8_t version_part_t;

/// enum version_which_t
typedef uint16_t version_which_t;
enum {
    version_10 = 0x0301,
    version_11 = 0x0302,
    version_12 = 0x0303,
    version_13 = 0x0304,
    
    version_major_shift = 8,
    version_major_mask  = 0xff,
    
    version_minor_shift = 0,
    version_minor_mask  = 0xff
}; /// enum version_which_t

/// enum version_sizeof_t
typedef version_which_t version_sizeof_t;
enum {
    version_sizeof = sizeof(version_sizeof_t)
}; /// enum version_sizeof_t

/// class versiont
template 
<typename TWhich = tls::protocol::version_which_t, TWhich VWhich = tls::protocol::version_12,
 TWhich VMajorShift = tls::protocol::version_major_shift, TWhich VMajorMask = tls::protocol::version_major_mask,
 TWhich VMinorShift = tls::protocol::version_minor_shift, TWhich VMinorMask = tls::protocol::version_minor_mask,
 typename TSizeOf = tls::protocol::version_sizeof_t, TSizeOf VSizeOf = tls::protocol::version_sizeof,
 typename TPart = tls::protocol::version_part_t, TPart VNone = 0, class TMessagePart = tls::message::part,
 class TExtends = TMessagePart, class TImplements = typename TExtends::implements>

class exported versiont: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef versiont derives; 
    
    typedef TMessagePart message_part_t;
    typedef TPart part_t;
    enum { none = VNone };
    typedef TWhich which_t;
    enum {
        which = VWhich,

        major_shift = VMajorShift,
        major_mask  = VMajorMask,

        minor_shift = VMinorShift,
        minor_mask  = VMinorMask
    };
    typedef TSizeOf size_of_t;
    enum { size_of = VSizeOf };
    
    /// constructors / destructor
    versiont(const versiont& copy): major_(copy.major()), minor_(copy.minor()) {
        combine();
    }
    versiont(const which_t& which)
    : major_((which >> major_shift) & major_mask), 
      minor_((which >> minor_shift) & minor_mask) {
        combine();
    }
    versiont()
    : major_((which >> major_shift) & major_mask), 
      minor_((which >> minor_shift) & minor_mask) {
        combine();
    }
    virtual ~versiont() {
    }
    
    /// combine / separate
    virtual bool combine(const part_t& major, const part_t& minor) {
        bool success = false;
        if (0 <= (set_to_msb(major, minor))) {
            success = true;
        }
        return success;
    }
    virtual bool combine() {
        bool success = true;
        if (0 <= (set_to_msb(major_, minor_))) {
            success = true;
        }
        return success;
    }
    virtual bool separate(size_t& count, const byte_t* bytes, size_t length) {
        bool success = false;

        count = 0;
        if ((bytes) && (length >= sizeof(which_t))) {
            part_t major = none;
            size_t amount = 0;

            if (sizeof(part_t) == (amount = this->from_msb(major, bytes, length))) {
                part_t minor = none;

                count += amount;
                bytes += amount;
                length -= amount;
                if (sizeof(part_t) == (amount = this->from_msb(minor, bytes, length))) {
                    
                    count += amount;
                    bytes += amount;
                    length -= amount;
                    if (sizeof(which_t) == (amount = set_to_msb(major, minor))) {
                        major_ = major;
                        minor_ = minor;
                        success = true;
                    }
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
    virtual size_t set_to_msb(const part_t& major, const part_t& minor) {
        size_t length = 0, size = 0;
        
        this->set_length(length = 0);
        if (sizeof(major_) == (size = this->to_msb(major))) {
            length += size;
            if (sizeof(minor_) == (size = this->to_msb(minor))) {
                length += size;
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
}; /// class versiont
typedef versiont<> version;

} /// namespace protocol
} /// namespace tls
} /// namespace protocol
} /// namespace xos

#endif /// ndef XOS_PROTOCOL_TLS_PROTOCOL_VERSION_HPP
