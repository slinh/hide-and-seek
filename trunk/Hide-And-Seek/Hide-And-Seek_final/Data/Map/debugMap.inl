FMap = NEW_IN_DOMAIN(Map) engine::object::TMap(10, 10);

f32 zCam = 0.f;
array<TTransform> locTranslateVect;

/* ----- tabouret.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(48);

locTranslateVect.push_back(TTransform(vector3df(0.81732363, zCam + 0.026013747, 2.1815689), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.75440687, zCam + 0.026013747, 2.1847956), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.82055014, zCam + 0.026130214, 2.4401441), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.75602025, zCam + 0.026130214, 2.4353044), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.75924677, zCam + 0.026013747, 2.2832038), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.81571025, zCam + 0.026013747, 2.2799771), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.75763339, zCam + 0.026013747, 2.0344944), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.82055014, zCam + 0.026013747, 2.0312679), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.81571025, zCam + 0.026013747, 1.92802), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.75279373, zCam + 0.026013747, 1.9312463), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.81893677, zCam + 0.026013747, 2.525646), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.76247329, zCam + 0.026013747, 2.5288727), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.060674, zCam + 0.026013747, 2.5288727), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.1171374, zCam + 0.026199892, 2.525646), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.0509944, zCam + 0.026013747, 1.9312463), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.1139109, zCam + 0.026199892, 1.92802), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.1187508, zCam + 0.026199892, 2.0312679), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.0558341, zCam + 0.026013747, 2.0344944), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.1139109, zCam + 0.026199892, 2.2799771), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.0574474, zCam + 0.026013747, 2.2832038), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.0542209, zCam + 0.026130214, 2.4353044), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.1187508, zCam + 0.026199892, 2.4401441), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.0526075, zCam + 0.026013747, 2.1847956), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.1155243, zCam + 0.026199892, 2.1815689), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.7124257, zCam + 0.026072577, 2.1815689), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.649509, zCam + 0.026072577, 2.1847956), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.7156522, zCam + 0.026221707, 2.429055), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.6511223, zCam + 0.026221707, 2.4242153), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.6543489, zCam + 0.026221707, 2.2832038), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.7108123, zCam + 0.026221707, 2.2799771), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.6527355, zCam + 0.026486889, 2.0344944), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.7156522, zCam + 0.026486889, 2.0312679), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.7108123, zCam + 0.026382044, 1.92802), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.6478958, zCam + 0.026382044, 1.9312463), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.7140388, zCam + 0.026340142, 2.5145569), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.6575754, zCam + 0.026340142, 2.5177836), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.9758624, zCam + 0.026340142, 2.5177836), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.0323257, zCam + 0.026340142, 2.5145569), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.9661828, zCam + 0.026382044, 1.9312463), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.0290995, zCam + 0.026382044, 1.92802), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.0339391, zCam + 0.026486889, 2.0312679), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.9710225, zCam + 0.026486889, 2.0344944), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.0290995, zCam + 0.026221707, 2.2799771), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.9726359, zCam + 0.026221707, 2.2832038), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.9694093, zCam + 0.026221707, 2.4242153), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.0339391, zCam + 0.026221707, 2.429055), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.967796, zCam + 0.026072577, 2.1847956), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.0307126, zCam + 0.026072577, 2.1815689), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/tabouret.obj", 0, locTranslateVect);

