// Split de String
//
// O(|s| * |del|).
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
