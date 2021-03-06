#pragma once

/* Ivo Carlos Pereira Goncalves 2006125068 Nuno António Marques Lourenço 2006131888 */


public class Cell {
	private:
		unsigned row;
		unsigned col;
		bool state;

	public:
		Cell() {}

		Cell(unsigned x, unsigned y, bool s) : row(x), col(y), state(s){

		}

		unsigned getRow() {
			return row;
		}

		unsigned getCol() {
			return col;
		}

		bool getState() {
			return state;
		}
};