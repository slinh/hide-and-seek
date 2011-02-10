#include <QtGui/QMouseEvent>
#include "GLWidget.h"
#include <Vertex3D.h>

#ifndef GL_MULTISAMPLE
#define GL_MULTISAMPLE  0x809D
#endif

namespace psp { namespace MapEditor {

TGLWidget::TGLWidget(QWidget *parent) : QGLWidget(QGLFormat(QGL::SampleBuffers), parent),
xRot(0), yRot(0), zRot(0)
{

}

TGLWidget::~TGLWidget(void)
{
}

void TGLWidget::initializeGL()
{
    qglClearColor(QColor(255,0,255));

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_MULTISAMPLE);
    static GLfloat lightPosition[4] = { 0.5, 5.0, 7.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
}

void TGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
    glTranslatef(0.0, 0.0, -10.0);
    glRotatef(xRot / 16.0, 1.0, 0.0, 0.0);
    glRotatef(yRot / 16.0, 0.0, 1.0, 0.0);
    glRotatef(zRot / 16.0, 0.0, 0.0, 1.0);
    
	// Drawing 3D objects
	for (u32 i=0; i<FMeshItemList.size(); ++i) DrawMesh(FMeshItemList[i]);
	//glBegin(GL_QUADS);

	//double coeff = 0.5f;

	//glColor3f(0, 1.f, 1.f);
	//glVertex3d(coeff, -coeff, coeff);
	//glVertex3d(-coeff, -coeff, coeff);
	//glVertex3d(-coeff, coeff, coeff);
	//glVertex3d(coeff, coeff, coeff);

	//glEnd();
}

void TGLWidget::resizeGL(int width, int height)
{
    int side = qMin(width, height);
    glViewport((width - side) / 2, (height - side) / 2, side, side);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
#ifdef QT_OPENGL_ES_1
    glOrthof(-0.5, +0.5, -0.5, +0.5, 4.0, 15.0);
#else
    glOrtho(-0.5, +0.5, -0.5, +0.5, 4.0, 15.0);
#endif
    glMatrixMode(GL_MODELVIEW);
}

void TGLWidget::mousePressEvent(QMouseEvent *event)
{
    lastPos = event->pos();
}

void TGLWidget::mouseMoveEvent(QMouseEvent *event)
{
    int dx = event->x() - lastPos.x();
    int dy = event->y() - lastPos.y();

    if (event->buttons() & Qt::LeftButton) {
        setXRotation(xRot + 8 * dy);
        setYRotation(yRot + 8 * dx);
    } else if (event->buttons() & Qt::RightButton) {
        setXRotation(xRot + 8 * dy);
        setZRotation(zRot + 8 * dx);
    }
    lastPos = event->pos();
}

void TGLWidget::setXRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != xRot) {
        xRot = angle;
        emit xRotationChanged(angle);
        updateGL();
    }
}

void TGLWidget::setYRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != yRot) {
        yRot = angle;
        emit yRotationChanged(angle);
        updateGL();
    }
}

void TGLWidget::setZRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != zRot) {
        zRot = angle;
        emit zRotationChanged(angle);
        updateGL();
    }
}

void TGLWidget::qNormalizeAngle(int &angle)
{
    while (angle < 0)
        angle += 360 * 16;
    while (angle > 360 * 16)
        angle -= 360 * 16;
}

void TGLWidget::DrawMesh(TMeshItem* parMesh)
{
	//TVertex3D* locArrayList = parMesh->GetMesh()->GetMeshBuffer().GetArrayList();

	glBegin(GL_TRIANGLES);

	/*for(u32 i=0; i<parMesh->GetMesh()->GetMeshBuffer().GetSize(); ++i)
		glVertex3d(	locArrayList[i].X,
					locArrayList[i].Y,
					locArrayList[i].Z
					);*/

	glEnd();
}

void TGLWidget::AddMeshToRender(TMeshItem* parMesh)
{
	FMeshItemList.push_back(parMesh);
}

void TGLWidget::DelMeshToRender(TMeshItem* parMesh)
{
	u32 locId = FMeshItemList.binary_search(parMesh);
	if (locId != -1) FMeshItemList.erase(locId);
}

void TGLWidget::DelAllMeshesToRender()
{
	FMeshItemList.clear();
}

} // namespace MapEditor
} // namespace psp
