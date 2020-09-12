#include<stdio.h>
#include"eea3.c"
#include<windows.h>
//以32bit标记的长度 
#define SIZE (80*1024*1024)
#define TIMES (80*1024*1024/SIZE)

void testZUC()
{
    u8 CK[16] = {0xe5,0xbd,0x3e,0xa0,0xeb,0x55,0xad,0xe8,0x66,0xc6,0xac,0x58,0xbd,0x54,0x30,0x2a};
    u32 COUNT = 0x56823;
	u32 BEARER = 0x18;
	u32 DIRECTION = 0x1;
	u32 LENGTH=32*SIZE-31;
    //u32 IBS[SIZE]={0x14a8ef69,0x3d678507,0xbbe7270a,0x7f67ff50,0x06c3525b,0x9807e467,0xc4e56000,
	//               0xba338f5d,0x42955903,0x67518222,0x46c80d3b,0x38f07f4b,0xe2d8ff58,0x05f51322,
	//			   0x29bde93b,0xbbdcaf38,0x2bf1ee97,0x2fbf9977,0xbada8945,0x847a2a6c,0x9ad34a66,
	//			   0x7554e04d,0x1f7fa2c3,0x3241bd8f,0x1ba220d};
    //u32 OBS[SIZE]={0};
    u32* OBS=(u32*)malloc(SIZE*sizeof(u32));
	u32* IBS=(u32*)malloc(SIZE*sizeof(u32)); 
    //u32 C[SIZE}={0};
    int i;
    for(i=0;i<TIMES;i++) 
        EEA3(CK,COUNT,BEARER,DIRECTION,LENGTH,IBS,OBS);
    //for(i=0;i<SIZE;i++)
    //    printf("%08x ",OBS[i]);
    free(OBS);
    free(IBS);
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
    
