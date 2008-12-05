#ifndef OBJECT3D_H
#define OBJECT3D_H

#include <QGLWidget>

typedef struct point3d {
	float x1;
	float y1;
	float z1;
	float x2;
	float y2;
	float z2;
};

class object3d {
public:
	object3d();
	object3d(QList<point3d> &lines);
	void render(GLfloat rot = 0.0f);
	QList<point3d> model3d;
	GLfloat angle;
};
#endif // OBJECT3D_H