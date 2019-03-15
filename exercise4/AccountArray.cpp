#include "AccountArray.h"

void AccountArray::setCapacity(int nCapacity)
{
	if (getCapacity() < nCapacity) {

		Account** nArr = new Account*[nCapacity];

		for (int i = 0; i < getSize(); i++) {
			nArr[i] = arr[i];
		}

		delete[] arr;

		arr = nArr;

		this->capacity = nCapacity;

	}
}

int AccountArray::getCapacity() const
{
	return this->capacity;
}

void AccountArray::setSize(int nSize)
{
	if (nSize < 0) return;

	if (nSize > getCapacity()) {
		setCapacity(nSize);
	}

	this->size = nSize;
}

AccountArray::AccountArray(){}

AccountArray::~AccountArray()
{

	for (int i = 0; i < getSize(); i++)
		delete arr[i];

	delete[] arr;
}

Account AccountArray::get(int index) const
{
	if (index >= 0 && index < getSize()) {
		return *(this->arr[index]);
	}
}

Account & AccountArray::get(int index)
{
	if (index >= 0 && index < getSize()) {
		return *(this->arr[index]);
	}
}

int AccountArray::getSize() const
{
	return this->size;
}

bool AccountArray::isEmpty() const
{
	return (getSize()== 0);
}

void AccountArray::add(const Account & other)
{
	setSize(getSize() + 1);
	arr[getSize() - 1] = new Account(other);

}

void AccountArray::set(const Account & other, int index)
{
	if (index == getSize())add(other);
	else if (index >= 0 && index < getSize()) {
		delete arr[index];
		arr[index] = new Account(other);
	}
}

bool AccountArray::remove(int index)
{
	if (index >= 0 && index < getSize()) {
		delete arr[index];
		for (int i = index; i < getSize() - 1; i++) {
			arr[i] = arr[i + 1];
		}
	}
	setSize(getSize() - 1);
	return false;
}
