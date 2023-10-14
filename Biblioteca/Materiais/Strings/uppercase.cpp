string to_upper(string a) { 
   for (int i=0;i<(int)a.size();++i) 
      if (a[i]>='a' && a[i]<='z') 
         a[i]-='a'-'A'; 
   return a; 
}
