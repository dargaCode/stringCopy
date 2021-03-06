#import <stdio.h>
#import <cs50.h>

// function prototypes
int str_len(char* addr);
char* str_copy(char* addr_a);
void str_overwrite(char* addr);

int main(int argc, char* argv[])
{
    char* original;
    // repeatedly prompt for string
    do
    {
        printf("Enter string: ");
        original = GetString();
    }
    while (original == NULL || str_len(original) == 0);

    char* duplicate = str_copy(original);

    printf("    Original: %s \n", original);
    printf("    Duplicate: %s \n", duplicate);

    str_overwrite(original);

    printf("    Original: %s \n", original);
    printf("    Duplicate: %s \n\n", duplicate);
}

int str_len(char* addr)
{
    int len = 0;
    while (*(addr + len) != '\0')
    {
        len++;
    }
    return len;
}

char* str_copy(char* addr_a)
{
    printf("\nCopying string \"%s\"...\n", addr_a);
    int len = str_len(addr_a);
    // initialize new pointer
    char* addr_b = malloc(len * sizeof(char));
    for (int i = 0; i < len; i++)
    {
        *(addr_b + i) = *(addr_a + i);
    }
    return addr_b;
}

void str_overwrite(char* addr)
{
    printf("\nDestroying string \"%s\"...\n", addr);
    int len = str_len(addr);
    for (int i = 0; i < len; i++)
    {
        *(addr + i) = 'x';
    }
}
