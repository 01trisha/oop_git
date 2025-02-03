#pragma once
#include <cstddef>

namespace Buffer {
	typedef char value_type;

	class CircularBuffer {

	private:
		value_type* _buffer;
		size_t _capacity;
		size_t _size;
		size_t _start;
		size_t seek(size_t i) const; 

	public:
		CircularBuffer();
		~CircularBuffer(); 
		CircularBuffer(const CircularBuffer& cb);

		//Constructs a buffer of a given capacity.
		explicit CircularBuffer(size_t capacity);
		//fills it entirely with the element elem.
		CircularBuffer(size_t capacity, const value_type& elem);

		// Access by index.
		value_type& operator[](size_t i);
		const value_type& operator[](size_t i) const;

		// Access by index. The methods throw an exception if the index is invalid.
		value_type& at(size_t i);
		const value_type& at(size_t i) const;

		value_type& front(); // Link to the first element.
		value_type& back();  // Link to the last element.
		const value_type& front() const;
		const value_type& back() const;

		// Linearization - shift the ring buffer so that its first element
		// will move to the beginning of the allocated memory. Returns a pointer
		// to the first element.
		value_type* linearize();
		// Checks whether the buffer is linearized.
		bool is_linearized() const;
		// Shifts the buffer so that the element is at index zero
		// with index new_begin.
		void rotate(size_t new_begin);
		// The number of elements stored in the buffer.
		size_t size() const;

		bool empty() const;
		// true, if size() == capacity().
		bool full() const;
		// The number of free cells in the buffer.
		size_t reserve() const;
		// buffer capacity
		size_t capacity() const;

		void set_capacity(size_t new_capacity);
		// Changes the buffer size.
		// In case of expansion, the new elements are filled with the item element.
		void resize(size_t new_size, const value_type& item = value_type());
		// Assignment operator.
		CircularBuffer& operator=(const CircularBuffer& cb);
		// Exchanges the contents of the buffer with the cb buffer.
		void swap(CircularBuffer& cb);

		// Adds an element to the end of the buffer.
		// If the current buffer size is equal to its capacity, then it is overwritten
		// the first element of the buffer (the buffer is looped).
		void push_back(const value_type& item = value_type());
		// Adds a new element before the first element of the buffer.
		// Similar to push_back, can overwrite the last element of the buffer.
		void push_front(const value_type& item = value_type());
		// removes the last element of the buffer.
		void pop_back();
		// removes the first element of the buffer.
		void pop_front();

		// Inserts an item element at index pos. The buffer capacity remains unchanged.
		void insert(size_t pos, const value_type& item = value_type());
		// Removes elements from the buffer in the interval [first, last).
		void erase(size_t first, size_t last);
		// Clears the buffer.
		void clear();
	};

	bool operator==(const CircularBuffer& a, const CircularBuffer& b);
	bool operator!=(const CircularBuffer& a, const CircularBuffer& b);
}

