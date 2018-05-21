/*

#include <GL/glu.h>

briques::briques(float largeurFenInp, float hauteurFenInp, int nbrBriqueLargeurInp, int nbrBriqueHauteurInp)
{
    player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("sonBriques.wav"));

    largeurF = largeurFenInp;
    hauteurF = hauteurFenInp;
    nbrBriqueLargeur = nbrBriqueLargeurInp;
    nbrBriqueHauteur = nbrBriqueHauteurInp;

    // Comme on affiche les couleurs en diagonale, il y a autant de couleurs que de colonnes de briques.
    for (int i = 0; i < nbrBriqueLargeur; i++)
    {
        couleurB[i] = rand()%230 + 20;
        couleurB[i] = couleurB[i] / 250;

        couleurR[i] = rand()%230 + 20;
        couleurR[i] = couleurR[i] / 250;

        couleurV[i] = rand()%236 + 20;
        couleurV[i] = couleurV[i] / 250;
    }

    for (int i = 0; i < nbrBriqueLargeur*nbrBriqueHauteur; i++) briquesRestantes[i] = true;

    for (int i = 0; i < 160 - nbrBriqueHauteur*nbrBriqueLargeur; i++) briquesRestantes[i + nbrBriqueHauteur*nbrBriqueLargeur] = false;

    largeurB = largeurFenInp/nbrBriqueLargeur*2;
    hauteurB = hauteurF/12*2;

    nbreBriquesRestantes = nbrBriqueHauteur*nbrBriqueLargeur;
}

void briques::dessinerBriques()
{
    int indexCouleur [nbrBriqueLargeur];
    for (int i = 0; i <nbrBriqueLargeur; i++)indexCouleur[i] = i;
    glPushMatrix();
    glTranslatef(-largeurF, hauteurF - hauteurB , 0);

    for (int l = 0; l < nbrBriqueHauteur; l++)
    {
        for (int c = 0; c < nbrBriqueLargeur ; c++)
        {
            if (briquesRestantes[l*10 + c])
            {
                indexCouleur[c] = indexCouleur[c] - 1;// gestion de la couleur en diagonale
                if (indexCouleur[c] < 0) indexCouleur[c] = 9;

                glPushMatrix();
                glTranslatef(c*largeurB, -l*hauteurB, 0);

                glBegin(GL_QUADS);

                glColor3f((float)couleurR[indexCouleur[c]], (float)couleurV[indexCouleur[c]], (float)couleurB[indexCouleur[c]]);
                glVertex3d(0,0,hauteurB);
                glVertex3d(0, 0,0);
                glVertex3d(largeurB, 0,0);
                glVertex3d(largeurB, 0,hauteurB);

                // FACE AVANT
                glVertex3d(0, 0,hauteurB);
                glVertex3d(largeurB, 0,hauteurB);
                glVertex3d(largeurB, hauteurB,hauteurB);
                glVertex3d(0, hauteurB,hauteurB);

                // FACE GAUCHE (VERIFIEE POUR LES PARAMETRES : gluLookAt(-3.0, 0.0, 15.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); ) !!!!!
                glColor3f((float)couleurR[indexCouleur[c]]*0.8, (float)couleurV[indexCouleur[c]]*0.8, (float)couleurB[indexCouleur[c]]*0.8);
                glVertex3d(0, 0,hauteurB);
                glVertex3d(0, 0,0);
                glVertex3d(0, hauteurB,0);
                glVertex3d(0,hauteurB ,hauteurB);

                glColor3f((float)couleurR[indexCouleur[c]], (float)couleurV[indexCouleur[c]], (float)couleurB[indexCouleur[c]]);
                glVertex3d(largeurB,0,hauteurB);
                glVertex3d(largeurB, 0,0);
                glVertex3d(largeurB, hauteurB,0);
                glVertex3d(largeurB, hauteurB,hauteurB);

                glVertex3d(0,hauteurB,hauteurB);
                glVertex3d(0, hauteurB,0);
                glVertex3d(largeurB, hauteurB,0);
                glVertex3d(largeurB, hauteurB,hauteurB);

                glVertex3d(0, hauteurB,0);
                glVertex3d(largeurB, hauteurB,0);
                glVertex3d(largeurB, 0,0);
                glVertex3d(0, 0,0);

                glEnd();
                glPopMatrix();
            }
        }
    }
    glPopMatrix();
}

void briques::reset()
{
    for (int i = 0; i < nbrBriqueLargeur*nbrBriqueHauteur; i++) briquesRestantes[i] = true;
    for (int i = 0; i < 160 - nbrBriqueHauteur*nbrBriqueLargeur; i++) briquesRestantes[i + nbrBriqueHauteur*nbrBriqueLargeur] = false;
    nbreBriquesRestantes = nbrBriqueHauteur*nbrBriqueLargeur;
}

bool briques::repContact(std::vector<int> indexTabBrique)
{
    bool contact = false;
    std::vector<int> :: iterator it;

    int tmpNbrPointContact = 0;

    for (it = indexTabBrique.begin(); it != indexTabBrique.end() ; ++it)
    {
        tmpNbrPointContact++;
        if (briquesRestantes[*it])// On test pour chacun des 8 points de la balle (pour plus d'explications, voir la partie 2 du rapport)
        {// si ils rentrent en collision avec une brique, et si c'est le cas, LEQUEL de ces 8 points touche une brique.
            contact = true;
            indexContact = *it;
            nbrPointContact = tmpNbrPointContact;

            player->setVolume(50);
            player->play();
        }
    }
    if (!contact) nbrPointContact = 0;

    return contact;
}

void briques::supprimerBrique()
{
    // indexContact = indice dans le tableau de briques de la dernière
    // brique touchée par la balle.
    if (briquesRestantes[indexContact])
    {
        briquesRestantes[indexContact] = false;
        nbreBriquesRestantes--;
    }
}

*/
