#include <bits/stdc++.h>

using namespace std;

/**
 *  @brief  str.find() aprimorado
 *  @param str  string to be analisedaaaaa
 *  @param sub  substring to be searched
 *  @return  vector<int> com indices de todas as ocorrências de uma substring em uma string
 */
vector<int> find_all_occurrencies(string str,string sub){
    
    vector<int> ret;
    int index = str.find(sub);
    while(index!=-1){
    	ret.push_back(index);
    	index = str.find(sub,index+1);
    }
    
    return ret;
}

void replace_new(char* str, char* alvo, char* new_) {
    int found_count = 0;

    for(int i=0; str[i] != '\0'; i++) {
        if(str[i] == alvo[0]) {
            int found = 1;
            int walked = 0;
            for(int j=0; j<strlen(alvo) && str[i+j] != '\0'; j++, walked++) {
                if(alvo[j] != str[i+j]){
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
   replace_new("STR AAAAAAAA", "STR", "A");
}