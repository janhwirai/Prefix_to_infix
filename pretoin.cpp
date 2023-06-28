#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string preToInfix(string pre) {
        // Write your code here
        stack <string> st;
        int n=pre.size()-1;
        //Reverse
        for(int i=n;i>=0;i--){
            char c=pre[i];
            //Operator
            if(c=='*'||c=='/'||c=='+'||c=='-'){
                string exp="(" + st.top() + c;      //exp = ( A +
                st.pop();
                exp= exp + st.top() + ")";          //exp = ( A + B )
                st.pop();
                st.push(exp);
            }
            //Operand
            else{
                string temp="";
                temp= temp+c;
                st.push(temp);
            }
        }
        return st.top();
    }
};


int main() {
    int t = 1;
    cout<<"Enter testcases:";
    cin >> t;
    while (t--) {
        string prefix;
        cout<<"\n prefix:";
        cin >> prefix;

        Solution obj;
        cout << "\nInfix:" << obj.preToInfix(prefix) << endl;
    }
    return 0;
}