/*****************************************
**		IMPORTANT		**
*****************************************/

INSTALLATION LINUX:

Allez dans le dossier build, tapez la commande : "cmake .." , un Makefile va être compilé.
Pour lancer le programme, entrez "make" puis ./gods_of_speed

Pensez à bien supprimer le contenu du dossier build avant de push afin d'éviter les problèmes de merge. SAUF L'INSTALLEUR WINDOWS

INSTALLATION WINDOWS:

Pour recompiler :
	cd build
	cmake .. -G "Visual Studio 15 2017 Win64"
	Aller build sur Visual Studio avec le .sln généré, choisir le build Release
	Ouvrir la solution générée, build et enjoy ;)

Pour installer et profiter simplement, suivre l'installeur et lancer gos.exe
