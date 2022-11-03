#include <iostream>
#include <stack>
#include <string>
#include <cmath>
#include <assert.h>

bool is_operand(char);
bool is_operator(char);
int calculate(int, int, char);

int main()
{

	std::stack<int> s;
	std::string line;
	std::cin >> line;
	for (int i = 0; i < line.size(); ++i)
	{
		if (is_operand(line[i]))
		{
			s.push(line[i] - '0');
		}
		else if (is_operator(line[i]))
		{
			const int var1 = s.top();
			s.pop();
			const int var2 = s.top();
			s.pop();
			s.push(calculate(var2, var1, line[i]));
		}
		else {
			std::cout << "normal ban greq";
			return 0;
		}
	}
	std::cout << s.top() << std::endl;
	system("pause");
	return 0;
}


bool is_operand(char c)
{
	return c >= '0' && c <= '9';
}

bool is_operator(char c)
{
	return c == '+' || c == '-' || c == '*' || c == '/'
		|| c == '^';
}

int calculate(int v1, int v2, char o)
{
	switch (o) {
	case '+':
		return v1 + v2;
	case '-':
		return v1 - v2;
	case '*':
		return v1 * v2;
	case '/':
		return v1 / v2;
	case '^':
		return pow(float(v1), v2);
	default:
		std::cout << "es inch eq grel??";
		assert(false);
	}
	return 0;
}