#include<bits/stdc++.h>
#define loop(i,a,b) for(int i = a;i<b;i++)
#define ms(a,b) memset(a,b,sizeof a)
#define pb(a) push_back(a) 
using namespace std;

typedef pair<int,int>ii;
typedef vector<int>vi;
typedef set<vi>si;
int ai,aj;

int tab[8];

si ans;

bool movientoValido(int i, int j){
	if(tab[j] != -1) return false;
	int k;
	loop(k,0,8)
		if(tab[k] != -1 && (tab[k]-k == i-j || tab[k]+k == i+j  || i == tab[k]))return false;
	return true;
}

bool backTracking(int i){
	bool posible = false;
	int j;
	if(i == 8){
		vi tm;
		loop(j,0,8)tm.pb(tab[j]+1);
		ans.insert(tm);
		printf("sol");
		return true;
	}
	if(i == ai){
		posible = backTracking(i+1);
	}else loop(j,0,8){
		printf("%d %d %d\n",i,j,movientoValido(i,j));
		if(movientoValido(i,j)){
			tab[j] = i;
			posible |= backTracking(i+1);
			if(i != ai && j != aj){
				tab[i] = -1;
			}
		}
	}
	return posible;
}

int main(){
	int n,i;
	scanf("%d",&n);
	loop(i,0,n){
		ans.clear();
		ms(tab,-1);
		scanf("%d %d",&ai,&aj);
		aj--;
		ai--;
		tab[aj] = ai;
		backTracking(0);
		puts("SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n");
		for(si::iterator it = ans.begin(); it != ans.end(); it++){
			printf("%2d      %d %d %d %d %d %d %d %d\n",(*it)[0],(*it)[1],(*it)[2],(*it)[3],(*it)[4],(*it)[5] ,(*it)[6],(*it)[7]);
		}
		
	}
	return 0;
}
