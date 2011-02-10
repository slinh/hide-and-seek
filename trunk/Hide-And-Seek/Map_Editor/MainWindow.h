#ifndef ME_MAINWINDOWS_H
#define ME_MAINWINDOWS_H

#define MAP_EDITOR_VERSION 0.1

#include "ui_mainwindow.h"
#include "MapItem.h"
#include "GLWidget.h"

// 34Lettres functions
#include <Alloc.h>
#include <LoggerTypes.h>
#include <engineTypes.h>

namespace psp { namespace MapEditor {

	class MainWindow : public QMainWindow
	{
		Q_OBJECT

	/*	Method	*/
	public:
		MainWindow(void);
		~MainWindow(void);

	/*	Slots	*/
	public slots:
	void NewMap();
	void AddMesh();
	void DelMesh();
	void Save();
	void Open();
	void SelectionChanged(const QItemSelection & selected, const QItemSelection & deselected);
	void APropos();
	void ImportBlenderOutput();

	/*	Fields	*/
	private:
		Ui::MainWindow ui;
		TMapItem* FOpenedMap;
		TGLWidget* FGLWidget;
	};

} // namespace MapEditor
} // namespace psp

#endif
