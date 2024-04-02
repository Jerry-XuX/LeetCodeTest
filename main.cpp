#include<vector>
#include<map>
#include<iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode() :val(0), next(nullptr) {}
	ListNode(int x) :val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) :val(x), next(next) {}
};

class Solution {
public:

public:
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		std::vector<int> vList1;
		std::vector<int> vList2;
		std::vector<int> vBool;// List1->0, List2->1

		ListNode* listTmp1 = list1;
		while (listTmp1)
		{
			vList1.push_back(listTmp1->val);
			listTmp1 = listTmp1->next;
		}

		ListNode* listTmp2 = list2;
		while (listTmp2)
		{
			vList2.push_back(listTmp2->val);
			listTmp2 = listTmp2->next;
		}

		while (!vList1.empty() || !vList2.empty())
		{
			if (!vList1.empty() && !vList2.empty())
			{
				if (vList1[0] > vList2[0])
				{
					vList2.erase(vList2.begin());
					vBool.push_back(0);
				}
				else if (vList1[0] == vList2[0])
				{
					vList1.erase(vList1.begin());
					vList2.erase(vList2.begin());
					vBool.push_back(0);
					vBool.push_back(1);
				}
				else
				{
					vList1.erase(vList1.begin());
					vBool.push_back(1);
				}
			}
			else if (vList1.empty())
			{
				vList2.erase(vList2.begin());
				vBool.push_back(0);
			}
			else
			{
				vList1.erase(vList1.begin());
				vBool.push_back(1);
			}
		}

		ListNode* ListDummy = new ListNode(0, nullptr);
		ListNode* ListRes = ListDummy;
		for (int n = 0; n < vBool.size(); n++)
		{
			if (vBool[n])
			{
				ListDummy->next = list1;
				ListDummy = ListDummy->next;
				list1 = list1->next;
			}
			else
			{
				ListDummy->next = list2;
				ListDummy = ListDummy->next;
				list2 = list2->next;
			}
		}
		//ListNode* listRes = new ListNode(0, ListDummy);
		return ListRes->next;
	}
};

int main()
{
	//ListNode* list1 = new ListNode(1, nullptr);
	//list1->next = new ListNode(2);
	//list1->next->next = new ListNode(4);

	//ListNode* list2 = new ListNode(1);
	//list2->next = new ListNode(3);
	//list2->next->next = new ListNode(4);

	ListNode* list1 = new ListNode();
	list1 = nullptr;
	ListNode* list2 = new ListNode(0, nullptr);
	Solution sol;
	ListNode* listRes =  sol.mergeTwoLists(list1, list2);
	std::cout << "show listRes: " << std::endl;
	while (listRes)
	{
		std::cout << listRes->val << std::endl;
		listRes = listRes->next;
	}
	return 0;
}