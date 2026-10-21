template <typename T>
Array<T>::Array() : _array(NULL), _size(0)
{
}

template <typename T> 
Array<T>::Array(unsigned int n) :  _array(new T[n]), _size(n)
{
}

template <typename T>
Array<T>::Array(const Array &other)
{
	unsigned int i;

	_size = other._size;
	if (_size == 0)
		_array = NULL;
	else
	{
		_array = new T[_size];
		i = 0;
		while (i < _size)
		{
			_array[i] = other._array[i];
			i++;
		}
	}
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
	unsigned int i;
	T	*new_array;

	if (this != &other)
	{
		if (other._size == 0)
			new_array = NULL;
		else
		{
			new_array = new T[other._size];
			i = 0;
			while (i < other._size)
			{
				new_array[i] = other._array[i];
				i++;
			}
		}
		delete[] _array;
		_array = new_array;
		_size = other._size;
	}
	return (*this);
}

template <typename T>
Array<T>::~Array()
{
	delete[] _array;
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw std::exception();
	return (_array[index]);
}

template <typename T>
const T &Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
		throw std::exception();
	return (_array[index]);
}

template <typename T>
unsigned int	Array<T>::size() const
{
	return (_size);
}
