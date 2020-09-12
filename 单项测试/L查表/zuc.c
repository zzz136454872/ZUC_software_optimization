/* ¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª- */
typedef unsigned char u8;
typedef unsigned int u32;
#include"constant.c"
/* ¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª- */
/* the state registers of LFSR */
u32 LFSR_S0;
u32 LFSR_S1;
u32 LFSR_S2;
u32 LFSR_S3;
u32 LFSR_S4;
u32 LFSR_S5;
u32 LFSR_S6;
u32 LFSR_S7;
u32 LFSR_S8;
u32 LFSR_S9;
u32 LFSR_S10;
u32 LFSR_S11;
u32 LFSR_S12;
u32 LFSR_S13;
u32 LFSR_S14;
u32 LFSR_S15;
/* the registers of F */
u32 F_R1;
u32 F_R2;
/* the outputs of BitReorganization */
u32 BRC_X0;
u32 BRC_X1;
u32 BRC_X2;
u32 BRC_X3;

/* ¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª- */
/* c = a + b mod (2^31 ¨C 1) */
u32 AddM(u32 a, u32 b)
{
    u32 c = a + b;
    return (c & 0x7FFFFFFF) + (c >> 31);
}
/* LFSR with initialization mode */
#define MulByPow2(x, k) ((((x) << k) | ((x) >> (31 - k))) & 0x7FFFFFFF)

void LFSRWithInitialisationMode(u32 u)
{
    u32 f, v;
    f = LFSR_S0;
    v = MulByPow2(LFSR_S0, 8);
    f = AddM(f, v);
    v = MulByPow2(LFSR_S4, 20);
    f = AddM(f, v);
    v = MulByPow2(LFSR_S10, 21);
    f = AddM(f, v);
    v = MulByPow2(LFSR_S13, 17);
    f = AddM(f, v);
    v = MulByPow2(LFSR_S15, 15);
    f = AddM(f, v);
    f = AddM(f, u);
    /* update the state */
    LFSR_S0 = LFSR_S1;
    LFSR_S1 = LFSR_S2;
    LFSR_S2 = LFSR_S3;
    LFSR_S3 = LFSR_S4;
    LFSR_S4 = LFSR_S5;
    LFSR_S5 = LFSR_S6;
    LFSR_S6 = LFSR_S7;
    LFSR_S7 = LFSR_S8;
    LFSR_S8 = LFSR_S9;
    LFSR_S9 = LFSR_S10;
    LFSR_S10 = LFSR_S11;
    LFSR_S11 = LFSR_S12;
    LFSR_S12 = LFSR_S13;
    LFSR_S13 = LFSR_S14;
    LFSR_S14 = LFSR_S15;
    LFSR_S15 = f;
    
}
/* LFSR with work mode */
void LFSRWithWorkMode()
{
    u32 f, v;
    f = LFSR_S0;
    v = MulByPow2(LFSR_S0, 8);
    f = AddM(f, v);
    v = MulByPow2(LFSR_S4, 20);
    f = AddM(f, v);
    v = MulByPow2(LFSR_S10, 21);
    f = AddM(f, v);
    v = MulByPow2(LFSR_S13, 17);
    f = AddM(f, v);
    v = MulByPow2(LFSR_S15, 15);
    f = AddM(f, v);
    /* update the state */
    LFSR_S0 = LFSR_S1;
    LFSR_S1 = LFSR_S2;
    LFSR_S2 = LFSR_S3;
    LFSR_S3 = LFSR_S4; 
    LFSR_S4 = LFSR_S5;
    LFSR_S5 = LFSR_S6;
    LFSR_S6 = LFSR_S7;
    LFSR_S7 = LFSR_S8;
    LFSR_S8 = LFSR_S9;
    LFSR_S9 = LFSR_S10;
    LFSR_S10 = LFSR_S11;
    LFSR_S11 = LFSR_S12;
    LFSR_S12 = LFSR_S13;
    LFSR_S13 = LFSR_S14;
    LFSR_S14 = LFSR_S15;
    LFSR_S15 = f;
}
/* BitReorganization */
void BitReorganization()
{
    BRC_X0 = ((LFSR_S15 & 0x7FFF8000) << 1) | (LFSR_S14 & 0xFFFF);
    BRC_X1 = ((LFSR_S11 & 0xFFFF) << 16) | (LFSR_S9 >> 15);
    BRC_X2 = ((LFSR_S7 & 0xFFFF) << 16) | (LFSR_S5 >> 15);
    BRC_X3 = ((LFSR_S2 & 0xFFFF) << 16) | (LFSR_S0 >> 15);
}
#define ROT(a, k) (((a) << k) | ((a) >> (32 - k)))
///* L1 */
//u32 L1(u32 X)
//{
//    return (X ^ ROT(X, 2) ^ ROT(X, 10) ^ ROT(X, 18) ^ ROT(X, 24));
//}
///* L2 */
//u32 L2(u32 X)
//{
//    return (X ^ ROT(X, 8) ^ ROT(X, 14) ^ ROT(X, 22) ^ ROT(X, 30));
//}

/*L1*/
#define L1(w1,w2) (L1_list3[(w1>>8)&0xff]^L1_list2[w1&0xff]^L1_list1[(w2>>24)&0xff]^L1_list0[(w2>>16)&0xff])

/*L2*/
#define L2(w1,w2)  (L2_list3[(w2>>8)&0xff]^L2_list2[w2&0xff]^L2_list1[(w1>>24)&0xff]^L2_list0[(w1>>16)&0xff])

#define MAKEU32(a, b, c, d) (((u32)(a) << 24) | ((u32)(b) << 16)\
        | ((u32)(c) << 8) | ((u32)(d)))

/* F */
u32 F()
{
    u32 W, W1, W2, u, v;
    W = (BRC_X0 ^ F_R1) + F_R2;
    W1 = F_R1 + BRC_X1;
    W2 = F_R2 ^ BRC_X2;
    u = L1(W1,W2);
	v = L2(W1,W2);
    //u = L1((W1 << 16) | (W2 >> 16));
    //v = L2((W2 << 16) | (W1 >> 16));
    F_R1 = MAKEU32(S0[u >> 24], S1[(u >> 16) & 0xFF],
            S0[(u >> 8) & 0xFF], S1[u & 0xFF]);
    F_R2 = MAKEU32(S0[v >> 24], S1[(v >> 16) & 0xFF],
            S0[(v >> 8) & 0xFF], S1[v & 0xFF]);
    return W;
}
#define MAKEU31(a, b, c) (((u32)(a) << 23) | ((u32)(b) << 8) | (u32)(c))
/* initialize */
void Initialization(u8* k, u8* iv)
{
    u32 w, nCount;
    /* expand key */
    LFSR_S0 = MAKEU31(k[0], EK_d[0], iv[0]);
    LFSR_S1 = MAKEU31(k[1], EK_d[1], iv[1]);
    LFSR_S2 = MAKEU31(k[2], EK_d[2], iv[2]);
    LFSR_S3 = MAKEU31(k[3], EK_d[3], iv[3]);
    LFSR_S4 = MAKEU31(k[4], EK_d[4], iv[4]);
    LFSR_S5 = MAKEU31(k[5], EK_d[5], iv[5]);
    LFSR_S6 = MAKEU31(k[6], EK_d[6], iv[6]);
    LFSR_S7 = MAKEU31(k[7], EK_d[7], iv[7]);
    LFSR_S8 = MAKEU31(k[8], EK_d[8], iv[8]);
    LFSR_S9 = MAKEU31(k[9], EK_d[9], iv[9]);
    LFSR_S10 = MAKEU31(k[10], EK_d[10], iv[10]);
    LFSR_S11 = MAKEU31(k[11], EK_d[11], iv[11]);
    LFSR_S12 = MAKEU31(k[12], EK_d[12], iv[12]);
    LFSR_S13 = MAKEU31(k[13], EK_d[13], iv[13]);
    LFSR_S14 = MAKEU31(k[14], EK_d[14], iv[14]);
    LFSR_S15 = MAKEU31(k[15], EK_d[15], iv[15]);
    /* set F_R1 and F_R2 to zero */
    F_R1 = 0;
    F_R2 = 0;
    nCount = 32;
    while (nCount > 0)
    {
        BitReorganization();
        w = F();
        LFSRWithInitialisationMode(w >> 1);
        nCount --;
    }
    BitReorganization();
    F(); /* discard the output of F */
    LFSRWithWorkMode();
}

void GenerateKeystream(u32* pKeystream, int KeystreamLen)
{
    int i;
    for (i = 0; i < KeystreamLen; i ++)
    {
        BitReorganization();
        pKeystream[i] = F() ^ BRC_X3;
        LFSRWithWorkMode();
    }
} 


