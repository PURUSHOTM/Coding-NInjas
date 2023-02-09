/*
Code : Polynomial Class
Send Feedback
Implement a polynomial class, with the following properties and functions.
Properties :
1. An integer array (lets say A) which holds the coefficient and degrees. Use array indices as degree and A[i] as coefficient of ith degree.
2. An integer holding total size of array A.
Functions :
1. Default constructor
2. Copy constructor
3. setCoefficient -
This function sets coefficient for a particular degree value. If the given degree is greater than the current capacity of polynomial, increase the capacity accordingly and add then set the required coefficient. If the degree is within limits, then previous coefficient value is replaced by given coefficient value
4. Overload "+" operator (P3 = P1 + P2) :
Adds two polynomials and returns a new polynomial which has result.
5. Overload "-" operator (P3 = p1 - p2) :
Subtracts two polynomials and returns a new polynomial which has result
6. Overload * operator (P3 = P1 * P2) :
Multiplies two polynomials and returns a new polynomial which has result
7. Overload "=" operator (Copy assignment operator) -
Assigns all values of one polynomial to other.
8. print() -
Prints all the terms (only terms with non zero coefficients are to be printed) in increasing order of degree.
Print pattern for a single term : <coefficient>"x"<degree>
And multiple terms should be printed separated by space. And after printing one polynomial, print new line. For more clarity, refer sample test cases
Input Format :
Line 1 : N, total number of terms in polynomial P1
Line 2 : N integers representing degree of P1 (separated by space)
Line 3 : N integers representing coefficients of P1 (separated by space)
Line 4 : M, total number of terms in polynomial P2
Line 5 : M integers representing degree of P2 (separated by space)
Line 6 : M integers representing coefficients of P2 (separated by space)
Line 7 : Integer C, choice representing the function to be called (See main for more details)
Sample Input 1 :
3
1 3 5
1 2 -4
4
0 1 2 3
4 2 -3 1
1
Sample Output 1 :
4x0 3x1 -3x2 3x3 -4x5
Sample Input 2 :
3
1 3 5
1 2 -4
4
0 1 2 3
4 2 -3 1
2
Sample Output 2 :
-4x0 -1x1 3x2 1x3 -4x5
Sample Input 3 :
3
1 3 5
1 2 -4
4
0 1 2 3
4 2 -3 1
3
Sample Output 3 :
4x1 2x2 5x3 5x4 -22x5 -6x6 12x7 -4x8
*/
/*------------------------------------------Solution-1----------------------------------------*/
#include <bits/stdc++.h>
class Polynomial
{

public:
    int *degCoeff;
    int capacity;

    Polynomial()
    {
        degCoeff = new int[5];
        capacity = 5;
        for (int i = 0; i < capacity; i++)
            degCoeff[i] = 0;
    }

    void setCoefficient(int deg, int co)
    {
        if (deg >= capacity)
        {
            int *newarr = new int[deg + 1];
            for (int j = 0; j < deg + 1; j++)
                newarr[j] = 0;
            for (int i = 0; i < capacity; i++)
            {
                newarr[i] = degCoeff[i];
            }
            capacity = deg + 1;
            delete[] degCoeff;
            degCoeff = newarr;
        }
        degCoeff[deg] = co;
    }

    Polynomial(Polynomial const &a)
    {
        this->degCoeff = new int[a.capacity];
        for (int i = 0; i < a.capacity; i++)
        {
            degCoeff[i] = a.degCoeff[i];
        }
        // this->degCoeff=temp;
        this->capacity = a.capacity;
    }

    void operator=(Polynomial const &a)
    {
        this->degCoeff = new int[a.capacity];
        for (int i = 0; i < a.capacity; i++)
        {
            degCoeff[i] = a.degCoeff[i];
        }
        // this->degCoeff=temp;
        this->capacity = a.capacity;
    }

    Polynomial operator+(Polynomial const &a)
    {
        int max = (capacity >= a.capacity) ? (capacity) : (a.capacity);
        int min = (capacity <= a.capacity) ? (capacity) : (a.capacity);
        int flag = 0;
        if (capacity > a.capacity)
            flag = 1;

        int *temp2 = new int[max];
        for (int i = 0; i < max; i++)
        {
            if (i >= min)
            {
                if (flag == 1)
                    temp2[i] = degCoeff[i];
                else
                    temp2[i] = a.degCoeff[i];
            }
            else
                temp2[i] = degCoeff[i] + a.degCoeff[i];
        }
        Polynomial b;
        b.capacity = max;
        b.degCoeff = temp2;
        return b;
    }

    Polynomial operator-(Polynomial const &a)
    {
        int max = (capacity >= a.capacity) ? capacity : a.capacity;
        int min = (capacity <= a.capacity) ? (capacity) : (a.capacity);
        int flag = 0;
        if (capacity > a.capacity)
            flag = 1;
        int *temp2 = new int[max];
        for (int i = 0; i < max; i++)
        {
            if (i >= min)
            {
                if (flag == 1)
                    temp2[i] = degCoeff[i];
                else
                    temp2[i] = -a.degCoeff[i];
            }
            else
                temp2[i] = degCoeff[i] - a.degCoeff[i];
        }
        Polynomial b;
        b.capacity = max;
        b.degCoeff = temp2;
        return b;
    }

    Polynomial operator*(Polynomial const &a)
    {
        int max = capacity + a.capacity + 1;
        int *temp3 = new int[max];
        for (int j = 0; j < max; j++)
            temp3[j] = 0;
        for (int i = 0; i < capacity; i++)
        {
            for (int j = 0; j < a.capacity; j++)
            {
                temp3[i + j] = temp3[i + j] + degCoeff[i] * a.degCoeff[j];
            }
        }

        Polynomial x;
        x.capacity = max;
        x.degCoeff = temp3;
        return x;
    }

    void print()
    {
        for (int i = 0; i < capacity; i++)
        {
            if (degCoeff[i] == 0)
                continue;
            else
            {
                cout << degCoeff[i] << "x" << i << " ";
            }
        }
    }
};

/*-------------------------------------------solution-2----------------------------------------*/
class Polynomial
{
public:
    int *degCoeff;
    int capacity;
    Polynomial()
    {
        degCoeff = new int[10];
        capacity = 10;
        for (int i = 0; i < 10; i++)
        {
            degCoeff[i] = 0;
        }
    }
    Polynomial(Polynomial const &p)
    {
        degCoeff = new int[p.capacity];
        for (int i = 0; i < p.capacity; i++)
        {
            degCoeff[i] = p.degCoeff[i];
        }
        capacity = p.capacity;
    }
    void operator=(Polynomial const &p)
    {
        delete[] degCoeff;
        degCoeff = new int[p.capacity];
        for (int i = 0; i < p.capacity; i++)
        {
            degCoeff[i] = p.degCoeff[i];
        }
        capacity = p.capacity;
    }
    void setCoefficient(int degree, int coeff)
    {
        if (degree >= capacity)
        {
            int size = 2 * capacity;
            while (size <= degree)
            {
                size *= 2;
            }
            int *newDegCoeff = new int[size];
            for (int i = 0; i < size; i++)
            {
                newDegCoeff[i] = 0;
            }
            for (int i = 0; i < capacity; i++)
            {
                newDegCoeff[i] = degCoeff[i];
            }
            capacity = size;
            delete[] degCoeff;
            degCoeff = newDegCoeff;
        }
        degCoeff[degree] = coeff;
    }
    void print()
    {
        for (int i = 0; i < capacity; i++)
        {
            if (degCoeff[i] != 0)
            {
                cout << degCoeff[i] << "x" << i << " ";
            }
        }
        cout << endl;
    }
    Polynomial operator+(Polynomial const &p)
    {
        Polynomial pNew;
        int i = 0, j = 0;
        while (i < this->capacity && j < p.capacity)
        {
            int deg = i;
            int coeff = this->degCoeff[i] + p.degCoeff[j];
            pNew.setCoefficient(deg, coeff);
            i++;
            j++;
        }
        while (i < capacity)
        {
            pNew.setCoefficient(i, degCoeff[i]);
            i++;
        }
        while (j < p.capacity)
        {
            pNew.setCoefficient(j, p.degCoeff[j]);
            j++;
        }
        return pNew;
    }
    Polynomial operator-(Polynomial p)
    {
        Polynomial pNew;
        int i = 0, j = 0;
        while (i < this->capacity && j < p.capacity)
        {
            int deg = i;
            int coeff = this->degCoeff[i] - p.degCoeff[j];
            pNew.setCoefficient(deg, coeff);
            i++;
            j++;
        }
        while (i < capacity)
        {
            pNew.setCoefficient(i, degCoeff[i]);
            i++;
        }
        while (j < p.capacity)
        {
            pNew.setCoefficient(j, (-1 * p.degCoeff[j]));
            j++;
        }
        return pNew;
    }
    int getCoefficient(int degree)
    {
        if (degree >= capacity)
        {
            return 0;
        }
        return degCoeff[degree];
    }
    Polynomial operator*(Polynomial p)
    {
        Polynomial pNew;
        for (int j = 0; j < p.capacity; j++)
        {
            for (int i = 0; i < capacity; i++)
            {
                int deg = i + j;
                int coeff =
                    pNew.getCoefficient(deg) + (this->degCoeff[i] * p.degCoeff[j]);
                pNew.setCoefficient(deg, coeff);
            }
        }
        return pNew;
    }
};

/*--------------------------------------Solution-3----------------------------------------*/

class Polynomial
{

public:
    int *degCoeff; // Name of your array (Don't change this)
    int capacity;

    Polynomial()
    {
        this->degCoeff = new int[6];
        this->capacity = 5;
    }
    // Making paramaterized constructor for defining with capacity
    Polynomial(int capacity)
    {
        this->degCoeff = new int[capacity + 1];
        this->capacity = capacity;
    }

    Polynomial(Polynomial const &p)
    {
        int *newdeg = new int[p.capacity + 1];

        for (int i = 0; i <= p.capacity; i++)
            newdeg[i] = p.degCoeff[i];

        this->degCoeff = newdeg;

        this->capacity = p.capacity;
    }

    void setCoefficient(int deg, int coef)
    {
        if (deg > capacity)
        {
            int newcapacity = deg;
            int *newdeg = new int[newcapacity + 1];
            // Copy the contents from original to new
            for (int i = 0; i <= capacity; i++)
                newdeg[i] = degCoeff[i];

            this->degCoeff = newdeg;
            this->capacity = newcapacity;
            // Set the new coeff;
            degCoeff[deg] = coef;
        }
        else
        {
            degCoeff[deg] = coef;
        }
    }

    Polynomial operator+(Polynomial const &P2)
    {

        int newcap = max(this->capacity, P2.capacity);

        Polynomial P3(newcap);

        for (int i = 0; i <= newcap; i++)
        {
            if (i <= capacity && i <= P2.capacity)
                P3.degCoeff[i] = this->degCoeff[i] + P2.degCoeff[i];
            else if (i <= capacity)
                P3.degCoeff[i] = this->degCoeff[i];
            else
                P3.degCoeff[i] = P2.degCoeff[i];
        }

        return P3;
    }

    Polynomial operator-(Polynomial const &P2)
    {

        int newcap = max(this->capacity, P2.capacity);
        Polynomial P3(newcap);

        for (int i = 0; i <= newcap; i++)
        {
            if (i <= capacity && i <= P2.capacity)
                P3.degCoeff[i] = this->degCoeff[i] - P2.degCoeff[i];
            else if (i <= capacity)
                P3.degCoeff[i] = this->degCoeff[i];
            else
                P3.degCoeff[i] = -P2.degCoeff[i];
        }

        return P3;
    }

    Polynomial operator*(Polynomial const &P2)
    {

        int newcap = this->capacity + P2.capacity;
        Polynomial P3(newcap);

        for (int i = 0; i <= this->capacity; i++)
        {

            for (int j = 0; j <= P2.capacity; j++)
            {
                P3.degCoeff[i + j] += this->degCoeff[i] * P2.degCoeff[j];
            }
        }
        return P3;
    }

    void operator=(Polynomial const &p)
    {
        int *newdeg = new int[p.capacity + 1];
        // Copy the contents
        for (int i = 0; i < p.capacity; i++)
            newdeg[i] = p.degCoeff[i];

        this->degCoeff = newdeg;

        this->capacity = p.capacity;
    }

    void print()
    {

        for (int i = 0; i <= this->capacity; i++)
        {
            if (degCoeff[i] != 0)
                cout << degCoeff[i] << "x" << i << " ";
        }
        cout << endl;
    }
};
