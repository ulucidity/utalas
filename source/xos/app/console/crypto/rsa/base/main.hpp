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
///   Date: 5/28/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_CRYPTO_RSA_BASE_MAIN_HPP
#define XOS_APP_CONSOLE_CRYPTO_RSA_BASE_MAIN_HPP

#include "xos/app/console/crypto/rsa/base/main_opt.hpp"

#include "xos/crypto/pseudo/random/number/generator.hpp"
#include "xos/crypto/random/number/reader.hpp"
#include "xos/crypto/random/prime/reader.hpp"

#include "xos/crypto/random/prime/bn/number.hpp"
#include "xos/crypto/random/prime/bn/reader.hpp"
#include "xos/crypto/random/prime/bn/miller_rabin.hpp"
#include "xos/crypto/random/prime/bn/generator.hpp"
#include "xos/crypto/rsa/bn/key_generator.hpp"

#include "xos/crypto/random/prime/mp/number.hpp"
#include "xos/crypto/random/prime/mp/reader.hpp"
#include "xos/crypto/random/prime/mp/miller_rabin.hpp"
#include "xos/crypto/random/prime/mp/generator.hpp"
#include "xos/crypto/rsa/mp/key_generator.hpp"

namespace xos {
namespace app {
namespace console {
namespace crypto {
namespace rsa {
namespace base {

/// class maint
template 
<class TExtends = xos::app::console::crypto::rsa::base::main_opt, 
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

    class exported bn_reader_observer_t
    : virtual public xos::crypto::random::prime::bn::reader::observer {
    friend class maint;
    public:
        bn_reader_observer_t(maint& main): main_(main), output_(0) {}
        virtual ~bn_reader_observer_t() {}
        virtual ssize_t on_read(BIGNUM* n, size_t bytes) {
            bool output = true;
            if ((output)) {
                main_.err(".");
                ++output_;
            }
            return bytes;
        }
        virtual size_t clear_output() {
            size_t output = output_;
            output_ = 0;
            if ((output)) {
                main_.errln();
            }
            return output;
        }
    protected:
        maint& main_;
        size_t output_;
    }; /// class bn_reader_observer_t
    
    class exported mp_reader_observer_t
: virtual public xos::crypto::random::prime::mp::reader::observer {
    friend class maint;
    public:
        mp_reader_observer_t(maint& main): main_(main), output_(0) {}
        virtual ~mp_reader_observer_t() {}
        virtual ssize_t on_read(MP_INT* n, size_t bytes) {
            bool output = true;
            if ((output)) {
                main_.err(".");
                ++output_;
            }
            return bytes;
        }
        virtual size_t clear_output() {
            size_t output = output_;
            output_ = 0;
            if ((output)) {
                main_.errln();
            }
            return output;
        }
    protected:
        maint& main_;
        size_t output_;
    }; /// class mp_reader_observer_t
    
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
    /// bn_...pseudo_random...run
    /// ...
    virtual int bn_miller_rabin_pseudo_random_prime_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t modulus_bits = this->modulus_bits(), modulus_length = ((modulus_bits + 7) >> 3);

        if ((modulus_length >= this->modbytes_min) && (modulus_length <= this->modbytes_max)) {
            size_t length = 0, sizeof_random = 0;
            byte_t *random = 0;
            
            if ((random = &this->rsa_decipher(sizeof_random)) 
                 && (sizeof_random >= (length = (modulus_length / 2)))) {
                xos::crypto::pseudo::random::number::generator generator;
                xos::crypto::random::prime::bn::number number;

                if ((number.is_created())) {
                    bn_reader_observer_t reader_observer(*this);
                    xos::crypto::random::prime::bn::miller_rabin miller_rabin(&reader_observer);

                    if ((miller_rabin.create())) {
                        xos::crypto::random::prime::bn::reader reader;
                        bool is_probably_prime = false;
                        
                        do {
                            if (length == (sizeof_random = reader.read_msb(number, length, generator))) {
                                if ((is_probably_prime = miller_rabin.probably_prime(number, length, generator))) {
                                    if (length == (sizeof_random = number.to_msb(random, length))) {
                                        this->output_hex_verbage_sized("pseudo_random_prime", random, sizeof_random);
                                    }
                                }
                            }
                        } while (!is_probably_prime);
                        miller_rabin.destroy();
                    }
                }
            }
        }
        return err;
    }
    virtual int bn_pseudo_random_prime_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t modulus_bits = this->modulus_bits(), modulus_length = ((modulus_bits + 7) >> 3);

        if ((modulus_length >= this->modbytes_min) && (modulus_length <= this->modbytes_max)) {
            size_t length = 0, sizeof_random = 0;
            byte_t *random = 0;
            
            if ((random = &this->rsa_decipher(sizeof_random)) 
                && (sizeof_random >= (length = (modulus_length / 2)))) {
                xos::crypto::pseudo::random::number::generator random_reader;
                xos::crypto::random::prime::bn::number number;

                if ((number.is_created())) {
                    bool no_miller_rabin_test = this->no_miller_rabin_test();
                    bn_reader_observer_t reader_observer(*this);
                    xos::crypto::random::prime::bn::generator generator(&reader_observer);

                    if ((generator.create(no_miller_rabin_test))) {
                        
                        if (length == (sizeof_random = generator.generate(number, length, random_reader))) {
                            
                            if (length == (sizeof_random = number.to_msb(random, length))) {
                                this->output_hex_verbage_sized("pseudo_random_prime", random, sizeof_random);
                            }
                        }
                        generator.destroy();
                    }
                }
            }
        }
        return err;
    }
    /// ...
    /// bn_...pseudo_random...run
    /// 

    /// ...modulus...
    virtual int on_set_modulus_bits_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            string_t set_modulus_bits(optarg);
            size_t modulus_bits = set_modulus_bits.to_unsigned(), 
                   modulus_bytes = ((modulus_bits + 7) >> 3);
            if ((this->modbytes_min <= modulus_bytes) && (this->modbytes_max >= modulus_bytes)) {
                modulus_bits = (modulus_bytes << 3);
                this->set_modulus_bits(modulus_bits);
            }
        }
        return err;
    }
    virtual int output_modulus_bits_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t modulus_bits = this->modulus_bits();
        unsigned_to_string output_modulus_bits(modulus_bits);
        this->outln(output_modulus_bits);
        return err;
    }
    virtual int on_set_modulus_bytes_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            string_t set_modulus_bytes(optarg);
            size_t modulus_bytes = set_modulus_bytes.to_unsigned();
            if ((this->modbytes_min <= modulus_bytes) && (this->modbytes_max >= modulus_bytes)) {
                this->set_modulus_bytes(modulus_bytes);
            }
        }
        return err;
    }
    virtual int output_modulus_bytes_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t modulus_bytes = this->modulus_bytes();
        unsigned_to_string output_modulus_bytes(modulus_bytes);
        this->outln(output_modulus_bytes);
        return err;
    }

protected:
}; /// class maint
typedef maint<> main;

} /// namespace base
} /// namespace rsa
} /// namespace crypto
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_CRYPTO_RSA_BASE_MAIN_HPP
