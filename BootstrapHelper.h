#ifndef BOOTSTRAP_HELPER_H
#define BOOTSTRAP_HELPER_H

#include "Observer.h"

class BootstrapHelper : public Observer, public Observable{
public:
	BootstrapHelper(const Handle<Quote>& quote);
	virtual ~BootstrapHelper() {}
	
	Real quoteError() const;
	const Handle<Quote>& quote() const;
	virtual Real impliedQuote() const = 0;
	virtual void setTermStructure(TS*);
	virtual Date latestDate() const;
	virtual void update();
protected:
	Handle<Quote> quote_;
	TS* termStructure_;
	Date latestDate_;
};
#endif