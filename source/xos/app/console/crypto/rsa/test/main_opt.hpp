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
///   Date: 5/31/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_CRYPTO_RSA_TEST_MAIN_OPT_HPP
#define XOS_APP_CONSOLE_CRYPTO_RSA_TEST_MAIN_OPT_HPP

#include "xos/app/console/crypto/rsa/operate/main.hpp"

#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_TEST_OPT "test"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_TEST_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_TEST_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_TEST_OPTARG ""
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_TEST_OPTUSE "test RSA key pair"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_TEST_OPTVAL_S "t"
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_TEST_OPTVAL_C 't'
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_TEST_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_TEST_OPT, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_TEST_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_TEST_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_TEST_OPTVAL_C}, \

#define XOS_APP_CONSOLE_CRYPTO_RSA_TEST_MAIN_OPTIONS_CHARS_EXTEND \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_TEST_OPTVAL_S \

#define XOS_APP_CONSOLE_CRYPTO_RSA_TEST_MAIN_OPTIONS_OPTIONS_EXTEND \
    XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_TEST_OPTION \

#define XOS_APP_CONSOLE_CRYPTO_RSA_TEST_MAIN_OPTIONS_CHARS \
   XOS_APP_CONSOLE_CRYPTO_RSA_TEST_MAIN_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_CRYPTO_RSA_OPERATE_MAIN_OPTIONS_CHARS

#define XOS_APP_CONSOLE_CRYPTO_RSA_TEST_MAIN_OPTIONS_OPTIONS \
   XOS_APP_CONSOLE_CRYPTO_RSA_TEST_MAIN_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_CRYPTO_RSA_OPERATE_MAIN_OPTIONS_OPTIONS

#define XOS_APP_CONSOLE_CRYPTO_RSA_TEST_MAIN_ARGS 0
#define XOS_APP_CONSOLE_CRYPTO_RSA_TEST_MAIN_ARGV 0,

namespace xos {
namespace app {
namespace console {
namespace crypto {
namespace rsa {
namespace test {

/// class main_optt
template 
<class TExtends = xos::app::console::crypto::rsa::operate::main, 
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
    /// ...test_key_pair_run
    /// ...
    /// test_key_pair_run
    int (derives::*test_key_pair_run_)(int argc, char_t** argv, char_t** env);
    virtual int test_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (test_key_pair_run_) {
            err = (this->*test_key_pair_run_)(argc, argv, env);
        } else {
            err = default_test_key_pair_run(argc, argv, env);
        }
        return err;
    }
    virtual int default_test_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        err = all_bn_test_key_pair_run(argc, argv, env);
        return err;
    }
    virtual int before_test_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_test_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_test_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_test_key_pair_run(argc, argv, env))) {
            int err2 = 0;
            err = test_key_pair_run(argc, argv, env);
            if ((err2 = after_test_key_pair_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_test_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_test_key_pair_run;
        return err;
    }
    /// ...bn_test_key_pair_run
    virtual int bn_test_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_bn_test_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_bn_test_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_bn_test_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_bn_test_key_pair_run(argc, argv, env))) {
            int err2 = 0;
            err = bn_test_key_pair_run(argc, argv, env);
            if ((err2 = after_bn_test_key_pair_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_bn_test_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        test_key_pair_run_ = &derives::all_bn_test_key_pair_run;
        return err;
    }
    /// ...gmp_test_key_pair_run
    virtual int gmp_test_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_gmp_test_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_gmp_test_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_gmp_test_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_gmp_test_key_pair_run(argc, argv, env))) {
            int err2 = 0;
            err = gmp_test_key_pair_run(argc, argv, env);
            if ((err2 = after_gmp_test_key_pair_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_gmp_test_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        test_key_pair_run_ = &derives::all_gmp_test_key_pair_run;
        return err;
    }
    /// ...
    /// ...test_key_pair_run
    /// 

    /// 
    /// on_set...integer_option...
    /// ...
    virtual int on_set_bn_integer_option(int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_bn_test_key_pair_run(argc, argv, env))) {
            if (!(err = extends::on_set_bn_integer_option(argc, argv, env))) {
            }
        }
        return err;
    }
    virtual int on_set_gmp_integer_option(int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_gmp_test_key_pair_run(argc, argv, env))) {
            if (!(err = extends::on_set_gmp_integer_option(argc, argv, env))) {
            }
        }
        return err;
    }
    /// ...
    /// on_set...integer_option...
    /// 

    /// ...option...
    virtual int on_test_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_test_key_pair_run(argc, argv, env))) {
        }
        return err;
    }
    virtual const char_t* test_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_TEST_OPTUSE;
        optarg = XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_TEST_OPTARG;
        return chars;
    }

    /// ...option...
    virtual int on_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        switch(optval) {

        case XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_TEST_OPTVAL_C:
            err = this->on_test_option(optval, optarg, optname, optind, argc, argv, env);
            break;

        default:
            err = extends::on_option(optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    virtual const char_t* option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = "";
        switch(longopt->val) {

        case XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_TEST_OPTVAL_C:
            chars = this->test_option_usage(optarg, longopt);
            break;

        default:
            chars = extends::option_usage(optarg, longopt);
            break;
        }
        return chars;
    }
    virtual const char_t* options(const struct option*& longopts) {
        static const char_t* chars = XOS_APP_CONSOLE_CRYPTO_RSA_TEST_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            XOS_APP_CONSOLE_CRYPTO_RSA_TEST_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

    /// ...argument...
    virtual const char_t* arguments(const char_t**& argv) {
        static const char_t* _args = XOS_APP_CONSOLE_CRYPTO_RSA_TEST_MAIN_ARGS;
        static const char_t* _argv[] = {
            XOS_APP_CONSOLE_CRYPTO_RSA_TEST_MAIN_ARGV
            0};
        argv = _argv;
        return _args;
    }

protected:
}; /// class main_optt
typedef main_optt<> main_opt;

} /// namespace test
} /// namespace rsa
} /// namespace crypto
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_CRYPTO_RSA_TEST_MAIN_OPT_HPP
