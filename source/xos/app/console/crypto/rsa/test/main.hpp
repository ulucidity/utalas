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
///   File: main.hpp
///
/// Author: $author$
///   Date: 5/31/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_CRYPTO_RSA_TEST_MAIN_HPP
#define XOS_APP_CONSOLE_CRYPTO_RSA_TEST_MAIN_HPP

#include "xos/app/console/crypto/rsa/test/main_opt.hpp"

namespace xos {
namespace app {
namespace console {
namespace crypto {
namespace rsa {
namespace test {

/// class maint
template 
<class TExtends = xos::app::console::crypto::rsa::test::main_opt, 
 class TImplements = typename TExtends::implements>

class exported maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef maint derives;

    typedef typename extends::char_t char_t;
    typedef typename extends::end_char_t end_char_t;
    enum { end_char = extends::end_char };
    typedef typename extends::string_t string_t;
    typedef typename extends::reader_t reader_t;
    typedef typename extends::writer_t writer_t;
    typedef typename extends::file_t file_t;

    /// constructor / destructor
    maint(): run_(0) {
    }
    virtual ~maint() {
    }
private:
    maint(const maint& copy) {
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

    /// ...rsa_public_cipher_run
    ///
    /// ...test_key_pair_run
    /// ...
    /// bn_test_key_pair_run
    virtual int bn_test_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t modulus_length = 0, exponent_length = 0;
        const byte_t *modulus = 0, *exponent = 0;

        if ((modulus = this->get_modulus(modulus_length)) && (modulus_length) 
            && (exponent = this->get_exponent(exponent_length)) && (exponent_length)) {
            size_t p_length = 0;
            const byte_t *p = 0, *q = 0, *dmp1 = 0, *dmq1 = 0, *iqmp = 0;
            
            xos::crypto::rsa::bn::public_key pub(modulus, modulus_length,exponent, exponent_length);
            if ((p = this->get_p(q, dmp1, dmq1, iqmp, p_length)) && (p_length)) {

                xos::crypto::rsa::bn::private_key prv(p, q, dmp1, dmq1, iqmp, p_length);
                err = test_key_pair_run(pub, prv, argc, argv, env);
            }
        }
        return err;
    }
    /// ...gmp_test_key_pair_run
    virtual int gmp_test_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t modulus_length = 0, exponent_length = 0;
        const byte_t *modulus = 0, *exponent = 0;

        if ((modulus = this->get_modulus(modulus_length)) && (modulus_length) 
            && (exponent = this->get_exponent(exponent_length)) && (exponent_length)) {
            size_t p_length = 0;
            const byte_t *p = 0, *q = 0, *dmp1 = 0, *dmq1 = 0, *iqmp = 0;
            
            xos::crypto::rsa::mp::public_key pub(modulus, modulus_length,exponent, exponent_length);
            if ((p = this->get_p(q, dmp1, dmq1, iqmp, p_length)) && (p_length)) {

                xos::crypto::rsa::mp::private_key prv(p, q, dmp1, dmq1, iqmp, p_length);
                err = test_key_pair_run(pub, prv, argc, argv, env);
            }
        }
        return err;
    }
    /// test_key_pair_run
    template <typename rsa_public_key_t, typename rsa_private_key_t>
    int test_key_pair_run(rsa_public_key_t& pub, rsa_private_key_t& prv, int argc, char_t** argv, char_t** env) {
        int err = 0;
        ssize_t size = 0, modbytes = pub.modbytes();

        if ((modbytes >= this->modbytes_min) && (modbytes <= this->modbytes_max)) {
            size_t sizeof_plain = 0;
            byte_t *plain = &this->rsa_plain(sizeof_plain);
            
            if ((size = this->random_plain(plain, modbytes))) {
                size_t sizeof_cipher = 0;
                byte_t *cipher = &this->rsa_cipher(sizeof_cipher);

                this->out("plain = ");
                this->outx(plain, modbytes);
                this->outln();
                this->outln();

                if (modbytes == (size = pub(cipher, sizeof_cipher, plain, modbytes))) {
                    size_t sizeof_decipher = 0;
                    byte_t *decipher = &this->rsa_decipher(sizeof_decipher);
    
                    this->out("cipher = ");
                    this->outx(cipher, size);
                    this->outln();
                    this->outln();

                    if (modbytes == (size = prv(decipher, sizeof_decipher, cipher, size))) {
                        this->out("decipher = ");
                        this->outx(decipher, size);
                        this->outln();
                        this->outln();

                        this->out("public <--> private ");
                        if (!(::memcmp(plain, decipher, size))) {
                            this->outln("success");
                        } else {
                            this->outln("failure");
                        }
                        this->outln();
                    } else {
                    }
                } else {
                }
                if (modbytes == (size = prv(cipher, sizeof_cipher, plain, modbytes))) {
                    size_t sizeof_decipher = 0;
                    byte_t *decipher = &this->rsa_decipher(sizeof_decipher);
    
                    this->out("cipher = ");
                    this->outx(cipher, size);
                    this->outln();
                    this->outln();

                    if (modbytes == (size = pub(decipher, sizeof_decipher, cipher, size))) {
                        this->out("decipher = ");
                        this->outx(decipher, size);
                        this->outln();
                        this->outln();

                        this->out("private <--> public ");
                        if (!(::memcmp(plain, decipher, size))) {
                            this->outln("success");
                        } else {
                            this->outln("failure");
                        }
                        this->outln();
                    } else {
                    }
                } else {
                }
            } else {
            }
        } else {
        }
        return err;
    }
    /// ...
    /// ...test_key_pair_run
    /// 

protected:
}; /// class maint
typedef maint<> main;

} /// namespace test
} /// namespace rsa
} /// namespace crypto
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_CRYPTO_RSA_TEST_MAIN_HPP
