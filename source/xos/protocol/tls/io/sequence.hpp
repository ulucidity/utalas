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
///   File: sequence.hpp
///
/// Author: $author$
///   Date: 5/1/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_PROTOCOL_TLS_IO_SEQUENCE_HPP
#define XOS_PROTOCOL_TLS_IO_SEQUENCE_HPP

#include "xos/io/sequence.hpp"

namespace xos {
namespace protocol {
namespace tls {
namespace io {

typedef xos::io::sequencet<byte_t, byte_t> byte_sequence;
typedef xos::io::sequencet<word_t, word_t> word_sequence;

///  Class: sequencet
template 
<typename TWhat = char, typename TSized = TWhat, typename TEndof = TSized, TEndof VEndof = 0,
 class TImplements = xos::io::char_sequencet<TSized, xos::io::sequencet<TWhat, TSized, TEndof, VEndof> > >

class exported sequencet: virtual public TImplements {
public:
    typedef TImplements implements, Implements;
    
    typedef typename implements::what_t what_t;
    typedef typename implements::sized_t sized_t;
    typedef typename implements::sized_t char_t;
    typedef typename implements::endof_t endof_t;
    static const endof_t endof = implements::endof;
    
};
typedef sequencet<> sequence;

typedef sequencet<char> char_sequence;
typedef sequencet<tchar_t> tchar_sequence;
typedef sequencet<wchar_t> wchar_sequence;

} /// namespace io
} /// namespace tls
} /// namespace protocol
} /// namespace xos

#endif /// ndef XOS_PROTOCOL_TLS_IO_SEQUENCE_HPP
