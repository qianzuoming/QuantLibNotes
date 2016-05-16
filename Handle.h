template<class Type>
class Handle {
protected:
	class Link : public Observable, public Observer {
	public:
		explicit Link(const shared_ptr<Type>& h = shared_ptr<Type>());
		void linkTo(const shared_ptr<Type>&);
		bool empty() const;
		void update() { notifyObservers(); }
	private:
		shared_ptr<Type> h_;
	};
	boost::shared_ptr<Link<Type> > link_;
public:
	explicit Handle(const shared_ptr<Type>& h = shared_ptr<Type>());
	const shared_ptr<Type>& operator->() const;
	const shared_ptr<Type>& operator*() const;
	bool empty() const;
	operator boost::shared_ptr<Observable>() const;
};

template<class Type>
class RelinkableHandle : public Handle<Type>{
public:
	explicit RelinkableHandle(const shared_ptr<Type>& h = shared_ptr<Type>());
	void linkTo(const boost::shared_ptr<Type>&);
};