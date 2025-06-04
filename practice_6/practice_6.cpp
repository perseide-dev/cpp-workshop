#include <iostream>
using namespace std;

int main()
{
    int n;
    const int R = 4;

    cout << "Ingrese el número de items: ";
    cin >> n;

    string itemInfo[2][n]; 

    int m1[R][n]; 

    int totalStock = 0;
    int totalStockPrice = 0;

    string tableName[3] = {
        "stock",
        "límite de stock",
        "precio por unidad"
    };

    // Data Capture
    for (int c = 0; c < n; c++)
    {
        cout << "Ingrese el ID del item #" << c + 1 << ": ";
        cin >> itemInfo[0][c]; 

        cout << "Ingrese el nombre del item #" << c + 1 << ": ";
        cin >> itemInfo[1][c]; 

        for (int r = 0; r < R - 1; r++)
        {
            cout << "Ingrese el " << tableName[r] << ": ";
            cin >> m1[r][c];
        }

        m1[3][c] = m1[0][c] * m1[2][c]; // totalStockPriceByItem
    }

    // Alerta of stock
    for (int c = 0; c < n; c++)
    {
        if (m1[0][c] < m1[1][c])
        {
            cout << "ALERTA: El stock del item " << itemInfo[1][c]
                 << " con ID " << itemInfo[0][c]
                 << " es menor al límite de stock." << endl;
        }
    }

    // Tabla de items
    cout << "\nTabla de items:" << endl;
    cout << "ID\tNombre\tStock\tLímite\tPrecio Unit.\tTotal" << endl;

    for (int c = 0; c < n; c++)
    {
        cout << itemInfo[0][c] << "\t"
             << itemInfo[1][c] << "\t"
             << m1[0][c] << "\t"
             << m1[1][c] << "\t"
             << m1[2][c] << "\t\t"
             << m1[3][c] << endl;
    }

    // Totales
    for (int c = 0; c < n; c++)
    {
        totalStockPrice += m1[3][c];
        totalStock += m1[0][c];
    }

    cout << "\nEl precio total del stock es: " << totalStockPrice << endl;
    cout << "El total de stock es: " << totalStock << endl;

    return 0;
}
