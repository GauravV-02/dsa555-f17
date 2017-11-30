template<class T>
class Queue{
	SList<T> data_;
public:
	Queue(){}
	void enqueue(const T& data){
		data_.push_back(data);
	}
	void dequeue(){
		data_.pop_front();
	}
	T front() const{
		SList<T>::iterator it=data_.begin();
		return *it;
	}
	bool empty(){
		return data_.empty();
	}

};