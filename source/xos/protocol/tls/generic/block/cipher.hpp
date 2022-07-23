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
///   File: cipher.hpp
///
/// Author: $author$
///   Date: 3/11/2022
/// 
/// For block ciphers (such as 3DES or AES), the encryption and MAC
/// functions convert TLSCompressed.fragment structures to and from block
/// TLSCiphertext.fragment structures.
/// 
/// struct {
///     opaque IV[SecurityParameters.record_iv_length];
///     block-ciphered struct {
///         opaque content[TLSCompressed.length];
///         opaque MAC[SecurityParameters.mac_length];
///         uint8 padding[GenericBlockCipher.padding_length];
///         uint8 padding_length;
///     };
/// } GenericBlockCipher;
/// 
/// IV
///    The Initialization Vector (IV) SHOULD be chosen at random, and
///    MUST be unpredictable.  Note that in versions of TLS prior to 1.1,
///    there was no IV field, and the last ciphertext block of the
///    previous record (the "CBC residue") was used as the IV.  This was
///    changed to prevent the attacks described in [CBCATT].  For block
///    ciphers, the IV length is of length
///    SecurityParameters.record_iv_length, which is equal to the
///    SecurityParameters.block_size.
/// 
/// padding
///    Padding that is added to force the length of the plaintext to be
///    an integral multiple of the block cipher's block length.  The
///    padding MAY be any length up to 255 bytes, as long as it results
///    in the TLSCiphertext.length being an integral multiple of the
///    block length.  Lengths longer than necessary might be desirable to
///    frustrate attacks on a protocol that are based on analysis of the
///    lengths of exchanged messages.  Each uint8 in the padding data
///    vector MUST be filled with the padding length value.  The receiver
///    MUST check this padding and MUST use the bad_record_mac alert to
///    indicate padding errors.
/// 
/// padding_length
///    The padding length MUST be such that the total size of the
///    GenericBlockCipher structure is a multiple of the cipher's block
///    length.  Legal values range from zero to 255, inclusive.  This
///    length specifies the length of the padding field exclusive of the
///    padding_length field itself.
/// 
/// The encrypted data length (TLSCiphertext.length) is one more than the
/// sum of SecurityParameters.block_length, TLSCompressed.length,
/// SecurityParameters.mac_length, and padding_length.
/// 
///////////////////////////////////////////////////////////////////////
#ifndef XOS_PROTOCOL_TLS_GENERIC_BLOCK_CIPHER_HPP
#define XOS_PROTOCOL_TLS_GENERIC_BLOCK_CIPHER_HPP

#include "xos/protocol/tls/message/part.hpp"
#include "xos/protocol/tls/security/parameters.hpp"
#include "xos/crypto/hash/algorithm.hpp"

namespace xos {
namespace protocol {
namespace tls {
namespace generic {
namespace block {

/// class ciphert
template 
<class TMACAlgorithm = xos::crypto::hash::algorithm, 
 class TOpaque = tls::message::part,
 class TPadding = tls::message::part,
 class TPaddingLength = tls::uintegert<uint8_t>,
 class TMessagePart = tls::message::part, 
 class TExtends = TMessagePart, class TImplements = typename TExtends::implements>

class exported ciphert: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef ciphert derives; 
    
    typedef TMACAlgorithm MAC_algorithm_t;
    typedef TOpaque opaque_t;
    typedef TPadding padding_t;
    typedef TPaddingLength padding_length_t;
    typedef typename padding_length_t::value_t padding_length_value_t;
    
    /// constructors / destructor
    ciphert(const ciphert& copy): extends(copy), MAC_algorithm_(this_MAC_algorithm_) {
    }
    ciphert(const opaque_t& IV, const opaque_t& content): MAC_algorithm_(this_MAC_algorithm_) {
        combine(IV, content);
    }
    ciphert(): MAC_algorithm_(this_MAC_algorithm_) {
    }
    virtual ~ciphert() {
    }

    /// combine / separate
    virtual bool combine(const opaque_t& IV, const opaque_t& content) {
        bool success = false;
        const byte_t* bytes = 0; size_t length = 0;
        
        this->set_length(0);
        if ((bytes = IV.has_elements(length))) {
            
            this->append(IV);
            if ((bytes = content.has_elements(length))) {
                const padding_length_value_t padding_length_value = 0;
                padding_length_t padding_length(padding_length_value);
                
                this->append(content);
                this->append(padding_length);
                success = true;
            } else {
                this->set_length(0);
            }
        }
        return success;
    }
    virtual bool separate(size_t& count, size_t IV_length, const byte_t *bytes, size_t length) {
        bool success = false;
        size_t padding_length_size_of = padding_length_t::size_of;
        
        if ((bytes) && ((IV_length + padding_length_size_of) < length)) {
            IV_.assign(bytes, IV_length);

            if (IV_length == (IV_.length())) {
                size_t content_length = 0;

                count += IV_length;
                bytes += IV_length;
                length -= IV_length;
                content_.assign(bytes, (content_length = (length - padding_length_size_of)));

                if (content_length == (content_.length())) {
                    size_t amount = 0;

                    count += content_length;
                    bytes += content_length;
                    length -= content_length;

                    if (padding_length_size_of == (padding_length_.separate(amount, bytes, length))) {
                        
                        count += length;
                        bytes += length;
                        length -= length;
                        success = true;
                    }
                }
            }
        }
        return success;
    }

    /// ...
    virtual opaque_t& IV() const {
        return (opaque_t&)IV_;
    }
    virtual opaque_t& content() const {
        return (opaque_t&)content_;
    }
    virtual padding_length_t& padding_length() const {
        return (padding_length_t&)padding_length_;
    }

protected:
    MAC_algorithm_t this_MAC_algorithm_, &MAC_algorithm_;
    opaque_t MAC_key_, IV_, content_;
    padding_length_t padding_length_;
}; /// class ciphert
typedef ciphert<> cipher;

} /// namespace block
} /// namespace generic
} /// namespace tls
} /// namespace protocol
} /// namespace xos

#endif /// XOS_PROTOCOL_TLS_GENERIC_BLOCK_CIPHER_HPP
