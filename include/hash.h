#pragma once
#include <iostream>


namespace rsa{

char* signMessage(std::string privateKey, std::string plainText);
bool verifySignature(std::string publicKey, std::string plainText, const char* signatureBase64);

}