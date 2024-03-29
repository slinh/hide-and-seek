FMap = NEW_IN_DOMAIN(Map) engine::object::TMap(110, 110);

f32 zCam = 0.f;
array<TTransform> locTranslateVect;

/* ----- n64.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(2.2000022, zCam + -0.60000181, -0.15000755), vector3df(0, -180.00002, -0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n64.obj", 0, locTranslateVect);


/* ----- caisse.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(72);

locTranslateVect.push_back(TTransform(vector3df(1.3630171, zCam + -0.70427728, 0.010737106), vector3df(0, 0.8022555, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.3625391, zCam + -0.70427728, 0.32642716), vector3df(0, 2.3935312, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.3630171, zCam + -0.70427728, 0.26723641), vector3df(0, 0.8022555, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.92155695, zCam + -0.70856321, -2.045773), vector3df(0, -88.445376, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.0592303, zCam + -0.62143004, -1.57649), vector3df(0, 70.193458, -0)));
locTranslateVect.push_back(TTransform(vector3df(2.0657372, zCam + -0.70427728, -1.6152941), vector3df(0, 0.8022555, -0)));
locTranslateVect.push_back(TTransform(vector3df(2.0652592, zCam + -0.70427728, -1.5561033), vector3df(0, 2.3935312, -0)));
locTranslateVect.push_back(TTransform(vector3df(2.2634187, zCam + -0.70427728, -2.3615656), vector3df(0, 2.3935312, -0)));
locTranslateVect.push_back(TTransform(vector3df(2.2638967, zCam + -0.70427728, -2.4207563), vector3df(0, 0.8022555, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.90832537, zCam + -0.62142968, -2.1503105), vector3df(0, -39.826468, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.93706834, zCam + -0.62142968, -2.1833692), vector3df(0, -108.4577, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.3552245, zCam + -0.62142968, -2.3073914), vector3df(0, -43.998976, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.3532971, zCam + -0.62142968, -2.2659528), vector3df(0, 24.632258, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.3581156, zCam + -0.62142968, -2.0751429), vector3df(0, -35.63213, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.86208969, zCam + -0.73384094, 0.41810015), vector3df(0, -157.58958, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.89464229, zCam + -0.7338469, 0.42147383), vector3df(0, -85.472065, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.3299136, zCam + -0.78523785, -0.048936307), vector3df(0, -1.427066, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.306447, zCam + -0.73032147, -0.023127109), vector3df(0, -85.472065, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.3001218, zCam + -0.75755841, -0.0089191198), vector3df(0, -77.708319, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.3163586, zCam + -0.75774151, -0.037012547), vector3df(0, 19.696112, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.3139117, zCam + -0.78523785, -0.024150968), vector3df(0, -36.541358, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.2966976, zCam + -0.78523785, -0.044261694), vector3df(0, -18.790151, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.2899888, zCam + -0.78523785, -0.0072190762), vector3df(0, -94.160059, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.84252805, zCam + -0.78147888, -0.016894884), vector3df(0, -94.160059, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.84923679, zCam + -0.78147888, -0.053937491), vector3df(0, -18.790151, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.86645097, zCam + -0.78147888, -0.033826772), vector3df(0, -36.541358, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.86889786, zCam + -0.75398254, -0.046688337), vector3df(0, 19.696112, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.85266095, zCam + -0.75379944, -0.018594913), vector3df(0, -77.708319, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.8589862, zCam + -0.7265625, -0.032802902), vector3df(0, -85.472065, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.88245291, zCam + -0.78147888, -0.058612097), vector3df(0, -1.427066, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.24255401, zCam + -0.78543937, 2.3609877), vector3df(0, -39.372629, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.20019898, zCam + -0.78534698, 2.3415389), vector3df(0, 14.714473, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.74304289, zCam + -0.78148293, -0.74473679), vector3df(0, -153.06063, 0)));
locTranslateVect.push_back(TTransform(vector3df(-0.77446043, zCam + -0.78148293, -0.77172428), vector3df(0, -77.690786, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.72356242, zCam + -0.78148293, -0.76763862), vector3df(0, -95.441935, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.75608796, zCam + -0.7539776, -0.7870146), vector3df(0, -13.774937, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.74453837, zCam + -0.75380522, -0.74743557), vector3df(0, -136.60895, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.74552667, zCam + -0.72656643, -0.77021044), vector3df(0, -144.37265, 0)));
locTranslateVect.push_back(TTransform(vector3df(-0.74179357, zCam + -0.78148293, -0.79572505), vector3df(0, -60.327646, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.74239445, zCam + -0.78148293, -0.87458551), vector3df(0, -6.4087622, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.75878513, zCam + -0.72656643, -0.83312446), vector3df(0, -90.453705, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.76385272, zCam + -0.75380522, -0.81842083), vector3df(0, -82.690013, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.75011659, zCam + -0.7539776, -0.84781814), vector3df(0, 14.714473, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.75143743, zCam + -0.78148293, -0.83479267), vector3df(0, -41.522998, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.77033281, zCam + -0.78148293, -0.85333264), vector3df(0, -23.771847, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.77379966, zCam + -0.78148293, -0.81584734), vector3df(0, -99.141692, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.76495254, zCam + -0.78148293, -0.95478624), vector3df(0, 51.526954, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.74697554, zCam + -0.78148293, -0.91566193), vector3df(0, 126.89686, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.77253056, zCam + -0.78148293, -0.92256898), vector3df(0, 109.14565, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.75939089, zCam + -0.7539776, -0.89685482), vector3df(0, 165.38318, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.76554757, zCam + -0.75380522, -0.9368062), vector3df(0, 30.423886, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.76377779, zCam + -0.72656643, -0.91707534), vector3df(0, 60.215002, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.7717759, zCam + -0.78148293, -0.89307654), vector3df(0, 144.25995, -0)));
locTranslateVect.push_back(TTransform(vector3df(2.4573698, zCam + -0.78148293, -0.92741948), vector3df(0, 75.537152, -0)));
locTranslateVect.push_back(TTransform(vector3df(2.4269326, zCam + -0.72656643, -0.94445997), vector3df(0, -8.5078501, -0)));
locTranslateVect.push_back(TTransform(vector3df(2.411664, zCam + -0.75380522, -0.9474175), vector3df(0, -0.74410028, -0)));
locTranslateVect.push_back(TTransform(vector3df(2.4426959, zCam + -0.7539776, -0.93793571), vector3df(0, 96.660332, -0)));
locTranslateVect.push_back(TTransform(vector3df(2.4296138, zCam + -0.78148293, -0.93741846), vector3df(0, 40.422859, -0)));
locTranslateVect.push_back(TTransform(vector3df(2.4453235, zCam + -0.78148293, -0.95872515), vector3df(0, 58.174067, -0)));
locTranslateVect.push_back(TTransform(vector3df(2.4077222, zCam + -0.78148293, -0.95690572), vector3df(0, -17.195838, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.9356077, zCam + -0.78410488, 0.74917221), vector3df(0, -38.717737, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.9027236, zCam + -0.78410488, 0.75318247), vector3df(0, -108.69267, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.9187644, zCam + -0.78410488, 0.71949619), vector3df(0, -150.22942, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.9183056, zCam + -0.75673002, 0.74150795), vector3df(0, -228.0706, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.6428289, zCam + -0.69215608, -1.3291668), vector3df(0, -224.87854, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.8229032, zCam + -0.75673002, -0.6516574), vector3df(0, -180.19494, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.8233619, zCam + -0.78410488, -0.67366916), vector3df(0, -150.22942, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.8073211, zCam + -0.78410488, -0.63998288), vector3df(0, -108.69267, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.8402052, zCam + -0.78410488, -0.64399314), vector3df(0, -38.717737, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.8464134, zCam + -0.61986691, -0.13795131), vector3df(0, 134.66256, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.851687, zCam + -0.61986691, -0.10156345), vector3df(0, 77.611658, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.8390303, zCam + -0.62142968, -0.41287231), vector3df(0, -35.63213, -0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/caisse.obj", 0, locTranslateVect);

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


/* ----- estrade.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(4);

locTranslateVect.push_back(TTransform(vector3df(-0.54390794, zCam + -0.79386061, 1.5008789), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.3928509, zCam + -0.79386061, 2.5437329), vector3df(0, 0, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.9369569, zCam + -0.79386061, -0.29865736), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.9369569, zCam + -0.79386061, 0.30540195), vector3df(0, 89.999982, -0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/estrade.obj", 0, locTranslateVect);


/* ----- n83.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(3.3525653, zCam + -0.59999782, -0.59999877), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n83.obj", 0, locTranslateVect);


/* ----- escalier.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(3);

locTranslateVect.push_back(TTransform(vector3df(2.8002036, zCam + -0.80002809, 0.59040487), vector3df(0, -539.97896, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.30955523, zCam + -0.80002809, -0.99979937), vector3df(0, -449.97898, -0)));
locTranslateVect.push_back(TTransform(vector3df(2.600023, zCam + -0.80002809, -0.59037703), vector3df(0, -359.97895, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/escalier.obj", 0, locTranslateVect);


/* ----- tableCarre3.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(68);

locTranslateVect.push_back(TTransform(vector3df(4.0716772, zCam + -0.75312972, -0.12246206), vector3df(0, -25.63906, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.095621407, zCam + -0.75312972, 2.0661421), vector3df(0, 7.8937538, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.88818878, zCam + -0.70187378, 0.41697815), vector3df(0, 87.887657, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.8877151, zCam + -0.75117493, 0.39051661), vector3df(0, 34.890495, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.85219812, zCam + -0.75117493, 0.43980759), vector3df(0, -75.436257, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.9165194, zCam + -0.75117493, 0.44135681), vector3df(0, -38.594151, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.3384062, zCam + -0.75312805, 0.44497448), vector3df(0, -172.63539, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.15220706, zCam + -0.7531296, 1.6483885), vector3df(0, -176.92616, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.15447772, zCam + -0.7531296, 1.700083), vector3df(0, -180.00002, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.15194176, zCam + -0.7531296, 1.7527217), vector3df(0, -182.36387, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.0087118596, zCam + -0.7531296, 1.5225538), vector3df(0, -172.59746, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.012623408, zCam + -0.7531296, 1.3571506), vector3df(0, -198.26403, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.010309339, zCam + -0.7531296, 1.6437502), vector3df(0, -180.00002, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.14789496, zCam + -0.7531296, 1.6633804), vector3df(0, -167.47121, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.14662018, zCam + -0.7531296, 1.3576521), vector3df(0, -175.93373, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.14629132, zCam + -0.7531296, 1.5023155), vector3df(0, -186.09595, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.31104922, zCam + -0.7531296, 1.5003883), vector3df(0, -173.75914, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.2974259, zCam + -0.7531296, 1.3576521), vector3df(0, -175.93373, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.29733431, zCam + -0.7531296, 1.6437502), vector3df(0, -180.00002, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.22610247, zCam + -0.70395792, 2.275878), vector3df(0, 5.8802085, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.19965699, zCam + -0.75312972, 2.2795846), vector3df(0, -34.500884, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.24540904, zCam + -0.75312972, 2.2462509), vector3df(0, 46.6952, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.24540904, zCam + -0.75312972, 2.3096499), vector3df(0, -25.468432, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.10912161, zCam + -0.75312972, 1.9297334), vector3df(0, 94.013435, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.0038123457, zCam + -0.75312972, 2.2786098), vector3df(0, 288.16527, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.12981062, zCam + -0.75312972, 2.2839477), vector3df(0, 256.64064, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.23980896, zCam + -0.75312972, 2.2217126), vector3df(0, 227.05767, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.28720972, zCam + -0.75312972, 2.1086676), vector3df(0, 180.90323, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.23519014, zCam + -0.75312972, 1.9867084), vector3df(0, 134.30354, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.028655162, zCam + -0.75312972, 1.9571935), vector3df(0, 62.331336, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.086064391, zCam + -0.75312972, 2.1893213), vector3df(0, -18.212723, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.470593, zCam + -0.75195807, 0.73853296), vector3df(0, 49.035219, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.8367238, zCam + -0.75195807, -0.73440784), vector3df(0, 49.035219, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.4505038, zCam + -0.70396638, -0.048506387), vector3df(0, 1.8081402, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.3571606, zCam + -0.75312972, -0.056416851), vector3df(0, -21.284924, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.4790206, zCam + -0.75312531, -0.052058231), vector3df(0, -21.284924, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.4574742, zCam + -0.75312984, 2.1902561), vector3df(0, -25.196163, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.069283, zCam + -0.75312972, -0.24300115), vector3df(0, 8.2286482, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.0888395, zCam + -0.75312972, -0.36304489), vector3df(0, -16.073872, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.2692075, zCam + -0.75312972, -0.36848283), vector3df(0, 14.783113, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.2691426, zCam + -0.75312972, -0.29574746), vector3df(0, -14.840065, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.2603717, zCam + -0.75312972, -0.13149187), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.4315228, zCam + -0.75312972, -0.17292872), vector3df(0, -21.284924, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.4184918, zCam + -0.75312972, -0.048897348), vector3df(0, 0.17990874, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.4438715, zCam + -0.75312972, -0.3634907), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.6449709, zCam + -0.75312972, -0.35495192), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.6132555, zCam + -0.75312972, -0.24136731), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.6120796, zCam + -0.75312972, -0.13099878), vector3df(0, -22.3842, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.6132555, zCam + -0.75312972, -0.47071314), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.4447031, zCam + -0.75312972, -0.47161949), vector3df(0, 6.1783185, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.2603717, zCam + -0.75312972, -0.47071314), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.0874238, zCam + -0.75312972, -0.47071314), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.0874743, zCam + -0.75312972, 0.13852173), vector3df(0, 0.80494841, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.2603717, zCam + -0.75312972, 0.13849749), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.4438715, zCam + -0.75312972, 0.13849749), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.6132555, zCam + -0.75312972, 0.13849749), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.9414935, zCam + -0.75312972, 0.54097211), vector3df(0, -270.11712, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.627666, zCam + -0.75312972, 0.36523226), vector3df(0, -9.6949046, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.6132731, zCam + -0.75312972, 0.24572828), vector3df(0, 5.3989239, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.4445281, zCam + -0.75312972, 0.24605665), vector3df(0, 8.0461609, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.4439397, zCam + -0.75312972, 0.3679823), vector3df(0, 5.8191312, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.4442716, zCam + -0.75312972, 0.47770563), vector3df(0, -5.203087, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.2603717, zCam + -0.75312972, 0.47771874), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.2604632, zCam + -0.75312972, 0.36829475), vector3df(0, 4.0662814, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.2603717, zCam + -0.75312972, 0.24571989), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.0874038, zCam + -0.75312972, 0.24551097), vector3df(0, -3.8678089, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.0874162, zCam + -0.75312972, 0.36782441), vector3df(0, -3.6778733, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.0878844, zCam + -0.75312972, 0.47745606), vector3df(0, 6.6013906, -0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/tableCarre3.obj", 0, locTranslateVect);

/* ----- quadDessin.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(3);

locTranslateVect.push_back(TTransform(vector3df(4.1368952, zCam + -0.6491732, -0.82028568), vector3df(180.00002, 89.999982, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.067851305, zCam + -0.6491732, 2.3776627), vector3df(180.00002, 89.999982, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.4333143, zCam + -0.6491732, -0.019653052), vector3df(180.00002, 89.999982, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/quadDessin.obj", 0, locTranslateVect);


/* ----- quadInfoTableau.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(3);

locTranslateVect.push_back(TTransform(vector3df(3.7800035, zCam + -0.6491732, 0.11984087), vector3df(180.00002, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.4796286, zCam + -0.6491732, 0.85203272), vector3df(180.00002, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.3817544, zCam + -0.6491732, -0.34493607), vector3df(180.00002, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/quadInfoTableau.obj", 0, locTranslateVect);

/* ----- faussePorte.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(13);

locTranslateVect.push_back(TTransform(vector3df(2.2200153, zCam + -0.80000085, 0.10000104), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(-0.79998451, zCam + -0.79951471, 1.2013974), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(-0.79998451, zCam + -0.80014473, -0.69999975), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.3200174, zCam + -0.79579753, -1.4000009), vector3df(0, -359.99998, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.0000021, zCam + -0.79994011, -0.57998419), vector3df(0, -270, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.80000323, zCam + -0.79990643, -0.97998554), vector3df(0, -270, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.40000081, zCam + -0.79987234, -0.72001314), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.8000027, zCam + -0.79998803, -0.72001177), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.1000013, zCam + -0.79990643, 1.1799856), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(2.1000023, zCam + -0.79999918, 1.1799865), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.2000008, zCam + -0.79994011, 0.57998621), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.3812908, zCam + -0.70213753, 1.5010824), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.5200119, zCam + -0.80000085, 0.099999122), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/faussePorte.obj", 0, locTranslateVect);

/* ----- pSecret.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(1.10138, zCam + -0.70001972, -0.10000908), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/pSecret.obj", 0, locTranslateVect);


/* ----- cylindre.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(48);

locTranslateVect.push_back(TTransform(vector3df(0.83692873, zCam + -0.72805732, -0.54747909), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.4488525, zCam + -0.72805738, 0.84397471), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.9264638, zCam + -0.6590457, 0.84319651), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.9702113, zCam + -0.65909022, 0.84010041), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.0609908, zCam + -0.6590457, 0.84313309), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.9801636, zCam + -0.69063467, 1.0669336), vector3df(89.187811, 46.787045, -1.6842667)));
locTranslateVect.push_back(TTransform(vector3df(4.0168276, zCam + -0.69063467, 1.0669336), vector3df(89.187811, 46.787045, -1.6842667)));
locTranslateVect.push_back(TTransform(vector3df(1.3585407, zCam + -0.71521676, 0.062970221), vector3df(89.187811, -29.221533, -1.6842667)));
locTranslateVect.push_back(TTransform(vector3df(1.3597906, zCam + -0.74907708, 0.042555243), vector3df(89.187811, -19.897106, -1.6842667)));
locTranslateVect.push_back(TTransform(vector3df(1.3601159, zCam + -0.74936759, 0.10408834), vector3df(89.187811, 23.242835, -1.6842667)));
locTranslateVect.push_back(TTransform(vector3df(1.3585407, zCam + -0.74909437, 0.062970221), vector3df(89.187811, -29.221533, -1.6842667)));
locTranslateVect.push_back(TTransform(vector3df(1.3622904, zCam + -0.74925137, 0.083385199), vector3df(89.187811, 13.93124, -1.6842667)));
locTranslateVect.push_back(TTransform(vector3df(1.3601159, zCam + -0.71544009, 0.12408669), vector3df(89.187811, 62.631223, -1.6842667)));
locTranslateVect.push_back(TTransform(vector3df(0.55061853, zCam + -0.74663472, 1.9807825), vector3df(89.187811, 62.631223, -1.6842667)));
locTranslateVect.push_back(TTransform(vector3df(0.5335592, zCam + -0.71649659, 1.969259), vector3df(89.187811, 75.089672, -1.6842667)));
locTranslateVect.push_back(TTransform(vector3df(0.53573292, zCam + -0.71649659, 1.9308566), vector3df(89.187811, 41.187185, -1.6842667)));
locTranslateVect.push_back(TTransform(vector3df(0.53021002, zCam + -0.7121942, 1.8891734), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.53443801, zCam + -0.7121942, 1.8767815), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.53351289, zCam + -0.71649659, 2.1117585), vector3df(89.187811, 77.257055, -1.6842667)));
locTranslateVect.push_back(TTransform(vector3df(0.53405768, zCam + -0.71649659, 2.1218369), vector3df(89.187811, 116.43116, -1.6842667)));
locTranslateVect.push_back(TTransform(vector3df(0.53392148, zCam + -0.71649659, 2.0552363), vector3df(89.187811, 116.43116, -1.6842667)));
locTranslateVect.push_back(TTransform(vector3df(0.53392148, zCam + -0.71649659, 2.0665407), vector3df(89.187811, 89.260348, -1.6842667)));
locTranslateVect.push_back(TTransform(vector3df(0.53443801, zCam + -0.7121942, 1.9788165), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.53753388, zCam + -0.71223289, 1.9934814), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.53378528, zCam + -0.71649659, 2.0747125), vector3df(89.187811, 89.260348, -1.6842667)));
locTranslateVect.push_back(TTransform(vector3df(1.0197653, zCam + -0.65787441, -2.1938014), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.99701017, zCam + -0.68612933, -2.1909208), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.98690766, zCam + -0.68609059, -2.2033045), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.97224253, zCam + -0.68605191, -2.2002087), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.3695388, zCam + -0.63279408, -2.1468198), vector3df(89.187811, 74.382584, -1.6842667)));
locTranslateVect.push_back(TTransform(vector3df(1.3799179, zCam + -0.6590457, -2.0470619), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.376822, zCam + -0.65909022, -2.0908093), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.3798544, zCam + -0.6590457, -2.1815889), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.3759422, zCam + -0.69049007, -2.0766838), vector3df(89.187811, 46.787045, -1.6842667)));
locTranslateVect.push_back(TTransform(vector3df(0.73363572, zCam + -0.69063467, -2.3060284), vector3df(89.187811, 46.787045, -1.6842667)));
locTranslateVect.push_back(TTransform(vector3df(0.73363572, zCam + -0.66248155, -2.4501328), vector3df(89.187811, 46.787045, -1.6842667)));
locTranslateVect.push_back(TTransform(vector3df(3.8322759, zCam + -0.69049007, -0.43316162), vector3df(89.187811, 46.787045, -1.6842667)));
locTranslateVect.push_back(TTransform(vector3df(3.8361881, zCam + -0.6590457, -0.53806674), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.8331556, zCam + -0.65909022, -0.44728702), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.8362515, zCam + -0.6590457, -0.4035396), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.8428998, zCam + -0.66238171, -0.4942404), vector3df(89.187811, 74.382584, -1.6842667)));
locTranslateVect.push_back(TTransform(vector3df(3.8331556, zCam + -0.68727309, 0.076533832), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.8362515, zCam + -0.68731177, 0.091198765), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.8238678, zCam + -0.68735051, 0.10130128), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.8238678, zCam + -0.68727309, 0.20934942), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.8362515, zCam + -0.68731177, 0.19924691), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.8331556, zCam + -0.68727309, 0.18458198), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.8267484, zCam + -0.65909559, 0.12405657), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/cylindre.obj", 0, locTranslateVect);

/* ----- livresAllsMulti.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(50);

locTranslateVect.push_back(TTransform(vector3df(4.0476689, zCam + -0.68554586, 0.84689534), vector3df(0, 180.00002, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.0046382, zCam + -0.71554637, 0.84512818), vector3df(0, 180.00002, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.976438, zCam + -0.68572348, 1.1327958), vector3df(0, 270, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.0247679, zCam + -0.68572348, 1.1327958), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.2976043, zCam + -0.71145749, -2.3473194), vector3df(0, -180.00002, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.99605465, zCam + -0.6832307, -2.3443098), vector3df(0, -180.00002, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.1062601, zCam + -0.71142519, -2.3454669), vector3df(0, -180.00002, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.1062601, zCam + -0.71142519, -2.3934412), vector3df(0, 0, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.99605465, zCam + -0.6832307, -2.3922842), vector3df(0, 0, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.2976043, zCam + -0.71145749, -2.3952937), vector3df(0, 0, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.3563583, zCam + -0.65684921, 0.37718117), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.3563607, zCam + -0.65684921, 0.30999959), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.3563607, zCam + -0.65684921, 0.028979689), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.3563583, zCam + -0.65684921, 0.096161276), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.53816837, zCam + -0.74222642, 2.1103137), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.53816575, zCam + -0.74222642, 2.1774952), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.88761932, zCam + -0.74171549, -2.0997961), vector3df(0, -449.99996, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.8876217, zCam + -0.74171549, -2.1669776), vector3df(0, -449.99996, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.8876217, zCam + -0.71458644, -2.1669776), vector3df(0, -449.99996, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.88761932, zCam + -0.71458644, -2.0997961), vector3df(0, -449.99996, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.88761932, zCam + -0.68463916, -2.0997961), vector3df(0, -449.99996, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.8876217, zCam + -0.68463916, -2.1669776), vector3df(0, -449.99996, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.9354865, zCam + -0.68463916, -2.1669776), vector3df(0, -270, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.93548411, zCam + -0.68463916, -2.0997961), vector3df(0, -270, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.93548411, zCam + -0.71458644, -2.0997961), vector3df(0, -270, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.9354865, zCam + -0.71458644, -2.1669776), vector3df(0, -270, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.9354865, zCam + -0.74171549, -2.1669776), vector3df(0, -270, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.93548411, zCam + -0.74171549, -2.0997961), vector3df(0, -270, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.058461, zCam + -0.65679151, -1.5658149), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(2.0584633, zCam + -0.65679151, -1.6329964), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(2.2566228, zCam + -0.65679151, -2.4384587), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(2.2566204, zCam + -0.65679151, -2.3712771), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(2.2604084, zCam + -0.7420857, -2.1253145), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(2.2604108, zCam + -0.7420857, -2.1924961), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.090966, zCam + -0.71432519, -2.1589901), vector3df(0, -180.00002, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.090966, zCam + -0.71432519, -2.203531), vector3df(0, 0, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.335234, zCam + -0.71554637, -2.125236), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.3353264, zCam + -0.68554586, -2.1695204), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.3839749, zCam + -0.68554586, -2.1695204), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.3838825, zCam + -0.71554637, -2.125236), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.0465307, zCam + -0.74214125, 1.3608404), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.9793491, zCam + -0.74214125, 1.3608377), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.9793491, zCam + -0.68550116, 1.3608377), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.0465307, zCam + -0.68550116, 1.3608404), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.8402162, zCam + -0.71554637, 0.19525716), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.74157602, zCam + -0.68572348, -2.2401662), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.74131018, zCam + -0.65749669, -2.5417159), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.74157602, zCam + -0.68569118, -2.4315104), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.8402162, zCam + -0.71554637, -0.48171386), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.8399503, zCam + -0.68554586, -0.52474451), vector3df(0, 89.999982, -0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/livresAllsMulti.obj", 0, locTranslateVect);

/* ----- livresBleus.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(19);

locTranslateVect.push_back(TTransform(vector3df(3.9372299, zCam + -0.71554738, 0.84513867), vector3df(0, 180.00002, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.0489516, zCam + -0.74251348, 0.84717143), vector3df(0, 180.00002, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.9764485, zCam + -0.71561652, 1.0213075), vector3df(0, 270, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.0247784, zCam + -0.71561652, 1.0213075), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.186116, zCam + -0.74135053, -2.3445861), vector3df(0, -180.00002, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.0390809, zCam + -0.71140993, -2.3454773), vector3df(0, -180.00002, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.99477172, zCam + -0.74137247, -2.3445861), vector3df(0, -180.00002, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.99477172, zCam + -0.74137247, -2.3925605), vector3df(0, 0, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.0390809, zCam + -0.71140993, -2.3934517), vector3df(0, 0, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.186116, zCam + -0.74135053, -2.3925605), vector3df(0, 0, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.3352445, zCam + -0.74251348, -2.1695497), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.3352445, zCam + -0.71554738, -2.0578277), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.383893, zCam + -0.71554738, -2.0578277), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.383893, zCam + -0.74251348, -2.1695497), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.74158651, zCam + -0.71561652, -2.3516545), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.74158651, zCam + -0.68567592, -2.4986897), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.74158651, zCam + -0.71563846, -2.5429988), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.8402267, zCam + -0.74251348, -0.52602738), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.8402267, zCam + -0.71554738, -0.41430554), vector3df(0, 89.999982, -0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/livresBleus.obj", 0, locTranslateVect);

/* ----- livresAlls.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(31);

locTranslateVect.push_back(TTransform(vector3df(3.981755, zCam + -0.74249798, 0.84715807), vector3df(0, 180.00002, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.9764347, zCam + -0.71560103, 1.0885041), vector3df(0, 270, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.0247645, zCam + -0.71560103, 1.0885041), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.2533126, zCam + -0.74133503, -2.3445725), vector3df(0, -180.00002, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.0619683, zCam + -0.74135292, -2.3445725), vector3df(0, -180.00002, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.0619683, zCam + -0.74135292, -2.3925469), vector3df(0, 0, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.2533126, zCam + -0.74133503, -2.3925469), vector3df(0, 0, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.54013681, zCam + -0.65709996, 2.1325204), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.54013681, zCam + -0.65709996, 2.0653608), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.88688207, zCam + -0.65692317, -2.1220028), vector3df(0, -449.99996, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.8868441, zCam + -0.65692317, -2.0548432), vector3df(0, -449.99996, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.93169516, zCam + -0.65692317, -2.0548432), vector3df(0, -270, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.93169516, zCam + -0.65692317, -2.1220028), vector3df(0, -270, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.0617645, zCam + -0.74230319, -1.58732), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(2.0617645, zCam + -0.74230319, -1.5201603), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(2.2599239, zCam + -0.74230319, -2.3256226), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(2.2599239, zCam + -0.74230319, -2.3927822), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(2.2566195, zCam + -0.65640682, -2.1475213), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(2.2566195, zCam + -0.65640682, -2.0803616), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.0292957, zCam + -0.74135208, -2.1589868), vector3df(0, -180.00002, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.0292957, zCam + -0.74135208, -2.2035279), vector3df(0, 0, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.3352309, zCam + -0.74249798, -2.1023531), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.3838794, zCam + -0.74249798, -2.1023531), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.9343963, zCam + -0.65701479, 1.3608367), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.0015559, zCam + -0.65701479, 1.3608367), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.0015559, zCam + -0.71522456, 1.3608367), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.9343963, zCam + -0.71522456, 1.3608367), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.8402131, zCam + -0.74257326, 0.13358694), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.74157292, zCam + -0.71560103, -2.2844579), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.74157292, zCam + -0.71561891, -2.4758022), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.8402131, zCam + -0.74249798, -0.45883077), vector3df(0, 89.999982, -0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/livresAlls.obj", 0, locTranslateVect);

/* ----- duoLivre.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(7);

locTranslateVect.push_back(TTransform(vector3df(3.9901044, zCam + -0.65625149, 1.0044186), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.0119505, zCam + -0.65625149, 1.0044186), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.8258176, zCam + -0.71434504, 0.058123268), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.72875911, zCam + -0.65625149, -2.3685434), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.6580083, zCam + -0.76675528, -1.3421694), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.6547673, zCam + -0.73416615, -1.3421694), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.6616356, zCam + -0.73416615, -1.3054088), vector3df(0, 89.999982, -0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/duoLivre.obj", 0, locTranslateVect);

/* ----- boiteVide.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(33);

locTranslateVect.push_back(TTransform(vector3df(3.9830132, zCam + -0.69182569, 1.0760832), vector3df(0, 85.298975, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.0196772, zCam + -0.69182569, 1.0760832), vector3df(0, 85.298975, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.3399898, zCam + -0.72156626, -2.2511621), vector3df(0, 116.70405, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.3802128, zCam + -0.69374144, -2.314527), vector3df(0, 74.119307, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.3600657, zCam + -0.71659112, 0.057026498), vector3df(0, -82.66205, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.3600657, zCam + -0.71659112, 0.11698286), vector3df(0, -82.66205, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.3600657, zCam + -0.71659112, 0.37348217), vector3df(0, -82.66205, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.53484154, zCam + -0.71662223, 2.1116383), vector3df(0, 87.761148, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.53525817, zCam + -0.71662223, 2.064559), vector3df(0, 87.761148, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.54247469, zCam + -0.74838126, 1.9761072), vector3df(0, 25.640549, -0)));
locTranslateVect.push_back(TTransform(vector3df(2.0627859, zCam + -0.71659112, -1.5090483), vector3df(0, -82.66205, -0)));
locTranslateVect.push_back(TTransform(vector3df(2.2609453, zCam + -0.74832857, -2.068996), vector3df(0, -98.174482, -0)));
locTranslateVect.push_back(TTransform(vector3df(2.2609453, zCam + -0.71659112, -2.3145106), vector3df(0, -82.66205, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.0410573, zCam + -0.69056284, -2.2022953), vector3df(0, -11.103635, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.0964942, zCam + -0.74743658, -2.2035344), vector3df(0, 6.875551, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.3669097, zCam + -0.6339851, -2.1384919), vector3df(0, 112.89452, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.378792, zCam + -0.69168109, -2.0675342), vector3df(0, 85.298975, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.9225826, zCam + -0.69149363, 1.3651628), vector3df(0, 7.3379275, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.9240119, zCam + -0.7484194, 1.3651628), vector3df(0, -8.1744464, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.8364813, zCam + -0.74865776, 0.2007854), vector3df(0, 96.875592, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.73648554, zCam + -0.69182569, -2.2968788), vector3df(0, 85.298975, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.73648554, zCam + -0.66367257, -2.4409833), vector3df(0, 85.298975, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.8351257, zCam + -0.69168109, -0.42401186), vector3df(0, 85.298975, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.41624284, zCam + -0.7452414, 1.3070066), vector3df(0, 257.58154, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.4403774, zCam + -0.7452414, 2.3656461), vector3df(0, 196.5377, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.84383094, zCam + -0.74528372, -2.0779169), vector3df(0, -225.93766, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.5639663, zCam + -0.74528372, -1.8852835), vector3df(0, -89.702616, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.8402708, zCam + -0.66357273, -0.48591244), vector3df(0, 112.89452, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.7690444, zCam + -0.74528366, -0.53093207), vector3df(0, -3.8210554, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.8352423, zCam + -0.69178402, 0.1453485), vector3df(0, 78.896348, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.7718797, zCam + -0.7452414, 0.40435401), vector3df(0, 106.53767, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.8364813, zCam + -0.73645252, 0.26355004), vector3df(0, 94.066834, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.3464718, zCam + -0.73664922, 0.042986002), vector3df(0, 23.095986, -0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/boiteVide.obj", 0, locTranslateVect);

/* ----- livresRouges.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(12);

locTranslateVect.push_back(TTransform(vector3df(3.9763751, zCam + -0.68572032, 1.0211539), vector3df(0, 270, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.0247049, zCam + -0.68572032, 1.0211539), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.1859624, zCam + -0.71145433, -2.3472567), vector3df(0, -180.00002, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.1859624, zCam + -0.71145433, -2.395231), vector3df(0, 0, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.5358758, zCam + -0.65662819, 1.8593606), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.5358758, zCam + -0.65662819, 1.926481), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.5358758, zCam + -0.74220031, 1.926481), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.5358758, zCam + -0.74220031, 1.8593606), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.97902006, zCam + -0.65591431, -2.1589072), vector3df(0, -180.00002, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.97902006, zCam + -0.65591431, -2.2034481), vector3df(0, 0, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.8401332, zCam + -0.65713549, 0.08331126), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.74151325, zCam + -0.68572032, -2.3518081), vector3df(0, 89.999982, -0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/livresRouges.obj", 0, locTranslateVect);

/* ----- corbeille.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(17);

locTranslateVect.push_back(TTransform(vector3df(0.53400862, zCam + -0.71282911, 1.8539655), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.53400862, zCam + -0.71282911, 1.9111359), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.53400862, zCam + -0.71282911, 1.949726), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.53792769, zCam + -0.79361922, 2.3861544), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.2939689, zCam + -0.79361922, 2.3640361), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.46169412, zCam + -0.79361922, 2.2014277), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.15941419, zCam + -0.79361922, 1.5961969), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.7236515, zCam + -0.79361922, -1.8809801), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.5418403, zCam + -0.79361922, -1.1574457), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.5633903, zCam + -0.79361922, 1.3101144), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.5280962, zCam + -0.79361922, 1.2584913), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.4006519, zCam + -0.79361922, 0.84066713), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.760679, zCam + -0.79361922, -0.99418658), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.4181657, zCam + -0.79361922, -0.83194965), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.8424776, zCam + -0.79361922, 0.40187111), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.8408644, zCam + -0.79361922, -0.22405854), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.8200893, zCam + -0.79361922, -0.036924932), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/corbeille.obj", 0, locTranslateVect);

/* ----- bouteille.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(30);

locTranslateVect.push_back(TTransform(vector3df(0.52837121, zCam + -0.7120316, 2.188097), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.53192121, zCam + -0.71246535, 2.1635392), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.53386128, zCam + -0.6588065, 2.1970472), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.53648138, zCam + -0.7120316, 2.1764181), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.0571305, zCam + -0.62832445, -2.1771121), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(2.0613918, zCam + -0.74455607, -1.6539298), vector3df(0, -180.00002, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.0693362, zCam + -0.63001657, -1.5152156), vector3df(0, -180.00002, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.0593235, zCam + -0.65976924, -1.5022399), vector3df(0, -180.00002, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.2618032, zCam + -0.65811336, -2.202996), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(2.2660942, zCam + -0.71225768, -2.202996), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(2.2606158, zCam + -0.71225768, -2.1909425), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.0571305, zCam + -0.62832445, -2.2001095), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.0729414, zCam + -0.62842876, -2.1837962), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.0918022, zCam + -0.62842876, -2.1986713), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.0950347, zCam + -0.65795189, -2.189549), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.0326841, zCam + -0.71610892, -2.2013283), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.1021571, zCam + -0.65795189, -2.2013283), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.3774343, zCam + -0.74438304, -2.0453475), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.0449772, zCam + -0.71708196, 1.3605421), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.0570307, zCam + -0.71708196, 1.3660208), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.0570307, zCam + -0.65872133, 1.3660208), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.8342752, zCam + -0.74443477, 0.060377128), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.74429351, zCam + -0.71637452, -2.4179633), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.81790161, zCam + -0.74089563, -2.0807133), vector3df(0, -225.93766, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.5854079, zCam + -0.74076796, -1.9001302), vector3df(0, -89.702616, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.6527376, zCam + -0.77240217, -1.3274484), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.8429337, zCam + -0.74438304, -0.40099192), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.7853928, zCam + -0.7407679, -0.51061201), vector3df(0, -3.8210554, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.8342752, zCam + -0.65917307, 0.20644829), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.8342752, zCam + -0.7173301, 0.13697517), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/bouteille.obj", 0, locTranslateVect);

/* ----- plante.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(7);

locTranslateVect.push_back(TTransform(vector3df(1.4321182, zCam + -0.76044494, -2.5337503), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(-0.71236473, zCam + -0.76044494, 0.97508454), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.2870693, zCam + -0.76044494, 0.45053214), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.3054266, zCam + -0.76044494, 0.97508454), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.8824147, zCam + -0.76044494, 0.81134462), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.2157252, zCam + -0.76044494, -2.5219316), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.4204173, zCam + -0.76044494, -1.9254507), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/plante.obj", 0, locTranslateVect);

/* ----- murO.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(61);

locTranslateVect.push_back(TTransform(vector3df(-0.79998612, zCam + -0.80000001, 1.0013971), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(-0.79998612, zCam + -0.80000001, -0.9000001), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.82001567, zCam + -0.79999995, 0.29999843), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.82001567, zCam + -0.79999995, 0.0999984), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.82001567, zCam + -0.79999995, -0.1000016), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.82001567, zCam + -0.79999995, 0.49999931), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.82001567, zCam + -0.79999995, 0.69999933), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.82001567, zCam + -0.79999995, 0.89999938), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.82001567, zCam + -0.79999995, -0.50000179), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.82001567, zCam + -0.79999995, -0.30000177), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(-0.57998586, zCam + -0.79999995, 1.5991423), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(-0.57998681, zCam + -0.79999995, 1.4000028), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(-0.57998586, zCam + -0.79999995, 1.7991498), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.22001536, zCam + -0.79999995, 1.8000025), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.22001441, zCam + -0.79999995, 1.4000028), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.52001411, zCam + -0.79999995, 2.6000309), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.52001411, zCam + -0.79999995, 2.2), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.52001315, zCam + -0.79999995, 2.0000012), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(-0.27998707, zCam + -0.79999995, 2.0000012), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(-0.27998611, zCam + -0.79999995, 2.399056), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(-0.27998611, zCam + -0.79999995, 2.1991482), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.1200151, zCam + -0.79999995, 1.4000013), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.5200132, zCam + -0.79999989, -1.0000006), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.5200132, zCam + -0.79999989, -1.799999), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.5200132, zCam + -0.79999989, -1.4000003), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.5200132, zCam + -0.79999989, -1.6000023), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.5200152, zCam + -0.79999989, -2.4000001), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.5200152, zCam + -0.79999989, -2.1999981), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.72001445, zCam + -0.79999989, -2.4000001), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.72001445, zCam + -0.79999989, -1.9999992), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.72001445, zCam + -0.79999989, -2.1999981), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.220013, zCam + -0.79999995, -1.0000002), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.220013, zCam + -0.79999995, -1.3999758), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.220013, zCam + -0.79999995, -1.1999769), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.32001486, zCam + -0.79999995, -1.2000245), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.32001486, zCam + -0.79999995, -1.6), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.32002136, zCam + -0.79999995, -1.7999986), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.2200136, zCam + -0.79999995, -0.2999984), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.2200158, zCam + -0.79999995, -0.50000179), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.2200158, zCam + -0.79999995, 0.89999938), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.2200158, zCam + -0.79999995, 0.69999933), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.2200158, zCam + -0.79999995, 0.49999931), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.2200136, zCam + -0.79999995, -0.099999361), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.2200158, zCam + -0.79999995, 0.29999843), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.4800158, zCam + -0.79999995, 0.0999984), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.5200133, zCam + -0.79999995, -0.1000016), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.5200133, zCam + -0.79999995, 0.29999843), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.420013, zCam + -0.79999995, 0.79999948), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.4200139, zCam + -0.79999995, 1.4000002), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.4200139, zCam + -0.79999995, 1.2000002), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.4200139, zCam + -0.79999995, 1.0000001), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.820014, zCam + -0.79999995, 0.79999948), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.6200135, zCam + -0.79999995, -0.60000002), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.6200135, zCam + -0.79999995, -0.80000001), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.6200135, zCam + -0.79999995, -1), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.6200135, zCam + -0.79999995, -1.2), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.820014, zCam + -0.79999995, -0.60000002), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.820014, zCam + -0.79999995, 0), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.820014, zCam + -0.79999995, -0.40000135), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.820014, zCam + -0.79999995, 0.2), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.820014, zCam + -0.79999995, 0.40000001), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/murO.obj", 0, locTranslateVect);

/* ----- quad_Religieuse.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(3);

locTranslateVect.push_back(TTransform(vector3df(0.053084496, zCam + -0.66380727, 1.2207875), vector3df(-89.999982, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.6427151, zCam + -0.66380721, -1.9786553), vector3df(-89.999982, 0, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.207571, zCam + -0.65129864, -0.57923031), vector3df(-89.999982, 0, -0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/quad_Religieuse.obj", 0, locTranslateVect);

/* ----- quad_BlackBoardSa.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(5);

locTranslateVect.push_back(TTransform(vector3df(-0.57655132, zCam + -0.66173238, 1.5004108), vector3df(-180.00002, -180.00002, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.3847511, zCam + -0.66173232, 2.5758333), vector3df(-180.00002, -270, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.6238453, zCam + -0.66173232, -1.099046), vector3df(-180.00002, -180.00002, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.9759612, zCam + -0.66173232, -0.2985903), vector3df(-180.00002, -0, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.9759612, zCam + -0.66173232, 0.29971296), vector3df(-180.00002, -0, -0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/quad_BlackBoardSa.obj", 0, locTranslateVect);

/* ----- casier.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(30);

locTranslateVect.push_back(TTransform(vector3df(3.979362, zCam + -0.72003996, 0.050632764), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.8506308, zCam + -0.72003996, -0.11962253), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.5305932, zCam + -0.72003996, 0.6506331), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.049335, zCam + -0.72003996, 1.7536366), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.71846902, zCam + -0.72003996, 1.7536366), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.88390183, zCam + -0.72003996, 1.7536366), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.55303538, zCam + -0.72003996, 1.7536366), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(-0.51353884, zCam + -0.72003996, 0.95063215), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(-0.34810591, zCam + -0.72003996, 0.95063215), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(-0.01723945, zCam + -0.72003996, 0.95063215), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(-0.18267226, zCam + -0.72003996, 0.95063215), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.14819372, zCam + -0.72003996, 0.95063215), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.267566, zCam + -0.72003996, -0.94936848), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.9367, zCam + -0.72003996, -0.94936848), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.1021328, zCam + -0.72003996, -0.94936848), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.7712663, zCam + -0.72003996, -0.94936848), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.6058334, zCam + -0.72003996, -0.94936848), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.4167166, zCam + -0.72003996, 0.35063148), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.2512839, zCam + -0.72003996, 0.35063148), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.920418, zCam + -0.72003996, 0.35063148), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.0858507, zCam + -0.72003996, 0.35063148), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.7549844, zCam + -0.72003996, 0.35063148), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.5895514, zCam + -0.72003996, 0.35063148), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.5895514, zCam + -0.72003996, -0.3463642), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.7549844, zCam + -0.72003996, -0.3463642), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.0858507, zCam + -0.72003996, -0.3463642), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.920418, zCam + -0.72003996, -0.3463642), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.2512839, zCam + -0.72003996, -0.3463642), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.4167166, zCam + -0.72003996, -0.3463642), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.6752739, zCam + -0.71986097, -2.5495307), vector3df(0, -359.99998, -0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/casier.obj", 0, locTranslateVect);

/* ----- murN.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(92);

locTranslateVect.push_back(TTransform(vector3df(4.7028489, zCam + -0.79999995, 0.61279255), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.8000135, zCam + -0.79999995, -0.61999977), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.6000123, zCam + -0.79999995, -0.61999977), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.8000143, zCam + -0.79999995, -0.61999977), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.0000143, zCam + -0.79999995, -0.61999977), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.2000155, zCam + -0.79999995, -0.61999977), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.2000009, zCam + -0.79999995, 0.87999898), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.80001295, zCam + -0.79999995, 0.87999898), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.2000009, zCam + -0.79999995, -0.11999866), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.80001295, zCam + -0.79999995, -0.11999866), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.80001295, zCam + -0.79999995, 0.48000067), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.2000009, zCam + -0.79999995, 0.48000067), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(-0.39998695, zCam + -0.79999995, 1.78), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(-0.59997398, zCam + -0.79999995, 1.78), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.2858967e-005, zCam + -0.79999995, 1.1800009), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(-0.40000302, zCam + -0.79999995, 1.1800009), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(-0.1999862, zCam + -0.79999995, 1.1800009), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(-0.600003, zCam + -0.79999995, 1.1800009), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(-0.80000085, zCam + -0.79999995, 1.1800009), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.1000113, zCam + -0.79999995, 2.5800016), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.9000108, zCam + -0.79999995, 2.5800016), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.5000256, zCam + -0.79999995, 2.5800016), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.3000109, zCam + -0.79999995, 2.5800016), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.50001508, zCam + -0.79999995, 2.5800016), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.70002979, zCam + -0.79999995, 2.5800016), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.100015, zCam + -0.79999995, 2.5800016), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.3000142, zCam + -0.79999995, 2.3800001), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.10002715, zCam + -0.79999995, 2.3800001), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(-0.099971108, zCam + -0.79999995, 2.3800001), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(-0.2999858, zCam + -0.79999995, 2.3800001), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.3190179e-005, zCam + -0.79999995, 1.78), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.40000001, zCam + -0.79999995, 1.78), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.60001469, zCam + -0.79999995, 1.78), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.80001295, zCam + -0.79999995, 1.78), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.0000141, zCam + -0.79999995, 1.78), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.49999946, zCam + -0.79999995, 1.1800005), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.70001632, zCam + -0.79999995, 1.1800005), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.6999992, zCam + -0.79999995, -1.0200001), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.900016, zCam + -0.79999995, -1.0200001), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.4999992, zCam + -0.79999995, -1.0200001), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.1000168, zCam + -0.79999995, -2.0199983), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.1000135, zCam + -0.79999995, -2.0199962), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.3, zCam + -0.79999995, -2.0199962), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.69999856, zCam + -0.79999995, -2.0199962), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.700011, zCam + -0.79999995, -2.0199983), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.5000128, zCam + -0.79999995, -2.0199983), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.0000057, zCam + -0.79999995, -1.6199994), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.80000997, zCam + -0.79999995, -1.6199994), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.60001069, zCam + -0.79999995, -1.6199994), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.8000175, zCam + -0.79999995, -0.71999782), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.0000157, zCam + -0.79999995, -0.71999782), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.4000007, zCam + -0.79999995, -0.71999782), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.2000009, zCam + -0.79999995, -0.71999782), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.2858967e-005, zCam + -0.79999995, -0.71999782), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.80001295, zCam + -0.79999995, -0.71999782), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.60001469, zCam + -0.79999995, -0.71999782), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.39999789, zCam + -0.79999995, -0.71999782), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(-0.40000302, zCam + -0.79999995, -0.71999782), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(-0.1999862, zCam + -0.79999995, -0.71999782), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(-0.600003, zCam + -0.79999995, -0.71999782), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(-0.80000085, zCam + -0.79999995, -0.71999782), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.7000128, zCam + -0.79999995, 1.1799999), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.100014, zCam + -0.79999995, 1.1799999), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.5000136, zCam + -0.79999995, 1.1799999), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.3000138, zCam + -0.79999995, 1.1799999), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.5000157, zCam + -0.79999995, -0.3199994), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.7000155, zCam + -0.79999995, -0.3199994), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.8000135, zCam + -0.79999995, 0.57999963), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.1000149, zCam + -0.79999995, -0.3199994), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.9000149, zCam + -0.79999995, -0.3199994), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.3000147, zCam + -0.79999995, -0.3199994), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.2000151, zCam + -0.79999995, 0.57999963), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.4000139, zCam + -0.79999995, 0.57999963), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.4000149, zCam + -0.79999995, 1.3800013), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.4000001, zCam + -0.79999995, 1.3800013), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.0000167, zCam + -0.79999995, 1.3800013), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.8, zCam + -0.79999995, 1.3800013), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.400013, zCam + -0.79999995, 0.78000152), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.0000143, zCam + -0.79999995, 0.78000152), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.8000157, zCam + -0.79999995, 0.78000152), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.2000155, zCam + -0.79999995, -0.81999999), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.0000143, zCam + -0.79999995, -0.81999999), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.8000143, zCam + -0.79999995, -0.81999999), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.2000155, zCam + -0.79999995, -0.019997139), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.8000157, zCam + -0.79999995, -0.019997139), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.0000157, zCam + -0.79999995, -0.019997139), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.400013, zCam + -0.79999995, -0.019997139), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.6000113, zCam + -0.79999995, -0.019997139), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.8000112, zCam + -0.79999995, 0.5800004), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.8000157, zCam + -0.79999995, 0.5800004), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.0000143, zCam + -0.79999995, 0.5800004), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.400013, zCam + -0.79999995, 0.5800004), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/murN.obj", 0, locTranslateVect);

/* ----- meubleBasRepet.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(35);

locTranslateVect.push_back(TTransform(vector3df(1.3548665, zCam + -0.77247864, 0.66451132), vector3df(-0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.3548665, zCam + -0.77247864, 0.7397114), vector3df(-0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.3548665, zCam + -0.77247864, 0.81491292), vector3df(-0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.3548665, zCam + -0.77247864, 0.58931172), vector3df(-0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.31749627, zCam + -0.77144843, 1.7548625), vector3df(-0, 0, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.4678973, zCam + -0.77206969, 1.7548625), vector3df(-0, 0, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.54309744, zCam + -0.77206969, 1.7548625), vector3df(-0, 0, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.39269769, zCam + -0.77206969, 1.7548625), vector3df(-0, 0, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.45485604, zCam + -0.77247876, 1.8812618), vector3df(-0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.45485604, zCam + -0.77247876, 2.106863), vector3df(-0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.45485604, zCam + -0.77247876, 2.0316615), vector3df(-0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.45485604, zCam + -0.77247876, 1.9564614), vector3df(-0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(2.2547004, zCam + -0.77197123, 1.9729023), vector3df(-0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(2.2547004, zCam + -0.77197123, 2.0481024), vector3df(-0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(2.2547004, zCam + -0.77217835, 2.1233039), vector3df(-0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(2.2547004, zCam + -0.77192092, 1.8977027), vector3df(-0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(2.2547004, zCam + -0.7723251, 2.1985004), vector3df(-0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(2.2547004, zCam + -0.77220666, 2.4241016), vector3df(-0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(2.2547004, zCam + -0.77220666, 2.4993019), vector3df(-0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(2.2547004, zCam + -0.7723251, 2.3489001), vector3df(-0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(2.2547004, zCam + -0.7723251, 2.2737), vector3df(-0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.8494867, zCam + -0.77197146, -2.0451336), vector3df(0, -359.99998, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.7742853, zCam + -0.77197146, -2.0451336), vector3df(0, -359.99998, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.6990805, zCam + -0.77197146, -2.0451336), vector3df(0, -359.99998, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.6238616, zCam + -0.77197146, -2.0451336), vector3df(0, -359.99998, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.467782, zCam + -0.77224296, 0.84538984), vector3df(0, -180.00002, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.5429821, zCam + -0.77224296, 0.84538984), vector3df(0, -180.00002, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.4915638, zCam + -0.77209347, 0.045157108), vector3df(0, -180.00002, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.5667639, zCam + -0.77209347, 0.045157108), vector3df(0, -180.00002, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.7171655, zCam + -0.77209628, 0.045157108), vector3df(0, -180.00002, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.6419654, zCam + -0.77209347, 0.045157108), vector3df(0, -180.00002, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.3411641, zCam + -0.77209347, 0.045157108), vector3df(0, -180.00002, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.4163642, zCam + -0.77209347, 0.045157108), vector3df(0, -180.00002, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.2659626, zCam + -0.77209347, 0.045157108), vector3df(0, -180.00002, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.1907625, zCam + -0.77209347, 0.045157108), vector3df(0, -180.00002, -0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/meubleBasRepet.obj", 0, locTranslateVect);

/* ----- armoirePharmacie.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(2);

locTranslateVect.push_back(TTransform(vector3df(0.86068898, zCam + -0.74384171, 0.57682586), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.8612936, zCam + -0.74407989, -0.71536863), vector3df(0, -89.999982, -0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/armoirePharmacie.obj", 0, locTranslateVect);

/* ----- chaise.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(92);

locTranslateVect.push_back(TTransform(vector3df(1.3655533, zCam + -0.74223328, 0.45815289), vector3df(0, -262.63536, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.45006087, zCam + -0.74223351, 1.2976947), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.037630379, zCam + -0.7422334, 1.5357515), vector3df(0, -262.59744, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.044476993, zCam + -0.7422334, 1.3567392), vector3df(0, -288.26406, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.040687203, zCam + -0.7422334, 1.6531119), vector3df(0, -270, 0)));
locTranslateVect.push_back(TTransform(vector3df(-0.12027132, zCam + -0.7422334, 1.6791091), vector3df(0, -257.47125, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.11699903, zCam + -0.7422334, 1.3693742), vector3df(0, -265.93372, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.11509107, zCam + -0.7422334, 1.5083984), vector3df(0, -276.09592, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.28186908, zCam + -0.7422334, 1.5129969), vector3df(0, -263.75912, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.26780474, zCam + -0.7422334, 1.3693742), vector3df(0, -265.93372, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.26695645, zCam + -0.7422334, 1.6531119), vector3df(0, -270, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.12058639, zCam + -0.74223351, 1.9000852), vector3df(0, 4.0133974, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.014553327, zCam + -0.74223351, 2.3045552), vector3df(0, 198.1653, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.12772135, zCam + -0.74223351, 2.3156667), vector3df(0, 166.64065, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.25365123, zCam + -0.74223351, 2.2503283), vector3df(0, 137.05769, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.31743634, zCam + -0.74223351, 2.1185069), vector3df(0, 90.903247, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.26310745, zCam + -0.74223351, 1.9715073), vector3df(0, 44.303561, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.034470327, zCam + -0.74223351, 1.9259423), vector3df(0, -27.668705, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.12550505, zCam + -0.74223351, 2.0514877), vector3df(0, -81.331359, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.11784635, zCam + -0.74223351, 2.189923), vector3df(0, -108.21276, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.3813931, zCam + -0.74223351, 2.3984272), vector3df(0, -180.00002, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.7399292, zCam + -0.74223357, -2.0832803), vector3df(0, -485.32718, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.8942271, zCam + -0.74223351, -1.6731358), vector3df(-0, -194.42784, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.8144073, zCam + -0.74223351, -1.7497599), vector3df(0, -101.46956, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.9287343, zCam + -0.74223351, -1.8269668), vector3df(-0, -338.51464, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.9839025, zCam + -0.74223351, -1.7397944), vector3df(-0, -276.52707, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.7252975, zCam + -0.74223351, -1.5738968), vector3df(0, -342.49273, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.7738153, zCam + -0.74223351, -1.558603), vector3df(0, -342.49273, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.6672248, zCam + -0.74223351, -1.4439125), vector3df(0, -163.79254, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.6350917, zCam + -0.74223351, -1.5118921), vector3df(0, -71.113457, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.6587991, zCam + -0.74223351, -1.5609108), vector3df(0, -48.793717, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.8206596, zCam + -0.74223351, -1.5007067), vector3df(0, -288.5891, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.8095659, zCam + -0.74223351, -1.4300014), vector3df(0, -251.5492, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.6100057, zCam + -0.74223351, -1.2181374), vector3df(0, -81.602538, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.6143545, zCam + -0.74223351, -1.1544806), vector3df(0, -103.92222, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.7147983, zCam + -0.74223351, -1.4280547), vector3df(0, -163.79254, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.7888287, zCam + -0.74223351, -1.1274824), vector3df(0, -251.5492, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.7999225, zCam + -0.74223351, -1.1981877), vector3df(0, -288.5891, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.734001, zCam + -0.74223351, -1.2565727), vector3df(0, -361.29561, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.6833887, zCam + -0.74223351, -1.261022), vector3df(0, -377.17239, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.9196326, zCam + -0.74223351, -1.4238453), vector3df(0, -357.77971, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.9629841, zCam + -0.74223351, -1.4376808), vector3df(0, -380.27862, -0)));
locTranslateVect.push_back(TTransform(vector3df(2.032162, zCam + -0.74223351, -1.3620465), vector3df(0, -294.73217, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.9814316, zCam + -0.74223351, -1.2901016), vector3df(0, -192.82912, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.9436144, zCam + -0.74223351, -1.2513621), vector3df(0, -200.4899, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.8578339, zCam + -0.74223351, -1.3076266), vector3df(0, -122.90529, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.843437, zCam + -0.74223351, -1.3697863), vector3df(0, -100.58555, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.6368941, zCam + -0.74223357, -1.9171159), vector3df(0, -359.70262, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.34995225, zCam + -0.74223351, -1.8338412), vector3df(0, 160.59881, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.42466396, zCam + -0.74223351, -1.9371464), vector3df(0, 72.367951, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.41728503, zCam + -0.74223351, -1.8679689), vector3df(0, 119.20799, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.35179695, zCam + -0.74223351, -1.9685071), vector3df(0, -8.1508976, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.5108094, zCam + -0.74223351, 1.2655439), vector3df(0, -133.88351, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.490993, zCam + -0.74223351, 1.3130889), vector3df(0, -195.47675, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.7308292, zCam + -0.74223351, -1.1081727), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.0312185, zCam + -0.74223351, -0.57314783), vector3df(0, -0.59215189, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.9893723, zCam + -0.74223351, -0.57314783), vector3df(0, -0.59215189, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.9639921, zCam + -0.74223351, -0.12746932), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.0385742, zCam + -0.74223351, -0.11740287), vector3df(0, -115.19614, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.0406895, zCam + -0.74223351, -0.25682801), vector3df(0, -81.771394, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.0571527, zCam + -0.74223351, -0.3636573), vector3df(0, -106.07391, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.2422237, zCam + -0.74223351, -0.38528591), vector3df(0, -75.216925, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.2373214, zCam + -0.74223351, -0.29723918), vector3df(0, -104.8401, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.2299938, zCam + -0.74223351, -0.14183268), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.399879, zCam + -0.74223351, -0.17169875), vector3df(0, -111.28491, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.9487388, zCam + -0.74223351, -0.57314783), vector3df(0, -0.59215189, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.4139395, zCam + -0.74223351, -0.37285244), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.6139083, zCam + -0.74223351, -0.36431366), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.5821929, zCam + -0.74223351, -0.25095943), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.5794196, zCam + -0.74223351, -0.12873131), vector3df(0, -112.38418, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.5821929, zCam + -0.74223351, -0.48007482), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.4159527, zCam + -0.74223351, -0.48414817), vector3df(0, -83.821666, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.2299938, zCam + -0.74223351, -0.48007482), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.0571456, zCam + -0.74223351, -0.48007482), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.8060322, zCam + -0.74223351, -0.46047863), vector3df(0, -273.821, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.8046608, zCam + -0.74223351, 0.46333829), vector3df(0, -270, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.0573306, zCam + -0.74223351, 0.12873557), vector3df(0, -89.195031, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.2299938, zCam + -0.74223351, 0.12913577), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.4139395, zCam + -0.74223351, 0.12913577), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.5821929, zCam + -0.74223351, 0.12913577), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.9517708, zCam + -0.74223351, 0.50988811), vector3df(0, -360.11711, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.5954318, zCam + -0.74223351, 0.36100814), vector3df(0, -99.694944, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.5832291, zCam + -0.74223351, 0.23348543), vector3df(0, -84.601059, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.4162011, zCam + -0.74223351, 0.23259747), vector3df(0, -81.953821, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.4151344, zCam + -0.74223351, 0.35540485), vector3df(0, -84.180907, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.4135251, zCam + -0.74223351, 0.47012183), vector3df(0, -95.20307, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.2299938, zCam + -0.74223351, 0.46737793), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.2308421, zCam + -0.74223351, 0.35657269), vector3df(0, -85.933759, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.2299938, zCam + -0.74223351, 0.23635818), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.0565634, zCam + -0.74223351, 0.23821299), vector3df(0, -93.86785, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.0565848, zCam + -0.74223351, 0.3601943), vector3df(0, -93.677854, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.0589957, zCam + -0.74223351, 0.46370301), vector3df(0, -83.398645, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/chaise.obj", 0, locTranslateVect);

/* ----- armoireAvecFond.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(8);

locTranslateVect.push_back(TTransform(vector3df(1.3654001, zCam + -0.77660382, 0.40501383), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.3654001, zCam + -0.77660382, 0.14887878), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.5347178, zCam + -0.77643669, 2.0397055), vector3df(0, -270, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.5347178, zCam + -0.77643669, 1.8315365), vector3df(0, -270, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.2651227, zCam + -0.77651376, -2.297992), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(2.2651227, zCam + -0.77630663, -2.0526409), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.8558993, zCam + -0.77691764, -1.0348847), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.0653174, zCam + -0.77691764, -1.4929875), vector3df(0, -89.999982, -0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/armoireAvecFond.obj", 0, locTranslateVect);

/* ----- radiateur.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(14);

locTranslateVect.push_back(TTransform(vector3df(1.3713065, zCam + -0.76816595, -0.23247251), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.21580669, zCam + -0.7650131, 1.2294997), vector3df(0, -180.00002, -0)));
locTranslateVect.push_back(TTransform(vector3df(-0.26995587, zCam + -0.7650131, 2.0762708), vector3df(0, -270, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.52882797, zCam + -0.7641654, 2.4749215), vector3df(0, -270, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.8064803, zCam + -0.76416546, -1.9713445), vector3df(0, -180.00002, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.3573239, zCam + -0.76416546, 1.1713092), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.3710722, zCam + -0.76416546, 1.6461607), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.4708027, zCam + -0.76416546, -1.5750815), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(2.4716985, zCam + -0.76416546, -0.036431231), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.7714379, zCam + -0.7641654, 0.17463064), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.4290388, zCam + -0.76716441, 1.1210614), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.6291456, zCam + -0.76543689, -0.87393862), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.2152262, zCam + -0.7641654, -0.57081497), vector3df(0, -180.00002, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.091465, zCam + -0.76633662, 0.57157087), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/radiateur.obj", 0, locTranslateVect);

/* ----- table.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(13);

locTranslateVect.push_back(TTransform(vector3df(1.1046183, zCam + -0.72598362, -0.51079434), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.1046183, zCam + -0.72598362, -0.38184837), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.089591451, zCam + -0.72590488, 2.0917675), vector3df(0, -40.324597, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.5509372, zCam + -0.72600269, -2.5168648), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.8980366, zCam + -0.72596127, -1.7201158), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.8980366, zCam + -0.72596127, -1.7814056), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.7315018, zCam + -0.72597671, -1.529338), vector3df(0, 15.716347, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.7149, zCam + -0.72597671, -1.4703395), vector3df(0, 15.716347, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.9568502, zCam + -0.72597671, -1.325217), vector3df(0, -12.847032, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.9432225, zCam + -0.72597671, -1.3849726), vector3df(0, -12.847032, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.7043879, zCam + -0.72596127, -1.2101573), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.7043879, zCam + -0.72619945, -1.1488675), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.8515279, zCam + -0.72588158, 0.30360642), vector3df(0, 89.999982, -0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/table.obj", 0, locTranslateVect);

/* ----- meubleAPied.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(4);

locTranslateVect.push_back(TTransform(vector3df(0.84406346, zCam + -0.76294714, -0.5317151), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.3534985, zCam + -0.76266992, -0.5317151), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.7018222, zCam + -0.76283878, -2.3074214), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.4457734, zCam + -0.76271439, 0.84956419), vector3df(0, -89.999982, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/meubleAPied.obj", 0, locTranslateVect);

/* ----- chauffeEau.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(3);

locTranslateVect.push_back(TTransform(vector3df(0.85563278, zCam + -0.73429316, -0.15573588), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.861064, zCam + -0.73456556, 0.6968509), vector3df(0, -15.428264, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.5316229, zCam + -0.73456556, 0.6968509), vector3df(0, -112.80044, -0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/chauffeEau.obj", 0, locTranslateVect);

/* ----- canapee.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(7);

locTranslateVect.push_back(TTransform(vector3df(1.3358476, zCam + -0.78193939, -0.42744875), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.86421031, zCam + -0.78205127, -0.30891633), vector3df(0, 89.999982, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.9432824, zCam + -0.78198195, -2.1715584), vector3df(0, 89.999982, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.8550738, zCam + -0.78198195, -2.2896514), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.8550738, zCam + -0.78218907, -2.4353867), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.9432824, zCam + -0.78198195, -2.3172936), vector3df(0, 89.999982, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.9235358, zCam + -0.78211278, -0.75852203), vector3df(0, -65.145361, -0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/canapee.obj", 0, locTranslateVect);

/* ----- bureau2.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(9);

locTranslateVect.push_back(TTransform(vector3df(-0.41876844, zCam + -0.75631797, 1.3160005), vector3df(0, 270, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.3996989, zCam + -0.75631797, 2.3671348), vector3df(0, 180.00002, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.80222386, zCam + -0.75631803, -2.1130607), vector3df(0, -135.93768, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.618426, zCam + -0.75631803, -1.8859192), vector3df(0, 0.2974224, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.5691798, zCam + -0.75596899, 1.2387459), vector3df(0, 234.14063, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.4677439, zCam + -0.75596899, 1.2516516), vector3df(0, 141.33213, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.7621672, zCam + -0.75613654, -1.1014658), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.7735896, zCam + -0.75631797, -0.4766584), vector3df(0, 86.178983, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.7733684, zCam + -0.75631797, 0.44503251), vector3df(0, 89.999982, -0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/bureau2.obj", 0, locTranslateVect);

/* ----- meubleLivre.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(3);

locTranslateVect.push_back(TTransform(vector3df(-0.24980783, zCam + -0.75339574, 1.8810576), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(2.0498884, zCam + -0.74039721, -1.1658218), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.6498957, zCam + -0.75328016, -1.3236117), vector3df(0, 89.999982, -0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/meubleLivre.obj", 0, locTranslateVect);

/* ----- extincteur.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(7);

locTranslateVect.push_back(TTransform(vector3df(1.4432421, zCam + -0.76941156, 1.8295554), vector3df(0, -180.00002, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.2708423, zCam + -0.76941162, 1.8410872), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.82867, zCam + -0.76941174, -0.64005309), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.3507576, zCam + -0.76941174, -0.13008553), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.471756, zCam + -0.76941174, -1.7079756), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(2.4713459, zCam + -0.76941162, 1.0918894), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.7718627, zCam + -0.76941156, -0.11823083), vector3df(0, -89.999982, -0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/extincteur.obj", 0, locTranslateVect);

/* ----- tabouret.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(48);

locTranslateVect.push_back(TTransform(vector3df(0.86167979, zCam + -0.77398437, 2.1336365), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.79876304, zCam + -0.77398437, 2.136863), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.86490631, zCam + -0.77386791, 2.3869166), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.80037642, zCam + -0.77386791, 2.382077), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.80360293, zCam + -0.77398437, 2.2352712), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.86006641, zCam + -0.77398437, 2.2320447), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.80198956, zCam + -0.77398437, 2.01103), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.86490631, zCam + -0.77398437, 2.0078034), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.86006641, zCam + -0.77398437, 1.9045556), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.7971499, zCam + -0.77398437, 1.9077818), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.86329293, zCam + -0.77398437, 2.4724185), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.80682945, zCam + -0.77398437, 2.4756453), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.060674, zCam + -0.77398437, 2.4756453), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.1171374, zCam + -0.77379823, 2.4724185), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.0509944, zCam + -0.77398437, 1.9077818), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.1139109, zCam + -0.77379823, 1.9045556), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.1187508, zCam + -0.77379823, 2.0078034), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.0558341, zCam + -0.77398437, 2.01103), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.1139109, zCam + -0.77379823, 2.2320447), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.0574474, zCam + -0.77398437, 2.2352712), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.0542209, zCam + -0.77386791, 2.382077), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.1187508, zCam + -0.77379823, 2.3869166), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.0526075, zCam + -0.77398437, 2.136863), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.1155243, zCam + -0.77379823, 2.1336365), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.7124257, zCam + -0.77392554, 2.1336365), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.649509, zCam + -0.77392554, 2.136863), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.7156522, zCam + -0.77377641, 2.3869166), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.6511223, zCam + -0.77377641, 2.382077), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.6543489, zCam + -0.77377641, 2.2352712), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.7108123, zCam + -0.77377641, 2.2320447), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.6527355, zCam + -0.77351123, 2.01103), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.7156522, zCam + -0.77351123, 2.0078034), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.7108123, zCam + -0.77361608, 1.9045556), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.6478958, zCam + -0.77361608, 1.9077818), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.7140388, zCam + -0.77365798, 2.4724185), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.6575754, zCam + -0.77365798, 2.4756453), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.9403775, zCam + -0.77365798, 2.4756453), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.9968408, zCam + -0.77365798, 2.4724185), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.9306979, zCam + -0.77361608, 1.9077818), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.9936144, zCam + -0.77361608, 1.9045556), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.9984542, zCam + -0.77351123, 2.0078034), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.9355376, zCam + -0.77351123, 2.01103), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.9936144, zCam + -0.77377641, 2.2320447), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.937151, zCam + -0.77377641, 2.2352712), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.9339244, zCam + -0.77377641, 2.382077), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.9984542, zCam + -0.77377641, 2.3869166), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.9323111, zCam + -0.77392554, 2.136863), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.9952277, zCam + -0.77392554, 2.1336365), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/tabouret.obj", 0, locTranslateVect);

/* ----- tableChimie.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(12);

locTranslateVect.push_back(TTransform(vector3df(0.82631969, zCam + -0.76477784, 2.1889522), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.83115935, zCam + -0.76477784, 2.4357793), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.82631969, zCam + -0.76477784, 1.9598713), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.0801642, zCam + -0.76477784, 1.9598713), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.0850039, zCam + -0.76477784, 2.4357793), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.0801642, zCam + -0.76477784, 2.1889522), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.6770656, zCam + -0.76516205, 2.1889522), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.6819053, zCam + -0.76492518, 2.4357793), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.6770656, zCam + -0.76471901, 1.9598713), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.9598677, zCam + -0.76471901, 1.9598713), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.9647074, zCam + -0.76492518, 2.4357793), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.9598677, zCam + -0.76516205, 2.1889522), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/tableChimie.obj", 0, locTranslateVect);

/* ----- ArmoireSsFond.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(20);

locTranslateVect.push_back(TTransform(vector3df(1.3176584, zCam + -0.77686465, -2.3833022), vector3df(0, -180.00002, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.3176574, zCam + -0.77686465, -2.354182), vector3df(0, -180.00002, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.1287354, zCam + -0.77686179, -2.3833003), vector3df(0, -180.00002, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.1287354, zCam + -0.77686179, -2.3544321), vector3df(0, -180.00002, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.73455453, zCam + -0.77687764, -2.401731), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.73464364, zCam + -0.77687764, -2.2127488), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.3717885, zCam + -0.77686465, -2.2196431), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.3429203, zCam + -0.77686465, -2.2196431), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.3429203, zCam + -0.77686465, -2.0306938), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.3717885, zCam + -0.77686465, -2.0306938), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.92415965, zCam + -0.77561682, -2.0306938), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(0.89529145, zCam + -0.77561682, -2.0306938), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(1.1169339, zCam + -0.77561682, -2.1654787), vector3df(0, -180.00002, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.1169339, zCam + -0.77561682, -2.1943469), vector3df(0, -180.00002, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.0145001, zCam + -0.77687562, 1.1607258), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.9100449, zCam + -0.77687562, 0.83439326), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.9856319, zCam + -0.77687562, 1.1607258), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.9063854, zCam + -0.77653319, 1.3650553), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.8357992, zCam + -0.77678329, -0.55408764), vector3df(0, 89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.8345921, zCam + -0.77683288, 0.055307798), vector3df(0, 89.999982, -0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/ArmoireSsFond.obj", 0, locTranslateVect);

/* ----- pupitre.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(16);

locTranslateVect.push_back(TTransform(vector3df(4.5059958, zCam + -0.75285757, 1.025914), vector3df(0, 178.83651, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.3083076, zCam + -0.75285757, 1.0981814), vector3df(0, 136.1209, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.5334299, zCam + -0.75285757, 0.99436527), vector3df(0, 194.09209, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.7048209, zCam + -0.75285757, 1.0934328), vector3df(0, 226.78643, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.2022872, zCam + -0.75285757, 1.2720549), vector3df(0, 93.753253, -0)));
locTranslateVect.push_back(TTransform(vector3df(3.7830617, zCam + -0.75285757, 1.2845317), vector3df(0, -89.507751, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.532433, zCam + -0.75268215, -1.3041095), vector3df(0, -270, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.2980165, zCam + -0.75263035, -0.87641311), vector3df(0, -93.191811, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.3110032, zCam + -0.75292033, -1.0879064), vector3df(0, -85.739925, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.2924509, zCam + -0.75268215, -1.2872413), vector3df(0, -92.208503, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.110641, zCam + -0.75268215, -1.2872413), vector3df(0, -87.772835, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.1087856, zCam + -0.75292033, -1.0860511), vector3df(0, -84.977491, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.1162066, zCam + -0.75263035, -0.87641311), vector3df(0, -82.806666, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.9566588, zCam + -0.75263035, -0.88568914), vector3df(0, -77.887994, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.9343965, zCam + -0.75292033, -1.0916167), vector3df(0, -79.479271, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.9418173, zCam + -0.75292033, -1.2872413), vector3df(0, -108.08832, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/pupitre.obj", 0, locTranslateVect);

/* ----- livreUnique.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(3.6601934, zCam + -0.73337936, -1.3245348), vector3df(-0, 89.999982, -39.295164)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/livreUnique.obj", 0, locTranslateVect);

/* ----- boiteALettre.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(4.7687135, zCam + -0.73853672, -0.02888516), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/boiteALettre.obj", 0, locTranslateVect);

/* ----- murS.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(95);

locTranslateVect.push_back(TTransform(vector3df(2.3000453, zCam + -0.79999995, -0.98000067), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.2000134, zCam + -0.79999983, -0.079999179), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.80001253, zCam + -0.79999983, -0.079999179), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.80001253, zCam + -0.79999983, 0.52000016), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.2000134, zCam + -0.79999983, 0.52000016), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.2000134, zCam + -0.79999983, -0.6799984), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.80001253, zCam + -0.79999983, -0.6799984), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(-0.19998656, zCam + -0.79999995, 1.2200001), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.3190179e-005, zCam + -0.79999995, 1.2200001), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(-0.59997398, zCam + -0.79999995, 1.2200001), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(-0.39998695, zCam + -0.79999995, 1.2200001), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.5000256, zCam + -0.79999995, 1.8199996), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.7000239, zCam + -0.79999995, 1.8199996), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.9000108, zCam + -0.79999995, 1.8199996), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.1000113, zCam + -0.79999995, 1.8199996), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.3190179e-005, zCam + -0.79999995, 1.8200037), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1, zCam + -0.79999995, 1.8200008), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.40000001, zCam + -0.79999995, 1.8200037), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.80001295, zCam + -0.79999995, 1.8200008), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.60001469, zCam + -0.79999995, 1.8200008), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.90001458, zCam + -0.79999995, 1.5199996), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.70001632, zCam + -0.79999995, 1.5199996), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.50001341, zCam + -0.79999995, 1.5199996), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.10002559, zCam + -0.79999995, -0.98000067), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.90001464, zCam + -0.79999995, -2.5799975), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.5000128, zCam + -0.79999995, -2.5799997), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.700016, zCam + -0.79999995, -2.5799997), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.70001572, zCam + -0.79999995, -2.5799975), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.3, zCam + -0.79999995, -2.5799975), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.1000168, zCam + -0.79999995, -2.5799997), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.5000128, zCam + -0.79999995, -1.9799988), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.700011, zCam + -0.79999995, -1.9799988), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.300028, zCam + -0.79999995, -1.9799966), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.69999856, zCam + -0.79999995, -1.9799966), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.3, zCam + -0.79999995, -1.9799966), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.1000135, zCam + -0.79999995, -1.9799966), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.49999854, zCam + -0.79999995, -1.9799966), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(-0.79998326, zCam + -0.79999995, -0.98000067), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(-0.39999899, zCam + -0.79999995, -0.98000067), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(-0.19998227, zCam + -0.79999995, -0.98000067), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.5986385e-005, zCam + -0.79999995, -0.98000067), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(-0.59999907, zCam + -0.79999995, -0.98000067), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.60001564, zCam + -0.79999995, -0.98000067), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.0000141, zCam + -0.79999995, -0.98000067), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.5000129, zCam + -0.79999995, -0.98000067), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.1000142, zCam + -0.79999995, -0.98000067), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.900016, zCam + -0.79999995, -0.98000067), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.6999992, zCam + -0.79999995, -0.98000067), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(-0.80000085, zCam + -0.79999995, 0.9200018), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(-0.600003, zCam + -0.79999995, 0.9200018), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(-0.1999862, zCam + -0.79999995, 0.9200018), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(-0.40000302, zCam + -0.79999995, 0.9200018), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.39999789, zCam + -0.79999995, 0.9200018), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.60001469, zCam + -0.79999995, 0.9200018), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.80001295, zCam + -0.79999995, 0.9200018), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.19999784, zCam + -0.79999995, 0.9200018), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.2858967e-005, zCam + -0.79999995, 0.9200018), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.2000009, zCam + -0.79999995, 0.9200018), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.4000007, zCam + -0.79999995, 0.9200018), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.0000157, zCam + -0.79999995, 0.9200018), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.8000175, zCam + -0.79999995, 0.9200018), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.6000007, zCam + -0.79999995, 0.9200018), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.4000137, zCam + -0.79999995, -0.57999933), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.2000139, zCam + -0.79999995, -0.57999933), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.8000145, zCam + -0.79999995, -0.57999933), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.3000147, zCam + -0.79999995, 0.31999955), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.9000149, zCam + -0.79999995, 0.31999955), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.1000149, zCam + -0.79999995, 0.31999955), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.7000155, zCam + -0.79999995, 0.31999955), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.5000157, zCam + -0.79999995, 0.31999955), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.4000113, zCam + -0.79999995, 0.61999923), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.8000157, zCam + -0.79999995, 0.82000053), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.0000143, zCam + -0.79999995, 0.82000053), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.400013, zCam + -0.79999995, 0.82000053), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.400013, zCam + -0.79999995, 0.62000197), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.0000143, zCam + -0.79999995, 0.62000197), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.8000157, zCam + -0.79999995, 0.62000197), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.5999999, zCam + -0.79999995, -1.379999), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.400013, zCam + -0.79999995, -1.379999), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.2000155, zCam + -0.79999995, -0.77999866), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.0000143, zCam + -0.79999995, -1.379999), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.6000113, zCam + -0.79999995, -0.77999866), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.8000116, zCam + -0.79999995, -0.77999866), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.0000143, zCam + -0.79999995, -0.77999866), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.8000157, zCam + -0.79999995, -0.77999866), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.2000155, zCam + -0.79999995, -0.58000004), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.8000157, zCam + -0.79999995, -0.58000004), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.0000157, zCam + -0.79999995, -0.58000004), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.8000116, zCam + -0.79999995, -0.58000004), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.6000113, zCam + -0.79999995, -0.58000004), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.6000113, zCam + -0.79999995, 0.020001207), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.400013, zCam + -0.79999995, 0.020001207), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.0000157, zCam + -0.79999995, 0.020001207), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.8000157, zCam + -0.79999995, 0.020001207), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.2000155, zCam + -0.79999995, 0.020001207), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/murS.obj", 0, locTranslateVect);

/* ----- fenetre.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(10);

locTranslateVect.push_back(TTransform(vector3df(1.199561, zCam + -0.80000001, -2.5923367), vector3df(0, -180.00002, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.9995602, zCam + -0.80000001, -2.5923362), vector3df(0, -180.00002, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.000441, zCam + -0.80000001, 2.5923607), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.8004425, zCam + -0.80000001, 2.5923598), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.7004406, zCam + -0.79999995, 1.3923608), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.3004441, zCam + -0.79999995, 1.3923599), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.8995624, zCam + -0.79999995, -1.3923353), vector3df(0, -180.00002, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.2995629, zCam + -0.79999995, -1.3923354), vector3df(0, -180.00002, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.5923605, zCam + -0.79999995, -1.100439), vector3df(0, -89.999982, -0)));
locTranslateVect.push_back(TTransform(vector3df(4.7004423, zCam + -0.79999995, 0.59236026), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/fenetre.obj", 0, locTranslateVect);

/* ----- coinNO.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(5);

locTranslateVect.push_back(TTransform(vector3df(3.7764554, zCam + -0.79999995, 1.0199361), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.4764566, zCam + -0.79999995, -0.38006309), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.47645515, zCam + -0.79999995, 1.7199376), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.57645595, zCam + -0.79999995, -0.78006291), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.4764543, zCam + -0.79999995, 0.5199362), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/coinNO.obj", 0, locTranslateVect);

/* ----- murLightHori.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(5);

locTranslateVect.push_back(TTransform(vector3df(2.4000294, zCam + -0.79999989, 0.57999903), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.4000297, zCam + -0.79999995, -0.57999974), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.2999793, zCam + -0.79999995, 1.8200017), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(-0.39998972, zCam + -0.79999995, 1.8200017), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.300015, zCam + -0.79999995, 1.1799997), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/murLightHori.obj", 0, locTranslateVect);

/* ----- coinBG.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(6);

locTranslateVect.push_back(TTransform(vector3df(2.4960413, zCam + -0.79999626, 0.8003211), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.49603599, zCam + -0.79999995, 1.4003221), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.3960413, zCam + -0.79999995, 1.400323), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.59604007, zCam + -0.79999995, -1.399676), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.4960399, zCam + -0.79999995, -0.099677913), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.7800157, zCam + -0.79999995, -0.60000002), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/coinBG.obj", 0, locTranslateVect);

/* ----- murE.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(62);

locTranslateVect.push_back(TTransform(vector3df(2.4800158, zCam + -0.79999995, -0.79999936), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.4800158, zCam + -0.79999995, -0.59999931), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.7800136, zCam + -0.79999995, 0.79999948), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.3800144, zCam + -0.79999995, -0.30000177), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.3800144, zCam + -0.79999995, -0.50000179), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.3800144, zCam + -0.79999995, 0.89999938), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.3800144, zCam + -0.79999995, 0.69999933), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.3800144, zCam + -0.79999995, 0.49999931), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.3800144, zCam + -0.79999995, -0.1000016), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.3800144, zCam + -0.79999995, 0.0999984), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.3800144, zCam + -0.79999995, 0.29999843), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.18001395, zCam + -0.79999995, 1.4000028), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.18001491, zCam + -0.79999995, 1.7999998), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.48001564, zCam + -0.79999995, 2.0000012), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.48001659, zCam + -0.79999995, 2.2000101), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.2800159, zCam + -0.79999995, 2.5991499), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.2800159, zCam + -0.79999995, 2.1991482), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.2800159, zCam + -0.79999995, 2.3991477), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.280015, zCam + -0.79999995, 2.0000012), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.48001394, zCam + -0.79999995, 1.4000013), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.3800159, zCam + -0.79999995, 1.4000028), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.3800168, zCam + -0.79999995, 1.7991498), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.4800154, zCam + -0.79999989, -2.1999981), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.4800154, zCam + -0.79999989, -2.4000001), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.2800133, zCam + -0.79999989, -2.1999981), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.2800133, zCam + -0.79999989, -1.9999992), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.2800133, zCam + -0.79999989, -2.4000001), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.0800149, zCam + -0.79999989, -1.7999985), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.0800149, zCam + -0.79999989, -1.5999997), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.0800149, zCam + -0.79999989, -1.1999989), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.0800149, zCam + -0.79999989, -1.3999977), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.0800149, zCam + -0.79999989, -1.0000013), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.58001429, zCam + -0.79999995, -1.1999769), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.58001429, zCam + -0.79999995, -1.3999983), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.58001429, zCam + -0.79999995, -1.0000002), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.4800149, zCam + -0.79999995, -1.7999986), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.4800149, zCam + -0.79999995, -1.4000012), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.4800149, zCam + -0.79999995, -1.6), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.4800149, zCam + -0.79999995, -1.0000013), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.4800169, zCam + -0.79999995, 1.0000001), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.4800169, zCam + -0.79999995, 1.2000002), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.480016, zCam + -0.79999995, 0.79999948), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.4800158, zCam + -0.79999995, 0.29999843), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.4800158, zCam + -0.79999995, -0.1000016), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.7800114, zCam + -0.79999995, -0.40000135), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.7800124, zCam + -0.79999995, 0.40000001), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.7800124, zCam + -0.79999995, 0.2), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.7800124, zCam + -0.79999995, 0), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.5800166, zCam + -0.79999995, 1.0000001), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.5800166, zCam + -0.79999995, 1.2000002), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.5800166, zCam + -0.79999995, 1.4000002), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.5800157, zCam + -0.79999995, 0.79999948), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.7800157, zCam + -0.79999995, -0.60000002), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.5800161, zCam + -0.79999995, -1.2), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.5800147, zCam + -0.79999995, -0.80000001), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.9800134, zCam + -0.79999995, -0.60000002), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.9800134, zCam + -0.79999995, -0.39999923), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.9800158, zCam + -0.79999995, -0.19999923), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.9800134, zCam + -0.79999995, 0), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.9800134, zCam + -0.79999995, 0.60000008), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.9800134, zCam + -0.79999995, 0.40000001), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(4.9800134, zCam + -0.79999995, 0.2), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/murE.obj", 0, locTranslateVect);

/* ----- coinNE.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(5);

locTranslateVect.push_back(TTransform(vector3df(2.1999986, zCam + -0.79999995, 1.1201851), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.099997, zCam + -0.79999995, 1.720185), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(0.29999673, zCam + -0.79999995, -0.77981633), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.1999942, zCam + -0.79999995, -0.77981633), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.4999964, zCam + -0.79999995, 0.52018452), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/coinNE.obj", 0, locTranslateVect);

/* ----- coinSE.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(5);

locTranslateVect.push_back(TTransform(vector3df(0.21983807, zCam + -0.80000007, 1.4003278), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.1198311, zCam + -0.80000007, 1.4003278), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(2.2198291, zCam + -0.80000001, -0.49967524), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.2198237, zCam + -0.80000001, -1.3996768), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(3.5198274, zCam + -0.79999995, -0.099677913), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/coinSE.obj", 0, locTranslateVect);

/* ----- murLightVerti.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(2);

locTranslateVect.push_back(TTransform(vector3df(0.48001394, zCam + -0.79999995, 1.6000013), vector3df(0, 0, 0)));
locTranslateVect.push_back(TTransform(vector3df(1.1200151, zCam + -0.79999995, 1.6000013), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/murLightVerti.obj", 0, locTranslateVect);

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

locTranslateVect.push_back(TTransform(vector3df(-0.69800001, zCam + -0.59997469, 1.8099999), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n2.obj", 0, locTranslateVect);

/* ----- n1.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(-1.109, zCam + -0.59997648, 1.101), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n1.obj", 0, locTranslateVect);

/* ----- n41.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(-0.84999132, zCam + -0.59997612, -1.1009693), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n41.obj", 0, locTranslateVect);

/* ----- n40.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(-0.55268955, zCam + -0.59997559, -1.719992), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n40.obj", 0, locTranslateVect);

/* ----- n46.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(0.20411956, zCam + -0.59997612, -2.3828812), vector3df(0, 0, 0)));

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

locTranslateVect.push_back(TTransform(vector3df(-0.15099999, zCam + -0.5999763, 2.7809999), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n4.obj", 0, locTranslateVect);

/* ----- n3.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(-0.43099999, zCam + -0.60000002, 2.221), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n3.obj", 0, locTranslateVect);

/* ----- n5.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(1.4490454, zCam + -0.59997654, 2.9805713), vector3df(0, 0, 0)));

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

locTranslateVect.push_back(TTransform(vector3df(0.01026361, zCam + -0.5999763, 0.099999472), vector3df(0, 0, 0)));

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

locTranslateVect.push_back(TTransform(vector3df(-0.40658981, zCam + -0.59997654, 1.8000038), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n7.obj", 0, locTranslateVect);

/* ----- n8.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(0.10203838, zCam + -0.59997654, 1.8000038), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n8.obj", 0, locTranslateVect);

/* ----- n10.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(-0.30999637, zCam + -0.59997392, 1.2000099), vector3df(0, 0, 0)));

FMap->AddMeshResource("ms0:/PSP/GAME/Hide-And-Seek/Mesh/final/n10.obj", 0, locTranslateVect);

/* ----- n30.obj ----- */
locTranslateVect.clear();
locTranslateVect.reallocate(1);

locTranslateVect.push_back(TTransform(vector3df(0.094200253, zCam + -0.59997392, 0.89999795), vector3df(0, 0, 0)));

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
