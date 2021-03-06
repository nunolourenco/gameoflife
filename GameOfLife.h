#pragma once

#include "MyMatrix.h"
#include "Cell.h"

/* Ivo Carlos Pereira Goncalves 2006125068 Nuno António Marques Lourenço 2006131888 */




public ref class GameOfLife {



	public:
		enum class neighborhoodType {MOORE, VON_NEUMANN};
		GameOfLife(unsigned rows, unsigned columns) {
			gameCells = new MyMatrix<bool>(rows, columns);
			neighborhood = neighborhoodType::MOORE;
			initCells();
		}

		GameOfLife() {
			gameCells = new MyMatrix<bool>(64, 48);
			neighborhood = neighborhoodType::MOORE;
			initCells();
		}

		void flipCellState(unsigned row, unsigned column) {
			gameCells->set(row, column, !gameCells->get(row,column));
		}

		void changeCellState(unsigned row, unsigned column, bool state) {
			gameCells->set(row,column,state);
		}
		
		bool getCellState(unsigned row, unsigned column) {
			return gameCells->get(row,column);
		}

		void changeWorld(unsigned row, unsigned columns) {
			unsigned oldRows = gameCells->rows();
			unsigned oldColumns = gameCells->columns();
			gameCells->resize(row,columns);

			if(columns > oldColumns) {
				for(unsigned i = 0; i < row; i++) {
					for(unsigned k = oldColumns; k < columns; k++) {
						gameCells->set(i, k, false);
					}
				}
				
			}
			if(row > oldRows) {
				for(unsigned i = oldRows; i < row; i++) {
					for(unsigned k = 0; k < columns; k++) {
						gameCells->set(i, k, false);
					}
				}
			}
		}

		void setNeighborhood(neighborhoodType nt) {
			neighborhood = nt;
		}

		Vector<Cell>* evolve() {
			Vector<Cell>* v = new Vector<Cell>(); 
			for(unsigned i = 0; i < gameCells->rows(); i++) {
				for(unsigned k = 0; k < gameCells->columns(); k++){
					unsigned count = getLivingNeighbors(i,k);
					if((count == 0 || count == 1 || count >= 4) && isAlive(i,k)) {
						//killCell(i,k);
						Cell c(i,k,false);
						v->append(c);

					}
					else if((count == 2 || count == 3) && isAlive(i,k)) {
						//reviveCell(i,k);
						Cell c(i,k,true);
						v->append(c);
					}

					else if(count == 3 && !isAlive(i,k)) {
						//reviveCell(i,k);
						Cell c(i,k,true);
						v->append(c);
					}
				}
			}

			for(unsigned i = 0; i < v->length(); i++) {
				changeCellState(v->get(i).getRow(), v->get(i).getCol(), v->get(i).getState());
			}
			return v;

		}

	
	private:

		
		neighborhoodType neighborhood;

		void initCells() {
			for(unsigned i = 0; i < gameCells->rows(); i++) {
				for(unsigned k = 0; k < gameCells->columns(); k++) {
					gameCells->set(i,k,false);
				}
			}
		}

		void reviveCell(unsigned row, unsigned column) {
			changeCellState(row,column,true);
		}

		bool isAlive(unsigned row, unsigned column) {
			return gameCells->get(row,column);
		}

		void killCell(unsigned row, unsigned column) {
			changeCellState(row,column,false);
		}

		unsigned getLivingNeighbors(unsigned row, unsigned column) {
			int neighbors = getNNeighbor(row, column);
			neighbors += getSNeighbor(row, column);
			neighbors += getENeighbor(row, column);
			neighbors += getWNeighbor(row, column);
			if(neighborhood == neighborhoodType::MOORE) {
				neighbors += getSENeighbor(row, column);
				neighbors += getSWNeighbor(row, column);
				neighbors += getNENeighbor(row, column);
				neighbors += getNWNeighbor(row, column);
			}
			return neighbors;
		}

		unsigned getNextVerticalIndex(unsigned row, unsigned column) {
			return (row + 1) % gameCells->rows();
		}

		unsigned getNextHorizontalIndex(unsigned row, unsigned column) {
			return (column + 1) % gameCells->columns();
		}

		unsigned getPreviousVerticalIndex(unsigned row, unsigned column) {
			if(row == 0) 
				return gameCells->rows() - 1;
			else
				return row - 1;
		}

		unsigned getPreviousHorizontalIndex(unsigned row, unsigned column) {
			if(column == 0)
				return gameCells->columns() - 1;
			else
				return column - 1;
		}

		unsigned getSWNeighbor(unsigned row, unsigned column) {
			return gameCells->get(getNextVerticalIndex(row, column), getPreviousHorizontalIndex(row, column)) ? 1 : 0;
		}

		unsigned getSENeighbor(unsigned row, unsigned column) {
			return gameCells->get(getNextVerticalIndex(row, column), getNextHorizontalIndex(row, column)) ? 1 : 0;
		}
		
		unsigned getNENeighbor(unsigned row, unsigned column) {
			return gameCells->get(getPreviousVerticalIndex(row, column), getNextHorizontalIndex(row, column)) ? 1 : 0;
		}

		unsigned getNWNeighbor(unsigned row, unsigned column) {
			return gameCells->get(getPreviousVerticalIndex(row, column), getPreviousHorizontalIndex(row, column)) ? 1 : 0;
		}

		unsigned getNNeighbor(unsigned row, unsigned column) {
			return gameCells->get(getPreviousVerticalIndex(row, column), column) ? 1 : 0;
		}
		
		unsigned getSNeighbor(unsigned row, unsigned column) {
			return gameCells->get(getNextVerticalIndex(row, column), column) ? 1 : 0;
		}

		unsigned getENeighbor(unsigned row, unsigned column) {
			return gameCells->get(row, getNextHorizontalIndex(row, column)) ? 1 : 0;
		}
		
		unsigned getWNeighbor(unsigned row, unsigned column) {
			return gameCells->get(row, getPreviousHorizontalIndex(row, column)) ? 1 : 0;
		}



		MyMatrix<bool>* gameCells;


		
};
