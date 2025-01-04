#include<iostream>
using namespace std;

class tree
{
	int a[20][20], l, u, w, i, j, v, e, visited[20];

public:
	void input();
	void display();
	void minimum();
};

void tree::input()
{
	cout << "Enter the number of branches: ";
	cin >> v;

	for (i = 0; i < v; i++)
	{
		visited[i] = 0;
		for (j = 0; j < v; j++)
		{
			a[i][j] = 999;
		}
	}

	cout << "\nEnter the number of connections: ";
	cin >> e;

	for (i = 0; i < e; i++)
	{
		cout << "Enter the end branches of the connection:\n";
		cin >> l >> u;
		cout << "Enter the phone company charges for this connection: ";
		cin >> w;
		a[l - 1][u - 1] = a[u - 1][l - 1] = w;
	}
}

void tree::display()
{
	cout << "\nAdjacency matrix:\n";
	for (i = 0; i < v; i++)
	{
		for (j = 0; j < v; j++)
		{
			cout << a[i][j] << "   ";
		}
		cout << endl;
	}
}

void tree::minimum()
{
	int p = 0, q = 0, total = 0, min;
	visited[0] = 1;
	for (int count = 0; count < (v - 1); count++)
	{
		min = 999;
		for (i = 0; i < v; i++)
		{
			if (visited[i] == 1)
			{
				for (j = 0; j < v; j++)
				{
					if (visited[j] != 1)
					{
						if (min > a[i][j])
						{
							min = a[i][j];
							p = i;
							q = j;
						}
					}
				}
			}
		}
		visited[p] = 1;
		visited[q] = 1;
		total = total + min;
		cout << "Minimum cost connection is " << (p + 1) << " -> " << (q + 1) << "  with charge: " << min << endl;
	}
	cout << "The minimum total cost of connections of all branches is: " << total << endl;
}

int main()
{
	int ch;
	tree t;
	do
	{
		cout << "==========PRIM'S ALGORITHM=================\n";
		cout << "\n1. Input\n2. Display\n3. Minimum\n4. Exit\n";
		cout << "Enter your choice: ";
		cin >> ch;

		switch (ch)
		{
		case 1:
			cout << "\n*******INPUT YOUR VALUES*******\n";
			t.input();
			break;

		case 2:
			cout << "\n*******DISPLAY THE CONTENTS********\n";
			t.display();
			break;

		case 3:
			cout << "\n*********MINIMUM************\n";
			t.minimum();
			break;

		case 4:
			cout << "\nExiting the program.\n";
			exit(0);

		default:
			cout << "\nInvalid choice. Please try again.\n";
		}

	} while (true);

	return 0;
}
