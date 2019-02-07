#include "b64.h"


string encryptDecrypt(string toEncrypt) {
	char key[2] = { '6', '9' }; //Any chars will work
	string output = toEncrypt;

	for (int i = 0; i < toEncrypt.size(); i++)
		output[i] = toEncrypt[i] ^ key[i % (sizeof(key) / sizeof(char))];

	return output;
}





