#include <iostream>
#include <string>
#include <algorithm>

std::string encrypt(std::string &plainText, std::string &key) {
	std::string cipherText;
	int	x;
	for (int i = 0, j = 0; i < plainText.length(); ++i, ++j) {
		if (j >= key.length())
			j = 0;
		if (plainText[i] >= 'A' && plainText[i] <= 'Z')
			x = ((plainText[i] - 'A') + (key[j] - 'A')) % 26;
		else
			x = plainText[i] - 'A';
		cipherText += (char)(x + 'A');
	}
	return cipherText;
}

std::string decrypt(std::string &cipherText, std::string &key) {
	std::string plainText;
	int x;
	for (int i = 0, j = 0; i < cipherText.length(); ++i, ++j) {
		if (j >= key.length())
			j = 0;
		if (cipherText[i] >= 'A' && cipherText[i] <= 'Z')
			x = ((cipherText[i] - 'A') + 26 - (key[j] - 'A')) % 26;
		else
			x = cipherText[i] - 'A';
		plainText += (char)(x + 'A');
	}
	return plainText;
}

int main()
{
	std::string plainText;
	std::cout << "Plain text: ";
	std::getline(std::cin, plainText);

	std::string key;
	std::cout << "Key: ";
	std::getline(std::cin, key);

	transform(plainText.begin(), plainText.end(), plainText.begin(), ::toupper);
	transform(key.begin(), key.end(), key.begin(), ::toupper);

	std::string encryptedText = encrypt(plainText, key);

	std::cout << "Encrypted text: " << encrypt(plainText, key) << std::endl;
	std::cout << "Decrypted text: " << decrypt(encryptedText, key) << std::endl;

	return 0;
}