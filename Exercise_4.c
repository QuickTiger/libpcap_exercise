/*
Founction:
get packets streaem and use a handler to process packets
*/
#include<stdio.h>
#include<stdlib.h>
#include<pcap.h>
#include<time.h>

#define devStr "wlan0"

void getPacket(u_char* arg,const struct pcap_pkthdr* pkthdr,const u_char * packet)
{
       int * id = (int *)arg;

       printf("id: %d\n",++(*id));
       printf("Packrt length: %d \n",pkthdr->len);
       printf("Number of bytes: %d \n",pkthdr->caplen);
       printf("Time : %s \n",ctime((const time_t *)&pkthdr->ts.tv_sec));

       int i ;
       for(i=0;i<pkthdr->len;++i)
       {
           printf(" %02x",packet[i]);
           if( (i+1)%16==0)
           {
               printf("\n");
           }
       }
   
}
int main()
{
    char errBuf[PCAP_ERRBUF_SIZE];
    pcap_t * session = pcap_open_live(devStr,65535,1,0,errBuf);

    if (!session)
    {
        printf("error in open %s: \n ",devStr);
        exit(1);
    }

    int id = 0;

    pcap_loop(session,-1,getPacket,(u_char*)&id);

    pcap_close(session);
    
    return 0;
}
