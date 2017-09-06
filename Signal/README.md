# Signal

Un **Signal** est une grandeur qui peut varier dans le temps.  

# Programme de Test

Le programme de test :

```
//===============================================
void GProcess::run() {
    GSignal::Instance()->polynomial();

    QVector<double> m_x = GSignal::Instance()->getX();
    QVector<double> m_y = GSignal::Instance()->getY();
    double m_xMin = GSignal::Instance()->getXmin();
    double m_xMax = GSignal::Instance()->getXmax();
    double m_yMin = GSignal::Instance()->getYmin();
    double m_yMax = GSignal::Instance()->getYmax();

    GGraphView::Instance()->setColor(QBrush("blue"));
    GGraphView::Instance()->setData(m_x, m_y);
    GGraphView::Instance()->setXRange(m_xMin, m_xMax);
    GGraphView::Instance()->setYRange(m_yMin, m_yMax);
    GGraphView::Instance()->drawGraph();
}
//===============================================
```

Les signaux développés :

```
public:
    void sinus(); //signal sinus
    void cosinus(); // signal cosinus
    void halfwave(); // signal mono-alternance
    void fullwave(); // signal double-alternance
    void square(); // signal carré
    void triangle(); // signal triangle
    void sawtooth(); // signal dent de scie
    void polynomial(); // signal polynôme
```

La génération d'un signal :  

**GSignal** est la classe chargée de la génération de signaux. 
`GSignal::Instance()->sinus();`

# Signal Sinus

Le signal sinus :

![Signal Sinus](https://raw.githubusercontent.com/gkesse/ReadyDSP/master/Signal/img/sinus.png)

# Signal Cosinus

Le signal cosinus :

![Signal Cosinus](https://raw.githubusercontent.com/gkesse/ReadyDSP/master/Signal/img/cosinus.png)

# Signal Mono-Alternance

Le signal mono-alternance :

![Signal Mono-Alternance](https://raw.githubusercontent.com/gkesse/ReadyDSP/master/Signal/img/halfwave.png)

# Signal Double-Alternance

Le signal double-alternance :

![Signal Double-Alternance](https://raw.githubusercontent.com/gkesse/ReadyDSP/master/Signal/img/fullwave.png)

# Signal Carré

Le signal carré :

![Signal Carré](https://raw.githubusercontent.com/gkesse/ReadyDSP/master/Signal/img/square.png)

# Signal Triangle

Le signal triangle :

![Signal Triangle](https://raw.githubusercontent.com/gkesse/ReadyDSP/master/Signal/img/triangle.png)

# Signal Dent de Scie

Le signal dent de scie :

![Signal Dent de Scie](https://raw.githubusercontent.com/gkesse/ReadyDSP/master/Signal/img/sawtooth.png)

# Signal Polynôme

Le signal polynôme :

![Signal Polynôme](https://raw.githubusercontent.com/gkesse/ReadyDSP/master/Signal/img/polynomial.png)
