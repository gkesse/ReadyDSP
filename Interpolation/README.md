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
Alors qu'elle est mod�lis�e par une fonction unique dans le cas l'Interpolation polynomiale.

# Interpolation Polynomiale

* **Co�fficients du Polyn�me d'Interpolation**

En consid�rant `N` points donn�s `(xi, yi)`, nous pouvons �crire : 

![Signal Sinus](https://raw.githubusercontent.com/gkesse/ReadyDSP/master/Interpolation/img/polynomial.png)

Le polyn�me r�sultant est de degr� `N - 1`.

# Programme de Test

**GProcess** est la classe charg�e de l'ex�cution du programme de test.
```
//===============================================
void GProcess::run() {
    GSignal::Instance()->sinus();
    QVector<double> m_x = GSignal::Instance()->getX();
    QVector<double> m_y = GSignal::Instance()->getY();

    GSampling::Instance()->setX(m_x);
    GSampling::Instance()->setY(m_y);
    GSampling::Instance()->run();
    QVector<double> m_ySamp = GSampling::Instance()->getY();

    GFourier::Instance()->setData(m_ySamp);
    GFourier::Instance()->dft();
    GFourier::Instance()->harmonic();
    QVector<double> m_xHarm = GFourier::Instance()->getXHarm();
    QVector<double> m_yHarm = GFourier::Instance()->getYHarm();
    double m_xMin = GFourier::Instance()->getXmin();
    double m_xMax = GFourier::Instance()->getXmax();
    double m_yMin = GFourier::Instance()->getYmin();
    double m_yMax = GFourier::Instance()->getYmax();

    GGraphView::Instance()->setColor(QBrush("red"));
    GGraphView::Instance()->setData(m_xHarm, m_yHarm);
    GGraphView::Instance()->setXRange(m_xMin, m_xMax);
    GGraphView::Instance()->setYRange(m_yMin, m_yMax);
    GGraphView::Instance()->drawSample();
}
//===============================================
```

**GFourier** est la classe charg�e du calcul de la Transform�e de Fourier Discr�te.  
```
GFourier::Instance()->setData(m_ySamp);
GFourier::Instance()->dft();
GFourier::Instance()->harmonic();
```

# Signal Sinus

![Signal Sinus](https://raw.githubusercontent.com/gkesse/ReadyDSP/master/Fourier_DFT/img/sinus.png)

# Voir Aussi

* [Signal](https://github.com/gkesse/ReadyDSP/tree/master/Signal "Signal")  
* [Echantillonnage](https://github.com/gkesse/ReadyDSP/tree/master/Echantillonnage "Echantillonnage")  
* [Transform�e de Fourier Rapide](https://github.com/gkesse/ReadyDSP/tree/master/Fourier_FFT "Transform�e de Fourier Rapide")  
* [Interpolation](https://github.com/gkesse/ReadyDSP/tree/master/Interpolation "Interpolation")  
