// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

typedef uint8_t BYTE;
typedef int16_t TWO_BYTE_SAMPLE;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "rb"); // input = name of original audio file
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "wb"); // output = name of new audio file to be generated
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    // factor = amount by which the volume of the original audio file should be scaled
    float factor = atof(argv[3]);

    // Copy header from input file to output file
    BYTE header[HEADER_SIZE]; // Declaring a variable called header of type BYTE (capitalized by
                              // convention in Windows' world)

    fread(header, HEADER_SIZE, 1, input);
    fwrite(header, HEADER_SIZE, 1, output);

    // Read samples from input file and write updated data to output file
    TWO_BYTE_SAMPLE two_byte_sample;
    while (fread(&two_byte_sample, sizeof(two_byte_sample), 1, input)) // 2 bytes at a time
    {
        two_byte_sample *= factor;
        fwrite(&two_byte_sample, sizeof(two_byte_sample), 1, output);
    }

    // Close files
    fclose(input);
    fclose(output);
}

// while I read from the file, passing into that byte a byte from the file (give this function the
// address of that byte so we can give 8 bits in it), let's read in the size of a byte (could keep
// as 1 but keeping it dynamic), I will read 1 byte at a time, and read from the input file

// HEADER

// read the header from the input file and write the header to the output file
// read the rest of the data from the WAV file, one 16-bit (2-byte) sample at a time
// multiply each sample by the factor and write the new sample to the output file

// I save it passing by the address of that byte, so we can go to the location of that byte,
// the size of it so it knows how big it is, how many there are, which is still 1, and send it to
// the output instead

// I save it passing by the address of that byte, so we can go to the location of that byte,
// the size of it so it knows how big it is, how many there are, which is still 1, and send it to
// the output instead
