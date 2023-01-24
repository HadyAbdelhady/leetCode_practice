#include <stdio.h>
int busyStudent(int *startTime, int startTimeSize, int *endTime, int endTimeSize, int queryTime)
{
    int students=0;
    for (int i = 0; i < startTimeSize; i++)
    {
        if (startTime[i] <= queryTime && endTime[i] >= queryTime)
        {
            students++;
        }
    }
    return students;
}
void main()
{
#define starttimesize 1
#define endtimesize 1
#define querytime 4
    int starttime[starttimesize] = {4};
    int endtime[endtimesize] = {4};
    printf("%d\n", busyStudent(starttime, starttimesize, endtime, endtimesize, querytime));
}