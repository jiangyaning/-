/*�㷨������
��һ�������������Ŀ�ʼʱ�䣨s���ͽ���ʱ�䣨e������ʼ������Ļ᳡��(n)��
�ڶ���������Ŀ�ʼʱ��ͻʱ������s���磨��һ���ȼ����ͳ���ʱ����̣��ڶ����ȼ����Ļ������ǰ��
��������ִ��̰���㷨����s����ͳ���ʱ����̵����Ȱ��Ż᳡������¼�᳡�ţ�������s���ڻ�����Ѱ��Ż��e�İ�����ͬһ�᳡����ĳ���sС�ڰ��Ż��e����������һ�᳡����¼�᳡�ţ�����ѭ����ֱ�����л�������š�
���Ĳ���ͳ�ƻ᳡�����������
*/


#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
typedef struct
{
    int begin;
    int end;
    int flag;
}meeting;

int cmp(const void* a,const void* b)//�������sqort����
{
    return (*(meeting *)a).begin - (*(meeting *)b).begin;
}

int sum(meeting a[],int n)
{
    int end,i,k =0;
    int sum = n;//���������Ԫ�ظ���
    qsort(a,n,sizeof(meeting),cmp);
    a[0].flag = 1;
    end = a[0].end;
    n = n-1;
    while(n>0)
    {
        k++;
        end = 0;
        for(i = 0;i<sum;i++)
        {
            if(a[i].begin >= end && a[i].flag == 0)
            {
                end = a[i].end;
                n--;
                a[i].flag = k;
            }
        }
    }
    return k;
}

int main()
{
    int n,i,min = 0;
    cin>>n;
    meeting meet[n];
    for(i = 0;i<n;i++)
    {
        cin>>meet[i].begin>>meet[i].end;
        meet[i].flag = 0;
    }
    min = sum(meet,n);
    cout<<"\n"<<min<<endl;
    return 0;
}






