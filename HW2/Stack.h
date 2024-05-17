template <typename DataType>

class Stack
{
	public:
		typedef typename DataType::ValueType ValueType;

		Stack() {}

		int Size() const
		{
			return ThisStack.size();
		}

		bool Empty() const
		{
			return Size() == 0;
		}

		void Push(const ValueType &ValueToAdd)
		{
			ThisStack.push_back(ValueToAdd);
		}

		void Pop()
		{
			ThisStack.pop_back();
		}

		ValueType Top()
		{
			return ThisStack.back();
		}
	
	private:
		DataType ThisStack;
};