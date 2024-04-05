#include <bits/stdc++.h>
using namespace std;


class DSU {  
private:  
	vector<int> p;
public:  
    DSU(int n) : p(n) {  
        iota(begin(p), end(p), 0);  
    }  
    int Leader(int v) {  
        return p[v] == v ? v : p[v] = Leader(p[v]);  
    }  
    void Unite(int a, int b) {  
        p[Leader(b)] = Leader(a);  
    }  
    void Reset(int a) {  
        p[a] = a;  
    }  
};

class BalancedDSU {  
private:  
	vector<int> s;
	vector<int> p;
public:  
    DSU(int n) : p(n), s(n, -1){  
        iota(begin(p), end(p), 0);  
    }  
    int Leader(int v) {  
        return p[v] == v ? v : p[v] = leader(p[v]);  
    }  
    void Unite(int a, int b) {  
        a = leader(a), b = leader(b);  
	    if (s[a] > s[b])  
	        swap(a, b);  
	    s[b] += s[a];  
	    p[a] = b;   
    }  
};