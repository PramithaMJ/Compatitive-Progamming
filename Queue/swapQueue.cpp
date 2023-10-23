// CPP program to illustrate
// Implementation of swap() function
#include<iostream>
#include<queue>

using namespace std;

int main()
{
	// Take any two queues
	queue<char> queue1, queue2;
	int v = 96;
	for (int i = 0; i < 5; i++) {
	queue1.push(v + 1);
	v++;
	}

for (int i = 0; i < 4; i++) {
	queue2.push(v + 1);
	v++;
	}
	
	// Swap elements of queues
	queue1.swap(queue2);

	// Print the first queue
	cout << "queue1 = ";
	while (!queue1.empty()) {
	cout << queue1.front() << " ";
	queue1.pop();
}

	// Print the second set
	cout << endl << "queue2 = ";
	while (!queue2.empty()) {
	cout << queue2.front() << " ";
	queue2.pop();
}
		
	return 0;
}
