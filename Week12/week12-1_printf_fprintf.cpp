#include <stdio.h>
int main()
{
    FILE * fout = fopen("file.txt", "w");///w;write 檔案指標

    printf("Hello World\n");
    fprintf(fout, "Hello World在檔案裡\n");
}
