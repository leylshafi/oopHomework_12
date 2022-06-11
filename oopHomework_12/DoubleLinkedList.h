#pragma once

template<class T>
class DoublyLinkedList
{
public:
	
	struct Node
	{
		T data;
		Node* prev;
		Node* next;

		Node(T data = "") : data(data), prev(), next() {}
	};



	// O(1)
	void push_front(T data)
	{
		push_front(new Node(data));
	}

	void push_front(Node* node)
	{
		if (_head == NULL)
		{
			_head = node;
			_tail = node;
			return;
		}

		node->next = _head;
		_head->prev = node;

		_head = node;
	}



	void push_back(T data)
	{
		push_back(new Node(data));
	}

	void push_back(Node* node)
	{
		if (_head == NULL)
		{
			_head = node;
			_tail = node;
			return;
		}


		_tail->next = node;
		node->prev = _tail;

		_tail = node;
	}


	void insert_before(Node* node, T data)
	{
		Node* new_node = new Node(data);

		new_node->prev = node->prev;

		if (node != _head)
			node->prev->next = new_node;
		else
			_head = new_node;

		new_node->next = node;
		node->prev = new_node;
	}

	void insert_after(Node* node, T data)
	{
		Node* new_node = new Node(data);

		new_node->prev = node;

		if (node != _tail)
			node->prev->next = new_node;
		else
			_tail = new_node;

		new_node->next = node->next;
		node->next = new_node;
	}


	void pop_front()
	{
		if (_head == NULL)
			return;

		if (_head->next == NULL)
		{
			delete _head;
			_head = NULL;
			_tail = NULL;
			return;
		}

		_head = _head->next;

		delete _head->prev;
		_head->prev = NULL;
	}

	void pop_back()
	{
		if (_head == NULL)
			return;

		if (_head->next == NULL)
		{
			delete _head;
			_head = NULL;
			_tail = NULL;
			return;
		}


		_tail = _tail->prev;
		delete _tail->next;
		_tail->next = NULL;
	}


	// O(N)
	Node* search(T data)
	{
		auto n = _head;

		while (n != NULL)
		{
			if (n->data == data)
				return n;

			n = n->next;
		}

		return NULL;
	}

	void startFront() const
	{
		Node* n = _head;

		while (n != NULL)
		{
			cout << n->data << endl;
			n = n->next;
		}
	}
	void startBack() const
	{
		Node* n = _tail;

		while (n != NULL)
		{
			cout << n->data << endl;
			n = n->prev;
		}
	}


	const Node* head() const { return _head; }
	const Node* tail() const { return _tail; }
	

private:
	Node* _head = NULL;
	Node* _tail = NULL;
};