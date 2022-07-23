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
///   File: method.hpp
///
/// Author: $author$
///   Date: 4/12/2022, 5/14/2022
/// 
///////////////////////////////////////////////////////////////////////
///
/// Dierks & Rescorla           Standards Track
/// RFC 5246                          TLS                        August 2008
/// 
/// 6.2.2.  Record Compression and Decompression
/// 
///    All records are compressed using the compression algorithm defined in
///    the current session state.  There is always an active compression
///    algorithm; however, initially it is defined as
///    CompressionMethod.null.  The compression algorithm translates a
///    TLSPlaintext structure into a TLSCompressed structure.  Compression
///    functions are initialized with default state information whenever a
///    connection state is made active.  [RFC3749] describes compression
///    algorithms for TLS.
/// 
///    Compression must be lossless and may not increase the content length
///    by more than 1024 bytes.  If the decompression function encounters a
///    TLSCompressed.fragment that would decompress to a length in excess of
///    2^14 bytes, it MUST report a fatal decompression failure error.
/// 
///       enum { null(0), (255) } CompressionMethod;
/// 
///       struct {
///           ContentType type;       / * same as TLSPlaintext.type * /
///           ProtocolVersion version;/ * same as TLSPlaintext.version * /
///           uint16 length;
///           opaque fragment[TLSCompressed.length];
///       } TLSCompressed;
/// 
///    length
///       The length (in bytes) of the following TLSCompressed.fragment.
///       The length MUST NOT exceed 2^14 + 1024.
/// 
///    fragment
///       The compressed form of TLSPlaintext.fragment.
/// 
///       Note: A CompressionMethod.null operation is an identity operation;
///       no fields are altered.
/// 
///       Implementation note: Decompression functions are responsible for
///       ensuring that messages cannot cause internal buffer overflows.
///
///////////////////////////////////////////////////////////////////////
#ifndef XOS_PROTOCOL_TLS_COMPRESSION_METHOD_HPP
#define XOS_PROTOCOL_TLS_COMPRESSION_METHOD_HPP

#include "xos/protocol/tls/message/part.hpp"

namespace xos {
namespace protocol {
namespace tls {
namespace compression {

/// enum method_which_t
typedef uint8_t method_which_t;
enum {
    method_null = 0x00,
    method_none = method_null,
    method_gzip = 0x01
}; /// enum method_which_t

/// class methodt
template 
<typename TWhich = method_which_t, TWhich VWhich = method_none, TWhich VNone = method_none, 
 class TMessagePart = tls::message::part, class TExtends = TMessagePart, class TImplements = typename TExtends::implements>

class exported methodt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef methodt derives; 
    
    typedef TWhich which_t;
    enum { none = VNone, which = VWhich };
    
    /// constructors / destructor
    methodt(const methodt& copy): which_(copy.which_) {
        combine();
    }
    methodt(const which_t& which): which_(which) {
        combine();
    }
    methodt(): which_(which) {
        combine();
    }
    virtual ~methodt() {
    }
    
    /// combine / separate
    virtual bool combine(const which_t& which) {
        bool success = false;
        if ((this->set_to_msb(which))) {
            success = true;
        }
        return success;
    }
    virtual bool combine() {
        bool success = false;
        if ((this->set_to_msb(which_))) {
            success = true;
        }
        return success;
    }
    virtual bool separate(size_t& count, const byte_t* bytes, size_t length) {
        bool success = false;
        count = 0;
        if ((bytes) && (length >= (sizeof(which_t)))) {
            which_t which = none;
            size_t amount = 0;
            if (sizeof(which_t) == (amount = this->from_msb(which, bytes, length))) {
                count += amount;
                bytes += amount;
                length -= amount;
                if ((this->set_to_msb(which))) {
                    success = true;
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

    /// ...which
    virtual which_t set_which(const which_t& which) {
        which_ = which;
        combine();
        return which_;
    }
    virtual which_t is_which() const {
        return which_;
    }

protected:
    which_t which_;
}; /// class methodt
typedef methodt<> method;

} /// namespace compression
} /// namespace tls
} /// namespace protocol
} /// namespace xos

#endif /// ndef XOS_PROTOCOL_TLS_COMPRESSION_METHOD_HPP
