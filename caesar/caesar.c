// Encrypt messages using Caesar’s cipher

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    // Check for only one argument (= the key)
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Iterate through key to ensure consists of digits only and a positive integer
    string numbs = "0123456789";
    int arg_1_is_numeric = 0;
    int key = 0;
    char crypt_str[100];

    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        for (int j = 0, m = strlen(numbs); j < m; j++)
        {
            if (argv[1][i] == numbs[j])
            {
                // Count should match number of digits
                arg_1_is_numeric++;
            }
        }
    }

    if (atoi(argv[1]) <= 0 || arg_1_is_numeric != strlen(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        key = atoi(argv[1]);
        key = key % 26;
        string input_str = get_string("plaintext:  ");

        unsigned char crypt_char;

        for (int i = 0, n = strlen(input_str); i < n; i++)
        {
            crypt_char = input_str[i];
            crypt_char = crypt_char + key;

            // Shift Uppercase
            if (input_str[i] >= 65 && input_str[i] <= 90)
            {
                if (crypt_char > 90)
                {
                    crypt_char = (crypt_char % 90) + 64;
                }
            }

            // Shift lowercase
            else if (input_str[i] >= 97 && input_str[i] <= 122)
            {
                if (crypt_char > 122)
                {
                    crypt_char = (crypt_char % 122) + 96;
                }
            }
            else
            {
                // Don't shift if not a letter
                crypt_char = crypt_char - key;
                crypt_char = input_str[i];
            }
            // Append to array & print string
            crypt_str[i] = (char) crypt_char;
        }
    }

    printf("ciphertext: %s\n", crypt_str);
    return 0;
}
