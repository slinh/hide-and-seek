// INL_gen.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class TMesh
{
public:
	TMesh(char* parName)
	{
		FName = parName;
		FName += ".obj";
	}

	void SetTranslation(float tx, float ty, float tz)
	{
		FTrans[0] = tx;
		FTrans[1] = ty;
		FTrans[2] = tz;
	}

	void SetRotation(float rx, float ry, float rz)
	{
		FRot[0] = rx;
		FRot[1] = ry;
		FRot[2] = rz;
	}

	void Write(fstream& parFile)
	{
		double RadtoDeg = 180 / 3.1415926535897932384626433832795;
		parFile << "locTranslateVect.push_back(TTransform(vector3df(" << 
			FTrans[0] << ", zCam + " <<
			FTrans[2] << ", " <<
			FTrans[1] << "), vector3df(" <<
			FRot[0] * RadtoDeg << ", " <<
			FRot[2] * RadtoDeg << ", " <<
			FRot[1] * RadtoDeg << ")));" << endl;
	}

public:
	string FName;
	float FTrans[3];
	float FRot[3];
};

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "INL Generator V2.1" << endl << endl << "entrez le nom du fichier : ";

	char buf[255];
	string sbuf;
	cin >> buf;
	string inFileName(buf);
	string outFileName(buf);
	outFileName[outFileName.size()-3] = 'i';
	outFileName[outFileName.size()-2] = 'n';
	outFileName[outFileName.size()-1] = 'l';

	cout << endl << "input file : " << inFileName.c_str() << endl;
	cout << "output file : " << outFileName.c_str() << endl;

	int height, width;
	cout << "subdivision width : ";
	cin >> width;
	cout << "subdivision height : ";
	cin >> height;

	string folder;
	cout << "meshes folder : ";
	cin >> buf;
	folder = buf;

	fstream inputFile(inFileName.c_str() , fstream::in);

	vector<TMesh*> locMeshList;
	float* locTrans = new float[6];
	TMesh* locMesh;

	while (inputFile.getline(buf, 255))
	{
		if (buf[0] == '(')
		{
			// translation
			float tx, ty, tz;

			sscanf(buf,"(%f, %f, %f)\n", &tx, &ty, &tz);
			locMesh->SetTranslation(tx, ty, tz);
		}
		else if (buf[0] == '[')
		{
			// translation
			float rx, ry, rz;
			sscanf(buf,"[%f, %f, %f](euler)\n", &rx, &ry, &rz);
			locMesh->SetRotation(rx, ry, rz);
		}
		else if (strlen(buf) != 0)
		{
			// nom d'objet
			for (int i = 0; i < strlen(buf); ++i)
				if (buf[i] == '.')
				{
						buf[i] = '\0';
						break;
				}
		
			locMesh = new TMesh(buf);
		}
		else
		{
			if (locMeshList.size()>0)
			{
				if (locMeshList[locMeshList.size()-1] != locMesh)
					locMeshList.push_back(locMesh);
			}
			else locMeshList.push_back(locMesh);
		}
	}

	inputFile.close();

	fstream outputFile(outFileName.c_str() , fstream::out | fstream::trunc);

	outputFile.setf(0,ios::floatfield);
	outputFile.precision(8);

	outputFile << "FMap = NEW_IN_DOMAIN(Map) engine::object::TMap(" << width << ", " << height << ");" << endl << endl;
	outputFile << "f32 zCam = 0.f;" << endl;
	outputFile << "array<TTransform> locTranslateVect;" << endl << endl;

	string locStr;
	vector<TMesh*> locMeshToSave;
	int cnt = 0;

	do
	{
		cnt = 0;
		for (int i = 0; i < locMeshList.size(); ++i)
		{
			if (locMeshList[i] != NULL)
			{
				if (locStr.empty())
				{
					locStr = locMeshList[i]->FName;
				}

				if (!locMeshList[i]->FName.compare(locStr))
				{
					locMeshToSave.push_back(locMeshList[i]);
					locMeshList[i] = NULL;
				}
			}
			else cnt++;
		}

		if (locMeshToSave.size()>0)
		{
			outputFile << "/* ----- " << locStr.c_str() << " ----- */" << endl;
			outputFile << "locTranslateVect.clear();" << endl;
			outputFile << "locTranslateVect.reallocate(" << locMeshToSave.size() << ");" << endl << endl;
			for (int i = 0; i < locMeshToSave.size(); ++i)
			{
				locMeshToSave[i]->Write(outputFile);
				delete locMeshToSave[i];
			}
			outputFile << endl << "FMap->AddMeshResource(\"ms0:/PSP/GAME/Hide-And-Seek/Mesh/" << folder.c_str()  << locStr.c_str() << "\", 0, locTranslateVect);" << endl << endl;
			locMeshToSave.clear();
			locStr.clear();
		}
		
	} while (cnt != locMeshList.size());

	outputFile.close();

	cout << "\nversion speciale pour Mathieu !!" << endl;

	system("pause");

	return 0;
}

