#ifndef LAZYOBJECT_H
#define LAZYOBJECT_H

#include "Observer.h"

class LazyObject : public virtual Observer, public virtual Observable
{
protected:
	mutable bool calculated_; // flag for showing whether something has been calculated
	virtual void performCalculations() const = 0;
public:
	void update() { calculated_ = false; }// implements observer interface
	virtual void calculate() const
	{
		if (!calculated_) 
		{
			calculated_ = true;
			try 
				// when performCalculations recursively call calculate & when flag is not set to be true
				// this will resulting in infinite loop; using this try block will prevent this error
			{
				performCalculations();
			}
			catch (...) {
				calculated_ = false;
				throw;
			}
		}
	}
};
#endif