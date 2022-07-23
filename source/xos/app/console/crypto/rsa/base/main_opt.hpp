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
///   File: main_opt.hpp
///
/// Author: $author$
///   Date: 5/28/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_CRYPTO_RSA_BASE_MAIN_OPT_HPP
#define XOS_APP_CONSOLE_CRYPTO_RSA_BASE_MAIN_OPT_HPP

#include "xos/app/console/crypto/base/main.hpp"

#include "xos/io/hex/read_to_arrays.hpp"
#include "xos/io/hex/read_to_array.hpp"
#include "xos/io/crt/file/reader.hpp"

#include "xos/base/array.hpp"
#include "xos/crypto/array.hpp"

#define XOS_APP_CONSOLE_RSA_MODULUS_BITS 2048
#define XOS_APP_CONSOLE_RSA_MODULUS_BYTES 256

#define XOS_APP_CONSOLE_RSA_MODULUS_BITS_MIN 512
#define XOS_APP_CONSOLE_RSA_MODULUS_BITS_MAX 8192

#define XOS_APP_CONSOLE_RSA_MODULUS_BYTES_MIN 128
#define XOS_APP_CONSOLE_RSA_MODULUS_BYTES_MAX 1024

#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GENERATE_PRIME_OPT "random-prime"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GENERATE_PRIME_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GENERATE_PRIME_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GENERATE_PRIME_OPTARG ""
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GENERATE_PRIME_OPTUSE "generate random prime"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GENERATE_PRIME_OPTVAL_S "a"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GENERATE_PRIME_OPTVAL_C 'a'
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GENERATE_PRIME_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GENERATE_PRIME_OPT, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GENERATE_PRIME_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GENERATE_PRIME_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GENERATE_PRIME_OPTVAL_C}, \

#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MILLER_RABIN_OPT "miller-rabin"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MILLER_RABIN_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MILLER_RABIN_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MILLER_RABIN_OPTARG ""
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MILLER_RABIN_OPTUSE "do miller rabin primality test"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MILLER_RABIN_OPTVAL_S "m"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MILLER_RABIN_OPTVAL_C 'm'
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MILLER_RABIN_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MILLER_RABIN_OPT, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MILLER_RABIN_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MILLER_RABIN_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MILLER_RABIN_OPTVAL_C}, \

#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_FERMAT_WITNESS_OPT "fermat-witness"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_FERMAT_WITNESS_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_FERMAT_WITNESS_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_FERMAT_WITNESS_OPTARG ""
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_FERMAT_WITNESS_OPTUSE "do fermat witness primality test"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_FERMAT_WITNESS_OPTVAL_S "w"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_FERMAT_WITNESS_OPTVAL_C 'w'
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_FERMAT_WITNESS_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_FERMAT_WITNESS_OPT, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_FERMAT_WITNESS_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_FERMAT_WITNESS_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_FERMAT_WITNESS_OPTVAL_C}, \

#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BITS_OPT "modulus-bits"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BITS_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BITS_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BITS_OPTARG \
    "[" XOS_2CHARS(XOS_APP_CONSOLE_RSA_MODULUS_BITS_MIN) \
    ".." XOS_2CHARS(XOS_APP_CONSOLE_RSA_MODULUS_BITS_MAX) \
    " (" XOS_2CHARS(XOS_APP_CONSOLE_RSA_MODULUS_BITS) ")" "]"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BITS_OPTUSE "RSA modulus size in bits"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BITS_OPTVAL_S "i::"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BITS_OPTVAL_C 'i'
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BITS_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BITS_OPT, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BITS_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BITS_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BITS_OPTVAL_C}, \

#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BYTES_OPT "modulus-bytes"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BYTES_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BYTES_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BYTES_OPTARG \
    "[" XOS_2CHARS(XOS_APP_CONSOLE_RSA_MODULUS_BYTES_MIN) \
    ".." XOS_2CHARS(XOS_APP_CONSOLE_RSA_MODULUS_BYTES_MAX) \
    " (" XOS_2CHARS(XOS_APP_CONSOLE_RSA_MODULUS_BYTES) ")" "]"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BYTES_OPTUSE "RSA modulus size in bytes"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BYTES_OPTVAL_S "y::"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BYTES_OPTVAL_C 'y'
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BYTES_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BYTES_OPT, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BYTES_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BYTES_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BYTES_OPTVAL_C}, \

#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_BN_INTEGER_OPT "bn-integer"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_BN_INTEGER_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_BN_INTEGER_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_BN_INTEGER_OPTARG ""
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_BN_INTEGER_OPTUSE "use bn integer library"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_BN_INTEGER_OPTVAL_S "b"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_BN_INTEGER_OPTVAL_C 'b'
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_BN_INTEGER_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_BN_INTEGER_OPT, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_BN_INTEGER_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_BN_INTEGER_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_BN_INTEGER_OPTVAL_C}, \

#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GMP_INTEGER_OPT "gmp-integer"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GMP_INTEGER_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GMP_INTEGER_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GMP_INTEGER_OPTARG ""
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GMP_INTEGER_OPTUSE "use gmp integer library"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GMP_INTEGER_OPTVAL_S "g"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GMP_INTEGER_OPTVAL_C 'g'
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GMP_INTEGER_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GMP_INTEGER_OPT, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GMP_INTEGER_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GMP_INTEGER_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GMP_INTEGER_OPTVAL_C}, \

#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_VERBOSE_OPT "verbose"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_VERBOSE_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_VERBOSE_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_VERBOSE_OPTARG ""
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_VERBOSE_OPTUSE "verbose output"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_VERBOSE_OPTVAL_S "v"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_VERBOSE_OPTVAL_C 'v'
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_VERBOSE_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_VERBOSE_OPT, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_VERBOSE_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_VERBOSE_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_VERBOSE_OPTVAL_C}, \

#define XOS_APP_CONSOLE_CRYPTO_RSA_BASE_MAIN_OPTIONS_CHARS_EXTEND \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GENERATE_PRIME_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MILLER_RABIN_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_FERMAT_WITNESS_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BITS_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BYTES_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_BN_INTEGER_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GMP_INTEGER_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_0X_HEX_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_UPPER_HEX_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_LOWER_HEX_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_TEXT_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_VERBOSE_OPTVAL_S \

#define XOS_APP_CONSOLE_CRYPTO_RSA_BASE_MAIN_OPTIONS_OPTIONS_EXTEND \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GENERATE_PRIME_OPTION \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MILLER_RABIN_OPTION \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_FERMAT_WITNESS_OPTION \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BITS_OPTION \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BYTES_OPTION \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_BN_INTEGER_OPTION \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GMP_INTEGER_OPTION \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_0X_HEX_OPTION \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_UPPER_HEX_OPTION \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_LOWER_HEX_OPTION \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_TEXT_OPTION \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_VERBOSE_OPTION \

#define XOS_APP_CONSOLE_CRYPTO_RSA_BASE_MAIN_OPTIONS_CHARS \
   XOS_APP_CONSOLE_CRYPTO_RSA_BASE_MAIN_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_UCIFRA_MAIN_LOGGING_OPTIONS_CHARS

#define XOS_APP_CONSOLE_CRYPTO_RSA_BASE_MAIN_OPTIONS_OPTIONS \
   XOS_APP_CONSOLE_CRYPTO_RSA_BASE_MAIN_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_UCIFRA_MAIN_LOGGING_OPTIONS_OPTIONS

#define XOS_APP_CONSOLE_CRYPTO_RSA_BASE_MAIN_ARGS 0
#define XOS_APP_CONSOLE_CRYPTO_RSA_BASE_MAIN_ARGV 0,

namespace xos {
namespace app {
namespace console {
namespace crypto {
namespace rsa {
namespace base {

/// class main_optt
template 
<class TExtends = xos::app::console::crypto::base::main, 
 class TImplements = typename TExtends::implements>

class exported main_optt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef main_optt derives;

    typedef typename extends::char_t char_t;
    typedef typename extends::end_char_t end_char_t;
    enum { end_char = extends::end_char };
    typedef typename extends::string_t string_t;
    typedef typename extends::reader_t reader_t;
    typedef typename extends::writer_t writer_t;
    typedef typename extends::file_t file_t;

    /// constructor / destructor
    main_optt()
    : run_(0),
      generate_pseudo_random_prime_run_(0),
      miller_rabin_pseudo_random_prime_run_(0),
      pseudo_random_prime_run_(0),
      no_miller_rabin_test_(false), 
      const_0x_output_(false), verbose_output_(false),
      modulus_bits_(XOS_APP_CONSOLE_RSA_MODULUS_BITS) {
    }
    virtual ~main_optt() {
    }
private:
    main_optt(const main_optt& copy) {
        throw exception(exception_unexpected);
    }

protected:
    typedef typename extends::in_reader_t in_reader_t;
    typedef typename extends::out_writer_t out_writer_t;
    typedef typename extends::err_writer_t err_writer_t;

    typedef xos::byte_array byte_array_t;
    typedef xos::crypto::array crypto_array_t;

    /// ...run
    int (derives::*run_)(int argc, char_t** argv, char_t** env);
    virtual int run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((run_)) {
            err = (this->*run_)(argc, argv, env);
        } else {
            err = extends::run(argc, argv, env);
        }
        return err;
    }

    /// ...generate_pseudo_random_prime_run
    int (derives::*generate_pseudo_random_prime_run_)(int argc, char_t** argv, char_t** env);
    virtual int generate_pseudo_random_prime_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (generate_pseudo_random_prime_run_) {
            err = (this->*generate_pseudo_random_prime_run_)(argc, argv, env);
        } else {
            err = default_generate_pseudo_random_prime_run(argc, argv, env);
        }
        return err;
    }
    virtual int default_generate_pseudo_random_prime_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        err = all_pseudo_random_prime_run(argc, argv, env);
        return err;
    }
    virtual int before_generate_pseudo_random_prime_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_generate_pseudo_random_prime_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_generate_pseudo_random_prime_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_generate_pseudo_random_prime_run(argc, argv, env))) {
            int err2 = 0;
            err = generate_pseudo_random_prime_run(argc, argv, env);
            if ((err2 = after_generate_pseudo_random_prime_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_generate_pseudo_random_prime_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_generate_pseudo_random_prime_run;
        return err;
    }

    /// ...output_modulus_bits_run
    virtual int output_modulus_bits_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_output_modulus_bits_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_output_modulus_bits_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_output_modulus_bits_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_output_modulus_bits_run(argc, argv, env))) {
            int err2 = 0;
            err = output_modulus_bits_run(argc, argv, env);
            if ((err2 = after_output_modulus_bits_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_output_modulus_bits_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_output_modulus_bits_run;
        return err;
    }
    /// ...output_modulus_bytes_run
    virtual int output_modulus_bytes_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_output_modulus_bytes_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_output_modulus_bytes_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_output_modulus_bytes_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_output_modulus_bytes_run(argc, argv, env))) {
            int err2 = 0;
            err = output_modulus_bytes_run(argc, argv, env);
            if ((err2 = after_output_modulus_bytes_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_output_modulus_bytes_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_output_modulus_bytes_run;
        return err;
    }

    /// ...miller_rabin_pseudo_random_prime_run
    int (derives::*miller_rabin_pseudo_random_prime_run_)(int argc, char_t** argv, char_t** env);
    virtual int miller_rabin_pseudo_random_prime_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (miller_rabin_pseudo_random_prime_run_) {
            err = (this->*miller_rabin_pseudo_random_prime_run_)(argc, argv, env);
        } else {
            err = default_miller_rabin_pseudo_random_prime_run(argc, argv, env);
        }
        return err;
    }
    virtual int default_miller_rabin_pseudo_random_prime_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        err = all_bn_miller_rabin_pseudo_random_prime_run(argc, argv, env);
        return err;
    }
    virtual int before_miller_rabin_pseudo_random_prime_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_miller_rabin_pseudo_random_prime_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_miller_rabin_pseudo_random_prime_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_miller_rabin_pseudo_random_prime_run(argc, argv, env))) {
            int err2 = 0;
            err = miller_rabin_pseudo_random_prime_run(argc, argv, env);
            if ((err2 = after_miller_rabin_pseudo_random_prime_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_miller_rabin_pseudo_random_prime_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        generate_pseudo_random_prime_run_ = &derives::all_miller_rabin_pseudo_random_prime_run;
        return err;
    }
    /// ...bn_miller_rabin_pseudo_random_prime_run
    virtual int bn_miller_rabin_pseudo_random_prime_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_bn_miller_rabin_pseudo_random_prime_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_bn_miller_rabin_pseudo_random_prime_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_bn_miller_rabin_pseudo_random_prime_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_bn_miller_rabin_pseudo_random_prime_run(argc, argv, env))) {
            int err2 = 0;
            err = bn_miller_rabin_pseudo_random_prime_run(argc, argv, env);
            if ((err2 = after_bn_miller_rabin_pseudo_random_prime_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_bn_miller_rabin_pseudo_random_prime_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        miller_rabin_pseudo_random_prime_run_ = &derives::all_bn_miller_rabin_pseudo_random_prime_run;
        return err;
    }
    /// ...gmp_miller_rabin_pseudo_random_prime_run
    virtual int gmp_miller_rabin_pseudo_random_prime_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_gmp_miller_rabin_pseudo_random_prime_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_gmp_miller_rabin_pseudo_random_prime_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_gmp_miller_rabin_pseudo_random_prime_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_gmp_miller_rabin_pseudo_random_prime_run(argc, argv, env))) {
            int err2 = 0;
            err = gmp_miller_rabin_pseudo_random_prime_run(argc, argv, env);
            if ((err2 = after_gmp_miller_rabin_pseudo_random_prime_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_gmp_miller_rabin_pseudo_random_prime_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        miller_rabin_pseudo_random_prime_run_ = &derives::all_gmp_miller_rabin_pseudo_random_prime_run;
        return err;
    }
    /// ...pseudo_random_prime_run
    int (derives::*pseudo_random_prime_run_)(int argc, char_t** argv, char_t** env);
    virtual int pseudo_random_prime_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (pseudo_random_prime_run_) {
            err = (this->*pseudo_random_prime_run_)(argc, argv, env);
        } else {
            err = default_pseudo_random_prime_run(argc, argv, env);
        }
        return err;
    }
    virtual int default_pseudo_random_prime_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        err = all_bn_pseudo_random_prime_run(argc, argv, env);
        return err;
    }
    virtual int before_pseudo_random_prime_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_pseudo_random_prime_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_pseudo_random_prime_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_pseudo_random_prime_run(argc, argv, env))) {
            int err2 = 0;
            err = pseudo_random_prime_run(argc, argv, env);
            if ((err2 = after_pseudo_random_prime_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_pseudo_random_prime_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        generate_pseudo_random_prime_run_ = &derives::all_pseudo_random_prime_run;
        return err;
    }
    /// ...bn_pseudo_random_prime_run
    virtual int bn_pseudo_random_prime_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_bn_pseudo_random_prime_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_bn_pseudo_random_prime_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_bn_pseudo_random_prime_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_bn_pseudo_random_prime_run(argc, argv, env))) {
            int err2 = 0;
            err = bn_pseudo_random_prime_run(argc, argv, env);
            if ((err2 = after_bn_pseudo_random_prime_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_bn_pseudo_random_prime_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        pseudo_random_prime_run_ = &derives::all_bn_pseudo_random_prime_run;
        return err;
    }
    /// ...gmp_pseudo_random_prime_run
    virtual int gmp_pseudo_random_prime_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_gmp_pseudo_random_prime_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_gmp_pseudo_random_prime_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_gmp_pseudo_random_prime_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_gmp_pseudo_random_prime_run(argc, argv, env))) {
            int err2 = 0;
            err = gmp_pseudo_random_prime_run(argc, argv, env);
            if ((err2 = after_gmp_pseudo_random_prime_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_gmp_pseudo_random_prime_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        pseudo_random_prime_run_ = &derives::all_gmp_pseudo_random_prime_run;
        return err;
    }

    /// output_const_0x_verbage...
    virtual int output_const_0x_verbage_sized(const char_t* verbage, const byte_array_t& array) {
        int err = 0;
        size_t length = 0;
        const byte_t* bytes = 0; 
        if ((bytes = array.has_elements(length))) {
            err = output_const_0x_verbage_sized(verbage, bytes, length);
        }
        return err;
    }
    virtual int output_const_0x_verbage_sized(const char_t* verbage, const void* out, size_t len) {
        int err = 0;
        err = output_0x_verbage_sized
        ("const byte_t ", " = {", "};", verbage, out, len);
        return err;
    }
    virtual int output_0x_verbage_sized
    (const char_t* before, const char_t* between, const char_t* after, 
     const char_t* verbage, const void* out, size_t len) {
        int err = 0;
        if ((out) && (len)) {
            bool verbose = this->verbose_output();
            if ((verbose)) {
                if ((before) && (before[0])) {
                    this->out(before);
                }
                if ((verbage) && (verbage[0])) {
                    unsigned_to_string size(len);
                    this->out(verbage);
                    this->out("[");
                    this->out(size);
                    this->out("]");
                }
                if ((between) && (between[0])) {
                    this->outln(between);
                }
            }
            this->output_0x(out, len);
            if ((verbose)) {
                if ((after) && (after[0])) {
                    this->outln(after);
                } else {
                    if ((verbage) && (verbage[0])) {
                        this->outln();
                    }
                }
            }
        }
        return err;
    }

    /// output_hex_verbage...
    virtual int output_hex_verbage_sized(const char_t* verbage, const byte_array_t& array) {
        int err = 0;
        size_t length = 0;
        const byte_t* bytes = 0; 
        if ((bytes = array.has_elements(length))) {
            err = output_hex_verbage_sized(verbage, bytes, length);
        }
        return err;
    }
    int (derives::*output_hex_verbage_sized_)(const char_t* verbage, const void* out, size_t len);
    virtual int output_hex_verbage_sized(const char_t* verbage, const void* out, size_t len) {
        int err = 0;
        if (output_hex_verbage_sized_) {
            err = (this->*output_hex_verbage_sized_)(verbage, out, len);
        } else {
            if ((const_0x_output())) {
                err = output_const_0x_verbage_sized(verbage, out, len);
            } else {
                err = default_output_hex_verbage_sized(verbage, out, len);
            }
        }
        return err;
    }
    virtual int default_output_hex_verbage_sized(const char_t* verbage, const void* out, size_t len) {
        int err = 0;
        if ((out) && (len)) {
            bool verbose = this->verbose_output();
            if ((verbose) && (verbage) && (verbage[0])) {
                unsigned_to_string size(len);
                this->out(verbage);
                this->out("[");
                this->out(size);
                this->outln("]:\\");
            }
            this->output_hex(out, len);
            if ((verbose) && (verbage) && (verbage[0])) {
                this->outln();
            }
        }
        return err;
    }
    virtual int output_hex_verbage(const char_t* verbage, const byte_array_t& array) {
        int err = 0;
        size_t length = 0;
        const byte_t* bytes = 0; 
        if ((bytes = array.has_elements(length))) {
            err = output_hex_verbage(verbage, bytes, length);
        }
        return err;
    }
    virtual int output_hex_verbage(const char_t* verbage, const void* out, size_t len) {
        int err = 0;
        if ((out) && (len)) {
            bool verbose = this->verbose_output();
            if ((verbose) && (verbage) && (verbage[0])) {
                this->out(verbage);
                this->outln(":\\");
            }
            this->output_hex(out, len);
            if ((verbose) && (verbage) && (verbage[0])) {
                this->outln();
            }
        }
        return err;
    }

    /// output_const_0x_verbose...
    virtual int output_const_0x_verbose_sized(const char_t* verbage, const byte_array_t& array) {
        int err = 0;
        size_t length = 0;
        const byte_t* bytes = 0; 
        if ((bytes = array.has_elements(length))) {
            err = output_const_0x_verbose_sized(verbage, bytes, length);
        }
        return err;
    }
    virtual int output_const_0x_verbose_sized(const char_t* verbage, const void* out, size_t len) {
        int err = 0;
        err = output_0x_verbose_sized
        ("const byte_t ", " = {", "};", verbage, out, len);
        return err;
    }
    virtual int output_0x_verbose_sized
    (const char_t* before, const char_t* between, const char_t* after, 
     const char_t* verbage, const void* out, size_t len) {
        int err = 0;
        if ((out) && (len)) {
            bool verbose = this->verbose_output();
            if ((verbose)) {
                if ((before) && (before[0])) {
                    this->out(before);
                }
                if ((verbage) && (verbage[0])) {
                    unsigned_to_string size(len);
                    this->out(verbage);
                    this->out("[");
                    this->out(size);
                    this->out("]");
                }
                if ((between) && (between[0])) {
                    this->outln(between);
                }
                this->output_0x(out, len);
                if ((after) && (after[0])) {
                    this->outln(after);
                } else {
                    if ((verbage) && (verbage[0])) {
                        this->outln();
                    }
                }
            }
        }
        return err;
    }

    /// 
    /// output_hex_verbose...
    /// ...
    virtual int output_hex_verbose_sized(const char_t* verbage, const byte_array_t& array) {
        int err = 0;
        size_t length = 0;
        const byte_t* bytes = 0; 
        if ((bytes = array.has_elements(length))) {
            err = output_hex_verbose_sized(verbage, bytes, length);
        }
        return err;
    }
    int (derives::*output_hex_verbose_sized_)(const char_t* verbage, const void* out, size_t len);
    virtual int output_hex_verbose_sized(const char_t* verbage, const void* out, size_t len) {
        int err = 0;
        if (output_hex_verbose_sized_) {
            err = (this->*output_hex_verbose_sized_)(verbage, out, len);
        } else {
            if ((const_0x_output())) {
                err = output_const_0x_verbose_sized(verbage, out, len);
            } else {
                err = default_output_hex_verbose_sized(verbage, out, len);
            }
        }
        return err;
    }
    virtual int default_output_hex_verbose_sized(const char_t* verbage, const void* out, size_t len) {
        int err = 0;
        if ((out) && (len)) {
            bool verbose = this->verbose_output();
            if ((verbose) && (verbage) && (verbage[0])) {
                unsigned_to_string size(len);
                this->out(verbage);
                this->out("[");
                this->out(size);
                this->outln("]:\\");
                this->output_hex(out, len);
                this->outln();
            }
        }
        return err;
    }
    virtual int output_hex_verbose(const char_t* verbage, const byte_array_t& array) {
        int err = 0;
        size_t length = 0;
        const byte_t* bytes = 0; 
        if ((bytes = array.has_elements(length))) {
            err = output_hex_verbose(verbage, bytes, length);
        }
        return err;
    }
    virtual int output_hex_verbose(const char_t* verbage, const void* out, size_t len) {
        int err = 0;
        if ((out) && (len)) {
            bool verbose = this->verbose_output();
            if ((verbose) && (verbage) && (verbage[0])) {
                this->out(verbage);
                this->outln(":\\");
                this->output_hex(out, len);
                this->outln();
            }
        }
        return err;
    }
    /// ...
    /// output_hex_verbose...
    /// 

    /// ...on...option...
    virtual int on_set_Ox_hex_option
    (int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        set_const_0x_output();
        return err;
    }

    /// 
    /// ...on...set_hex...literals
    /// ...
    int (derives::*on_set_hex_literals_)(xos::io::hex::read_to_byte_arrays &to_arrays, string_t &literal);
    virtual int on_set_hex_literals(xos::io::hex::read_to_byte_arrays &to_arrays, string_t &literal) {
        int err = 0;
        if (on_set_hex_literals_) {
            err = (this->*on_set_hex_literals_)(to_arrays, literal);
        } else {
            err = default_on_set_hex_literals(to_arrays, literal);
        }
        return err;
    }
    virtual int default_on_set_hex_literals(xos::io::hex::read_to_byte_arrays &to_arrays, string_t &literal) {
        int err = 0;
        err = on_set_hex_file_literals(to_arrays, literal);
        return err;
    }
    virtual int on_set_hex_file_literals(xos::io::hex::read_to_byte_arrays &to_arrays, string_t &literal) {
        int err = 0;
        size_t length = 0;
        const char_t* chars = 0;

        if ((chars = literal.has_chars(length))) {
            xos::io::crt::file::char_reader file;

            this->errlln("file.open(\"", chars, "\")...", null);
            if ((file.open(chars))) {
                ssize_t count = 0;
                xos::io::hex::reader hex(to_arrays, file);
    
                if (0 >= (count = hex.read())) {
                    err = on_failed_set_hex_literals(to_arrays, literal);
                }
                this->errlln("...file.close(\"", chars, "\")...", null);
                file.close();
            }
        }
        return err;
    }
    virtual int on_failed_set_hex_literals(xos::io::hex::read_to_byte_arrays &to_arrays, string_t &literal) {
        int err = 0;
        size_t length = 0;
        xos::io::hex::read_to_byte_arrays::arrays_t &arrays = to_arrays.arrays();
        xos::io::hex::read_to_byte_arrays::array_pointer_t* array_pointers = 0;

        if ((array_pointers = arrays.elements(length))) {
            xos::io::hex::read_to_byte_arrays::array_pointer_t array_pointer = 0;

            for (array_pointer = *array_pointers; length; --length, ++array_pointers) {
                if ((array_pointer)) {
                    array_pointer->set_length(0);
                }
            }
        }
        return err;
    }
    /// ...
    /// ...on...set_hex...literals
    /// 

    /// ...on...prime...option...
    virtual int on_generate_prime_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_generate_pseudo_random_prime_run(argc, argv, env))) {
        }
        return err;
    }
    virtual const char_t* generate_prime_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GENERATE_PRIME_OPTUSE;
        optarg = XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GENERATE_PRIME_OPTARG;
        return chars;
    }
    virtual int on_miller_rabin_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_miller_rabin_pseudo_random_prime_run(argc, argv, env))) {
        }
        return err;
    }
    virtual const char_t* miller_rabin_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MILLER_RABIN_OPTUSE;
        optarg = XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MILLER_RABIN_OPTARG;
        return chars;
    }
    virtual int on_fermat_witness_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_pseudo_random_prime_run(argc, argv, env))) {
            set_no_miller_rabin_test();
        }
        return err;
    }
    virtual const char_t* fermat_witness_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_FERMAT_WITNESS_OPTUSE;
        optarg = XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_FERMAT_WITNESS_OPTARG;
        return chars;
    }

    /// ...on...modulus...option...
    virtual int on_set_modulus_bits_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_modulus_bits_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_modulus_bits_option(optarg, optind, argc, argv, env))) {
                if (!(err = set_output_modulus_bits_run(argc, argv, env))) {
                }
            }
        } else {
            if (!(err = set_output_modulus_bits_run(argc, argv, env))) {
            }
        }
        return err;
    }
    virtual const char_t* modulus_bits_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BITS_OPTUSE;
        optarg = XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BITS_OPTARG;
        return chars;
    }
    virtual int on_set_modulus_bytes_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_modulus_bytes_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_modulus_bytes_option(optarg, optind, argc, argv, env))) {
                if (!(err = set_output_modulus_bytes_run(argc, argv, env))) {
                }
            }
        } else {
            if (!(err = set_output_modulus_bytes_run(argc, argv, env))) {
            }
        }
        return err;
    }
    virtual const char_t* modulus_bytes_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BYTES_OPTUSE;
        optarg = XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BYTES_OPTARG;
        return chars;
    }

    /// ...on...option...
    virtual int on_set_bn_integer_option(int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_bn_integer_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_bn_miller_rabin_pseudo_random_prime_run(argc, argv, env))) {
            if (!(err = set_bn_pseudo_random_prime_run(argc, argv, env))) {
                if (!(err = on_set_bn_integer_option(argc, argv, env))) {
                }
            }
        }
        return err;
    }
    virtual const char_t* bn_integer_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_BN_INTEGER_OPTUSE;
        optarg = XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_BN_INTEGER_OPTARG;
        return chars;
    }
    virtual int on_set_gmp_integer_option(int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_gmp_integer_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_gmp_miller_rabin_pseudo_random_prime_run(argc, argv, env))) {
            if (!(err = set_gmp_pseudo_random_prime_run(argc, argv, env))) {
                if (!(err = on_set_gmp_integer_option(argc, argv, env))) {
                }
            }
        }
        return err;
    }
    virtual const char_t* gmp_integer_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GMP_INTEGER_OPTUSE;
        optarg = XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GMP_INTEGER_OPTARG;
        return chars;
    }

    /// ...on...option...
    virtual int on_verbose_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        set_verbose_output();
        return err;
    }
    virtual const char_t* verbose_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_VERBOSE_OPTUSE;
        optarg = XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_VERBOSE_OPTARG;
        return chars;
    }

    /// ...option...
    virtual int on_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        switch(optval) {

        case XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GENERATE_PRIME_OPTVAL_C:
            err = this->on_generate_prime_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MILLER_RABIN_OPTVAL_C:
            err = this->on_miller_rabin_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_FERMAT_WITNESS_OPTVAL_C:
            err = this->on_fermat_witness_option(optval, optarg, optname, optind, argc, argv, env);
            break;

        case XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BITS_OPTVAL_C:
            err = this->on_modulus_bits_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BYTES_OPTVAL_C:
            err = this->on_modulus_bytes_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_BN_INTEGER_OPTVAL_C:
            err = this->on_bn_integer_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GMP_INTEGER_OPTVAL_C:
            err = this->on_gmp_integer_option(optval, optarg, optname, optind, argc, argv, env);
            break;

        case XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_VERBOSE_OPTVAL_C:
            err = this->on_verbose_option(optval, optarg, optname, optind, argc, argv, env);
            break;

        default:
            err = extends::on_option(optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    virtual const char_t* option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = "";
        switch(longopt->val) {

        case XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GENERATE_PRIME_OPTVAL_C:
            chars = this->generate_prime_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MILLER_RABIN_OPTVAL_C:
            chars = this->miller_rabin_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_FERMAT_WITNESS_OPTVAL_C:
            chars = this->fermat_witness_option_usage(optarg, longopt);
            break;

        case XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BITS_OPTVAL_C:
            chars = this->modulus_bits_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_MODULUS_BYTES_OPTVAL_C:
            chars = this->modulus_bytes_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_BN_INTEGER_OPTVAL_C:
            chars = this->bn_integer_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GMP_INTEGER_OPTVAL_C:
            chars = this->gmp_integer_option_usage(optarg, longopt);
            break;

        case XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_VERBOSE_OPTVAL_C:
            chars = this->verbose_option_usage(optarg, longopt);
            break;

        default:
            chars = extends::option_usage(optarg, longopt);
            break;
        }
        return chars;
    }
    virtual const char_t* options(const struct option*& longopts) {
        static const char_t* chars = XOS_APP_CONSOLE_CRYPTO_RSA_BASE_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            XOS_APP_CONSOLE_CRYPTO_RSA_BASE_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

    /// ...argument...
    virtual const char_t* arguments(const char_t**& argv) {
        static const char_t* _args = XOS_APP_CONSOLE_CRYPTO_RSA_BASE_MAIN_ARGS;
        static const char_t* _argv[] = {
            XOS_APP_CONSOLE_CRYPTO_RSA_BASE_MAIN_ARGV
            0};
        argv = _argv;
        return _args;
    }

    /// ...miller_rabin_test
    virtual bool set_miller_rabin_test(const bool to = true) {
        no_miller_rabin_test_ = !to;
        return no_miller_rabin_test_;
    }
    virtual bool set_no_miller_rabin_test(const bool to = true) {
        no_miller_rabin_test_ = to;
        return no_miller_rabin_test_;
    }
    virtual bool no_miller_rabin_test() const {
        return no_miller_rabin_test_;
    }

    /// ...const_0x_output
    virtual bool set_const_0x_output(const bool to = true) {
        const_0x_output_ = to;
        return const_0x_output_;
    }
    virtual bool const_0x_output() const {
        return const_0x_output_;
    }

    /// ...verbose / ...quiet
    virtual bool set_verbose_output(const bool to = true) {
        verbose_output_ = to;
        return verbose_output_;
    }
    virtual bool verbose_output() const {
        return verbose_output_;
    }
    virtual bool set_quiet_output(const bool to = true) {
        verbose_output_ = !to;
        return !verbose_output_;
    }
    virtual bool quiet_output() const {
        return !verbose_output_;
    }

    /// ...modulus...
    virtual size_t set_modulus_bits(const size_t& to) {
        size_t modulus_bytes = ((to + 7) >> 3);
        modulus_bits_ = (modulus_bytes << 3);
        return modulus_bits_;
    }
    virtual size_t modulus_bits() const {
        return modulus_bits_;
    }
    virtual size_t set_modulus_bytes(const size_t& to) {
        size_t modulus_bytes = to;
        modulus_bits_ = (modulus_bytes << 3);
        return modulus_bytes;
    }
    virtual size_t modulus_bytes() const {
        size_t modulus_bytes = (modulus_bits_ >> 3);
        return modulus_bytes;
    }

    /// ...rsa...
    virtual byte_t& rsa_plain(size_t& size) const {
        size = sizeof(rsa_plain_);
        return (byte_t&)(rsa_plain_[0]);
    }
    virtual byte_t& rsa_cipher(size_t& size) const {
        size = sizeof(rsa_cipher_);
        return (byte_t&)(rsa_cipher_[0]);
    }
    virtual byte_t& rsa_encipher(size_t& size) const {
        size = sizeof(rsa_encipher_);
        return (byte_t&)(rsa_encipher_[0]);
    }
    virtual byte_t& rsa_decipher(size_t& size) const {
        size = sizeof(rsa_decipher_);
        return (byte_t&)(rsa_decipher_[0]);
    }
    virtual byte_t& rsa_random(size_t& size) const {
        size = sizeof(rsa_random_);
        return (byte_t&)(rsa_random_[0]);
    }

protected:
    enum {
        modulus_bits_min = 1024,
        modulus_bits_max = 1024*8,
        
        modulus_bytes_min = (modulus_bits_min >> 3),
        modulus_bytes_max = (modulus_bits_max >> 3),

        modbytes_min = modulus_bytes_min,
        modbytes_max = modulus_bytes_max
    };
    bool no_miller_rabin_test_, const_0x_output_, verbose_output_;
    size_t modulus_bits_;
    byte_t rsa_plain_[modbytes_max], rsa_cipher_[modbytes_max], 
           rsa_encipher_[modbytes_max], rsa_decipher_[modbytes_max], rsa_random_[modbytes_max];
}; /// class main_optt
typedef main_optt<> main_opt;

} /// namespace base
} /// namespace rsa
} /// namespace crypto
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_CRYPTO_RSA_BASE_MAIN_OPT_HPP
