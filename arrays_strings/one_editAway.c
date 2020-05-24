/* Check if the given string s2 is one edit away from the actual string s1
int oneeditAway(char *str1, char *str2, int strlen1, int strlen2){
    int i=0,j=0, count =0;
    int H[128] = {0};
    if( (strlen2 != strlen2) ){
        if((strlen2 != strlen1 + 1) || (strlen2 != strlen1-1)){
            return -1;
        }
    }
    
    while(str1[i] != '\0'){
        H[str1[i++]] += 1;
    }
    
    while(str2[j] != '\0'){
        if(H[str2[j++]] == 0){
            count ++;
        }
        if(count > 1){
            return -1;
        }
    }
return 1;    
}
int main() {
    char A[]="pale";
    char B[]="pales";//"bale", "ale", "pales", "bake"
    if(oneeditAway(A, B, strlen(A), strlen(B)) == 1){
        printf("The given string is one edit away from the parent string\n");
    }
    else{
        printf("The given string is not one edit away\n");
    }
}
