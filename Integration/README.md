# Int�gration

L'**Int�gration** est la technique qui consiste � calculer l'int�grale d'une fonction. 

# Int�gration Num�rique

* **M�thode de Gauss-Legendre**

En consid�rant une fonction `f(x)`, nous pouvons �crire : 

![Formule](https://raw.githubusercontent.com/gkesse/ReadyDSP/master/Integration/img/formula.png)

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

    GIntegrate::Instance()->setX(m_x);
    GIntegrate::Instance()->setY(m_y);
    GIntegrate::Instance()->gaussLegendre();
    QVector<double> m_xInteg = GIntegrate::Instance()->getX();
    QVector<double> m_yInteg = GIntegrate::Instance()->getY();
    double m_xMin2 = GIntegrate::Instance()->getXmin();
    double m_xMax2 = GIntegrate::Instance()->getXmax();
    double m_yMin2 = GIntegrate::Instance()->getYmin();
    double m_yMax2 = GIntegrate::Instance()->getYmax();

    GGraphView::Instance()->setColor(QBrush("blue"));
    GGraphView::Instance()->setData(m_x, m_y);
    GGraphView::Instance()->setXRange(m_xMin, m_xMax);
    GGraphView::Instance()->setYRange(m_yMin, m_yMax);
    GGraphView::Instance()->drawGraph();

    GGraphView::Instance()->setColor(QBrush("red"));
    GGraphView::Instance()->setData(m_xInteg, m_yInteg);
    GGraphView::Instance()->setXRange(m_xMin2, m_xMax2, 1);
    GGraphView::Instance()->setYRange(m_yMin2, m_yMax2, 1);
    GGraphView::Instance()->drawGraph(1);
}
//===============================================
```

**GIntegrate** est la classe charg�e du calcul de l'int�grale d'un signal.  
```
GIntegrate::Instance()->setX(m_x);
GIntegrate::Instance()->setY(m_y);
GIntegrate::Instance()->gaussLegendre();
```

# Signal Sinus

![Signal Sinus](https://raw.githubusercontent.com/gkesse/ReadyDSP/master/Integration/img/sinus.png)
![Signal Sinus](https://raw.githubusercontent.com/gkesse/ReadyDSP/master/Integration/img/sinus2.png)

# Signal Cosinus

![Signal Cosinus](https://raw.githubusercontent.com/gkesse/ReadyDSP/master/Integration/img/cosinus.png)
![Signal Cosinus](https://raw.githubusercontent.com/gkesse/ReadyDSP/master/Integration/img/cosinus2.png)

# Signal Mono-Alternance

![Signal Mono-Alternance](https://raw.githubusercontent.com/gkesse/ReadyDSP/master/Integration/img/halfwave.png)
![Signal Mono-Alternance](https://raw.githubusercontent.com/gkesse/ReadyDSP/master/Integration/img/halfwave2.png)

# Signal Double-Alternance

![Signal Double-Alternance](https://raw.githubusercontent.com/gkesse/ReadyDSP/master/Integration/img/fullwave.png)

# Signal Carr�

![Signal Carr�](https://raw.githubusercontent.com/gkesse/ReadyDSP/master/Integration/img/square.png)

# Signal Triangle

![Signal Triangle](https://raw.githubusercontent.com/gkesse/ReadyDSP/master/Integration/img/triangle.png)

# Signal Dent de Scie

![Signal Dent de Scie](https://raw.githubusercontent.com/gkesse/ReadyDSP/master/Integration/img/sawtooth.png)

# Signal Polyn�me

![Signal Polyn�me](https://raw.githubusercontent.com/gkesse/ReadyDSP/master/Integration/img/polynomial.png)

# Voir Aussi

* [ReadyDSP](https://github.com/gkesse/ReadyDSP "ReadyDSP")  
* [Signal](https://github.com/gkesse/ReadyDSP/tree/master/Signal "Signal")  
* [Echantillonnage](https://github.com/gkesse/ReadyDSP/tree/master/Echantillonnage "Echantillonnage")  
* [Transform�e de Fourier Rapide](https://github.com/gkesse/ReadyDSP/tree/master/Fourier_FFT "Transform�e de Fourier Rapide")  
* [Interpolation](https://github.com/gkesse/ReadyDSP/tree/master/Interpolation "Interpolation") 
* [Int�gration](https://github.com/gkesse/ReadyDSP/tree/master/Integration "Int�gration")  
