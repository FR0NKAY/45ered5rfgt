#include "b64.h"


std::string encryptDecrypt(std::string toEncrypt) {
	char key[2] = { '6', '9' }; //Any chars will work
	std::string output = toEncrypt;

	for (int i = 0; i < toEncrypt.size(); i++)
		output[i] = toEncrypt[i] ^ key[i % (sizeof(key) / sizeof(char))];

	return output;
}





