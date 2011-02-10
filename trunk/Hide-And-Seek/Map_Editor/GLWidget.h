#ifndef ME_GLWIDGET_H
#define ME_GLWIDGET_H

#include <config.h>
#include <QtOpenGL/QtOpenGL>
#include <engineArray.h>
#include "MeshItem.h"

namespace psp { 

namespace engine
{
	namespace video
	{
		struct TVertex3D;
	}
}

using namespace engine::video;
using namespace engine::core;
	
namespace MapEditor {

class TGLWidget : public QGLWidget
{
	Q_OBJECT

	/*	Method	*/
public:
	TGLWidget(QWidget *parent);
	~TGLWidget(void);

	void AddMeshToRender(TMeshItem* parMesh);
	void DelMeshToRender(TMeshItem* parMesh);
	void DelAllMeshesToRender();

protected:
	void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

	void DrawMesh(TMeshItem* parMesh);

	static void qNormalizeAngle(int &angle);

	/*	Slots	*/
public slots:
     void setXRotation(int angle);
     void setYRotation(int angle);
     void setZRotation(int angle);

	 /*	Signals	*/
signals:
    void xRotationChanged(int angle);
    void yRotationChanged(int angle);
    void zRotationChanged(int angle);

	/*	Fields	*/
private:
	QPoint lastPos;
	int xRot;
    int yRot;
    int zRot;
	array<TMeshItem*> FMeshItemList;
	
};

} // namespace MapEditor
} // namespace psp

#endif
