# Ft_ls - Le 101 (école 42)

## Consignes

• Vous devez recoder la commande ls du système.

• Son comportement doit être identique à celui de la commands ls originale du
système, avec les bémols suivants :

• Parmi les nombreuses options disponibles sur la ligne de commande, il vous est
demandé de réaliser les suivantes : -l, -R, -a, -r et -t.

• Vous n’avez pas à gérer le formatage en plusieurs colonnes de la sortie quand
l’option -l n’est pas passée.

• Vous n’êtes pas obligés de gérer les ACL et les attributs étendus.

• L’affichage général, selon chaque option, doit rester sensiblement identique à
celui de la commande système. Une certaine tolérance est appliquée sur le
padding et la mise en page, mais il ne doit manquer aucune information.


## Fonctions autorisées
◦ write
◦ opendir
◦ readdir
◦ closedir
◦ stat
◦ lstat
◦ getpwuid
◦ getgrgid
◦ listxattr
◦ getxattr
◦ time
◦ ctime
◦ readlink
◦ malloc
◦ free
◦ perror
◦ strerror
◦ exit

## Bonus réalisés

• Affichage en couleurs,<br/>
• Tri en arbre binaire (moins d'1 seconde d'écart avec le ls système sur `ls -lR ~`),<br/>
• man.

## Utilisation

#### Télécharger et compiler ft_ls
```
git clone https://github.com/Alhuin/ft_ls.git ~/Ft_ls
cd ~/Ft_ls
make
```
#### Exécution
```
./ft_ls [-larRt][directory (not necessary)]
```

## Licence
Ce projet a été produit sous licence MIT - voir le fichier LICENSE.md pour plus d'informations.
