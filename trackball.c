// trackball.c

#include <math.h>
#include <stdio.h>
#include "trackball.h"

// Define the Quaternion type (must match the header)
typedef float Quaternion[4];

// Convert a rotation matrix to a quaternion
void mat_to_quat(float m[4][4], Quaternion q) {
    float s;
    q[3] = s = 2.0f;
    q[0] = (m[2][1] - m[1][2]) * s;
    q[1] = (m[0][2] - m[2][0]) * s;
    q[2] = (m[1][0] - m[0][1]) * s;
    q[3] = sqrtf(fmax(0.0f, 1.0f + m[0][0] + m[1][1] + m[2][2])) / 2.0f;
}

// Add two quaternions and normalize the result
void add_quats(Quaternion q1, Quaternion q2, Quaternion dest) {
    for (int i = 0; i < 4; i++)
        dest[i] = q1[i] + q2[i];

    float mag = sqrtf(dest[0]*dest[0] + dest[1]*dest[1] +
                      dest[2]*dest[2] + dest[3]*dest[3]);

    if (mag > 1e-6f) {
        for (int i = 0; i < 4; i++)
            dest[i] /= mag;
    }
}

// Convert a quaternion to a rotation matrix
void quat_to_mat(Quaternion q, float m[4][4]) {
    float x = q[0], y = q[1], z = q[2], w = q[3];

    m[0][0] = 1 - 2*y*y - 2*z*z;
    m[0][1] = 2*x*y - 2*z*w;
    m[0][2] = 2*x*z + 2*y*w;
    m[0][3] = 0;

    m[1][0] = 2*x*y + 2*z*w;
    m[1][1] = 1 - 2*x*x - 2*z*z;
    m[1][2] = 2*y*z - 2*x*w;
    m[1][3] = 0;

    m[2][0] = 2*x*z - 2*y*w;
    m[2][1] = 2*y*z + 2*x*w;
    m[2][2] = 1 - 2*x*x - 2*y*y;
    m[2][3] = 0;

    m[3][0] = 0;
    m[3][1] = 0;
    m[3][2] = 0;
    m[3][3] = 1;
}

// Initializes a 4x4 identity matrix
void mat_ident(float m[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            m[i][j] = (i == j) ? 1.0f : 0.0f;
        }
    }
}

// Simulates a virtual trackball drag (simplified)
void trackball(Quaternion q, float p1x, float p1y, float p2x, float p2y) {
    // If there's no movement, return identity rotation
    if (p1x == p2x && p1y == p2y) {
        q[0] = q[1] = q[2] = 0.0f;
        q[3] = 1.0f;
        return;
    }

    // Calculate a simple rotation axis and angle
    float axis[3] = { p1y - p2y, p2x - p1x, 0.0f };
    float angle = sqrtf((p2x - p1x)*(p2x - p1x) + (p2y - p1y)*(p2y - p1y));

    float s = sinf(angle / 2.0f);
    q[0] = axis[0] * s;
    q[1] = axis[1] * s;
    q[2] = axis[2] * s;
    q[3] = cosf(angle / 2.0f);
}
