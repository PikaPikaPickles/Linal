//
// Created by yus on 03.05.2020.
//

#include "Matrix.h"
#include<vector>

Matrix::Matrix(int n, int m)
{
    this->n = n;
    this->m = m;
    value.resize(n);
    for(int i=0; i<value.size(); i++){
        value[i].resize(m);
    }
};

Matrix::Matrix(std::vector <std::vector<double>> value)
{
    this->n = value.size();
    this->m = value[0].size();
    this->value = value;
};

Matrix::~Matrix()
{
    n = 0;
    m = 0;
};

void Matrix::InsertValue()
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            double r;
            std::cin>>value[i][j];
        }
    }
};

void Matrix::InsertValue(int i, int j, double value)
{
    this->value[i][j] = value;
};

double Matrix::getValue(int n1, int m1) const
{
    return this->value[n1][m1];
};

int Matrix::getN() const
{
    return n;
}

int Matrix::getM() const
{
    return m;
}

Matrix Matrix::operator*(const double a)
{
    int n = this->n;
    int m = this->m;
    std::vector<std::vector<double>> value;
    value = this->value;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            value[i][j] = value[i][j] * a;
        }
    }
    return Matrix(value);
};

Matrix Matrix::operator/(const double a)
{
    int n = this->n;
    int m = this->m;
    std::vector<std::vector<double>> value;
    value = this->value;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            value[i][j] = value[i][j] / a;
        }
    }
    return Matrix(value);
};

Matrix Matrix::operator+(const Matrix &a)
{
    int n = this->n;
    int m = this->m;
    std::vector<std::vector<double>> value;
    value = this->value;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            value[i][j] = value[i][j] + a.getValue(i, j);
        }
    }
    return Matrix(value);
};

Matrix Matrix::operator-(const Matrix &a)
{
    int n = this->n;
    int m = this->m;
    std::vector<std::vector<double>> value;
    value = this->value;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            value[i][j] = value[i][j] - a.getValue(i, j);
        }
    }
    return Matrix( value);
};

Matrix Matrix::operator+=(const Matrix &a)
{
    int n = this->n;
    int m = this->m;
    std::vector<std::vector<double>> value;
    value = this->value;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            value[i][j] = value[i][j] + a.getValue(i, j);
    return Matrix(value);
};

Matrix Matrix::operator-=(const Matrix &a)
{
    int n = this->n;
    int m = this->m;
    std::vector<std::vector<double>> value;
    value = this->value;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            value[i][j] = value[i][j] - a.getValue(i, j);
    return Matrix(value);
};

Matrix Matrix::operator*=(const double a)
{
    int n = this->n;
    int m = this->m;
    std::vector<std::vector<double>> value;
    value = this->value;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            value[i][j] = value[i][j] * a;
    return Matrix(value);
};

Matrix Matrix::operator/=(const double a)
{
    int n = this->n;
    int m = this->m;
    std::vector<std::vector<double>> value;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            value[i][j] = value[i][j] / a;
    return Matrix(value);
};

Matrix Matrix::transpose()
{
    std::vector<std::vector<double>> value1;
    int m = this->n;
    int n = this->m;
    value1.resize(this->value[0].size());
    for(int i=0; i<value1.size(); i++){
        value1[i].resize(this->value.size());
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            value1[i][j] = this->value[j][i];
        }
    }
    return Matrix(value1);
};

Matrix Matrix::operator*(const Matrix &a)
{
    int n = this->n;
    int m = a.m;
    std::vector<std::vector<double>> value(this->n,std::vector<double>(a.m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            double sum = 0;
            for (int k = 0; k < a.m; k++)
                sum += this->value[k][j] * a.value[i][k];
            value[i][j] = sum;
        }
    return Matrix(value);
}

std::ostream &operator<<(std::ostream &os, const Matrix &a)
{
    for (int i = 0; i < a.getN(); i++)
    {
        for (int j = 0; j < a.getM(); j++)
            os << a.getValue(i, j) << " ";
        os << std::endl;
    }

    return os;
}

std::istream &operator>>(std::istream &is, Matrix &a)
{
    for (int i = 0; i < a.getN(); i++)
        for (int j = 0; j < a.getM(); j++)
        {
            double b=0;
            is >> b;
            a.InsertValue(i, j, b);
        }
    return is;
}