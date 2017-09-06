# Transform�e de Fourier Discr�te (DFT)

La **Transform�e de Fourier** est la technique qui permet de calculer le spectre d'un signal.  
Le spectre d'un signal est la repr�sentation des intensit�s des sinuso�des
contenues dans le signal en fonction de leurs fr�quences. 

La **Transform�e de Fourier Discr�te** est la Transform�e de Fourier appliqu�e aux signaux discrets.

# Programme de Test

**GProcess** est la classe charg�e de l'ex�cution du programme principal.
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

# Signal Cosinus

![Signal Cosinus](https://raw.githubusercontent.com/gkesse/ReadyDSP/master/Fourier_DFT/img/cosinus.png)

# Signal Mono-Alternance

![Signal Mono-Alternance](https://raw.githubusercontent.com/gkesse/ReadyDSP/master/Fourier_DFT/img/halfwave.png)

# Signal Double-Alternance

![Signal Double-Alternance](https://raw.githubusercontent.com/gkesse/ReadyDSP/master/Fourier_DFT/img/fullwave.png)

# Signal Carr�

![Signal Carr�](https://raw.githubusercontent.com/gkesse/ReadyDSP/master/Fourier_DFT/img/square.png)

# Signal Triangle

![Signal Triangle](https://raw.githubusercontent.com/gkesse/ReadyDSP/master/Fourier_DFT/img/triangle.png)

# Signal Dent de Scie

![Signal Dent de Scie](https://raw.githubusercontent.com/gkesse/ReadyDSP/master/Fourier_DFT/img/sawtooth.png)

# Signal Polyn�me

![Signal Polyn�me](https://raw.githubusercontent.com/gkesse/ReadyDSP/master/Fourier_DFT/img/polynomial.png)

# Voir Aussi

[Pr�c�dent : Echantillonnage](https://github.com/gkesse/ReadyDSP/tree/master/Echantillonnage "Echantillonnage")  
[Suivant : Fourier FFT](https://github.com/gkesse/ReadyDSP/tree/master/Fourier_DFT "Fourier FFT)")  
