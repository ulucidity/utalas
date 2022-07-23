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
///   Date: 5/30/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_CRYPTO_RSA_OPERATE_MAIN_OPT_HPP
#define XOS_APP_CONSOLE_CRYPTO_RSA_OPERATE_MAIN_OPT_HPP

#include "xos/app/console/crypto/rsa/pair/main.hpp"

#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PLAIN_TEXT_OPT "plain"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PLAIN_TEXT_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PLAIN_TEXT_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PLAIN_TEXT_OPTARG "[string]"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PLAIN_TEXT_OPTUSE "plain text to encrypt"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PLAIN_TEXT_OPTVAL_S "p::"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PLAIN_TEXT_OPTVAL_C 'p'
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PLAIN_TEXT_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PLAIN_TEXT_OPT, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PLAIN_TEXT_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PLAIN_TEXT_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PLAIN_TEXT_OPTVAL_C}, \

#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_CIPHER_TEXT_OPT "cipher"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_CIPHER_TEXT_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_CIPHER_TEXT_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_CIPHER_TEXT_OPTARG "[string]"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_CIPHER_TEXT_OPTUSE "cipher text to decrypt"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_CIPHER_TEXT_OPTVAL_S "c::"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_CIPHER_TEXT_OPTVAL_C 'c'
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_CIPHER_TEXT_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_CIPHER_TEXT_OPT, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_CIPHER_TEXT_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_CIPHER_TEXT_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_CIPHER_TEXT_OPTVAL_C}, \

#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_ENCRYPT_OPT "encrypt"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_ENCRYPT_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_ENCRYPT_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_ENCRYPT_OPTARG ""
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_ENCRYPT_OPTUSE "RSA public encrypt/decrypt"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_ENCRYPT_OPTVAL_S "e"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_ENCRYPT_OPTVAL_C 'e'
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_ENCRYPT_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_ENCRYPT_OPT, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_ENCRYPT_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_ENCRYPT_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_ENCRYPT_OPTVAL_C}, \

#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_DECRYPT_OPT "decrypt"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_DECRYPT_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_DECRYPT_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_DECRYPT_OPTARG ""
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_DECRYPT_OPTUSE "RSA private decrypt/encrypt"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_DECRYPT_OPTVAL_S "d"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_DECRYPT_OPTVAL_C 'd'
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_DECRYPT_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_DECRYPT_OPT, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_DECRYPT_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_DECRYPT_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_DECRYPT_OPTVAL_C}, \

#define XOS_APP_CONSOLE_CRYPTO_RSA_OPERATE_MAIN_OPTIONS_CHARS_EXTEND \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_ENCRYPT_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_DECRYPT_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PLAIN_TEXT_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_CIPHER_TEXT_OPTVAL_S \

#define XOS_APP_CONSOLE_CRYPTO_RSA_OPERATE_MAIN_OPTIONS_OPTIONS_EXTEND \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_ENCRYPT_OPTION \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_DECRYPT_OPTION \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PLAIN_TEXT_OPTION \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_CIPHER_TEXT_OPTION \

#define XOS_APP_CONSOLE_CRYPTO_RSA_OPERATE_MAIN_OPTIONS_CHARS \
   XOS_APP_CONSOLE_CRYPTO_RSA_OPERATE_MAIN_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_CRYPTO_RSA_PAIR_MAIN_OPTIONS_CHARS

#define XOS_APP_CONSOLE_CRYPTO_RSA_OPERATE_MAIN_OPTIONS_OPTIONS \
   XOS_APP_CONSOLE_CRYPTO_RSA_OPERATE_MAIN_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_CRYPTO_RSA_PAIR_MAIN_OPTIONS_OPTIONS

#define XOS_APP_CONSOLE_CRYPTO_RSA_OPERATE_MAIN_ARGS 0
#define XOS_APP_CONSOLE_CRYPTO_RSA_OPERATE_MAIN_ARGV 0,

namespace xos {
namespace app {
namespace console {
namespace crypto {
namespace rsa {
namespace operate {

/// class main_optt
template 
<class TExtends = xos::app::console::crypto::rsa::pair::main, 
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
    main_optt(): run_(0) {
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
    /// ...rsa_public_encrypt_run
    /// ...
    int (derives::*rsa_public_encrypt_run_)(int argc, char_t** argv, char_t** env);
    virtual int rsa_public_encrypt_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (rsa_public_encrypt_run_) {
            err = (this->*rsa_public_encrypt_run_)(argc, argv, env);
        } else {
            err = bn_rsa_public_encrypt_run(argc, argv, env);
        }
        return err;
    }
    virtual int bn_rsa_public_encrypt_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int set_bn_rsa_public_encrypt_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        rsa_public_encrypt_run_ = &derives::bn_rsa_public_encrypt_run;
        return err;
    }
    virtual int gmp_rsa_public_encrypt_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int set_gmp_rsa_public_encrypt_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        rsa_public_encrypt_run_ = &derives::gmp_rsa_public_encrypt_run;
        return err;
    }
    virtual int before_rsa_public_encrypt_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_rsa_public_encrypt_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_rsa_public_encrypt_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_rsa_public_encrypt_run(argc, argv, env))) {
            int err2 = 0;
            err = rsa_public_encrypt_run(argc, argv, env);
            if ((err2 = after_rsa_public_encrypt_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_rsa_public_encrypt_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_rsa_public_encrypt_run;
        return err;
    }
    /// ...
    /// ...rsa_public_encrypt_run
    /// 

    ///
    /// ...rsa_private_decrypt_run
    /// ...
    int (derives::*rsa_private_decrypt_run_)(int argc, char_t** argv, char_t** env);
    virtual int rsa_private_decrypt_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (rsa_private_decrypt_run_) {
            err = (this->*rsa_private_decrypt_run_)(argc, argv, env);
        } else {
            err = bn_rsa_private_decrypt_run(argc, argv, env);
        }
        return err;
    }
    virtual int bn_rsa_private_decrypt_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int set_bn_rsa_private_decrypt_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        rsa_private_decrypt_run_ = &derives::bn_rsa_private_decrypt_run;
        return err;
    }
    virtual int gmp_rsa_private_decrypt_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int set_gmp_rsa_private_decrypt_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        rsa_private_decrypt_run_ = &derives::gmp_rsa_private_decrypt_run;
        return err;
    }
    virtual int before_rsa_private_decrypt_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_rsa_private_decrypt_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_rsa_private_decrypt_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_rsa_private_decrypt_run(argc, argv, env))) {
            int err2 = 0;
            err = rsa_private_decrypt_run(argc, argv, env);
            if ((err2 = after_rsa_private_decrypt_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_rsa_private_decrypt_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_rsa_private_decrypt_run;
        return err;
    }
    /// ...
    /// ...rsa_private_decrypt_run
    /// 

    ///
    /// ...output_rsa_plain_run
    /// ...
    int (derives::*output_rsa_plain_run_)(int argc, char_t** argv, char_t** env);
    virtual int output_rsa_plain_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (output_rsa_plain_run_) {
            err = (this->*output_rsa_plain_run_)(argc, argv, env);
        } else {
            err = default_output_rsa_plain_run(argc, argv, env);
        }
        return err;
    }
    virtual int default_output_rsa_plain_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        err = all_output_test_rsa_plain_run(argc, argv, env);
        return err;
    }
    virtual int before_output_rsa_plain_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_output_rsa_plain_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_output_rsa_plain_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_output_rsa_plain_run(argc, argv, env))) {
            int err2 = 0;
            err = output_rsa_plain_run(argc, argv, env);
            if ((err2 = after_output_rsa_plain_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_output_rsa_plain_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_output_rsa_plain_run;
        return err;
    }
    /// ...output_get_rsa_plain_run
     int (derives::*output_get_rsa_plain_run_)(int argc, char_t** argv, char_t** env);
     virtual int output_get_rsa_plain_run(int argc, char_t** argv, char_t** env) {
         int err = 0;
         if (output_get_rsa_plain_run_) {
             err = (this->*output_get_rsa_plain_run_)(argc, argv, env);
         } else {
             err = default_output_get_rsa_plain_run(argc, argv, env);
         }
         return err;
     }
     virtual int default_output_get_rsa_plain_run(int argc, char_t** argv, char_t** env) {
         int err = 0;
         /// err = extends::run(argc, argv, env);
         return err;
     }
     virtual int before_output_get_rsa_plain_run(int argc, char_t** argv, char_t** env) {
         int err = 0;
         return err;
     }
     virtual int after_output_get_rsa_plain_run(int argc, char_t** argv, char_t** env) {
         int err = 0;
         return err;
     }
     virtual int all_output_get_rsa_plain_run(int argc, char_t** argv, char_t** env) {
         int err = 0;
         if (!(err = before_output_get_rsa_plain_run(argc, argv, env))) {
             int err2 = 0;
             err = output_get_rsa_plain_run(argc, argv, env);
             if ((err2 = after_output_get_rsa_plain_run(argc, argv, env))) {
                 if (!(err)) err = err2;
             }
         }
         return err;
     }
     virtual int set_output_get_rsa_plain_run(int argc, char_t** argv, char_t** env) {
         int err = 0;
         output_rsa_plain_run_ = &derives::all_output_get_rsa_plain_run;
         return err;
     }
    /// ...output_test_rsa_plain_run
    int (derives::*output_test_rsa_plain_run_)(int argc, char_t** argv, char_t** env);
    virtual int output_test_rsa_plain_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (output_test_rsa_plain_run_) {
            err = (this->*output_test_rsa_plain_run_)(argc, argv, env);
        } else {
            err = default_output_test_rsa_plain_run(argc, argv, env);
        }
        return err;
    }
    virtual int default_output_test_rsa_plain_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        /// err = extends::run(argc, argv, env);
        return err;
    }
    virtual int before_output_test_rsa_plain_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_output_test_rsa_plain_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_output_test_rsa_plain_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_output_test_rsa_plain_run(argc, argv, env))) {
            int err2 = 0;
            err = output_test_rsa_plain_run(argc, argv, env);
            if ((err2 = after_output_test_rsa_plain_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_output_test_rsa_plain_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        output_rsa_plain_run_ = &derives::all_output_test_rsa_plain_run;
        return err;
    }
    /// ...
    /// ...output...rsa_plain_run
    /// 

    ///
    /// ...output_rsa_cipher_run
    /// ...
    int (derives::*output_rsa_cipher_run_)(int argc, char_t** argv, char_t** env);
    virtual int output_rsa_cipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (output_rsa_cipher_run_) {
            err = (this->*output_rsa_cipher_run_)(argc, argv, env);
        } else {
            err = default_output_rsa_cipher_run(argc, argv, env);
        }
        return err;
    }
    virtual int default_output_rsa_cipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        err = all_output_test_rsa_cipher_run(argc, argv, env);
        return err;
    }
    virtual int before_output_rsa_cipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_output_rsa_cipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_output_rsa_cipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_output_rsa_cipher_run(argc, argv, env))) {
            int err2 = 0;
            err = output_rsa_cipher_run(argc, argv, env);
            if ((err2 = after_output_rsa_cipher_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_output_rsa_cipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_output_rsa_cipher_run;
        return err;
    }
    /// ...output_get_rsa_cipher_run
     int (derives::*output_get_rsa_cipher_run_)(int argc, char_t** argv, char_t** env);
     virtual int output_get_rsa_cipher_run(int argc, char_t** argv, char_t** env) {
         int err = 0;
         if (output_get_rsa_cipher_run_) {
             err = (this->*output_get_rsa_cipher_run_)(argc, argv, env);
         } else {
             err = default_output_get_rsa_cipher_run(argc, argv, env);
         }
         return err;
     }
     virtual int default_output_get_rsa_cipher_run(int argc, char_t** argv, char_t** env) {
         int err = 0;
         /// err = extends::run(argc, argv, env);
         return err;
     }
     virtual int before_output_get_rsa_cipher_run(int argc, char_t** argv, char_t** env) {
         int err = 0;
         return err;
     }
     virtual int after_output_get_rsa_cipher_run(int argc, char_t** argv, char_t** env) {
         int err = 0;
         return err;
     }
     virtual int all_output_get_rsa_cipher_run(int argc, char_t** argv, char_t** env) {
         int err = 0;
         if (!(err = before_output_get_rsa_cipher_run(argc, argv, env))) {
             int err2 = 0;
             err = output_get_rsa_cipher_run(argc, argv, env);
             if ((err2 = after_output_get_rsa_cipher_run(argc, argv, env))) {
                 if (!(err)) err = err2;
             }
         }
         return err;
     }
     virtual int set_output_get_rsa_cipher_run(int argc, char_t** argv, char_t** env) {
         int err = 0;
         output_rsa_cipher_run_ = &derives::all_output_get_rsa_cipher_run;
         return err;
     }
    /// ...output_test_rsa_cipher_run
    int (derives::*output_test_rsa_cipher_run_)(int argc, char_t** argv, char_t** env);
    virtual int output_test_rsa_cipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (output_test_rsa_cipher_run_) {
            err = (this->*output_test_rsa_cipher_run_)(argc, argv, env);
        } else {
            err = default_output_test_rsa_cipher_run(argc, argv, env);
        }
        return err;
    }
    virtual int default_output_test_rsa_cipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        /// err = extends::run(argc, argv, env);
        return err;
    }
    virtual int before_output_test_rsa_cipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_output_test_rsa_cipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_output_test_rsa_cipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_output_test_rsa_cipher_run(argc, argv, env))) {
            int err2 = 0;
            err = output_test_rsa_cipher_run(argc, argv, env);
            if ((err2 = after_output_test_rsa_cipher_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_output_test_rsa_cipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        output_rsa_cipher_run_ = &derives::all_output_test_rsa_cipher_run;
        return err;
    }
    /// ...
    /// ...output...rsa_cipher_run
    /// 

    /// 
    /// on_set...integer_option...
    /// ...
    virtual int on_set_bn_integer_option(int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_bn_rsa_public_encrypt_run(argc, argv, env))) {
            if (!(err = set_bn_rsa_private_decrypt_run(argc, argv, env))) {
                if (!(err = extends::on_set_bn_integer_option(argc, argv, env))) {
                }
            }
        }
        return err;
    }
    virtual int on_set_gmp_integer_option(int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_gmp_rsa_public_encrypt_run(argc, argv, env))) {
            if (!(err = set_gmp_rsa_private_decrypt_run(argc, argv, env))) {
                if (!(err = extends::on_set_gmp_integer_option(argc, argv, env))) {
                }
            }
        }
        return err;
    }
    /// ...
    /// on_set...integer_option...
    /// 

    /// ...on...option...
    virtual int on_encrypt_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_rsa_public_encrypt_run(argc, argv, env))) {
        }
        return err;
    }
    virtual const char_t* encrypt_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_ENCRYPT_OPTUSE;
        optarg = XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_ENCRYPT_OPTARG;
        return chars;
    }
    virtual int on_decrypt_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_rsa_private_decrypt_run(argc, argv, env))) {
        }
        return err;
    }
    virtual const char_t* decrypt_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_DECRYPT_OPTUSE;
        optarg = XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_DECRYPT_OPTARG;
        return chars;
    }

    /// ...on...text_option...
    virtual int on_set_rsa_plain_literal(const char_t* literal, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_plain_text_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_rsa_plain_literal(optarg, argc, argv, env))) {
                if (!(err = set_output_rsa_plain_run(argc, argv, env))) {
                }
            }
        } else {
            if (!(err = set_output_rsa_plain_run(argc, argv, env))) {
            }
        }
        return err;
    }
    virtual const char_t* plain_text_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PLAIN_TEXT_OPTUSE;
        optarg = XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PLAIN_TEXT_OPTARG;
        return chars;
    }
    virtual int on_set_rsa_cipher_literal(const char_t* literal, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_cipher_text_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_rsa_cipher_literal(optarg, argc, argv, env))) {
                if (!(err = set_output_rsa_cipher_run(argc, argv, env))) {
                }
            }
        } else {
            if (!(err = set_output_rsa_cipher_run(argc, argv, env))) {
            }
        }
        return err;
    }
    virtual const char_t* cipher_text_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_CIPHER_TEXT_OPTUSE;
        optarg = XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_CIPHER_TEXT_OPTARG;
        return chars;
    }

    /// ...option...
    virtual int on_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        switch(optval) {

        case XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_ENCRYPT_OPTVAL_C:
            err = this->on_encrypt_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_DECRYPT_OPTVAL_C:
            err = this->on_decrypt_option(optval, optarg, optname, optind, argc, argv, env);
            break;

        case XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PLAIN_TEXT_OPTVAL_C:
            err = this->on_plain_text_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_CIPHER_TEXT_OPTVAL_C:
            err = this->on_cipher_text_option(optval, optarg, optname, optind, argc, argv, env);
            break;

        default:
            err = extends::on_option(optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    virtual const char_t* option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = "";
        switch(longopt->val) {

        case XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_ENCRYPT_OPTVAL_C:
            chars = this->encrypt_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_DECRYPT_OPTVAL_C:
            chars = this->decrypt_option_usage(optarg, longopt);
            break;

        case XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_PLAIN_TEXT_OPTVAL_C:
            chars = this->plain_text_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_CIPHER_TEXT_OPTVAL_C:
            chars = this->cipher_text_option_usage(optarg, longopt);
            break;

        default:
            chars = extends::option_usage(optarg, longopt);
            break;
        }
        return chars;
    }
    virtual const char_t* options(const struct option*& longopts) {
        static const char_t* chars = XOS_APP_CONSOLE_CRYPTO_RSA_OPERATE_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            XOS_APP_CONSOLE_CRYPTO_RSA_OPERATE_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

    /// ...argument...
    virtual const char_t* arguments(const char_t**& argv) {
        static const char_t* _args = XOS_APP_CONSOLE_CRYPTO_RSA_OPERATE_MAIN_ARGS;
        static const char_t* _argv[] = {
            XOS_APP_CONSOLE_CRYPTO_RSA_OPERATE_MAIN_ARGV
            0};
        argv = _argv;
        return _args;
    }

    /// ...get_rsa...
    const byte_t* (derives::*get_rsa_plain_)(size_t &length);
    virtual const byte_t* get_rsa_plain(size_t &length) {
        const byte_t* bytes = 0;
        if (get_rsa_plain_) {
            bytes = (this->*get_rsa_plain_)(length);
        } else {
            bytes = get_test_rsa_plain(length);
        }
        return bytes;
    }
    virtual const byte_t* get_test_rsa_plain(size_t &length) {
        const byte_t *bytes = 0, *modulus = 0;
        size_t modbytes = 0;

        if ((modulus = this->get_modulus(modbytes)) && (modbytes)
            && (modbytes >= this->modbytes_min) && (modbytes <= this->modbytes_max)) {
            size_t size = 0, sizeof_plain = 0;
            byte_t *plain = &this->rsa_random(sizeof_plain);
            
            if ((modbytes == (size = this->random_plain(plain, modbytes)))) {
                length = size;
                bytes = plain;
            }
        }
        return bytes;
    }
    virtual const byte_t* get_literal_rsa_plain(size_t &length) {
        const byte_t* bytes = 0;
        length = this->rsa_plain_array().length();
        bytes = this->rsa_plain_array().elements();
        return bytes;
    }
    virtual int set_get_test_rsa_plain(int argc, char_t** argv, char_t** env) {
        int err = 0;
        get_rsa_plain_ = &derives::get_test_rsa_plain;
        return err;
    }
    virtual int set_get_literal_rsa_plain(int argc, char_t** argv, char_t** env) {
        int err = 0;
        get_rsa_plain_ = &derives::get_literal_rsa_plain;
        return err;
    }
    const byte_t* (derives::*get_rsa_cipher_)(size_t &length);
    virtual const byte_t* get_rsa_cipher(size_t &length) {
        const byte_t* bytes = 0;
        if (get_rsa_cipher_) {
            bytes = (this->*get_rsa_cipher_)(length);
        } else {
            bytes = get_test_rsa_cipher(length);
        }
        return bytes;
    }
    virtual const byte_t* get_test_rsa_cipher(size_t &length) {
        const byte_t *bytes = 0, *modulus = 0;
        size_t modbytes = 0;

        if ((modulus = this->get_modulus(modbytes)) && (modbytes)
            && (modbytes >= this->modbytes_min) && (modbytes <= this->modbytes_max)) {
            size_t size = 0, sizeof_cipher = 0;
            byte_t *cipher = &this->rsa_random(sizeof_cipher);
            
            if (modbytes == (size = this->random(cipher, modbytes))) {
                length = size;
                bytes = cipher;
            }
        }
        return bytes;;
    }
    virtual const byte_t* get_literal_rsa_cipher(size_t &length) {
        const byte_t* bytes = 0;
        length = this->rsa_cipher_array().length();
        bytes = this->rsa_cipher_array().elements();
        return bytes;;
    }
    virtual int set_get_test_rsa_cipher(int argc, char_t** argv, char_t** env) {
        int err = 0;
        get_rsa_cipher_ = &derives::get_test_rsa_cipher;
        return err;
    }
    virtual int set_get_literal_rsa_cipher(int argc, char_t** argv, char_t** env) {
        int err = 0;
        get_rsa_cipher_ = &derives::get_literal_rsa_cipher;
        return err;
    }

    /// random...
    virtual size_t random_plain(unsigned char *buff, size_t len) const {
        size_t size = 0;

        if ((buff) && (len)) {

            if (len == (size = random(buff, len))) {
                buff[0] &= 0x7F;
            }
        }
        return size;
    }
    virtual size_t random(unsigned char *buff, size_t len) const {
        static unsigned randnum = 0;
        static unsigned avail = 0;
        size_t size = 0;
        
        if ((buff) && (len)) {
            for (size = 0; size < len;) {
                if (avail < 1) {
                    randnum = (unsigned)rand();
                    avail = sizeof(randnum);
                }
                if (0 != (buff[size] = ((char)(randnum & 0xFF)))) {
                    ++size;
                }
                if ((randnum >>= 8) < 1) {
                    avail = 0;
                } else {
                    --avail;
                }
            }
        }
        return size;
    }

    /// ....
    virtual byte_array_t &rsa_plain_array() const {
        return (byte_array_t&)rsa_plain_array_;
    }
    virtual byte_array_t &rsa_cipher_array() const {
        return (byte_array_t&)rsa_cipher_array_;
    }

protected:
    byte_array_t rsa_plain_array_, rsa_cipher_array_;
}; /// class main_optt
typedef main_optt<> main_opt;

} /// namespace operate
} /// namespace rsa
} /// namespace crypto
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_CRYPTO_RSA_OPERATE_MAIN_OPT_HPP
