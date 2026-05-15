#ifndef MATRIX_H
#define MATRIX_H

#pragma once

#include <stdexcept>

using std::cout;
using std::endl;
using std::runtime_error;

template <typename E>
class Matriz {
private:
	int rows;
	int columns;
	E** matriz;

public:
	Matriz(int rows, int columns) {
		if (rows <= 0 || columns <= 0)
			throw runtime_error("Numbre of rows and columns must be greater than zero.");
		this->rows = rows;
		this->columns = columns;
		matriz = new E* [rows];
		for (int i = 0; i < rows; i++)
			matriz[i] = new E[columns];
	}

	~Matriz() {
		for (int i = 0; i < rows; i++)
			delete[] matriz[i];
		delete[] matriz;
	}

	E getValue(int row, int column) {
		if (row < 0 || row >= rows)
			throw runtime_error("Invalid row.");
		if (column < 0 || column >= columns)
			throw runtime_error("Invalid column.");
		return matriz[row][column];
	}

	void setValue(int row, int column, E value) {
		if (row < 0 || row >= rows)
			throw runtime_error("Invalid row.");
		if (column < 0 || column >= columns)
			throw runtime_error("Invalid column.");
		matriz[row][column] = value;
	}

	int getRows() {
		return rows;
	}

	int getColumns() {
		return columns;
	}

	void setAll(E value) {
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < columns; j++)
				matriz[i][j] = value;
	}

	void transpose() {
		E** temp = matriz;
		matriz = new E* [columns];
		for (int i = 0; i < columns; i++)
			matriz[i] = new E[rows];
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < columns; i++)
				matriz[j][i] = temp[i][j];
		int tempInt = columns;
		columns = rows;
		rows = tempInt;
		delete temp;
	}

	void addRow(E value) {
		E** temp = matriz;
		matriz = new E* [rows + 1];
		for (int i = 0; i < rows; i++) {
			matriz[i] = temp[i];
		}
		E* tempRow = new E[columns];
		for (int i = 0; i < columns; i++)
			tempRow[i] = value;
		matriz[rows] = tempRow;
		rows++;
	}

	void addColumn(E value) {
		for (int i = 0; i < rows; i++) {
			E* temp1 = matriz[i];
			E* temp2 = new E[columns + 1];
			for (int j = 0; j < columns; j++) {
				temp2[j] = temp1[j];
			}
			temp2[columns] = value;
			matriz[i] = temp2;
			delete temp1;
		}
		columns++;
	}

	void removeRow(int row) {
		if (row < 0 || row >= rows)
			throw runtime_error("Invalid row.");
		E** temp = matriz;
		matriz = new E* [rows - 1];
		for (int i = 0; i < row; i++)
				matriz[i] = temp[i];
		for (int i = row + 1; i < rows; i++)
			matriz[i - 1] = temp[i];
		rows--;
		delete temp;
	}

	void removeColumn(int column) {
		if (column < 0 || column >= columns)
			throw runtime_error("Invalid column.");
		for (int i = 0; i < rows; i++) {
			E* temp1 = matriz[i];
			E* temp2 = new E[columns - 1];
			for (int j = 0; j < column; j++)
				temp2[j] = temp1[j];
			for (int j = column + 1; j < columns; j++)
				temp2[j - 1] = temp2[j];
			matriz[i] = temp2;
			delete temp1;
		}
		columns--;
	}

	void print() {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++)
				cout << matriz[i][j] << "\t";
			cout << endl;
		}
	}
};

#endif