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
///   Date: 5/14/2022
/// 
///////////////////////////////////////////////////////////////////////
///
/// Dierks & Rescorla           Standards Track
/// RFC 5246                          TLS                        August 2008
/// 
/// 7.4.3.  Server Key Exchange Message
/// 
///    When this message will be sent:
/// 
///       This message will be sent immediately after the server Certificate
///       message (or the ServerHello message, if this is an anonymous
///       negotiation).
/// 
///       The ServerKeyExchange message is sent by the server only when the
///       server Certificate message (if sent) does not contain enough data
///       to allow the client to exchange a premaster secret.  This is true
///       for the following key exchange methods:
/// 
///          DHE_DSS
///          DHE_RSA
///          DH_anon
/// 
///       It is not legal to send the ServerKeyExchange message for the
///       following key exchange methods:
/// 
///          RSA
///          DH_DSS
///          DH_RSA
/// 
///       Other key exchange algorithms, such as those defined in [TLSECC],
///       MUST specify whether the ServerKeyExchange message is sent or not;
///       and if the message is sent, its contents.
/// 
/// Meaning of this message:
/// 
///    This message conveys cryptographic information to allow the client
///    to communicate the premaster secret: a Diffie-Hellman public key
///    with which the client can complete a key exchange (with the result
///    being the premaster secret) or a public key for some other
///    algorithm.
/// 
/// Structure of this message:
/// 
///    enum { dhe_dss, dhe_rsa, dh_anon, rsa, dh_dss, dh_rsa
///          /* may be extended, e.g., for ECDH -- see [TLSECC] */
///         } KeyExchangeAlgorithm;
/// 
///    struct {
///        opaque dh_p<1..2^16-1>;
///        opaque dh_g<1..2^16-1>;
///        opaque dh_Ys<1..2^16-1>;
///    } ServerDHParams;     /* Ephemeral DH parameters */
/// 
///    dh_p
///       The prime modulus used for the Diffie-Hellman operation.
/// 
///    dh_g
///       The generator used for the Diffie-Hellman operation.
/// 
///    dh_Ys
///       The server's Diffie-Hellman public value (g^X mod p).
/// 
///    struct {
///        select (KeyExchangeAlgorithm) {
///            case dh_anon:
///                ServerDHParams params;
///            case dhe_dss:
///            case dhe_rsa:
///                ServerDHParams params;
///                digitally-signed struct {
///                    opaque client_random[32];
///                    opaque server_random[32];
///                    ServerDHParams params;
///                } signed_params;
/// 
///            case rsa_private:
///                EncryptedPreMasterSecret;
///                /* added to allow client private key rsa encryption */
/// 
///            case rsa_plain:
///                PKCSEncodedPreMasterSecret;
///                /* added for testing purposes only */
/// 
///            case rsa:
///            case dh_dss:
///            case dh_rsa:
///                struct {} ;
///               /* message is omitted for rsa, dh_dss, and dh_rsa */
///            /* may be extended, e.g., for ECDH -- see [TLSECC] */
///        };
///    } ServerKeyExchange;
/// 
///    params
///       The server's key exchange parameters.
/// 
///    signed_params
///       For non-anonymous key exchanges, a signature over the server's
///       key exchange parameters.
/// 
/// If the client has offered the "signature_algorithms" extension, the
/// signature algorithm and hash algorithm MUST be a pair listed in that
/// extension.  Note that there is a possibility for inconsistencies
/// here.  For instance, the client might offer DHE_DSS key exchange but
/// omit any DSA pairs from its "signature_algorithms" extension.  In
/// order to negotiate correctly, the server MUST check any candidate
/// cipher suites against the "signature_algorithms" extension before
/// selecting them.  This is somewhat inelegant but is a compromise
/// designed to minimize changes to the original cipher suite design.
/// 
/// In addition, the hash and signature algorithms MUST be compatible
/// with the key in the server's end-entity certificate.  RSA keys MAY be
/// used with any permitted hash algorithm, subject to restrictions in
/// the certificate, if any.
/// 
/// Because DSA signatures do not contain any secure indication of hash
/// algorithm, there is a risk of hash substitution if multiple hashes
/// may be used with any key.  Currently, DSA [DSS] may only be used with
/// SHA-1.  Future revisions of DSS [DSS-3] are expected to allow the use
/// of other digest algorithms with DSA, as well as guidance as to which
/// digest algorithms should be used with each key size.  In addition,
/// future revisions of [PKIX] may specify mechanisms for certificates to
/// indicate which digest algorithms are to be used with DSA.
/// 
/// As additional cipher suites are defined for TLS that include new key
/// exchange algorithms, the server key exchange message will be sent if
/// and only if the certificate type associated with the key exchange
/// algorithm does not provide enough information for the client to
/// exchange a premaster secret.
///
///////////////////////////////////////////////////////////////////////
#ifndef XOS_PROTOCOL_TLS_SERVER_KEY_EXCHANGE_MESSAGE_HPP
#define XOS_PROTOCOL_TLS_SERVER_KEY_EXCHANGE_MESSAGE_HPP

#include "xos/protocol/tls/message/part.hpp"
#include "xos/protocol/tls/key/exchange/algorithm.hpp"
#include "xos/protocol/tls/premaster/secret/message.hpp"
#include "xos/protocol/tls/encrypted/premaster/secret.hpp"

namespace xos {
namespace protocol {
namespace tls {
namespace server {
namespace key {
namespace exchange {

/// class messaget
template 
<typename TKeyExchangeAlgorithm = tls::key::exchange::algorithm, 
 TKeyExchangeAlgorithm VKeyExchangeAlgorithmRsa = tls::key::exchange::rsa,
 TKeyExchangeAlgorithm VKeyExchangeAlgorithmRsaPrivate = tls::key::exchange::rsa_private,
 TKeyExchangeAlgorithm VKeyExchangeAlgorithmRsaPlain = tls::key::exchange::rsa_plain,
 TKeyExchangeAlgorithm VKeyExchangeAlgorithm = VKeyExchangeAlgorithmRsaPrivate,
 class TEncryptedPreMasterSecret = tls::encrypted::premaster::secret,
 class TPreMasterSecret = tls::premaster::secret::message,
 class TMessagePart = message::part, class TExtends = TMessagePart, class TImplements = typename TExtends::implements>

class exported messaget: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef messaget derives; 
    
    typedef TKeyExchangeAlgorithm key_exchange_algorithm_t;
    enum { 
        key_exchange_algorithm_rsa = VKeyExchangeAlgorithmRsa,
        key_exchange_algorithm_rsa_private = VKeyExchangeAlgorithmRsaPrivate,
        key_exchange_algorithm_rsa_plain = VKeyExchangeAlgorithmRsaPlain,
        key_exchange_algorithm = VKeyExchangeAlgorithm
    };
    typedef TEncryptedPreMasterSecret encrypted_pre_master_secret_t;
    typedef TPreMasterSecret pre_master_secret_t;
    typedef typename encrypted_pre_master_secret_t::rsa_key_t rsa_key_t;

    /// constructors / destructor
    messaget(const key_exchange_algorithm_t& key_exchange_algorithm, const encrypted_pre_master_secret_t& encrypted_pre_master_secret)
    : key_exchange_algorithm_(key_exchange_algorithm) {
        combine(encrypted_pre_master_secret);
    }
    messaget(const encrypted_pre_master_secret_t& encrypted_pre_master_secret)
    : key_exchange_algorithm_(key_exchange_algorithm_rsa_private) {
        combine(encrypted_pre_master_secret);
    }
    messaget(const pre_master_secret_t& pre_master_secret)
    : key_exchange_algorithm_(key_exchange_algorithm_rsa_plain) {
        combine(pre_master_secret);
    }
    messaget(const messaget& copy): extends(copy), key_exchange_algorithm_(copy.key_exchange_algorithm_) {
    }
    messaget(): key_exchange_algorithm_(key_exchange_algorithm) {
    }
    virtual ~messaget() {
    }

    /// combine / separate
    virtual bool combine(const encrypted_pre_master_secret_t& encrypted_pre_master_secret) {
        bool success = false;
        this->set_length(0);
        if ((this->append(encrypted_pre_master_secret))) {
            success = true;
        }
        return success;
    }
    virtual bool combine(const pre_master_secret_t& pre_master_secret) {
        bool success = false;
        this->set_length(0);
        if ((this->append(pre_master_secret))) {
            success = true;
        }
        return success;
    }
    virtual bool combine() {
        bool success = false;
        return success;
    }
    virtual bool separate(size_t& count, rsa_key_t& rsa_key, const byte_t *bytes, size_t length) {
        bool success = false;
        size_t amount = 0;
        
        count = 0;
        if ((bytes) && (0 < (length))) {
            if ((encrypted_pre_master_secret_.separate(amount, rsa_key, bytes, length))) {
                count += amount;
                bytes += amount;
                length -= amount;
                success = true;
            }
        }
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

    /// ...
    virtual key_exchange_algorithm_t& key_exchange_algorithm_of() const {
        return (key_exchange_algorithm_t&)key_exchange_algorithm_;
    }
    virtual encrypted_pre_master_secret_t& encrypted_pre_master_secret() const {
        return (encrypted_pre_master_secret_t&)encrypted_pre_master_secret_;
    }

protected:
    key_exchange_algorithm_t key_exchange_algorithm_;
    encrypted_pre_master_secret_t encrypted_pre_master_secret_;
}; /// class messaget
typedef messaget<> message;

} /// namespace exchange
} /// namespace key
} /// namespace server
} /// namespace tls
} /// namespace protocol
} /// namespace xos

#endif /// ndef XOS_PROTOCOL_TLS_SERVER_KEY_EXCHANGE_MESSAGE_HPP
