FMap = NEW_IN_DOMAIN(Map) engine::object::TMap(110, 110);

f32 zCam = 0.f;
array<TTransform> locTranslateVect;

/* ----- coinNO.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(6);

locTranslateVect.push_back(TTransform(vector3df(1.4764569, zCam + -0.79999995, -0.78006345), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.4764543, zCam + -0.79999995, 0.5199362), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.57645595, zCam + -0.79999995, -0.78006291), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.47645515, zCam + -0.79999995, 1.7199376), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.4764566, zCam + -0.79999995, -0.38006309), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.7764554, zCam + -0.79999995, 1.0199361), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/coinNO.obj", 0, locTranslateVect);

/* ----- coinBG.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(6);

locTranslateVect.push_back(TTransform(vector3df(1.3800159, zCam + -0.79999995, 1.4000019), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.48002964, zCam + -0.79999995, 1.4000093), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.58001721, zCam + -0.79999995, -1.4000167), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.480015, zCam + -0.79999995, -0.099997148), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.7800157, zCam + -0.79999995, -0.60000002), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.4960413, zCam + -0.79999626, 0.8003211), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/coinBG.obj", 0, locTranslateVect);

/* ----- faussePorte.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(12);

locTranslateVect.push_back(TTransform(vector3df(1.3799868, zCam + -0.7999047, 1.3991513), vector3df(0, -180.00002, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.5200119, zCam + -0.80000085, 0.099999122), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.2000008, zCam + -0.7994386, 0.57998621), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(2.1000023, zCam + -0.79579741, 1.1799865), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.1000013, zCam + -0.80016673, 1.1799856), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.8000027, zCam + -0.79579741, -0.72001177), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.40000081, zCam + -0.79579741, -0.72001314), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.80000323, zCam + -0.80016673, -0.97998554), vector3df(0, -270, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.0000021, zCam + -0.7994386, -0.57998419), vector3df(0, -270, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.3200174, zCam + -0.79579753, -1.4000009), vector3df(0, -359.99998, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.79998714, zCam + -0.79579163, -0.71999723), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(-0.79998714, zCam + -0.79579163, 1.1800004), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/faussePorte.obj", 0, locTranslateVect);

/* ----- murS.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(95);

locTranslateVect.push_back(TTransform(vector3df(4.2000155, zCam + -0.79999995, 0.020001207), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.8000157, zCam + -0.79999995, 0.020001207), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.0000157, zCam + -0.79999995, 0.020001207), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.400013, zCam + -0.79999995, 0.020001207), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.6000113, zCam + -0.79999995, 0.020001207), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.6000113, zCam + -0.79999995, -0.58000004), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.8000116, zCam + -0.79999995, -0.58000004), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.0000157, zCam + -0.79999995, -0.58000004), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.8000157, zCam + -0.79999995, -0.58000004), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.2000155, zCam + -0.79999995, -0.58000004), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.8000157, zCam + -0.79999995, -0.77999866), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.0000143, zCam + -0.79999995, -0.77999866), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.8000116, zCam + -0.79999995, -0.77999866), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.6000113, zCam + -0.79999995, -0.77999866), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.0000143, zCam + -0.79999995, -1.379999), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.2000155, zCam + -0.79999995, -0.77999866), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.400013, zCam + -0.79999995, -1.379999), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.5999999, zCam + -0.79999995, -1.379999), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.8000157, zCam + -0.79999995, 0.62000197), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.0000143, zCam + -0.79999995, 0.62000197), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.400013, zCam + -0.79999995, 0.62000197), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.400013, zCam + -0.79999995, 0.82000053), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.0000143, zCam + -0.79999995, 0.82000053), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.8000157, zCam + -0.79999995, 0.82000053), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.4000113, zCam + -0.79999995, 0.61999923), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.5000157, zCam + -0.79999995, 0.31999955), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.7000155, zCam + -0.79999995, 0.31999955), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.1000149, zCam + -0.79999995, 0.31999955), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.9000149, zCam + -0.79999995, 0.31999955), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.3000147, zCam + -0.79999995, 0.31999955), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.8000145, zCam + -0.79999995, -0.57999933), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.2000139, zCam + -0.79999995, -0.57999933), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.4000137, zCam + -0.79999995, -0.57999933), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.6000007, zCam + -0.79999995, 0.9200018), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.8000175, zCam + -0.79999995, 0.9200018), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.0000157, zCam + -0.79999995, 0.9200018), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.4000007, zCam + -0.79999995, 0.9200018), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.2000009, zCam + -0.79999995, 0.9200018), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.2858967e-005, zCam + -0.79999995, 0.9200018), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.19999784, zCam + -0.79999995, 0.9200018), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.80001295, zCam + -0.79999995, 0.9200018), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.60001469, zCam + -0.79999995, 0.9200018), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.39999789, zCam + -0.79999995, 0.9200018), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(-0.40000302, zCam + -0.79999995, 0.9200018), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(-0.1999862, zCam + -0.79999995, 0.9200018), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(-0.600003, zCam + -0.79999995, 0.9200018), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(-0.80000085, zCam + -0.79999995, 0.9200018), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.6999992, zCam + -0.79999995, -0.98000067), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.900016, zCam + -0.79999995, -0.98000067), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.1000142, zCam + -0.79999995, -0.98000067), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.5000129, zCam + -0.79999995, -0.98000067), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.0000141, zCam + -0.79999995, -0.98000067), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.60001564, zCam + -0.79999995, -0.98000067), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(-0.59999907, zCam + -0.79999995, -0.98000067), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.5986385e-005, zCam + -0.79999995, -0.98000067), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(-0.19998227, zCam + -0.79999995, -0.98000067), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(-0.39999899, zCam + -0.79999995, -0.98000067), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(-0.79998326, zCam + -0.79999995, -0.98000067), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.49999854, zCam + -0.79999995, -1.9799966), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.1000135, zCam + -0.79999995, -1.9799966), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.3, zCam + -0.79999995, -1.9799966), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.69999856, zCam + -0.79999995, -1.9799966), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.300028, zCam + -0.79999995, -1.9799966), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.700011, zCam + -0.79999995, -1.9799988), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.5000128, zCam + -0.79999995, -1.9799988), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.1000168, zCam + -0.79999995, -2.5799997), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.3, zCam + -0.79999995, -2.5799975), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.70001572, zCam + -0.79999995, -2.5799975), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.700016, zCam + -0.79999995, -2.5799997), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.5000128, zCam + -0.79999995, -2.5799997), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.90001464, zCam + -0.79999995, -2.5799975), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.10002559, zCam + -0.79999995, -0.98000067), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.50001341, zCam + -0.79999995, 1.5199996), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.70001632, zCam + -0.79999995, 1.5199996), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.90001458, zCam + -0.79999995, 1.5199996), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.60001469, zCam + -0.79999995, 1.8200008), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.80001295, zCam + -0.79999995, 1.8200008), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.40000001, zCam + -0.79999995, 1.8200037), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1, zCam + -0.79999995, 1.8200008), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.3190179e-005, zCam + -0.79999995, 1.8200037), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.1000113, zCam + -0.79999995, 1.8199996), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.9000108, zCam + -0.79999995, 1.8199996), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.7000239, zCam + -0.79999995, 1.8199996), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.5000256, zCam + -0.79999995, 1.8199996), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(-0.39998695, zCam + -0.79999995, 1.2200001), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(-0.59997398, zCam + -0.79999995, 1.2200001), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.3190179e-005, zCam + -0.79999995, 1.2200001), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(-0.19998656, zCam + -0.79999995, 1.2200001), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.80001253, zCam + -0.79999983, -0.6799984), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.2000134, zCam + -0.79999983, -0.6799984), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.2000134, zCam + -0.79999983, 0.52000016), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.80001253, zCam + -0.79999983, 0.52000016), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.80001253, zCam + -0.79999983, -0.079999179), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.2000134, zCam + -0.79999983, -0.079999179), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.3000453, zCam + -0.79999995, -0.98000067), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/murS.obj", 0, locTranslateVect);

/* ----- murN.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(91);

locTranslateVect.push_back(TTransform(vector3df(4.400013, zCam + -0.79999995, 0.5800004), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.0000143, zCam + -0.79999995, 0.5800004), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.8000157, zCam + -0.79999995, 0.5800004), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.8000112, zCam + -0.79999995, 0.5800004), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.6000113, zCam + -0.79999995, -0.019997139), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.400013, zCam + -0.79999995, -0.019997139), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.0000157, zCam + -0.79999995, -0.019997139), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.8000157, zCam + -0.79999995, -0.019997139), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.2000155, zCam + -0.79999995, -0.019997139), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.8000143, zCam + -0.79999995, -0.81999999), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.0000143, zCam + -0.79999995, -0.81999999), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.2000155, zCam + -0.79999995, -0.81999999), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.8000157, zCam + -0.79999995, 0.78000152), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.0000143, zCam + -0.79999995, 0.78000152), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.400013, zCam + -0.79999995, 0.78000152), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.8, zCam + -0.79999995, 1.3800013), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.0000167, zCam + -0.79999995, 1.3800013), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.4000001, zCam + -0.79999995, 1.3800013), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.4000149, zCam + -0.79999995, 1.3800013), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.4000139, zCam + -0.79999995, 0.57999963), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.2000151, zCam + -0.79999995, 0.57999963), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.3000147, zCam + -0.79999995, -0.3199994), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.9000149, zCam + -0.79999995, -0.3199994), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.1000149, zCam + -0.79999995, -0.3199994), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.8000135, zCam + -0.79999995, 0.57999963), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.7000155, zCam + -0.79999995, -0.3199994), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.5000157, zCam + -0.79999995, -0.3199994), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.3000138, zCam + -0.79999995, 1.1799999), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.5000136, zCam + -0.79999995, 1.1799999), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.100014, zCam + -0.79999995, 1.1799999), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.7000128, zCam + -0.79999995, 1.1799999), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(-0.80000085, zCam + -0.79999995, -0.71999782), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(-0.600003, zCam + -0.79999995, -0.71999782), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(-0.1999862, zCam + -0.79999995, -0.71999782), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(-0.40000302, zCam + -0.79999995, -0.71999782), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.39999789, zCam + -0.79999995, -0.71999782), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.60001469, zCam + -0.79999995, -0.71999782), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.80001295, zCam + -0.79999995, -0.71999782), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.2858967e-005, zCam + -0.79999995, -0.71999782), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.2000009, zCam + -0.79999995, -0.71999782), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.4000007, zCam + -0.79999995, -0.71999782), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.0000157, zCam + -0.79999995, -0.71999782), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.8000175, zCam + -0.79999995, -0.71999782), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.60001069, zCam + -0.79999995, -1.6199994), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.80000997, zCam + -0.79999995, -1.6199994), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.0000057, zCam + -0.79999995, -1.6199994), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.5000128, zCam + -0.79999995, -2.0199983), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.700011, zCam + -0.79999995, -2.0199983), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.69999856, zCam + -0.79999995, -2.0199962), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.3, zCam + -0.79999995, -2.0199962), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.1000135, zCam + -0.79999995, -2.0199962), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.1000168, zCam + -0.79999995, -2.0199983), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.4999992, zCam + -0.79999995, -1.0200001), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.900016, zCam + -0.79999995, -1.0200001), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.6999992, zCam + -0.79999995, -1.0200001), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.70001632, zCam + -0.79999995, 1.1800005), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.49999946, zCam + -0.79999995, 1.1800005), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.0000141, zCam + -0.79999995, 1.78), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.80001295, zCam + -0.79999995, 1.78), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.60001469, zCam + -0.79999995, 1.78), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.40000001, zCam + -0.79999995, 1.78), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.3190179e-005, zCam + -0.79999995, 1.78), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(-0.2999858, zCam + -0.79999995, 2.3800001), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(-0.099971108, zCam + -0.79999995, 2.3800001), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.10002715, zCam + -0.79999995, 2.3800001), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.3000142, zCam + -0.79999995, 2.3800001), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.100015, zCam + -0.79999995, 2.5800016), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.70002979, zCam + -0.79999995, 2.5800016), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.50001508, zCam + -0.79999995, 2.5800016), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.3000109, zCam + -0.79999995, 2.5800016), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.5000256, zCam + -0.79999995, 2.5800016), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.9000108, zCam + -0.79999995, 2.5800016), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.1000113, zCam + -0.79999995, 2.5800016), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(-0.80000085, zCam + -0.79999995, 1.1800009), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(-0.600003, zCam + -0.79999995, 1.1800009), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(-0.1999862, zCam + -0.79999995, 1.1800009), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(-0.40000302, zCam + -0.79999995, 1.1800009), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.2858967e-005, zCam + -0.79999995, 1.1800009), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(-0.59997398, zCam + -0.79999995, 1.78), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(-0.39998695, zCam + -0.79999995, 1.78), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.2000009, zCam + -0.79999995, 0.48000067), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.80001295, zCam + -0.79999995, 0.48000067), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.80001295, zCam + -0.79999995, -0.11999866), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.2000009, zCam + -0.79999995, -0.11999866), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.80001295, zCam + -0.79999995, 0.87999898), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.2000009, zCam + -0.79999995, 0.87999898), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.2000155, zCam + -0.79999995, -0.61999977), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.0000143, zCam + -0.79999995, -0.61999977), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.8000143, zCam + -0.79999995, -0.61999977), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.6000123, zCam + -0.79999995, -0.61999977), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.8000135, zCam + -0.79999995, -0.61999977), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/murN.obj", 0, locTranslateVect);

/* ----- murO.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(62);

locTranslateVect.push_back(TTransform(vector3df(3.820014, zCam + -0.79999995, 0.40000001), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.820014, zCam + -0.79999995, 0.2), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.820014, zCam + -0.79999995, -0.40000135), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.820014, zCam + -0.79999995, 0), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.820014, zCam + -0.79999995, -0.60000002), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.6200135, zCam + -0.79999995, -1.2), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.6200135, zCam + -0.79999995, -1), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.6200135, zCam + -0.79999995, -0.80000001), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.6200135, zCam + -0.79999995, -0.60000002), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.820014, zCam + -0.79999995, 0.79999948), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.4200139, zCam + -0.79999995, 1.0000001), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.4200139, zCam + -0.79999995, 1.2000002), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.4200139, zCam + -0.79999995, 1.4000002), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.420013, zCam + -0.79999995, 0.79999948), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.5200133, zCam + -0.79999995, 0.29999843), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.5200133, zCam + -0.79999995, -0.1000016), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.4800158, zCam + -0.79999995, 0.0999984), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.2200158, zCam + -0.79999995, 0.29999843), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.2200158, zCam + -0.79999995, 0.0999984), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.2200158, zCam + -0.79999995, -0.1000016), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.2200158, zCam + -0.79999995, 0.49999931), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.2200158, zCam + -0.79999995, 0.69999933), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.2200158, zCam + -0.79999995, 0.89999938), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.2200158, zCam + -0.79999995, -0.50000179), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.2200158, zCam + -0.79999995, -0.30000177), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.32002136, zCam + -0.79999995, -1.7999986), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.32001486, zCam + -0.79999995, -1.6), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.32001486, zCam + -0.79999995, -1.2000245), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.220013, zCam + -0.79999995, -1.1999769), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.220013, zCam + -0.79999995, -1.3999758), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.220013, zCam + -0.79999995, -1.0000002), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.72001445, zCam + -0.79999989, -2.1999981), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.72001445, zCam + -0.79999989, -1.9999992), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.72001445, zCam + -0.79999989, -2.4000001), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.5200152, zCam + -0.79999989, -2.1999981), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.5200152, zCam + -0.79999989, -2.4000001), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.5200132, zCam + -0.79999989, -1.6000023), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.5200132, zCam + -0.79999989, -1.4000003), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.5200132, zCam + -0.79999989, -1.799999), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.5200132, zCam + -0.79999989, -1.0000006), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.1200151, zCam + -0.79999995, 1.4000013), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(-0.27998611, zCam + -0.79999995, 2.1991482), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(-0.27998611, zCam + -0.79999995, 2.399056), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(-0.27998707, zCam + -0.79999995, 2.0000012), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.52001315, zCam + -0.79999995, 2.0000012), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.52001411, zCam + -0.79999995, 2.2), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.52001411, zCam + -0.79999995, 2.6000309), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.22001441, zCam + -0.79999995, 1.4000028), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.22001536, zCam + -0.79999995, 1.8000025), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(-0.57998586, zCam + -0.79999995, 1.7991498), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(-0.57998681, zCam + -0.79999995, 1.4000028), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(-0.57998586, zCam + -0.79999995, 1.5991423), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.82001567, zCam + -0.79999995, -0.30000177), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.82001567, zCam + -0.79999995, -0.50000179), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.82001567, zCam + -0.79999995, 0.89999938), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.82001567, zCam + -0.79999995, 0.69999933), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.82001567, zCam + -0.79999995, 0.49999931), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.82001567, zCam + -0.79999995, -0.1000016), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.82001567, zCam + -0.79999995, 0.0999984), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.82001567, zCam + -0.79999995, 0.29999843), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(-0.79998797, zCam + -0.79578555, -0.91999823), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(-0.79998797, zCam + -0.79578555, 0.97999942), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/murO.obj", 0, locTranslateVect);

/* ----- murE.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(62);

locTranslateVect.push_back(TTransform(vector3df(4.9800134, zCam + -0.79999995, 0.2), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.9800134, zCam + -0.79999995, 0.40000001), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.9800134, zCam + -0.79999995, 0.60000008), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.9800134, zCam + -0.79999995, 0), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.9800158, zCam + -0.79999995, -0.19999923), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.9800148, zCam + -0.80000001, -0.40000001), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.9800134, zCam + -0.79999995, -0.60000002), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.5800147, zCam + -0.79999995, -0.80000001), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.5800161, zCam + -0.79999995, -1.2), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.7800157, zCam + -0.79999995, -0.60000002), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.5800157, zCam + -0.79999995, 0.79999948), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.5800166, zCam + -0.79999995, 1.4000002), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.5800166, zCam + -0.79999995, 1.2000002), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.5800166, zCam + -0.79999995, 1.0000001), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.7800124, zCam + -0.79999995, 0), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.7800124, zCam + -0.79999995, 0.2), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.7800124, zCam + -0.79999995, 0.40000001), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.7800114, zCam + -0.79999995, -0.40000135), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.4800158, zCam + -0.79999995, -0.1000016), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.4800158, zCam + -0.79999995, 0.29999843), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.480016, zCam + -0.79999995, 0.79999948), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.4800169, zCam + -0.79999995, 1.2000002), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.4800169, zCam + -0.79999995, 1.0000001), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.4800149, zCam + -0.79999995, -1.0000013), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.4800149, zCam + -0.79999995, -1.6), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.4800149, zCam + -0.79999995, -1.4000012), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.4800149, zCam + -0.79999995, -1.7999986), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.58001429, zCam + -0.79999995, -1.0000002), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.58001429, zCam + -0.79999995, -1.3999983), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.58001429, zCam + -0.79999995, -1.1999769), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.0800149, zCam + -0.79999989, -1.0000013), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.0800149, zCam + -0.79999989, -1.3999977), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.0800149, zCam + -0.79999989, -1.1999989), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.0800149, zCam + -0.79999989, -1.5999997), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.0800149, zCam + -0.79999989, -1.7999985), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.2800133, zCam + -0.79999989, -2.4000001), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.2800133, zCam + -0.79999989, -1.9999992), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.2800133, zCam + -0.79999989, -2.1999981), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.4800154, zCam + -0.79999989, -2.4000001), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.4800154, zCam + -0.79999989, -2.1999981), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.3800168, zCam + -0.79999995, 1.7991498), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.3800159, zCam + -0.79999995, 1.4000028), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.48001394, zCam + -0.79999995, 1.4000013), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.280015, zCam + -0.79999995, 2.0000012), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.2800159, zCam + -0.79999995, 2.3998737), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.2800159, zCam + -0.79999995, 2.1991482), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.2800159, zCam + -0.79999995, 2.6000333), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.48001659, zCam + -0.79999995, 2.2000101), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.48001564, zCam + -0.79999995, 2.0000012), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.18001491, zCam + -0.79999995, 1.7999998), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.18001395, zCam + -0.79999995, 1.4000028), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.3800144, zCam + -0.79999995, 0.29999843), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.3800144, zCam + -0.79999995, 0.0999984), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.3800144, zCam + -0.79999995, -0.1000016), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.3800144, zCam + -0.79999995, 0.49999931), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.3800144, zCam + -0.79999995, 0.69999933), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.3800144, zCam + -0.79999995, 0.89999938), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.3800144, zCam + -0.79999995, -0.50000179), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.3800144, zCam + -0.79999995, -0.30000177), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.7800136, zCam + -0.79999995, 0.79999948), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.4800158, zCam + -0.79999995, -0.59999931), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.4800158, zCam + -0.79999995, -0.79999936), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/murE.obj", 0, locTranslateVect);

/* ----- coinNE.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(5);

locTranslateVect.push_back(TTransform(vector3df(3.4999964, zCam + -0.79999995, 0.52018452), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.1999942, zCam + -0.79999995, -0.77981633), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.29999673, zCam + -0.79999995, -0.77981633), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.099997, zCam + -0.79999995, 1.720185), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.1999986, zCam + -0.79999995, 1.1201851), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/coinNE.obj", 0, locTranslateVect);

/* ----- coinSE.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(5);

locTranslateVect.push_back(TTransform(vector3df(3.5198274, zCam + -0.79999995, -0.099677913), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.2198237, zCam + -0.80000001, -1.3996768), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.2198291, zCam + -0.80000001, -0.49967524), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.1198311, zCam + -0.80000007, 1.4003278), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.21983807, zCam + -0.80000007, 1.4003278), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/coinSE.obj", 0, locTranslateVect);

/* ----- murLightHori.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(5);

locTranslateVect.push_back(TTransform(vector3df(1.300015, zCam + -0.79999995, 1.1799997), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(-0.39998972, zCam + -0.79999995, 1.8200017), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.2999793, zCam + -0.79999995, 1.8200017), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.4000297, zCam + -0.79999995, -0.57999974), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.4000294, zCam + -0.79999989, 0.57999903), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/murLightHori.obj", 0, locTranslateVect);

/* ----- murLightVerti.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(2);

locTranslateVect.push_back(TTransform(vector3df(1.1200151, zCam + -0.79999995, 1.6000013), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.48001394, zCam + -0.79999995, 1.6000013), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/murLightVerti.obj", 0, locTranslateVect);

/* ----- fenetre.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(10);

locTranslateVect.push_back(TTransform(vector3df(4.7004423, zCam + -0.79999995, 0.59236026), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.5923605, zCam + -0.79999995, -1.100439), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.2995629, zCam + -0.79999995, -1.3923354), vector3df(0, -180.00002, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.8995624, zCam + -0.79999995, -1.3923353), vector3df(0, -180.00002, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.3004441, zCam + -0.79999995, 1.3923599), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.7004406, zCam + -0.79999995, 1.3923608), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.8004425, zCam + -0.80000001, 2.5923598), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.000441, zCam + -0.80000001, 2.5923607), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.9995602, zCam + -0.80000001, -2.5923362), vector3df(0, -180.00002, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.199561, zCam + -0.80000001, -2.5923367), vector3df(0, -180.00002, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/fenetre.obj", 0, locTranslateVect);

/* ----- escalier.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(3);

locTranslateVect.push_back(TTransform(vector3df(2.7999821, zCam + -0.80002809, 0.59037948), vector3df(0, -179.979, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.600023, zCam + -0.80002809, -0.59037703), vector3df(0, -359.97895, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.30962446, zCam + -0.80002809, -1.0000156), vector3df(0, -449.97898, -0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/escalier.obj", 0, locTranslateVect);

/* ----- tableCarre3.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(67);

locTranslateVect.push_back(TTransform(vector3df(4.0878844, zCam + -0.75312972, 0.47745606), vector3df(0, 6.6013906, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.0874162, zCam + -0.75312972, 0.36782441), vector3df(0, -3.6778733, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.0874038, zCam + -0.75312972, 0.24551097), vector3df(0, -3.8678089, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.2603717, zCam + -0.75312972, 0.24571989), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.2604632, zCam + -0.75312972, 0.36829475), vector3df(0, 4.0662814, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.2603717, zCam + -0.75312972, 0.47771874), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.4442716, zCam + -0.75312972, 0.47770563), vector3df(0, -5.203087, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.4439397, zCam + -0.75312972, 0.3679823), vector3df(0, 5.8191312, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.4445281, zCam + -0.75312972, 0.24605665), vector3df(0, 8.0461609, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.6132731, zCam + -0.75312972, 0.24572828), vector3df(0, 5.3989239, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.627666, zCam + -0.75312972, 0.36523226), vector3df(0, -9.6949046, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.9414935, zCam + -0.75312972, 0.54097211), vector3df(0, -270.11712, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.6132555, zCam + -0.75312972, 0.13849749), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.4438715, zCam + -0.75312972, 0.13849749), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.2603717, zCam + -0.75312972, 0.13849749), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.0874743, zCam + -0.75312972, 0.13852173), vector3df(0, 0.80494841, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.0874238, zCam + -0.75312972, -0.47071314), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.2603717, zCam + -0.75312972, -0.47071314), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.4447031, zCam + -0.75312972, -0.47161949), vector3df(0, 6.1783185, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.6132555, zCam + -0.75312972, -0.47071314), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.6120796, zCam + -0.75312972, -0.13099878), vector3df(0, -22.3842, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.6132555, zCam + -0.75312972, -0.24136731), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.6449709, zCam + -0.75312972, -0.35495192), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.4438715, zCam + -0.75312972, -0.3634907), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.4184918, zCam + -0.75312972, -0.048897348), vector3df(0, 0.17990874, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.4315228, zCam + -0.75312972, -0.17292872), vector3df(0, -21.284924, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.2603717, zCam + -0.75312972, -0.13149187), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.2691426, zCam + -0.75312972, -0.29574746), vector3df(0, -14.840065, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.2692075, zCam + -0.75312972, -0.36848283), vector3df(0, 14.783113, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.0888395, zCam + -0.75312972, -0.36304489), vector3df(0, -16.073872, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.069283, zCam + -0.75312972, -0.24300115), vector3df(0, 8.2286482, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.4574742, zCam + -0.75312984, 2.1902561), vector3df(0, -25.196163, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.4790206, zCam + -0.75312531, -0.052058231), vector3df(0, -21.284924, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.3571606, zCam + -0.75312972, -0.056416851), vector3df(0, -21.284924, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.4505038, zCam + -0.70396638, -0.048506387), vector3df(0, 1.8081402, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.8367238, zCam + -0.75195807, -0.73440784), vector3df(0, 49.035219, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.470593, zCam + -0.75195807, 0.73853296), vector3df(0, 49.035219, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.086064391, zCam + -0.75312972, 2.1893213), vector3df(0, -18.212723, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.096885055, zCam + -0.75312972, 2.065321), vector3df(0, 8.6686225, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.028655162, zCam + -0.75312972, 1.9571935), vector3df(0, 62.331336, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.23519014, zCam + -0.75312972, 1.9867084), vector3df(0, 134.30354, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.28720972, zCam + -0.75312972, 2.1086676), vector3df(0, 180.90323, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.23980896, zCam + -0.75312972, 2.2217126), vector3df(0, 227.05767, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.12981062, zCam + -0.75312972, 2.2839477), vector3df(0, 256.64064, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.0038123457, zCam + -0.75312972, 2.2786098), vector3df(0, 288.16527, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.10912161, zCam + -0.75312972, 1.9297334), vector3df(0, 94.013435, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.24540904, zCam + -0.75312972, 2.3096499), vector3df(0, -25.468432, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.24540904, zCam + -0.75312972, 2.2462509), vector3df(0, 46.6952, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.19965699, zCam + -0.75312972, 2.2795846), vector3df(0, -34.500884, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.22610247, zCam + -0.70395792, 2.275878), vector3df(0, 5.8802085, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.29733431, zCam + -0.7531296, 1.6437502), vector3df(0, -180.00002, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.2974259, zCam + -0.7531296, 1.3576521), vector3df(0, -175.93373, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.31104922, zCam + -0.7531296, 1.5003883), vector3df(0, -173.75914, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.14629132, zCam + -0.7531296, 1.5023155), vector3df(0, -186.09595, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.14662018, zCam + -0.7531296, 1.3576521), vector3df(0, -175.93373, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.14789496, zCam + -0.7531296, 1.6633804), vector3df(0, -167.47121, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.010309339, zCam + -0.7531296, 1.6437502), vector3df(0, -180.00002, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.012623408, zCam + -0.7531296, 1.3571506), vector3df(0, -198.26403, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.0087118596, zCam + -0.7531296, 1.5225538), vector3df(0, -172.59746, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.15194176, zCam + -0.7531296, 1.7527217), vector3df(0, -182.36387, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.15447772, zCam + -0.7531296, 1.700083), vector3df(0, -180.00002, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.15220706, zCam + -0.7531296, 1.6483885), vector3df(0, -176.92616, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.3384062, zCam + -0.75312805, 0.44497448), vector3df(0, -172.63539, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.9165194, zCam + -0.75117493, 0.44135681), vector3df(0, -38.594151, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.85219812, zCam + -0.75117493, 0.43980759), vector3df(0, -75.436257, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.8877151, zCam + -0.75117493, 0.39051661), vector3df(0, 34.890495, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.88818878, zCam + -0.70187378, 0.41697815), vector3df(0, 87.887657, -0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/tableCarre3.obj", 0, locTranslateVect);

/* ----- chaise.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(92);

locTranslateVect.push_back(TTransform(vector3df(4.0589957, zCam + -0.74223351, 0.46370301), vector3df(0, -83.398645, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.0565848, zCam + -0.74223351, 0.3601943), vector3df(0, -93.677854, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.0565634, zCam + -0.74223351, 0.23821299), vector3df(0, -93.86785, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.2299938, zCam + -0.74223351, 0.23635818), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.2308421, zCam + -0.74223351, 0.35657269), vector3df(0, -85.933759, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.2299938, zCam + -0.74223351, 0.46737793), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.4135251, zCam + -0.74223351, 0.47012183), vector3df(0, -95.20307, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.4151344, zCam + -0.74223351, 0.35540485), vector3df(0, -84.180907, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.4162011, zCam + -0.74223351, 0.23259747), vector3df(0, -81.953821, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.5832291, zCam + -0.74223351, 0.23348543), vector3df(0, -84.601059, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.5954318, zCam + -0.74223351, 0.36100814), vector3df(0, -99.694944, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.9517708, zCam + -0.74223351, 0.50988811), vector3df(0, -360.11711, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.5821929, zCam + -0.74223351, 0.12913577), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.4139395, zCam + -0.74223351, 0.12913577), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.2299938, zCam + -0.74223351, 0.12913577), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.0573306, zCam + -0.74223351, 0.12873557), vector3df(0, -89.195031, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.8046608, zCam + -0.74223351, 0.46333829), vector3df(0, -270, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.8060322, zCam + -0.74223351, -0.46047863), vector3df(0, -273.821, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.0571456, zCam + -0.74223351, -0.48007482), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.2299938, zCam + -0.74223351, -0.48007482), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.4159527, zCam + -0.74223351, -0.48414817), vector3df(0, -83.821666, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.5821929, zCam + -0.74223351, -0.48007482), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.5794196, zCam + -0.74223351, -0.12873131), vector3df(0, -112.38418, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.5821929, zCam + -0.74223351, -0.25095943), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.6139083, zCam + -0.74223351, -0.36431366), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.4139395, zCam + -0.74223351, -0.37285244), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.9487388, zCam + -0.74223351, -0.57314783), vector3df(0, -0.59215189, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.399879, zCam + -0.74223351, -0.17169875), vector3df(0, -111.28491, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.2299938, zCam + -0.74223351, -0.14183268), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.2373214, zCam + -0.74223351, -0.29723918), vector3df(0, -104.8401, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.2422237, zCam + -0.74223351, -0.38528591), vector3df(0, -75.216925, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.0571527, zCam + -0.74223351, -0.3636573), vector3df(0, -106.07391, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.0406895, zCam + -0.74223351, -0.25682801), vector3df(0, -81.771394, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.0385742, zCam + -0.74223351, -0.11740287), vector3df(0, -115.19614, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.9639921, zCam + -0.74223351, -0.12746932), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.9893723, zCam + -0.74223351, -0.57314783), vector3df(0, -0.59215189, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.0312185, zCam + -0.74223351, -0.57314783), vector3df(0, -0.59215189, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.7308292, zCam + -0.74223351, -1.1081727), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.490993, zCam + -0.74223351, 1.3130889), vector3df(0, -195.47675, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.5108094, zCam + -0.74223351, 1.2655439), vector3df(0, -133.88351, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.35179695, zCam + -0.74223351, -1.9685071), vector3df(0, -8.1508976, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.41728503, zCam + -0.74223351, -1.8679689), vector3df(0, 119.20799, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.42466396, zCam + -0.74223351, -1.9371464), vector3df(0, 72.367951, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.34995225, zCam + -0.74223351, -1.8338412), vector3df(0, 160.59881, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.6368941, zCam + -0.74223357, -1.9171159), vector3df(0, -359.70262, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.843437, zCam + -0.74223351, -1.3697863), vector3df(0, -100.58555, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.8578339, zCam + -0.74223351, -1.3076266), vector3df(0, -122.90529, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.9436144, zCam + -0.74223351, -1.2513621), vector3df(0, -200.4899, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.9814316, zCam + -0.74223351, -1.2901016), vector3df(0, -192.82912, -0)));
locTranslateVect.push_back(TTransform(vector3df(2.032162, zCam + -0.74223351, -1.3620465), vector3df(0, -294.73217, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.9629841, zCam + -0.74223351, -1.4376808), vector3df(0, -380.27862, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.9196326, zCam + -0.74223351, -1.4238453), vector3df(0, -357.77971, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.6833887, zCam + -0.74223351, -1.261022), vector3df(0, -377.17239, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.734001, zCam + -0.74223351, -1.2565727), vector3df(0, -361.29561, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.7999225, zCam + -0.74223351, -1.1981877), vector3df(0, -288.5891, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.7888287, zCam + -0.74223351, -1.1274824), vector3df(0, -251.5492, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.7147983, zCam + -0.74223351, -1.4280547), vector3df(0, -163.79254, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.6143545, zCam + -0.74223351, -1.1544806), vector3df(0, -103.92222, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.6100057, zCam + -0.74223351, -1.2181374), vector3df(0, -81.602538, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.8095659, zCam + -0.74223351, -1.4300014), vector3df(0, -251.5492, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.8206596, zCam + -0.74223351, -1.5007067), vector3df(0, -288.5891, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.6587991, zCam + -0.74223351, -1.5609108), vector3df(0, -48.793717, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.6350917, zCam + -0.74223351, -1.5118921), vector3df(0, -71.113457, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.6672248, zCam + -0.74223351, -1.4439125), vector3df(0, -163.79254, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.7738153, zCam + -0.74223351, -1.558603), vector3df(0, -342.49273, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.7252975, zCam + -0.74223351, -1.5738968), vector3df(0, -342.49273, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.9839025, zCam + -0.74223351, -1.7397944), vector3df(-0, -276.52707, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.9287343, zCam + -0.74223351, -1.8269668), vector3df(-0, -338.51464, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.8144073, zCam + -0.74223351, -1.7497599), vector3df(0, -101.46956, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.8942271, zCam + -0.74223351, -1.6731358), vector3df(-0, -194.42784, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.7399292, zCam + -0.74223357, -2.0832803), vector3df(0, -485.32718, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.3813931, zCam + -0.74223351, 2.3984272), vector3df(0, -180.00002, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.11784635, zCam + -0.74223351, 2.189923), vector3df(0, -108.21276, 0)));
locTranslateVect.push_back(TTransform(vector3df(-0.12550505, zCam + -0.74223351, 2.0514877), vector3df(0, -81.331359, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.034470327, zCam + -0.74223351, 1.9259423), vector3df(0, -27.668705, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.26310745, zCam + -0.74223351, 1.9715073), vector3df(0, 44.303561, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.31743634, zCam + -0.74223351, 2.1185069), vector3df(0, 90.903247, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.25365123, zCam + -0.74223351, 2.2503283), vector3df(0, 137.05769, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.12772135, zCam + -0.74223351, 2.3156667), vector3df(0, 166.64065, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.014553327, zCam + -0.74223351, 2.3045552), vector3df(0, 198.1653, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.12058639, zCam + -0.74223351, 1.9000852), vector3df(0, 4.0133974, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.26695645, zCam + -0.7422334, 1.6531119), vector3df(0, -270, 0)));
locTranslateVect.push_back(TTransform(vector3df(-0.26780474, zCam + -0.7422334, 1.3693742), vector3df(0, -265.93372, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.28186908, zCam + -0.7422334, 1.5129969), vector3df(0, -263.75912, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.11509107, zCam + -0.7422334, 1.5083984), vector3df(0, -276.09592, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.11699903, zCam + -0.7422334, 1.3693742), vector3df(0, -265.93372, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.12027132, zCam + -0.7422334, 1.6791091), vector3df(0, -257.47125, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.040687203, zCam + -0.7422334, 1.6531119), vector3df(0, -270, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.044476993, zCam + -0.7422334, 1.3567392), vector3df(0, -288.26406, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.037630379, zCam + -0.7422334, 1.5357515), vector3df(0, -262.59744, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.45006087, zCam + -0.74223351, 1.2976947), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.3655533, zCam + -0.74223328, 0.45815289), vector3df(0, -262.63536, -0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/chaise.obj", 0, locTranslateVect);

/* ----- estrade.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(4);

locTranslateVect.push_back(TTransform(vector3df(4.9369569, zCam + -0.79386061, 0.30540195), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.9369569, zCam + -0.79386061, -0.29865736), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.3928509, zCam + -0.79386061, 2.5437329), vector3df(0, 0, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.54390794, zCam + -0.79386061, 1.5008789), vector3df(0, 89.999982, -0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/estrade.obj", 0, locTranslateVect);

/* ----- bureau2.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(9);

locTranslateVect.push_back(TTransform(vector3df(4.7733684, zCam + -0.75631797, 0.44503251), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.7735896, zCam + -0.75631797, -0.4766584), vector3df(0, 86.178983, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.7621672, zCam + -0.75613654, -1.1014658), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.4677439, zCam + -0.75596899, 1.2516516), vector3df(0, 141.33213, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.5691798, zCam + -0.75596899, 1.2387459), vector3df(0, 234.14063, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.618426, zCam + -0.75631803, -1.8859192), vector3df(0, 0.2974224, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.80222386, zCam + -0.75631803, -2.1130607), vector3df(0, -135.93768, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.3996989, zCam + -0.75631797, 2.3671348), vector3df(0, 180.00002, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.41876844, zCam + -0.75631797, 1.3160005), vector3df(0, 270, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/bureau2.obj", 0, locTranslateVect);

/* ----- radiateur.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(14);

locTranslateVect.push_back(TTransform(vector3df(4.091465, zCam + -0.76854181, 0.57157087), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.2152262, zCam + -0.7641654, -0.57081497), vector3df(0, -180.00002, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.6291456, zCam + -0.76543689, -0.87393862), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.4290388, zCam + -0.76716441, 1.1210614), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.7714379, zCam + -0.7641654, 0.17463064), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(2.4716985, zCam + -0.76416546, -0.036431231), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.4708027, zCam + -0.76416546, -1.5750815), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.3710722, zCam + -0.76416546, 1.6461607), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(2.3573239, zCam + -0.76416546, 1.1713092), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.8064803, zCam + -0.76416546, -1.9713445), vector3df(0, -180.00002, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.52882797, zCam + -0.7641654, 2.4749215), vector3df(0, -270, 0)));
locTranslateVect.push_back(TTransform(vector3df(-0.26995587, zCam + -0.7650131, 2.0762708), vector3df(0, -270, 0)));
locTranslateVect.push_back(TTransform(vector3df(-0.21580669, zCam + -0.7650131, 1.2294997), vector3df(0, -180.00002, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.3713065, zCam + -0.76777482, -0.23247251), vector3df(0, -89.999982, -0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/radiateur.obj", 0, locTranslateVect);

/* ----- ArmoireSsFond.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(20);

locTranslateVect.push_back(TTransform(vector3df(3.8345921, zCam + -0.77737325, 0.055307798), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.8357992, zCam + -0.77721876, -0.55408764), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.9063854, zCam + -0.77721876, 1.3650553), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.9856319, zCam + -0.77721876, 1.1607258), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.9100449, zCam + -0.77721876, 0.83439326), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.0145001, zCam + -0.77721876, 1.1607258), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.1169339, zCam + -0.77561682, -2.1943469), vector3df(0, -180.00002, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.1169339, zCam + -0.77561682, -2.1654787), vector3df(0, -180.00002, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.89529145, zCam + -0.77561682, -2.0306938), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.92415965, zCam + -0.77561682, -2.0306938), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.3717885, zCam + -0.77686465, -2.0306938), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.3429203, zCam + -0.77686465, -2.0306938), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.3429203, zCam + -0.77686465, -2.2196431), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.3717885, zCam + -0.77686465, -2.2196431), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.73464364, zCam + -0.77561682, -2.2127488), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.73455453, zCam + -0.77561682, -2.401731), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.1287354, zCam + -0.77685624, -2.3544321), vector3df(0, -180.00002, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.1287354, zCam + -0.77685624, -2.3833003), vector3df(0, -180.00002, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.3176574, zCam + -0.77686465, -2.354182), vector3df(0, -180.00002, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.3176584, zCam + -0.77686465, -2.3833022), vector3df(0, -180.00002, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/ArmoireSsFond.obj", 0, locTranslateVect);

/* ----- table.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(13);

locTranslateVect.push_back(TTransform(vector3df(3.8515279, zCam + -0.72656256, 0.30360642), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.7043879, zCam + -0.72604626, -1.1488675), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.7043879, zCam + -0.72604626, -1.2101573), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.9432225, zCam + -0.72604626, -1.3849726), vector3df(0, -12.847032, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.9568502, zCam + -0.72604626, -1.325217), vector3df(0, -12.847032, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.7149, zCam + -0.72604626, -1.4703395), vector3df(0, 15.716347, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.7315018, zCam + -0.72604626, -1.529338), vector3df(0, 15.716347, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.8980366, zCam + -0.72604626, -1.7814056), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.8980366, zCam + -0.72604626, -1.7201158), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.5509372, zCam + -0.72604626, -2.5168648), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.089591451, zCam + -0.72590488, 2.0917675), vector3df(0, -40.324597, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.1046183, zCam + -0.7260074, -0.38184837), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.1046183, zCam + -0.7260074, -0.51079434), vector3df(0, -89.999982, -0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/table.obj", 0, locTranslateVect);

/* ----- meubleBasRepet.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(35);

locTranslateVect.push_back(TTransform(vector3df(4.1907625, zCam + -0.77213418, 0.045157108), vector3df(0, -180.00002, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.2659626, zCam + -0.77213418, 0.045157108), vector3df(0, -180.00002, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.4163642, zCam + -0.77240115, 0.045157108), vector3df(0, -180.00002, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.3411641, zCam + -0.77240115, 0.045157108), vector3df(0, -180.00002, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.6419654, zCam + -0.77224368, 0.045157108), vector3df(0, -180.00002, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.7171655, zCam + -0.77224648, 0.045157108), vector3df(0, -180.00002, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.5667639, zCam + -0.77224368, 0.045157108), vector3df(0, -180.00002, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.4915638, zCam + -0.77240115, 0.045157108), vector3df(0, -180.00002, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.5429821, zCam + -0.77224368, 0.84538984), vector3df(0, -180.00002, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.467782, zCam + -0.77240115, 0.84538984), vector3df(0, -180.00002, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.6238616, zCam + -0.77263647, -2.0451336), vector3df(0, -359.99998, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.6990805, zCam + -0.77263647, -2.0451336), vector3df(0, -359.99998, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.7742853, zCam + -0.77263647, -2.0451336), vector3df(0, -359.99998, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.8494867, zCam + -0.77263647, -2.0451336), vector3df(0, -359.99998, -0)));
locTranslateVect.push_back(TTransform(vector3df(2.2547004, zCam + -0.77190799, 2.2737), vector3df(-0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(2.2547004, zCam + -0.77190799, 2.3489001), vector3df(-0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(2.2547004, zCam + -0.77190799, 2.4993019), vector3df(-0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(2.2547004, zCam + -0.77190799, 2.4241016), vector3df(-0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(2.2547004, zCam + -0.77190799, 2.1985004), vector3df(-0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(2.2547004, zCam + -0.77190799, 1.8977027), vector3df(-0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(2.2547004, zCam + -0.77190799, 2.1233039), vector3df(-0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(2.2547004, zCam + -0.77190799, 2.0481024), vector3df(-0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(2.2547004, zCam + -0.77190799, 1.9729023), vector3df(-0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.45485604, zCam + -0.77247876, 1.9564614), vector3df(-0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.45485604, zCam + -0.77247876, 2.0316615), vector3df(-0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.45485604, zCam + -0.77247876, 2.106863), vector3df(-0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.45485604, zCam + -0.77247876, 1.8812618), vector3df(-0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.39269769, zCam + -0.77206969, 1.7548625), vector3df(-0, 0, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.54309744, zCam + -0.77206969, 1.7548625), vector3df(-0, 0, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.4678973, zCam + -0.77206969, 1.7548625), vector3df(-0, 0, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.31749627, zCam + -0.77144843, 1.7548625), vector3df(-0, 0, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.3548665, zCam + -0.77247864, 0.58931172), vector3df(-0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.3548665, zCam + -0.77247864, 0.81491292), vector3df(-0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.3548665, zCam + -0.77247864, 0.7397114), vector3df(-0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.3548665, zCam + -0.77247864, 0.66451132), vector3df(-0, -89.999982, -0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/meubleBasRepet.obj", 0, locTranslateVect);

/* ----- casier.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(27);

locTranslateVect.push_back(TTransform(vector3df(0.96479684, zCam + -0.72004002, 1.5506226), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.63393122, zCam + -0.72004002, 1.5506226), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.7993632, zCam + -0.72004002, 1.5506226), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(-0.48045993, zCam + -0.72004002, 0.95063072), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(-0.14959478, zCam + -0.72004002, 0.95063072), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(-0.31502676, zCam + -0.72004002, 0.95063072), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.015838867, zCam + -0.72004002, 0.95063072), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.18127084, zCam + -0.72004002, 0.95063072), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.2754138, zCam + -0.72004002, -0.94936866), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.1099818, zCam + -0.72004002, -0.94936866), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.7791162, zCam + -0.72004002, -0.94936866), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.9445481, zCam + -0.72004002, -0.94936866), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.613683, zCam + -0.72004002, -0.94936866), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.7518268, zCam + -0.72003996, -0.35063258), vector3df(0, -180.00002, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.5863945, zCam + -0.72003996, -0.35063258), vector3df(0, -180.00002, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.0826907, zCam + -0.72003996, -0.35063258), vector3df(0, -180.00002, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.9172587, zCam + -0.72003996, -0.35063258), vector3df(0, -180.00002, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.2481229, zCam + -0.72003996, -0.35063258), vector3df(0, -180.00002, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.4135549, zCam + -0.72003996, -0.35063258), vector3df(0, -180.00002, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.8506317, zCam + -0.72003996, -0.13271356), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(2.7592785, zCam + -0.72003996, 0.35063282), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.5938451, zCam + -0.72003996, 0.35063282), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.0901437, zCam + -0.72003996, 0.35063282), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.9247117, zCam + -0.72003996, 0.35063282), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.2555771, zCam + -0.72003996, 0.35063282), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.4210091, zCam + -0.72003996, 0.35063282), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.5113955, zCam + -0.72003996, 0.65048671), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/casier.obj", 0, locTranslateVect);

/* ----- boiteVide.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(16);

locTranslateVect.push_back(TTransform(vector3df(4.3464718, zCam + -0.74002725, 0.042986002), vector3df(0, 23.095986, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.8364813, zCam + -0.73723233, 0.26355004), vector3df(0, 94.066834, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.7718797, zCam + -0.7452414, 0.40435401), vector3df(0, 106.53767, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.8352423, zCam + -0.69236523, 0.1453485), vector3df(0, 78.896348, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.7690444, zCam + -0.74528366, -0.53093207), vector3df(0, -3.8210554, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.8402708, zCam + -0.66513962, -0.48591244), vector3df(0, 112.89452, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.5639663, zCam + -0.74528372, -1.8852835), vector3df(0, -89.702616, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.84383094, zCam + -0.74528372, -2.0779169), vector3df(0, -225.93766, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.4403774, zCam + -0.7452414, 2.3656461), vector3df(0, 196.5377, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.41624284, zCam + -0.7452414, 1.3070066), vector3df(0, 257.58154, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.984924, zCam + -0.73876226, -1.3283519), vector3df(0, 23.095986, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.6483462, zCam + -0.73923665, -2.0426013), vector3df(0, -14.90544, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.2450441, zCam + -0.69183898, -2.3897939), vector3df(0, -14.90544, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.9256347, zCam + -0.73759073, 1.9531997), vector3df(0, 94.066834, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.7233298, zCam + -0.7375946, 2.4425514), vector3df(0, 153.96481, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.8577196, zCam + -0.7375946, 2.2013643), vector3df(0, 153.96481, -0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/boiteVide.obj", 0, locTranslateVect);

/* ----- bouteille.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(17);

locTranslateVect.push_back(TTransform(vector3df(3.8342752, zCam + -0.7179395, 0.085919715), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.8342752, zCam + -0.65961832, 0.20644829), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.7853928, zCam + -0.7407679, -0.51061201), vector3df(0, -3.8210554, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.8429337, zCam + -0.74086195, -0.4187943), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.6527376, zCam + -0.77240217, -1.3274484), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.5854079, zCam + -0.74076796, -1.9001302), vector3df(0, -89.702616, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.81790161, zCam + -0.74076796, -2.0807133), vector3df(0, -225.93766, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.73558223, zCam + -0.71607661, -2.492276), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.73238373, zCam + -0.68621302, -2.2466557), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.72982496, zCam + -0.62780577, -2.4524164), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.0090165, zCam + -0.68621302, -2.3843288), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.0926497, zCam + -0.68621302, -2.1939025), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.3435493, zCam + -0.68621302, -2.0549428), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.92538339, zCam + -0.68621302, -2.0729561), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.5359574, zCam + -0.65803164, 2.1332216), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.5359574, zCam + -0.7117815, 2.0829704), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.5359574, zCam + -0.7117815, 1.9214027), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/bouteille.obj", 0, locTranslateVect);

/* ----- livreGroupeCube.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(17);

locTranslateVect.push_back(TTransform(vector3df(3.8413751, zCam + -0.71594012, 0.19530779), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.8413751, zCam + -0.71594012, 0.12807408), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.8413751, zCam + -0.65793985, 0.087130472), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.8413751, zCam + -0.74318302, 0.19524188), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.8413751, zCam + -0.71714687, -0.52031666), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.8413751, zCam + -0.71714687, -0.45316255), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.8413751, zCam + -0.6872949, -0.45454171), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.8413751, zCam + -0.6872949, -0.52186882), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.74436492, zCam + -0.68457633, -2.5223601), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.74436492, zCam + -0.68457633, -2.4550328), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.74436492, zCam + -0.65609115, -2.2383335), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.74436492, zCam + -0.65609115, -2.3056607), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.74436492, zCam + -0.74196041, -2.3529985), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.74436492, zCam + -0.74196041, -2.2856712), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.5415777, zCam + -0.65609109, 1.9715528), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.54286259, zCam + -0.65609109, 2.1798415), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.540748, zCam + -0.74284029, 1.8655576), vector3df(0, 89.999982, -0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/livreGroupeCube.obj", 0, locTranslateVect);

/* ----- cylindre.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(11);

locTranslateVect.push_back(TTransform(vector3df(3.8267484, zCam + -0.65962988, 0.12405657), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.8331556, zCam + -0.68773764, 0.18458198), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.8362515, zCam + -0.68773764, 0.19924691), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.8238678, zCam + -0.68773764, 0.20934942), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.8238678, zCam + -0.68773764, 0.10130128), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.8362515, zCam + -0.68773764, 0.091198765), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.8331556, zCam + -0.68773764, 0.076533832), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.8428998, zCam + -0.6639486, -0.4942404), vector3df(89.187811, 74.382584, -1.6842667)));
locTranslateVect.push_back(TTransform(vector3df(3.8362515, zCam + -0.660604, -0.4035396), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.8331556, zCam + -0.660604, -0.44728702), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.8361881, zCam + -0.660604, -0.53806674), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/cylindre.obj", 0, locTranslateVect);

/* ----- porteLivre.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(8);

locTranslateVect.push_back(TTransform(vector3df(4.6457758, zCam + -0.73633951, 0.040522598), vector3df(0, -138.33711, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.2356143, zCam + -0.73627341, 0.040522598), vector3df(0, -204.20846, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.7645772, zCam + -0.74205732, -1.0392158), vector3df(0, -28.71418, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.1934054, zCam + -0.71796656, -2.3701134), vector3df(0, 22.932521, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.3594023, zCam + -0.71853817, -2.1192138), vector3df(0, 84.548289, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.3542557, zCam + -0.74522334, -2.2916269), vector3df(0, -43.751286, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.0052552, zCam + -0.74411082, -2.175827), vector3df(0, -43.751286, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.9264881, zCam + -0.71685404, -2.1205006), vector3df(0, -109.40245, -0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/porteLivre.obj", 0, locTranslateVect);

/* ----- armoirePharmacie.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(2);

locTranslateVect.push_back(TTransform(vector3df(3.8612936, zCam + -0.74410802, -0.71536863), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.86068898, zCam + -0.74533987, 0.57682586), vector3df(0, -89.999982, -0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/armoirePharmacie.obj", 0, locTranslateVect);

/* ----- boiteALettre.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(4.7687135, zCam + -0.73853672, -0.02888516), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/boiteALettre.obj", 0, locTranslateVect);

/* ----- caisse.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(67);

locTranslateVect.push_back(TTransform(vector3df(3.8390303, zCam + -0.62326348, -0.41287231), vector3df(0, -35.63213, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.851687, zCam + -0.61994678, -0.10156345), vector3df(0, 77.611658, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.8464134, zCam + -0.61994678, -0.13795131), vector3df(0, 134.66256, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.8402052, zCam + -0.78410488, -0.64399314), vector3df(0, -38.717737, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.8073211, zCam + -0.78410488, -0.63998288), vector3df(0, -108.69267, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.8233619, zCam + -0.78410488, -0.67366916), vector3df(0, -150.22942, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.8229032, zCam + -0.75673002, -0.6516574), vector3df(0, -180.19494, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.6428289, zCam + -0.69215608, -1.3291668), vector3df(0, -224.87854, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.9183056, zCam + -0.75673002, 0.74150795), vector3df(0, -228.0706, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.9187644, zCam + -0.78410488, 0.71949619), vector3df(0, -150.22942, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.9027236, zCam + -0.78410488, 0.75318247), vector3df(0, -108.69267, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.9356077, zCam + -0.78410488, 0.74917221), vector3df(0, -38.717737, -0)));
locTranslateVect.push_back(TTransform(vector3df(2.4077222, zCam + -0.78148293, -0.95690572), vector3df(0, -17.195838, -0)));
locTranslateVect.push_back(TTransform(vector3df(2.4453235, zCam + -0.78148293, -0.95872515), vector3df(0, 58.174067, -0)));
locTranslateVect.push_back(TTransform(vector3df(2.4296138, zCam + -0.78148293, -0.93741846), vector3df(0, 40.422859, -0)));
locTranslateVect.push_back(TTransform(vector3df(2.4426959, zCam + -0.7539776, -0.93793571), vector3df(0, 96.660332, -0)));
locTranslateVect.push_back(TTransform(vector3df(2.411664, zCam + -0.75380522, -0.9474175), vector3df(0, -0.74410028, -0)));
locTranslateVect.push_back(TTransform(vector3df(2.4269326, zCam + -0.72656643, -0.94445997), vector3df(0, -8.5078501, -0)));
locTranslateVect.push_back(TTransform(vector3df(2.4573698, zCam + -0.78148293, -0.92741948), vector3df(0, 75.537152, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.7717759, zCam + -0.78148293, -0.89307654), vector3df(0, 144.25995, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.76377779, zCam + -0.72656643, -0.91707534), vector3df(0, 60.215002, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.76554757, zCam + -0.75380522, -0.9368062), vector3df(0, 30.423886, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.75939089, zCam + -0.7539776, -0.89685482), vector3df(0, 165.38318, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.77253056, zCam + -0.78148293, -0.92256898), vector3df(0, 109.14565, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.74697554, zCam + -0.78148293, -0.91566193), vector3df(0, 126.89686, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.76495254, zCam + -0.78148293, -0.95478624), vector3df(0, 51.526954, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.77379966, zCam + -0.78148293, -0.81584734), vector3df(0, -99.141692, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.77033281, zCam + -0.78148293, -0.85333264), vector3df(0, -23.771847, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.75143743, zCam + -0.78148293, -0.83479267), vector3df(0, -41.522998, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.75011659, zCam + -0.7539776, -0.84781814), vector3df(0, 14.714473, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.76385272, zCam + -0.75380522, -0.81842083), vector3df(0, -82.690013, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.75878513, zCam + -0.72656643, -0.83312446), vector3df(0, -90.453705, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.74239445, zCam + -0.78148293, -0.87458551), vector3df(0, -6.4087622, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.74179357, zCam + -0.78148293, -0.79572505), vector3df(0, -60.327646, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.74552667, zCam + -0.72656643, -0.77021044), vector3df(0, -144.37265, 0)));
locTranslateVect.push_back(TTransform(vector3df(-0.74453837, zCam + -0.75380522, -0.74743557), vector3df(0, -136.60895, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.75608796, zCam + -0.7539776, -0.7870146), vector3df(0, -13.774937, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.72356242, zCam + -0.78148293, -0.76763862), vector3df(0, -95.441935, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.77446043, zCam + -0.78148293, -0.77172428), vector3df(0, -77.690786, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.74304289, zCam + -0.78148293, -0.74473679), vector3df(0, -153.06063, 0)));
locTranslateVect.push_back(TTransform(vector3df(-0.20019898, zCam + -0.78534698, 2.3415389), vector3df(0, 14.714473, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.24255401, zCam + -0.78543937, 2.3609877), vector3df(0, -39.372629, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.88245291, zCam + -0.78147888, -0.058612097), vector3df(0, -1.427066, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.8589862, zCam + -0.7265625, -0.032802902), vector3df(0, -85.472065, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.85266095, zCam + -0.75379944, -0.018594913), vector3df(0, -77.708319, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.86889786, zCam + -0.75398254, -0.046688337), vector3df(0, 19.696112, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.86645097, zCam + -0.78147888, -0.033826772), vector3df(0, -36.541358, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.84923679, zCam + -0.78147888, -0.053937491), vector3df(0, -18.790151, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.84252805, zCam + -0.78147888, -0.016894884), vector3df(0, -94.160059, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.2899888, zCam + -0.78147888, -0.0072190762), vector3df(0, -94.160059, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.2966976, zCam + -0.78147888, -0.044261694), vector3df(0, -18.790151, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.3139117, zCam + -0.78147888, -0.024150968), vector3df(0, -36.541358, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.3163586, zCam + -0.75398254, -0.037012547), vector3df(0, 19.696112, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.3001218, zCam + -0.75379944, -0.0089191198), vector3df(0, -77.708319, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.306447, zCam + -0.7265625, -0.023127109), vector3df(0, -85.472065, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.3299136, zCam + -0.78147888, -0.048936307), vector3df(0, -1.427066, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.89464229, zCam + -0.7338469, 0.42147383), vector3df(0, -85.472065, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.86208969, zCam + -0.73384094, 0.41810015), vector3df(0, -157.58958, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.74102634, zCam + -0.62010324, -2.5019493), vector3df(0, -198.08498, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.74166602, zCam + -0.62010324, -2.3675568), vector3df(0, -284.98503, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.0071177, zCam + -0.62010324, -2.37096), vector3df(0, -246.70438, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.106847, zCam + -0.62010324, -2.3726616), vector3df(0, -296.6458, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.247859, zCam + -0.62010324, -2.37096), vector3df(0, -242.06882, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.92033547, zCam + -0.62010324, -2.1752744), vector3df(0, -242.06882, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.53735358, zCam + -0.70422643, 2.054219), vector3df(0, -264.27914, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.53933096, zCam + -0.70422643, 1.9585638), vector3df(0, -198.53446, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.5367313, zCam + -0.70422643, 2.1596999), vector3df(0, -181.99494, -0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/caisse.obj", 0, locTranslateVect);

/* ----- livreUnique.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(5);

locTranslateVect.push_back(TTransform(vector3df(3.8335359, zCam + -0.7162652, -0.41166556), vector3df(-0, 89.999982, -39.295164)));
locTranslateVect.push_back(TTransform(vector3df(3.8335359, zCam + -0.68617004, -0.41166556), vector3df(-0, 89.999982, -39.295164)));
locTranslateVect.push_back(TTransform(vector3df(3.6601934, zCam + -0.73337936, -1.3245348), vector3df(-0, 89.999982, -39.295164)));
locTranslateVect.push_back(TTransform(vector3df(0.73808026, zCam + -0.71198797, -2.5484102), vector3df(-0, 89.999982, -39.295164)));
locTranslateVect.push_back(TTransform(vector3df(0.73808026, zCam + -0.68284708, -2.3599758), vector3df(-0, 89.999982, -39.295164)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/livreUnique.obj", 0, locTranslateVect);

/* ----- canapee.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(7);

locTranslateVect.push_back(TTransform(vector3df(4.9235358, zCam + -0.78211278, -0.75852203), vector3df(0, -65.145361, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.9432824, zCam + -0.78202552, -2.3172936), vector3df(0, 89.999982, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.8550738, zCam + -0.78202552, -2.4353867), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.8550738, zCam + -0.78202552, -2.2896514), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.9432824, zCam + -0.78202552, -2.1715584), vector3df(0, 89.999982, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.86421031, zCam + -0.78205127, -0.30891633), vector3df(0, 89.999982, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.3358476, zCam + -0.78113973, -0.42744875), vector3df(0, -89.999982, -0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/canapee.obj", 0, locTranslateVect);

/* ----- corbeille.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(16);

locTranslateVect.push_back(TTransform(vector3df(4.8200893, zCam + -0.79361922, -0.036924932), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.8408644, zCam + -0.79361922, -0.22405854), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.8424776, zCam + -0.79361922, 0.40187111), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.4181657, zCam + -0.79361922, -0.83194965), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.760679, zCam + -0.79361922, -0.99418658), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.4006519, zCam + -0.79361922, 0.84066713), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.5280962, zCam + -0.79361922, 1.2584913), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.5633903, zCam + -0.79361922, 1.3101144), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.5418403, zCam + -0.79361922, -1.1574457), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.7236515, zCam + -0.79361922, -1.8809801), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.15941419, zCam + -0.79361922, 1.5961969), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.46169412, zCam + -0.79361922, 2.2014277), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.2939689, zCam + -0.79361922, 2.3640361), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.53792769, zCam + -0.79361922, 2.3861544), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.1882007, zCam + -0.62937653, -2.3692904), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.125771, zCam + -0.79338366, -2.0529265), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/corbeille.obj", 0, locTranslateVect);

/* ----- pupitre.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(16);

locTranslateVect.push_back(TTransform(vector3df(3.9418173, zCam + -0.7526412, -1.2872413), vector3df(0, -108.08832, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.9343965, zCam + -0.7526412, -1.0916167), vector3df(0, -79.479271, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.9566588, zCam + -0.7526412, -0.88568914), vector3df(0, -77.887994, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.1162066, zCam + -0.7526412, -0.87641311), vector3df(0, -82.806666, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.1087856, zCam + -0.7526412, -1.0860511), vector3df(0, -84.977491, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.110641, zCam + -0.7526412, -1.2872413), vector3df(0, -87.772835, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.2924509, zCam + -0.75250429, -1.2872413), vector3df(0, -92.208503, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.3110032, zCam + -0.75250429, -1.0879064), vector3df(0, -85.739925, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.2980165, zCam + -0.75250429, -0.87641311), vector3df(0, -93.191811, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.532433, zCam + -0.75261378, -1.3041095), vector3df(0, -270, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.7830617, zCam + -0.75285757, 1.2845317), vector3df(0, -89.507751, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.2022872, zCam + -0.75285757, 1.2720549), vector3df(0, 93.753253, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.7048209, zCam + -0.75285757, 1.0934328), vector3df(0, 226.78643, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.5334299, zCam + -0.75285757, 0.99436527), vector3df(0, 194.09209, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.3083076, zCam + -0.75285757, 1.0981814), vector3df(0, 136.1209, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.5059958, zCam + -0.75285757, 1.025914), vector3df(0, 178.83651, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/pupitre.obj", 0, locTranslateVect);

/* ----- meubleLivre.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(3);

locTranslateVect.push_back(TTransform(vector3df(3.6498957, zCam + -0.75328016, -1.3236117), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(2.0498884, zCam + -0.74039721, -1.1658218), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.24980783, zCam + -0.75339574, 1.8810576), vector3df(0, 89.999982, -0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/meubleLivre.obj", 0, locTranslateVect);

/* ----- duoLivre.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(5);

locTranslateVect.push_back(TTransform(vector3df(3.6616356, zCam + -0.73416615, -1.3054088), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.6547673, zCam + -0.73416615, -1.3421694), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.6580083, zCam + -0.76675528, -1.3421694), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.73265409, zCam + -0.71277475, -2.5660448), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.73265409, zCam + -0.68363386, -2.3776104), vector3df(0, 89.999982, -0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/duoLivre.obj", 0, locTranslateVect);

/* ----- meubleAPied.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(4);

locTranslateVect.push_back(TTransform(vector3df(3.4457734, zCam + -0.76271439, 0.84956419), vector3df(0, -89.999982, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.7018222, zCam + -0.76308954, -2.3074214), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.3534985, zCam + -0.76323217, -0.5317151), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.84406346, zCam + -0.76294714, -0.5317151), vector3df(0, -89.999982, -0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/meubleAPied.obj", 0, locTranslateVect);

/* ----- chauffeEau.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(3);

locTranslateVect.push_back(TTransform(vector3df(4.5316229, zCam + -0.73456556, 0.6968509), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.861064, zCam + -0.73456556, 0.6968509), vector3df(0, -15.428264, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.85563278, zCam + -0.73456556, -0.15573588), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/chauffeEau.obj", 0, locTranslateVect);

/* ----- extincteur.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(7);

locTranslateVect.push_back(TTransform(vector3df(3.7718627, zCam + -0.76941156, -0.11823083), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(2.4713459, zCam + -0.76941162, 1.0918894), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.471756, zCam + -0.76941174, -1.7079756), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.3507576, zCam + -0.76941174, -0.13008553), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.82867, zCam + -0.76941174, -0.64005309), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(2.2708423, zCam + -0.76941162, 1.8410872), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.4432421, zCam + -0.76941156, 1.8295554), vector3df(0, -180.00002, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/extincteur.obj", 0, locTranslateVect);

/* ----- armoireAvecFond.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(8);

locTranslateVect.push_back(TTransform(vector3df(2.0653174, zCam + -0.77676445, -1.4929875), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.8558993, zCam + -0.77676445, -1.0348847), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.2651227, zCam + -0.77603626, -2.0526409), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(2.2651227, zCam + -0.77603626, -2.297992), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.5347178, zCam + -0.77643669, 1.8315365), vector3df(0, -270, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.5347178, zCam + -0.77643669, 2.0397055), vector3df(0, -270, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.3654001, zCam + -0.77587873, 0.14887878), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.3654001, zCam + -0.77587873, 0.40501383), vector3df(0, -89.999982, -0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/armoireAvecFond.obj", 0, locTranslateVect);

/* ----- tabouret.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(48);

locTranslateVect.push_back(TTransform(vector3df(1.9952277, zCam + -0.77396911, 2.1336365), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.9323111, zCam + -0.77396911, 2.136863), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.9984542, zCam + -0.77396911, 2.3869166), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.9339244, zCam + -0.77396911, 2.382077), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.937151, zCam + -0.77396911, 2.2352712), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.9936144, zCam + -0.77396911, 2.2320447), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.9355376, zCam + -0.77396911, 2.01103), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.9984542, zCam + -0.77396911, 2.0078034), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.9936144, zCam + -0.77396911, 1.9045556), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.9306979, zCam + -0.77396911, 1.9077818), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.9968408, zCam + -0.77396911, 2.4724185), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.9403775, zCam + -0.77396911, 2.4756453), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.6575754, zCam + -0.77396911, 2.4756453), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.7140388, zCam + -0.77396911, 2.4724185), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.6478958, zCam + -0.77396911, 1.9077818), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.7108123, zCam + -0.77396911, 1.9045556), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.7156522, zCam + -0.77396911, 2.0078034), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.6527355, zCam + -0.77396911, 2.01103), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.7108123, zCam + -0.77396911, 2.2320447), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.6543489, zCam + -0.77396911, 2.2352712), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.6511223, zCam + -0.77396911, 2.382077), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.7156522, zCam + -0.77396911, 2.3869166), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.649509, zCam + -0.77396911, 2.136863), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.7124257, zCam + -0.77396911, 2.1336365), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.1155243, zCam + -0.77379823, 2.1336365), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.0526075, zCam + -0.77398437, 2.136863), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.1187508, zCam + -0.77379823, 2.3869166), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.0542209, zCam + -0.77398437, 2.382077), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.0574474, zCam + -0.77398437, 2.2352712), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.1139109, zCam + -0.77379823, 2.2320447), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.0558341, zCam + -0.77398437, 2.01103), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.1187508, zCam + -0.77379823, 2.0078034), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.1139109, zCam + -0.77379823, 1.9045556), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.0509944, zCam + -0.77398437, 1.9077818), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.1171374, zCam + -0.77379823, 2.4724185), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.060674, zCam + -0.77398437, 2.4756453), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.80682945, zCam + -0.77398437, 2.4756453), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.86329293, zCam + -0.77398437, 2.4724185), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.7971499, zCam + -0.77398437, 1.9077818), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.86006641, zCam + -0.77398437, 1.9045556), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.86490631, zCam + -0.77398437, 2.0078034), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.80198956, zCam + -0.77398437, 2.01103), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.86006641, zCam + -0.77398437, 2.2320447), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.80360293, zCam + -0.77398437, 2.2352712), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.80037642, zCam + -0.77398437, 2.382077), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.86490631, zCam + -0.77398437, 2.3869166), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.79876304, zCam + -0.77398437, 2.136863), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.86167979, zCam + -0.77398437, 2.1336365), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/tabouret.obj", 0, locTranslateVect);

/* ----- tableChimie.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(12);

locTranslateVect.push_back(TTransform(vector3df(1.9598677, zCam + -0.76476258, 2.1889522), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.9647074, zCam + -0.76476258, 2.4357793), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.9598677, zCam + -0.76476258, 1.9598713), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.6770656, zCam + -0.76476258, 1.9598713), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.6819053, zCam + -0.76476258, 2.4357793), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.6770656, zCam + -0.76476258, 2.1889522), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.0801642, zCam + -0.76477784, 2.1889522), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.0850039, zCam + -0.76477784, 2.4357793), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.0801642, zCam + -0.76477784, 1.9598713), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.82631969, zCam + -0.76477784, 1.9598713), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.83115935, zCam + -0.76477784, 2.4357793), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.82631969, zCam + -0.76477784, 2.1889522), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/tableChimie.obj", 0, locTranslateVect);

/* ----- sol2.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(4.4003525, zCam + -0.80075222, 0.29857448), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/sol2.obj", 0, locTranslateVect);

/* ----- sol3.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(4.4003525, zCam + -0.80075222, -0.30142274), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/sol3.obj", 0, locTranslateVect);

/* ----- sol4.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(4.4003525, zCam + -0.80034959, -0.70000142), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/sol4.obj", 0, locTranslateVect);

/* ----- sol5.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(4.1009588, zCam + -0.80079514, -1.0013596), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/sol5.obj", 0, locTranslateVect);

/* ----- sol1.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(4.0015616, zCam + -0.80035549, 0.99830925), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/sol1.obj", 0, locTranslateVect);

/* ----- sol11.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(1.7997842, zCam + -0.80063426, -1.5001181), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/sol11.obj", 0, locTranslateVect);

/* ----- sol12.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(1.9001507, zCam + -0.80063426, -2.3006132), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/sol12.obj", 0, locTranslateVect);

/* ----- sol13.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(1.0998522, zCam + -0.80029976, -2.3006132), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/sol13.obj", 0, locTranslateVect);

/* ----- sol9.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(-0.200286, zCam + -0.80038601, 1.5006802), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/sol9.obj", 0, locTranslateVect);

/* ----- sol8.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(0.099847525, zCam + -0.80038595, 2.1021392), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/sol8.obj", 0, locTranslateVect);

/* ----- sol7.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(1.4027901, zCam + -0.79993987, 2.1977887), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/sol7.obj", 0, locTranslateVect);

/* ----- sol10.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(1.0981194, zCam + -0.80029976, 0.099999547), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/sol10.obj", 0, locTranslateVect);

/* ----- sol6.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(1.4978204, zCam + -0.80098772, -0.073148221), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/sol6.obj", 0, locTranslateVect);

/* ----- n75.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(5.0544615, zCam + -0.59999782, 0), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n75.obj", 0, locTranslateVect);

/* ----- n67.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(4.2499723, zCam + -0.59997553, -1.0999981), vector3df(0, -89.999982, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n67.obj", 0, locTranslateVect);

/* ----- n83.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(3.3525653, zCam + -0.59999782, -0.59999877), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n83.obj", 0, locTranslateVect);

/* ----- n20.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(1.7995272, zCam + -0.59999084, 1.8000038), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n20.obj", 0, locTranslateVect);

/* ----- n6.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(0.49999207, zCam + -0.59999084, 2.4261303), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n6.obj", 0, locTranslateVect);

/* ----- n81.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(3.5019021, zCam + -0.59997559, 0.34884849), vector3df(0, -539.7581, -0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n81.obj", 0, locTranslateVect);

/* ----- n84.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(4.5066695, zCam + -0.59999084, 0.8000015), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n84.obj", 0, locTranslateVect);

/* ----- n79.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(3.9998903, zCam + -0.59999782, 0.8000015), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n79.obj", 0, locTranslateVect);

/* ----- n42.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(-0.14997031, zCam + -0.59997559, -0.70000094), vector3df(0, 89.999982, -0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n42.obj", 0, locTranslateVect);

/* ----- n16.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(0.20000333, zCam + -0.59997559, 1.3500036), vector3df(0, -180.00002, -0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n16.obj", 0, locTranslateVect);

/* ----- n19.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(1.1000023, zCam + -0.59997571, 1.3499919), vector3df(0, -180.00002, -0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n19.obj", 0, locTranslateVect);

/* ----- n12.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(0.49760851, zCam + -0.59997541, 1.651492), vector3df(0, -359.70822, -0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n12.obj", 0, locTranslateVect);

/* ----- n35.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(2.4999986, zCam + -0.60000181, 0.75000829), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n35.obj", 0, locTranslateVect);

/* ----- n24.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(2.2000022, zCam + -0.59997565, 0.74989164), vector3df(0, -180.00002, -0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n24.obj", 0, locTranslateVect);

/* ----- n56.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(1.2000327, zCam + -0.59997547, -1.4499301), vector3df(0, -180.00002, -0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n56.obj", 0, locTranslateVect);

/* ----- n60.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(2.2000008, zCam + -0.59997553, -1.0499685), vector3df(0, -180.00002, -0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n60.obj", 0, locTranslateVect);

/* ----- n59.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(2.5500004, zCam + -0.59999084, -0.79108298), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n59.obj", 0, locTranslateVect);

/* ----- n44.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(0.30000177, zCam + -0.59997559, -1.4500073), vector3df(0, -180.00002, -0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n44.obj", 0, locTranslateVect);

/* ----- n64.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(2.2000022, zCam + -0.60000181, -0.15000755), vector3df(0, -180.00002, -0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n64.obj", 0, locTranslateVect);

/* ----- n45.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(1.5000001, zCam + -0.59997559, -1.1499931), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n45.obj", 0, locTranslateVect);

/* ----- n65.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(3.7999976, zCam + -0.59997565, 0.15000646), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n65.obj", 0, locTranslateVect);

/* ----- n17.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(1.3999994, zCam + -0.59997559, 1.3499974), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n17.obj", 0, locTranslateVect);

/* ----- n15.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(0.80000013, zCam + -0.59997559, 1.3499959), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n15.obj", 0, locTranslateVect);

/* ----- n2.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(-0.69800001, zCam + -0.60000002, 1.8099999), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n2.obj", 0, locTranslateVect);

/* ----- n1.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(-1.109, zCam + -0.60000002, 1.101), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n1.obj", 0, locTranslateVect);

/* ----- n41.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(-0.84999132, zCam + -0.60002136, -1.1009693), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n41.obj", 0, locTranslateVect);

/* ----- n40.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(-0.55268955, zCam + -0.59997559, -1.719992), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n40.obj", 0, locTranslateVect);

/* ----- n46.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(0.20411956, zCam + -0.60002136, -2.3828812), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n46.obj", 0, locTranslateVect);

/* ----- n47.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(1.186883, zCam + -0.59997559, -3.0067592), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n47.obj", 0, locTranslateVect);

/* ----- n57.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(3.7864738, zCam + -0.59997559, -2.3465822), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n57.obj", 0, locTranslateVect);

/* ----- n63.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(2.9999998, zCam + -0.60000175, 0), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n63.obj", 0, locTranslateVect);

/* ----- n4.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(-0.15099999, zCam + 0, 2.7809999), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n4.obj", 0, locTranslateVect);

/* ----- n3.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(-0.43099999, zCam + -0.60000002, 2.221), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n3.obj", 0, locTranslateVect);

/* ----- n5.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(1.4490454, zCam + -0.59999084, 2.9805713), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n5.obj", 0, locTranslateVect);

/* ----- n21.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(2.4505012, zCam + -0.59999084, 2.2205703), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n21.obj", 0, locTranslateVect);

/* ----- n23.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(2.700068, zCam + -0.59999692, 1.238153), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n23.obj", 0, locTranslateVect);

/* ----- n25.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(2.55, zCam + -0.59999853, 0.89645541), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n25.obj", 0, locTranslateVect);

/* ----- n18.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(2.000042, zCam + -0.59997559, 1.5), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n18.obj", 0, locTranslateVect);

/* ----- n58.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(2.700068, zCam + -0.5999887, -1.5781512), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n58.obj", 0, locTranslateVect);

/* ----- n26.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(3.9971504, zCam + -0.59997559, 1.5840099), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n26.obj", 0, locTranslateVect);

/* ----- n22.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(3.1099916, zCam + -0.59997559, 1.1921216), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n22.obj", 0, locTranslateVect);

/* ----- n27.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(4.7800536, zCam + -0.59997559, 1.1921232), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n27.obj", 0, locTranslateVect);

/* ----- n28.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(5.3253746, zCam + -0.60000175, 0.39489245), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n28.obj", 0, locTranslateVect);

/* ----- n61.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(4.0900269, zCam + -0.59997559, -1.6904742), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n61.obj", 0, locTranslateVect);

/* ----- n82.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(3.2000048, zCam + -0.60002136, -1.279706), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n82.obj", 0, locTranslateVect);

/* ----- n62.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(4.9253793, zCam + -0.59997559, -1.3921216), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n62.obj", 0, locTranslateVect);

/* ----- n54.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(2.3400435, zCam + -0.59997559, -1.4799997), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n54.obj", 0, locTranslateVect);

/* ----- n43.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(0.90000069, zCam + -0.59997559, -1.3000004), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n43.obj", 0, locTranslateVect);

/* ----- n29.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(-0.084280014, zCam + 0, 0), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n29.obj", 0, locTranslateVect);

/* ----- n33.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(1.7999959, zCam + -0.59999907, 0.10000026), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n33.obj", 0, locTranslateVect);

/* ----- n13.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(0.49999207, zCam + -0.59999084, 1.8886256), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n13.obj", 0, locTranslateVect);

/* ----- n9.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(0.19999541, zCam + -0.59999084, 1.6461816), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n9.obj", 0, locTranslateVect);

/* ----- n11.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(0.19999541, zCam + -0.59999084, 1.2513444), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n11.obj", 0, locTranslateVect);

/* ----- n53.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(2.0100148, zCam + -0.59999889, -0.99999928), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n53.obj", 0, locTranslateVect);

/* ----- n50.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(1.4999906, zCam + -0.59999084, -2.5184383), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n50.obj", 0, locTranslateVect);

/* ----- n51.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(1.4999906, zCam + -0.59999084, -1.8754765), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n51.obj", 0, locTranslateVect);

/* ----- n52.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(1.4999906, zCam + -0.59999084, -1.1560684), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n52.obj", 0, locTranslateVect);

/* ----- n78.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(3.7999923, zCam + -0.59999084, 0.65315622), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n78.obj", 0, locTranslateVect);

/* ----- n73.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(3.7999923, zCam + -0.59999752, -0.083650775), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n73.obj", 0, locTranslateVect);

/* ----- n68.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(3.7999923, zCam + -0.59999752, -0.54920012), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n68.obj", 0, locTranslateVect);

/* ----- n55.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(2.2129073, zCam + -0.59997559, -1.9999983), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n55.obj", 0, locTranslateVect);

/* ----- n48.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(0.5928762, zCam + -0.59997559, -1.9999983), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n48.obj", 0, locTranslateVect);

/* ----- n49.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(1.505209, zCam + -0.59999889, -1.9999983), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n49.obj", 0, locTranslateVect);

/* ----- n39.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(1.7061422, zCam + -0.59999734, -0.69999689), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n39.obj", 0, locTranslateVect);

/* ----- n38.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(0.093249381, zCam + -0.59997559, -0.69999689), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n38.obj", 0, locTranslateVect);

/* ----- n36.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(0.90419769, zCam + -0.59997559, -0.099999577), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n36.obj", 0, locTranslateVect);

/* ----- n32.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(0.90419769, zCam + -0.59997559, 0.50000036), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n32.obj", 0, locTranslateVect);

/* ----- n37.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(1.2971019, zCam + -0.59999084, -0.099998675), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n37.obj", 0, locTranslateVect);

/* ----- n34.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(1.2971019, zCam + -0.59999084, 0.50000036), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n34.obj", 0, locTranslateVect);

/* ----- n14.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(0.79953009, zCam + -0.59999084, 1.8000038), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n14.obj", 0, locTranslateVect);

/* ----- n7.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(-0.40658981, zCam + -0.59999084, 1.8000038), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n7.obj", 0, locTranslateVect);

/* ----- n8.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(0.10203838, zCam + -0.59999084, 1.8000038), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n8.obj", 0, locTranslateVect);

/* ----- n10.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(-0.30999637, zCam + -0.59999776, 1.2000099), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n10.obj", 0, locTranslateVect);

/* ----- n30.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(0.094200253, zCam + -0.59999776, 0.89999795), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n30.obj", 0, locTranslateVect);

/* ----- n31.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(1.7071024, zCam + -0.59999776, 0.89999795), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n31.obj", 0, locTranslateVect);

/* ----- n66.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(3.1999986, zCam + -0.59999782, 0.60000306), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n66.obj", 0, locTranslateVect);

/* ----- n76.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(4.6898127, zCam + -0.59999782, 0.60000306), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n76.obj", 0, locTranslateVect);

/* ----- n77.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(4.0001073, zCam + -0.59999782, 0.60000306), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n77.obj", 0, locTranslateVect);

/* ----- n70.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(4.8129082, zCam + -0.59999782, -0.799999), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n70.obj", 0, locTranslateVect);

/* ----- n71.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(4.8129053, zCam + -0.59999782, -0.59999877), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n71.obj", 0, locTranslateVect);

/* ----- n74.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(4.3099976, zCam + -0.59999782, 0), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n74.obj", 0, locTranslateVect);

/* ----- n72.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(4.1099977, zCam + -0.59999782, -0.59999877), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n72.obj", 0, locTranslateVect);

/* ----- n69.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(4.1099977, zCam + -0.59999782, -0.80000097), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n69.obj", 0, locTranslateVect);

