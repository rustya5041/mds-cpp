#ifndef RINGBUF_HPP
#define RINGBUF_HPP

#include <stdexcept>
#include <string>

template<typename T>

class RingBuffer {
private:
    T* _buf;
    size_t _size;
    T* _pTail;
    T* _pHead;
    bool _empty;

public:
    RingBuffer(size_t sz) : _size(sz), _empty(true) {
        if (_size == 0) {
            throw std::invalid_argument("Zero buffer size");
        }

        _buf = new T[_size];
        _pHead = _buf;
        _pTail = _buf;
    }

    ~RingBuffer() {
        delete [] _buf;
    }

    // st 2
    size_t getSize() const { 
        return _size; 
    }

    bool isEmpty() const { 
        return _empty; 
    }

    bool isFull() const {
        return !_empty && (_pHead == _pTail);
    }

    size_t getCount() const {
        if (isEmpty()) {
            return 0;
        }
        if (isFull()) {
            return _size;
        }
        return _pTail >= _pHead ? _pTail - _pHead : _size - (_pHead - _pTail);
    }

    size_t getFree() const {
        return _size - getCount();
    }

    // st 3
    void push(const T& value) {
        if (isFull()) {
            throw std::out_of_range("Buffer capacity exceeded");
        }
        
        *_pTail = value;
        _pTail++;
        
        if (_pTail >= _buf + _size) {
            _pTail = _buf;
        }
        _empty = false;
    }

    // st 4
    const std::string emptyBuffer = "Empty buffer";

    T& front() {
        if (isEmpty()) {
            throw std::out_of_range(emptyBuffer);
        }
        return *_pHead;
    }

    const T& front() const {
        if (isEmpty()) {
            throw std::out_of_range(emptyBuffer);
        }
        return *_pHead;
    }

    T& back() {
        if (isEmpty()) {
            throw std::out_of_range(emptyBuffer);
        }
        return _pTail == _buf ? *(_buf + _size - 1) : *(_pTail - 1);
    }

    const T& back() const {
        if (isEmpty()) {
            throw std::out_of_range(emptyBuffer);
        }
        return _pTail == _buf ? *(_buf + _size - 1) : *(_pTail - 1);
    }


    // st 5
    void pop() {
        if (isEmpty()) {
            throw std::out_of_range(emptyBuffer);
        }
        _pHead++;
        if (_pHead >= _buf + _size) {
            _pHead = _buf;
        }
        _empty = (_pHead == _pTail);
    }

    // st 6
    RingBuffer(const RingBuffer& other) : _size(other._size), _empty(other._empty) {
        _buf = new T[_size];
        std::copy(other._buf, other._buf + _size, _buf);
        
        size_t ofs_h = other._pHead - other._buf;
        size_t ofs_t = other._pTail - other._buf;
        _pHead = _buf + ofs_h;
        _pTail = _buf + ofs_t;
    }

    // st 7
    static void swap(RingBuffer& lhv, RingBuffer& rhv) {
        std::swap(lhv._buf, rhv._buf);
        std::swap(lhv._size, rhv._size);
        std::swap(lhv._pHead, rhv._pHead);
        std::swap(lhv._pTail, rhv._pTail);
        std::swap(lhv._empty, rhv._empty);
    }

    RingBuffer& operator=(RingBuffer rhv) {
        swap(*this, rhv);
        return *this;
    }
};

#endif // RINGBUF_HPP