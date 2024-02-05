// Description: Função que transforma uma string em lowercase.
// Complexidade: O(n) onde n é o tamanho da string.
string to_lower(string a) { 
   for (int i=0;i<(int)a.size();++i) 
      if (a[i]>='A' && a[i]<='Z') 
         a[i]+='a'-'A'; 
   return a; 
}

// para checar se é lowercase: islower(c);

// Description: Função que transforma uma string em uppercase.
// Complexidade: O(n) onde n é o tamanho da string.
string to_upper(string a) { 
   for (int i=0;i<(int)a.size();++i) 
      if (a[i]>='a' && a[i]<='z') 
         a[i]-='a'-'A'; 
   return a; 
}

// para checar se e uppercase: isupper(c);