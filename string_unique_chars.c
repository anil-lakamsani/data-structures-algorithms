/* Assuming that the given string is ASCII string,
find if the given string is made up of unique characters or not*/
int unique(char* str, int len){
    int i=0;
    int H[128] = {0};//Hash table that holds the count of each character
    
    /*if the length of the given string is greater than 128,
    then return, as an ASCII string can only have 128 unique characters*/
    if(len > 128){
        return -1;
    }else if(len < 1){
        return 0;
    }
    
    /* For every character in the string, add the count to
    the hash table*/
    while(str[i]!='\0'){
        if(H[str[i]] == 0){
            //printf("%d\n", str[i]);
            H[str[i]] = 1;
            i++;
        }
        else{//If the count becomes one and the same character is present in the string, then return
            return -1;
        }
    }
  return 1;
}

int main() {
    char A[]="~abcdefghijk%";
    if (unique(A, strlen(A)) == 1){
      printf("The string has all unique characters\n");  
    }
    else if(unique(A, strlen(A)) == 0) {
      printf("The string is Null\n");          
    }
    else{
        printf("The string has duplicates\n");
    }
}
