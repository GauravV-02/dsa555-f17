template<class T>
class Stack{
	SList<T> data_;
public:
	Stack(){}
	void push(const T& data){
		//v1
		data_.push_front(data);
	}
	void pop(){
		//v1
		data_.pop_front();
	}
	T top() const{
		SList<T>::iterator it=data_.begin();
		return *it;
	}
	bool empty(){
		return data_.empty();
	}

};