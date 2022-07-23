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
///   Date: 5/29/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_CRYPTO_RSA_PAIR_MAIN_HPP
#define XOS_APP_CONSOLE_CRYPTO_RSA_PAIR_MAIN_HPP

#include "xos/app/console/crypto/rsa/pair/main_opt.hpp"

namespace xos {
namespace app {
namespace console {
namespace crypto {
namespace rsa {
namespace pair {

/// class maint
template 
<class TExtends = xos::app::console::crypto::rsa::pair::main_opt, 
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

    typedef typename extends::bn_reader_observer_t bn_reader_observer_t;
    typedef typename extends::mp_reader_observer_t mp_reader_observer_t;
    
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
    virtual int bn_generate_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t expbits = this->exponent_bits(), expbytes = ((expbits + 7) >> 3),
               modbits = this->modulus_bits(), modbytes = ((modbits + 7) >> 3),
               pbits = (modbits >> 1), pbytes = (modbytes >> 1);
        crypto_array_t exponent_array(this->exponent_value(), expbytes);
        byte_t* exponent = 0; size_t exponent_length = 0;
        
        if ((exponent = exponent_array.has_elements(exponent_length)) && (expbytes == exponent_length)) {
            xos::crypto::pseudo::random::number::generator random;
            xos::crypto::rsa::bn::public_key pub(modbytes, expbytes);
            xos::crypto::rsa::bn::private_key prv(pbytes);
            bn_reader_observer_t observer(*this);
            xos::crypto::rsa::bn::key_generator generator(&observer);
            
            observer.clear_output();
            if ((generator.generate(prv, pub, modbytes, exponent, expbytes, random))) {
                
                observer.clear_output();
                if (!(err = output_generated_key_pair_run(pub, prv, argc, argv, env))) {
                }
            }
        }
        return err;
    }
    virtual int gmp_generate_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t expbits = this->exponent_bits(), expbytes = ((expbits + 7) >> 3),
               modbits = this->modulus_bits(), modbytes = ((modbits + 7) >> 3),
               pbits = (modbits >> 1), pbytes = (modbytes >> 1);
        crypto_array_t exponent_array(this->exponent_value(), expbytes);
        byte_t* exponent = 0; size_t exponent_length = 0;
        
        if ((exponent = exponent_array.has_elements(exponent_length)) && (expbytes == exponent_length)) {
            xos::crypto::pseudo::random::number::generator random;
            xos::crypto::rsa::mp::public_key pub(modbytes, expbytes);
            xos::crypto::rsa::mp::private_key prv(pbytes);
            mp_reader_observer_t observer(*this);
            xos::crypto::rsa::mp::key_generator generator(&observer);
            
            observer.clear_output();
            if ((generator.generate(prv, pub, modbytes, exponent, expbytes, random))) {
                
                observer.clear_output();
                if (!(err = output_generated_key_pair_run(pub, prv, argc, argv, env))) {
                }
            }
        }
        return err;
    }
    /// ...
    /// ...generate_key_pair_run
    /// 

    /// ...output_generated_key_pair_run
    virtual int output_generated_key_pair_run
    (const xos::crypto::rsa::public_key::extend& pub, 
     const xos::crypto::rsa::private_key::extend& prv, int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t expbytes = pub.expbytes(), 
               modbytes = pub.modbytes(), 
               pbytes = prv.pbytes();
        byte_array_t array(modbytes);
        byte_t *bytes = 0; size_t length = 0;
        
        if ((bytes = array.has_elements(length)) && (modbytes <= length)) {
            bool const_0x_output = this->const_0x_output();

            if ((const_0x_output)) {
                this->outlln("#ifndef ", this->key_pair_define_chars(), null);
                this->outlln("#define ", this->key_pair_define_chars(), null);
                this->outln("");
            }
            if (expbytes == (length = pub.get_exponent_msb(bytes, modbytes))) {
                this->output_hex_verbage_sized("rsa_public_exponent", bytes, length);

                if (modbytes == (length = pub.get_modulus_msb(bytes, modbytes))) {
                    this->output_hex_verbage_sized("rsa_public_modulus", bytes, length);
                    
                    if (pbytes == (length = prv.get_p_msb(bytes, pbytes))) {
                        this->output_hex_verbage_sized("rsa_private_p", bytes, length);
                        
                        if (pbytes == (length = prv.get_q_msb(bytes, pbytes))) {
                            this->output_hex_verbage_sized("rsa_private_q", bytes, length);
                            
                            if (pbytes == (length = prv.get_dmp1_msb(bytes, pbytes))) {
                                this->output_hex_verbage_sized("rsa_private_dmp1", bytes, length);
                                
                                if (pbytes == (length = prv.get_dmq1_msb(bytes, pbytes))) {
                                    this->output_hex_verbage_sized("rsa_private_dmq1", bytes, length);
                                    
                                    if (pbytes == (length = prv.get_iqmp_msb(bytes, pbytes))) {
                                        this->output_hex_verbage_sized("rsa_private_iqmp", bytes, length);
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if ((const_0x_output)) {
                this->outln("");
                this->outlln("#endif /// ndef ", this->key_pair_define_chars(), null);
            }
        }
        return err;
    }

    /// 
    /// ...output_get_..._run
    /// ...
    virtual int default_output_get_public_key_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t length = 0;
        const byte_t *bytes = 0;

        if ((bytes = this->get_exponent(length)) && (length)) {
            bool const_0x_output = this->const_0x_output();

            if ((const_0x_output)) {
                this->outlln("#ifndef ", this->public_key_define_chars(), null);
                this->outlln("#define ", this->public_key_define_chars(), null);
                this->outln("");
                this->outln("///");
                this->outln("/// public");
                this->outln("/// ...");
            }
            this->output_hex_verbage_sized("rsa_public_exponent", bytes, length);

            if ((bytes = this->get_modulus(length)) && (length)) {
                this->output_hex_verbage_sized("rsa_public_modulus", bytes, length);
            }
            if ((const_0x_output)) {
                this->outln("/// ...");
                this->outln("/// public");
                this->outln("///");
                this->outln("");
                this->outlln("#endif /// ndef ", this->public_key_define_chars(), null);
            }
        }
        return err;
    }
    virtual int default_output_get_private_key_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t length = 0;
        const byte_t *bytes = 0;
        const byte_t *q = 0, *dmp1 = 0, *dmq1 = 0, *iqmp = 0;
        if ((bytes = this->get_p(q, dmp1, dmq1, iqmp, length)) && (length)) {
            bool const_0x_output = this->const_0x_output();

            if ((const_0x_output)) {
                this->outlln("#ifndef ", this->private_key_define_chars(), null);
                this->outlln("#define ", this->private_key_define_chars(), null);
                this->outln("");
                this->outln("///");
                this->outln("/// private");
                this->outln("/// ...");
            }
            this->output_hex_verbage_sized("rsa_private_p", bytes, length);
            this->output_hex_verbage_sized("rsa_private_q", q, length);
            this->output_hex_verbage_sized("rsa_private_dmp1", dmp1, length);
            this->output_hex_verbage_sized("rsa_private_dmq1", dmq1, length);
            this->output_hex_verbage_sized("rsa_private_iqmp", iqmp, length);

            if ((const_0x_output)) {
                this->outln("/// ...");
                this->outln("/// private");
                this->outln("///");
                this->outln("");
                this->outlln("#endif /// ndef ", this->private_key_define_chars(), null);
            }
        }
        return err;
    }
    virtual int default_output_get_key_pair_run(int argc, char_t** argv, char_t** env) {
         int err = 0;
         size_t length = 0;
         const byte_t *bytes = 0;
 
         if ((bytes = this->get_exponent(length)) && (length)) {
             bool const_0x_output = this->const_0x_output();
 
             if ((const_0x_output)) {
                 this->outlln("#ifndef ", this->key_pair_define_chars(), null);
                 this->outlln("#define ", this->key_pair_define_chars(), null);
                 this->outln("");
             }
             if ((const_0x_output)) {
                 this->outln("///");
                 this->outln("/// public");
                 this->outln("/// ...");
             }
             this->output_hex_verbage_sized("rsa_public_exponent", bytes, length);
 
             if ((bytes = this->get_modulus(length)) && (length)) {
                 const byte_t *q = 0, *dmp1 = 0, *dmq1 = 0, *iqmp = 0;
                 this->output_hex_verbage_sized("rsa_public_modulus", bytes, length);
 
                 if ((const_0x_output)) {
                     this->outln("/// ...");
                     this->outln("/// public");
                     this->outln("///");
                 }
                 if ((bytes = this->get_p(q, dmp1, dmq1, iqmp, length)) && (length)) {
                     if ((const_0x_output)) {
                         this->outln("");
                         this->outln("///");
                         this->outln("/// private");
                         this->outln("/// ...");
                     }
                     this->output_hex_verbage_sized("rsa_private_p", bytes, length);
                     this->output_hex_verbage_sized("rsa_private_q", q, length);
                     this->output_hex_verbage_sized("rsa_private_dmp1", dmp1, length);
                     this->output_hex_verbage_sized("rsa_private_dmq1", dmq1, length);
                     this->output_hex_verbage_sized("rsa_private_iqmp", iqmp, length);
         
                     if ((const_0x_output)) {
                         this->outln("/// ...");
                         this->outln("/// private");
                         this->outln("///");
                     }
                 }
             }
             if ((const_0x_output)) {
                 this->outln("");
                 this->outlln("#endif /// ndef ", this->key_pair_define_chars(), null);
             }
         }
         return err;
     }
    /// ...
    /// ...output_get_..._run
    /// 

    ///
    /// on_set...literal
    /// ...
    virtual int on_set_public_key_literal(const char_t* chars, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((chars) && (chars[0])) {
            string_t literal(chars);
            if (!(err = this->on_set_public_key_hex_literals
                  (this->exponent(), this->modulus(), literal))) {
                if (!(err = this->set_get_literal_exponent(argc, argv, env))) {
                    if (!(err = this->set_get_literal_modulus(argc, argv, env))) {
                    }
                }
            }
        }
        return err;
    }
    virtual int on_set_private_key_literal(const char_t* chars, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((chars) && (chars[0])) {
            string_t literal(chars);
            if (!(err = this->on_set_private_key_hex_literals
                  (this->p(), this->q(), this->dmp1(), this->dmq1(), this->iqmp(), literal))) {
                if (!(err = this->set_get_literal_p(argc, argv, env))) {
                }
            }
        }
        return err;
    }
    virtual int on_set_key_pair_literal(const char_t* chars, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((chars) && (chars[0])) {
            string_t literal(chars);
            if (!(err = this->on_set_key_pair_hex_literals
                (this->exponent(), this->modulus(), 
                 this->p(), this->q(), this->dmp1(), this->dmq1(), this->iqmp(), literal))) {
                if (!(err = this->set_get_literal_exponent(argc, argv, env))) {
                    if (!(err = this->set_get_literal_modulus(argc, argv, env))) {
                        if (!(err = this->set_get_literal_p(argc, argv, env))) {
                        }
                    }
                }
            }
        }
        return err;
    }
    /// ...
    /// on_set...literal
    /// 

protected:
}; /// class maint
typedef maint<> main;

} /// namespace pair
} /// namespace rsa
} /// namespace crypto
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_CRYPTO_RSA_PAIR_MAIN_HPP
