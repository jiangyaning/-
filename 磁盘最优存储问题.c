#include <stdio.h>
#include <stdlib.h> // malloc

typedef struct
{
    int length;
    int pi; // ����ĸ���
    double tr; // ����ʱ��
} File;
static int Pall; // ��������ĸ���֮��

double calctime(File *const files, const int index)
{
    if (index == -1)
        return 0;

    if (files[index].tr != 0)
        return files[index].tr;
    else
        return files[index].tr = calctime(files, index - 1) + files[index].length * files[index].pi * 1.0 / Pall;
}
int pall(File *const files, const int count)
{
    int pall = 0;
    for (int i = 0; i < count; i++)
        pall += files[i].pi;
    return pall;
}
int comparer(const void *file1, const void *file2) // �����ļ����ȴӴ�С����
{
    return ((const File *)file2)->length - ((const File *)file1)->length;
}

int main(void)
{
    int count;
    scanf("%d", &count);
    File *files = malloc(count * sizeof(File));

    for (int i = 0; i < count; i++)
    {
        scanf("%d %d", &files[i].length, &files[i].pi);
        files[i].tr = 0;
    }
    qsort(files, count, sizeof(File), comparer);
    Pall = pall(files, count);

    double tall = 0;
    calctime(files, count - 1);

    for (int i = 0; i < count; i++)
        tall += files[i].tr;
    printf("%lf\n", tall);
}