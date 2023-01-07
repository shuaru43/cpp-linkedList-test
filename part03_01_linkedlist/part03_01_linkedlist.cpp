#include <iostream> 

struct Node
{
	int data;
	Node* next;
};

class LinkedList 
{
private:
	Node* head;
	int size;
public:
	LinkedList() : head(NULL) {
		head = new Node();
		size = 0;
	}

	~LinkedList() {
		while (!empty()) {
			pop_front();
		}
	};

	void push_front(int val) {
		Node* new_node = new Node{ val, NULL };

		new_node->next = head->next;
		head->next = new_node;
		size++;
	};

	void pop_front() {
		if (head->next == NULL) {
			std::cout << "size is 0 " << std::endl;
			return;
		}

		Node* temp = head->next;
		head->next = head->next->next;
		std::cout << "Deleted value : " << temp->data << std::endl;
		delete temp;
	}

	bool empty() const {
		return head->next == NULL;
	}

	void print_all() const {
		Node* cur = head->next;

		while (cur != NULL) {
			std::cout << cur->data << std::endl;
			cur = cur->next;
		}

		std::cout << std::endl;
	}
};
int main()
{
	LinkedList ll;
	ll.push_front(10);
	ll.push_front(20);
	ll.push_front(30);
	ll.print_all();

	ll.pop_front();
	ll.print_all();

	ll.push_front(40);
	ll.print_all();
	
	ll.~LinkedList();
}