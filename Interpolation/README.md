# Interpolation

L'**Interpolation** est la technique qui permet de construire une courbe � partir de la donn�e 
d'un nombre fini de points.

Il en existe plusieurs types :
* Interpolation lin�aire
* Interpolation cosinus
* Interpolation cubique
* Interpolation polynomiale

L'**Interpolation** est mod�lis�e par plusieurs fonctions d�finies par tron�on dans les cas 
de l'Interpolation lin�aire, l'Interpolation cosinus et l'Interpolation cubique.
Alors qu'elle est mod�lis�e par une fonction unique dans le cas l'Interpolation polynomiale
(C'est la technique r�command�e).

# Interpolation Polynomiale

* **Co�fficients du Polyn�me d'Interpolation**

En consid�rant `N` points donn�s `(xi, yi)`, nous pouvons �crire : 

![Signal Sinus](https://raw.githubusercontent.com/gkesse/ReadyDSP/master/Interpolation/img/polynomial.png)

Le polyn�me d'interpolation est de degr� `N - 1`.

# Programme de Test

**GProcess** est la classe charg�e de l'ex�cution du programme de test.
```
//===============================================
void GProcess::run() {
    GSignal::Instance()->sinus();
    QVector<double> m_x = GSignal::Instance()->getX();
    QVector<double> m_y = GSignal::Instance()->getY();
    double m_xMin = GSignal::Instance()->getXmin();
    double m_xMax = GSignal::Instance()->getXmax();
    double m_yMin = GSignal::Instance()->getYmin();
    double m_yMax = GSignal::Instance()->getYmax();

    GSampling::Instance()->setX(m_x);
    GSampling::Instance()->setY(m_y);
    GSampling::Instance()->run(3);
    QVector<double> m_xSamp = GSampling::Instance()->getX();
    QVector<double> m_ySamp = GSampling::Instance()->getY();

    GInterPol::Instance()->setX(m_xSamp);
    GInterPol::Instance()->setY(m_ySamp);
    GInterPol::Instance()->polynomial();
    GInterPol::Instance()->compute();
    GInterPol::Instance()->coefficient();
    QVector<double> m_xInter = GInterPol::Instance()->getX();
    QVector<double> m_yInter = GInterPol::Instance()->getY();

    GGraphView::Instance()->setColor(QBrush("green"));
    GGraphView::Instance()->setData(m_xInter, m_yInter);
    GGraphView::Instance()->setXRange(m_xMin, m_xMax);
    GGraphView::Instance()->setYRange(m_yMin, m_yMax);
    GGraphView::Instance()->drawGraph();

    GGraphView::Instance()->setColor(QBrush("red"));
    GGraphView::Instance()->setData(m_xSamp, m_ySamp);
    GGraphView::Instance()->drawPoint();
}
//===============================================
```

**GInterPol** est la classe charg�e du calcul de l'Interpolation.  
```
GInterPol::Instance()->setX(m_xSamp);
GInterPol::Instance()->setY(m_ySamp);
GInterPol::Instance()->polynomial();
GInterPol::Instance()->compute();
GInterPol::Instance()->coefficient();
```

# Signal Sinus

![Signal Sinus](https://raw.githubusercontent.com/gkesse/ReadyDSP/master/Interpolation/img/sinus.png) 
![Signal Sinus](https://raw.githubusercontent.com/gkesse/ReadyDSP/master/Interpolation/img/sinus2.png) 

# Voir Aussi

* [Signal](https://github.com/gkesse/ReadyDSP/tree/master/Signal "Signal")  
* [Echantillonnage](https://github.com/gkesse/ReadyDSP/tree/master/Echantillonnage "Echantillonnage")  
* [Transform�e de Fourier Rapide](https://github.com/gkesse/ReadyDSP/tree/master/Fourier_FFT "Transform�e de Fourier Rapide")  
* [Interpolation](https://github.com/gkesse/ReadyDSP/tree/master/Interpolation "Interpolation")  
