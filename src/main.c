#include "main.h"

#include <stdio.h>
#include <time.h>
// iota-related stuff
#include "iota/kerl.h"
#include "iota/conversion.h"
#include "iota/addresses.h"

void address(char *seedChars, int index, int security, char *result);

int main()
{
    clock_t start = clock();

    char seedChars[] = "FMBFUDZXVLQDJUZKPUJAQNYJHOWKZBQQKNHFMXWDYHTUIRCBRJEYUFR"
                       "MFRYKYNANGTEDX9BVFFMXNQNTF";
    char charAddress[81];
    for (int i = 0; i < 100; i++) {
        address(seedChars, i, 2, charAddress);
        // printf("%s\n", charAddress);
    }
    clock_t end = clock();
    float seconds = (float)(end - start) / CLOCKS_PER_SEC;
    printf("Took %lf seconds to run.\n", seconds);

    return 0;
}

void address(char *seedChars, int index, int security, char result[81])
{

    unsigned char address[81];
    unsigned char seedBytes[48];
    chars_to_bytes(seedChars, seedBytes, 81);
    get_public_addr(seedBytes, index, security, address);

    bytes_to_chars(address, result, 48);
}
