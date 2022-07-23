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
///   Date: 3/11/2022, 5/14/2022
/// 
///////////////////////////////////////////////////////////////////////
///
/// Dierks & Rescorla           Standards Track
/// RFC 5246                          TLS                        August 2008
/// 
/// 7.4.7.  Client Key Exchange Message
/// 
///    When this message will be sent:
/// 
///       This message is always sent by the client.  It MUST immediately
///       follow the client certificate message, if it is sent.  Otherwise,
///       it MUST be the first message sent by the client after it receives
///       the ServerHelloDone message.
/// 
///    Meaning of this message:
/// 
///       With this message, the premaster secret is set, either by direct
///       transmission of the RSA-encrypted secret or by the transmission of
///       Diffie-Hellman parameters that will allow each side to agree upon
///       the same premaster secret.
/// 
///       When the client is using an ephemeral Diffie-Hellman exponent,
///       then this message contains the client's Diffie-Hellman public
///       value.  If the client is sending a certificate containing a static
///       DH exponent (i.e., it is doing fixed_dh client authentication),
///       then this message MUST be sent but MUST be empty.
/// 
///    Structure of this message:
/// 
///       The choice of messages depends on which key exchange method has
///       been selected.  See Section 7.4.3 for the KeyExchangeAlgorithm
///       definition.
/// 
///       struct {
///           select (KeyExchangeAlgorithm) {
/// 
///               case rsa_plain:
///                   PKCSEncodedPreMasterSecret; 
///                   /* added for testing purposes only */
/// 
///               case rsa:
///                   EncryptedPreMasterSecret;
///               case dhe_dss:
///               case dhe_rsa:
///               case dh_dss:
///               case dh_rsa:
///               case dh_anon:
///                   ClientDiffieHellmanPublic;
///           } exchange_keys;
///       } ClientKeyExchange;
///
///////////////////////////////////////////////////////////////////////
#ifndef XOS_PROTOCOL_TLS_CLIENT_KEY_EXCHANGE_MESSAGE_HPP
#define XOS_PROTOCOL_TLS_CLIENT_KEY_EXCHANGE_MESSAGE_HPP

#include "xos/protocol/tls/key/exchange/algorithm.hpp"
#include "xos/protocol/tls/premaster/secret/message.hpp"
#include "xos/protocol/tls/encrypted/premaster/secret.hpp"

namespace xos {
namespace protocol {
namespace tls {
namespace client {
namespace key {
namespace exchange {

/// class messaget
template 
<typename TKeyExchangeAlgorithm = tls::key::exchange::algorithm, 
 TKeyExchangeAlgorithm VKeyExchangeAlgorithmRsa = tls::key::exchange::rsa,
 TKeyExchangeAlgorithm VKeyExchangeAlgorithmRsaPlain = tls::key::exchange::rsa_plain,
 TKeyExchangeAlgorithm VKeyExchangeAlgorithm = VKeyExchangeAlgorithmRsa,
 class TEncryptedPreMasterSecret = tls::encrypted::premaster::secret,
 class TPreMasterSecret = tls::premaster::secret::message,
 class TMessagePart = tls::message::part, class TExtends = TMessagePart, class TImplements = typename TExtends::implements>

class exported messaget: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef messaget derives; 
    
    typedef TKeyExchangeAlgorithm key_exchange_algorithm_t;
    enum { 
        key_exchange_algorithm_rsa = VKeyExchangeAlgorithmRsa,
        key_exchange_algorithm_rsa_plain = VKeyExchangeAlgorithmRsaPlain,
        key_exchange_algorithm = VKeyExchangeAlgorithm
    };
    typedef TEncryptedPreMasterSecret encrypted_pre_master_secret_t;
    typedef TPreMasterSecret pre_master_secret_t;
    typedef typename encrypted_pre_master_secret_t::rsa_key_t rsa_key_t;
    
    /// constructors / destructor
    messaget(const messaget& copy)
    : extends(copy), key_exchange_algorithm_(copy.key_exchange_algorithm_) {
    }
    messaget(const encrypted_pre_master_secret_t& encrypted_pre_master_secret)
    : key_exchange_algorithm_(key_exchange_algorithm_rsa) {
        combine(encrypted_pre_master_secret);
    }
    messaget(const pre_master_secret_t& pre_master_secret)
    : key_exchange_algorithm_(key_exchange_algorithm_rsa_plain) {
        combine(pre_master_secret);
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

    /// ...of
    virtual encrypted_pre_master_secret_t& encrypted_pre_master_secret() const {
        return (encrypted_pre_master_secret_t&)encrypted_pre_master_secret_;
    }
    virtual key_exchange_algorithm_t& key_exchange_algorithm_of() const {
        return (key_exchange_algorithm_t&)key_exchange_algorithm_;
    }

protected:
    key_exchange_algorithm_t key_exchange_algorithm_;
    encrypted_pre_master_secret_t encrypted_pre_master_secret_;
}; /// class messaget
typedef messaget<> message;

} /// namespace exchange
} /// namespace key
} /// namespace client
} /// namespace tls
} /// namespace protocol
} /// namespace xos

#endif /// XOS_PROTOCOL_TLS_CLIENT_KEY_EXCHANGE_MESSAGE_HPP
