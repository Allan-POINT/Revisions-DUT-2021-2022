# LES FILES


## Principe

* Les files permettent de structuré les information par ordre d'arivée. 
* Elles sont chaîées.
* Permet de travailler avec la valleur la plus anciène.
* Quand on défile, on retire la valeur la plus anciène(tête) et on la remplace avec la valeur la précédent.

## 2 manière d'implémenter les files !

### Méthode 1

```
+--+--+  +--+--+  +--+--+ 
|x | -|->|y | -|->|z | -|->NULL
+--+--+  +--+--+  +--+--+
 ^		    ^
 |		    |
f.tete 		f.queue
```

### Méthode 2

```
+---+
| f |
+---+
  |
  ˇ 
+--+--+  +--+--+  +--+--+ 
|x | -|->|y | -|->|z | -|---+
+--+--+  +--+--+  +--+--+   |
   ^			    |
   |			    |
   +------------------------+
```
