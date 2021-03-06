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
///   File: secret.hpp
///
/// Author: $author$
///   Date: 3/11/2022, 5/14/2022
/// 
///////////////////////////////////////////////////////////////////////
///
/// Dierks & Rescorla           Standards Track
/// RFC 5246                          TLS                        August 2008
/// 
/// 7.4.7.1.  RSA-Encrypted Premaster Secret Message
/// 
///    Meaning of this message:
/// 
///       If RSA is being used for key agreement and authentication, the
///       client generates a 48-byte premaster secret, encrypts it using the
///       public key from the server's certificate, and sends the result in
///       an encrypted premaster secret message.  This structure is a
///       variant of the ClientKeyExchange message and is not a message in
///       itself.
/// 
///    Structure of this message:
/// 
///       struct {
///           ProtocolVersion client_version;
///           opaque random[46];
///       } PreMasterSecret;
/// 
///       client_version
///          The latest (newest) version supported by the client.  This is
///          used to detect version rollback attacks.
/// 
///       random
///          46 securely-generated random bytes.
/// 
///       struct {
///           public-key-encrypted PreMasterSecret pre_master_secret;
///       } EncryptedPreMasterSecret;
/// 
///       pre_master_secret
///          This random value is generated by the client and is used to
///          generate the master secret, as specified in Section 8.1.
///       
///       Note: The version number in the PreMasterSecret is the version
///       offered by the client in the ClientHello.client_version, not the
///       version negotiated for the connection.  This feature is designed to
///       prevent rollback attacks.  Unfortunately, some old implementations
///       use the negotiated version instead, and therefore checking the
///       version number may lead to failure to interoperate with such
///       incorrect client implementations.
///    
///       Client implementations MUST always send the correct version number in
///       PreMasterSecret.  If ClientHello.client_version is TLS 1.1 or higher,
///       server implementations MUST check the version number as described in
///       the note below.  If the version number is TLS 1.0 or earlier, server
///       implementations SHOULD check the version number, but MAY have a
///       configuration option to disable the check.  Note that if the check
///       fails, the PreMasterSecret SHOULD be randomized as described below.
///    
///       Note: Attacks discovered by Bleichenbacher [BLEI] and Klima et al.
///       [KPR03] can be used to attack a TLS server that reveals whether a
///       particular message, when decrypted, is properly PKCS#1 formatted,
///       contains a valid PreMasterSecret structure, or has the correct
///       version number.
///    
///       As described by Klima [KPR03], these vulnerabilities can be avoided
///       by treating incorrectly formatted message blocks and/or mismatched
///       version numbers in a manner indistinguishable from correctly
///       formatted RSA blocks.  In other words:
///    
///          1. Generate a string R of 46 random bytes
///    
///          2. Decrypt the message to recover the plaintext M
///    
///          3. If the PKCS#1 padding is not correct, or the length of message
///             M is not exactly 48 bytes:
///                pre_master_secret = ClientHello.client_version || R
///             else If ClientHello.client_version <= TLS 1.0, and version
///             number check is explicitly disabled:
///                pre_master_secret = M
///             else:
///                pre_master_secret = ClientHello.client_version || M[2..47]
///    
///       Note that explicitly constructing the pre_master_secret with the
///       ClientHello.client_version produces an invalid master_secret if the
///       client has sent the wrong version in the original pre_master_secret.
///    
///       An alternative approach is to treat a version number mismatch as a
///       PKCS-1 formatting error and randomize the premaster secret
///       completely:
///             
///             1. Generate a string R of 48 random bytes
///       
///             2. Decrypt the message to recover the plaintext M
///       
///             3. If the PKCS#1 padding is not correct, or the length of message
///                M is not exactly 48 bytes:
///                   pre_master_secret = R
///                else If ClientHello.client_version <= TLS 1.0, and version
///                number check is explicitly disabled:
///                   premaster secret = M
///                else If M[0..1] != ClientHello.client_version:
///                   premaster secret = R
///                else:
///                   premaster secret = M
///       
///          Although no practical attacks against this construction are known,
///          Klima et al. [KPR03] describe some theoretical attacks, and therefore
///          the first construction described is RECOMMENDED.
///       
///          In any case, a TLS server MUST NOT generate an alert if processing an
///          RSA-encrypted premaster secret message fails, or the version number
///          is not as expected.  Instead, it MUST continue the handshake with a
///          randomly generated premaster secret.  It may be useful to log the
///          real cause of failure for troubleshooting purposes; however, care
///          must be taken to avoid leaking the information to an attacker
///          (through, e.g., timing, log files, or other channels.)
///       
///          The RSAES-OAEP encryption scheme defined in [PKCS1] is more secure
///          against the Bleichenbacher attack.  However, for maximal
///          compatibility with earlier versions of TLS, this specification uses
///          the RSAES-PKCS1-v1_5 scheme.  No variants of the Bleichenbacher
///          attack are known to exist provided that the above recommendations are
///          followed.
///       
///          Implementation note: Public-key-encrypted data is represented as an
///          opaque vector <0..2^16-1> (see Section 4.7).  Thus, the RSA-encrypted
///          PreMasterSecret in a ClientKeyExchange is preceded by two length
///          bytes.  These bytes are redundant in the case of RSA because the
///          EncryptedPreMasterSecret is the only data in the ClientKeyExchange
///          and its length can therefore be unambiguously determined.  The SSLv3
///          specification was not clear about the encoding of public-key-
///          encrypted data, and therefore many SSLv3 implementations do not
///          include the length bytes -- they encode the RSA-encrypted data
///          directly in the ClientKeyExchange message.
///       
///          This specification requires correct encoding of the
///          EncryptedPreMasterSecret complete with length bytes.  The resulting
///          PDU is incompatible with many SSLv3 implementations.  Implementors
///          upgrading from SSLv3 MUST modify their implementations to generate
///          and accept the correct encoding.  Implementors who wish to be
///          compatible with both SSLv3 and TLS should make their implementation's
///          behavior dependent on the protocol version.
///          
///          Implementation note: It is now known that remote timing-based attacks
///          on TLS are possible, at least when the client and server are on the
///          same LAN.  Accordingly, implementations that use static RSA keys MUST
///          use RSA blinding or some other anti-timing technique, as described in
///          [TIMING].
/// 
///////////////////////////////////////////////////////////////////////
#ifndef XOS_PROTOCOL_TLS_ENCRYPTED_PREMASTER_SECRET_HPP
#define XOS_PROTOCOL_TLS_ENCRYPTED_PREMASTER_SECRET_HPP

#include "xos/protocol/tls/message/part.hpp"
#include "xos/protocol/tls/pkcs1/encoded/premaster/secret.hpp"
#include "xos/protocol/tls/rsa/key.hpp"

namespace xos {
namespace protocol {
namespace tls {
namespace encrypted {
namespace premaster {

/// class secrett
template 
<class TRsaKey = tls::rsa::key, 
 class TEncodedPremasterSecret = tls::pkcs1::encoded::premaster::secret,
 class TMessagePart = tls::message::part, class TExtends = TMessagePart, class TImplements = typename TExtends::implements>

class exported secrett: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef secrett derives; 
    
    typedef TRsaKey rsa_key_t;
    typedef TEncodedPremasterSecret encoded_premaster_secret_t;
    
    /// constructors / destructor
    secrett(const secrett& copy): extends(copy) {
    }
    secrett(rsa_key_t& rsa_key, const encoded_premaster_secret_t& encoded_premaster_secret) {
        combine(rsa_key, encoded_premaster_secret);
    }
    secrett() {
    }
    virtual ~secrett() {
    }

    /// combine / separate
    virtual bool combine(rsa_key_t& rsa_key, const encoded_premaster_secret_t& encoded_premaster_secret) {
        bool success = false;
        const byte_t* secret_bytes = 0; size_t secret_length = 0;

        if ((secret_bytes = encoded_premaster_secret.has_elements(secret_length)) 
            && (secret_length == rsa_key.modulus_size())) {
            byte_t* bytes = 0; size_t length = 0;

            this->set_length(secret_length);
            if ((bytes = this->has_elements(length)) && (length == secret_length)) {
                if (length == (rsa_key(bytes, length, secret_bytes, secret_length))) {
                    success = true;
                }
            }
        }
        return success;
    }
    virtual bool separate(size_t& count, rsa_key_t& rsa_key, const byte_t *bytes, size_t length) {
        bool success = false;
        size_t size = rsa_key.modulus_size();
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

}; /// class secrett
typedef secrett<> secret;

} /// namespace premaster
} /// namespace encrypted
} /// namespace tls
} /// namespace protocol
} /// namespace xos

#endif /// XOS_PROTOCOL_TLS_ENCRYPTED_PREMASTER_SECRET_HPP
