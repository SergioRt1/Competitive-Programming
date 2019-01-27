#include<bits/stdc++.h>
#define loop(i,a,b) for(auto i=a;i<b;i++)
#define loopit(i,a,b) for(auto i=a;i!=b;i++)
#define X first
#define Y second

using namespace std;

typedef long long large;
typedef pair<char, char> cc;

map<string,char> ope;
unordered_map<char,char> unit;
unordered_map<char,float> pot;

void pre(){
   ope["PI"]='U';
   ope["IP"]='U';
   ope["PU"]='I';
   ope["UP"]='I';
   ope["UI"]='P';
   ope["IU"]='P';
   unit['P']='W';
   unit['U']='V';
   unit['I']='A';
   pot['m']=0.001;
   pot['k']=1000;
   pot['M']=1000000;
}

float toUnit(float num, string uni){
   if(uni.length() < 2)return num;
   auto it = pot.find(uni[0]);
   return it== pot.end()?num:(it->Y)*num;
}

int main(){
//   freopen("in.in","r",stdin);
//   freopen("out.out","w",stdout);
   int n;
   pre();
   scanf("%d",&n);
   string line;
   getline(cin, line);
   loop(ca,0,n){
      getline(cin, line);
      stringstream ss(line);
      string token;
      int ch = 0;
      float num1,num2;
      char t1,t2,na;
      string uni1 = "",uni2 = "";
      bool p=false,u=false,i=false;
      int i1 = line.find_first_of("=");
      int i2 = line.find_last_of("=");
      t1 = line[i1-1];
      t2 = line[i2-1];
      int it = i1+1;
      string tm = "";
      while(!isalpha(line[it])){
         tm+=line[it];
         it++;
      }
      num1 = stof(tm);
      uni1 += line[it];
      if(pot.find(line[it]) != pot.end())
         uni1 += line[it+1];

      it = i2+1;
      tm = "";
      while(!isalpha(line[it])){
         tm+=line[it];
         it++;
      }
      num2 = stof(tm);
      uni2 += line[it];
      if(pot.find(line[it]) != pot.end())
         uni2 += line[it+1];
      string tf = "";
      tf+=t1;
      tf+=t2;
      char t = ope[tf];
      float num;
      num1 = toUnit(num1,uni1);
      num2 = toUnit(num2,uni2);
      if(t1 == 'P'){
         num = num1/num2;
      }else if(t2 == 'P'){
         num = num2/num1;
      }else num = num1*num2;

      printf("Problem #%d\n%c=%.2f%c\n\n",ca+1,t,num,unit[t]);
   }
   return 0;
}


