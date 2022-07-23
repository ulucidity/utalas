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
///   File: code.hpp
///
/// Author: $author$
///   Date: 5/16/2022
///////////////////////////////////////////////////////////////////////
///
/// Dierks & Rescorla           Standards Track
/// RFC 5246                          TLS                        August 2008
/// 
/// 7.4.1.4.1.  Signature Algorithms
/// 
///    The client uses the "signature_algorithms" extension to indicate to
///    the server which signature/hash algorithm pairs may be used in
///    digital signatures.  The "extension_data" field of this extension
///    contains a "supported_signature_algorithms" value.
/// 
/// struct {
///       HashAlgorithm hash;
///       SignatureAlgorithm signature;
/// } SignatureAndHashAlgorithm;
/// 
/// SignatureAndHashAlgorithm
///   supported_signature_algorithms<2..2^16-2>;
/// 
/// Each SignatureAndHashAlgorithm value lists a single hash/signature
/// pair that the client is willing to verify.  The values are indicated
/// in descending order of preference.
/// 
/// Note: Because not all signature algorithms and hash algorithms may be
/// accepted by an implementation (e.g., DSA with SHA-1, but not
/// SHA-256), algorithms here are listed in pairs.
/// 
/// hash
///    This field indicates the hash algorithm which may be used.  The
///    values indicate support for unhashed data, MD5 [MD5], SHA-1,
///    SHA-224, SHA-256, SHA-384, and SHA-512 [SHS], respectively.  The
///    "none" value is provided for future extensibility, in case of a
///    signature algorithm which does not require hashing before signing.
/// 
/// signature
///    This field indicates the signature algorithm that may be used.
///    The values indicate anonymous signatures, RSASSA-PKCS1-v1_5
///    [PKCS1] and DSA [DSS], and ECDSA [ECDSA], respectively.  The
///    "anonymous" value is meaningless in this context but used in
///    Section 7.4.3.  It MUST NOT appear in this extension.
/// 
/// The semantics of this extension are somewhat complicated because the
/// cipher suite indicates permissible signature algorithms but not hash
/// algorithms.  Sections 7.4.2 and 7.4.3 describe the appropriate rules.
/// 
/// If the client supports only the default hash and signature algorithms
/// (listed in this section), it MAY omit the signature_algorithms
/// extension.  If the client does not support the default algorithms, or
/// supports other hash and signature algorithms (and it is willing to
/// use them for verifying messages sent by the server, i.e., server
/// certificates and server key exchange), it MUST send the
/// signature_algorithms extension, listing the algorithms it is willing
/// to accept.
/// 
/// If the client does not send the signature_algorithms extension, the
/// server MUST do the following:
/// 
/// -  If the negotiated key exchange algorithm is one of (RSA, DHE_RSA,
///    DH_RSA, RSA_PSK, ECDH_RSA, ECDHE_RSA), behave as if client had
///    sent the value {sha1,rsa}.
/// 
/// -  If the negotiated key exchange algorithm is one of (DHE_DSS,
///    DH_DSS), behave as if the client had sent the value {sha1,dsa}.
/// 
/// -  If the negotiated key exchange algorithm is one of (ECDH_ECDSA,
///    ECDHE_ECDSA), behave as if the client had sent value {sha1,ecdsa}.
/// 
/// Note: this is a change from TLS 1.1 where there are no explicit
/// rules, but as a practical matter one can assume that the peer
/// supports MD5 and SHA-1.
/// 
/// Note: this extension is not meaningful for TLS versions prior to 1.2.
/// Clients MUST NOT offer it if they are offering prior versions.
/// However, even if clients do offer it, the rules specified in [TLSEXT]
/// require servers to ignore extensions they do not understand.
/// 
/// Servers MUST NOT send this extension.  TLS servers MUST support
/// receiving this extension.
/// 
/// When performing session resumption, this extension is not included in
/// Server Hello, and the server ignores the extension in Client Hello
/// (if present).
/// 
///////////////////////////////////////////////////////////////////////
#ifndef XOS_PROTOCOL_TLS_SIGNATURE_HASH_ALGORITHM_CODE_HPP
#define XOS_PROTOCOL_TLS_SIGNATURE_HASH_ALGORITHM_CODE_HPP

#include "xos/protocol/tls/message/part.hpp"

namespace xos {
namespace protocol {
namespace tls {
namespace signature {
namespace hash {
namespace algorithm {

/// class codet
template 
<class TMessagePart = message::part, 
 class TExtends = TMessagePart, class TImplements = typename TExtends::implements>

class exported codet: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef codet derives; 
    
    /// constructors / destructor
    codet(const codet& copy): extends(copy) {
        combine();
    }
    codet() {
        combine();
    }
    virtual ~codet() {
    }

    /// combine / separate
    virtual bool combine() {
        bool success = false;
        return success;
    }
    virtual bool separate(size_t& count, const byte_t* bytes, size_t length) {
        bool success = false;
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

protected:
}; /// class codet
typedef codet<> code;

} /// namespace algorithm
} /// namespace hash
} /// namespace signature
} /// namespace tls
} /// namespace protocol
} /// namespace xos

#endif /// ndef XOS_PROTOCOL_TLS_SIGNATURE_HASH_ALGORITHM_CODE_HPP
