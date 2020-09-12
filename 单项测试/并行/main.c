#include<stdio.h>
#include"zuc.c"
#include<windows.h>

#define SIZE 4 
#define TIMES 20*1024*1024 

void testZUC()
{
	u8 key[16] = {0x3d, 0x4c, 0x4b, 0xe9, 0x6a, 0x82, 0xfd, 0xae, 0xb5, 0x8f, 0x64, 0x1d, 0xb1, 0x7b, 0x45, 0x5b};
    u8 iv[16] = {0x84, 0x31, 0x9a, 0xa8, 0xde, 0x69, 0x15, 0xca, 0x1f, 0x6b, 0xda, 0x6b, 0xfb, 0xd8, 0xc7, 0x66};
	
	//u8 key[16] = {0x00, 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
	//u8 iv[16] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,};
	
	u32 pKeyStream[SIZE] = {0};
	u32 i;

	Initialization(key, iv);
	GenerateKeystream(pKeyStream, SIZE*TIMES);
    
    //正确性验证 
	//for (i=0; i<4; i++)
	//{
	//	printf("z%d:\t0x%08x\n", i, pKeyStream[i]);
	//}
	/* times=1 
	14f1c272
	3279c419 */
}

long long nstimer()
{
	LARGE_INTEGER time_start;	//开始时间
	LARGE_INTEGER time_over;	//结束时间
	LARGE_INTEGER pcFrequency;	//计时器频率
	QueryPerformanceFrequency(&pcFrequency);
	QueryPerformanceCounter(&time_start);	//计时开始
    //这里添加需要测试的函数
    //for(int i=0;i<TIMES;i++)
    testZUC();
    //被测试函数结束
	QueryPerformanceCounter(&time_over);	//计时结束
	long long run_time=(long long)1000000000*(time_over.QuadPart-time_start.QuadPart)/pcFrequency.QuadPart;
	printf("run_time：%I64dns\n",run_time);
    return run_time;
}

int main()
{
    int i;
    for(i=0;i<10;i++)
    {
        printf("第%d次 ",i+1);
        nstimer(); 
    }
    return 0;
}
    
