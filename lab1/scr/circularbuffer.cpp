#include "circularbuffer.h"
#include <stdexcept>
#include <algorithm>

namespace Buffer {
	//конструктор по умолчанию
	CircularBuffer::CircularBuffer() : _buffer(nullptr), _capacity(0), _size(0), _start(0) {}

	//деструктор
	CircularBuffer::~CircularBuffer() {
		clear();
		if (_buffer != nullptr) {
			delete[] _buffer;
			_buffer = nullptr;
		}
	}
	//конструктор копирования
	CircularBuffer::CircularBuffer(const CircularBuffer& cb) : _capacity(cb._capacity), _size(cb._size), _start(cb._start) {
		_buffer = new value_type[_capacity];
		for (size_t i = 0; i < _size; i++) {
			_buffer[i] = cb[i];
		}
	}
	// конструктор с заданной глубиной
	CircularBuffer::CircularBuffer(size_t capacity) : _size(0), _start(0) {
		this->_capacity = capacity;
		_buffer = new value_type[capacity];
	}
	//конструктор с заданной глубиной и чем заполнять буфер
	CircularBuffer::CircularBuffer(size_t capacity, const value_type& elem) : _size(0), _start(0) {
		this->_capacity = capacity;
		_buffer = new value_type[capacity];
		for (size_t i = 0; i < capacity; i++) {
			_buffer[i] = elem;
			++_size;
		}
	}

	//перегрузки оператора [] доступ к элементу по индексу
	value_type& CircularBuffer::operator[](size_t i) {
		return _buffer[seek(i)];
	}

	const value_type& CircularBuffer::operator[](size_t i) const {
		return _buffer[seek(i)];
	}

	//возвращение элемента по индексу i и проверкой на корректность индекса
	value_type& CircularBuffer::at(size_t i) {
		if (i >= _size || i < 0) {
			throw std::out_of_range("Index out of range");
		}
		return _buffer[seek(i)];
	}
	//доступ по индексу с исключением
	const value_type& CircularBuffer::at(size_t i) const {
		if (i >= _size || i < 0) {
			throw std::out_of_range("Index out of range");
		}
		return _buffer[seek(i)];
	}
	//ссылка на первый элемент буфера
	value_type& CircularBuffer::front() {
		return _buffer[_start];
	}
	//ссылка на последний элемент буфера
	value_type& CircularBuffer::back() {
		return _buffer[seek(_size - 1)];
	}
	//
	const value_type& CircularBuffer::front() const {
		return _buffer[_start];
	}
	//
	const value_type& CircularBuffer::back() const {
		return _buffer[seek(_size - 1)];
	}
	//преобразование кольцевого в в линейный 
	value_type* CircularBuffer::linearize() {
		if (empty()) {
			return nullptr;
		}
		rotate(seek(0));
		_start = 0;
		return _buffer;
	}
	//проверка  линеаризован ли буфер (1 эл в начале)
	bool CircularBuffer::is_linearized() const {
		return _start == 0 || (_start + _size <= _capacity);
	}
	//элемент с индексом new_begin становится началом буфера
	void CircularBuffer::rotate(size_t new_begin) {
		if (new_begin < _capacity) {
			//если вдруг new_begin не в пределах текущего кол-ва элементов
			_size = std::max(_size, new_begin + 1);
			std::rotate(_buffer, _buffer + new_begin, _buffer + _size);
		}
	}
	//текущее кол-во эл-в
	size_t CircularBuffer::size() const {
		return _size;
	}
	//пустой ли буфер
	bool CircularBuffer::empty() const {
		return _size == 0;
	}
	//полный ли буфер
	bool CircularBuffer::full() const {
		return _size == _capacity;
	}
	//кол-во свободных ячеек
	size_t CircularBuffer::reserve() const {
		return _capacity - _size;
	}
	//глубина/вместимость 
	size_t CircularBuffer::capacity() const {
		return _capacity;
	}

	//новая вместимость буфера 
	void CircularBuffer::set_capacity(size_t new_capacity) {
		if (new_capacity > _capacity) {
			auto* new_buffer = new value_type[new_capacity];
			for (size_t i = 0; i < _size; i++) {
				new_buffer[i] = at(i);
			}
			if (_buffer != nullptr) {
				delete[] _buffer;
			}
			_buffer = new_buffer;
			_capacity = new_capacity;
			_start = 0;
		} else {
			_capacity = new_capacity;
			_size = std::min(_size, new_capacity);
		}
	}
	//изменение  размера буфера добавляя item при увеличении размера
	void CircularBuffer::resize(size_t new_size, const value_type& item) {
		if (new_size < _size) {
			_size = new_size;
		} else {
			if (_capacity < new_size)
				//новая глубина
				set_capacity(new_size);
			while (_size < new_size) {
				push_back(item);
			}
		}
	}
	//оператор присваивания =, попируем эл в текущий из cb
	CircularBuffer& CircularBuffer::operator=(const CircularBuffer& cb) {
		//если текущий и так = cb то не нужно ничего
		if (this == &cb) {
			return *this;
		}
		//если у буфера уже есть элементы то очищаем
		if (_buffer != nullptr) {
			delete[] _buffer;
		}
		_capacity = cb._capacity;
		_size = cb._size;
		_start = 0;
		_buffer = new value_type[_capacity];
		for (size_t i = 0; i < _size; i++) {
			_buffer[i] = cb[i];
		}
		return *this;
	}
	//обменимаем содержимое текущего и cb
	void CircularBuffer::swap(CircularBuffer& cb) {
		std::swap(_buffer, cb._buffer);
		std::swap(_capacity, cb._capacity);
		std::swap(_size, cb._size);
		std::swap(_start, cb._start);
	}

	//добавляем элемент в конец 
	void CircularBuffer::push_back(const value_type& item) {
		//и если нужно перезеписываем сущ-е эл-ы
		if (full()) {
			pop_front();
		}
		_buffer[seek(_size)] = item;
		if (!full()) {
			_size++;
		}
	}
	//добавляем в начало
	void CircularBuffer::push_front(const value_type& item) {
		//и перезаписываем существующие эл-ы
		if (full()) {
			pop_back();
		}
		//шаг "назад"
		_start = seek(_capacity - 1);
		//перезаписываем
		_buffer[_start] = item;
		if (!full()) {
			_size++;
		}
	}
	//удаляем последний эл-т
	void CircularBuffer::pop_back() {
		if (!empty()) {
			_size--;
		}
	}
	//удаляем первый элемент
	void CircularBuffer::pop_front() {
		if (!empty()) {
			_start = seek(1);
			_size--;
		}
	}

	//вставляем item по заданной pos
	void CircularBuffer::insert(size_t pos, const value_type& item) {
		//если привышает кол-во эл-в то ошибка
		if (pos > _size) {
			throw std::out_of_range("Invalid position");
		}
		//если полный то освобождаем место сдвигом на 1
		if (full()) {
			_start = seek(1);
		}
		//если pos в первой половине, то двигаем влево
		if (pos <= _size / 2) {
			_start = seek(_capacity - 1);
			for (size_t i = 0; i < pos; i++) {
				_buffer[seek(i)] = _buffer[seek(i + 1)];
			}
			_buffer[seek(pos)] = item;
		//иначе двигаем вправо
		} else {
			for (size_t i = _size; i > pos; i--) {
				_buffer[seek(i)] = _buffer[seek(i - 1)];
			}
			_buffer[seek(pos)] = item;
		}
		//если был не полон до добавляем
		if (_size < _capacity) {
			_size++;
		}
	}
	//удаляем [first, last]
	void CircularBuffer::erase(size_t first, size_t last) {
		if (last > _size || first >= last) {
			throw std::out_of_range("Invalid range");
		}
		//если полный то освобождаем место
		if (full()) {
			_start = seek(1);
		}
		size_t eraseStart = seek(first);
		size_t eraseEnd = seek(last);
		if (eraseEnd > eraseStart) {
			//сдвигаем элементы с eStart до конца буфера
			for (size_t i = eraseStart; i < _size - (last - first); ++i) {
				_buffer[i] = _buffer[i + (last - first)];
			}
		} else {
			//сдвигаем сначала с eStart до конца, потом в начале буфера с eEnd заполняя оставшееся
			size_t remainingSize = _size - eraseEnd;
			for (size_t i = eraseStart; i < _size - (last - first); ++i) {
				_buffer[i] = _buffer[i + (last - first)];
			}
			for (size_t i = 0; i < remainingSize; ++i) {
				_buffer[(eraseEnd + i) % _size] = _buffer[(i + eraseStart + 1) % _size];
			}
		}
		_size -= (last - first);
		if (_size == 0) {
			_start = 0;
		} else {
			_start = seek(last);
		}
	}
	//очищение буфера
	void CircularBuffer::clear() {
		_size = 0;
		_start = 0;
	}
	//индекс элемента относительно начала буфера
	size_t CircularBuffer::seek(size_t i) const {
		return (_start + i) % _capacity;
	}
	//проверка что буферы одинаковые
	bool operator==(const CircularBuffer& a, const CircularBuffer& b) {
		if (a.size() != b.size()) {
			return false;
		}
		for (size_t i = 0; i < a.size(); i++) {
			if (a[i] != b[i]) {
				return false;
			}
		}
		return true;
	}
	//проверка что буферы не одинаковые
	bool operator!=(const CircularBuffer& a, const CircularBuffer& b) {
		return !(a == b);
	}
}
