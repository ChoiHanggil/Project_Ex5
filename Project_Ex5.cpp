#include <iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
//O(n)
bool IsPalindrome(std::string s)
{
	std::string temp{""};

	for (auto c : s)
	{
		if (c <= 'z' && c >= 'a')
		{
			temp += c;
		}
		else if (c <= 'Z' && c >= 'A')
		{
			temp += (char)(c - 32);
		}
	}

	int start = 0; 
	int end = temp.size() - 1 ;

	while (start < end)
	{
		if (temp[start] != temp[end])
		{
			return false;
		}
		start++;
		end--;
	}
	return true;
}

//O(1)
int NumberOfOneBit(uint32_t n)
{
	int count{ 0 };
	while (n)
	{
		if (n & 1)
		{
			count++;
		}
		n >>= 1;
	}
	return count;
}
//O(n log n)
std::vector<int> ArrayOfBitCount(int n)
{
	int count = 1;
	int temp = count;
	int ac = 0;
	std::vector<int> answer;
	answer.push_back(0);

	while (count <= n)
	{
		while (temp)
		{
			if (temp & 1)
			{
				ac++;
			}
			temp >>= 1;
		}
		answer.push_back(ac);
		count++;
		temp = count;
		ac = 0;
	}
	return answer;
}
struct ListNode
{
	int val;
	ListNode* next;
};
//O(n)
ListNode* RemoveNthFromEnd(ListNode* head, int n)
{
	int listSize{ 0 };
	ListNode* p = head;
	while (p->next)
	{
		listSize++;
		p = p->next;
	}
	listSize++;
	int fromBack = listSize - n + 1;

	listSize = 0;

	p = head;

	while (p->next)
	{
		if (listSize == fromBack)
		{
			p->next = p->next->next;
			break;
		}
		p = p->next;
		listSize++;
	}

	return head;
}

//O(n long k )
int FindKthSmallest(const std::vector<int>& nums, int k)
{
	std::priority_queue<int> pq;

	for (auto e : nums)
	{
		pq.push(e);
		if (pq.size() > k)
		{
			pq.pop();
		}
	}
	return pq.top();
}


int main()
{
	//std::string s{"race a car"};
	//std::cout << IsPalindrome(s);

	//std::cout << NumberOfOneBit(00000000000000000000000000001011);

	//for (auto e : ArrayOfBitCount(5))
	//{
	//	std::cout << e << std::endl;
	//}


}

