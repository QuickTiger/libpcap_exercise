/*
libpcap exercise first one 
        Founction:
get first device can use 
*/
#include<pcap.h>
#include<stdio.h>

int main()
{
    char errBuf[PCAP_ERRBUF_SIZE],*device;

    device = pcap_lookupdev(errBuf);

    if(device)
    {
        printf("Success :device :%s \n",errBuf);
    }
    else
    {
        printf("error: %s \n",errBuf);
    }
    return 0;
}
