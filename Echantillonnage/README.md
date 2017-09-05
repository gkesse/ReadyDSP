# Echantillonnage

L'**Echantillonnage** est le processus qui consiste à prélever les valeurs d'un signal 
à intervalles de temps réguliers.  

# Programme de Test

Le programme de test :

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
    GSampling::Instance()->run();
    QVector<double> m_xSamp = GSampling::Instance()->getX();
    QVector<double> m_ySamp = GSampling::Instance()->getY();

    GGraphView::Instance()->setColor(QBrush("blue"));
    GGraphView::Instance()->setData(m_x, m_y);
    GGraphView::Instance()->setXRange(m_xMin, m_xMax);
    GGraphView::Instance()->setYRange(m_yMin, m_yMax);
    GGraphView::Instance()->drawGraph();

    GGraphView::Instance()->setColor(QBrush("red"));
    GGraphView::Instance()->setData(m_xSamp, m_ySamp);
    GGraphView::Instance()->drawSample();
}
//===============================================
```

L'échantillonnage d'un signal :  

**GSampling** est la classe chargée de l'échantillonnage de signaux. 
`GSampling::Instance()->run();`

# Signal Sinus

Le signal sinus :

![Signal Sinus](https://raw.githubusercontent.com/gkesse/ReadyDSP/master/Echantillonnage/img/sinus.png)

# Signal Cosinus

Le signal cosinus :

![Signal Cosinus](https://raw.githubusercontent.com/gkesse/ReadyDSP/master/Echantillonnage/img/cosinus.png)

# Signal Mono-Alternance

Le signal mono-alternance :

![Signal Mono-Alternance](https://raw.githubusercontent.com/gkesse/ReadyDSP/master/Echantillonnage/img/halfwave.png)

# Signal Double-Alternance

Le signal double-alternance :

![Signal Double-Alternance](https://raw.githubusercontent.com/gkesse/ReadyDSP/master/Echantillonnage/img/fullwave.png)

# Signal Carré

Le signal carré :

![Signal Carré](https://raw.githubusercontent.com/gkesse/ReadyDSP/master/Echantillonnage/img/square.png)

# Signal Triangle

Le signal triangle :

![Signal Triangle](https://raw.githubusercontent.com/gkesse/ReadyDSP/master/Echantillonnage/img/triangle.png)

# Signal Dent de Scie

Le signal dent de scie :

![Signal Dent de Scie](https://raw.githubusercontent.com/gkesse/ReadyDSP/master/Echantillonnage/img/sawtooth.png)

# Signal Polynôme

Le signal polynôme :

![Signal Polynôme](https://raw.githubusercontent.com/gkesse/ReadyDSP/master/Echantillonnage/img/polynomial.png)
