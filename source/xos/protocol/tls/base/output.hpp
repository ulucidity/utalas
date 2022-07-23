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
///   File: output.hpp
///
/// Author: $author$
///   Date: 2/27/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_PROTOCOL_TLS_BASE_OUTPUT_HPP
#define XOS_PROTOCOL_TLS_BASE_OUTPUT_HPP

#include "talas/crypto/output.hpp"

namespace xos {
namespace protocol {
namespace tls {
namespace base {

/// class outputt
template 
<class TOutput = talas::crypto::output, 
 class TExtends = TOutput, class TImplements = typename TExtends::implements>

class exported outputt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef outputt derives; 
    
    /// constructors / destructor
    outputt(const outputt& copy): extends(copy) {
    }
    outputt() {
    }
    virtual ~outputt() {
    }

}; /// class outputt
typedef outputt<> output;

} /// namespace base
} /// namespace tls
} /// namespace protocol
} /// namespace xos

#endif /// XOS_PROTOCOL_TLS_BASE_OUTPUT_HPP
