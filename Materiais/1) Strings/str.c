#include <stdio.h>
#include <string.h>

void replace_new(char* str, char* alvo, char* new_) {
    int found_count = 0;

    for(int i=0; str[i] != '\0'; i++) {
        printf("letrinha: %c\n",str[i]);
        if(str[i] == alvo[0]) {
            int found = 1;
            int walked = 0;
            for(int j=0; j<strlen(alvo); j++, walked++) {

                if(str[i+j] = '\0') {}

                printf("letrixxx: %c %c\n",alvo[j], str[i+j]);
                if(alvo[j] != str[i+j]){
                    printf("Entrei\n");
                    found = 0;
                }
            }
            if(found == 1) found_count ++;
            i += walked;
        }
    }

    printf("f: %d\n",found_count);
}

int main()
{/*
    for(auto x : find_all_occurrencies("STR AAA STR AAAAAAAA STR", "STR"))
        cout << x << " ";
    cout << endl;
    */
   replace_new("STR AAA STR AAAAAAAA S", "STR", "A");
}