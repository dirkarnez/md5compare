#include <stdio.h>
#include <stdlib.h>
#include "md5.h"

void getMD5Digest(char* filePath, md5_byte_t* digest) {
    int len;
    md5_byte_t buffer[512];
    md5_state_t state;

    FILE *pfile = fopen(filePath, "r");

    if (!pfile)
    {
        printf("No file");
        return;
    }

    md5_init(&state);

    do
    {
        len = fread(buffer, 1, 512, pfile);
        if (!ferror(pfile))
        {
            md5_append(&state, (const md5_byte_t *)buffer, len);
        }
    } while (!feof(pfile));

    md5_finish(&state, digest);

    fclose(pfile);
}

int main(int argc, char *argv[])
{
    int i;
    md5_byte_t digest_1[16];
    md5_byte_t digest_2[16];

    getMD5Digest(argv[1], digest_1);
    getMD5Digest(argv[2], digest_2);

    for (i = 0; i < 16; i++)
    {
        printf("%02x", digest_1[i]);
    }
    printf("\n");

    for (i = 0; i < 16; i++)
    {
        printf("%02x", digest_2[i]);
    }
    printf("\n");

    system("pause");
    return 0;
};