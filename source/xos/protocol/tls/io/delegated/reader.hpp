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
///   File: reader.hpp
///
/// Author: $author$
///   Date: 5/2/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_PROTOCOL_TLS_IO_DELEGATED_READER_HPP
#define XOS_PROTOCOL_TLS_IO_DELEGATED_READER_HPP

#include "xos/protocol/tls/io/reader.hpp"

namespace xos {
namespace protocol {
namespace tls {
namespace io {
namespace delegated {

/// class reader_eventst
template 
<class TReader = tls::io::reader, class TImplements = xos::implement>

class exported reader_eventst: virtual public TImplements {
public:
    typedef TImplements Implements, implements;

    typedef TReader reader_t;
    typedef typename reader_t::what_t what_t;
    typedef typename reader_t::sized_t sized_t;

    /// constructors / destructor
    virtual ~reader_eventst() {
    }

    /// on_read
    virtual ssize_t on_read(what_t* what, size_t size) {
        return size;
    }

}; /// class reader_eventst
typedef reader_eventst<> reader_events;

/// class readert
template 
<class TReader = tls::io::reader, 
 class TReaderEvents = reader_eventst<TReader>, 
 class TImplements = TReader, class TExtends = extend>

class exported readert: virtual public TReaderEvents, virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements, implements;
    typedef TExtends Extends, extends;
    typedef readert Derives, derives; 
    
    typedef TReader reader_t;
    typedef TReaderEvents reader_events_t;
    typedef typename Implements::what_t what_t;
    typedef typename Implements::sized_t sized_t;

    /// constructors / destructor
    readert(reader_events_t& reader_events, reader_t& reader)
    : reader_(reader), reader_events_(reader_events) {
    }
    readert(reader_t& reader): reader_(reader), reader_events_(*this) {
    }
    readert(const readert& copy)
    : reader_(copy.reader_), reader_events_(copy.reader_events_) {
    }
    virtual ~readert() {
    }

    /// read / fill
    using Implements::read;
    virtual ssize_t read() {
        ssize_t count = 0, amount = 0;
        sized_t sized = (sized_t)(0);
        while (0 != (amount = this->read(&sized, 1))) {
            if (0 > (amount)) {
                return amount;
            }
            count += amount;
        }
        return count;
    }
    virtual ssize_t read(what_t* what, size_t size) {
        ssize_t count = 0;
        if (0 < (count = reader_.read(what, size))) {
            count = this->on_read(what, size);
        }
        return count;
    }
    virtual ssize_t fill() {
        ssize_t count = 0;
        return count;
    }

    /// seek / tell / eof
    virtual ssize_t seek(ssize_t offset, int whence) {
        ssize_t count = 0;
        return count;
    }
    virtual ssize_t tell() {
        ssize_t count = 0;
        return count;
    }
    virtual ssize_t eof() {
        ssize_t count = 0;
        return count;
    }

    /// on_read
    virtual ssize_t on_read(what_t* what, size_t size) {
        if (&reader_events_ != this) {
            return reader_events_.on_read(what, size);
        }
        return size;
    }

protected:
    reader_t& reader_;
    reader_events_t& reader_events_;
}; /// class readert
typedef readert<> reader;

} /// namespace delegated
} /// namespace io
} /// namespace tls
} /// namespace protocol
} /// namespace xos

#endif /// ndef XOS_PROTOCOL_TLS_IO_DELEGATED_READER_HPP
