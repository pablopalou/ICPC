#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
#define mod 1000000007
#define SIZE 6

// cambiar por matriz de transformacion
ll matrix[SIZE][SIZE] = {
    {0, 1, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0},
    {0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1}
};

void multiply(ll a[SIZE][SIZE], ll b[SIZE][SIZE]) {
    ll result[SIZE][SIZE] = {0};
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < SIZE; k++) {
                result[i][j] = (result[i][j] %mod + (a[i][k] * b[k][j]) % mod) % mod;
            }
        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            a[i][j] = result[i][j] % mod;
        }
    }
}

void matrix_pow(ll a[SIZE][SIZE], ll n) {
    // cambiar por matriz de transformacion
    ll result[SIZE][SIZE] = {
        {1, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 1}
    };
    while (n > 0) {
        if (n % 2 == 1) {
            multiply(result, a);
        }
        multiply(a, a);
        n /= 2;
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            a[i][j] = result[i][j] % mod;
        }
    }
}

int main() {
    ll n;
    cin >> n;
    if (n <= SIZE) {
        cout << (1 << (n - 1)) << endl;
    } else {
        matrix_pow(matrix, n - SIZE);
        ll ans = 0;
        // Aca lo que hace es multiplicar por el vector
        // Justo en este caso es 1,2,4,8,16,32 y por eso hace (1<<i)
        // en realidad aca tenemos que multiplicar por el vector inicial que tengamos (casos base)
        for (int i = 0; i < SIZE; i++) {
            ans = (ans + (matrix[5][i] * (1 << i))%mod) % mod;
        }
        cout << ans << endl;
    }
    return 0;
}