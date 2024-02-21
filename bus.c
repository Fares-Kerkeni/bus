#include <stdio.h>
#include <string.h>

#define MAX_LIGNES 10
#define MAX_BUS 10

typedef struct {
  char marque[20];
  int nombrePlaces;
} Bus;

typedef struct {
  int numero;
  char nom[20];
  Bus busAssocies[MAX_BUS];
  int nombreBuses;
} Ligne;

Ligne lignes[MAX_LIGNES];
int nombreLignes = 0;

void ajouterBus(int numeroLigne) {
  if (numeroLigne < 1 || numeroLigne > nombreLignes) {
    printf("Ligne invalide\n");
    return;
  }

  Ligne *ligne = &lignes[numeroLigne - 1];

  if (ligne->nombreBuses >= MAX_BUS) {
    printf("La ligne a atteint le nombre maximum de bus\n");
    return;
  }

  Bus bus;

  printf("Marque du bus: ");
  scanf("%s", bus.marque);

  printf("Nombre de places du bus: ");
  scanf("%d", &bus.nombrePlaces);

  ligne->busAssocies[ligne->nombreBuses] = bus;
  ligne->nombreBuses++;

  printf("Le bus a été ajouté avec succès à la ligne %d\n", numeroLigne);
}

void afficherBuses(int numeroLigne) {
  if (numeroLigne < 1 || numeroLigne > nombreLignes) {
    printf("Ligne invalide\n");
    return;
  }

  Ligne *ligne = &lignes[numeroLigne - 1];

  printf("Buses de la ligne %d:\n", numeroLigne);

  for (int i = 0; i < ligne->nombreBuses; i++) {
    Bus bus = ligne->busAssocies[i];
    printf("Bus %d:\n", i + 1);
    printf("Marque: %s\n", bus.marque);
    printf("Nombre de places: %d\n", bus.nombrePlaces);
    printf("\n");
  }
}

void ajouterLigne() {
  if (nombreLignes >= MAX_LIGNES) {
    printf("Le nombre maximum de lignes a été atteint\n");
    return;
  }

  Ligne ligne;

  printf("Numéro de la ligne: ");
  scanf("%d", &ligne.numero);

  printf("Nom de la ligne: ");
  scanf("%s", ligne.nom);

  lignes[nombreLignes] = ligne;
  nombreLignes++;

  printf("La ligne a été ajoutée avec succès\n");
}

void afficherLignes() {
  printf("Lignes de bus:\n");

  for (int i = 0; i < nombreLignes; i++) {
    Ligne ligne = lignes[i];
    printf("Ligne %d:\n", i + 1);
    printf("Numéro: %d\n", ligne.numero);
    printf("Nom: %s\n", ligne.nom);
    printf("\n");
  }
}

void consulterLigne(int numeroLigne) {
  if (numeroLigne < 1 || numeroLigne > nombreLignes) {
    printf("Ligne invalide\n");
    return;
  }

  Ligne ligne = lignes[numeroLigne - 1];

  printf("Ligne %d:\n", numeroLigne);
  printf("Numéro: %d\n", ligne.numero);
  printf("Nom: %s\n", ligne.nom);
  printf("Nombre de buses: %d\n", ligne.nombreBuses);
  printf("\n");
}

void supprimerLigne(int numeroLigne) {
  if (numeroLigne < 1 || numeroLigne > nombreLignes) {
    printf("Ligne invalide\n");
    return;
  }

  for (int i = numeroLigne - 1; i < nombreLignes - 1; i++) {
    lignes[i] = lignes[i + 1];
  }

  nombreLignes--;

  printf("La ligne %d a été supprimée avec succès\n", numeroLigne);
}

void trierLignesParNombreStations() {
  for (int i = 0; i < nombreLignes - 1; i++) {
    for (int j = 0; j < nombreLignes - i - 1; j++) {
      if (lignes[j].nombreBuses > lignes[j + 1].nombreBuses) {
        Ligne temp = lignes[j];
        lignes[j] = lignes[j + 1];
        lignes[j + 1] = temp;
      }
    }
  }

  printf("Les lignes ont été triées par nombre de stations avec succès\n");
}

void afficherStatistiques() {
  int choix;
  printf("MENU STATISTIQUES\n");
  printf("1 - Minimum de bus par ligne\n");
  printf("2 - Maximum de bus par ligne\n");
  printf("3 - Moyenne de bus par ligne\n");
  printf("0 - Retour\n");
  printf("Choix: ");
  scanf("%d", &choix);

  switch (choix) {
    case 1:
      if (nombreLignes == 0) {
        printf("Aucune ligne disponible\n");
        return;
      }

      int minBuses = lignes[0].nombreBuses;
      for (int i = 1; i < nombreLignes; i++) {
        if (lignes[i].nombreBuses < minBuses) {
          minBuses = lignes[i].nombreBuses;
        }
      }
      printf("Le minimum de bus par ligne est: %d\n", minBuses);
      break;

    case 2:
      if (nombreLignes == 0) {
        printf("Aucune ligne disponible\n");
        return;
      }

      int maxBuses = lignes[0].nombreBuses;
      for (int i = 1; i < nombreLignes; i++) {
        if (lignes[i].nombreBuses > maxBuses) {
          maxBuses = lignes[i].nombreBuses;
        }
      }
      printf("Le maximum de bus par ligne est: %d\n", maxBuses);
      break;

    case 3:
      if (nombreLignes == 0) {
        printf("Aucune ligne disponible\n");
        return;
      }

      int totalBuses = 0;
      for (int i = 0; i < nombreLignes; i++) {
        totalBuses += lignes[i].nombreBuses;
      }
      float moyenneBuses = (float)totalBuses / nombreLignes;
      printf("La moyenne de bus par ligne est: %.2f\n", moyenneBuses);
      break;

    case 0:
      break;

    default:
      printf("Choix invalide\n");
      break;
  }
}

int main() {
  int choix;

  do {
    printf("MENU PRINCIPAL\n");
    printf("1 - Gérer les bus\n");
    printf("2 - Gérer les lignes\n");
    printf("3 - Statistiques\n");
    printf("0 - Quitter\n");
    printf("Choix: ");
    scanf("%d", &choix);

    switch (choix) {
      case 1: {
        int choixBus;

        printf("1 - Ajouter un bus\n");
        printf("2 - Afficher les bus\n");
        printf("3 - Consulter un bus\n");
        printf("4 - Supprimer un bus\n");
        printf("5 - Afficher les chauffeurs\n");
        printf("6 - Trier les bus par marque\n");
        printf("7 - Trier les bus par nombre de places\n");
        printf("0 - Retour\n");
        printf("Choix: ");
        scanf("%d", &choixBus);

        switch (choixBus) {
          case 1: {
            int numeroLigne;

            printf("Numéro de la ligne: ");
            scanf("%d", &numeroLigne);

            ajouterBus(numeroLigne);

            break;
          }
          case 2: {
            int numeroLigne;

            printf("Numéro de la ligne: ");
            scanf("%d", &numeroLigne);

            afficherBuses(numeroLigne);

            break;
          }
          case 3: {
            int numeroLigne, numeroBus;

            printf("Numéro de la ligne: ");
            scanf("%d", &numeroLigne);

            printf("Numéro du bus: ");
            scanf("%d", &numeroBus);

            consulterBus(numeroLigne, numeroBus);

            break;
          }
          case 4: {
            int numeroLigne, numeroBus;

            printf("Numéro de la ligne: ");
            scanf("%d", &numeroLigne);

            printf("Numéro du bus: ");
            scanf("%d", &numeroBus);

            supprimerBus(numeroLigne, numeroBus);

            break;
          }
          case 5:
            afficherChauffeurs();
            break;
          case 6: {
            int numeroLigne;

            printf("Numéro de la ligne: ");
            scanf("%d", &numeroLigne);

            trierBusParMarque(numeroLigne);

            break;
          }
          case 7: {
            int numeroLigne;

            printf("Numéro de la ligne: ");
            scanf("%d", &numeroLigne);

            trierBusParNombrePlaces(numeroLigne);

            break;
          }
          case 0:
            break;
          default:
            printf("Choix invalide\n");
            break;
        }

        break;
      }
      case 2: {
        int choixLigne;

        printf("1 - Ajouter une ligne\n");
        printf("2 - Afficher toutes les lignes\n");
        printf("3 - Consulter une ligne\n");
        printf("4 - Supprimer une ligne\n");
        printf("5 - Afficher les bus d'une ligne\n");
        printf("6 - Trier les lignes par nombre de stations\n");
        printf("0 - Retour\n");
        printf("Choix: ");
        scanf("%d", &choixLigne);

        switch (choixLigne) {
          case 1:
            ajouterLigne();
            break;
          case 2:
            afficherLignes();
            break;
          case 3: {
            int numeroLigne;

            printf("Numéro de la ligne: ");
            scanf("%d", &numeroLigne);

            consulterLigne(numeroLigne);

            break;
          }
          case 4: {
            int numeroLigne;

            printf("Numéro de la ligne: ");
            scanf("%d", &numeroLigne);

            supprimerLigne(numeroLigne);

            break;
          }
          case 5: {
            int numeroLigne;

            printf("Numéro de la ligne: ");
            scanf("%d", &numeroLigne);

            afficherBuses(numeroLigne);

            break;
          }
          case 6:
            trierLignesParNombreStations();
            break;
          case 0:
            break;
          default:
            printf("Choix invalide\n");
            break;
        }

        break;
      }
      case 3:
        afficherStatistiques();
        break;
      case 0:
        printf("Au revoir!\n");
        break;
      default:
        printf("Choix invalide. Veuillez réessayer.\n");
        break;
    }
  } while (choix != 0);

  return 0;
}
