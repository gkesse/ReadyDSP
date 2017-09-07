# Interpolation

L'**Interpolation** est la technique qui permet de construire une courbe à partir de la donnée 
d'un nombre fini de points.

Il en existe plusieurs types :
* Interpolation linéaire
* Interpolation cosinus
* Interpolation cubique
* Interpolation polynomiale

L'**Interpolation** est modélisée par plusieurs fonctions définies par tronçon dans les cas 
de l'Interpolation linéaire, l'Interpolation cosinus et l'Interpolation cubique.
Alors que l'**Interpolation** est modélisée par une fonction unique dans le cas 
l'Interpolation polynomiale.

# Programme de Test

**GProcess** est la classe chargée de l'exécution du programme de test.
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

**GFourier** est la classe chargée du calcul de la Transformée de Fourier Discrète.  
```
GFourier::Instance()->setData(m_ySamp);
GFourier::Instance()->dft();
GFourier::Instance()->harmonic();
```

# Signal Sinus

![Signal Sinus](https://raw.githubusercontent.com/gkesse/ReadyDSP/master/Fourier_DFT/img/sinus.png)

# Signal Cosinus

![Signal Cosinus](https://raw.githubusercontent.com/gkesse/ReadyDSP/master/Fourier_DFT/img/cosinus.png)

# Signal Mono-Alternance

![Signal Mono-Alternance](https://raw.githubusercontent.com/gkesse/ReadyDSP/master/Fourier_DFT/img/halfwave.png)

# Signal Double-Alternance

![Signal Double-Alternance](https://raw.githubusercontent.com/gkesse/ReadyDSP/master/Fourier_DFT/img/fullwave.png)

# Signal Carré

![Signal Carré](https://raw.githubusercontent.com/gkesse/ReadyDSP/master/Fourier_DFT/img/square.png)

# Signal Triangle

![Signal Triangle](https://raw.githubusercontent.com/gkesse/ReadyDSP/master/Fourier_DFT/img/triangle.png)

# Signal Dent de Scie

![Signal Dent de Scie](https://raw.githubusercontent.com/gkesse/ReadyDSP/master/Fourier_DFT/img/sawtooth.png)

# Signal Polynôme

![Signal Polynôme](https://raw.githubusercontent.com/gkesse/ReadyDSP/master/Fourier_DFT/img/polynomial.png)

# Voir Aussi

* [Signal](https://github.com/gkesse/ReadyDSP/tree/master/Signal "Signal")  
* [Echantillonnage](https://github.com/gkesse/ReadyDSP/tree/master/Echantillonnage "Echantillonnage")  
* [Transformée de Fourier Rapide](https://github.com/gkesse/ReadyDSP/tree/master/Fourier_FFT "Transformée de Fourier Rapide")  
* [Interpolation](https://github.com/gkesse/ReadyDSP/tree/master/Interpolation "Interpolation")  
