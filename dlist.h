template <typename T>
class DList{
	struct Node{
		T data_;
		Node* next_;
		Node* prev_;
		Node(const T& d=T{},Node* n=nullptr,Node* p=nullptr){
			data_=d;	
			next_ = n;
			prev_ = p;
		}
	};

	Node* front_;
	Node* back_;

public:
	DList();
	class const_iterator{
	protected:
		Node* curr_;
		const_iterator(Node* n){curr_=n;}
	public:
		const_iterator(){
			curr_=nullptr;
		}
		const_iterator operator++(){
			//++x
			curr_=curr_->next_;
			return *this;
		}
		const_iterator operator++(int){
			//x++
			const_iterator old=*this;
			curr_=curr_->next_;
			return old;
		}
		const_iterator operator--(){
			//--x
		}
		const_iterator operator--(int){
			//x--
		}
		bool operator==(const_iterator rhs){
			return curr_ == rhs.curr_;
		}
		bool operator!=(const_iterator rhs){}
		const T& operator*()const{
			return curr_->data_;
		}
	};
	class iterator:public const_iterator{
		iterator(Node* n):const_iterator(n){}
	public:
		iterator(){}
		iterator operator++(){
			this->curr_=this->curr_->next_;
			return *this;			
		}
		iterator operator++(int){}
		iterator operator--(){}
		iterator operator--(int){}
		T& operator*(){}
		const T& operator*()const{}
	};

	void push_front(const T& d);
	void push_back(const T& d);
	void pop_front();
	void pop_back();
	void print() const;
	~DList();
};

//create an empty linked list
template <typename T>
DList<T>::DList(){
	front_=back_=nullptr;
}

template <typename T>
void DList<T>::push_front(const T& d){
	Node* nn=new Node(d,front_,nullptr);
	//if list is empty
	if(front_==nullptr){
		front_=nn;	
		back_=nn;
	}
	else{
		front_->prev_=nn;
		front_=nn;
	
	}
	

}
template <typename T>
void DList<T>::push_back(const T& d){
	Node* nn=new Node(d,nullptr,back_);
	//empty list
	if(back_==nullptr){
		front_=nn;
		back_=nn;
	}
	else{
		back_->next_=nn;
		back_=nn;
	}

}
template <typename T>
void DList<T>::pop_front(){
	if(front_){
		//if one node
		if(front_==back_){
 			//deallocate node
 			delete front_;
			front_=nullptr;
			back_=nullptr
		}
		else{
			//set front to front's next
			front_=front_->next_;
			//delete front's previous
			delete front_->prev_;
			//set front's previous to nullptr
			front_->prev_=nullptr;
		}
	}
}
template <typename T>
void DList<T>::pop_back(){

}
template <typename T>
void DList<T>::print() const{

}
template <typename T>
DList<T>::~DList(){

}

//returns sum from 1 to n... 
//sum(4) = 1 + 2 + 3 + 4
unsigned int sum(unsigned int n){
	int rc=0;
	for(int i=1;i<=n;i++){
		rc+=i;
	}
	return rc;
}

unsigned int sum(unsigned int n){
	return (n*(n+1))/2;
}










