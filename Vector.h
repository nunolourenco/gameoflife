/* Ivo Carlos Pereira Goncalves 2006125068 Nuno António Marques Lourenço 2006131888 */  #ifndef _VECTOR_H #define _VECTOR_H  #include <iostream> #include <cstring> #include <algorithm> #include <cassert>  using namespace std;  template<class T> 	class Vector {  		template<class P> 		friend ostream& operator<<(ostream& os, const Vector<P>& v);  	private: 		// current allocated capacity 		unsigned capacity; 		static const unsigned MAX_SIZE = 1000000; 		static const unsigned ALLOCATION_INCREMENT = 50;  		void copyData(const Vector<T>& v) { 			for(unsigned i = 0; i < len; i++) 				data[i] = v.data[i]; 		}  	protected: 		T* data; 		// current number of elements 		unsigned len;  	public: 		Vector(unsigned n = 10) { 			assert(n > 0 && n <= MAX_SIZE); 			len = 0; 			capacity = n; 			data = new T[capacity]; 		}  		Vector(const Vector<T>& v) { 			len = v.len; 			capacity = v.capacity; 			data = new T[capacity]; 			copyData(v); 		}  		virtual ~Vector(void) { 			delete [] data; 			len = capacity = 0; 		}  		Vector<T>& operator=(const Vector<T>& v) { 			if(len > v.len) 				len = v.len; 			else if(len < v.len){ 				len = v.len; 				capacity = v.capacity; 				data = new T[capacity]; 			} 			copyData(v); 			return *this; 		}  		bool operator==(const Vector<T>& v) { 			if(len != v.len) 				return false;  			for(unsigned i = 0; i < len; i++) { 				if(data[i] != v.data[i]) 					return false; 			} 			return true; 		}  		T& operator[](unsigned i) { 			assert(i < MAX_SIZE); 			if(i >= capacity) { 				T * tempData = new T[capacity]; 				for(unsigned i = 0; i < len; i++) 					tempData[i] = data[i]; 				delete [] data; 				capacity += ALLOCATION_INCREMENT; 				data = new T[capacity]; 				for(unsigned i = 0; i < len; i++) 					data[i] = tempData[i]; 			} 			// the number of elements will be equal to i, because its the lower position of the new created array 			if(i > len) 				len = i + 1; 			return data[i]; 		}  		unsigned length() {return len;}    		unsigned getCapacity() {return capacity;}  		void resize(unsigned newLen) { 			ensureCapacity(newLen); 			len = newLen; 		}  		void ensureCapacity(unsigned newCapacity) { 			assert(newCapacity <= MAX_SIZE); 			if(newCapacity > capacity) { 				T * tempData = new T[capacity]; 				for(unsigned i = 0; i < len; i++) 					tempData[i] = data[i]; 				delete [] data; 				capacity = newCapacity; 				data = new T[capacity]; 				for(unsigned i = 0; i < len; i++) 					data[i] = tempData[i]; 			}  		}  		T& get(unsigned i) { 			assert(i < MAX_SIZE); 			if(i >= capacity) { 				T * tempData = new T[capacity]; 				for(unsigned i = 0; i < len; i++) 					tempData[i] = data[i]; 				delete [] data; 				capacity += ALLOCATION_INCREMENT; 				data = new T[capacity]; 				for(unsigned i = 0; i < len; i++) 					data[i] = tempData[i]; 			} 			// the number of elements will be equal to i, because its the lower position of the new created array 			if(i > len) 				len = i + 1; 			return data[i]; 		}  		T& append(const T& newItem) { 			assert(len + 1 <= MAX_SIZE); 			if(len == capacity) { 				T * tempData = new T[capacity]; 				for(unsigned i = 0; i < len; i++) 					tempData[i] = data[i]; 				delete [] data; 				capacity += ALLOCATION_INCREMENT; 				data = new T[capacity]; 				for(unsigned i = 0; i < len; i++) 					data[i] = tempData[i]; 			} 			data[len++] = newItem; 			return data[len-1]; 		} 	};  	template<class P> 		ostream& operator<<(ostream& os, const Vector<P>& v) { 			for(unsigned i = 0; i < v.len; i++) 				os << v.data[i] << " "; 			return os; 		}  #endif 