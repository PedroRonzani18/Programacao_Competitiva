// Descricao: Funcao que divide uma string em um vetor de strings.
// Complexidade: O(n * m) onde n eh o tamanho da string e m eh o tamanho do delimitador.
vector<string> split(string s, string del = " ") {
   vector<string> retorno;
   int start, end = -1*del.size();
   do {
       start = end + del.size();
       end = s.find(del, start);
       retorno.push_back(s.substr(start, end - start));
   } while (end != -1);
   return retorno;
}