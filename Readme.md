# Types de connexion

Cet exemple illustre les différents types de connexion de signaux et de slots et leurs effets

## Utilisation

Modifiez la valeur de la macro `TP` dans le fichier `main.cpp`. Les valeurs possibles vont de 1 à 8.

## Analyse

Les TP 1 à 4 utilisent la run-loop. Les TP 5 à 8 ne l'utilisent pas.

Un émetteur émet un signal, un récepteur capte ce signal et affiche un message lorsqu'il a reçu le message. La fonction `main()` connecte l'émetteur et le récepteur.

### TP n°1

Deux connexions sont effectuées, la première est du type `AutoConnection` et la seconde est du type `QueuedConnection`.

A l'exécution, un signal est reçu, puis le message "N'oubliez pas de forcer la fermeture de l'application..." est affiché, puis un second message est reçu.

Le premier signal n'est pas passé par la run-loop, il a donc été affiché immédiatement (par un branchement dans la fonction du Slot). Cela s'explique par le fait que le type `AutoConnection` utilise la règle de l'affinité de thread, or l'émetteur et le récepteur on la même affinité, donc la run-loop n'est pas utilisée.

Le seonc signal est passé par la run-loop car nous avons forcé ce comportement en utilisant le type de connexion `QueuedConnection`. S'il y avait plusieurs threads, c'est la run-loop de l'objet appelé (Recepteur) qui aurait été utilisée.

### TP n°2

Trois connexions sont effectuées, elles sont toutes du type `QueuedConnection` mais la dernière utilise le drapeau `UniqueConnection`.

A l'exécution, deux signaux sont reçus.

Ce sont les deux premiers signaux qui sont reçus car le troisième utilise le drapeau `UniqueConnection`, il y a donc une vérification de la non-existance d'une connexion préalable du même type. L'utilisation de ce drapeau à la troisième connexion n'a pas d'effet sur les connexions déjà établies.

### TP n°3

Quatre connexions sont effectuées, la première est du type `QueuedConnection`, la deuxième du type `DirectConnection`, la troisième utilise uniquement le drapeau `UniqueConnection`, elle est donc implicitement du type `AutoConnection` et unique sur ce type, et la dernière est du type `QueuedConnection`.

A l'exécution, un premier signal est reçu, puis le message "N'oubliez pas de forcer la fermeture de l'application..." est affiché, puis deux autres signaux sont reçus.

Le premier signal correspond à `DirectConnection`, il n'utilise donc pas la run-loop pour cette raison.

Le deuxième signal correspond au premier `QueuedConnection`, il a été placé sur la run-loop.

Le troisième signal correspond au dernier `QueuedConnection`, il a été placé sur la run-loop également.

Le signal du type `UniqueConnection` n'a pas été exécuté car il existait déjà une connexion du même type (assimilé à `QueuedConnection`).

### TP n°4

Une seule connexion du type `BlockingQueuedConnection` est effectuée.

A l'exécution, Qt affiche un message d'erreur car nous avons demandé l'exécution d'un Slot sur la run-loop du récepteur tout en bloquant la run-loop de l'émetteur. Or il n'y a qu'un seul thread, et lmes deux objets ont la même affinité de thread. Cette opération n'est donc pas possible.

### TP n°5

Deux connexions sont effectuées, la première est du type `AutoConnection` et la seconde est du type `QueuedConnection`.

A l'exécution, un seul signal est reçu. Il s'agit du signal correspondant au `DirectConnection`. En effet, en l'absence d'une run-loop le Slot ne sera jamais exécuté.

### TP n°6

Trois connexions sont effectuées, elles sont toutes du type `QueuedConnection` mais la dernière utilise le drapeau `UniqueConnection`.

Aucun Slot ne sera exécuté faute de run-loop.

### TP n°7

Quatre connexions sont effectuées, la première est du type `QueuedConnection`, la deuxième du type `DirectConnection`, la troisième utilise uniquement le drapeau `UniqueConnection`, elle est donc implicitement du type `AutoConnection` et unique sur ce type, et la dernière est du type `QueuedConnection`.

A l'exécution, un seul signal est reçu. Il s'agit du signal correspondant au `DirectConnection`. En effet, en l'absence d'une run-loop le Slot ne sera jamais exécuté.

### TP n°8

Une seule connexion du type `BlockingQueuedConnection` est effectuée.

En dépit de l'absence de run-loop, Qt refuse d'exécuter cet ordre absurde, qui traduit une erreur de conception majeure...