#pragma once

/* Ivo Carlos Pereira Goncalves 2006125068 Nuno António Marques Lourenço 2006131888 */

#include "Vector.h"


template<class T>
class MyMatrix {
	protected:
		Vector< Vector<T> > innerVector; 
	private:

	public:

		MyMatrix(unsigned n = 64, unsigned m = 48) {
			innerVector.resize(m);
			for(unsigned i = 0; i < m; i++) {
				innerVector[i].resize(n);
				
			}
		}
		unsigned rows() {
			return innerVector.length();
		}

		unsigned columns() {
			return innerVector[0].length();
		}

		T& get(unsigned i, unsigned j) {
			return innerVector[i][j];
		}

		void set(unsigned i, unsigned j, const T& newValue) {
			int b = 0;
			innerVector[i][j] = newValue;
			b++;
		}

		void resize(unsigned rows, unsigned columns) {
			innerVector.resize(rows);
			for(unsigned i = 0; i < rows; i++) {
				innerVector[i].resize(columns);
			}
		}








};