#include <iostream>

using namespace std;

int main()
{
    int n;

    const int R = 4;

    cout << "ingrese el numero de items" << endl;
    cin >> n;

    string itemID[n];
    string itemName[n];

    // dinamic matrix allocation
    int** m1 = new int*[R];
    for (int i = 0; i < R; ++i)
    {
        m1[i] = new int[n];
    }

    int totalStock = 0;
    int totalStockPrice = 0;

    string tableName[3] = {
        "stock",
        "limite de stock",
        "precio por unidad",
    };

    for (int c = 0; c < n; c++)
    {
        cout << "ingrese el id" << endl;
        cin >> itemID[c];
        cout << "ingrese el nombre del item" << endl;
        cin >> itemName[c];

        for (int r = 0; r < R - 1; r++)
        {
            cout << "ingrese el " << tableName[r] << endl;
            cin >> m1[r][c];
        }

        m1[3][c] = m1[0][c] * m1[2][c];
    }

    for (int c = 0; c < n; c++)
    {
        if (m1[0][c] < m1[1][c])
        {
            cout << "ALERTA: El stock del item " << itemName[c] << " con id " << itemID[c] << " es menor al limite de stock" << endl;
        }
    }

    cout << "Tabla de items:" << endl;
    cout << "ID\tNombre\tStock\tLimite de Stock\tPrecio del stock\tTotal" << endl;

    for (int c = 0; c < n; c++)
    {
        cout << itemID[c] 
             << "\t" << itemName[c] 
             << "\t" << m1[0][c] 
             << "\t" << m1[1][c] 
             << "\t" << m1[2][c] 
             << "\t" << m1[3][c] 
             << endl;
    }

    for (int c = 0; c < n; c++)
    {
        totalStockPrice += m1[3][c];
    }
    cout << "El precio total del stock es: " << totalStockPrice << endl;

    for (int c = 0; c < n; c++)
    {
        totalStock += m1[0][c];
    }
    cout << "El total de stock es: " << totalStock << endl;

    // free memory
    for (int i = 0; i < R; ++i)
    {
        delete[] m1[i];
    }
    delete[] m1;

    return 0;
}