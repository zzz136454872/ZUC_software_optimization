#include "zuc.c" 
#include<windows.h>
#include <stdio.h>

#define SIZE 4
#define TIMES 20*1024*1024

void testZUC256()  
{  
    register u32 i;  
    u8 iv[25]={0x00};
    u8 key[32] = {0x00};
    Initialization256(key, iv);  
    u32 M[SIZE]={0};

    for(i=0;i<TIMES;i++)
	{
		GenerateKeyStream(M,SIZE); 
	} 

    //for (i=0; i<4; i++)
	//{
	//	printf("z%d:\t0x%08x\n", i, M[i]);
	//}
}


long long nstimer()
{
	LARGE_INTEGER time_start;
	LARGE_INTEGER time_over;
	LARGE_INTEGER pcFrequency;
	QueryPerformanceFrequency(&pcFrequency);
	QueryPerformanceCounter(&time_start);
    testZUC256();
	QueryPerformanceCounter(&time_over);
	long long run_time=(long long)1000000000*(time_over.QuadPart-time_start.QuadPart)/pcFrequency.QuadPart;
	printf("run_time: %I64dns\n",run_time);
    return run_time;
}

int main()
{
    int i;
    for(i=0;i<10;i++)
    {
        printf("µÚ%d´Î ",i+1);
        nstimer(); 
    }
    return 0;
}

