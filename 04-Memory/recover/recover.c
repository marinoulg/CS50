#include <stdint.h>
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef uint8_t BYTE;

// NB : any slack space will be filled with 0s
// Ultimately : 50 JPEGs

int main(int argc, char *argv[])
{
    // 1 CLI : name of a forensic image from which to recover JPEGs
    if (argc == 2)
    {
        // open argv[1]
        FILE *card = fopen(argv[1], "r"); // card = name of original audio file

        // Create a buffer for a block of data
        uint8_t buffer[512];

        while (fread(buffer, 1, 512, card) == 512)
        {
         // Create JPEGs from the data


        }





        for (int i = 0; i < 5; i ++)
        {
            printf("i: address of (card + %i) : %p\n", i, &card[i]);
            FILE *p = &card[i];
            printf("%p\n", p);

            // printf("%li, %i",(&card[i], 0x5876e75ad600));


            // printf("i+1 : address of (card + %i) : %p\n", i, &card[i+1]);
            // printf("(card + %i) : %i\n", i, card[i]);
            // char *string = &card[i];

            for (int j = 0; j < 4; j++)
            {
                // printf("%c\n", string[j]);
            }
        }
        // printf("address of (card + 1) : %p\n", &card[1]);


        if (card == NULL)
        {
            printf("Cannot open the file because it is empty\n");
            return 1;
        }

        else
        {
            // iterates over a copy of my memory card, looking for JPEGs’ signatures. Each time you find a signature, you can open a new file
            // for writing and start filling that file with bytes from my memory card, closing that file only once you encounter another signature


            // Moreover, rather than read my memory card’s bytes one at a time, you can read 512 of them at a time into a buffer for efficiency’s sake.


            // Thanks to FAT, you can trust that JPEGs’ signatures will be “block-aligned.” That is, you need only look for those signatures in a block’s
            // first four bytes.

        }
    }

    // If your program is not executed with exactly one command-line argument, it should remind the user of correct usage, and main should return 1.
    else
    {
        // printf("The correct usage is to provide the name of the file in the CLI\n");
        printf("Usage: ./recover FILE\n");
        return 1;
    }
}
