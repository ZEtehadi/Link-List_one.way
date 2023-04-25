// LinkList_1taraf.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

struct node
{
	int data;
	struct node* next;
};

class LinkList
{
	node* head;
public:
	LinkList()
	{
		head = NULL;
		//NextHead = NULL;
	}

	void insert_asLast(int item)
	{
		node* temp = new node;
		
		if (head == NULL)
		{
			temp->data = item;
			temp->next = NULL;
			head = temp;
			return;
		}

		node* Copy = head;
		while (Copy->next != NULL)
		{
			Copy = Copy->next;
		}
		Copy->next = temp;
		temp->data = item;
		temp->next = NULL;
		return;
	}

	void Insert_atFirst(int Item)
	{
		node* Start = new node;
		Start->data = Item;
		Start->next = head;
		head = Start;
	}

	void Show()
	{
		node* Copy = head;
		if (Copy == NULL)
			cout << "*** We Don't have any List !\n";
		while (Copy != NULL)
		{
			cout << Copy->data << ",[" << Copy->next << "]\t";
			Copy = Copy->next;
		}
		cout << "\n";
	}

	void Delete_atLast()
	{
		node* Copy = head;
		if (Copy == NULL)
		{
			cout << "*** Don't have any list\n";
			return;
		}
		else
		{
			while (Copy->next->next != NULL)
				Copy = Copy->next;
			Copy->next = NULL;
			delete Copy->next;
		}
	}

	void Delete(int item)
	{
		node* Copy = head;
		if (Copy == NULL)
			cout << "*** Don't have any List\n";
		else
		{
			int data;
			node* next;
			if (Copy == NULL)
			{
				cout << "!!! Don't hava any List\n";
				return;
			}
			if (Copy->data == item)
			{
				cout << "Delete=>\t" << Copy->data << ",[" << Copy->next << "]\n";
				//next = Copy->next;
				head = head->next;
				delete Copy;
				//Copy = next;
				return;
			}
			while (Copy->next!=NULL)
			{
				data=Copy->next->data;
				if (data == item)
				{
					cout << "Delete=>\t" << data << ",[" << Copy->next->next << "]\n";
					next =Copy->next->next;
					delete Copy->next;
					Copy->next = next;
					return;
				}
				Copy = Copy->next;
			}
			cout << "\nDon't have this Number !!!\n";
			return;
		}
	}
};

int main()
{
	int item;
	LinkList a;
	int ch;
	do
	{
		cout << "\n1: Insert at Last\n2: Show\n3: Delete at Last\n4: Delet by Data\n";
		cin >> ch;

		switch (ch)
		{
			case 1:
			{
				cout << "Enter Item: ";
				cin >> item;
				a.insert_asLast(item);
				break;
			}
			case 2:
			{
				cout << "\n******Show List \n";
				a.Show();
				break;
			}
			case 3:
			{
				cout << "\n*** Delete At Last\n";
				a.Delete_atLast();
				break;
			}
			case 4:
			{
				int Data;
				cout << "Enter One Data for Delete:";
				cin >> Data;
				a.Delete(Data);
				break;
			}
			default:
				break;
		}

	} while (ch <= 4);


		return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
