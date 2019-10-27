//
// Created by 김혁진 on 14/10/2019.
//

#include "unique_immut.h"

namespace ptr {
unique_immut::unique_immut() {
    _mgr = new mgr();
}

unique_immut::unique_immut(Object *obj) {
    _mgr = new mgr(obj);
}

unique_immut::unique_immut(const unique_immut &immut) {
    if (immut._mgr) {
        int val = immut._mgr->ptr->get();
        _mgr = new mgr(val);
    }
}

unique_immut::~unique_immut() {
    release();
}

Object* unique_immut::get() const {
	if (_mgr == nullptr) return nullptr;
	return _mgr->ptr;
}

void unique_immut::release() {
	if (_mgr != nullptr) {
		delete(_mgr);
		_mgr = nullptr;
	}
}

unique_immut unique_immut::operator+(unique_immut& unique) {
	int val = (*this)->get() + unique->get();
	(*this).release();
	unique.release();
	return unique_immut(new Object(val));
}

unique_immut unique_immut::operator-(unique_immut& unique) {
	int val = (*this)->get() - unique->get();
	(*this).release();
	unique.release();
	return unique_immut(new Object(val));
}

unique_immut unique_immut::operator*(unique_immut& unique) {
	int val = (*this)->get() * unique->get();
	(*this).release();
	unique.release();
	return unique_immut(new Object(val));
}

unique_immut unique_immut::operator/(unique_immut& unique) {
	int val = (*this)->get() / unique->get();
	(*this).release();
	unique.release();
	return unique_immut(new Object(val));
}

Object* unique_immut::operator->() {
	return _mgr->ptr;
}

unique_immut& unique_immut::operator=(unique_immut& r) {
	if ((*this)._mgr == r._mgr) return *this;
	(*this).release();
	_mgr = r._mgr;
	r._mgr = nullptr;
	return *this;
}
} // end of namespace ptr
