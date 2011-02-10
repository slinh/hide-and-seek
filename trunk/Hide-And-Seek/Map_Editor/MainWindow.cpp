#include "MainWindow.h"
#include <QtGui/QFileDialog>
#include "GLWidget.h"
#include <QtGui/QListView>

namespace psp { namespace MapEditor {

	MainWindow::MainWindow(void) : FOpenedMap(NULL), FGLWidget(NULL)
	{
		ui.setupUi(this);

		FGLWidget = NEW_IN_DOMAIN(Tools) TGLWidget(this);
		ui.layRenderLayout->addWidget(FGLWidget);

		QObject::connect(ui.actionNew, SIGNAL(triggered()), this, SLOT(NewMap()));
		QObject::connect(ui.actionOpen, SIGNAL(triggered()), this, SLOT(Open()));
		QObject::connect(ui.actionSave, SIGNAL(triggered()), this, SLOT(Save()));
		QObject::connect(ui.butAddMeshes, SIGNAL(clicked()), this, SLOT(AddMesh()));
		QObject::connect(ui.butDelMeshes, SIGNAL(clicked()), this, SLOT(DelMesh()));
		QObject::connect(ui.lstMeshes->selectionModel(), SIGNAL(selectionChanged(const QItemSelection &, const QItemSelection &)), 
			this, SLOT(SelectionChanged(const QItemSelection &, const QItemSelection &)));
		QObject::connect(ui.actionQuit, SIGNAL(triggered()), qApp, SLOT(quit()));

		QObject::connect(ui.actionLoad_blender_script_output, SIGNAL(triggered()), this, SLOT(ImportBlenderOutput()));

		QObject::connect(ui.actionAbout, SIGNAL(triggered()), this, SLOT(APropos()));
		QObject::connect(ui.actionAbout_Qt, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
	}


	MainWindow::~MainWindow(void)
	{
		DELETE_IN_DOMAIN(Tools) FOpenedMap;
		DELETE_IN_DOMAIN(Tools) FGLWidget;
	}

	void MainWindow::NewMap()
	{
		FGLWidget->DelAllMeshesToRender();
		DELETE_IN_DOMAIN(Tools) FOpenedMap;
		FOpenedMap = NULL;

		bool locOk;

		int locWidth = QInputDialog::getInteger(this, "Map configuration", "Map subdivision width", 100, 1, 32768, 10, &locOk);
		if (!locOk) return; 
		int locHeight = QInputDialog::getInteger(this, "Map configuration", "Map subdivision height", 100, 1, 32768, 10, &locOk);
		if (!locOk) return; 
		QString locFolder = QFileDialog::getExistingDirectory(this, "Selectionnez le dossier contenant les fichiers *.obj de la map");
		if (locFolder.size() < 1) return; 

		FOpenedMap = NEW_IN_DOMAIN(Tools) TMapItem(locWidth, locHeight, locFolder.toStdString().c_str());
		ui.lstMeshes->setModel(FOpenedMap);

		ui.tabTools->setEnabled(true);
		ui.actionSave->setEnabled(true);

		LAssert(FOpenedMap!=NULL);
	}

	void MainWindow::AddMesh()
	{
		QStringList locFichiers = QFileDialog::getOpenFileNames(this, "Add mesh(es)", QString(), "Meshes (*.obj *.md2 )");
		FOpenedMap->AddMeshes(locFichiers);
		ui.lstMeshes->setModel(FOpenedMap);
	}

	void MainWindow::DelMesh()
	{
		QModelIndexList locIndexes = ui.lstMeshes->selectionModel()->selectedRows();
		ui.lstMeshes->selectionModel()->clearSelection();

		for (s32 i=0; i<locIndexes.count(); ++i)
		{	
			FGLWidget->DelMeshToRender(FOpenedMap->GetMesh(locIndexes[i])); 
		}

		FOpenedMap->RemoveMeshes(locIndexes);
		ui.lstMeshes->setModel(FOpenedMap);
	}

	void MainWindow::Save()
	{
		QString fichier = QFileDialog::getSaveFileName(this, "Save Map", QString(), "Map (*.map )");
		if (!fichier.isEmpty()) FOpenedMap->Save(fichier.toStdString().c_str(), 8, 8);
	}

	void MainWindow::Open()
	{
		if (FOpenedMap==NULL) NewMap();

		if (FOpenedMap!=NULL)
		{
			QString fichier = QFileDialog::getOpenFileName(this, "Open Map", QString(), "Map (*.map )");
			if (!fichier.isEmpty()) FOpenedMap->Load(fichier.toStdString().c_str());
		}
	}

	void MainWindow::SelectionChanged( const QItemSelection & selected, const QItemSelection & deselected )
	{
		for (s32 i=0; i<selected.indexes().count(); ++i)
		{	
			FGLWidget->AddMeshToRender(FOpenedMap->GetMesh(selected.indexes()[i])); 
		}
		
		for (s32 i=0; i<deselected.indexes().count(); ++i)
		{	
			FGLWidget->DelMeshToRender(FOpenedMap->GetMesh(deselected.indexes()[i])); 
		}
	}

	void MainWindow::APropos()
	{
		//MAP_EDITOR_VERSION
		QString locMsg = QString("Map Editor version %1\npar Adrien Allard").arg(MAP_EDITOR_VERSION);
		QMessageBox::information(this, "Map Editor", locMsg);
	}

	void MainWindow::ImportBlenderOutput()
	{
		if (FOpenedMap==NULL) NewMap();

		if (FOpenedMap!=NULL)
		{
			QStringList fichiers = QFileDialog::getOpenFileNames(this, "Open Blender Scene informations", QString(), "Blender Scene Informations (*.bsi )");

			QStringList::Iterator it = fichiers.begin();
			 while(it != fichiers.end()) {
				 FOpenedMap->LoadBSI(it->toStdString().c_str());
				 ++it;
			 }
		}
	}
} // namespace MapEditor
} // namespace psp
