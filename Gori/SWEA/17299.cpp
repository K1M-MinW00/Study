#include <iostream>
#include <string>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
  
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int n;
        cin >> n;
		
        string num = to_string(n);
        int len = num.length() , sum;
        bool even = false;

        if(len%2==0)
            even = true;

        if(even)
        {
            string num1 = num.substr(0,len/2);
            string num2 = num.substr(len/2);
            
            sum = stoi(num1) + stoi(num2);
        }

        else
        {
            string num1 = num.substr(0,len/2);
            string num2 = num.substr(len/2);

            string num3 = num.substr(0,len/2+1);
            string num4 = num.substr(len/2+1);

            int sum1 = stoi(num1) + stoi(num2);
            int sum2 = stoi(num3) + stoi(num4);

            sum = min(sum1,sum2);

        }
        cout << "#" << test_case << " " << sum << endl;
	}
  
	return 0;
}
