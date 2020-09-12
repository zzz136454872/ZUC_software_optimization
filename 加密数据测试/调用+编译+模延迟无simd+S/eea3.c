#include"zuc.c"

void EEA3(u8* CK,u32 COUNT,u32 BEARER,u32 DIRECTION,u32 LENGTH,u32* M,u32* C)
{
    u32 L;
    u8 IV[16];
    L = (LENGTH+31)/32;
    IV[0] = (COUNT>>24) & 0xFF;
    IV[1] = (COUNT>>16) & 0xFF;
    IV[2] = (COUNT>>8) & 0xFF;
    IV[3] = COUNT & 0xFF;
    IV[4] = ((BEARER << 3) | ((DIRECTION&1)<<2)) & 0xFC;
    IV[5] = 0;
    IV[6] = 0;
    IV[7] = 0;
    IV[8] = IV[0];
    IV[9] = IV[1];
    IV[10] = IV[2];
    IV[11] = IV[3];
    IV[12] = IV[4];
    IV[13] = IV[5];
    IV[14] = IV[6];
    IV[15] = IV[7];
    Initialization(CK, IV);
    GenerateCipherstream(L,M,C);
}
