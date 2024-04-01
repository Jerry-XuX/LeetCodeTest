#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <stack>
// (),[],{}
class Solution
{
public:
	Solution() {
		map['('] = -1;
		map[')'] = 1;
		map['['] = -2;
		map[']'] = 2;
		map['{'] = -3;
		map['}'] = 3;
	}
public:
	std::map<char, int> map;
public:
	
	bool isValid(std::string s) {
		std::stack<int> st;
		for (int i = 0; i < s.size(); i++)
		{
			std::cout << s[i] << std::endl;
			if (s[i] == '(' || s[i] == '[' || s[i] == '{')
			{
				st.push(i);
			}
			else
			{
				if (st.empty())
				{
					return false;
				}
				if (s[i] == ')'&&s[st.top()] != '(')
				{
					return false;
				}
				if (s[i] == '}'&&s[st.top()] != '{')
				{
					return false;
				}
				if (s[i] == ']'&&s[st.top()] != '[')
				{
					return false;
				}
				st.pop();
			}
		}
		return st.empty();
	}

	bool isValidMyAnswer(std::string s)
	{
		std::stack<char> stk;
		for (int i = 0; i < s.size(); i++)
		{
			auto auto1 = map.find(s[i]);
			if (auto1->second < 0)
			{
				stk.push(s[i]);
			}
			else
			{
				if (stk.empty()) return false;
				auto auto2 = map.find(s[i]);
				if (auto1->second + auto2->second != 0)
				{
					return false;
				}
				stk.pop();
			}
		}
		return stk.empty();
	}
};

int main()
{
	//std::string s = "([)]";
	//std::string s = "()";
	//std::string s = "(([]){})";
	//std::string s = "[({(())}[()])]";
	//std::string s = "(]";
	//std::string s = "(){}}{";
	std::string s = "{}[{}]((){})(){}";
	Solution sol;
	if (sol.isValid(s))
	{
		std::cout << "true" << std::endl;
	}
	else
	{
		std::cout << "false" << std::endl;
	}
	std::stack<char> stk;
	stk.push('a');
	return 0;
}