#pragma once

template<typename TValue>
class IStlContainer abstract
{
public:
	virtual std::size_t size() const = 0;

	virtual bool empty() const = 0;

	virtual void push_front(const TValue& val) = 0;
	virtual void push_front(TValue&& val) = 0;

	virtual void push_back(const TValue& val) = 0;
	virtual void push_back(TValue&& val) = 0;

	virtual TValue front() = 0;
	virtual const TValue front() const = 0;

	virtual TValue back() = 0;
	virtual const TValue back() const = 0;

	virtual TValue pop_front() = 0;
	virtual TValue pop_back() = 0;

	virtual void clear() = 0;

	//iterator begin();
	//iterator end();

	//iterator rbegin();
	//iterator rend();

	//const_iterator cbegin() const;
	//const_iterator cend() const;

	virtual std::string toString() const = 0;

};
