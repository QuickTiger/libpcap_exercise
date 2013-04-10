/*
Founction:

Get one packet from a hard-conded device

*/
#include<stdio.h>
#include<pcap.h>
#include<time.h>
#include<stdlib.h>


int main()
{
    char errBuf[PCAP_ERRBUF_SIZE],* devStr;

    /*get a device*/
    //devStr = pcap_lookupdev(errBuf);
    devStr="wlan0";
    if(devStr)
    {
        printf("Scuess :device :%s\n",devStr);
    }
    else
    {
        printf("Error : %s\n",errBuf);
        exit(1);
    }

    /*open a device ,wait ubtil a packet arrives*/

    pcap_t * device = pcap_open_live(devStr, 65535, 1, 0, errBuf);

    if(!device)
    {
        printf("error: pcap_open_live() : %s\n",errBuf);
        exit(1);
    }


    /* wait a packet to arrive*/
    struct pcap_pkthdr packet;
    const u_char * pktStr=pcap_next(device,&packet);

    if(!pktStr)
    {
        printf("did not capture a packet!\n");
        exit(1);
    }

    printf("length: %d\n",packet.len);
    printf("Number of bytes: %d\n",packet.len);
    printf("time: %s\n",ctime((const time_t *)&packet.ts.tv_sec));

    pcap_close(device);

    return 0;
}
