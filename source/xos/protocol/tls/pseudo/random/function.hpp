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
///   File: function.hpp
///
/// Author: $author$
///   Date: 5/19/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_PROTOCOL_TLS_PSEUDO_RANDOM_FUNCTION_HPP
#define XOS_PROTOCOL_TLS_PSEUDO_RANDOM_FUNCTION_HPP

#include "xos/protocol/tls/array.hpp"
#include "xos/crypto/hash/implemented.hpp"

namespace xos {
namespace protocol {
namespace tls {
namespace pseudo {
namespace random {

/// class functiont
template 
<class THash = xos::crypto::hash::implemented::sha256, 
 class TByteArray = xos::protocol::tls::byte_array_t, 
 class TExtends = extend, class TImplements = implement>

class exported functiont: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef functiont derives; 
    
    typedef THash hash_t;
    typedef TByteArray byte_array_t;
    
    /// constructors / destructor
    functiont(const functiont& copy)
    : secret_(copy.secret()), seed_(copy.seed()), iterate_begin_(0) {
    }
    functiont
    (const byte_array_t& secret, const byte_array_t& seed, const byte_array_t& A)
    : secret_(secret), seed_(seed), A_(A), iterate_begin_(&derives::iterate_begin_A) {
    }
    functiont
    (const byte_array_t& secret, const byte_array_t& seed)
    : secret_(secret), seed_(seed), iterate_begin_(0) {
    }
    functiont(): iterate_begin_(0) {
    }
    virtual ~functiont() {
    }

    /// iterate...
    virtual const byte_t* iterate(size_t& length) {
        hash_t& hash = this->hash();
        byte_array_t& block = this->block();
        size_t hash_size = hash.hash_size();
        byte_t* block_bytes = 0; size_t block_size = 0;

        if (hash_size <= (block_size = block.set_size(hash_size))) {
            
            if ((block_bytes = block.elements())) {
                const byte_array_t& secret = this->secret();
                const byte_t* key = 0; size_t keylen = 0;
        
                if ((key = secret.has_elements(keylen))) {
        
                    if ((0 <= hash.initialize(key, keylen))) {
                        const byte_array_t& seed = this->seed();
                        const byte_t* seedbytes = 0; size_t seedlen = 0;
                        
                        if ((seedbytes = seed.has_elements(seedlen))) {
                            byte_array_t& A = this->A();
                            const byte_t* Abytes = 0; size_t Alen = 0;
                            
                            if ((Abytes = A.has_elements(Alen))) {
                                
                                LOGGER_LOG_INFO("HMAC_hash(secret, A(i) + seed)...");
                                if (Alen <= (hash.hash(Abytes, Alen))) {
                                    
                                    if (hash_size <= (hash.finalize(block_bytes, block_size))) {

                                        ///
                                        /// A(i+1) = HMAC_hash(secret, A(i))
                                        /// 
                                        A.assign(block_bytes, hash_size);
                                        if ((0 <= hash.initialize(key, keylen))) {

                                            if (Alen <= (hash.hash(Abytes, Alen))) {

                                                if (seedlen <= (hash.hash(seedbytes, seedlen))) {
                                                    
                                                    ///
                                                    /// HMAC_hash(secret, A(i) + seed)
                                                    /// 
                                                    LOGGER_LOG_INFO("...HMAC_hash(secret, A(i) + seed)");
                                                    if (hash_size <= (hash.finalize(block_bytes, block_size))) {
                                                        length = hash_size;
                                                        return block_bytes;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            } else {
                                LOGGER_LOG_INFO("HMAC_hash(secret, A(0) + seed)...");
                                if (seedlen <= (hash.hash(seedbytes, seedlen))) {
                                    
                                    if (hash_size <= (hash.finalize(block_bytes, block_size))) {

                                        ///
                                        /// A(0) = seed
                                        /// A(1) = HMAC_hash(secret, A(0))
                                        /// 
                                        A.assign(block_bytes, hash_size);
                                        if ((0 <= hash.initialize(key, keylen))) {
                                            
                                            if (seedlen <= (hash.hash(seedbytes, seedlen))) {
                                                
                                                if (seedlen <= (hash.hash(seedbytes, seedlen))) {
                                                    
                                                    ///
                                                    /// HMAC_hash(secret, A(0) + seed)
                                                    /// 
                                                    LOGGER_LOG_INFO("...HMAC_hash(secret, A(0) + seed)");
                                                    if (hash_size <= (hash.finalize(block_bytes, block_size))) {
                                                        length = hash_size;
                                                        return block_bytes;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        return 0;
    }
    const byte_t* (derives::*iterate_begin_)(size_t& length);
    virtual const byte_t* iterate_begin(size_t& length) {
        const byte_t* bytes = 0;
        if ((iterate_begin_)) {
            bytes = (this->*iterate_begin_)(length);
        } else {
            bytes = iterate_begin_A0(length);
        }
        return bytes;
    }
    virtual const byte_t* iterate_begin_A(size_t& length) {
        const byte_t* bytes = 0;
        bytes = iterate(length);
        return bytes;
    }
    virtual const byte_t* iterate_begin_A0(size_t& length) {
        byte_array_t& A = this->A();
        const byte_t* bytes = 0;
        A.set_length(0);
        bytes = iterate(length);
        return bytes;
    }
    virtual const byte_t* iterate_end(size_t& length) {
        byte_array_t& A = this->A();
        const byte_t* bytes = 0;
        A.set_length(0);
        return bytes;
    }

    /// ...secret
    virtual byte_array_t& set_secret(const byte_array_t& to) {
        const byte_t* bytes = 0; size_t length = 0;
        if ((bytes = to.has_elements(length))) {
            secret_.assign(bytes, length);
        }
        return (byte_array_t&)secret_;
    }
    virtual byte_array_t& secret() const {
        return (byte_array_t&)secret_;
    }

    /// ...seed
    virtual byte_array_t& set_seed(const byte_array_t& to) {
        const byte_t* bytes = 0; size_t length = 0;
        if ((bytes = to.has_elements(length))) {
            seed_.assign(bytes, length);
        }
        return (byte_array_t&)seed_;
    }
    virtual byte_array_t& seed() const {
        return (byte_array_t&)seed_;
    }

    /// ...A
    virtual byte_array_t& set_A(const byte_array_t& to) {
        const byte_t* bytes = 0; size_t length = 0;
        if ((bytes = to.has_elements(length))) {
            A_.assign(bytes, length);
        }
        return (byte_array_t&)A_;
    }
    virtual byte_array_t& A() const {
        return (byte_array_t&)A_;
    }

    /// block
    virtual byte_array_t& block() const {
        return (byte_array_t&)block_;
    }

    /// hash
    virtual hash_t& hash() const {
        return (hash_t&)hash_;
    }

protected:
    byte_array_t secret_, seed_, A_, block_;
    hash_t hash_;
}; /// class functiont
typedef functiont<> function;

} /// namespace random
} /// namespace pseudo
} /// namespace tls
} /// namespace protocol
} /// namespace xos

#endif /// ndef XOS_PROTOCOL_TLS_PSEUDO_RANDOM_FUNCTION_HPP
