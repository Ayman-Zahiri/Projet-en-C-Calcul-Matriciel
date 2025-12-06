# 🧮 Projet en C - Calcul Matriciel

![C](https://img.shields.io/badge/Language-C-blue.svg)
![License](https://img.shields.io/badge/License-Académique-green.svg)

Application développée en langage C pour la gestion et la manipulation de **matrices creuses** (sparse matrices), à travers une interface en ligne de commande interactive. Le programme offre des fonctionnalités optimisées pour le traitement de matrices de grande taille avec peu d'éléments non nuls.

## 📋 Table des Matières

- [Fonctionnalités](#-fonctionnalités)
- [Prérequis](#-prérequis)
- [Installation](#-installation)
- [Utilisation](#-utilisation)
- [Structure du Projet](#-structure-du-projet)
- [Détails Techniques](#-détails-techniques)
- [Exemples](#-exemples)
- [Auteur](#-auteur)
- [Licence](#-licence)

## ✨ Fonctionnalités

- **Création de matrice identité** : Génération automatique d'une matrice identité de taille n×n
- **Addition de matrices creuses** : Addition efficace de deux matrices creuses
- **Transformation dense → creuse** : Conversion d'une matrice dense en représentation creuse
- **Affichage optimisé** : Visualisation des matrices sous différents formats
- **Interface interactive** : Menu en ligne de commande convivial

## 🔧 Prérequis

- **Compilateur C** : GCC version 4.8 ou supérieure
- **Système d'exploitation** : Linux, macOS, ou Windows (avec MinGW/Cygwin)
- **Mémoire** : Minimum 256 MB RAM
- **Espace disque** : Environ 1 MB pour l'exécutable

## 📥 Installation

### 1. Cloner le dépôt

```bash
git clone https://github.com/Ayman-Zahiri/Projet-en-C-Calcul-Matriciel.git
cd Projet-en-C-Calcul-Matriciel
```

### 2. Compiler le programme

```bash
gcc -o matrix_calc main.c -Wall
```

Ou avec optimisations :

```bash
gcc -o matrix_calc main.c -Wall -O2
```

### 3. Vérifier la compilation

```bash
./matrix_calc
```

## 🚀 Utilisation

### Lancer le programme

```bash
./matrix_calc
```

### Menu Principal

Une fois lancé, le programme affiche un menu interactif avec les options suivantes :

```
===== MENU =====
1. Creer matrice identite
2. Additionner deux matrices creuses
3. Transformer une matrice dense en creuse
0. Quitter
```

### Options détaillées

#### Option 1 : Créer une matrice identité

- Entrez la taille souhaitée (n×n)
- Le programme génère et affiche une matrice identité

#### Option 2 : Additionner deux matrices creuses

- Spécifiez la taille des matrices carrées
- Saisissez les éléments de la première matrice (les zéros peuvent être entrés mais seront optimisés)
- Saisissez les éléments de la seconde matrice
- Le programme affiche les deux matrices et leur somme

#### Option 3 : Transformer une matrice dense en creuse

- Entrez la taille de la matrice (maximum 10×10)
- Saisissez tous les éléments de la matrice
- Le programme affiche la représentation creuse (liste chaînée) avec uniquement les éléments non nuls

## 📁 Structure du Projet

```
Projet-en-C-Calcul-Matriciel/
├── main.c              # Code source principal
├── README.md           # Documentation du projet
├── .gitignore          # Fichiers à ignorer par Git
└── matrix_calc         # Exécutable (généré après compilation)
```

## 🔬 Détails Techniques

### Structure de données

Le projet utilise une **liste chaînée** pour représenter les matrices creuses de manière optimisée :

```c
typedef struct Smat {
    int i;              // Indice de ligne
    int j;              // Indice de colonne
    int coeff;          // Valeur non nulle
    struct Smat *next;  // Pointeur vers l'élément suivant
} Smat;
```

### Avantages de l'approche

- **Efficacité mémoire** : Stockage uniquement des éléments non nuls
- **Performance** : Opérations optimisées pour matrices éparses
- **Scalabilité** : Gestion de grandes matrices avec peu d'éléments significatifs

### Fonctions principales

| Fonction | Description |
|----------|-------------|
| `creeelement()` | Crée un nouvel élément de matrice |
| `creematrice_identite()` | Génère une matrice identité |
| `ajouter_element()` | Ajoute un élément à la matrice creuse |
| `additionner_matrice()` | Additionne deux matrices creuses |
| `transformer()` | Convertit une matrice dense en creuse |
| `affiche_matric()` / `affiche_matrice()` | Affiche la matrice complète |
| `afficher_creuse()` | Affiche la représentation creuse |

## 📝 Exemples

### Exemple 1 : Matrice Identité 3×3

```
1  0  0
0  1  0
0  0  1
```

Représentation creuse :
```
(0, 0) = 1
(1, 1) = 1
(2, 2) = 1
```

### Exemple 2 : Addition de matrices creuses

**Matrice A :**
```
1  0  2
0  3  0
4  0  5
```

**Matrice B :**
```
5  0  0
0  2  0
1  0  3
```

**Somme (A + B) :**
```
6  0  2
0  5  0
5  0  8
```

## 👨‍💻 Auteur

**Ayman Zahiri**

- GitHub: [@Ayman-Zahiri](https://github.com/Ayman-Zahiri)
- Projet: [Projet-en-C-Calcul-Matriciel](https://github.com/Ayman-Zahiri/Projet-en-C-Calcul-Matriciel)

## 📄 Licence

Ce projet a été développé dans un cadre **pédagogique et académique**. 

Vous êtes libre de l'utiliser, le modifier et le distribuer pour des fins éducatives.

---

### 🌟 Contribution

Les contributions sont les bienvenues ! N'hésitez pas à :

- Signaler des bugs
- Proposer de nouvelles fonctionnalités
- Améliorer la documentation
- Soumettre des pull requests

### 📞 Support

Pour toute question ou suggestion, veuillez ouvrir une [issue](https://github.com/Ayman-Zahiri/Projet-en-C-Calcul-Matriciel/issues) sur GitHub.

---

**Développé avec ❤️ en langage C**
