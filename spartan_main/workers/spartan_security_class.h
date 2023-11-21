#ifndef SPARTANSECURITYCLASS_H 
#define SPARTANSECURITYCLASS_H

#include "../lib/Base64.h"
#include "../lib/ESP8266TrueRandom/ESP8266TrueRandom.cpp"

#include <SHA256.h>
#include <Crypto.h>
#include <cstring>

SHA256 sha256;

class SpartanSecurityClass {
  private:
		String chaos_factor = "";

  public:

		void start();
		String random_code();
		String hash_256(String);
		String encrypt(String, String, String);
		String decrypt(String, String, String);

};

void SpartanSecurityClass::start () {
	Serial.println("Started SpartanSecurityClass");
	
	Serial.println("Testing RNG Class:");
	Serial.println(random_code());
	Serial.println(random_code());
	Serial.println(random_code());
	Serial.println(random_code());
	Serial.println("Done");


};

String SpartanSecurityClass::random_code(){
	String seed;
	randomSeed(ESP8266TrueRandom.random());
  for (int i=1;i<=20;i++){
		seed += String(random(10));
	};
	return hash_256(seed);
}

String SpartanSecurityClass::hash_256(String input){
 byte hashed[32];
 const char* toHash = input.c_str();
 String BufferOut = "";
    sha256.reset();
    sha256.update(toHash, strlen(toHash));
    sha256.finalize(hashed, 32);
    
    for (int x = 0; x < 32; x++) {
      if(hashed[x] < 0x10) {
        BufferOut += '0';
      }
      BufferOut += String (hashed[x], HEX);
    }
  return BufferOut;    
}

String SpartanSecurityClass::encrypt(String plain_data, String SymKey, String Vector){
   /*   
      // AES CBC Encryption
      //tool from Kakopappa (from Github).
      //Modified by DocMac.

      const char* Key_Man = SymKey.c_str();
      const char* IV_Man = Vector.c_str();

      int len = plain_data.length();
      int n_blocks = len / 16 + 1;
      uint8_t n_padding = n_blocks * 16 - len;
      uint8_t data[n_blocks*16];
      memcpy(data, plain_data.c_str(), len);
      for(int i = len; i < n_blocks * 16; i++){
        data[i] = n_padding;
      }
      
      uint8_t key[16], iv[16];
      memcpy(key, Key_Man, 16);
      memcpy(iv, IV_Man, 16);

      // encryption context
      br_aes_big_cbcenc_keys encCtx;

      // reset the encryption context and encrypt the data
      br_aes_big_cbcenc_init(&encCtx, key, 16);
      br_aes_big_cbcenc_run( &encCtx, iv, data, n_blocks*16 );

      // Base64 encode
      len = n_blocks*16;
      char encoded_data[ base64_enc_len(len) ];
      base64_encode(encoded_data, (char *)data, len);
      
      return String(encoded_data);*/
			return  "";
}

String SpartanSecurityClass::decrypt(String encoded_data_str, String SymKey, String Vector){  
/*
      // AES CBC Decryption
      //tool from Kakopappa (from Github).
      //Modified by DocMac.

      const char* Key_Man = SymKey.c_str();
      const char* IV_Man = Vector.c_str();
      
      int input_len = encoded_data_str.length();
      char *encoded_data = const_cast<char*>(encoded_data_str.c_str());
      int len = base64_dec_len(encoded_data, input_len);
      uint8_t data[ len ];
      base64_decode((char *)data, encoded_data, input_len);
      
      uint8_t key[16], iv[16];
      memcpy(key, Key_Man, 16);
      memcpy(iv, IV_Man, 16);

      int n_blocks = len / 16;

      br_aes_big_cbcdec_keys decCtx;

      br_aes_big_cbcdec_init(&decCtx, key, 16);
      br_aes_big_cbcdec_run( &decCtx, iv, data, n_blocks*16 );

      uint8_t n_padding = data[n_blocks*16-1];
      len = n_blocks*16 - n_padding;
      char plain_data[len + 1];
      memcpy(plain_data, data, len);
      plain_data[len] = '\0';

      return String(plain_data);
			*/
		return "";
}
#endif