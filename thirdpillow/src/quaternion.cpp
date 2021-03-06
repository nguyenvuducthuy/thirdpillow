/*
 * quaternion.cpp
 *
 *  Created on: Apr 13, 2014
 *      Author: jwpilly
 */

#include "quaternion.h"

quaternion::quaternion() {
    // TODO Auto-generated constructor stub

}

quaternion::quaternion(float x, float y, float z, float w) {
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
}

quaternion::~quaternion() {
    // TODO Auto-generated destructor stub
}

void quaternion::set_x(float x) {
    this->x = x;
}

void quaternion::set_y(float y) {
    this->y = y;
}

void quaternion::set_z(float z) {
    this->z = z;
}

void quaternion::set_w(float w) {
    this->w = w;
}

float quaternion::get_x() {
    return x;
}

float quaternion::get_y() {
    return y;
}

float quaternion::get_z() {
    return z;
}

float quaternion::get_w() {
    return w;
}

float quaternion::magnitude() {
    return (float) sqrt(
               x * x + y * y + z * z
               + w * w);
}

void quaternion::normalize() {
    float mag = magnitude();
    x /= mag;
    y /= mag;
    z /= mag;
    w /= mag;
}

void quaternion::conjugate() {
    float x_prime = -x;
    float y_prime = -y;
    float z_prime = -z;
    float w_prime = w;
    x = x_prime;
    y = y_prime;
    z = z_prime;
    w = w_prime;
}

void quaternion::multiply(quaternion q) {
    float w_prime = w * q.get_w() - x * q.get_x() - y * q.get_y()
                    - z * q.get_z();
    float x_prime = x * q.get_w() + w * q.get_x() + y * q.get_z()
                    - z * q.get_y();
    float y_prime = y * q.get_w() + w * q.get_y() + z * q.get_x()
                    - x * q.get_z();
    float z_prime = z * q.get_w() + w * q.get_z() + x * q.get_y()
                    - y * q.get_x();
    x = x_prime;
    y = y_prime;
    z = z_prime;
    w = w_prime;
}

void quaternion::multiply(float v_x, float v_y, float v_z) {
    float x_prime = w * v_x + y * v_z - z * v_y;
    float y_prime = w * v_y + z * v_x - x * v_z;
    float z_prime = w * v_z + x * v_y - y * v_x;
    float w_prime = -x * v_x - y * v_y - z * v_z;

    x = x_prime;
    y = y_prime;
    z = z_prime;
    w = w_prime;
}

void quaternion::print() {
    printf("quaternion: %f %f %f %f\n", x, y, z, w);
}

quaternion* quaternion::clone() {
    quaternion* clone = new quaternion(x, y, z, w);
    return clone; //wow fail
}
