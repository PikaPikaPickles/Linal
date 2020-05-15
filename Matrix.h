//
// Created by yus on 03.05.2020.
//

#ifndef LINAL_MATRIX_H
#define LINAL_MATRIX_H

#include <iostream>
#include <vector>

class Matrix
{
private:
    int n;
    int m;
    std::vector<std::vector<double>> value;

public:
    Matrix(int n, int m);
    Matrix(std::vector <std::vector<double>> value);
    ~Matrix();

    void InsertValue();
    void InsertValue(int i, int j, double value);
    double getValue(int n1, int m1) const;
    int getN() const;
    int getM() const;

    Matrix operator + (const Matrix &a);
    Matrix operator - (const Matrix &a);
    Matrix operator * (const double a);
    Matrix operator / (const double a);
    Matrix operator * (const Matrix &a);

    Matrix operator += (const Matrix &a);
    Matrix operator -= (const Matrix &a);
    Matrix operator *= (const double a);
    Matrix operator /= (const double a);

    Matrix transpose();

};
std::ostream &operator << (std::ostream &os, const Matrix &a);
std::istream &operator>>(std::istream &is, Matrix &a);

#endif //LINAL_MATRIX_H