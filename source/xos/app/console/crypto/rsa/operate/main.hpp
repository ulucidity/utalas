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
///   Date: 5/30/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_CRYPTO_RSA_OPERATE_MAIN_HPP
#define XOS_APP_CONSOLE_CRYPTO_RSA_OPERATE_MAIN_HPP

#include "xos/app/console/crypto/rsa/operate/main_opt.hpp"

namespace xos {
namespace app {
namespace console {
namespace crypto {
namespace rsa {
namespace operate {

/// class maint
template 
<class TExtends = xos::app::console::crypto::rsa::operate::main_opt, 
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

    ///
    /// ...rsa_public_...encrypt_run
    /// ...
    virtual int bn_rsa_public_encrypt_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t modulus_length = 0, exponent_length = 0;
        const byte_t *modulus = 0, *exponent = 0;

        if ((modulus = this->get_modulus(modulus_length)) && (modulus_length) 
            && (exponent = this->get_exponent(exponent_length)) && (exponent_length)) {
            xos::crypto::rsa::bn::public_key pub(modulus, modulus_length,exponent, exponent_length);

            err = rsa_public_encrypt_run(pub, argc, argv, env);
        }
        return err;
    }
    virtual int gmp_rsa_public_encrypt_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t modulus_length = 0, exponent_length = 0;
        const byte_t *modulus = 0, *exponent = 0;

        if ((modulus = this->get_modulus(modulus_length)) && (modulus_length) 
            && (exponent = this->get_exponent(exponent_length)) && (exponent_length)) {
            xos::crypto::rsa::mp::public_key pub(modulus, modulus_length,exponent, exponent_length);

            err = rsa_public_encrypt_run(pub, argc, argv, env);
        }
        return err;
    }
    template <typename rsa_public_key_t>
    int rsa_public_encrypt_run(rsa_public_key_t& pub, int argc, char_t** argv, char_t** env) {
        int err = 0;
        ssize_t size = 0, modbytes = pub.modbytes();

        if ((modbytes >= this->modbytes_min) && (modbytes <= this->modbytes_max)) {
            size_t sizeof_plain = 0, plain_length = 0;
            const byte_t *plain_bytes = 0;
            byte_t *plain = &this->rsa_plain(sizeof_plain);

            if ((plain_bytes = this->get_rsa_plain(plain_length)) && (plain_length)) {
                size_t sizeof_encipher = 0, sizeof_decipher = 0;
                byte_t *encipher = &this->rsa_encipher(sizeof_encipher), 
                       *decipher = &this->rsa_decipher(sizeof_decipher);

                if ((modbytes > plain_length)) {
                    size_t length = length = (modbytes - plain_length);
                    ::memcpy(decipher, plain_bytes, plain_length);
                    ::memset(decipher + plain_length, 0, length);
                } else {
                    ::memcpy(decipher, plain_bytes, modbytes);
                }
                this->output_hex_verbose_sized("plain", decipher, modbytes);
                if (modbytes == (size = pub(encipher, sizeof_encipher, decipher, modbytes))) {
                    this->output_hex_verbage_sized("cipher", encipher, size);
                }
            }
        }
        return err;
    }
    /// ...
    /// ...rsa_public_...encrypt_run
    /// 

    ///
    /// ...rsa_public_...decrypt_run
    /// ...
    virtual int bn_rsa_public_decrypt_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t modulus_length = 0, exponent_length = 0;
        const byte_t *modulus = 0, *exponent = 0;

        if ((modulus = this->get_modulus(modulus_length)) && (modulus_length) 
            && (exponent = this->get_exponent(exponent_length)) && (exponent_length)) {
            xos::crypto::rsa::bn::public_key pub(modulus, modulus_length,exponent, exponent_length);

            err = rsa_public_decrypt_run(pub, argc, argv, env);
        }
        return err;
    }
    virtual int gmp_rsa_public_decrypt_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t modulus_length = 0, exponent_length = 0;
        const byte_t *modulus = 0, *exponent = 0;

        if ((modulus = this->get_modulus(modulus_length)) && (modulus_length) 
            && (exponent = this->get_exponent(exponent_length)) && (exponent_length)) {
            xos::crypto::rsa::mp::public_key pub(modulus, modulus_length,exponent, exponent_length);

            err = rsa_public_decrypt_run(pub, argc, argv, env);
        }
        return err;
    }
    template <typename rsa_public_key_t>
    int rsa_public_decrypt_run(rsa_public_key_t& pub, int argc, char_t** argv, char_t** env) {
        int err = 0;
        ssize_t size = 0, modbytes = pub.modbytes();

        if ((modbytes >= this->modbytes_min) && (modbytes <= this->modbytes_max)) {
            size_t sizeof_cipher = 0, cipher_length = 0;
            const byte_t *cipher_bytes = 0;
            byte_t *cipher = &this->rsa_cipher(sizeof_cipher);

            if ((cipher_bytes = this->get_rsa_cipher(cipher_length)) && (cipher_length)) {
                size_t sizeof_decipher = 0, sizeof_encipher = 0;
                byte_t *decipher = &this->rsa_decipher(sizeof_decipher),
                       *encipher = &this->rsa_encipher(sizeof_encipher);

                if ((modbytes > cipher_length)) {
                    size_t length = length = (modbytes - cipher_length);
                    ::memcpy(encipher, cipher_bytes, cipher_length);
                    ::memset(encipher + cipher_length, 0, length);
                } else {
                    ::memcpy(encipher, cipher_bytes, modbytes);
                }
                this->output_hex_verbose_sized("cipher", encipher, modbytes);
                if (modbytes == (size = pub(decipher, sizeof_decipher, encipher, modbytes))) {
                    this->output_hex_verbage_sized("plain", decipher, size);
                }
            }
        }
        return err;
    }
    /// ...
    /// ...rsa_public_...encrypt_run
    /// 

    /// ...
    /// ...rsa_private_...decrypt_run
    /// 
    virtual int bn_rsa_private_decrypt_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t p_length = 0;
        const byte_t *p = 0, *q = 0, *dmp1 = 0, *dmq1 = 0, *iqmp = 0;

        if ((p = this->get_p(q, dmp1, dmq1, iqmp, p_length)) && (p_length)) {
            xos::crypto::rsa::bn::private_key prv(p, q, dmp1, dmq1, iqmp, p_length);

            err = rsa_private_decrypt_run(prv, argc, argv, env);
        }
        return err;
    }
    virtual int gmp_rsa_private_decrypt_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t p_length = 0;
        const byte_t *p = 0, *q = 0, *dmp1 = 0, *dmq1 = 0, *iqmp = 0;

        if ((p = this->get_p(q, dmp1, dmq1, iqmp, p_length)) && (p_length)) {
            xos::crypto::rsa::mp::private_key prv(p, q, dmp1, dmq1, iqmp, p_length);

            err = rsa_private_decrypt_run(prv, argc, argv, env);
        }
        return err;
    }
    template <typename rsa_private_key_t>
    int rsa_private_decrypt_run(rsa_private_key_t& prv, int argc, char_t** argv, char_t** env) {
        int err = 0;
        ssize_t size = 0, modbytes = prv.modbytes();

        if ((modbytes >= this->modbytes_min) && (modbytes <= this->modbytes_max)) {
            size_t sizeof_cipher = 0, cipher_length = 0;
            const byte_t *cipher_bytes = 0;
            byte_t *cipher = &this->rsa_cipher(sizeof_cipher);

            if ((cipher_bytes = this->get_rsa_cipher(cipher_length)) && (cipher_length)) {
                size_t sizeof_decipher = 0, sizeof_encipher = 0;
                byte_t *decipher = &this->rsa_decipher(sizeof_decipher),
                       *encipher = &this->rsa_encipher(sizeof_encipher);

                if ((modbytes > cipher_length)) {
                    size_t length = length = (modbytes - cipher_length);
                    ::memcpy(encipher, cipher_bytes, cipher_length);
                    ::memset(encipher + cipher_length, 0, length);
                } else {
                    ::memcpy(encipher, cipher_bytes, modbytes);
                }
                this->output_hex_verbose_sized("cipher", encipher, modbytes);
                if (modbytes == (size = prv(decipher, sizeof_decipher, encipher, modbytes))) {
                    this->output_hex_verbage_sized("plain", decipher, size);
                }
            }
        }
        return err;
    }
    /// ...
    /// ...rsa_private_...crypt_run
    /// 

    ///
    /// ...rsa_private_...encrypt_run
    /// ...
    virtual int bn_rsa_private_encrypt_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t p_length = 0;
        const byte_t *p = 0, *q = 0, *dmp1 = 0, *dmq1 = 0, *iqmp = 0;

        if ((p = this->get_p(q, dmp1, dmq1, iqmp, p_length)) && (p_length)) {
            xos::crypto::rsa::bn::private_key prv(p, q, dmp1, dmq1, iqmp, p_length);

            err = rsa_private_encrypt_run(prv, argc, argv, env);
        }
        return err;
    }
    virtual int gmp_rsa_private_encrypt_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t p_length = 0;
        const byte_t *p = 0, *q = 0, *dmp1 = 0, *dmq1 = 0, *iqmp = 0;

        if ((p = this->get_p(q, dmp1, dmq1, iqmp, p_length)) && (p_length)) {
            xos::crypto::rsa::mp::private_key prv(p, q, dmp1, dmq1, iqmp, p_length);

            err = rsa_private_encrypt_run(prv, argc, argv, env);
        }
        return err;
    }
    template <typename rsa_private_key_t>
    int rsa_private_encrypt_run(rsa_private_key_t& prv, int argc, char_t** argv, char_t** env) {
        int err = 0;
        ssize_t size = 0, modbytes = prv.modbytes();

        if ((modbytes >= this->modbytes_min) && (modbytes <= this->modbytes_max)) {
            size_t sizeof_plain = 0, plain_length = 0;
            const byte_t *plain_bytes = 0;
            byte_t *plain = &this->rsa_plain(sizeof_plain);

            if ((plain_bytes = this->get_rsa_plain(plain_length)) && (plain_length)) {
                size_t sizeof_encipher = 0, sizeof_decipher = 0;
                byte_t *encipher = &this->rsa_encipher(sizeof_encipher), 
                       *decipher = &this->rsa_decipher(sizeof_decipher);

                if ((modbytes > plain_length)) {
                    size_t length = length = (modbytes - plain_length);
                    ::memcpy(decipher, plain_bytes, plain_length);
                    ::memset(decipher + plain_length, 0, length);
                } else {
                    ::memcpy(decipher, plain_bytes, modbytes);
                }
                this->output_hex_verbose_sized("plain", decipher, modbytes);
                if (modbytes == (size = prv(encipher, sizeof_encipher, decipher, modbytes))) {
                    this->output_hex_verbage_sized("cipher", encipher, size);
                }
            }
        }
        return err;
    }
    /// ...
    /// ...rsa_private_...encrypt_run
    /// 

    ///
    /// ...output_get_..._run
    /// ...
    virtual int default_output_get_rsa_plain_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t length = 0;
        const byte_t *bytes = 0;
        if ((bytes = this->get_rsa_plain(length)) && (length)) {
            this->output_hex_verbage_sized("plain", bytes, length);
        }
        return err;
    }
    virtual int default_output_get_rsa_cipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t length = 0;
        const byte_t *bytes = 0;
        if ((bytes = this->get_rsa_cipher(length)) && (length)) {
            this->output_hex_verbage_sized("cipher", bytes, length);
        }
        return err;
    }
    /// ...
    /// ...output_get_..._run
    /// 

    ///
    /// ...output_test_..._run
    /// ...
    virtual int default_output_test_rsa_plain_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t modbytes = 0;
        const byte_t *modulus = 0;

        if ((modulus = this->get_modulus(modbytes)) && (modbytes)
            && (modbytes >= this->modbytes_min) && (modbytes <= this->modbytes_max)) {
            size_t sizeof_plain = 0; const byte_t *plain = 0;
            
            if ((plain = this->get_test_rsa_plain(sizeof_plain)) && (modbytes == sizeof_plain)) {
                this->output_hex_verbage_sized("plain", plain, sizeof_plain);
            }
        }
        return err;
    }
    virtual int default_output_test_rsa_cipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t modbytes = 0;
        const byte_t *modulus = 0;

        if ((modulus = this->get_modulus(modbytes)) && (modbytes)
            && (modbytes >= this->modbytes_min) && (modbytes <= this->modbytes_max)) {
            size_t sizeof_cipher = 0; const byte_t *cipher = 0;
            
            if ((cipher = this->get_test_rsa_cipher(sizeof_cipher)) && (modbytes == sizeof_cipher)) {
                this->output_hex_verbage_sized("cipher", cipher, sizeof_cipher);
            }
        }
        return err;
    }
    /// ...
    /// ...output_test_..._run
    /// 

    /// 
    /// on_set_rsa...literal
    /// ...
    virtual int on_set_rsa_plain_literal(const char_t* chars, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((chars) && (chars[0])) {
            string_t literal(chars);
            if (!(err = this->on_set_rsa_plain_hex_literal(this->rsa_plain_array(), literal))) {
                if (!(err = this->set_get_literal_rsa_plain(argc, argv, env))) {
                    if (!(err = this->set_output_get_rsa_plain_run(argc, argv, env))) {
                    }
                }
            }
        }
        return err;
    }
    virtual int on_set_rsa_cipher_literal(const char_t* chars, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((chars) && (chars[0])) {
            string_t literal(chars);
            if (!(err = this->on_set_rsa_cipher_hex_literal(this->rsa_cipher_array(), literal))) {
                if (!(err = this->set_get_literal_rsa_cipher(argc, argv, env))) {
                    if (!(err = this->set_output_get_rsa_cipher_run(argc, argv, env))) {
                    }
                }
            }
        }
        return err;
    }
    /// ...
    /// on_set_rsa...literal
    /// 

protected:
}; /// class maint
typedef maint<> main;

} /// namespace operate
} /// namespace rsa
} /// namespace crypto
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_CRYPTO_RSA_OPERATE_MAIN_HPP
