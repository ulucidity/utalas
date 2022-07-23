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
///   File: base.hpp
///
/// Author: $author$
///   Date: 5/2/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_PROTOCOL_TLS_BASE_HPP
#define XOS_PROTOCOL_TLS_BASE_HPP

#include "xos/base/base.hpp"
#include "xos/base/attached.hpp"
#include "xos/base/created.hpp"
#include "xos/base/opened.hpp"
#include "xos/protocol/tls/types.hpp"
#include "xos/protocol/tls/array.hpp"
#include "xos/protocol/tls/string.hpp"

namespace xos {
namespace protocol {
namespace tls {

typedef xos::base::implement_base implement_base;
typedef xos::base::base base;

typedef ::xos::base::create_exception create_exception;
static const create_exception create_failed = ::xos::base::create_failed;
static const create_exception destroy_failed = ::xos::base::destroy_failed;

typedef ::xos::base::open_exception open_exception;
static const open_exception open_failed = ::xos::base::open_failed;
static const open_exception close_failed = ::xos::base::close_failed;

typedef ::xos::base::creator_exception creator_exception;
static const creator_exception failed_to_create = ::xos::base::failed_to_create;
static const creator_exception failed_to_destroy = ::xos::base::failed_to_destroy;

typedef ::xos::base::opener_exception opener_exception;
static const opener_exception failed_to_open = ::xos::base::failed_to_open;
static const opener_exception failed_to_close = ::xos::base::failed_to_close;

} /// namespace tls
} /// namespace protocol
} /// namespace xos

#endif /// ndef XOS_PROTOCOL_TLS_BASE_HPP
