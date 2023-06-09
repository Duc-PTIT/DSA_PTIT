#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define pf push_front
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int n;
int a[20];
bool ok;
vector <string> v;

void khoitao() {
    for (int i = 1; i <= n; i++)
        a[i] = 0;
}

void sinh() {
    int i = n;
    while (i > 0 && a[i] == 1) {
        a[i] = 0;
        i--;
    }
    if (i == 0) ok = false;
    else a[i] = 1;
}

bool check() {
    if (a[1] != 0) return false;
    if (a[n] != 1) return false;
    //int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 0 && a[i + 1] == 0)
            return false;
    }
    return true;
}

void xuat() {
    string s = "";
    if (check()) {
        for (int i = 1; i <= n; i++) {
            if(a[i] == 0) s += "H";
            else s += "A";
        }
        v.pb(s);
    }
}

int main() {
    fast_io;
    int t; cin >> t;
    while (t--) {
        v.clear();
        ok = true;
        cin >> n;
        khoitao();
        while (ok) {
            xuat();
            sinh();
        }
        sort(begin(v), end(v));
        for (string s : v) cout << s << endl;
    }
    return 0;
}