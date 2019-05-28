/*算法描述：
第一步：输入各个活动的开始时间（s）和结束时间（e），初始化各活动的会场号(n)。
第二步：按活动的开始时间和活动时间排序，s最早（第一优先级）和持续时间最短（第二优先级）的活动排在最前。
第三步：执行贪婪算法，即s最早和持续时间最短的优先安排会场，并记录会场号，其余活动的s大于或等于已安排活动的e的安排在同一会场，若某活动的s小于安排活动的e，则安排在另一会场，记录会场号，依次循环，直到所有活动均被安排。
第四步：统计会场号数，输出。
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

int cmp(const void* a,const void* b)//快排里的sqort函数
{
    return (*(meeting *)a).begin - (*(meeting *)b).begin;
}

int sum(meeting a[],int n)
{
    int end,i,k =0;
    int sum = n;//保存数组的元素个数
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






