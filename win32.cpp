/*
win32.cpp

2020 RSA ALGORITHM XIV


KEY GENERATION
Select a value of e from 3,5,17,257,65537
repeat
   p ← genprime(k/2)
until (pmode)≠1
repeat
   q ← genprime(k - k/2)
until (qmode)≠1
N ← pq
L ← (p-1)(q-1)
d ← modinv(e, L)
return (N,e,d)

ENCRYPTION
Sender A does the following:-

Obtains the recipient B's public key (n,e).
Represents the plaintext message as a positive integer m with 1<m<n [see note 4].
Computes the ciphertext c=memodn.
Sends the ciphertext c to B.


DECRTYPTION
Recipient B does the following:-

Uses his private key (n,d) to compute m=cdmodn.
Extracts the plaintext from the message representative m.
 */
#include <iostream>
#include <windows.h>
using std::cout;
using std::cin;
using std::endl;
int prime(int in)
{
    int key = 0, i, j;
    i = in / 2;
    for (j = 2; j <= i; j++)
    {
        if (in % j == 0)
        {
            key = 1;
            break;
        }
    }
    return key;
}

int selecti(int a1, int a2)
{
    int i;
    do
    {
        i = a2 % a1;
        a2 = a1;
        a1 = i;
    }
    while (i != 0 && i != 1);
    return i;
}

int main()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 15);
    int p = 0, q = 0, k = 0;
    int n, n0, e;
    int d = 1, M = 1, C = 1, i, s = 1, h, se = 1;
    do
    {
        cout << "Input prime number p: ";
        SetConsoleTextAttribute(hConsole, 10);
        cin >> p;
        SetConsoleTextAttribute(hConsole, 15);
        k = prime(p);
        if (k == 1)
            cout << "p is not a prime number!\n";
    }
    while (k == 1);
    do
    {
        cout << "Input prime number q: ";
        SetConsoleTextAttribute(hConsole, 10);
        cin >> q;
        SetConsoleTextAttribute(hConsole, 15);
        k = prime(q);
        if (k == 1)
            cout << "q is not a prime number!\n";
    }
    while (k == 1);
    n = p * q;
    n0 = (p - 1)*(q - 1);
    do
    {
        cout << "Input a random number between ";
        SetConsoleTextAttribute(hConsole, 12);
        cout << "0";
        SetConsoleTextAttribute(hConsole, 15);
        cout << " and ";
        SetConsoleTextAttribute(hConsole, 12);
        cout << n0;
        SetConsoleTextAttribute(hConsole, 15);
        cout << " (they are mutually prime numbers): ";
        SetConsoleTextAttribute(hConsole, 10);
        cin >> e;
        SetConsoleTextAttribute(hConsole, 15);
        k = selecti(e, n0);
        if (k == 0)
            cout << "Input number and " << n0 << " and not mutually prime number!\n";
    }
    while (k == 0);
    do
    {
        d++;
        k = (d *e) % n0;
    }
    while (k != 1);
    cout << "Private key is ";
    SetConsoleTextAttribute(hConsole, 12);
    cout << d;
    SetConsoleTextAttribute(hConsole, 15);
    cout << ", public key is ";
    SetConsoleTextAttribute(hConsole, 11);
    cout << e;
    SetConsoleTextAttribute(hConsole, 15);
    cout << " and ";
    SetConsoleTextAttribute(hConsole, 11);
    cout << n << endl;
    SetConsoleTextAttribute(hConsole, 15);
    if (k == 1)
    {
        cout << "Encryption (1) Decryption (2): ";
        SetConsoleTextAttribute(hConsole, 10);
        cin >> k;
        SetConsoleTextAttribute(hConsole, 15);
        if (k == 1)
        {
            cout << "Input plain text: ";
            SetConsoleTextAttribute(hConsole, 10);
            cin >> M;
            SetConsoleTextAttribute(hConsole, 15);
            for (i = 1; i <= e; i++)
                C = (C *M) % n;
            cout << "Cipher text is: ";
            SetConsoleTextAttribute(hConsole, 12);
            cout << C << endl;
            SetConsoleTextAttribute(hConsole, 15);
        }
        else
        {
            cout << "Input cipher text: ";
            SetConsoleTextAttribute(hConsole, 10);
            cin >> C;
            SetConsoleTextAttribute(hConsole, 15);
            for (i = 1; i <= d; i++)
                M = (C *M) % n;
            cout << "Plain text is: ";
            SetConsoleTextAttribute(hConsole, 12);
            cout << M << endl;
            SetConsoleTextAttribute(hConsole, 15);
        }
    }
    cin >> i;
   return 0;
}
