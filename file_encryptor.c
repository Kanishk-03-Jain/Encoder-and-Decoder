#include <iostream>
#include <fstream>

int main() {
    int choice;
    std::cout << "Enter 1 to encrypt and 2 to decrypt: ";
    std::cin >> choice;

    const char* inputFile;
    const char* outputFile;
    char key = 'K'; // Simple XOR key

    if (choice == 1) {
        inputFile = "input.txt";
        outputFile = "output.txt";
        // inputFile = "input.jpeg";  //for images
        // outputFile = "output.jpeg";
    } else if (choice == 2) {
        inputFile = "output.txt";
        outputFile = "decrypted_file.txt";
        // inputFile = "output.jpeg";  //for images
        // outputFile = "decrypted_file.jpeg";
    } else {
        std::cout << "Invalid Choice!\n";
        return 1;
    }

    std::ifstream inFile(inputFile, std::ios::binary);
    std::ofstream outFile(outputFile, std::ios::binary);

    if (!inFile.is_open() || !outFile.is_open()) {
        std::cerr << "Error! Could not open file\n";
        if (inFile.is_open()) inFile.close();
        if (outFile.is_open()) outFile.close();
        return 1;
    }

    char ch;
    while (inFile.get(ch)) {
        outFile.put(ch ^ key); // XOR encryption/decryption
    }

    inFile.close();
    outFile.close();

    std::cout << "Operation complete: " << (choice == 1 ? "Encrypted" : "Decrypted") << "\n";
    return 0;
}
