#pragma once
#include <iostream>

#include <openssl/aes.h>
#include <openssl/evp.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/ssl.h>
#include <openssl/bio.h>
#include <openssl/err.h>
#include <assert.h>

namespace rsa{



char* signMessage(std::string privateKey, std::string plainText);
bool verifySignature(std::string publicKey, std::string plainText, const char* signatureBase64);
}