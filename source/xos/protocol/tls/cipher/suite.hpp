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
///   File: suite.hpp
///
/// Author: $author$
///   Date: 4/12/2022, 5/14/2022
///
///////////////////////////////////////////////////////////////////////
/// 
/// Dierks & Rescorla           Standards Track
/// RFC 5246                          TLS                        August 2008
/// 
/// A.5.  The Cipher Suite
/// 
///    The following values define the cipher suite codes used in the
///    ClientHello and ServerHello messages.
/// 
///    A cipher suite defines a cipher specification supported in TLS
///    Version 1.2.
/// 
///    TLS_NULL_WITH_NULL_NULL is specified and is the initial state of a
///    TLS connection during the first handshake on that channel, but MUST
///    NOT be negotiated, as it provides no more protection than an
///    unsecured connection.
/// 
///       CipherSuite TLS_NULL_WITH_NULL_NULL               = { 0x00,0x00 };
/// 
///    The following CipherSuite definitions require that the server provide
///    an RSA certificate that can be used for key exchange.  The server may
///    request any signature-capable certificate in the certificate request
///    message.
/// 
///       CipherSuite TLS_RSA_WITH_NULL_MD5                 = { 0x00,0x01 };
///       CipherSuite TLS_RSA_WITH_NULL_SHA                 = { 0x00,0x02 };
///       CipherSuite TLS_RSA_WITH_NULL_SHA256              = { 0x00,0x3B };
///       CipherSuite TLS_RSA_WITH_RC4_128_MD5              = { 0x00,0x04 };
///       CipherSuite TLS_RSA_WITH_RC4_128_SHA              = { 0x00,0x05 };
///       CipherSuite TLS_RSA_WITH_3DES_EDE_CBC_SHA         = { 0x00,0x0A };
///       CipherSuite TLS_RSA_WITH_AES_128_CBC_SHA          = { 0x00,0x2F };
///       CipherSuite TLS_RSA_WITH_AES_256_CBC_SHA          = { 0x00,0x35 };
///       CipherSuite TLS_RSA_WITH_AES_128_CBC_SHA256       = { 0x00,0x3C };
///       CipherSuite TLS_RSA_WITH_AES_256_CBC_SHA256       = { 0x00,0x3D };
/// 
///    The following cipher suite definitions are used for server-
///    authenticated (and optionally client-authenticated) Diffie-Hellman.
///    DH denotes cipher suites in which the server's certificate contains
///    the Diffie-Hellman parameters signed by the certificate authority
///    (CA).  DHE denotes ephemeral Diffie-Hellman, where the Diffie-Hellman
///    parameters are signed by a signature-capable certificate, which has
///    been signed by the CA.  The signing algorithm used by the server is
///    specified after the DHE component of the CipherSuite name.  The
///    server can request any signature-capable certificate from the client
///    for client authentication, or it may request a Diffie-Hellman
///    certificate.  Any Diffie-Hellman certificate provided by the client
///    must use the parameters (group and generator) described by the
///    server.
/// 
///       CipherSuite TLS_DH_DSS_WITH_3DES_EDE_CBC_SHA      = { 0x00,0x0D };
///       CipherSuite TLS_DH_RSA_WITH_3DES_EDE_CBC_SHA      = { 0x00,0x10 };
///       CipherSuite TLS_DHE_DSS_WITH_3DES_EDE_CBC_SHA     = { 0x00,0x13 };
///       CipherSuite TLS_DHE_RSA_WITH_3DES_EDE_CBC_SHA     = { 0x00,0x16 };
///       CipherSuite TLS_DH_DSS_WITH_AES_128_CBC_SHA       = { 0x00,0x30 };
///       CipherSuite TLS_DH_RSA_WITH_AES_128_CBC_SHA       = { 0x00,0x31 };
///       CipherSuite TLS_DHE_DSS_WITH_AES_128_CBC_SHA      = { 0x00,0x32 };
///       CipherSuite TLS_DHE_RSA_WITH_AES_128_CBC_SHA      = { 0x00,0x33 };
///       CipherSuite TLS_DH_DSS_WITH_AES_256_CBC_SHA       = { 0x00,0x36 };
///       CipherSuite TLS_DH_RSA_WITH_AES_256_CBC_SHA       = { 0x00,0x37 };
///       CipherSuite TLS_DHE_DSS_WITH_AES_256_CBC_SHA      = { 0x00,0x38 };
///       CipherSuite TLS_DHE_RSA_WITH_AES_256_CBC_SHA      = { 0x00,0x39 };
///       CipherSuite TLS_DH_DSS_WITH_AES_128_CBC_SHA256    = { 0x00,0x3E };
///       CipherSuite TLS_DH_RSA_WITH_AES_128_CBC_SHA256    = { 0x00,0x3F };
///       CipherSuite TLS_DHE_DSS_WITH_AES_128_CBC_SHA256   = { 0x00,0x40 };
///       CipherSuite TLS_DHE_RSA_WITH_AES_128_CBC_SHA256   = { 0x00,0x67 };
///       CipherSuite TLS_DH_DSS_WITH_AES_256_CBC_SHA256    = { 0x00,0x68 };
///       CipherSuite TLS_DH_RSA_WITH_AES_256_CBC_SHA256    = { 0x00,0x69 };
///       CipherSuite TLS_DHE_DSS_WITH_AES_256_CBC_SHA256   = { 0x00,0x6A };
///       CipherSuite TLS_DHE_RSA_WITH_AES_256_CBC_SHA256   = { 0x00,0x6B };
/// 
///    The following cipher suites are used for completely anonymous
///    Diffie-Hellman communications in which neither party is
///    authenticated.  Note that this mode is vulnerable to man-in-the-
///    middle attacks.  Using this mode therefore is of limited use: These
///    cipher suites MUST NOT be used by TLS 1.2 implementations unless the
///    application layer has specifically requested to allow anonymous key
///    exchange.  (Anonymous key exchange may sometimes be acceptable, for
///    example, to support opportunistic encryption when no set-up for
///    authentication is in place, or when TLS is used as part of more
///    complex security protocols that have other means to ensure
///    authentication.)
/// 
///       CipherSuite TLS_DH_anon_WITH_RC4_128_MD5          = { 0x00,0x18 };
///       CipherSuite TLS_DH_anon_WITH_3DES_EDE_CBC_SHA     = { 0x00,0x1B };
///       CipherSuite TLS_DH_anon_WITH_AES_128_CBC_SHA      = { 0x00,0x34 };
///       CipherSuite TLS_DH_anon_WITH_AES_256_CBC_SHA      = { 0x00,0x3A };
///       CipherSuite TLS_DH_anon_WITH_AES_128_CBC_SHA256   = { 0x00,0x6C };
///       CipherSuite TLS_DH_anon_WITH_AES_256_CBC_SHA256   = { 0x00,0x6D };
/// 
///    Note that using non-anonymous key exchange without actually verifying
///    the key exchange is essentially equivalent to anonymous key exchange,
///    and the same precautions apply.  While non-anonymous key exchange
///    will generally involve a higher computational and communicational
///    cost than anonymous key exchange, it may be in the interest of
///    interoperability not to disable non-anonymous key exchange when the
///    application layer is allowing anonymous key exchange.
/// 
///    New cipher suite values have been assigned by IANA as described in
///    Section 12.
/// 
///    Note: The cipher suite values { 0x00, 0x1C } and { 0x00, 0x1D } are
///    reserved to avoid collision with Fortezza-based cipher suites in
///    SSL 3.
/// 
///////////////////////////////////////////////////////////////////////
#ifndef XOS_PROTOCOL_TLS_CIPHER_SUITE_HPP
#define XOS_PROTOCOL_TLS_CIPHER_SUITE_HPP

#include "xos/protocol/tls/message/part.hpp"

namespace xos {
namespace protocol {
namespace tls {
namespace cipher {

/// enum suite_which_t
typedef uint8_t suite_which_t;
enum {
    suite_TLS_RSA = 0x00,
    suite_TLS_NONE = 0xFF
}; /// enum suite_which_t

/// enum suite_with_t
typedef uint8_t suite_with_t;
enum {
    suite_WITH_AES_256_CBC_SHA256 = 0x3D,
    suite_WITH_NONE_NONE = 0xFF
}; /// enum suite_with_t

/// enum which_suite_t
typedef uint16_t which_suite_t;
enum {
    suite_which_shift = 8,
    suite_which_mask  = 0xff,
    
    suite_with_shift = 0,
    suite_with_mask  = 0xff,

    suite_TLS_RSA_WITH_AES_256_CBC_SHA256 = ((suite_TLS_RSA << suite_which_shift) | suite_WITH_AES_256_CBC_SHA256),
    suite_TLS_NONE_WITH_NONE_NONE = ((suite_TLS_NONE << suite_which_shift) | suite_WITH_NONE_NONE)
}; /// enum which_suite_t

/// class suitet
template 
<typename TWhich = suite_which_t, TWhich VWhich = suite_TLS_RSA, TWhich VNone = suite_TLS_NONE, 
 typename TWith = suite_with_t, TWith VWith = suite_WITH_AES_256_CBC_SHA256, TWith VWithNone = suite_WITH_NONE_NONE,
 typename TWhichSuite = which_suite_t, TWhichSuite VWhichSuite = suite_TLS_RSA_WITH_AES_256_CBC_SHA256, TWhichSuite VSuiteNone = suite_TLS_NONE_WITH_NONE_NONE,
 TWhichSuite VSuiteWhichShift = suite_which_shift, TWhichSuite VSuiteWhichMASK = suite_which_mask,
 TWhichSuite VSuiteWithShift = suite_with_shift, TWhichSuite VSuiteWithMASK = suite_with_mask,
 class TMessagePart = tls::message::part, class TExtends = TMessagePart, class TImplements = typename TExtends::implements>

class exported suitet: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef suitet derives; 
    
    typedef TWhichSuite which_suite_t;
    enum { 
        suite_which_shift = VSuiteWhichShift, suite_which_mask = VSuiteWhichMASK,
        suite_with_shift = VSuiteWithShift, suite_with_mask = VSuiteWithMASK,
        suite_which = VWhichSuite, suite_none = VSuiteNone 
    };

    typedef TWhich which_t;
    enum { which = VWhich, none = VNone };

    typedef TWith with_t;
    enum { with = VWith, with_none = VWithNone};
    
    /// constructors / destructor
    suitet(const suitet& copy): which_(copy.which_), with_(copy.which_) {
        combine();
    }
    suitet(const which_t& which, const which_t& with): which_(which), with_(with) {
        combine();
    }
    suitet(): which_(which), with_(with) {
        combine();
    }
    virtual ~suitet() {
    }

    /// combine / separate
    virtual bool combine(const which_suite_t& suite) {
        bool success = false;
        which_t which = ((suite >> suite_which_shift) & suite_which_mask);
        with_t with = ((suite >> suite_with_shift) & suite_with_mask);
        if ((this->set_to_msb(which))) {
            if ((this->to_msb(with))) {
                success = true;
            }
        }
        return success;
    }
    virtual bool combine(const which_t& which, const with_t& with) {
        bool success = false;
        if ((this->set_to_msb(which))) {
            if ((this->to_msb(with))) {
                success = true;
            }
        }
        return success;
    }
    virtual bool combine() {
        bool success = false;
        if ((this->set_to_msb(which_))) {
            if ((this->to_msb(with_))) {
                success = true;
            }
        }
        return success;
    }
    virtual bool separate(size_t& count, const byte_t* bytes, size_t length) {
        bool success = false;
        count = 0;
        if ((bytes) && (length >= (sizeof(which_t)+sizeof(with_t)))) {
            which_t which = none;
            size_t amount = 0;
            if (sizeof(which_t) == (amount = this->from_msb(which, bytes, length))) {
                with_t with = with_none;
                count += amount;
                bytes += amount;
                length -= amount;
                if (sizeof(with_t) == (amount = this->from_msb(with, bytes, length))) {
                    count += amount;
                    bytes += amount;
                    length -= amount;
                    if ((this->set_to_msb(which))) {
                        if ((this->to_msb(with))) {
                            success = true;
                        }
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

    /// ...which_suite
    virtual which_suite_t set_which_suite(const which_suite_t& suite) {
        which_ = ((suite >> suite_which_shift) & suite_which_mask);
        with_ = ((suite >> suite_with_shift) & suite_with_mask);
        combine();
        return suite;
    }
    virtual which_suite_t is_which_suite() const {
        which_suite_t suite = ((which_ & suite_which_mask) << suite_which_shift)
                              | ((with_ & suite_with_mask) << suite_with_shift);
        return suite;
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

    /// ...with
    virtual with_t set_with(const with_t& with) {
        with_ = with;
        combine();
        return with_;
    }
    virtual with_t is_with() const {
        return with_;
    }

protected:
    which_t which_;
    with_t with_;
}; /// class suitet
typedef suitet<> suite;

} /// namespace cipher
} /// namespace tls
} /// namespace protocol
} /// namespace xos

#endif /// ndef XOS_PROTOCOL_TLS_CIPHER_SUITE_HPP
