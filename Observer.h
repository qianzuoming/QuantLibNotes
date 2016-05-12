#ifndef OBSERVER_H
#define OBSERVER_H

#include<list>
#include<memory>

using std::list; using std::shared_ptr;

class Observable{
	friend class Observer;
public:
	Observable();
	Observable(const Observable&);
	Observable& operator=(const Observable&);
	virtual ~Observable();
	void notifyObservers();
private:
	void registerObserver(Observer*);
	void unregisterObserver(Observer*);
	list<Observer*> observers_;
};

class Observer {
public:
	Observer();
	Observer(const Observer&);
	Observer& operator=(const Observer&);
	virtual ~Observer();
	void registerWith(const shared_ptr<Observable>&);
	void unregisterWith(const shared_ptr<Observable>&);
	virtual void update() = 0;
private:
	list<shared_ptr<Observable> > observables_;
};

#endif