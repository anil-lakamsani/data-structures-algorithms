/* if given two strings, find if one is a permuation of the other
for example: "abbc" is a permutation of "bcba", wher as "abcd" is
not a permutation of "bcba"
*/
int permutation(char *str1, char *str2, int strval1, int strval2){
    int i=0, j=0;
    int H[128]={0};//Hash table that holds the no of occurances
    
    /*If string lengths are 0, then return, if string lengths
    are not equal then return as well */
    if(strval1 == 0 || strval2 ==0){
        return 0;
    }else if(strval1 != strval2){
        return -1;
    }
    
    //First fill the Hash table with occurances in str1
    while(str1[i] != '\0'){
        H[str1[i++]] += 1;
    }
    
    //Go thorugh str2 and decremnet the count in the hash table
    while(str2[j] != '\0'){
        //printf("%d and %d and %d\n", j,str2[j], H[str2[j]]);
        if(H[str2[j]] > 0){
            H[str2[j++]] -= 1;
        }
        else{//if the number of occurances in the hash table become 0, then retun -1
            return -1;
        }
    }
return 1;
}

int main() {
    char A[]="abcdb";
    char B[]="dbcab";
    if (permutation(A, B, strlen(A), strlen(B)) == 1){
      printf("The string A is a permutation of string B\n");  
    }
    else if((A, B, strlen(A), strlen(B)) == 0) {
      printf("One of the strings is \n");          
    }
    else{
        printf("The strings are not a permutation of each other\n");
    }
}
