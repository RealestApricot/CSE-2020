template <typename DataType>

class List
{
private:
	struct Node
	{
		DataType Data;
		Node *Next;
		Node *Previous;

		Node(const DataType &NodeData, Node *PreviousNode = nullptr, Node *NextNode = nullptr)
		{
			Data = NodeData;
			Previous = PreviousNode;
			Next = NextNode;
		}

		Node()
		{
			Data = 0;
			Previous = nullptr;
			Next = nullptr;
		}
	};

public:
	class Const_Iterator
	{
		public:
			Node *Current;
			friend class List<DataType>;
	};

	class Iterator : public Const_Iterator
	{
		public:
			friend class List<DataType>;

			Iterator()
			{
				Current = nullptr;
			}

			Iterator(Node *NodeToIterate)
			{
				Current = NodeToIterate;
			}

			Iterator &operator*() -> DataType
			{
				return Current -> Data;
			}

			Iterator &operator++()
			{
				this -> Current = this -> Current -> Next;
				return *this;
			};

			Iterator &operator+=(Iterator &Other)
			{
				return Current += Other.Current;
			};

			Iterator &operator--(int)
			{
				Iterator old = *this;
				++(*this);
				return old;
			};

			Iterator &operator==(const Iterator &Other)
			{
				return Current == Other.Current;s
			};

			Iterator &operator!=(const Iterator &Other)
			{
				return Current != Other.Current;
			};
	};

	int ListSize = 0;
	Node *Head;
	Node *Tail;

	List()
	{
		ListSize = 0;
		Head = new Node;
		Tail = new Node;
		Head->Next = Tail;
		Tail->Previous = Head;
	};

	List(List &&ListToCopy)
	{
		Head = ListToCopy.Head;
		Tail = ListToCopy.Tail;
		ListSize = ListToCopy.ListSize;
		ListToCopy.Head = nullptr;
		ListToCopy.Tail = nullptr;
		ListToCopy.ListSize = 0;
	};

	List(const List<DataType> &)
	{
		Head = new Node;
		Tail = new Node;
		Head->Next = Tail;
		Tail->Previous = Head;
		ListSize = 0;
	};

	Iterator Begin() -> Iterator
	{
		return Iterator(Head -> Next);
	};

	Iterator End() -> Iterator
	{
		return Iterator(Tail);
	};

	Iterator Erase(Iterator Iteration)
	{
		Node *Position = Iteration.Current;
		Iterator ReturnValue(Position->Next);

		Position->Previous->Next = Position->Next;
		Position->Next->Previous = Position->Previous;
		delete Position;
		--ListSize;

		return ReturnValue;
	};

	Iterator Insert(Iterator Iteration, const DataType &Data)
	{
		Node *Position = Iteration.Current;
		++ListSize;
		return Iteration(Position->Previous = Position->Previous->Next = new Node(Data, Position->Previous, Position));
	};

	void PushFront(const DataType &Data)
	{
		Insert(Begin(), Data);
	};

	void PushBack(const DataType &Data)
	{
		Insert(End(), Data);
	};

	void PopFront()
	{
		Erase(Begin());
	};

	void PopBack()
	{
		Erase(--End());
	};

	void ClearList()
	{
		while (!ListIsEmpty())
		{
			PopFront();
		}
	};
};