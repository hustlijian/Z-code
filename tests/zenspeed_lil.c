#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#include "../zcode.h"

#define NUM (2*1024*1024*1024UL)

#ifndef MSG
    #define MSG 0
#endif

void help(const char *file)
{
    printf("Usage: %s [m k datasize packetsize]\n\n", file);
    printf("  m:\t\t parity devices number(2)\n");
    printf("  k:\t\t data devices number(3)\n");
    printf("  datasize:\t the  data size(MB)(512M)\n");
    printf("  packetsize:\t the process unit(KB)(2KB)\n");
}

int main(int argc, char const* argv[])
{
    z_info_t zcode;

    int m = 2;  // init to 2, parity deveices number
    int k = 3;  // init to 3, data devices number
    int datasize = 512*1024*1024; // init to 512M, file size
    int packetsize = 2*1024; // init to 2KB, process unit 
    unsigned char *pdata, *psrc, *pdes, *pdes2;

    if (argc>1 && !strcmp(argv[1], "-h")) {
        help(argv[0]);
        return 0;
    }

    if (argc>1) m = atoi(argv[1]);
    if (argc>2) k = atoi(argv[2]);
    if (argc>3) datasize = atoi(argv[3])*1024*1024; // MB
    if (argc>4) packetsize = atoi(argv[4])*1024; // KB

    //printf("data size : %.1fMB  \n", (datasize*1.0)/(1024.0*1024.0));
    //printf("packet size:%.1fKB  \n", (packetsize*1.0)/(1024.0));

    int r;
    // test zcode init
    r = z_init(&zcode, m, k, datasize, packetsize);
    //printf("main block_size : %d\n",zcode.blocksize);

    // init data 
    pdata = (unsigned char *)malloc((2*m+k)*r*zcode.blocksize);

    // test zcode encode
    //printf("Encode zcode:\n");
    psrc = pdata;
    pdes = pdata + (k*r*(zcode.blocksize));
    pdes2 = pdes + (m*r*(zcode.blocksize));
    memset(pdes, 0, 2*m*r*(zcode.blocksize));

#if MSG==1
    printf("n:%d, k:%d, row:%d col:%d\n", m+k, k, LIL_ROW(m,k), LIL_COL(m,k));
    printf("blocksize : %.4f\n", zcode.blocksize/(1024.0*1024.0));
    printf("filesize : %.4f\n", (zcode.blocksize*LIL_COL(m,k))/(1024.0*1024.0));
#endif

    int times = NUM/datasize;
    int i;
    struct timeval begin, end;
    double tsize_mb;
    double time_cost;

#if MSG==1
    printf("ppg\t\tpbg\n");
#endif

#if MSG==0
    printf("(%d,%d)\t",m,k);
    printf("%d\t", datasize/(1024*1024));
#endif

    // -----------------------------------
    z_encode(&zcode, psrc, pdes);
    gettimeofday(&begin, NULL);
    for (i = 0; i < times; i++) {
        z_encode(&zcode, psrc, pdes);
    }
    gettimeofday(&end, NULL);
    tsize_mb = (datasize/(1024.0*1024.0));
    tsize_mb = tsize_mb*times;
    time_cost = end.tv_sec-begin.tv_sec+(end.tv_usec-begin.tv_usec)/(1000.0*1000.0);
    printf("%.3f\t", tsize_mb*1.0/time_cost);
    

    // -----------------------------------
    z_encode_dpg(&zcode, psrc, pdes2);
    gettimeofday(&begin, NULL);
    for (i = 0; i < times; i++) {
        z_encode_dpg(&zcode, psrc, pdes2);
    }
    gettimeofday(&end, NULL);
    tsize_mb = (datasize/(1024.0*1024.0));
    tsize_mb = tsize_mb*times;
    time_cost = end.tv_sec-begin.tv_sec+(end.tv_usec-begin.tv_usec)/(1000.0*1000.0);
    printf("%.3f\t", tsize_mb*1.0/time_cost);


    printf("\n");
    z_free(&zcode);
    free(pdata);

    return 0;
}
