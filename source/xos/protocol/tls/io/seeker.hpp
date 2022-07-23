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
///   File: seeker.hpp
///
/// Author: $author$
///   Date: 5/2/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_PROTOCOL_TLS_IO_SEEKER_HPP
#define XOS_PROTOCOL_TLS_IO_SEEKER_HPP

#include "xos/protocol/tls/io/sequence.hpp"
#include "xos/io/seeker.hpp"

namespace xos {
namespace protocol {
namespace tls {
namespace io {

/// enum from_t
typedef xos::io::from_t from_t;
enum {
    from_begining = xos::io::from_begining,
    from_begin    = xos::io::from_begining,
    from_end      = xos::io::from_end,
    from_current  = xos::io::from_current
}; /// enum from_t

///  Class: seekert
template <class TImplements = sequence>
class exported seekert: virtual public TImplements {
public:
    typedef TImplements implements;

    typedef typename implements::what_t what_t;
    typedef typename implements::sized_t sized_t;
    typedef typename implements::endof_t endof_t;
    static const endof_t endof = implements::endof;

}; /// class seekert
typedef seekert<sequence> seeker;

typedef seekert<byte_sequence> byte_seeker;
typedef seekert<word_sequence> word_seeker;

typedef seekert<char_sequence> char_seeker;
typedef seekert<tchar_sequence> tchar_seeker;
typedef seekert<wchar_sequence> wchar_seeker;

} /// namespace io
} /// namespace tls
} /// namespace protocol
} /// namespace xos

#endif /// ndef XOS_PROTOCOL_TLS_IO_SEEKER_HPP
