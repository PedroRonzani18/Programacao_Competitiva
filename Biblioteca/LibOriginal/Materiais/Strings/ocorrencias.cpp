// Description: Função que retorna um vetor com as posições de todas as ocorrências de uma substring em uma string.
// Complexidade: O(n * m) onde n é o tamanho da string e m é o tamanho da substring.
vector<int> ocorrencias(string str,string sub){
    vector<int> ret;
    int index = str.find(sub);
    while(index!=-1){
    	ret.push_back(index);
    	index = str.find(sub,index+1);
    }
    
    return ret;
}