#include <bits/stdc++.h>
using namespace std;

// Encontra o unico elemento mais frequente em um vetor
// Complexidade: O(n)
int maxFreq1(vector<int> v) { 
    int res = 0; 
    int count = 1; 

    for(int i = 1; i < v.size(); i++) { 

        if(v[i] == v[res]) 
            count++; 
        else 
            count--; 
          
        if(count == 0) { 
            res = i; 
            count = 1; 
        }     
    } 
      
    return v[res]; 
} 

// Encontra os elemento mais frequente em um vetor
// Complexidade: O(n)
vector<int> maxFreqn(vector<int> v) 
{ 
    unordered_map<int, int> hash; 
    for (int i = 0; i < v.size(); i++) 
        hash[v[i]]++; 
  
    int max_count = 0, res = -1; 
    for (auto i : hash) { 
        if (max_count < i.second) { 
            res = i.first; 
            max_count = i.second; 
        } 
    } 

    vector<int> ans;
    for (auto i : hash) { 
        if (max_count == i.second) { 
            ans.push_back(i.first); 
        } 
    }
  
    return ans; 
} 