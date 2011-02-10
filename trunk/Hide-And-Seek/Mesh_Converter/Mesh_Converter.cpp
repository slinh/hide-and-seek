// Mesh_Converter.cpp : main project file.

#include "stdafx.h"
#include "Converter.h"
#include <engineArray.h>

using namespace System;

#define WIDTH 512.f
#define HEIGHT 512.f

int main(array<System::String ^> ^args)
{
	c8 buf[64];

	psp::TMeshConverter locConverter;

	// Try to load MD2 model
//*
	/*printf("Convert 1\n");
	locConverter.LoadMD2("Mesh/victime.md2");
	locConverter.SaveMD2("Mesh2/victime.md2", 128.f/WIDTH, 0.f, 128.f/WIDTH, 128.f/HEIGHT);
	printf("\n");*/
//*/
//*
	/*printf("Convert 2\n");
	locConverter.LoadMD2("Mesh2/victime.md2");
	locConverter.SaveMD2("Mesh2/victime2.md2", 128.f/WIDTH, 0.f, 128.f/WIDTH, 128.f/HEIGHT);
	printf("\n");
//*/
/*
	locConverter.LoadOBJ("Mesh/radiateur.obj");
	locConverter.SaveOBJ("Mesh2/radiateur.obj",64.f/WIDTH, 256.f/HEIGHT, 64/WIDTH, 64/HEIGHT);

	locConverter.LoadOBJ("Mesh/pupitre.obj");
	locConverter.SaveOBJ("Mesh2/pupitre.obj",0/WIDTH, 256/HEIGHT, 64/WIDTH, 64/HEIGHT);
	//*/
	locConverter.LoadOBJ("Mesh/sol.obj");
	locConverter.SaveOBJ("Mesh2/sol.obj",64.f/WIDTH, 384.f/HEIGHT, 128/WIDTH, 128/HEIGHT);

	
	for(u32 i=1; i<=13; ++i)
	{
		sprintf(buf, "Mesh/sol%d.obj", i);
		locConverter.LoadOBJ(buf);
		sprintf(buf, "Mesh2/sol%d.obj", i);
		locConverter.SaveOBJ(buf,64.f/WIDTH, 384.f/HEIGHT, 128/WIDTH, 128/HEIGHT);
	}
		for(u32 i=15; i<=23; ++i)
	{
		sprintf(buf, "Mesh/sol%d.obj", i);
		locConverter.LoadOBJ(buf);
		sprintf(buf, "Mesh2/sol%d.obj", i);
		locConverter.SaveOBJ(buf,64.f/WIDTH, 384.f/HEIGHT, 128/WIDTH, 128/HEIGHT);
	}

/*
	for(u32 i=1; i<=79; ++i)
	{
		sprintf(buf, "Mesh/n%d.obj", i);
		locConverter.LoadOBJ(buf);
		sprintf(buf, "Mesh2/n%d.obj", i);
		locConverter.SaveOBJ(buf,450/WIDTH, 10/HEIGHT, 1/WIDTH, 1/HEIGHT);
	}

	for(u32 i=81; i<=84; ++i)
	{
		sprintf(buf, "Mesh/n%d.obj", i);
		locConverter.LoadOBJ(buf);
		sprintf(buf, "Mesh2/n%d.obj", i);
		locConverter.SaveOBJ(buf,450/WIDTH, 10/HEIGHT, 1/WIDTH, 1/HEIGHT);
	}
	
	
	
	locConverter.LoadOBJ("Mesh/livreUnique.obj");
	locConverter.SaveOBJ("Mesh2/livreUnique.obj",320/WIDTH, 480/HEIGHT, 32/WIDTH, 32/HEIGHT);
	
	locConverter.LoadOBJ("Mesh/table.obj");
	locConverter.SaveOBJ("Mesh2/table.obj",0/WIDTH, 384/HEIGHT, 64/WIDTH, 64/HEIGHT);
	/*
	locConverter.LoadOBJ("Mesh/canapee.obj");
	locConverter.SaveOBJ("Mesh2/canapee.obj",256/WIDTH, 256/HEIGHT, 64/WIDTH, 64/HEIGHT);
	/*
	locConverter.LoadOBJ("Mesh/tableCarre3.obj");
	locConverter.SaveOBJ("Mesh2/tableCarre3.obj",128/WIDTH, 256/HEIGHT, 64/WIDTH, 64/HEIGHT);
	
	locConverter.LoadOBJ("Mesh/armoireAvecfond.obj");
	locConverter.SaveOBJ("Mesh2/armoireAvecfond.obj",192/WIDTH, 320/HEIGHT, 64/WIDTH, 64/HEIGHT);
	/*locConverter.LoadOBJ("Mesh/ArmoirePharmacie.obj");
	
	locConverter.SaveOBJ("Mesh2/ArmoirePharmacie.obj",256/WIDTH, 320/HEIGHT, 64/WIDTH, 64/HEIGHT);
	//
	locConverter.LoadOBJ("Mesh/ArmoireSsFond.obj");
	locConverter.SaveOBJ("Mesh2/ArmoireSsFond.obj",448/WIDTH, 384/HEIGHT, 64/WIDTH, 64/HEIGHT);
	
	locConverter.LoadOBJ("Mesh/quad_BlackBoardSa.obj");
	locConverter.SaveOBJ("Mesh2/quad_BlackBoardSa.obj",384/WIDTH, 448/HEIGHT, 128/WIDTH, 64/HEIGHT);
	
	locConverter.LoadOBJ("Mesh/armature.obj");
	locConverter.SaveOBJ("Mesh2/armature.obj",384/WIDTH, 0/HEIGHT, 128/WIDTH, 128/HEIGHT);
	/*
	locConverter.LoadOBJ("Mesh/quad_Religieuse.obj");
	locConverter.SaveOBJ("Mesh2/quad_Religieuse.obj",448/WIDTH, 321/HEIGHT, 32/WIDTH, 32/HEIGHT);

	locConverter.LoadOBJ("Mesh/pSecret.obj");
	locConverter.SaveOBJ("Mesh2/pSecret.obj",128/WIDTH, 128/HEIGHT, 128/WIDTH, 128/HEIGHT);
	/*
	locConverter.LoadOBJ("Mesh/boiteALettre.obj");
	locConverter.SaveOBJ("Mesh2/boiteALettre.obj",384/WIDTH, 320/HEIGHT, 32/WIDTH, 32/HEIGHT);

	locConverter.LoadOBJ("Mesh/Bouteille.obj");
	locConverter.SaveOBJ("Mesh2/Bouteille.obj",384/WIDTH, 352/HEIGHT, 32/WIDTH,32/HEIGHT);
	
	locConverter.LoadOBJ("Mesh/Bureau2.obj");
	locConverter.SaveOBJ("Mesh2/Bureau2.obj",0/WIDTH, 448/HEIGHT, 64/WIDTH, 64/HEIGHT);
	locConverter.LoadOBJ("Mesh/caisse.obj");
	locConverter.SaveOBJ("Mesh2/caisse.obj",64/WIDTH, 320/HEIGHT, 64/WIDTH, 64/HEIGHT);
	
	locConverter.LoadOBJ("Mesh/casier.obj");
	locConverter.SaveOBJ("Mesh2/casier.obj",0/WIDTH, 320/HEIGHT, 64/WIDTH, 64/HEIGHT);
	
	locConverter.LoadOBJ("Mesh/chaise.obj");
	locConverter.SaveOBJ("Mesh2/chaise.obj",320/WIDTH, 448/HEIGHT, 32/WIDTH, 32/HEIGHT);
	
	locConverter.LoadOBJ("Mesh/chauffeEau.obj");
	locConverter.SaveOBJ("Mesh2/chauffeEau.obj",192/WIDTH, 256/HEIGHT, 64/WIDTH, 64/HEIGHT);
	
	

	locConverter.LoadOBJ("Mesh/quadInfoTableau.obj");
	locConverter.SaveOBJ("Mesh2/quadInfoTableau.obj",192/WIDTH, 448/HEIGHT, 128/WIDTH, 64/HEIGHT);

	locConverter.LoadOBJ("Mesh/plante.obj");
	locConverter.SaveOBJ("Mesh2/plante.obj",384/WIDTH, 384/HEIGHT, 64/WIDTH, 64/HEIGHT);
	
	locConverter.LoadOBJ("Mesh/quadDessin.obj");
	locConverter.SaveOBJ("Mesh2/quadDessin.obj",384/WIDTH, 256/HEIGHT, 128/WIDTH, 64/HEIGHT);

	locConverter.LoadOBJ("Mesh/livresBleus.obj");
	locConverter.SaveOBJ("Mesh2/livresBleus.obj",320/WIDTH, 416/HEIGHT, 32/WIDTH, 32/HEIGHT);

	locConverter.LoadOBJ("Mesh/livresRouges.obj");
	locConverter.SaveOBJ("Mesh2/livresRouges.obj",352/WIDTH, 384/HEIGHT, 32/WIDTH, 32/HEIGHT);

	locConverter.LoadOBJ("Mesh/livresAllsMulti.obj");
	locConverter.SaveOBJ("Mesh2/livresAllsMulti.obj",352/WIDTH, 416/HEIGHT, 32/WIDTH, 32/HEIGHT);

	locConverter.LoadOBJ("Mesh/livresAlls.obj");
	locConverter.SaveOBJ("Mesh2/livresAlls.obj",320/WIDTH, 384/HEIGHT, 32/WIDTH, 32/HEIGHT);

	/*
	locConverter.LoadOBJ("Mesh/corbeille.obj");
	locConverter.SaveOBJ("Mesh2/corbeille.obj",416/WIDTH, 352/HEIGHT, 32/WIDTH, 32/HEIGHT);
	locConverter.LoadOBJ("Mesh/cylindre.obj");
	locConverter.SaveOBJ("Mesh2/cylindre.obj",416/WIDTH, 320/HEIGHT, 32/WIDTH, 32/HEIGHT);
	
	locConverter.LoadOBJ("Mesh/escalier.obj");
	locConverter.SaveOBJ("Mesh2/escalier.obj",384/WIDTH, 128/HEIGHT, 128/WIDTH, 128/HEIGHT);
	
	locConverter.LoadOBJ("Mesh/estrade.obj");
	locConverter.SaveOBJ("Mesh2/estrade.obj",320/WIDTH, 256/HEIGHT, 64/WIDTH, 64/HEIGHT);
	locConverter.LoadOBJ("Mesh/extincteur.obj");
	locConverter.SaveOBJ("Mesh2/extincteur.obj",352/WIDTH, 448/HEIGHT, 32/WIDTH, 32/HEIGHT);
	locConverter.LoadOBJ("Mesh/faussePorte.obj");
	locConverter.SaveOBJ("Mesh2/faussePorte.obj",0/WIDTH, 128/HEIGHT, 128/WIDTH, 128/HEIGHT);
	locConverter.LoadOBJ("Mesh/fenetre.obj");
	locConverter.SaveOBJ("Mesh2/fenetre.obj",256/WIDTH, 128/HEIGHT, 128/WIDTH, 128/HEIGHT);
	locConverter.LoadOBJ("Mesh/meubleLivre.obj");
	locConverter.SaveOBJ("Mesh2/meubleLivre.obj",128/WIDTH, 320/HEIGHT, 64/WIDTH, 64/HEIGHT);
	locConverter.LoadOBJ("Mesh/murN.obj");
	locConverter.SaveOBJ("Mesh2/murN.obj",256/WIDTH, 0/HEIGHT, 128/WIDTH, 128/HEIGHT);
	locConverter.LoadOBJ("Mesh/murS.obj");
	locConverter.SaveOBJ("Mesh2/murS.obj",256/WIDTH, 0/HEIGHT, 128/WIDTH, 128/HEIGHT);
	locConverter.LoadOBJ("Mesh/murE.obj");
	locConverter.SaveOBJ("Mesh2/murE.obj",256/WIDTH, 0/HEIGHT, 128/WIDTH, 128/HEIGHT);
	locConverter.LoadOBJ("Mesh/murO.obj");
	locConverter.SaveOBJ("Mesh2/murO.obj",256/WIDTH, 0/HEIGHT, 128/WIDTH, 128/HEIGHT);
	locConverter.LoadOBJ("Mesh/coinBG.obj");
	locConverter.SaveOBJ("Mesh2/coinBG.obj",256/WIDTH, 0/HEIGHT, 36/WIDTH, 128/HEIGHT);
	locConverter.LoadOBJ("Mesh/coinNO.obj");
	locConverter.SaveOBJ("Mesh2/coinNO.obj",256/WIDTH, 0/HEIGHT, 36/WIDTH, 128/HEIGHT);
	locConverter.LoadOBJ("Mesh/coinNE.obj");
	locConverter.SaveOBJ("Mesh2/coinNE.obj",256/WIDTH, 0/HEIGHT, 36/WIDTH, 128/HEIGHT);
	locConverter.LoadOBJ("Mesh/coinSE.obj");
	locConverter.SaveOBJ("Mesh2/coinSE.obj",256/WIDTH, 0/HEIGHT, 36/WIDTH, 128/HEIGHT);
	locConverter.LoadOBJ("Mesh/murLightVerti.obj");
	locConverter.SaveOBJ("Mesh2/murLightVerti.obj",256/WIDTH, 0/HEIGHT, 64/WIDTH, 128/HEIGHT);
	locConverter.LoadOBJ("Mesh/murLightHori.obj");
	locConverter.SaveOBJ("Mesh2/murLightHori.obj",256/WIDTH, 0/HEIGHT, 64/WIDTH, 128/HEIGHT);
	*/
	locConverter.LoadOBJ("Mesh/boiteVide.obj");
	locConverter.SaveOBJ("Mesh2/boiteVide.obj",384/WIDTH, 256/HEIGHT, 64/WIDTH, 64/HEIGHT);
	/*
	locConverter.LoadOBJ("Mesh/meubleBasRepet.obj");
	locConverter.SaveOBJ("Mesh2/meubleBasRepet.obj",192/WIDTH, 384/HEIGHT, 64/WIDTH, 64/HEIGHT);
	locConverter.LoadOBJ("Mesh/porteLivre.obj");
	locConverter.SaveOBJ("Mesh2/porteLivre.obj",480/WIDTH, 352/HEIGHT, 32/WIDTH, 32/HEIGHT);
	locConverter.LoadOBJ("Mesh/tableChimie.obj");
	locConverter.SaveOBJ("Mesh2/tableChimie.obj",480/WIDTH, 320/HEIGHT, 32/WIDTH, 32/HEIGHT);
	locConverter.LoadOBJ("Mesh/tabouret.obj");
	locConverter.SaveOBJ("Mesh2/tabouret.obj",448/WIDTH, 352/HEIGHT, 32/WIDTH, 32/HEIGHT);
	
	locConverter.LoadOBJ("Mesh/meubleAPied.obj");
	locConverter.SaveOBJ("Mesh2/meubleAPied.obj",256/WIDTH, 384/HEIGHT, 64/WIDTH, 64/HEIGHT);
	locConverter.LoadOBJ("Mesh/duoLivre.obj");
	locConverter.SaveOBJ("Mesh2/duoLivre.obj",352/WIDTH, 480/HEIGHT, 32/WIDTH, 32/HEIGHT);
//*/
/*
	locConverter.LoadOBJ("Mesh/livreGroupeCube.obj");
	locConverter.SaveOBJ("Mesh2/livreGroupeCube.obj",320/WIDTH, 385/HEIGHT, 32/WIDTH, 32/HEIGHT);
//*/
	system("pause");

    return 0;
}
