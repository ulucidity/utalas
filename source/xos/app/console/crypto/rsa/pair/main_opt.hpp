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
///   Date: 5/29/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_CRYPTO_RSA_PAIR_MAIN_OPT_HPP
#define XOS_APP_CONSOLE_CRYPTO_RSA_PAIR_MAIN_OPT_HPP

#include "xos/app/console/crypto/rsa/base/main.hpp"
#include "xos/app/console/crypto/rsa/pair/key_define.hpp"

#include "xos/app/console/crypto/rsa/key_pair.hpp"
#include "xos/app/console/crypto/rsa/public_key.hpp"
#include "xos/app/console/crypto/rsa/private_key.hpp"
#include "xos/app/console/crypto/rsa/public_exponent_const.hpp"

#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GENERATE_KEY_OPT "generate-key"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GENERATE_KEY_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GENERATE_KEY_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GENERATE_KEY_OPTARG ""
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GENERATE_KEY_OPTUSE "generate RSA key pair"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GENERATE_KEY_OPTVAL_S "n"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GENERATE_KEY_OPTVAL_C 'n'
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GENERATE_KEY_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GENERATE_KEY_OPT, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GENERATE_KEY_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GENERATE_KEY_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GENERATE_KEY_OPTVAL_C}, \

#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_KEY_PAIR_OPT "key-pair"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_KEY_PAIR_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_KEY_PAIR_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_KEY_PAIR_OPTARG "[string]"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_KEY_PAIR_OPTUSE "RSA key pair"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_KEY_PAIR_OPTVAL_S "k::"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_KEY_PAIR_OPTVAL_C 'k'
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_KEY_PAIR_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_KEY_PAIR_OPT, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_KEY_PAIR_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_KEY_PAIR_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_KEY_PAIR_OPTVAL_C}, \

#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PUBLIC_KEY_OPT "public-key"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PUBLIC_KEY_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PUBLIC_KEY_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PUBLIC_KEY_OPTARG "[string]"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PUBLIC_KEY_OPTUSE "RSA public key"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PUBLIC_KEY_OPTVAL_S "u::"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PUBLIC_KEY_OPTVAL_C 'u'
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PUBLIC_KEY_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PUBLIC_KEY_OPT, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PUBLIC_KEY_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PUBLIC_KEY_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PUBLIC_KEY_OPTVAL_C}, \

#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PRIVATE_KEY_OPT "private-key"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PRIVATE_KEY_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PRIVATE_KEY_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PRIVATE_KEY_OPTARG "[string]"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PRIVATE_KEY_OPTUSE "RSA private key"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PRIVATE_KEY_OPTVAL_S "r::"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PRIVATE_KEY_OPTVAL_C 'r'
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PRIVATE_KEY_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PRIVATE_KEY_OPT, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PRIVATE_KEY_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PRIVATE_KEY_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PRIVATE_KEY_OPTVAL_C}, \

#define XOS_APP_CONSOLE_CRYPTO_RSA_PAIR_MAIN_OPTIONS_CHARS_EXTEND \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GENERATE_KEY_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_KEY_PAIR_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PUBLIC_KEY_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PRIVATE_KEY_OPTVAL_S \

#define XOS_APP_CONSOLE_CRYPTO_RSA_PAIR_MAIN_OPTIONS_OPTIONS_EXTEND \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GENERATE_KEY_OPTION \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_KEY_PAIR_OPTION \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PUBLIC_KEY_OPTION \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PRIVATE_KEY_OPTION \

#define XOS_APP_CONSOLE_CRYPTO_RSA_PAIR_MAIN_OPTIONS_CHARS \
   XOS_APP_CONSOLE_CRYPTO_RSA_PAIR_MAIN_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_CRYPTO_RSA_BASE_MAIN_OPTIONS_CHARS

#define XOS_APP_CONSOLE_CRYPTO_RSA_PAIR_MAIN_OPTIONS_OPTIONS \
   XOS_APP_CONSOLE_CRYPTO_RSA_PAIR_MAIN_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_CRYPTO_RSA_BASE_MAIN_OPTIONS_OPTIONS

#define XOS_APP_CONSOLE_CRYPTO_RSA_PAIR_MAIN_ARGS 0
#define XOS_APP_CONSOLE_CRYPTO_RSA_PAIR_MAIN_ARGV 0,

namespace xos {
namespace app {
namespace console {
namespace crypto {
namespace rsa {
namespace pair {

/// class main_optt
template 
<class TExtends = xos::app::console::crypto::rsa::base::main, 
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
      key_pair_define_(const_key_pair_define),
      public_key_define_(const_public_key_define),
      private_key_define_(const_private_key_define),
      exponent_bits_(const_exponent_bits), 
      exponent_value_(const_exponent_value) {
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

    typedef typename extends::byte_array_t byte_array_t;
    typedef typename extends::crypto_array_t crypto_array_t;

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

    ///
    /// ...generate_key_pair_run
    /// ...
    int (derives::*generate_key_pair_run_)(int argc, char_t** argv, char_t** env);
    virtual int generate_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (generate_key_pair_run_) {
            err = (this->*generate_key_pair_run_)(argc, argv, env);
        } else {
            err = default_generate_key_pair_run(argc, argv, env);
        }
        return err;
    }
    virtual int default_generate_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        err = all_bn_generate_key_pair_run(argc, argv, env);
        return err;
    }
    virtual int set_default_generate_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        generate_key_pair_run_ = 0;
        return err;
    }
    virtual int before_generate_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const char_t* arg = 0;
        if ((optind < (argc)) && ((arg = argv[optind])) && (arg[0])) {
            key_pair_define_.assign(arg);
        }
        return err;
    }
    virtual int after_generate_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_generate_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_generate_key_pair_run(argc, argv, env))) {
            int err2 = 0;
            err = generate_key_pair_run(argc, argv, env);
            if ((err2 = after_generate_key_pair_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_generate_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_generate_key_pair_run;
        return err;
    }
    /// ...bn_generate_key_pair_run
    virtual int bn_generate_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_bn_generate_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_bn_generate_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_bn_generate_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_bn_generate_key_pair_run(argc, argv, env))) {
            int err2 = 0;
            err = bn_generate_key_pair_run(argc, argv, env);
            if ((err2 = after_bn_generate_key_pair_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_bn_generate_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        generate_key_pair_run_ = &derives::all_bn_generate_key_pair_run;
        return err;
    }
    /// ...gmp_generate_key_pair_run
    virtual int gmp_generate_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_gmp_generate_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_gmp_generate_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_gmp_generate_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_gmp_generate_key_pair_run(argc, argv, env))) {
            int err2 = 0;
            err = gmp_generate_key_pair_run(argc, argv, env);
            if ((err2 = after_gmp_generate_key_pair_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_gmp_generate_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        generate_key_pair_run_ = &derives::all_gmp_generate_key_pair_run;
        return err;
    }
    /// ...
    /// ...generate_key_pair_run
    /// 

    ///
    /// ...output...key_pair_run
    /// ...
    /// ...output_key_pair_run
    int (derives::*output_key_pair_run_)(int argc, char_t** argv, char_t** env);
    virtual int output_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (output_key_pair_run_) {
            err = (this->*output_key_pair_run_)(argc, argv, env);
        } else {
            err = default_output_key_pair_run(argc, argv, env);
        }
        return err;
    }
    virtual int default_output_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        err = all_output_get_key_pair_run(argc, argv, env);
        return err;
    }
    virtual int before_output_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const char_t* arg = 0;
        if ((optind < (argc)) && ((arg = argv[optind])) && (arg[0])) {
            key_pair_define_.assign(arg);
        }
        return err;
    }
    virtual int after_output_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_output_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_output_key_pair_run(argc, argv, env))) {
            int err2 = 0;
            err = output_key_pair_run(argc, argv, env);
            if ((err2 = after_output_key_pair_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_output_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_output_key_pair_run;
        return err;
    }
    /// ...output_get_key_pair_run
    int (derives::*output_get_key_pair_run_)(int argc, char_t** argv, char_t** env);
    virtual int output_get_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (output_get_key_pair_run_) {
            err = (this->*output_get_key_pair_run_)(argc, argv, env);
        } else {
            err = default_output_get_key_pair_run(argc, argv, env);
        }
        return err;
    }
    virtual int default_output_get_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        /// err = extends::run(argc, argv, env);
        return err;
    }
    virtual int before_output_get_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_output_get_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_output_get_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_output_get_key_pair_run(argc, argv, env))) {
            int err2 = 0;
            err = output_get_key_pair_run(argc, argv, env);
            if ((err2 = after_output_get_key_pair_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_output_get_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        output_key_pair_run_ = &derives::all_output_get_key_pair_run;
        return err;
    }
    /// ...output_test_key_pair_run
    int (derives::*output_test_key_pair_run_)(int argc, char_t** argv, char_t** env);
    virtual int output_test_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (output_test_key_pair_run_) {
            err = (this->*output_test_key_pair_run_)(argc, argv, env);
        } else {
            err = default_output_test_key_pair_run(argc, argv, env);
        }
        return err;
    }
    virtual int default_output_test_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        /// err = extends::run(argc, argv, env);
        return err;
    }
    virtual int before_output_test_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_output_test_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_output_test_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_output_test_key_pair_run(argc, argv, env))) {
            int err2 = 0;
            err = output_test_key_pair_run(argc, argv, env);
            if ((err2 = after_output_test_key_pair_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_output_test_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        output_key_pair_run_ = &derives::all_output_test_key_pair_run;
        return err;
    }
    /// ...
    /// ...output...key_pair_run
    /// 

    ///
    /// ...output...private_key_run
    /// ...
    /// ...output_private_key_run
    int (derives::*output_private_key_run_)(int argc, char_t** argv, char_t** env);
    virtual int output_private_key_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (output_private_key_run_) {
            err = (this->*output_private_key_run_)(argc, argv, env);
        } else {
            err = all_output_get_private_key_run(argc, argv, env);
        }
        return err;
    }
    virtual int set_default_output_private_key_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        output_private_key_run_ = 0;
        return err;
    }
    virtual int before_output_private_key_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const char_t* arg = 0;
        if ((optind < (argc)) && ((arg = argv[optind])) && (arg[0])) {
            private_key_define_.assign(arg);
        }
        return err;
    }
    virtual int after_output_private_key_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_output_private_key_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_output_private_key_run(argc, argv, env))) {
            int err2 = 0;
            err = output_private_key_run(argc, argv, env);
            if ((err2 = after_output_private_key_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_output_private_key_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_output_private_key_run;
        return err;
    }
    /// ...output_get_private_key_run
    int (derives::*output_get_private_key_run_)(int argc, char_t** argv, char_t** env);
    virtual int output_get_private_key_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (output_get_private_key_run_) {
            err = (this->*output_get_private_key_run_)(argc, argv, env);
        } else {
            err = default_output_get_private_key_run(argc, argv, env);
        }
        return err;
    }
    virtual int default_output_get_private_key_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        /// err = extends::run(argc, argv, env);
        return err;
    }
    virtual int before_output_get_private_key_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_output_get_private_key_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_output_get_private_key_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_output_get_private_key_run(argc, argv, env))) {
            int err2 = 0;
            err = output_get_private_key_run(argc, argv, env);
            if ((err2 = after_output_get_private_key_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_output_get_private_key_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        output_private_key_run_ = &derives::all_output_get_private_key_run;
        return err;
    }
    /// ...output_test_private_key_run
    int (derives::*output_test_private_key_run_)(int argc, char_t** argv, char_t** env);
    virtual int output_test_private_key_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (output_test_private_key_run_) {
            err = (this->*output_test_private_key_run_)(argc, argv, env);
        } else {
            err = default_output_test_private_key_run(argc, argv, env);
        }
        return err;
    }
    virtual int default_output_test_private_key_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        /// err = extends::run(argc, argv, env);
        return err;
    }
    virtual int before_output_test_private_key_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_output_test_private_key_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_output_test_private_key_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_output_test_private_key_run(argc, argv, env))) {
            int err2 = 0;
            err = output_test_private_key_run(argc, argv, env);
            if ((err2 = after_output_test_private_key_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_output_test_private_key_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        output_private_key_run_ = &derives::all_output_test_private_key_run;
        return err;
    }
    /// ...
    /// ...output...private_key_run
    /// 

    ///
    /// ...output...public_key_run
    /// ...
    /// ...output_public_key_run
    int (derives::*output_public_key_run_)(int argc, char_t** argv, char_t** env);
    virtual int output_public_key_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (output_public_key_run_) {
            err = (this->*output_public_key_run_)(argc, argv, env);
        } else {
            err = all_output_get_public_key_run(argc, argv, env);
        }
        return err;
    }
    virtual int set_default_output_public_key_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        output_public_key_run_ = 0;
        return err;
    }
    virtual int before_output_public_key_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const char_t* arg = 0;
        if ((optind < (argc)) && ((arg = argv[optind])) && (arg[0])) {
            public_key_define_.assign(arg);
        }
        return err;
    }
    virtual int after_output_public_key_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_output_public_key_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_output_public_key_run(argc, argv, env))) {
            int err2 = 0;
            err = output_public_key_run(argc, argv, env);
            if ((err2 = after_output_public_key_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_output_public_key_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_output_public_key_run;
        return err;
    }
    /// ...output_get_public_key_run
     int (derives::*output_get_public_key_run_)(int argc, char_t** argv, char_t** env);
     virtual int output_get_public_key_run(int argc, char_t** argv, char_t** env) {
         int err = 0;
         if (output_get_public_key_run_) {
             err = (this->*output_get_public_key_run_)(argc, argv, env);
         } else {
             err = default_output_get_public_key_run(argc, argv, env);
         }
         return err;
     }
     virtual int default_output_get_public_key_run(int argc, char_t** argv, char_t** env) {
         int err = 0;
         /// err = extends::run(argc, argv, env);
         return err;
     }
     virtual int before_output_get_public_key_run(int argc, char_t** argv, char_t** env) {
         int err = 0;
         return err;
     }
     virtual int after_output_get_public_key_run(int argc, char_t** argv, char_t** env) {
         int err = 0;
         return err;
     }
     virtual int all_output_get_public_key_run(int argc, char_t** argv, char_t** env) {
         int err = 0;
         if (!(err = before_output_get_public_key_run(argc, argv, env))) {
             int err2 = 0;
             err = output_get_public_key_run(argc, argv, env);
             if ((err2 = after_output_get_public_key_run(argc, argv, env))) {
                 if (!(err)) err = err2;
             }
         }
         return err;
     }
     virtual int set_output_get_public_key_run(int argc, char_t** argv, char_t** env) {
         int err = 0;
         output_public_key_run_ = &derives::all_output_get_public_key_run;
         return err;
     }
    /// ...output_test_public_key_run
    int (derives::*output_test_public_key_run_)(int argc, char_t** argv, char_t** env);
    virtual int output_test_public_key_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (output_test_public_key_run_) {
            err = (this->*output_test_public_key_run_)(argc, argv, env);
        } else {
            err = default_output_test_public_key_run(argc, argv, env);
        }
        return err;
    }
    virtual int default_output_test_public_key_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        /// err = extends::run(argc, argv, env);
        return err;
    }
    virtual int before_output_test_public_key_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_output_test_public_key_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_output_test_public_key_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_output_test_public_key_run(argc, argv, env))) {
            int err2 = 0;
            err = output_test_public_key_run(argc, argv, env);
            if ((err2 = after_output_test_public_key_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_output_test_public_key_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        output_public_key_run_ = &derives::all_output_test_public_key_run;
        return err;
    }
    /// ...
    /// ...output...public_key_run
    /// 

    ///
    /// on_set...key...hex_literal...
    /// ...
    virtual int on_set_rsa_plain_hex_literal(xos::byte_array &plain, string_t &literal) {
        int err = 0;
        xos::io::hex::read_to_byte_arrays to_arrays(&plain, null);
        err = this->on_set_hex_literals(to_arrays, literal);
        return err;
    }
    virtual int on_set_rsa_cipher_hex_literal(xos::byte_array &cipher, string_t &literal) {
        int err = 0;
        xos::io::hex::read_to_byte_arrays to_arrays(&cipher, null);
        err = this->on_set_hex_literals(to_arrays, literal);
        return err;
    }
    virtual int on_set_public_key_hex_literals
    (xos::byte_array &exponent, xos::byte_array &modulus, string_t &literal) {
        int err = 0;
        xos::io::hex::read_to_byte_arrays to_arrays(&exponent, &modulus, null);
        err = this->on_set_hex_literals(to_arrays, literal);
        return err;
    }
    virtual int on_set_private_key_hex_literals
    (xos::byte_array &p, xos::byte_array &q, xos::byte_array &dmp1, 
     xos::byte_array &dmq1, xos::byte_array &iqmp, string_t &literal) {
        int err = 0;
        xos::io::hex::read_to_byte_arrays to_arrays(&p, &q, &dmp1, &dmq1, &iqmp, null);
        err = this->on_set_hex_literals(to_arrays, literal);
        return err;
    }
    virtual int on_set_key_pair_hex_literals
    (xos::byte_array &exponent, xos::byte_array &modulus, 
     xos::byte_array &p, xos::byte_array &q, xos::byte_array &dmp1, 
     xos::byte_array &dmq1, xos::byte_array &iqmp, string_t &literal) {
        int err = 0;
        xos::io::hex::read_to_byte_arrays to_arrays(&exponent, &modulus, &p, &q, &dmp1, &dmq1, &iqmp, null);
        err = this->on_set_hex_literals(to_arrays, literal);
        return err;
    }
    /// ...
    /// on_set...key...hex_literal...
    /// 

    /// 
    /// on_set...integer_option...
    /// ...
    virtual int on_set_bn_integer_option(int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_bn_generate_key_pair_run(argc, argv, env))) {
            if (!(err = extends::on_set_bn_integer_option(argc, argv, env))) {
            }
        }
        return err;
    }
    virtual int on_set_gmp_integer_option(int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_gmp_generate_key_pair_run(argc, argv, env))) {
            if (!(err = extends::on_set_gmp_integer_option(argc, argv, env))) {
            }
        }
        return err;
    }
    /// ...
    /// on_set...integer_option...
    /// 

    /// on...generate_key...
    virtual int on_generate_key_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_generate_key_pair_run(argc, argv, env))) {
        }
        return err;
    }
    virtual const char_t* generate_key_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GENERATE_KEY_OPTUSE;
        optarg = XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GENERATE_KEY_OPTARG;
        return chars;
    }
    /// on...key_pair...
    virtual int on_set_key_pair_literal(const char_t* literal, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_set_key_pair_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_key_pair_literal(optarg, argc, argv, env))) {
                if (!(err = set_output_get_key_pair_run(argc, argv, env))) {
                }
            }
        }
        return err;
    }
    virtual int on_key_pair_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_key_pair_option(optarg, optind, argc, argv, env))) {
                if (!(err = set_output_key_pair_run(argc, argv, env))) {
                }
            }
        } else {
            if (!(err = set_output_key_pair_run(argc, argv, env))) {
            }
        }
        return err;
    }
    virtual const char_t* key_pair_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_KEY_PAIR_OPTUSE;
        optarg = XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_KEY_PAIR_OPTARG;
        return chars;
    }
    /// on...private_key
    virtual int on_set_private_key_literal(const char_t* literal, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_set_private_key_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_private_key_literal(optarg, argc, argv, env))) {
                if (!(err = set_output_get_private_key_run(argc, argv, env))) {
                }
            }
        }
        return err;
    }
    virtual int on_private_key_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_private_key_option(optarg, optind, argc, argv, env))) {
                if (!(err = set_output_private_key_run(argc, argv, env))) {
                }
            }
        } else {
            if (!(err = set_output_private_key_run(argc, argv, env))) {
            }
        }
        return err;
    }
    virtual const char_t* private_key_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PRIVATE_KEY_OPTUSE;
        optarg = XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PRIVATE_KEY_OPTARG;
        return chars;
    }
    /// on...public_key
    virtual int on_set_public_key_literal(const char_t* literal, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_set_public_key_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_public_key_literal(optarg, argc, argv, env))) {
                if (!(err = set_output_get_public_key_run(argc, argv, env))) {
                }
            }
        }
        return err;
    }
    virtual int on_public_key_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_public_key_option(optarg, optind, argc, argv, env))) {
                if (!(err = set_output_public_key_run(argc, argv, env))) {
                }
            }
        } else {
            if (!(err = set_output_public_key_run(argc, argv, env))) {
            }
        }
        return err;
    }
    virtual const char_t* public_key_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PUBLIC_KEY_OPTUSE;
        optarg = XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PUBLIC_KEY_OPTARG;
        return chars;
    }

    /// ...option...
    virtual int on_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        switch(optval) {

        case XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GENERATE_KEY_OPTVAL_C:
            err = this->on_generate_key_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PUBLIC_KEY_OPTVAL_C:
            err = this->on_public_key_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PRIVATE_KEY_OPTVAL_C:
            err = this->on_private_key_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_KEY_PAIR_OPTVAL_C:
            err = this->on_key_pair_option(optval, optarg, optname, optind, argc, argv, env);
            break;

        default:
            err = extends::on_option(optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    virtual const char_t* option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = "";
        switch(longopt->val) {

        case XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_GENERATE_KEY_OPTVAL_C:
            chars = this->generate_key_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PUBLIC_KEY_OPTVAL_C:
            chars = this->public_key_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PRIVATE_KEY_OPTVAL_C:
            chars = this->private_key_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_KEY_PAIR_OPTVAL_C:
            chars = this->key_pair_option_usage(optarg, longopt);
            break;

        default:
            chars = extends::option_usage(optarg, longopt);
            break;
        }
        return chars;
    }
    virtual const char_t* options(const struct option*& longopts) {
        static const char_t* chars = XOS_APP_CONSOLE_CRYPTO_RSA_PAIR_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            XOS_APP_CONSOLE_CRYPTO_RSA_PAIR_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

    /// ...argument...
    virtual const char_t* arguments(const char_t**& argv) {
        static const char_t* _args = XOS_APP_CONSOLE_CRYPTO_RSA_PAIR_MAIN_ARGS;
        static const char_t* _argv[] = {
            XOS_APP_CONSOLE_CRYPTO_RSA_PAIR_MAIN_ARGV
            0};
        argv = _argv;
        return _args;
    }

    /// ...get_exponent
    const byte_t* (derives::*get_exponent_)(size_t &length);
    virtual const byte_t* get_exponent(size_t &length) {
        const byte_t* bytes = 0;
        if (get_exponent_) {
            bytes = (this->*get_exponent_)(length);
        } else {
            bytes = get_test_exponent(length);
        }
        return bytes;
    }
    virtual const byte_t* get_test_exponent(size_t &length) {
        const byte_t* bytes = 0;
        length = sizeof(::xos::app::console::crypto::rsa::rsa_public_exponent);
        bytes = ::xos::app::console::crypto::rsa::rsa_public_exponent;
        return bytes;
    }
    virtual const byte_t* get_literal_exponent(size_t &length) {
        const byte_t* bytes = 0;
        length = exponent_.length();
        bytes = exponent_.elements();
        return bytes;
    }
    virtual int set_get_test_exponent(int argc, char_t** argv, char_t** env) {
        int err = 0;
        get_exponent_ = &derives::get_literal_exponent;
        return err;
    }
    virtual int set_get_literal_exponent(int argc, char_t** argv, char_t** env) {
        int err = 0;
        get_exponent_ = &derives::get_literal_exponent;
        return err;
    }

    /// ...get_modulus
    const byte_t* (derives::*get_modulus_)(size_t &length);
    virtual const byte_t* get_modulus(size_t &length) {
        const byte_t* bytes = 0;
        if (get_modulus_) {
            bytes = (this->*get_modulus_)(length);
        } else {
            bytes = get_test_modulus(length);
        }
        return bytes;
    }
    virtual const byte_t* get_test_modulus(size_t &length) {
        const byte_t* bytes = 0;
        length = sizeof(::xos::app::console::crypto::rsa::rsa_public_modulus);
        bytes = ::xos::app::console::crypto::rsa::rsa_public_modulus;
        return bytes;
    }
    virtual const byte_t* get_literal_modulus(size_t &length) {
        const byte_t* bytes = 0;
        length = modulus_.length();
        bytes = modulus_.elements();
        return bytes;;
    }
    virtual int set_get_test_modulus(int argc, char_t** argv, char_t** env) {
        int err = 0;
        get_modulus_ = &derives::get_test_modulus;
        return err;
    }
    virtual int set_get_literal_modulus(int argc, char_t** argv, char_t** env) {
        int err = 0;
        get_modulus_ = &derives::get_literal_modulus;
        return err;
    }

    /// ...get_p
    const byte_t* (derives::*get_p_)
    (const byte_t *&q, const byte_t *&dmp1, 
     const byte_t *&dmq1, const byte_t *&iqmp, size_t &length);
    virtual const byte_t* get_p
    (const byte_t *&q, const byte_t *&dmp1, 
     const byte_t *&dmq1, const byte_t *&iqmp, size_t &length) {
        const byte_t* bytes = 0;
        if (get_p_) {
            bytes = (this->*get_p_)(q, dmp1, dmq1, iqmp, length);
        } else {
            bytes = get_test_p(q, dmp1, dmq1, iqmp, length);
        }
        return bytes;
    }
    virtual const byte_t* get_test_p
    (const byte_t *&q, const byte_t *&dmp1, 
     const byte_t *&dmq1, const byte_t *&iqmp, size_t &length) {
        const byte_t* bytes = 0;
        length = sizeof(::xos::app::console::crypto::rsa::rsa_private_p);
        bytes = ::xos::app::console::crypto::rsa::rsa_private_p;
        q = ::xos::app::console::crypto::rsa::rsa_private_q;
        dmp1 = ::xos::app::console::crypto::rsa::rsa_private_dmp1;
        dmq1 = ::xos::app::console::crypto::rsa::rsa_private_dmq1;
        iqmp = ::xos::app::console::crypto::rsa::rsa_private_iqmp;
        return bytes;
    }
    virtual const byte_t* get_literal_p
    (const byte_t *&q, const byte_t *&dmp1, 
     const byte_t *&dmq1, const byte_t *&iqmp, size_t &length) {
        const byte_t* bytes = 0;
        length = p_.length();
        bytes = p_.elements();
        q = q_.elements();
        dmp1 = dmp1_.elements();
        dmq1 = dmq1_.elements();
        iqmp = iqmp_.elements();
        return bytes;;
    }
    virtual int set_get_test_p(int argc, char_t** argv, char_t** env) {
        int err = 0;
        get_p_ = &derives::get_test_p;
        return err;
    }
    virtual int set_get_literal_p(int argc, char_t** argv, char_t** env) {
        int err = 0;
        get_p_ = &derives::get_literal_p;
        return err;
    }

    /// ...key_..._define...
    virtual const char_t* key_pair_define_chars() const {
        string_t &key_pair_define = this->key_pair_define();
        return key_pair_define.chars();
    }
    virtual const char_t* public_key_define_chars() const {
        string_t &public_key_define = this->public_key_define();
        return public_key_define.chars();
    }
    virtual const char_t* private_key_define_chars() const {
        string_t &private_key_define = this->private_key_define();
        return private_key_define.chars();
    }
    virtual string_t &key_pair_define() const {
        return (string_t &)key_pair_define_;
    }
    virtual string_t &public_key_define() const {
        return (string_t &)public_key_define_;
    }
    virtual string_t &private_key_define() const {
        return (string_t &)private_key_define_;
    }

    /// ...exponent...
    virtual uint32_t set_exponent_value(const uint32_t& to) {
        exponent_value_ = to;
        return exponent_value_;
    }
    virtual uint32_t exponent_value() const {
        return exponent_value_;
    }
    virtual size_t set_exponent_bits(const size_t& to) {
        exponent_bits_ = to;
        return exponent_bits_;
    }
    virtual size_t exponent_bits() const {
        return exponent_bits_;
    }

    /// ...
    virtual byte_array_t &exponent() const {
        return (byte_array_t&)exponent_;
    }
    virtual byte_array_t &modulus() const {
        return (byte_array_t&)modulus_;
    }
    virtual byte_array_t &p() const {
        return (byte_array_t&)p_;
    }
    virtual byte_array_t &q() const {
        return (byte_array_t&)q_;
    }
    virtual byte_array_t &dmp1() const {
        return (byte_array_t&)dmp1_;
    }
    virtual byte_array_t &dmq1() const {
        return (byte_array_t&)dmq1_;
    }
    virtual byte_array_t &iqmp() const {
        return (byte_array_t&)iqmp_;
    }

protected:
    string_t key_pair_define_, public_key_define_, private_key_define_; 
    size_t exponent_bits_;
    uint32_t exponent_value_;
    byte_array_t exponent_, modulus_, p_, q_, dmp1_, dmq1_, iqmp_;
}; /// class main_optt
typedef main_optt<> main_opt;

} /// namespace pair
} /// namespace rsa
} /// namespace crypto
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_CRYPTO_RSA_PAIR_MAIN_OPT_HPP
