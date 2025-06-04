#include <iostream>
using namespace std;

int main()
{
    int n;
    const int R = 4;

    cout << "Enter the number of items: ";
    cin >> n;

    // Dynamically allocate itemInfo[2][n]
    string** itemInfo = new string*[2];
    for (int i = 0; i < 2; ++i)
    {
        itemInfo[i] = new string[n];
    }

    // Dynamically allocate m1[R][n]
    int** m1 = new int*[R];
    for (int i = 0; i < R; ++i)
    {
        m1[i] = new int[n];
    }

    int totalStock = 0;
    int totalStockPrice = 0;

    string tableName[3] = {
        "stock",
        "stock limit",
        "unit price"
    };

    // Input loop
    for (int c = 0; c < n; c++)
    {
        cout << "Enter the ID for item #" << c + 1 << ": ";
        cin >> itemInfo[0][c];

        cout << "Enter the name for item #" << c + 1 << ": ";
        cin >> itemInfo[1][c];

        for (int r = 0; r < R - 1; r++)
        {
            cout << "Enter the " << tableName[r] << ": ";
            cin >> m1[r][c];
        }

        // Calculate total stock price for the item
        m1[3][c] = m1[0][c] * m1[2][c];
    }

    // Stock alert
    for (int c = 0; c < n; c++)
    {
        if (m1[0][c] < m1[1][c])
        {
            cout << "ALERT: Stock for item " << itemInfo[1][c]
                 << " (ID: " << itemInfo[0][c]
                 << ") is below the stock limit." << endl;
        }
    }

    // Print item table
    cout << "\nItem Table:" << endl;
    cout << "ID\tName\tStock\tLimit\tUnit Price\tTotal" << endl;

    for (int c = 0; c < n; c++)
    {
        cout << itemInfo[0][c] << "\t"
             << itemInfo[1][c] << "\t"
             << m1[0][c] << "\t"
             << m1[1][c] << "\t"
             << m1[2][c] << "\t\t"
             << m1[3][c] << endl;
    }

    // Calculate totals
    for (int c = 0; c < n; c++)
    {
        totalStockPrice += m1[3][c];
        totalStock += m1[0][c];
    }

    cout << "\nTotal stock value: " << totalStockPrice << endl;
    cout << "Total stock units: " << totalStock << endl;

    // Free memory
    for (int i = 0; i < 2; ++i)
    {
        delete[] itemInfo[i];
    }
    delete[] itemInfo;

    for (int i = 0; i < R; ++i)
    {
        delete[] m1[i];
    }
    delete[] m1;

    return 0;
}
