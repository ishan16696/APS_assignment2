#include<bits/stdc++.h>
using namespace std; 
  
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

      /*      for( i=0;i<len;i++){
        if(sufArray[i]<len)
        {
            break;

         }
         
            }

        cout << s.substr(sufxArray[i],len)<<endl;
*/




        // Return the suffix array 
        return  sufxArray; 


}
  


int main() 
{ 
    string s;
    cin >> s;// input string
    int len=s.size();
    s=s+s;
    // cout << s<<" ";
    int *sufArray = calcSuffixArr(s,s.size());
    /*for (int i = 0; i < s.size(); i++) 
        cout << sufArray[i] << " "; */
    int i,min;
    for( i=0;i<len;i++){
    if(sufArray[i]<len)
    {
        break;

    }
     
}

    cout << s.substr(sufArray[i],len)<<endl;
    return 0; 
}