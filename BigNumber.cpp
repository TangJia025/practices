#include <string>

class BigNumber
{
private:
	string num;

public:
	BigNumber()
	{
		num = "";
	}
	BigNumber(string s)
	{
		num = s;
	}
	string str_add(string &s1, string &s2);
	string str_sub(string &s1, string &s2);
	BigNumer &add(BigNumber &a, BigNumber &b)
	{
		BigNumber c;
		c.num = str_add(a.num, b.num);
		return c;
	}
	BigNumber &sub(BigNumber &a, Number &b)
	{
		BigNumber c;
		c.num = str_sub(a.num, b.num);
		return c;
	}
};

string BigNumber::str_add(string s1, string s2)
{
	if (s1 == "0")
		return s2;
	if (s2 == "0")
		return s1;
	if (s1[0] == '-')
	{
		if (s2[0] == '-')
		{
			return "-" + add_int(s1.erase(0, 1), s2.erase(0, 1)); 
		}
		else
		{
			return sub_int(s2, s1.erase(0, 1)); 
		}
	}
	if (s2[0] == '-')
	{
		return sub_int(s1, s2.erase(0, 1));
	}
	string::size_type i, size1, size2;
	size1 = s1.size();
	size2 = s2.size();
	if (size1 < size2)
	{
		for (i = 0; i < size2 - size1; i++)  
			s1 = "0" + s1;
	}
	else
	{
		for (i = 0; i < size1 - size2; i++) 
			s2 = "0" + s2;
	}

	int n1, n2;
	n2 = 0;
	size1 = s1.size();
	size2 = s2.size();
	string res;
	for (i = size1 - 1; i != 0; i--)  
	{
		n1 = (s1[i] - '0' + s2[i] - '0' + n2) % 10; 
		n2 = (s1[i] - '0' + s2[i] - '0' + n2) / 10;  
		res = char(n1 + '0') + res;
	}
	n1 = (s1[0] - '0' + s2[0] - '0' + n2) % 10;
	n2 = (s1[0] - '0' + s2[0] - '0' + n2) / 10;
	res = char(n1 + '0') + res;

	if (n2 == 1)
		res = "1" + res;

	return res;
}

string BigNumber::str_sub(string s1, string s2)
{
	if (s2 == "0")
		return s1;
	if (s1 == "0")
	{
		if (s2[0] == '-')
			return s2.erase(0, 1);
		return "-" + s2;
	}

	if (s1[0] == '-')
	{
		if (s2[0] == '-')
		{
			return sub_int(s2.erase(0, 1), s1.erase(0, 1)); 
		}
		return "-" + add_int(s1.erase(0, 1), s2); 
	}

	if (s2[0] == '-')
		return add_int(s1, s2.erase(0, 1));  

	string::size_type i, size1, size2;
	size1 = s1.size();
	size2 = s2.size();
	if (size1 < size2)
	{
		for (i = 0; i < size2 - size1; i++)   
			s1 = "0" + s1;
	}
	else
	{
		for (i = 0; i < size1 - size2; i++)  
			s2 = "0" + s2;
	}
	int t = s1.compare(s2);

	if (t < 0)   
		return "-" + sub_int(s2, s1);

	if (t == 0)
		return "0";

	string res;
	string::size_type j;
	for (i = s1.size() - 1; i != 0; i--)
	{
		if (s1[i] < s2[i])   
		{
			j = 1;
			while (s1[i - j] == '0')
			{
				s1[i - j] = '9';
				j++;
			}
			s1[i - j] -= 1;
			res = char(s1[i] + ':' - s2[i]) + res;
		}
		else
		{
			res = char(s1[i] - s2[i] + '0') + res;
		}
	}
	res = char(s1[0] - s2[0] + '0') + res;
	res.erase(0, res.find_first_not_of('0'));
	return res;
}
