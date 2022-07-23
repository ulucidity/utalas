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
///   File: parameters.hpp
///
/// Author: $author$
///   Date: 3/11/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_PROTOCOL_TLS_SECURITY_PARAMETERS_HPP
#define XOS_PROTOCOL_TLS_SECURITY_PARAMETERS_HPP

#include "xos/protocol/tls/message/part.hpp"
#include "xos/protocol/tls/uinteger.hpp"
#include "xos/protocol/tls/cipher/type.hpp"
#include "xos/protocol/tls/compression/method.hpp"
#include "xos/protocol/tls/connection/end.hpp"
#include "xos/protocol/tls/hello/random.hpp"
#include "xos/protocol/tls/master/secret.hpp"
#include "xos/protocol/tls/prf/algorithm.hpp"
#include "xos/protocol/tls/mac/algorithm.hpp"
#include "xos/protocol/tls/bulk/cipher/algorithm.hpp"

namespace xos {
namespace protocol {
namespace tls {
namespace security {

/// class parameterst
template 
<class TConnectionEnd = tls::connection::end, 
 class TPRFAlgorithm = tls::prf::algorithm, 
 class TBulkCipherAlgorithm = tls::bulk::cipher::algorithm, 
 class TCipherType = tls::cipher::type,
 class TMACAlgorithm = tls::mac::algorithm,
 class TCompressionMethod = tls::compression::method,
 class TMasterSecret = tls::master::secret,
 class THelloRandom = tls::hello::random,
 class TLength = tls::uintegert<uint8_t>,
 class TMessagePart = tls::message::part, class TExtends = TMessagePart, class TImplements = typename TExtends::implements>

class exported parameterst: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef parameterst derives; 
    
    typedef TConnectionEnd connection_end_t;
    typedef TPRFAlgorithm prf_algorithm_t;
    typedef TBulkCipherAlgorithm bulk_cipher_algorithm_t;
    typedef typename bulk_cipher_algorithm_t::which_t bulk_cipher_algorithm_which_t;
    typedef TCipherType cipher_type_t;
    typedef TMACAlgorithm mac_algorithm_t;
    typedef typename mac_algorithm_t::which_t mac_algorithm_which_t;
    typedef TCompressionMethod compression_method_t;
    typedef TMasterSecret master_secret_t;
    typedef THelloRandom hello_random_t;
    typedef TLength length_t;
    typedef typename length_t::value_t length_value_t;
    
    /// constructors / destructor
    parameterst(const parameterst& copy): extends(copy) {
    }
    parameterst
    (const uint8_t& record_iv_length, 
     const uint8_t& mac_length, const uint8_t& mac_key_length)
    : record_iv_length_(record_iv_length), 
      mac_length_(mac_length), mac_key_length_(mac_key_length) {
    }
    parameterst() {
    }
    virtual ~parameterst() {
    }

    /// ...
    virtual const length_t& record_iv_length() const {
        return record_iv_length_;
    }
    virtual length_value_t set_record_iv_length_value(const length_value_t& to) {
        record_iv_length_.set_value(to);
        return record_iv_length_.value();
    }
    virtual length_value_t record_iv_length_value() const {
        return record_iv_length_.value();
    }

protected:
    connection_end_t entity_;
    prf_algorithm_t prf_algorithm_;
    bulk_cipher_algorithm_t bulk_cipher_algorithm_;
    cipher_type_t cipher_type_;
    length_t enc_key_length_, block_length_, fixed_iv_length_, record_iv_length_;
    mac_algorithm_t mac_algorithm_;
    length_t mac_length_, mac_key_length_;
    compression_method_t compression_algorithm_;
    master_secret_t master_secret_;
    hello_random_t client_random_, server_random_;
}; /// class parameterst
typedef parameterst<> parameters;

} /// namespace security
} /// namespace tls
} /// namespace protocol
} /// namespace xos

#endif /// XOS_PROTOCOL_TLS_SECURITY_PARAMETERS_HPP
