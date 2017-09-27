
template <typename T>

class SortedList{
	struct Node{

		Node(const T& data={},Node* nx=nullptr,Node* pr=nullptr){
			
		}
	};

public:
	class const_iterator{
	public:
		const_iterator(){}
		const_iterator operator++(){}
		const_iterator operator++(int){}
		const_iterator operator--(){}
		const_iterator operator--(int){}
		bool operator==(const_iterator rhs){}
		bool operator!=(const_iterator rhs){}
		const T& operator*()const{}
	};
	class iterator:public const_iterator{
	public:
		iterator();
		iterator operator++(){}
		iterator operator++(int){}
		iterator operator--(){}
		iterator operator--(int){}
		T& operator*(){}
		const T& operator*()const{}
	};
	SortedList();
	~SortedList();
	SortedList(const SortedList& rhs);
	SortedList& operator=(const SortedList& rhs);
	SortedList(SortedList&& rhs);
	SortedList& operator=(SortedList&& rhs);
	iterator begin();
	iterator end();
	const_iterator begin() const;
	const_iterator end() const;
	iterator insert(const T& data);
	iterator search(const T& data);
	const_iterator search(const T& data) const;
	iterator erase(iterator it);
	iterator erase(iterator first, iterator last);
	bool empty() const;
	int size() const;
};

template <typename T>
SortedList<T>::SortedList(){

}
template <typename T>
SortedList<T>::~SortedList(){

}
template <typename T>
SortedList<T>::SortedList(const SortedList& rhs){

}
template <typename T>
SortedList<T>& SortedList<T>::operator=(const SortedList& rhs){

}
template <typename T>
SortedList<T>::SortedList(SortedList&& rhs){

}

template <typename T>
SortedList<T>& SortedList<T>::operator=(SortedList&& rhs){

}


template <typename T>
typename SortedList<T>::iterator SortedList<T>::insert(const T& data){

}

template <typename T>
typename SortedList<T>::iterator SortedList<T>::search(const T& data){

}

template <typename T>
typename SortedList<T>::const_iterator SortedList<T>::search(const T& data) const{

}

template <typename T>
typename SortedList<T>::iterator SortedList<T>::erase(iterator it){

}

template <typename T>
typename SortedList<T>::iterator SortedList<T>::erase(iterator first, iterator last){

}
template <typename T>
bool SortedList<T>::empty() const{

}
template <typename T>
int SortedList<T>::size() const{

}
