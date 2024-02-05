// Descricao: Funcao que remove acentos de uma string.
// Complexidade: O(n * m) onde n eh o tamanho da string e m eh o tamanho do alfabeto com acento.
string removeAcentro(string str) {

    string comAcento = "áéíóúâêôãõà";
    string semAcento = "aeiouaeoaoa";

    for(int i = 0; i < str.size(); i++){
        for(int j = 0; j < comAcento.size(); j++){
            if(str[i] == comAcento[j]){
                str[i] = semAcento[j];
                break;
            }
        }
    }

    return str;
}