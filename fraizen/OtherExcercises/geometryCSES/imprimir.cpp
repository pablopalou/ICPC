GEOMETRIA CSES

CONVEX HULL

struct P {
    int x,y;
    void read(){
        cin >> x >> y;
    }
    P operator - (const P& b) const{
        return P{x-b.x, y -b.y};
    }
    void operator -=(const P& b){
        x -= b.x;
        y -= b.y;
    }
    ll operator * (const P& b) const{
        return (ll) x*b.y - (ll) y * b.x;
    }
    bool operator < (const P& B) const{
        return make_pair(x,y) < make_pair(B.x, B.y);
    }
};

int main() {
    int n;
    cin >> n;
    vector<P> points(n);
    fr(0,n){
        points[i].read();
    }
    sort(points.begin(), points.end());
    vector<P> hull;
    fr(0,2){
        const int S = hull.size();
        for(P C: points){
            while ((int) hull.size() - S >= 2){
                P A = hull.end()[-2];
                P B = hull.end()[-1];
                if ((B-A) * (C-A) <= 0){
                    break;
                }
                hull.pop_back();
            }
            hull.push_back(C);
        }
        hull.pop_back(); //remove rightmost point
        reverse(points.begin(), points.end());
    }
    cout << hull.size() << "\n";
    for(P p:hull){
        cout << p.x << ' ' << p.y << "\n";
    }
}

LINE SEGMENT INTERSECTION

// te dan dos segmentos (4 puntos digamos), y tenes que ver si esos segmentos tienen un punto en comun o no. 
// Aca la cuestion es separar por casos. 
// Primero vemos si los segmentos son paralelos. En caso de serlo, veo si son colineares. Si no lo son, retorno que no tienen puntos en comun. 
// Si son, me tengo que fijar si estan separados o no, esto lo hacemos con la tecnica de los boxes. 

void solve() {
    P p1,p2,p3,p4;
    p1.read();
    p2.read();
    p3.read();
    p4.read();
    if ((p2-p1) * (p4-p3) == 0) {// son paralelos
        if ((p2-p1) * (p3-p1) != 0){//veo si estan en distintas lineas digamos
            cout("NO");
            return;
        }
        // si llego aca es xq estan en la misma linea, hay que chequear si se overlappean.
        // para eso se hace la tecnica de los boxes
        if (max(p1.x,p2.x) < min(p3.x, p4.x) || max(p1.y,p2.y) < min(p3.y,p4.y)){
            cout("NO");
            return;
        }
        swap(p1,p3);
        swap(p2,p4);
        // cambio por si el segmento estaba arriba...
        if (max(p1.x,p2.x) < min(p3.x, p4.x) || max(p1.y,p2.y) < min(p3.y,p4.y)){
            cout("NO");
            return;
        }
        cout("YES");
        return;
    }
    // caso general, se podrian cruzar en un punto P si hacemos las rectas.
    // me fijo si P esta incluido en A y si P esta incluido en B
    // Si esta incluido en ambos devuelvo YES, sino NO
    // me tengo que fijar que los dos puntos del segmento esten de distinto lado
    // para que P este en el segmento.
    ll sign1 = (p2-p1) * (p3-p1);
    ll sign2 = (p2-p1) * (p4-p1);
    if ((sign1 < 0 && sign2 < 0) || (sign1 > 0 && sign2 > 0)){
        cout("NO");
        return;
    }
    sign1 = (p4-p3) * (p2-p3);
    sign2 = (p4-p3) * (p1-p3);
    if ((sign1 < 0 && sign2 < 0) || (sign1 > 0 && sign2 > 0)){
        cout("NO");
        return;
    }
    cout("YES");
    return;
}

int main() {
    int cases;
    cin >> cases;
    while (cases--){
        solve();
    }
}

POINT LOCATION TEST


void solve() {
    P p1, p2, p3;
    p1.read();
    p2.read();
    p3.read();
    p3 -= p1;
    p2 -= p1;
    ll cross_product = p2 * p3;
    if (cross_product < 0){
        cout("RIGHT");
    } else if (cross_product == 0){
        cout("TOUCH");
    } else {
        cout("LEFT");
    }
}

int main() {
    int cases;
    cin >> cases;
    while(cases--){
        solve();
    }
}

POLYGON AREA

// Este es solo hacer el producto cross de todos los adyacentes y al final de todo hacer el abs() y dividir entre 2 (creo) Eso del dividido 2 en este codigo no esta xq me piden el resultado * 2.

int main() {
    int cases = 1;
    while (cases--){
        int n;
        cin >> n;
        vector<P> polygon(n);
        fr(0,n){
            P p;
            p.read();
            polygon[i] = p;
        }
        ll area = 0;
        fr(0,n){
            area += polygon[i] * polygon[i+1==n? 0: i+1];
        }
        cout(abs(area));
    }
}

Problema 4) Punto en poligono (adentro, afuera o borde). 
Aca el loco como que se hace un segmento desde el punto a uno bien alto y movido un uno a la derecha. Se arma una funcion para ver si un punto esta en el borde 

bool segment_contains(P a, P b, P c){
    if (a.triangle(b,c) != 0){
        return false; //not collinear
    }
    return min(a.x, b.x) <= c.x && c.x <= max(a.x, b.x) && min(a.y, b.y) <= c.y && c.y <= max(a.y, b.y);
}

Llama eso primero y si esta en un borde ya retorna.
Ahi lo que hace es ir llamando a la interseccion de segmentos (problema 2) y va contando. 
Si la cantidad es par entonces ta afuera. Si la cantidad es impar adentro.

Problema 5) Polygon lattice points

Aca hay que contar la cantidad de puntos enteros en los bordes y adentro del poligono. 
En el borde tengo que ir viendo la diferencia de x e y con el siguiente punto y hago el gcd entre esos y sumo. 
Para los de adentro hay una formula area = interior + bordes/2 - 1.
