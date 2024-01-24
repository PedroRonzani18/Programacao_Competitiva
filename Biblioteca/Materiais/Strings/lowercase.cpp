string to_lower(string a) { 
   for (int i=0;i<(int)a.size();++i) 
      if (a[i]>='A' && a[i]<='Z') 
         a[i]+='a'-'A'; 
   return a; 
}

// para checar se é lowercase: islower(c);