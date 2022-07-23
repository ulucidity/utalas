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
///   Date: 3/12/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_PROTOCOL_TLS_MASTER_SECRET_HPP
#define XOS_PROTOCOL_TLS_MASTER_SECRET_HPP

#include "xos/protocol/tls/message/part.hpp"
#include "xos/protocol/tls/hello/random.hpp"
#include "xos/protocol/tls/premaster/secret/message.hpp"

namespace xos {
namespace protocol {
namespace tls {
namespace master {

/// class secrett
template 
<class THelloRandom = tls::hello::random, 
 class TPremasterSecret = tls::premaster::secret::message, 
 class TMasterSecretSeed = tls::message::part, 
 class TPseudoRandomReader = tls::pseudo::random::reader,
 class TMessagePart = tls::message::part, 
 class TExtends = TMessagePart, class TImplements = typename TExtends::implements>

class exported secrett: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef secrett derives; 
    
    typedef THelloRandom hello_random_t;
    typedef TPremasterSecret premaster_secret_t;
    typedef TMasterSecretSeed master_secret_seed_t;
    typedef TMessagePart message_part_t;
    typedef typename message_part_t::byte_array_t byte_array_t;
    typedef TPseudoRandomReader pseudo_random_reader_t;
    
    /// constructors / destructor
    secrett(const secrett& copy): extends(copy) {
    }
    secrett
    (const byte_array_t& premaster_secret, const byte_array_t& master_secret_seed,
     const byte_array_t& client_hello_random, const byte_array_t& server_hello_random) {
        combine(premaster_secret, master_secret_seed, client_hello_random, server_hello_random);
    }
    secrett() {
    }
    virtual ~secrett() {
    }

    /// combine / separate
    virtual bool combine
    (const byte_array_t& premaster_secret, const byte_array_t& master_secret_seed,
     const byte_array_t& client_hello_random, const byte_array_t& server_hello_random) {
        bool success = false;
        const byte_t* premaster_secret_bytes = 0; size_t premaster_secret_length = 0; 

        this->set_length(0);
        if ((premaster_secret_bytes = premaster_secret.has_elements(premaster_secret_length))) {
            byte_t* master_secret_seed_bytes = 0; size_t master_secret_seed_length = 0;
            
            if ((master_secret_seed_bytes = master_secret_seed.has_elements(master_secret_seed_length))) {
                const byte_t* client_hello_random_bytes = 0; size_t client_hello_random_length = 0;
                
                if ((client_hello_random_bytes = client_hello_random.has_elements(client_hello_random_length))) {
                    const byte_t* server_hello_random_bytes = 0; size_t server_hello_random_length = 0;
                    
                    if ((server_hello_random_bytes = server_hello_random.has_elements(server_hello_random_length))) {
                        message_part_t master_secret_A(client_hello_random);
                        const byte_t* master_secret_A_bytes = 0; size_t master_secret_A_length = 0; 
                        
                        master_secret_A.append(server_hello_random);
                        if ((master_secret_A_bytes = master_secret_A.has_elements(master_secret_A_length))) {
                            byte_t* master_secret_bytes = 0; size_t master_secret_length = 0; 
                            
                            this->set_length(48);
                            if ((master_secret_bytes = this->has_elements(master_secret_length))) {
                                pseudo_random_reader_t pseudo_random_reader(premaster_secret, master_secret_seed, master_secret_A);
                                
                                if (master_secret_length == (pseudo_random_reader.read(master_secret_bytes, master_secret_length))) {
                                    success = true;
                                }
                            }
                        }
                    }
                }
            }
        }
        return success;
    }
    virtual bool separate() {
        bool success = false;
        return success;
    }

}; /// class secrett
typedef secrett<> secret;

} /// namespace master
} /// namespace tls
} /// namespace protocol
} /// namespace xos

#endif /// XOS_PROTOCOL_TLS_MASTER_SECRET_HPP
