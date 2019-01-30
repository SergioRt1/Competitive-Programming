#include<bits/stdc++.h>
#define loop(i,a,b) for(auto i=a;i<b;i++)
#define loopit(i,a) for(auto i=a.begin();i!=a.end();i++)
#define X first
#define Y second

using namespace std;

typedef long long large;

unordered_map<char,char> rev;

void fillrev(){
   rev['A']='A';
   rev['E']='3';
   rev['H']='H';
   rev['I']='I';
   rev['J']='L';
   rev['L']='J';
   rev['M']='M';
   rev['O']='O';
   rev['S']='2';
   rev['2']='S';
   rev['T']='T';
   rev['U']='U';
   rev['V']='V';
   rev['W']='W';
   rev['X']='X';
   rev['Y']='Y';
   rev['Z']='5';
   rev['1']='1';
   rev['2']='S';
   rev['3']='E';
   rev['5']='Z';
   rev['8']='8';
}

int main(){
//   freopen("401.in","r",stdin);
//   freopen("401.out","w",stdout);
   fillrev();
   string line;
   while(getline(cin,line)){
      int len = line.length();
      int p=0,m=0;
      loop(i,0,len){
         if(line[i]==line[len-i-1])p++;
         if(line[i]==rev[line[len-i-1]])m++;
      }
      if(p==len && m==len)cout<<line<<" -- is a mirrored palindrome."<<endl<<endl;
      if(p!=len && m==len)cout<<line<<" -- is a mirrored string."<<endl<<endl;
      if(p==len && m!=len)cout<<line<<" -- is a regular palindrome."<<endl<<endl;
      if(p!=len && m!=len)cout<<line<<" -- is not a palindrome."<<endl<<endl;


   }
   return 0;
}
