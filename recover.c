#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover card.raw\n");
        return 1;
    }

    char *infile = argv[1];

    // open input file
    FILE *inputfile = fopen(infile, "r");
    if (inputfile == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    unsigned char buffer[512];

    // pointer to outfile
    FILE *outptr = NULL;

    // make space for jpg file name
    char image[8];
    int n = 0;
    while (fread(buffer, 512, 1, inputfile) == 1)
    {
        // find the beginning of an jpg
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
buffer[3] >= 0xe0 && buffer[3] <= 0xef)
        {
            // close image file if one has been created
            if (n > 0)
            {
                fclose(outptr);
            }
            //name the nth image
            sprintf(image, "%03d.jpg", n);

            // open Nth image
            outptr = fopen(image, "w");
            if (outptr == NULL)
            {
                fprintf(stderr, "Could not create %s.\n", image);
                return 3;
            }
            n++;
        }

        // write on image file if one exists
        if (outptr != NULL)
        {
            fwrite(buffer, 512, 1, outptr);
        }
    }

    // close last image file
    fclose(outptr);

    // close card
    fclose(inputfile);

    return 0;
}