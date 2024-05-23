#include <stdio.h>

int main() {
    int choice;
    printf("Enter 1 to encrypt and 2 to decrypt: ");
    scanf("%d", &choice);

    const char *inputFile, *outputFile;
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
        printf("Invalid Choice!\n");
        return 0;
    }

    FILE *in = fopen(inputFile, "rb");
    FILE *out = fopen(outputFile, "wb");

    if (in == NULL || out == NULL) {
        printf("Error! Could not open file\n");
        fclose(in);
        fclose(out);
        return 0;
    }

    int ch;
    while ((ch = fgetc(in)) != EOF) {
        fputc(ch ^ key, out); // XOR encryption/decryption
    }

    fclose(in);
    fclose(out);

    printf("Operation complete: %s\n", choice == 1 ? "Encrypted" : "Decrypted");
    return 0;
}
