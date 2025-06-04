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

    int m1[R][n];

    int totalStock = 0;
    int totalStockPrice = 0;

    /*
     |stock|
     |limitStock|
     |unitPrice|
     |totalStockPriceByItem|
    */

    string tableName[3] = {
        "stock",
        "limite de stock",
        "precio por unidad",
    };

    // Allocation loop
    for (int c = 0; c < n; c++)
    {
        cout << "ingrese el id" << endl;
        cin >> itemID[c];
        cout << "ingrese el nombre del item" << endl;
        cin >> itemName[c];  // ← Fixed index here

        for (int r = 0; r < R - 1; r++) // ← Only loop over 3 attributes
        {
            cout << "ingrese el " << tableName[r] << endl;
            cin >> m1[r][c];
        }

        m1[3][c] = m1[0][c] * m1[2][c]; // totalStockPriceByItem
    };

    // Stock Alert Loop
    for (int c = 0; c < n; c++)
    {
        if (m1[0][c] < m1[1][c])
        {
            cout << "ALERTA: El stock del item " << itemName[c] << " con id " << itemID[c] << " es menor al limite de stock" << endl;
        }
    }

    // Print Table
    cout << "Tabla de items:" << endl;
    cout << "ID\tNombre\tStock\tLimite de Stock\tPrecio sel stock" << endl;

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

    // Print Total Stock Price
    for (int c = 0; c < n; c++)
    {
        totalStockPrice += m1[3][c];
    }
    cout << "El precio total del stock es: " << totalStockPrice << endl;

    // Print Total Stock
    for (int c = 0; c < n; c++)
    {
        totalStock += m1[0][c];
    }
    cout << "El total de stock es: " << totalStock << endl;

    return 0;
}