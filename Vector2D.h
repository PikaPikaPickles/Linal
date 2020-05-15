//
// Created by yus on 03.05.2020.
//


#ifndef UNTITLED_VECTOR2D_H
#define UNTITLED_VECTOR2D_H

#include <iostream>

class Vector2D {
private:
    double x, y;
public:
    Vector2D();
    Vector2D(double x, double y);

    ~Vector2D();

    double getX() const;
    double getY() const;

    void setX(double x);
    void setY(double y);

    bool operator==(const Vector2D &v2) const;

    bool operator!=(const Vector2D &v2) const;

    Vector2D operator= (const Vector2D& v2);

    Vector2D operator+(const Vector2D &v2) const;
    Vector2D operator+=(const Vector2D &v2) const;

    Vector2D operator-(const Vector2D &v2) const;
    Vector2D operator-=(const Vector2D &v2) const;

    Vector2D operator*(double a) const;
    Vector2D operator*=(double a) const;

    Vector2D operator/ (double a) const;
    Vector2D operator/= (double a) const;

    double get_module() const;

    double scalar(const Vector2D &v2) const;

    double module_vector(const Vector2D &v2) const;

    double AngInDeg(const Vector2D &v2) const;
    double AngInRad(const Vector2D &v2) const;
};

std::ostream& operator<< (std::ostream& os, const Vector2D& v);
std::istream& operator>>(std::istream& is, Vector2D& v);



#endif //UNTITLED_VECTOR2D_H