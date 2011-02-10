FMap = NEW_IN_DOMAIN(Map) engine::object::TMap(10, 10);

f32 zCam = 1.1f;
array<TTransform> locTranslateVect;
//*
// murNord
LOGC_LOAD("load murNord\n");
locTranslateVect.reallocate(4);

locTranslateVect.push_back(TTransform(vector3df(4.8f, zCam, 0.58f), vector3df(0.f, 0.f, 0.f)));
locTranslateVect.push_back(TTransform(vector3df(4.4f, zCam, 0.58f), vector3df(0.f, 0.f, 0.f)));
locTranslateVect.push_back(TTransform(vector3df(4.0f, zCam, 0.58f), vector3df(0.f, 0.f, 0.f)));
locTranslateVect.push_back(TTransform(vector3df(3.8f, zCam, 0.58f), vector3df(0.f, 0.f, 0.f)));

//locMeshRsc = locMeshRscFMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/murNord.obj", O_NORMAL, locTranslateVect);
//FAllInteractiveItems.push_back(locMeshRsc);

// murEst
locTranslateVect.push_back(TTransform(vector3df(4.98f, zCam, 0.6f), vector3df(0.f, 90.f, 0.f)));
locTranslateVect.push_back(TTransform(vector3df(4.98f, zCam, 0.4f), vector3df(0.f, 90.f, 0.f)));
locTranslateVect.push_back(TTransform(vector3df(4.98f, zCam, 0.2f), vector3df(0.f, 90.f, 0.f)));
FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/murNord.obj", 0, locTranslateVect);
//*/

/*
// murEst
//locTranslateVect.clear();
locTranslateVect.reallocate(3);

locTranslateVect.push_back(vector3df(4.98f, zCam, 0.6f));
locTranslateVect.push_back(vector3df(4.98f, zCam, 0.4f));
locTranslateVect.push_back(vector3df(4.98f, zCam, 0.2f));
FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/murEst.obj", 0, locTranslateVect);
//*/

// murSud
LOGC_LOAD("load muSud\n");
locTranslateVect.clear();
locTranslateVect.reallocate(5);

locTranslateVect.push_back(TTransform(vector3df(4.6f, zCam, 0.02f), vector3df(0.f, 0.f, 0.f)));
locTranslateVect.push_back(TTransform(vector3df(4.4f, zCam, 0.02f), vector3df(0.f, 0.f, 0.f)));
locTranslateVect.push_back(TTransform(vector3df(4.2f, zCam, 0.02f), vector3df(0.f, 0.f, 0.f)));
locTranslateVect.push_back(TTransform(vector3df(4.0f, zCam, 0.02f), vector3df(0.f, 0.f, 0.f)));
locTranslateVect.push_back(TTransform(vector3df(3.8f, zCam, 0.02f), vector3df(0.f, 0.f, 0.f)));
FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/murSud.obj", 0, locTranslateVect);
//*/
/*
// murOuest
//locTranslateVect.clear();
locTranslateVect.reallocate(2);

locTranslateVect.push_back(vector3df(3.82f, zCam, 0.2f));
locTranslateVect.push_back(vector3df(3.82f, zCam, 0.4f));
FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/murOuest.obj", 0, locTranslateVect);
//*/
//* TO ADD
// murNordFenetre
LOGC_LOAD("load murNordFenetre\n");
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(4.7f, zCam, 0.592f), vector3df(0.f, 0.f, 0.f)));
FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/murNordFenetre.obj", 0, locTranslateVect);
//*/
//* TO ADD
// porteEO
LOGC_LOAD("load porteEO\n");
locTranslateVect.clear();
locTranslateVect.reallocate(2);

locTranslateVect.push_back(TTransform(vector3df(5.06f, zCam, 0.f), vector3df(0.f, 0.f, 0.f)));
locTranslateVect.push_back(TTransform(vector3df(4.43f, zCam, 0.59f), vector3df(0.f, 0.f, 0.f)));
FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/porteEO.obj", 0, locTranslateVect);
//*/
//* TO ADD
// porteNS
LOGC_LOAD("load porteNS\n");
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(3.8f, zCam, 0.48f), vector3df(0.f, 0.f, 0.f)));
FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/porteNS.obj", 0, locTranslateVect);
//*/
//* TO ADD
// tableCarre
LOGC_LOAD("load tableCarre\n");
locTranslateVect.clear();
locTranslateVect.reallocate(15);

locTranslateVect.push_back(TTransform(vector3df(4.06f, zCam, 0.17f), vector3df(0.f, 0.f, 0.f)));
locTranslateVect.push_back(TTransform(vector3df(4.06f, zCam, 0.3f), vector3df(0.f, 0.f, 0.f)));
locTranslateVect.push_back(TTransform(vector3df(4.06f, zCam, 0.44f), vector3df(0.f, 0.f, 0.f)));
locTranslateVect.push_back(TTransform(vector3df(4.18f, zCam, 0.18f), vector3df(0.f, 0.f, 0.f)));
locTranslateVect.push_back(TTransform(vector3df(4.18f, zCam, 0.3f), vector3df(0.f, 0.f, 0.f)));
locTranslateVect.push_back(TTransform(vector3df(4.18f, zCam, 0.44f), vector3df(0.f, 0.f, 0.f)));
locTranslateVect.push_back(TTransform(vector3df(4.32f, zCam, 0.18f), vector3df(0.f, 0.f, 0.f)));
locTranslateVect.push_back(TTransform(vector3df(4.32f, zCam, 0.3f), vector3df(0.f, 0.f, 0.f)));
locTranslateVect.push_back(TTransform(vector3df(4.32f, zCam, 0.44f), vector3df(0.f, 0.f, 0.f)));
locTranslateVect.push_back(TTransform(vector3df(4.44f, zCam, 0.18f), vector3df(0.f, 0.f, 0.f)));
locTranslateVect.push_back(TTransform(vector3df(4.44f, zCam, 0.31f), vector3df(0.f, 0.f, 0.f)));
locTranslateVect.push_back(TTransform(vector3df(4.44f, zCam, 0.44f), vector3df(0.f, 0.f, 0.f)));
locTranslateVect.push_back(TTransform(vector3df(4.58f, zCam, 0.18f), vector3df(0.f, 0.f, 0.f)));
locTranslateVect.push_back(TTransform(vector3df(4.58f, zCam, 0.31f), vector3df(0.f, 0.f, 0.f)));
locTranslateVect.push_back(TTransform(vector3df(4.58f, zCam, 0.44f), vector3df(0.f, 0.f, 0.f)));
FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/tableCarre.obj", 0, locTranslateVect);
//*/
//* TO ADD
// chaiseE
LOGC_LOAD("load chaiseE\n");
locTranslateVect.clear();
locTranslateVect.reallocate(15);

locTranslateVect.push_back(TTransform(vector3df(4.02f, zCam, 0.43f), vector3df(0.f, 0.f, 0.f)));
locTranslateVect.push_back(TTransform(vector3df(4.02f, zCam, 0.29f), vector3df(0.f, 0.f, 0.f)));
locTranslateVect.push_back(TTransform(vector3df(4.02f, zCam, 0.17f), vector3df(0.f, 0.f, 0.f)));
locTranslateVect.push_back(TTransform(vector3df(4.15f, zCam, 0.43f), vector3df(0.f, 0.f, 0.f)));
locTranslateVect.push_back(TTransform(vector3df(4.15f, zCam, 0.29f), vector3df(0.f, 0.f, 0.f)));
locTranslateVect.push_back(TTransform(vector3df(4.15f, zCam, 0.17f), vector3df(0.f, 0.f, 0.f)));
locTranslateVect.push_back(TTransform(vector3df(4.28f, zCam, 0.43f), vector3df(0.f, 0.f, 0.f)));
locTranslateVect.push_back(TTransform(vector3df(4.28f, zCam, 0.29f), vector3df(0.f, 0.f, 0.f)));
locTranslateVect.push_back(TTransform(vector3df(4.28f, zCam, 0.17f), vector3df(0.f, 0.f, 0.f)));
locTranslateVect.push_back(TTransform(vector3df(4.41f, zCam, 0.43f), vector3df(0.f, 0.f, 0.f)));
locTranslateVect.push_back(TTransform(vector3df(4.41f, zCam, 0.29f), vector3df(0.f, 0.f, 0.f)));
locTranslateVect.push_back(TTransform(vector3df(4.41f, zCam, 0.17f), vector3df(0.f, 0.f, 0.f)));
locTranslateVect.push_back(TTransform(vector3df(4.55f, zCam, 0.43f), vector3df(0.f, 0.f, 0.f)));
locTranslateVect.push_back(TTransform(vector3df(4.55f, zCam, 0.29f), vector3df(0.f, 0.f, 0.f)));
locTranslateVect.push_back(TTransform(vector3df(4.55f, zCam, 0.17f), vector3df(0.f, 0.f, 0.f)));
FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/chaiseE.obj", 0, locTranslateVect);
//*/
//*
// chaiseO
LOGC_LOAD("load chaiseO\n");
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(4.8f, zCam, 0.48f), vector3df(0.f, 0.f, 0.f)));
FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/chaiseO.obj", 0, locTranslateVect);
//*/
//*
// bureauO
LOGC_LOAD("load bureauO\n");
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(4.79f, zCam, 0.47f), vector3df(0.f, 0.f, 0.f)));
FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/bureauO.obj", 0, locTranslateVect);
//*/
// radiateur
LOGC_LOAD("load radiateur\n");
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(4.1f, zCam, 0.57f), vector3df(0.f, 0.f, 0.f)));
FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/radiateur.obj", 0, locTranslateVect);
//*/
LOGC_LOAD("End Loading Map\n");
/*
// judith2 : WAIT
LOGC_LOAD("load judith2\n");
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(4.35f, zCam, 0.26f), vector3df(0.f, 0.f, 0.f)));
FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/judith2.obj", 0, locTranslateVect);
//*/