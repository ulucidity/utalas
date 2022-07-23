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
///   Date: 6/1/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_PROTOCOL_TLS_CRYPTO_OUTPUT_HPP
#define XOS_PROTOCOL_TLS_CRYPTO_OUTPUT_HPP

#include "xos/io/console/output.hpp"

#include "xos/io/file/reader.hpp"
#include "xos/io/string/reader.hpp"

#include "xos/io/hex/reader.hpp"
#include "xos/io/hex/read_to_array.hpp"
#include "xos/io/hex/read_to_arrays.hpp"

#include "xos/protocol/tls/array.hpp"

namespace xos {
namespace protocol {
namespace tls {
namespace crypto {

/// class outputt
template 
<class TLiteralString = xos::base::string, 
 class TByteArray = xos::protocol::tls::byte_array_t, 
 class TByteArrays = xos::protocol::tls::byte_arrays_t,
 class TCharFileReader = xos::io::file::reader,
 class TStringCharReader = xos::io::string::reader,
 class THexCharReader = xos::io::hex::reader,
 class THexReadToByteArray = xos::io::hex::read_to_arrayt<TByteArray>,
 class THexReadToByteArrays = xos::io::hex::read_to_arrayst<TByteArrays, TByteArray>,
 class TForwardedOutput = io::console::output, 
 class TExtendsOutput = io::forwarded::outputt<TForwardedOutput>, 
 class TExtends = TExtendsOutput, class TImplements = typename TExtends::implements>

class exported outputt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef outputt derives; 
    
    typedef TLiteralString literal_string_t;
    typedef TByteArray byte_array_t;
    typedef TByteArrays byte_arrays_t;
    typedef THexReadToByteArray hex_read_to_byte_array_t;
    typedef THexReadToByteArrays hex_read_to_byte_arrays_t;
    typedef TCharFileReader file_char_reader_t;
    typedef TStringCharReader string_char_reader_t;
    typedef THexCharReader hex_char_reader_t;

    typedef typename extends::char_t char_t;
    typedef typename extends::end_char_t end_char_t;
    enum { end_char = extends::end_char };
    typedef typename extends::string_t string_t;
    typedef typename extends::file_t file_t;
    typedef typename extends::output_to_t output_to_t;

    typedef char_t what_t;
    typedef char_t sized_t;

    /// constructors / destructor
    outputt(const outputt& copy) {
    }
    outputt() {
    }
    virtual ~outputt() {
    }

    /// on_set_text_..._literal
    int (derives::*on_set_text_literal_)(byte_array_t &array, literal_string_t &literal);
    virtual int on_set_text_literal(byte_array_t &array, literal_string_t &literal) {
        int err = 0;
        if (on_set_text_literal_) {
            err = (this->*on_set_text_literal_)(array, literal);
        } else {
            err = default_on_set_text_literal(array, literal);
        }
        return err;
    }
    virtual int default_on_set_text_literal(byte_array_t &array, literal_string_t &literal) {
        int err = 0;
        err = on_set_text_string_literal(array, literal);
        return err;
    }
    virtual int on_set_text_string_literal
    (byte_array_t &array, literal_string_t &literal) {
        int err = 0;
        const byte_t* bytes = 0; const char_t* chars = 0; size_t length = 0;
        if ((bytes = (const byte_t*)(chars = literal.has_chars(length)))) {
            array.assign(bytes, length);
        }
        return err;
    }
    virtual int on_set_text_file_literal
    (byte_array_t &array, literal_string_t &literal) {
        int err = 0;
        size_t length = 0;
        const char_t* chars = 0;

        if ((chars = literal.has_chars(length))) {
            file_char_reader_t file;

            this->errlln("file.open(\"", chars, "\")...", null);
            if ((file.open(chars))) {
                typename file_char_reader_t::char_t c = 0;
                byte_t b = 0;
                ssize_t count = 0;
    
                array.set_length(0);
                while (0 < (count = file.read(&c, 1))) {
                    b = (byte_t)c;
                    array.append(&b, 1);
                }
                this->errlln("...file.close(\"", chars, "\")...", null);
                file.close();
            }
        }
        return err;
    }
    virtual int set_on_set_text_string_literal() {
        int err = 0;
        on_set_text_literal_ = &derives::on_set_text_string_literal;
        return err;
    }
    virtual int set_on_set_text_file_literal() {
        int err = 0;
        on_set_text_literal_ = &derives::on_set_text_file_literal;
        return err;
    }
    virtual int unset_on_set_text_file_literal() {
        int err = 0;
        on_set_text_literal_ = 0;
        return err;
    }

    /// on_set_hex_..._literal
    int (derives::*on_set_hex_literal_)(byte_array_t &array, literal_string_t &literal);
    virtual int on_set_hex_literal(byte_array_t &array, literal_string_t &literal) {
        int err = 0;
        if (on_set_hex_literal_) {
            err = (this->*on_set_hex_literal_)(array, literal);
        } else {
            err = default_on_set_hex_literal(array, literal);
        }
        return err;
    }
    virtual int default_on_set_hex_literal(byte_array_t &array, literal_string_t &literal) {
        int err = 0;
        err = on_set_hex_string_literal(array, literal);
        return err;
    }
    virtual int on_set_hex_string_literal
    (byte_array_t &array, literal_string_t &literal) {
        int err = 0;
        hex_read_to_byte_arrays_t to_arrays(&array, null);
        err = on_set_hex_string_literals(to_arrays, literal);
        return err;
    }
    virtual int on_set_hex_file_literal
    (byte_array_t &array, literal_string_t &literal) {
        int err = 0;
        hex_read_to_byte_arrays_t to_arrays(&array, null);
        err = on_set_hex_file_literals(to_arrays, literal);
        return err;
    }
    virtual int set_on_set_hex_string_literal() {
        int err = 0;
        on_set_hex_literal_ = &derives::on_set_hex_string_literal;
        return err;
    }
    virtual int set_on_set_hex_file_literal() {
        int err = 0;
        on_set_hex_literal_ = &derives::on_set_hex_file_literal;
        return err;
    }
    virtual int unset_on_set_hex_file_literal() {
        int err = 0;
        on_set_hex_literal_ = 0;
        return err;
    }

    /// on_set_hex_..._literal_array
    int (derives::*on_set_hex_literal_array_)(byte_arrays_t &arrays, literal_string_t &literal);
    virtual int on_set_hex_literal_array(byte_arrays_t &arrays, literal_string_t &literal) {
        int err = 0;
        if (on_set_hex_literal_array_) {
            err = (this->*on_set_hex_literal_array_)(arrays, literal);
        } else {
            err = default_on_set_hex_literal_array(arrays, literal);
        }
        return err;
    }
    virtual int default_on_set_hex_literal_array(byte_arrays_t &arrays, literal_string_t &literal) {
        int err = 0;
        err = on_set_hex_string_literal_array(arrays, literal);
        return err;
    }
    virtual int on_set_hex_string_literal_array
    (byte_arrays_t &arrays, literal_string_t &literal) {
        int err = 0;
        size_t length = 0;
        const char_t* chars = 0;

        if ((chars = literal.has_chars(length))) {
            ssize_t count = 0;
            string_char_reader_t reader(literal);
            hex_read_to_byte_arrays_t to_arrays(arrays);
            hex_char_reader_t hex(to_arrays, reader);

            if (0 >= (count = hex.read())) {
                err = on_failed_set_hex_literal_array(arrays, literal);
            }
        }
        return err;
    }
    virtual int on_set_hex_file_literal_array
    (byte_arrays_t &arrays, literal_string_t &literal) {
        int err = 0;
        size_t length = 0;
        const char_t* chars = 0;

        if ((chars = literal.has_chars(length))) {
            file_char_reader_t file;

            this->errlln("file.open(\"", chars, "\")...", null);
            if ((file.open(chars))) {
                ssize_t count = 0;
                hex_read_to_byte_arrays_t to_arrays(arrays);
                hex_char_reader_t hex(to_arrays, file);
    
                if (0 >= (count = hex.read())) {
                    err = on_failed_set_hex_literal_array(arrays, literal);
                }
                this->errlln("...file.close(\"", chars, "\")...", null);
                file.close();
            }
        }
        return err;
    }
    virtual int on_failed_set_hex_literal_array(byte_arrays_t &arrays, literal_string_t &literal) {
        int err = 0;
        return err;
    }
    virtual int set_on_set_hex_string_literal_array() {
        int err = 0;
        on_set_hex_literal_array_ = &derives::on_set_hex_string_literal_array;
        return err;
    }
    virtual int set_on_set_hex_file_literal_array() {
        int err = 0;
        on_set_hex_literal_array_ = &derives::on_set_hex_file_literal_array;
        return err;
    }
    virtual int unset_on_set_hex_file_literal_array() {
        int err = 0;
        on_set_hex_literal_array_ = 0;
        return err;
    }

    /// ...on_set_hex_literals
    int (derives::*on_set_hex_literals_)
    (hex_read_to_byte_arrays_t &to_arrays, literal_string_t &literal);
    virtual int on_set_hex_literals
    (hex_read_to_byte_arrays_t &to_arrays, literal_string_t &literal) {
        int err = 0;
        if (on_set_hex_literals_) {
            err = (this->*on_set_hex_literals_)(to_arrays, literal);
        } else {
            err = default_on_set_hex_literals(to_arrays, literal);
        }
        return err;
    }
    virtual int default_on_set_hex_literals
    (hex_read_to_byte_arrays_t &to_arrays, literal_string_t &literal) {
        int err = 0;
        err = on_set_hex_string_literals(to_arrays, literal);
        return err;
    }
    virtual int on_set_hex_string_literals
    (hex_read_to_byte_arrays_t &to_arrays, literal_string_t &literal) {
        int err = 0;
        size_t length = 0;
        const char_t* chars = 0;

        if ((chars = literal.has_chars(length))) {
            ssize_t count = 0;
            string_char_reader_t reader(literal);
            hex_char_reader_t hex(to_arrays, reader);

            if (0 >= (count = hex.read())) {
                err = on_failed_set_hex_literals(to_arrays, literal);
            }
        }
        return err;
    }
    virtual int on_set_hex_file_literals
    (hex_read_to_byte_arrays_t &to_arrays, literal_string_t &literal) {
        int err = 0;
        size_t length = 0;
        const char_t* chars = 0;

        if ((chars = literal.has_chars(length))) {
            file_char_reader_t file;

            this->errlln("file.open(\"", chars, "\")...", null);
            if ((file.open(chars))) {
                ssize_t count = 0;
                hex_char_reader_t hex(to_arrays, file);
    
                if (0 >= (count = hex.read())) {
                    this->errln("...failed on (0 < (count = hex.read()))");
                    err = on_failed_set_hex_literals(to_arrays, literal);
                }
                this->errlln("...file.close(\"", chars, "\")...", null);
                file.close();
            } else {
                this->errlln("...failed on file.open(\"", chars, "\")...", null);
                err = 1;
            }
        } else {
            this->errln("...failed on ((chars = literal.has_chars(length)))");
            err = 1;
        }
        return err;
    }
    virtual int on_failed_set_hex_literals
    (hex_read_to_byte_arrays_t &to_arrays, literal_string_t &literal) {
        int err = 0;
        size_t length = 0;
        typename hex_read_to_byte_arrays_t::arrays_t &arrays = to_arrays.arrays();
        typename hex_read_to_byte_arrays_t::array_pointer_t *array_pointers = 0;

        if ((array_pointers = arrays.elements(length))) {
            typename hex_read_to_byte_arrays_t::array_pointer_t array_pointer = 0;

            for (array_pointer = *array_pointers; length; --length, ++array_pointers) {
                if ((array_pointer)) {
                    array_pointer->set_length(0);
                }
            }
        }
        err = 1;
        return err;
    }
    virtual int set_on_set_hex_string_literals() {
        int err = 0;
        on_set_hex_literals_ = &derives::on_set_hex_string_literals;
        return err;
    }
    virtual int set_on_set_hex_file_literals() {
        int err = 0;
        on_set_hex_literals_ = &derives::on_set_hex_file_literals;
        return err;
    }
    virtual int unset_on_set_hex_file_literals() {
        int err = 0;
        on_set_hex_literals_ = 0;
        return err;
    }

    /// on_set_hex_literals
    virtual int on_set_hex_literals
    (byte_array_t &a1, byte_array_t &a2, literal_string_t &literal) {
        int err = 0;
        hex_read_to_byte_arrays_t to_arrays(&a1, &a2, null);
        err = on_set_hex_literals(to_arrays, literal);
        return err;
    }
    virtual int on_set_hex_literals
    (byte_array_t &a1, byte_array_t &a2, 
     byte_array_t &a3, literal_string_t &literal) {
        int err = 0;
        hex_read_to_byte_arrays_t to_arrays(&a1, &a2, &a3, null);
        err = on_set_hex_literals(to_arrays, literal);
        return err;
    }
    virtual int on_set_hex_literals
    (byte_array_t &a1, byte_array_t &a2, 
     byte_array_t &a3, byte_array_t &a4, literal_string_t &literal) {
        int err = 0;
        hex_read_to_byte_arrays_t to_arrays(&a1, &a2, &a3, &a4, null);
        err = on_set_hex_literals(to_arrays, literal);
        return err;
    }
    virtual int on_set_hex_literals
    (byte_array_t &a1, byte_array_t &a2, 
     byte_array_t &a3, byte_array_t &a4, 
     byte_array_t &a5, literal_string_t &literal) {
        int err = 0;
        hex_read_to_byte_arrays_t to_arrays(&a1, &a2, &a3, &a4, &a5, null);
        err = on_set_hex_literals(to_arrays, literal);
        return err;
    }
    virtual int on_set_hex_literals
    (byte_array_t &a1, byte_array_t &a2, 
     byte_array_t &a3, byte_array_t &a4, 
     byte_array_t &a5, byte_array_t &a6, literal_string_t &literal) {
        int err = 0;
        hex_read_to_byte_arrays_t to_arrays(&a1, &a2, &a3, &a4, &a5, &a6, null);
        err = on_set_hex_literals(to_arrays, literal);
        return err;
    }
    virtual int on_set_hex_literals
    (byte_array_t &a1, byte_array_t &a2, 
     byte_array_t &a3, byte_array_t &a4, 
     byte_array_t &a5, byte_array_t &a6, 
     byte_array_t &a7, literal_string_t &literal) {
        int err = 0;
        hex_read_to_byte_arrays_t to_arrays(&a1, &a2, &a3, &a4, &a5, &a6, &a7, null);
        err = on_set_hex_literals(to_arrays, literal);
        return err;
    }

    /// set_on_set...literals
    virtual int set_on_set_string_literals() {
        int err = 0;
        if (!(err = set_on_set_text_string_literal())) {
            if (!(err = set_on_set_hex_string_literal())) {
                if (!(err = set_on_set_hex_string_literals())) {
                    if (!(err = set_on_set_hex_string_literal_array())) {
                    }
                }
            }
        }
        return err;
    }
    virtual int set_on_set_file_literals() {
        int err = 0;
        if (!(err = set_on_set_text_file_literal())) {
            if (!(err = set_on_set_hex_file_literal())) {
                if (!(err = set_on_set_hex_file_literals())) {
                    if (!(err = set_on_set_hex_file_literal_array())) {
                    }
                }
            }
        }
        return err;
    }
    virtual int unset_on_set_file_literals() {
        int err = 0;
        if (!(err = unset_on_set_text_file_literal())) {
            if (!(err = unset_on_set_hex_file_literal())) {
                if (!(err = unset_on_set_hex_file_literals())) {
                    if (!(err = unset_on_set_hex_file_literal_array())) {
                    }
                }
            }
        }
        return err;
    }

    /// ...output_hex
    virtual ssize_t output_hex(const byte_array_t &array) {
        ssize_t count = 0;
        size_t length = 0;
        const byte_t *bytes = 0;
        
        if ((bytes = array.elements(length))) {
            count = this->output_x(bytes, length);
        }
        return count;
    }

    /// ...output_x...
    ssize_t (derives::*output_x_verbage_sized_)(const char_t* verbage, const void* out, size_t len);
    virtual ssize_t output_x_verbage_sized(const char_t* verbage, const void* out, size_t len) {
        ssize_t err = 0;
        if (output_x_verbage_sized_) {
            err = (this->*output_x_verbage_sized_)(verbage, out, len);
        } else {
            err = default_output_x_verbage_sized(verbage, out, len);
        }
        return err;
    }
    virtual ssize_t default_output_x_verbage_sized(const char_t* verbage, const void* out, size_t len) {
        ssize_t count = 0;
        if ((out) && (len)) {
            ssize_t amount = 0;
            bool verbose = this->verbose_output();
            if ((verbose) && (verbage) && (verbage[0])) {
                unsigned_to_string size(len);
                count += ((0 < (amount = this->out(verbage)))?(amount):(0));
                count += ((0 < (amount = this->out("[")))?(amount):(0));
                count += ((0 < (amount = this->out(size)))?(amount):(0));
                count += ((0 < (amount = this->outln("]:\\")))?(amount):(0));
            }
            count += ((0 < (amount = this->output_x(out, len)))?(amount):(0));
            if ((verbose) && (verbage) && (verbage[0])) {
                count += ((0 < (amount = this->outln()))?(amount):(0));
            }
        }
        return count;
    }
    ssize_t (derives::*output_x_)(const void* out, size_t len);
    virtual ssize_t output_x(const void* out, size_t len) {
        ssize_t count = 0;
        if (output_x_) {
            count = (this->*output_x_)(out, len);
        } else {
            count = default_output_x(out, len);
        }
        return count;
    }
    virtual ssize_t default_output_x(const void* out, size_t len) {
        ssize_t count = 0;
        const byte_t *bytes = 0;

        if ((bytes = ((const byte_t*)out)) && (len)) {
            size_t cols = 32, col = 0;
            ssize_t amount = 0;
            const char_t& nextln = this->nextln();

            for (col = 0; len; --len, ++bytes, ++col) {
                if (cols <= (col)) {
                    if (0 < (amount = this->outln(&nextln, 1))) {
                        count += amount;
                    }
                    col = 0;
                }
                if (0 < (amount = this->outx(bytes, 1))) {
                    count += amount;
                }
            }
            if (0 < (amount = this->outln())) {
                count += amount;
            }
        }
        return count;
    }

    /// nextln
    virtual const char_t& nextln() const {
        static const char_t nextln = (char_t)'\\';
        return nextln;
    }

protected:
}; /// class outputt
typedef outputt<> output;

} /// namespace crypto
} /// namespace tls
} /// namespace protocol
} /// namespace xos

#endif /// ndef XOS_PROTOCOL_TLS_CRYPTO_OUTPUT_HPP
