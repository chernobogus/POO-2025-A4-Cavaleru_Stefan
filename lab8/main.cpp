#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <map>
#include <queue>

using namespace std;

ifstream f("file.in");

string transform(string a) {
	for(int i=0;i<a.length();i++)
		if(isupper(a[i])) a[i]+=32;
	return a;
}

struct compare {
	int nr;
	string cuvant;
	bool operator < (const compare& x) const {
		if(nr < x.nr)
			return true;
		if(nr==x.nr)
			return cuvant>x.cuvant;
		return false;
	}

};

int main() {

	string s;
	string sub;
	map <string,int> map;

	getline(f,s);
	int sep=s.find_first_of(" ,.?!");

	while(sep<s.size()){
			sub = transform(s.substr(0,sep));
			if(sub!="")
			map[sub]++;
				s = s.substr(sep + 1);
				sep = s.find_first_of(" ,.?!");
		}

	priority_queue <compare> q;

	for(auto i:map){
		compare cuv;
		cuv.nr=i.second;
		cuv.cuvant=i.first;
		q.push(cuv);
	}
		

	while (!q.empty()) {
		cout<<q.top().cuvant<<" => ";
		cout<<q.top().nr<<endl;
		q.pop();

	}

	f.close();
	return 0;
}