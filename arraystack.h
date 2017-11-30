template<class T>
class Stack{
	T* data_;
	int capacity_;
	int used_;
	void grow(){
		T* tmp=new T[capacity_*2];
		for(int i=0;i<used_;i++){
			tmp[i]=data[i];
		}
		delete [] data_;
		data_=tmp;
		capacity_=capacity_*2;
	}
public:
	Stack(){
		capacity_=50;
		data_=new T[capacity_];
		used_=0;
	}
	void push(const T& data){
		if(used_==capacity_){
			grow();
		}
		data_[used_]=data;
		used_++;
	}
	void pop(){
		if(!empty()){
			used_--;
		}
	}
	T top() const{
		return data_[used_-1]
	}
	bool empty(){
		return used_==0;
	}
	~Stack(){
		delete [] data_;
	}
};