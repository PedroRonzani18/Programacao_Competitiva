/**
 *  @brief  str.find() aprimorado
 *  @param str  string to be analised
 *  @param sub  substring to be searched
 *  @return  vector<int> com indices de todas as ocorrências de uma substring em uma string
 */
vector<int> ocorrencias(string str,string sub){
    
    vector<int> ret;
    int index = str.find(sub);
    while(index!=-1){
    	ret.push_back(index);
    	index = str.find(sub,index+1);
    }
    
    return ret;
}