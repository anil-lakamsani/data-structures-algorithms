/* Given a string "aaaabbbccd", return the compressed version of it
"a4b3c2d1" if the length of the compressed string is less than the orginal string
else return the original string (i.e orginal string "abcd" and the compressed string
is "a1b1c1d1", retun "abcd"*/

#include <string.h>
char* compressOrNot(char *str1, int strlen1){
    int i=0,j=0, count=0, len=0;
    char *temp;
    int H[128] = {0};//Has table to hold the number of occurances of a character
    if(strlen1 == 0){
       return NULL;
    }
    /* Fill in the has table with the character occurance*/
    while(str1[i] != '\0'){
        H[str1[i++]] += 1;
    }
    //Create a compressed buffer called temp and allocate ((2*strlen(of original string))+1)
    temp = (char*)malloc((2* strlen1 +1) *sizeof(char));    
    while(H[str1[j]] > 0){
          if(str1[j] == str1[j+1]){//While reading the values from the Hash table ignore the reputations
             j++;  
          }
          else{
            //copy the character and the value of its occurances to compressed string temp
            len += sprintf(temp+len, "%c%d",str1[j],H[str1[j]]);
            j++;
         }
    }

    if(strlen(str1) < len){
        printf("returning the original string\n");
        return str1;
    }
    else{
        printf("returning the compresed string\n");
        return temp;
    }   
}

int main() {
    char A[]="aaaabbbccccddddeeff";//"abcdefghijklmnopqrstuvw";
    printf("%s", compressOrNot(A,strlen(A)));
}
