FMap = NEW_IN_DOMAIN(Map) engine::object::TMap(10, 10);

f32 zCam = 0.f;
array<TTransform> locTranslateVect;

/* ----- fenetre.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(3);

locTranslateVect.push_back(TTransform(vector3df(3.8995624, zCam + -0.79999995, -1.3923353), vector3df(0, -180.00002, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.2995629, zCam + -0.79999995, -1.3923354), vector3df(0, -180.00002, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.5923605, zCam + -0.79999995, -1.100439), vector3df(0, -89.999982, -0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/fenetre.obj", 0, locTranslateVect);

/* ----- radiateur.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(3.6291456, zCam + -0.76543689, -0.87393862), vector3df(0, 89.999982, -0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/radiateur.obj", 0, locTranslateVect);

/* ----- porteLivre.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(3.7645772, zCam + -0.74205732, -1.0392158), vector3df(0, -28.71418, -0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/porteLivre.obj", 0, locTranslateVect);

/* ----- caisse.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(3.6428289, zCam + -0.69215608, -1.3291668), vector3df(0, -224.87854, -0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/caisse.obj", 0, locTranslateVect);

/* ----- bouteille.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(3.6527376, zCam + -0.77240217, -1.3274484), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/bouteille.obj", 0, locTranslateVect);

/* ----- livreUnique.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(3.6601934, zCam + -0.73337936, -1.3245348), vector3df(-0, 89.999982, -39.295164)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/livreUnique.obj", 0, locTranslateVect);

/* ----- duoLivre.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(3);

locTranslateVect.push_back(TTransform(vector3df(3.6580083, zCam + -0.76675528, -1.3421694), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.6547673, zCam + -0.73416615, -1.3421694), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.6616356, zCam + -0.73416615, -1.3054088), vector3df(0, 89.999982, -0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/duoLivre.obj", 0, locTranslateVect);

/* ----- corbeille.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(2);

locTranslateVect.push_back(TTransform(vector3df(3.760679, zCam + -0.79361922, -0.99418658), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.4181657, zCam + -0.79361922, -0.83194965), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/corbeille.obj", 0, locTranslateVect);

/* ----- meubleLivre.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(3.6498957, zCam + -0.75328016, -1.3236117), vector3df(0, 89.999982, -0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/meubleLivre.obj", 0, locTranslateVect);

/* ----- pupitre.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(10);

locTranslateVect.push_back(TTransform(vector3df(4.532433, zCam + -0.75387317, -1.3041095), vector3df(0, -270, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.2980165, zCam + -0.75387317, -0.87641311), vector3df(0, -93.191811, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.3110032, zCam + -0.75387317, -1.0879064), vector3df(0, -85.739925, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.2924509, zCam + -0.75387317, -1.2872413), vector3df(0, -92.208503, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.110641, zCam + -0.75387317, -1.2872413), vector3df(0, -87.772835, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.1087856, zCam + -0.75387317, -1.0860511), vector3df(0, -84.977491, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.1162066, zCam + -0.75387317, -0.87641311), vector3df(0, -82.806666, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.9566588, zCam + -0.75387317, -0.88568914), vector3df(0, -77.887994, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.9343965, zCam + -0.75387317, -1.0916167), vector3df(0, -79.479271, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.9418173, zCam + -0.75387317, -1.2872413), vector3df(0, -108.08832, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/pupitre.obj", 0, locTranslateVect);

/* ----- chaise.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(3.7308292, zCam + -0.74223351, -1.1081727), vector3df(0, -89.999982, -0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/chaise.obj", 0, locTranslateVect);

/* ----- bureau2.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(3.7621672, zCam + -0.75613654, -1.1014658), vector3df(0, 89.999982, -0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/bureau2.obj", 0, locTranslateVect);

/* ----- porte.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(5.3983927, zCam + 0, 0), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/porte.obj", 0, locTranslateVect);

/* ----- coinBG.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(3.7800157, zCam + -0.79999995, -0.60000002), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/coinBG.obj", 0, locTranslateVect);

/* ----- murE.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(3);

locTranslateVect.push_back(TTransform(vector3df(3.7800157, zCam + -0.79999995, -0.60000002), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.5800161, zCam + -0.79999995, -1.2), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.5800147, zCam + -0.79999995, -0.80000001), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/murE.obj", 0, locTranslateVect);

/* ----- murO.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(4);

locTranslateVect.push_back(TTransform(vector3df(3.6200135, zCam + -0.79999995, -0.60000002), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.6200135, zCam + -0.79999995, -0.80000001), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.6200135, zCam + -0.79999995, -1), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.6200135, zCam + -0.79999995, -1.2), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/murO.obj", 0, locTranslateVect);

/* ----- murS.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(3);

locTranslateVect.push_back(TTransform(vector3df(3.5999999, zCam + -0.79999995, -1.379999), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.400013, zCam + -0.79999995, -1.379999), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.0000143, zCam + -0.79999995, -1.379999), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/murS.obj", 0, locTranslateVect);

/* ----- murN.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(3);

locTranslateVect.push_back(TTransform(vector3df(4.2000155, zCam + -0.79999995, -0.81999999), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.0000143, zCam + -0.79999995, -0.81999999), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.8000143, zCam + -0.79999995, -0.81999999), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/murN.obj", 0, locTranslateVect);

