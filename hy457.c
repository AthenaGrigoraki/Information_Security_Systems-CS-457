#include <stdio.h> 
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include <unistd.h>
#include <inttypes.h>
#include <time.h>


#include "hy457.h"

int get_length(uint8_t *plaintext){
    int len=0;
    uint8_t *get_text=plaintext;
    while(*(get_text++) != '\0'){
        len++;
    }


    return len;
}


/***************************************OTP*************************************/

uint8_t *get_key(int size){
    
    int i;
    int upper=126;
    int lower=33;

    uint8_t *key;
    key = (uint8_t*)malloc(size * sizeof(uint8_t));
     srand ( time(NULL) );
    
   /* myFile = open("/dev/urandom", O_RDONLY);
    printf("My file : %d\n", myFile);
    key = calloc(size + 1, sizeof(uint8_t));
    read(myFile, &key,size);
    
    close(myFile);*/

    for(i=0; i<size; i++){
        key[i]= ((rand() % (upper - lower + 1)) + lower);
        

    }

       printf("key(as decimals):\n");
        for(i = 0; i < size; ++i)
                printf("%u-", (unsigned char)key[i]);       
    printf("\n");
     printf("\nText entered as key: %s, %d chars\n", key, size);
    return key;


}

uint8_t *one_time_pad_encr(uint8_t *plaintext,uint8_t *key){
    
    int len=get_length(plaintext);
    uint8_t* chiper=malloc(len);
    int i;
    if(plaintext == NULL || key == NULL){
        printf("Empty parameters\n");
        return NULL;
    }

    printf("encrypted:\n");

    for(i=0; i<len; i++){
        chiper[i]=(unsigned char)(plaintext[i]^key[i]);
        
        printf("%c",(char)chiper[i]);
    }
    printf("\n");
    
    return chiper;
}

uint8_t *one_time_pad_dencr(uint8_t *cipertext,uint8_t *key,int size){

    
    uint8_t  *dec_chiper=malloc(size);
    int i;
    
    printf("decrypted:\n");
    
    if(cipertext == NULL || key == NULL){
        printf("Empty parameters!\n");
        return NULL;
    }

    for(i=0; i<size; i++){
        dec_chiper[i]=(unsigned char)(cipertext[i]^key[i]);
        printf("%c",(char)dec_chiper[i]);
    }
    printf("\n");
    
    return dec_chiper;

}

void word_decryption(uint8_t *key){
   /* uint8_t *dec1,*dec2;
    int len1,len2;
    uint8_t first_word[8] = {'e9','3a','e9','c5','fc','73','55','d5'};
    uint8_t second_word[8] = {'f4','3a','fe','c7','e1','68','4a','df'};
    int i;


    len1=get_length(first_word);
    len2=get_length(second_word);
    
    dec1=malloc(len1);
    dec2=malloc(len2);
    dec1=one_time_pad_dencr(first_word,key,len1);
    dec2=one_time_pad_dencr(second_word,key,len2);

    */

}

/*************************rail fence********************************************/


uint8_t *rail_fence_encr(uint8_t *plaintext,int rails){
    int len=get_length(plaintext);
  //  uint8_t *chiper=malloc(len);
    char chiper1[len][rails];
    int i,j,x=-1;
    int m=0;
    int comp;
    int new_length=len-1;
    printf("len is %d and rails are %d\n", len, rails);
    int rows=0,columns=0;
    if(plaintext == NULL){
        printf("Empty parameters\n");
        return NULL;
    }
    
  /*  if(rails == 0){
        printf("rails not entered correctly!\n");
    }*/

    
    

    for(i=0; i<rails; i++){
        
        for(j=0; j<new_length; j++){
            
            
           
            chiper1[i][j]='\n';
            


        }
        
    }
    
   
    comp=(rails-1);
    
    for(i=0; i<new_length; i++){
       
        
        chiper1[rows][columns++]=(char)plaintext[i];
        
        printf("%c", chiper1[rows][i]);
        
        if((rows == 0) || (rows == comp)){
            
            x=x*(-1);
        }
           
        rows= rows + x;
           
            
    }      
   // chiper[rows*rails + columns++];   
 
/*
    printf("Encrypted Message: \n");
    for(i = 0; i < rails; i++){ 
        for(j=0; j<new_length; j++){
            if(chiper1[i][j] != '\n'){
              /* printf("positions where text %d,%d\n",i,j);
                printf("m is %d\n", m);
              /*  printf("chiper is %c\n", chiper1[i][j]);
               chiper[m]= chiper1[i][j];
               m++;
              
            }
        }
    
    } 
    
    for (i=0; i<new_length; i++){
        printf("%c", chiper[i]);
    }
    
    return chiper;  */

     
   



}

uint8_t **rail_fence_decr(uint8_t *cipertext,int rails){
 /*   int len=get_length(cipertext);
    uint8_t** decr=malloc((len*rails)*sizeof(uint8_t*));
    int i,j,x=-1;
    
    int rows=0,columns=0;
    printf("\nmpainei\n");
    if(cipertext == NULL){
        printf("Empty parameters\n");
        return NULL;
    }

    printf("len %d\n", len);
     for(i=0; i<rails; ++i){
        
        for(j=0; j<len; ++j){
            
            
            decr[i][j]='\n';

        }

    }

    /*

    for(i=0; i<len; i++){

        decr[rows][columns++]='-';
        
        if((rows == 0) || (rows == (rails-1))){
            x=x*(-1);
        }
            rows= rows + x;
            printf("rows are %d\n",rows);
           
            
    }

    for(i = 0; i < rails; ++i){
        
        for(j=0; j<len; j++){
            if(decr[i][j] == '-'){
                decr[i][j]=cipertext[j++];
                printf("%c", (char*)decr[i][j]);
            }
        }
    }

    rows = columns = 0;
    x = -1;
 
    printf("\nDecrypted Message: ");

    for(i=0; i<len; i++){
        printf("%c", (char*)decr[i][j++]);
        if((rows == 0) || (rows=(rails-1))){
            x= x * (-1);
        }
        rows=rows+x;
    }*/

}

/****************************************Affine**********************************************/

uint8_t *affine_encr(uint8_t *plaintext){
    int len=get_length(plaintext);
    uint8_t* chiper=malloc(len);
    int a=11,b=19,m=26;

    int position=0;
    int encoding;
    int i;

    for (i=0; i<(len); i++){

        if((plaintext[i] < 'A') || (plaintext[i] > 'Z')){
            printf("some chars entered are not capital latin, only the capital ones get encrypted!\n");
            continue;
        }
        position=plaintext[i] - 'A';
       /* printf("position is %d\n", position);*/

        encoding= ((a * position) + b) % m;
        /*printf("encoding is %d\n",encoding);*/
        chiper[i]= encoding + 'A';

        if((chiper[i] >= 96) && (chiper[i] <= 123)){
            chiper[i] ^= 0x20;  /*convert lowercase to uppercase if needed*/
        }

    }
    chiper[strlen(chiper) ] = '\0'; /*remove last char*/
    printf("Encrypted text:\n");
    printf("%s\n", chiper);
    
    return chiper;

}

int mod_mult_Inverse(int a, int m) 
{   int x;
    a = a%m; 
    for (x=1; x<m; x++) {
       if((a*x) % m == 1){
           return x;
       } 

    }
    return 0;    
} 

uint8_t *affine_decr(uint8_t *cipertext){
    int len=get_length(cipertext);
    uint8_t* decrypted=malloc(len);
    int a=11,b=19,m=26;
    int mod_mul_inv;
    int position=0;
    int encoding;
    int i,j;
    mod_mul_inv=mod_mult_Inverse(a,m);

    if(mod_mul_inv == 0){
        printf("equation is not satisfied\n");
        exit(0);
    }

    for (i=0; i<len; i++){

        
        position=cipertext[i] - 'A';
        

        encoding= (mod_mul_inv * ((position - b)) % m);

        if(encoding < 0){
            encoding= encoding + 26;
        }else if(encoding >= 26){
            encoding= encoding - 26;
        }

       

        decrypted[i]= encoding + 'A';


    }

    printf("Decrypted : \n");
    decrypted[len  ] = '\0'; /*remove garbage at the end of string*/
    printf("%s\n", decrypted);
    return decrypted;

}
/**********************************feistel****************************************/


uint8_t *get_key_feistel(){
    uint8_t *keys;
    int size=64;
    int i;
    int upper=126;
    int lower=33;
    keys = (uint8_t*)malloc(size * sizeof(uint8_t));

    for(i=0; i<size; i++){

        keys[i]= ((rand() % (upper - lower + 1)) + lower);
        printf("%c-",keys[i]);
    }
    
    return keys;
}

uint8_t *feistel_encr(uint8_t *plaintext, uint8_t *key, int size){
    int len=get_length(plaintext);
    uint8_t* chiper_right=malloc(len/2);
    uint8_t* chiper_left=malloc(len/2);
    int i;
    int n=4; /*rounds*/
    if(plaintext == NULL || key == NULL){
        printf("Empty parameters\n");
        return NULL;
    }




}

/****************************beaufort*******************************************************************/
uint8_t table[]={'A','B','C','D','E','F','G','H','I','G','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

uint8_t *beaufort_encr(uint8_t *plaintext, uint8_t *key){

    
    int len=get_length(plaintext);
    uint8_t* chiper=malloc(len);
    int i,j=0;
    uint8_t letter,key_letter;
    unsigned short n;
    
    
    int key_len=get_length(key);
    uint8_t* new_key=malloc(len);
    int final_pos=0;
    

    int position;
    int chiper_place;
    if(plaintext == NULL || key == NULL){
        printf("Empty parameters\n");
        return NULL;
    }

   /* printf("len of plaintext %d\n",len);*/
   /*get key*/
    for(i=0; i<(len-1); i++){

    
       if(i< (key_len-1)){
       new_key[i]=key[i];
      /* printf("key length is %d and i is %d and char is %c\n", (key_len-1),i,new_key[i]);*/
       
       }else if(i >= (key_len-1)){
           
           new_key[i]=new_key[j];
           j++;
           /*printf(" i is %d extra char in pos %d char is %c\n",i,j, new_key[i]);*/
       }

       /* printf("new key %c\n", new_key[i]);*/
        key[i]=new_key[i];
        
    }
    key[strlen(key)] = '\0'; /*remove last char*/
   
    printf("final key is %s\n", key);


    
    for(i=0; i<(len-1); i++){
        letter=plaintext[i];
        key_letter=key[i];

        /*where alphabet is placed,plaintext*/
        for(j=0; j<26; j++){
            
            if(table[j] == letter){
                position=j;
             /*   printf("position of letter is %d\n",j);*/
                break;
            }
        }

        /*move down column of the table till we find key letter*/
        for(j=position; j<(position+26); j++){
            if(table[j%26] == key_letter){
              /*  printf("key letter is %c and table's position is %d\n", key_letter,(j%26));*/
                final_pos=j%65;
                break;
            }
            
        }

       /* printf("letter is %c\n", letter);
        printf("final pos should be %d\n",((final_pos-position) % 26));*/
        chiper[i] = table[(final_pos-position) % 26];
        

    }
   /* chiper[strlen(chiper)-1] = '\0';*/
    chiper[strlen(chiper)] = '\0'; /*remove last char*/
    printf("Encrypted:\n");
    printf("%s\n", chiper);

    return chiper;


}

uint8_t *beaufort_dencr(uint8_t *cipertext, uint8_t *key){
    int len=get_length(cipertext);
    uint8_t* dec_chiper=malloc(len);
    int i,j=0;

    uint8_t letter,key_letter;
    unsigned short n;
    
    
    int key_len=get_length(key);
    uint8_t* new_key=malloc(len);
    int final_pos=0;
    

    int position;
    int chiper_place;
    if(cipertext == NULL || key == NULL){
        printf("Empty parameters\n");
        return NULL;
    }

    for(i=0; i<(len-1); i++){

    
       if(i< (key_len-1)){
       new_key[i]=key[i];
      /* printf("key length is %d and i is %d and char is %c\n", (key_len-1),i,new_key[i]);*/
       
       }else if(i >= (key_len-1)){
           
           new_key[i]=new_key[j];
           j++;
           /*printf(" i is %d extra char in pos %d char is %c\n",i,j, new_key[i]);*/
       }

       /* printf("new key %c\n", new_key[i]);*/
        key[i]=new_key[i];
        
    }
   /* key[strlen(key)] = '\0'; /*remove last char*/
   
  /*  printf("final key is %s\n", key);*/


    
    for(i=0; i<(len); i++){
        letter=cipertext[i];
        key_letter=key[i];

        /*where alphabet is placed,plaintext*/
        for(j=0; j<26; j++){
            
            if(table[j] == letter){
                position=j;
             /*   printf("position of letter is %d\n",j);*/
                break;
            }
        }

        /*move down column of the table till we find key letter*/
        for(j=position; j<(position+26); j++){
            if(table[j%26] == key_letter){
              /*  printf("key letter is %c and table's position is %d\n", key_letter,(j%26));*/
                final_pos=j%65;
                break;
            }
            
        }

       /* printf("letter is %c\n", letter);
        printf("final pos should be %d\n",((final_pos-position) % 26));*/
        dec_chiper[i] = table[(final_pos-position) % 26];
        

    }
   /* chiper[strlen(chiper)-1] = '\0';*/
   /* dec_chiper[strlen(dec_chiper)] = '\0'; /*remove last char*/
    printf("Decrypted:\n");
    printf("%s\n", dec_chiper);

    return dec_chiper;

}








int main(int argc, char** argv){
    char text[400];
    char dec[400];
    uint8_t *plaintext, *en_cipher, *key,*dec_cipher;
    uint8_t *rail_fence_chiper,**rail_fence_dec;
    char *affine="AFFINECIPHER";
    int rails=0;
    int i,j;
    int len;
    int operation=1;
    
    printf("Choose what encryption algorithm you want\n");
    printf("1 : for One Time Pass Algorithm\n");
    printf("2 : for Rail Fence Algorithm\n");
    printf("3 : for Affine Algorithm\n");
    printf("4 : for Feistel Algorithm\n");
    printf("5 : for Beaufort Algorithm\n");

    scanf("%d\n", &operation);
    
    fflush(stdout);
    switch(operation)
    {
    case 1 :
       
       

        scanf("%s", text);

        plaintext = (uint8_t *)text;

        len=get_length(plaintext);

        key = get_key(len);
    
        en_cipher=one_time_pad_encr(plaintext,key);

        dec_cipher=one_time_pad_dencr(en_cipher,key,len);

        word_decryption(key);


        break;


    case 2 :

        printf("First insert how many rails you want for the railfence:\n");
        scanf("%d", &rails);
        
        printf("Insert text for Rail Fence algorithm:\n");
        fseek(stdin,0,SEEK_END); /*clean buffer of scanf so that i can get input again*/
        

        fgets(dec,sizeof(dec),stdin);
        
        plaintext = (uint8_t *)dec;
        len=get_length(plaintext);
        
        
        rail_fence_chiper= rail_fence_encr(plaintext,rails);

        printf("\nNow enter text to decrypt:\n");
        
       /* fseek(stdin,0,SEEK_END); /*clean buffer of scanf so that i can get input again

        fgets(dec,sizeof(dec),stdin);
        
        en_cipher = (uint8_t *)dec;

        rail_fence_dec=rail_fence_decr(en_cipher,rails); */

        free(rail_fence_chiper);
        break;


    case 3 :

       

        fseek(stdin,0,SEEK_END); /*clean buffer of scanf so that i can get input again*/
       
        fgets(text,sizeof(text),stdin);

        plaintext = (uint8_t *)text;
        
        
        
        en_cipher=affine_encr(plaintext);

        dec_cipher=affine_decr(en_cipher);


        break;


    case 4 :


        get_key_feistel();


        break;


    case 5 :
        

        fseek(stdin,0,SEEK_END); /*clean buffer of scanf so that i can get input again*/

        fgets(text,sizeof(text),stdin);

        plaintext = (uint8_t *)text;

        printf("Insert key for beaufort algorithm:\n");

        fseek(stdin,0,SEEK_END); /*clean buffer of scanf so that i can get input again*/

        fgets(dec,sizeof(dec),stdin);

        key = (uint8_t *)dec;

        en_cipher=beaufort_encr(plaintext,key);

        dec_cipher=beaufort_dencr(en_cipher,key);


        break;
    
    default:
        printf("Error! operator is not correct");
        break;
    }
    
    
    

    return 0;

}