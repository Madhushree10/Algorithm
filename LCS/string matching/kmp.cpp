

#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

/**************************************
              LPS function
***************************************/          
void lps_func(string txt, vector<int>&Lps){
    Lps[0] = 0;                   
    int len = 0;
    int i=1;
    while (i<txt.length()){
        if(txt[i]==txt[len]){   
            len++;
            Lps[i] = len;
            i++;
            continue;
        }
        else{                   
            if(len==0){         
                Lps[i] = 0;
                i++;
                continue;
            }
            else{              
                len = Lps[len-1];
                continue;
            }
        }
    }
}

/**************************************
              KMP Function
***************************************/  
void KMP(string pattern,string text){
    int n = text.length();
    int m = pattern.length();
    vector<int>Lps(m);
    
    lps_func(pattern,Lps); 
    
    int i=0,j=0;
    while(i<n){
        if(pattern[j]==text[i]){i++;j++;} 

        if (j == m) { 
            cout<<i - m <<' ';    
                                 
            j = Lps[j - 1]; 
        } 
        else if (i < n && pattern[j] != text[i])
        { 
            if (j == 0)          
                i++;
            else
                j = Lps[j - 1];  //Update j as Lps of last matched character
        }
    }
}

int main()
{
    string text;
    cout << "Enter text: ";
    cin >> text;
    string pattern;
    cout << "Enter pattern: ";
    cin >> pattern;
    KMP(pattern, text);
    
    return 0; 
}
