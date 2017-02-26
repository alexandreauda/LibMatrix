#ifndef LIBMATRIX_H_INCLUDED
#define LIBMATRIX_H_INCLUDED

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <ctime>
#include <math.h>


class LibMatrix{

private:

    /******ATTRIBUT******/
    int m_lm1;

public:

    /******CONSTRUCTEUR PAR DEFAUT******/
	LibMatrix():m_lm1(0){}

    /******PROTOTYPES DES METHODES******/

    static void readMatrix(int matrix[12][12]);//Prend une matrice 12*12 en parametre qui va etre lue et affichee sur la console.

    static void identity(int matrix[12][12]);//Prend une matrice 12*12 prise en parametre et modifie ses coefficients pour la transformer en matrice identite de meme dimension.

    static void axialSymmetryIdentity(int matrix[12][12]);//Prend une matrice 12*12 prise en parametre et modifie ses coefficients pour la transformer en le symetrique de la matrice identite par rapport a l'axe vertical.

    static void transpose(int matrix[12][12]);//Permet de transpose une matrice prise en parametre.

    static void matrixCopy(int matrix[12][12], int matrix1[12][12]);//Prend deux matrices 12*12 en parametre et initialise la premiere matrice avec les coefficients de la deuxieme matrice.

    static void matrixProduct(int matrixproduct[12][12], int matrix1[12][12], int matrix2[12][12]);//Prend trois matrices 12*12 en parametre, effectue le produit matriciel entre les deux matrices et initialise la troisieme matrice avec les coefficients de la matrice produit.

    static void matrixRot90(int matrix[12][12]);//Fait une rotation de 90 degres des coefficients de la matrice prise en parametre

    static void matrixRot180(int matrix[12][12]);//Fait une rotation de 180 degres des coefficients de la matrice prise en parametre

    static int puissance(int const& x, int const& y);//Retourne x^y

    static int isContained(std::vector<float> const& vectorTest, float const& x);//Retourne 1 si x se trouve dans le vecteur et 0 sinon

    static float distanceBetweenPoint(float const& pointx1, float const& pointy1, float const& pointx2, float const& pointy2);//Prend les coordonnes de deux points en parametre et renvoie la distance qui separe ces deux points sur le plan cartesien.

    static void loadLevelByInt(int const& intLevel, int matLevel[12][12], std::string const& stringNameDirectory="Files/");//Permet d'initialiser une matrice prise en parametre avec la matrice presente dans un fichier grace a un int pris en parametre et une convention de nommage.

    static void loadLevel(std::string const& stringLevel, int matLevel[12][12]);//Permet d'initialiser une matrice prise en parametre avec la matrice presente dans un fichier.

    static int loadIntInFile(std::string const& stringLevel);//Permet de retourner un int lu dans dans un fichier.

    static int varAleatoire(int const& nbMax);//Permet de retourner un int aleatoire entre 1 et le nombre pris en parametre compris.

    static int varAleatoireBetweenTwoNumbers(int const& nbMin, int const& nbMax);//Permet de retourner un int aleatoire entre le premier nombre pris en parametre et le deuxieme nombre pris en parametre.

    static void writeIntInFileWithEraseData(std::string const& stringNameFile, int const& valueWrite, std::string const& stringNameDirectory="Files/");//Permet d'ecrire un int pris en parametre dans dans un fichier en effacant au prealable son contenu.

    static int loadIntInFileWithDirectory(std::string const& stringLevel, std::string const& stringNameDirectory="Files/");//Permet de retourner un int lu dans dans un fichier qui se trouve dans un ou dans de multiples repertoires.

};

#endif // LIBMATRIX_H_INCLUDED
