#include<bits/stdc++.h>
#define loop(i,a,b) for(auto i=a;i<b;i++)
#define loopit(i,a,b) for(auto i=a;i!=b;i++)
#define X first
#define Y second

typedef long long large;

using namespace std;

unordered_map<char,int> toNum;
map<string,int> cant;

void load(){
   toNum['A']='2';
   toNum['B']='2';
   toNum['C']='2';
   toNum['D']='3';
   toNum['E']='3';
   toNum['F']='3';
   toNum['G']='4';
   toNum['H']='4';
   toNum['I']='4';
   toNum['J']='5';
   toNum['K']='5';
   toNum['L']='5';
   toNum['M']='6';
   toNum['N']='6';
   toNum['O']='6';
   toNum['P']='7';
   toNum['R']='7';
   toNum['S']='7';
   toNum['T']='8';
   toNum['U']='8';
   toNum['V']='8';
   toNum['W']='9';
   toNum['Y']='9';
   toNum['X']='9';
}
int main(){
//   freopen("755.txt","r",stdin);
//   freopen("755.out","w",stdout);
   load();
   int cas;
   scanf("%d",&cas);
   loop(ca,0,cas){
      if(ca!=0)puts("");
      cant.clear();
      int n;
      scanf("%d",&n);
      string phone;
      loop(k,0,n){
         string can;
         cin>>phone;
         loop(i,0,phone.length()){
            if('0'<=phone[i]&&phone[i]<='9'){
               can+=phone[i];
            }else if(isalpha(phone[i])){
               can+= toNum[phone[i]];
            }
            if(can.length() == 3) can+='-';
         }
         auto it = cant.find(can);
         if(it!=cant.end()){
            cant[can]++;
         }else cant[can] = 1;
      }
      bool done=false;
      loopit(itr,cant.begin(),cant.end()){
         if(itr->Y>1){
            cout<<itr->X<<" "<<itr->Y<<endl;
            done = true;
         }
      }
      if(!done){
         puts("No duplicates.");
      }
   }
   return 0;
}
