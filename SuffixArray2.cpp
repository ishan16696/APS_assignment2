#include<bits/stdc++.h>
using namespace std; 
 

//*******************************************************  Suffix Array ************************************************************************ 
struct node{
    int index;
    int curRank;
    int nextRank;
};

bool comp(node r,node f){   // comparator function used for sorting
    if(r.curRank==f.curRank){
        if(r.nextRank <f.nextRank){
            return true;
        }
        else
            return false;
    }

    if(r.curRank < f.curRank)
        return true;
    else
        return false;
}

int  *calcSuffixArr(string s,int n){
        transform(s.begin(), s.end(), s.begin(), ::tolower);   // convering it into the lowerCase()
        int len=s.length();
        char input[len+1];
        strcpy(input,s.c_str());// converting string to char array in the disguise of copy
        node suffix[n];


    //all suffixes have to be sorted according to first 2 characters.
        for(int i=0;i<n;i++)
        {
            suffix[i].index=i;
            suffix[i].curRank=input[i]-'a';
            suffix[i].nextRank=((i+1)<n )? (input[i+1]-'a'): -1 ;
        }

        sort(suffix,suffix+n,comp);  // O(nlogn) 

        int pointer[n];  //This array is needed to get the index in suffixes[] from original index

        for(int k=4;k<2*n;k=k*2)
        {
            int rank = 0; 
            int prev_rank = suffix[0].curRank; 
            suffix[0].curRank = rank; 
            pointer[suffix[0].index] = 0; 

            // this is for Current Rank
            for(int i=1;i<n;i++)
            {

                if(suffix[i].curRank==prev_rank && suffix[i].nextRank==suffix[i-1].nextRank)
                {

                    prev_rank=suffix[i].curRank;
                    suffix[i].curRank=rank;  // same rank
                }
                else
                {
                // if differ by prev rank then increment the rank
                    prev_rank = suffix[i].curRank;
                    rank++;  // increment the rank
                    suffix[i].curRank=rank;

                }
                pointer[suffix[i].index] = i; 
            }

            // this is for nextRank
            for(int i=0;i<n;i++)
            {
                //to fill the next rank 
                int next_Index=suffix[i].index+k/2;
                suffix[i].nextRank=(next_Index<  n) ? suffix[pointer[next_Index]].curRank : -1;
            }

            sort(suffix,suffix+n,comp);

        }


        int *sufxArray = new int[n]; 
        for (int i = 0; i < n; i++) 
            sufxArray[i] = suffix[i].index; 

        // Return the suffix array 
        return  sufxArray; 


}
//*************************************************************** Making if LCP(longest common prefix)*************************************
//===============================================================  using Kasai's algorothm ===================================================

int * longestCommonPrefix(string s,int n){
        
        int *sufArray = calcSuffixArr(s,n);
        int *result =new int[n];
        int *invSuf=new int[n];

        for(int i=0;i<n;i++){
            invSuf[sufArray[i]]=i; // taking the inverse of 
        }
        int k=0;
       // result[invSuf[0]]=k;
        for(int i=0;i<n;i++){
            
            int j;// to hold the index for next substring which are next to subtring of i=0;


            //base condition (applies on last element)
            if(invSuf[i]==n-1){
                k=0;
                continue;
            }

             j=sufArray[invSuf[i]+1];// index of next subtring of sufArray(i.e sorted substring)

            while(j+k < n && j+k <  n && s[i+k]==s[j+k])
                k++;

            result[invSuf[i]]=k;

            if(k>0)
                k--;// doubt

        }
        return result;

}
//*********************************************************************************************************************************************
//rotate to get lcp of suffix i to i-1 ; not from i to i+1;
int *rotate(int *lcp,int n){
    std::vector<int> v;
    for(int i=0;i<n;i++)
        v.push_back(lcp[i]);

    for(int i=1;i<v.size();i++){
        lcp[i]=v[i-1];
    }
    lcp[0]=0;
    
    return lcp;
}


//*************************************************************** Driver() function *************************************************************
int main() 
{ 
    string s;
    cin >> s;// input string
    int n=s.size();
    int *sufArray=calcSuffixArr(s,s.size());
    int *lcp=longestCommonPrefix(s,s.size());
    

    //algo
    /*for i = 1 to (N-M+1):
    ans=max(ans, LCP(SA[i],SA[i+M-1]))*/
    int ans=0;
    for(int i=0;i<;i++);
        ans=max(ans,lcp[sufArray[i]])

    return 0; 
}