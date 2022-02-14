//
//  wav_header.c
//  main
//
//  Created by Sammuel Diaz on 2/13/22.
//

#include "wav_header.h"


// Build wave header

struct wav_header
{
    char RIFF [4]; // RIFF
    char format [4]; // shoul be 1??
    char fmt [4]; // array? fmt
    unsigned long c_Size;
    unsigned long chunk_size_s; //var for sub data 16
    unsigned short aFormat;// var for format of file
    unsigned short nChannels;// var for numb of channels
    unsigned long rate;// var for the number of amps per sec
    unsigned long byte_rate;// rate*nchannel*bitsps
    unsigned short align; /// nchan*bps/8
    unsigned short bits_per_sample; // the numb of bits per samp 8 or 16

};

// chunks
struct chunk_1
{
    //size and array-id chunk
    unsigned long size;
    char id[4];
    
};

void reader (const char* fName, const char* fSave)//read file and print
{
    FILE *fin = fopen(fName,);


    wav_header header;
    fread(&header, sizeof(header), 1, fin);

    
    printf(".wav header read out:\n");
    printf("file type is: %s\n", header.RIFF);
    printf("file size is: %ld\n", header.c_Size);
    printf(".wav marker is: %s\n", header.format);
    printf("fornat name is: %s\n", header.fmt);
    printf("format length: %ld\n", header.chunk_size_s );
    printf("format type is: %hd\n", header.aFormat);
    printf("file's number of channels are: %hd\n", header.nChannels);
    printf("sample rate is: %ld\n", header.rate);
    printf("bytes rate is : %ld\n", header.byte_rate);
    printf("align is: %hd\n", header.align);
    printf("bits per sample are: %hd\n", header.bits_per_sample);


    // handle chunks
       chunk_1 chunk;
       printf("id\t" "size\n");
    
       while (true)
       {
           fread(&chunk, sizeof(chunk), 1, fin);
           printf("%c%c%c%c\t" "%li\n",
                  chunk.id[0],
                  chunk.id[1],
                  chunk.id[2],
                  chunk.id[3],
                  chunk.size);
       
           if (*(unsigned int *)&chunk.id == 0x61746164)
                       break;
       }

     // handle samples
       int sample_size = header.bits_per_sample / 8;
       int sampCount = chunk.size * 8 / header.bits_per_sample;
       printf("samples = %i\n", sampCount);

       short int *value = new short int[sampCount];
       memset(value, 0, sizeof(short int) * sampCount);
    
}


   int main()
   {
       reader ("/Users/Shoxtech/Desktop/School/CSCI_3731/CSCI3731/hw04/main/OAB INTRO.wav", "list.dat" );
       return 0;
   }





/* seems to kinda work, my output is below. had a  error (libc++abi.dylib: terminating with uncaught exception of type std::bad_alloc: std::bad_alloc)
 
 main % ./testV1.o
 .wav header read out:
 file type is: ID3
 file size is: 3544387882321970688
 .wav marker is:
 fornat name is: <TYER
 format length: 92639295963193
 format type is: 1536
 file's number of channels are: 0
 sample rate is: 76198245040183
 bytes rate is : 3474580988586100224
 align is: 56
 bits per sample are: 21072
 id    size
 <?xp    22603038489369877
 "﻿    4426591376555253876
 Cehi    8092177213620167229
 9d"?    7163954199297686099
  xml    7022349239689508922
 ns:m    4207877657412575805
 k="A    8390326468935688226
 e 5.    8245883248803928096
 3765    3904953175179802676
 -18:    3761120527116089649
  ">
     2314885530818453558
 lns:    7888090233505462886
 www.    3400000498352547874
 02/2    3402813911256229746
 -ns#    8674342375125101926
 scri    7297021507693329440
 out=    7089011499904147566
 :xmp    8317704779222491168
 adob    3347140097001287796
 0/"
     3328493759321616237
 pMM=    7888119014787673464
 dobe    7002661387682921072
 /mm/    3471766442567890991
 stEv    4211831488493658144
 .ado    8317637441690301556
 .0/s    3544174995694382447
 eEve    7165919078637720111
 ns:s    7813033007930941450
 /ns.    3403156113903329853
 p/1.    7023415765951000165
 urce    8030873964188627065
 lns:    7888090069689436706
 url.    8083731784194618472
 nts/    7308609286520660836
 lns:    7888090069689436706
 /ns.    3403156113903329853
 f/be    8602490385297780325
  xml    2314885436363714606
 om="    8377102604905309554
 obe.    7233113549838430010
 tom/    4715954305451258467
 lns:    7888090069689436706
 //ns    4210993694903516493
 mp/1    8660260933629535586
 dia/    7299599875495259769
 ator    7309979063449122848
 Audi    2334380212424352317
 acin    5559729135589404960
 p:Cr    7888090069688001065
 19-0    3472875909746549060
 4-10    3475151842256105812
 Meta    4210986014293893130
 19-0    3472875909746549060
 2-10    3763375621337526356
 Modi    4210986014293893130
 -07-    4121128125901661556
 10:0    3256722905097058864
 Inst    4201099172674805792
 iid:    3346294885874222153
 0-4e    7221350672891209062
 f250    3631090293395644769
 MM:D    8101263384082647586
 mp.d    8656548797258952293
 d7d0    3258413040025155892
 9d2f    7074371481051409764
 xmpM    2314885436364383332
 cume    8017652402346354537
 d:95    7594245932061303357
 4540    3257283840760952673
 aa0a    7017001179745037670
 rmat    8027167584390488096
 "
       7450484772803930468
 atio    7956003919315810932
 07-2    3258689888448560485
 rigi    8014846547305046048
 00:0    2467239691461881455
 t:ti    8675448147316574754
 "0">    4424051534760928614
 isto    5204557314374072380
 :Seq    7378147692102295584
 li
      4208161343622094880
 ctio    7006040221648450336
         2314861351297971809
 ceID    7953766456035457652
 e10a    3835160760622329456
 -8c2    3473459710822462053
 51"
     7003204491434616165
 when    4212121592176779296
 T18:    4121124849075435825

        2463522022646426932
 twar    7381245009182737780
 e Au    7092998169041925230
 (Mac    2319686076179967599
    s    2314885436363335795
 ="/m    7234302100218864442
         2308726131141997665
   st    2314885530454158394
 save    2467249595658560353
 vt:i    5004751667730587680
 mp.i    8656548797257966446
 ed06    3256210502731446116
 5aa7    7362593979461348709
    s    2314885436364186466
 019-    3612517395461601082
 42-1    4193467229510063152
 stEv    2314885530818447906
 ent=    7440339601328665702
 ion     8388346235720852834
 osh)    8389759031392938016
 t:ch    8522345907677569056
 data    7022349238594059620
 samples = -2098265808
 libc++abi.dylib: terminating with uncaught exception of type std::bad_alloc: std::bad_alloc
 zsh: abort      ./testV1.o
 
*/
