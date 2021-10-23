#include <iostream>
#include <stack>

using namespace std;

string decodeString(string s);

int main() {
    string input = "2(2(A)3(B))";
    string res = decodeString(input);
    cout << res;
    return 0;
}

string decodeString(string s) {
    string output = "";
    string k = "";
    stack<string> st;

    for (int i = 0; i < s.size(); ++i) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            while(s[i] >= 'A' && s[i] <= 'Z') {
                output+=s[i];
                i++;
            }
        }

        if (s[i] >= '0' && s[i] <= '9') {
            while(s[i] >= '0' && s[i] <= '9') {
                k+=s[i];
                i++;
            }
        }

        if (s[i] == '(') {
            st.push(output);
            st.push(k);
            output="";
            k="";
        }

        if (s[i] == ')') {
            int repetitions = stoi(st.top());
            st.pop();
            string x = "";

            for (int j = 0; j < repetitions; ++j) {
                x+=output;
            }

            output = st.top() + x;
            st.pop();
        }
    }

    return output;
}
