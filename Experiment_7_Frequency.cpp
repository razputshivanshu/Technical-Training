#include <iostream>
#include <string>

using namespace std;

long repeatedString(string s, long n) {
    long count_a = 0;
    long len = s.length();


    for (int i = 0; i < len; i++) {
        if (s[i] == 'a') {
            count_a++;
        }
    }

   
    count_a *= (n / len);

 
    for (int i = 0; i < n % len; i++) {
        if (s[i] == 'a') {
            count_a++;
        }
    }

    return count_a;
}

int main() {
    string s;
    long n;

    
    cin >> s;
    cin >> n;

    long result = repeatedString(s, n);
    cout << result << endl;

    return 0;
}
