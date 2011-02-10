FMap = NEW_IN_DOMAIN(Map) engine::object::TMap(10, 10);

f32 zCam = 0.f;
array<TTransform> locTranslateVect;

// ----- mur.obj -----
locTranslateVect.clear();
locTranslateVect.reallocate(13);     // nb d'objets

locTranslateVect.push_back(TTransform(vector3df(4.2f, zCam - 0.8f, -0.82f), vector3df(0.f, 0.f, 0.f)));
locTranslateVect.push_back(TTransform(vector3df(4.f, zCam -0.8f, -0.82f), vector3df(0.f, 0.f, 0.f)));
locTranslateVect.push_back(TTransform(vector3df(3.8f, zCam -0.8f, -0.82f), vector3df(0.f, 0.f, 0.f)));
locTranslateVect.push_back(TTransform(vector3df(4.58f, zCam -0.8f, -0.8f), vector3df(0.f, -90.f, 0.f)));
locTranslateVect.push_back(TTransform(vector3df(4.580f, zCam -0.8f, -1.2f), vector3df(0.f, -90.f, 0.f)));
locTranslateVect.push_back(TTransform(vector3df(4.4f, zCam -0.8f, -1.38f), vector3df(0.f, -180.f, 0.f)));
locTranslateVect.push_back(TTransform(vector3df(4.f, zCam -0.8f, -1.38f), vector3df(0.f, -180.f, 0.f)));
locTranslateVect.push_back(TTransform(vector3df(3.6f, zCam -0.8f, -1.38f), vector3df(0.f, -180.f, 0.f)));
locTranslateVect.push_back(TTransform(vector3df(3.62f, zCam -0.8f, -1.2f), vector3df(0.f, 90.f, 0.f)));
locTranslateVect.push_back(TTransform(vector3df(3.620f, zCam -0.8f, -1.f), vector3df(0.f, 90.f, 0.f)));
locTranslateVect.push_back(TTransform(vector3df(3.620f, zCam -0.8f, -0.8f), vector3df(0.f, 90.f, 0.f)));
locTranslateVect.push_back(TTransform(vector3df(3.620f, zCam -0.8f, -0.6f), vector3df(0.f, 90.f, 0.f)));
locTranslateVect.push_back(TTransform(vector3df(3.780f, zCam -0.8f, -0.6f), vector3df(0.f, -90.f, 0.f)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/mur.obj", 0, locTranslateVect);

// ----- MurFenetre.obj ----- 
locTranslateVect.clear();
locTranslateVect.reallocate(3);     // nb d'objets

locTranslateVect.push_back(TTransform(vector3df(4.592f, zCam - 0.8f, 1.1f), vector3df(0.f, -90.f, 0.f)));   // translation : 4.592 -1.1 -0.8   rotation :  0 0 -90
locTranslateVect.push_back(TTransform(vector3df(4.3f, zCam - 0.8f, -1.392f), vector3df(0.f, -180.f, 0.f )));
locTranslateVect.push_back(TTransform(vector3df(3.9f, zCam - 0.8f, -1.392f), vector3df(0.f, -180.f, 0.f )));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/murFenetre.obj", 0, locTranslateVect);  // 0 si l'objet n'est pas interactif, 1 si il est interactif

// ----- murCoin.obj ----- 
locTranslateVect.clear();
locTranslateVect.reallocate(1);     // nb d'objets

locTranslateVect.push_back(TTransform(vector3df(3.780f, zCam -0.8f, -0.6f), vector3df(0.f, 0.f, 0.f)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/murCoin.obj", 0, locTranslateVect);

// ----- pupitre.obj ----- 

locTranslateVect.clear();
locTranslateVect.reallocate(10);     // nb d'objets

locTranslateVect.push_back(TTransform(vector3df(4.298f, zCam -0.754f, -0.876f), vector3df(0.f,-93.192f, 0.f)));
locTranslateVect.push_back(TTransform(vector3df(4.116f, zCam -0.754f, -0.876f), vector3df(0.f, -82.807f, 0.f)));
locTranslateVect.push_back(TTransform(vector3df(3.957f, zCam -0.754f, -0.886f), vector3df(0.f, -77.888f, 0.f)));
locTranslateVect.push_back(TTransform(vector3df(4.311f, zCam -0.754f, -1.088f), vector3df(0.f, -85.740f, 0.f)));
locTranslateVect.push_back(TTransform(vector3df(4.109f, zCam -0.754f, -1.086f), vector3df(0.f, -84.977f, 0.f)));
locTranslateVect.push_back(TTransform(vector3df(3.934f, zCam -0.754f, -1.092f), vector3df(0.f, -79.479f, 0.f)));
locTranslateVect.push_back(TTransform(vector3df(4.292f, zCam -0.754f, -1.287f), vector3df(0.f, -92.208f, 0.f)));
locTranslateVect.push_back(TTransform(vector3df(4.111f, zCam -0.754f, -1.287f), vector3df(0.f, -87.773f, 0.f)));
locTranslateVect.push_back(TTransform(vector3df(3.942f, zCam -0.754f, -1.287f), vector3df(0.f, -108.088f, 0.f)));
locTranslateVect.push_back(TTransform(vector3df(4.532f, zCam -0.754f, -1.304f), vector3df(0.f, -270.f, 0.f)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/pupitre.obj", 0, locTranslateVect);

// ----- bureau.obj ----- 

locTranslateVect.clear();
locTranslateVect.reallocate(1);     // nb d'objets

locTranslateVect.push_back(TTransform(vector3df(3.762f, zCam -0.756f, -1.101f), vector3df(0.f, 90.f, 0.f)));
FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/bureau.obj", 0, locTranslateVect);

// ----- radiateur.obj ----- 

locTranslateVect.clear();
locTranslateVect.reallocate(1);     // nb d'objets

locTranslateVect.push_back(TTransform(vector3df(3.629f, zCam -0.765f, -0.874f), vector3df(0.f, 90.f, 0.f)));
FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/radiateur.obj", 0, locTranslateVect);

// ----- chaise.obj ----- 

locTranslateVect.clear();
locTranslateVect.reallocate(1);     // nb d'objets

locTranslateVect.push_back(TTransform(vector3df(3.731f, zCam -0.742f, -1.108f), vector3df(0.f, -90.f, 0.f)));
FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/chaise.obj", 0, locTranslateVect);

// ----- meubleLivre.obj -----
locTranslateVect.clear();
locTranslateVect.reallocate(1);     // nb d'objets

locTranslateVect.push_back(TTransform(vector3df(3.650f, zCam -0.753f, -1.324f), vector3df(0.f, 90.f, 0.f)));
FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/meubleLivre.obj", 0, locTranslateVect);

// ----- porte.obj -----

locTranslateVect.clear();
locTranslateVect.reallocate(2);     // nb d'objets

locTranslateVect.push_back(TTransform(vector3df(4.645f, zCam -0.702f, -0.8f), vector3df(0.f, 0.f, -90.f)));
locTranslateVect.push_back(TTransform(vector3df(3.845f, zCam -0.702f, -0.6f), vector3df(0.f, 0.f, -90.f)));
FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/porte.obj", 0, locTranslateVect);
