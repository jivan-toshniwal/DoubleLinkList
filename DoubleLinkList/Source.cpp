#include <iostream>

class Node {
	int data;
	Node* next, * last;
public:
	Node* head;
	Node(int val = 0)
		:data(val) {
		head = next = NULL;
	}
	void creatDoubleList() {
		std::cout << "Enter Size: ";
		int x; std::cin >> x;
		while (x--)
		{
			int y; std::cin >> y;
			Node* n = new Node(y);
			if (!head) {
				head = last = n;
			}
			else {
				last->next = n;
				n->head = last;
				last = last->next;
			}
		}std::cout << std::endl;
	}
	void display(Node* h) {
		while (h)
		{
			std::cout << h->data << " ";
			h = h->next;
		}std::cout << std::endl;
	}
	void insert(int pos, int val) {
		Node* n = new Node(val);
		if (pos == 0) {				   // insert at begining
			n->next = head;
			head->head = n;
			head = n;
		}
		else {
			Node* temp = head;
			while (--pos)
			{
				temp = temp->next;
			}
			if (temp->next) {			// insert at valid position
				n->next = temp->next;
				temp->next->head = n;
				temp->next = n;
				n->head = temp;
			}
			else if (temp) {			// insert at end
				temp->next = n;
				n->head = temp;
			}
			else {
				std::cout << "Position out of range!!!\n";  // invalid range
			}
		}
	}
	void delete_node(int pos) {
		// delete at pos 0
		if (pos == 0) {
			Node* to_del = head;
			head = head->next;
			delete to_del;
		}
		// delete at pos
		else {
			Node* temp = head;
			while (--pos)
			{
				temp = temp->next;
			}
			if (temp->next) {
				Node* to_del = temp->next;
				temp->next = to_del->next;
				if (to_del->next) {
					to_del->next->head = temp;
				}
				delete to_del;
			}
			else {
				std::cout << "Position out of range!!\n";
			}
		}
	}
};

int main() {
	Node n;
	n.creatDoubleList();
	n.insert(5, 10);
	n.display(n.head);
	n.delete_node(5);
	n.display(n.head);
}