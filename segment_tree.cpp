#include <iostream>
using namespace std;

int array[100000];

void build(int N){
	for(int i=N-1; i>0; i--){
		array[i] = array[2*i] + array[2*i+1];
	}
}

void modify(int position, int value, int N){
	int p = position + N;
	array[p] = value;
	for(int i = p/2; i>0; i/=2)
		array[i] = array[2*i] + array[2*i+1];
}

int query(int l, int r, int N){
	int res = 0;
	l += N;
	r += N;
	while(l < r){
		if(l&1)
			res += array[l++];
		if(r&1)
			res += array[--r];
		l /= 2;
		r /= 2;
	}
	return res;
}

int main(){
	int N;
	cin>>N;
	for(int i = 0; i < N; i++)
		cin>>array[N+i];
	build(N);
	modify(1, 10, N);
	// for(int i = 0; i < 2 * N; i++){
	// 	cout<<array[i]<<"	";
	// }
	// cout<<endl;
	cout<<query(0, 1, N);
}