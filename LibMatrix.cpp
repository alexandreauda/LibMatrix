#include "LibMatrix.h"

using namespace std;

/******IMPLEMENTATION DES METHODES******/

/*
@description:
La methode readMatrix prend une matrice 12*12 en parametre qui va etre lue et affichee sur la console.
La matrice en parametre est modifiee par la methode car elle est passee par reference.
Note: Cete methode est particulierement utile pour le debogage.

@param: La methode readMatrix prend 1 parametre obligatoire: une matrice statique de int 12*12.
-param1: une matrice de int 12*12 qui va etre lue et affichee sur la console.
*/
void LibMatrix::readMatrix(int matrix[12][12]) {
    vector <int> v;
    //on parcourt la matrice passee en parametre
        for(int y=0;y<12;y++){
            for(int x=0;x<12;x++){
				v.push_back(matrix[y][x]);//on met les nombres lus dans un vecteur
            }
        }
    for(unsigned k=0;k<v.size();k++){
                if(k%12==0 && k!=0){
                    cout<<endl<<v[k];
                }
                else{
                    cout<<v[k];
                }
            }
}


/*
@description:
La methode identity prend une matrice 12*12 prise en parametre et modifie ses coefficients pour la transformer en matrice identite de meme dimension.
La matrice en parametre est modifiee par la methode car elle est passee par reference.

@param: La methode identity prend 1 parametre obligatoire: une matrice statique de int 12*12.
-param1: une matrice de int 12*12 qui va etre modifiee pour donner la matrice identite de meme dimension.
*/
void LibMatrix::identity(int matrix[12][12]) {
   //on parcourt la matrice passee en parametre
        for(int y=0;y<12;y++){
            for(int x=0;x<12;x++){
                if(y==x){   //Sur la diagonnal, on initialise les coefficients a 1
				matrix[y][x]=1;
                }
                else{   //Pour tout les autres coefficients, on initialise ces derniers a 0
                matrix[y][x]=0;
                }
            }
        }
}

/*
@description:
La methode axialSymmetryIdentity prend une matrice 12*12 prise en parametre et modifie ses coefficients pour la transformer en le symetrique de la matrice identite par rapport a l'axe vertical.
La matrice en parametre est modifiee par la methode car elle est passee par reference.

@param: La methode axialSymmetryIdentity prend 1 parametre obligatoire: une matrice statique de int 12*12.
-param1: une matrice de int 12*12 qui va etre modifiee pour donner le symetrique de la matrice identite par rapport a l'axe vertical.
*/
void LibMatrix::axialSymmetryIdentity(int matrix[12][12]) {
//on parcourt la matrice passee en parametre
        for(int y=0;y<12;y++){
            for(int x=0;x<12;x++){
                    if(y==11-x){
                        matrix[y][x]=1;
                    }
                    else{
                        matrix[y][x]=0;
                    }
            }
        }
}


/*
@description:
La methode transpose permet de transpose une matrice prise en parametre.
La matrice en parametre est modifiee par la methode car elle est passee par reference.

@param: La methode transpose prend 1 parametre obligatoire: une matrice statique de int 12*12.
-param1: une matrice de int 12*12 qui va etre modifiee pour donner la transpose de cette matrice.
*/
void LibMatrix::transpose(int matrix[12][12]) {
int stockMatrix[12][12];
//on parcourt la matrice passee en parametre
    for(int y=0;y<12;y++){
        for(int x=0;x<12;x++){

				stockMatrix[y][x]=matrix[x][y];//on transpose la matrice
        }
    }

//on parcourt la matrice passee en parametre
        for(int y=0;y<12;y++){
            for(int x=0;x<12;x++){

				matrix[x][y]=stockMatrix[x][y];//on transpose la matrice
            }
        }
}


/*
@description:
La methode matrixCopy prend deux matrices 12*12 en parametre et initialise la premiere matrice avec les coefficients de la deuxieme matrice.
La matrice en parametre est modifiee par la methode car elle est passee par reference.

@param: La methode matrixCopy prend 2 parametres obligatoires: 1 matrice statique de int 12*12, 1 matrice statique de int 12*12.
-param1: une matrice de int 12*12 qui va etre initialise avec les coefficients de la matrice param2.
-param2: une matrice de int 12*12 qui va etre lue pour initialise la matrice param1 avec les coefficients de param2.
*/
void LibMatrix::matrixCopy(int matrix[12][12], int matrix1[12][12]) {
//on parcourt la matrice passee en parametre
        for(int y=0;y<12;y++){
            for(int x=0;x<12;x++){

				matrix[x][y]=matrix1[x][y];//on transpose la matrice
            }
        }
}



/*
@description:
La methode matrixProduct prend trois matrices 12*12 en parametre, effectue le produit matriciel entre les deux matrices et initialise la troisieme matrice avec les coefficients de la matrice produit.
La matrice en parametre est modifiee par la methode car elle est passee par reference.

@param: La methode matrixProduct prend 3 parametres obligatoires: 1 matrice statique de int 12*12, 1 matrice statique de int 12*12, 1 matrice statique de int 12*12.
-param1: une matrice de int 12*12 qui va etre initialise avec les coefficients de la matrice produit param2*param3.
-param2: une matrice de int 12*12 qui va etre servir a faire le produit param2*param3.
-param3: une matrice de int 12*12 qui va etre servir a faire le produit param2*param3.
*/
void LibMatrix::matrixProduct(int matrixproduct[12][12], int matrix1[12][12], int matrix2[12][12]) {
//on parcourt la matrice passee en parametre
    int c=0;
    for(int x=0;x<12;x++){
        for(int y=0;y<12;y++){

                  for(int k=0;k<12;k++){
                      c+=matrix1[x][k]*matrix2[k][y];
                  }

                matrixproduct[x][y]=c;
                c=0;
            }
        }
}

/*
@description:
La methode matrixRot90 prend une matrices 12*12 en parametre et effectue une rotation de la matrice de 90° dans le sens horaire.
La matrice en parametre est modifiee par la methode car elle est passee par reference.

@param: La methode matrixRot90 prend 1 parametre obligatoire: 1 matrice statique de int 12*12.
-param1: une matrice de int 12*12 qui va etre transforme en sa rotation de 90° dans le sens horaire.
*/
void LibMatrix::matrixRot90(int matrix[12][12]) {
int transposeMatrix[12][12];
matrixCopy(transposeMatrix,matrix);
transpose(transposeMatrix);//transposeMatrix est maintenant la transpose de la matrice matrix. On a donc transposeMatrix=(T)matrix

int identityRot[12][12];
axialSymmetryIdentity(identityRot);//Cree une matrice identityRot qui est le symetrique de la matrice identite par rapport a l'axe vertical.

matrixProduct(matrix,transposeMatrix,identityRot);//matrix=(T)matrix*identityRot
}

/*
@description:
La methode matrixRot180 prend une matrices 12*12 en parametre et effectue une rotation de la matrice de 180° dans le sens horaire.
La matrice en parametre est modifiee par la methode car elle est passee par reference.

@param: La methode matrixRot180 prend 1 parametre obligatoire: 1 matrice statique de int 12*12.
-param1: une matrice de int 12*12 qui va etre transforme en sa rotation de 180° dans le sens horaire.
*/
void LibMatrix::matrixRot180(int matrix[12][12]) {
matrixRot90(matrix);//On effectue une rotation de la matrice de 90° dans le sens horaire.
matrixRot90(matrix);//On effectue une nouvelle fois une rotation de la matrice de 90° dans le sens horaire. On obtient donc une matrice transforme en sa rotation de 180° dans le sens horaire.
}

/*
@description:
La methode puissance prend deux int x et y en parametre et retourne x^y.

@param: La methode puissance prend 2 parametres obligatoires: un int et un int.
-param1: Le int que l'on veut mettre a la puissanse.
-param2: Le int specifiant la puissance a laquelle est mise le param1.
*/
int LibMatrix::puissance(int const& x, int const& y){
    int curentPuissance=1;
    for(int i=0;i<y;i++){
        curentPuissance*=x;
    }
    return curentPuissance;//Retourne x^y
}

/*
@description:
La methode isContained retourne 1 si le float pris en second parametre se trouve dans le vecteur specifie par le premier parametre et 0 sinon.

@param: La methode isContained prend 2 parametres obligatoires: un vector de float et un float.
-param1: Le vector de float ou l'on veut effectuer la recherche.
-param2: Le float que l'on veut savoir s'il se trouve dans le vector pris en premier parametre.
*/
int LibMatrix::isContained(vector<float> const& vectorTest, float const& x){
    //Pour chaque element du vector
    for(int i=0;i<vectorTest.size();i++){
        //On verifie si l'element du vecteur est egal au param2 specifie
        if(vectorTest[i] == x){
            return 1;
        }
    }
    return 0;
}

/*
@description:
La methode distanceBetweenPoint prend les coordonnes de deux points en parametre et renvoie la distance qui separe ces deux points sur le plan cartesien.

@param: La methode distanceBetweenPoint prend 4 parametres obligatoires: un float, un float, un float, un float.
-param1: un float qui correspond a l'abscisse du premier point
-param2: un float qui correspond a l'ordonne du premier point
-param3: un float qui correspond a l'abscisse du deuxieme point
-param4: un float qui correspond a l'ordonne du deuxieme point
*/
float LibMatrix::distanceBetweenPoint(float const& pointx1, float const& pointy1, float const& pointx2, float const& pointy2){
float distance;
distance = sqrt((pointx2-pointx1)*(pointx2-pointx1) + (pointy2-pointy1)*(pointy2-pointy1));
return distance;
}


/*
@description:
La methode loadLevelByInt permet d'initialiser une matrice prise en parametre avec la matrice presente dans un fichier.
La matrice en parametre est modifiee par la methode car elle est passee par reference.

@param: La methode loadLevelByInt prend deux parametres obligatoires: un int, et une matrice statique de int 12*12.
-param1: le int permet de specifier le niveau de la grille et donc le chemin du fichier contenant la matrice qui sert a initialiser la matrice passee en second parametre
-param2: une matrice  de int 12*12 qui va etre modifiee pour etre initialisee avec les donnees lues dans le fichier.
*/
void LibMatrix::loadLevelByInt(int const& intLevel,int matLevel[12][12], string const& stringNameDirectory) {

    //On construit petit a petit l'arborescence du chemin pour trouver les fichiers
    string stringLevel=stringNameDirectory;
    stringLevel+="Level_";

    string numberLevel;
    stringstream convertToString;
    convertToString << intLevel;
    numberLevel=convertToString.str();
    stringLevel+=numberLevel;

    stringLevel+=".txt";

    ifstream flux(stringLevel.c_str(),ios::app);//ouverture du flux de lecture
    int valueMatrix;
    int i=0;
    vector <int> v;

    if(flux)//si l'ouverture du fichier reussi
    {
        while(flux>>valueMatrix){//on lit le fichier mot par mot jusqu'a la fin de celui-ci
            v.push_back(valueMatrix);//on met les nombres lus dans un vecteur
        }

        //on parcourt la matrice passee en parametre et on initialise chaque element
        for(int y=0;y<12;y++){
            for(int x=0;x<12;x++){

				matLevel[y][x]=v[i];//on initialise la matrice passee en parametre avec les donnees du fichier que l'on a stocke dans un vecteur.
				i++;
            }
        }

    }
    else// En cas de probleme lors de l'ouverture du fichier
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;// on affiche un message d'erreur
    }
}


/*
@description:
La methode loadLevel permet d'initialiser une matrice prise en parametre avec la matrice presente dans un fichier.
La matrice en parametre est modifiee par la methode car elle est passee par reference.

@param: La methode loadLevel prend deux parametres obligatoires: un string, et une matrice statique de int 12*12.
-param1: le string permet de specifier le chemin du fichier contenant la matrice qui sert a initialiser la matrice passee en second parametre
-param2: une matrice  de int 12*12 qui va etre modifiee pour etre initialisee avec les donnees lues dans le fichier.
*/
void LibMatrix::loadLevel(string const& stringLevel,int matLevel[12][12]) {

    ifstream flux(stringLevel.c_str(),ios::app);//ouverture du flux de lecture
    int valueMatrix;
    int i=0;
    vector <int> v;

    if(flux)//si l'ouverture du fichier reussi
    {
        while(flux>>valueMatrix){//on lit le fichier mot par mot jusqu'a la fin de celui-ci
            v.push_back(valueMatrix);//on met les nombres lus dans un vecteur
        }

        //on parcourt la matrice passee en parametre et on initialise chaque element
        for(int y=0;y<12;y++){
            for(int x=0;x<12;x++){

				matLevel[y][x]=v[i];//on initialise la matrice passee en parametre avec les donnees du fichier que l'on a stocke dans un vecteur.
				i++;
            }
        }

    }
    else// En cas de probleme lors de l'ouverture du fichier
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;// on affiche un message d'erreur
    }
}


/*
@description:
La methode loadIntInFile permet de retourner un int lu dans dans un fichier.

@param: La methode loadIntInFile prend un parametre obligatoire: un string.
-param1: le string permet de specifier le chemin du fichier contenant le int que l'on veut lire et retourner.
*/
int LibMatrix::loadIntInFile(string const& stringLevel) {

    ifstream flux(stringLevel.c_str(),ios::app);//ouverture du flux de lecture
    int valueInt;

    if(flux)//si l'ouverture du fichier reussi
    {
        while(flux>>valueInt){//on lit le fichier mot par mot jusqu'a la fin de celui-ci
            return valueInt;
        }

    }
    else// En cas de probleme lors de l'ouverture du fichier
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;// on affiche un message d'erreur
    }
}

/*
@description:
La methode varAleatoire permet de retourner un int aleatoire entre 1 et le nombre pris en parametre compris.

@param: La methode varAleatoire prend un parametre obligatoire: un int.
-param1: le int permet de specifier le nombre maximum que peut prendre le nombre aleatoire.
*/
int LibMatrix::varAleatoire(int const& nbMax){
    int nombre_aleatoire=0;
    srand(time(NULL));
    nombre_aleatoire=rand()%nbMax+1;
    return nombre_aleatoire;
}

/*
@description:
La methode varAleatoireBetweenTwoNumbers permet de retourner un int aleatoire entre le premier nombre pris en parametre et le deuxieme nombre pris en parametre.

@param: La methode varAleatoireBetweenTwoNumbers prend deux parametres obligatoires: un int, un int.
-param1: Le premier int permet de specifier le nombre minimum que peut prendre le nombre aleatoire.
-param2: Le deuxieme int permet de specifier le nombre maximum que peut prendre le nombre aleatoire.
*/
int LibMatrix::varAleatoireBetweenTwoNumbers(int const& nbMin, int const& nbMax){
    int nombre_aleatoire=0;
    srand(time(NULL));
    nombre_aleatoire = (rand() % (nbMax - nbMin + 1)) + nbMin;
    return nombre_aleatoire;
}


/*
@description:
La methode writeIntInFileWithEraseData permet d'ecrire un int pris en parametre dans dans un fichier en effacant au prealable son contenu.

@param: La methode writeIntInFileWithEraseData prend deux parametres obligatoires et un parametre facultatif: un string, un int et un string facultatif.
-param1: Le string permet de specifier le nom du ficher dont on souhaite ecrire le int passee en second parametre.
-param2: Le int permet de specifier le int que l'on souhaite ecrire dans le ficher en ayant efface au prealable son contenu.
-param3: Le string facultatif permet de specifier le nom du repertoire ou des multiples repertoires ou est stocke le fichier dont on souhaite ecrire le int passee en second parametre. Par defaut, le repertoire se nomme Files.
*/
void LibMatrix::writeIntInFileWithEraseData(string const& stringNameFile, int const& valueWrite, string const& stringNameDirectory){

    //On construit petit a petit l'arborescence du chemin pour trouver les fichiers
    string stringPathFile=stringNameDirectory;
    stringPathFile+=stringNameFile;
    stringPathFile+=".txt";

    ofstream flux(stringPathFile.c_str());//ouverture en mode ecriture avec ecrasement des donnees
    //si l'ouverture du fichier reussi
    if(flux){
        flux<<valueWrite;//Ecriture du int dans le fichier
    }
    //En cas de probleme lors de l'ouverture du fichier
    else{
        cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;// on affiche un message d'erreur
    }
}


/*
@description:
La methode loadIntInFileWithDirectory permet de retourner un int lu dans dans un fichier qui se trouve dans un ou dans de multiples repertoires.

@param: La methode loadIntInFileWithDirectory prend un parametre obligatoire et un parametre facultatif: un string et un string facultatif.
-param1: Le string pris en premier parametre permet de specifier le fichier contenant le int que l'on veut lire et retourner.
-param2: Le string facultatif pris en second parametre permet de specifier le nom du repertoire ou des multiples repertoires ou est stocke le fichier contenant le int que l'on veut lire et retourner. Par defaut, le repertoire se nomme Files.
*/
int LibMatrix::loadIntInFileWithDirectory(string const& stringNameFile, string const& stringNameDirectory) {

    //On construit petit a petit l'arborescence du chemin pour trouver les fichiers
    string stringPathFile=stringNameDirectory;
    stringPathFile+=stringNameFile;
    stringPathFile+=".txt";

    ifstream flux(stringPathFile.c_str(),ios::app);//ouverture du flux de lecture
    int valueInt;

    if(flux)//si l'ouverture du fichier reussi
    {
        while(flux>>valueInt){//on lit le fichier mot par mot jusqu'a la fin de celui-ci
            return valueInt;
        }

    }
    else// En cas de probleme lors de l'ouverture du fichier
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;// on affiche un message d'erreur
    }
}
