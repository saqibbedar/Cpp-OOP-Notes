#include "matrix.hpp"

// allocation methods
void Matrix::alloc()
{
    matrix = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new int[cols];
    }
}
void Matrix::dealloc()
{
    for (int i = 0; i < rows; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
    rows = 0;
    cols = 0;
    matrix = nullptr;
}

// constructors
Matrix::Matrix()
{
    rows = 0;
    cols = 0;
    matrix = nullptr;
}
Matrix::Matrix(int r)
{
    rows = r;
    cols = 0;
    matrix = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = 0;
    }
}
Matrix::Matrix(int r, int c)
{
    rows = r;
    cols = c;
    alloc(); // allocation
}
Matrix::Matrix(int **mat, int r, int c)
{
    rows = r;
    cols = c;
    alloc(); // memory allocation
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            mat[i][j] = matrix[i][j];
        }
    }
}
Matrix::Matrix(const Matrix &mat)
{
    rows = mat.rows;
    cols = mat.cols;
    alloc();
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = mat.matrix[i][j];
        }
    }
}

// destructor
Matrix::~Matrix()
{
    dealloc();
}

// setters & getters
void Matrix::setRows(int r)
{
    rows = r;
};
void Matrix::setCols(int c)
{
    cols = c;
}
int Matrix::getRows() const
{
    return rows;
}
int Matrix::getCols() const
{
    return cols;
}

// friend functions
ostream &operator<<(ostream &out, const Matrix &m)
{
    if (m.rows && m.cols)
    {
        for (int i = 0; i < m.rows; i++)
        {
            for (int j = 0; j < m.cols; j++)
            {
                out << m.matrix[i][j] << " ";
            }
            out << endl;
        }
    }
    return out;
}
istream &operator>>(istream &in, Matrix &m)
{
    // check on rows and cols
    do
    {
        cout << "Enter no. of rows for matrix (rows>0): ";
        in >> m.rows;
        cout << "Enter no. of cols for matrix (cols>0): ";
        in >> m.cols;
    } while (m.rows <= 0 || m.cols <= 0);

    m.alloc();
    
    cout << "***Enter Matrix elements***" << endl;
    for (int i = 0; i < m.rows; i++)
    {
        for (int j = 0; j < m.cols; j++)
        {
            cout << "Enter element at index [" << i << "][" << j << "]: ";
            in >> m.matrix[i][j];
        }
    }
    return in;
}

// operator overloading
const Matrix& Matrix::operator+(const Matrix &m) const
{

    if (m.rows <= 0 || m.cols <= 0)
        return Matrix();

    Matrix sum(m.rows, m.cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            sum.matrix[i][j] = matrix[i][j] + m.matrix[i][j];
        }
    }
    return sum;
}
const Matrix& Matrix::operator-(const Matrix &m) const
{

    if (m.rows <= 0 || m.cols <= 0)
        return Matrix();

    Matrix sub(m.rows, m.cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            sub.matrix[i][j] = matrix[i][j] - m.matrix[i][j];
        }
    }
    return sub;
}
const Matrix& Matrix::operator*(const Matrix &m) const
{
    // check if matrix is square
    if (cols != m.rows)
    {
        return Matrix();
    }

    Matrix mul(m.rows, m.cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < m.cols; j++)
        {
            for (int k = 0; k < cols; k++)
            {
                mul.matrix[i][j] += matrix[i][k] * m.matrix[k][j];
            }
        }
    }
    return mul;
}

bool Matrix::operator==(const Matrix &m) const
{
    // check for square matrix
    if (rows != m.rows || cols != m.cols)
    {
        return false; // not square return false
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] != m.matrix[i][j])
            {
                return false; // if any element is not equal then return false
            }
        }
    }
    return true;
};
bool Matrix::operator!=(const Matrix &m) const
{
    return !(*this == m);
};

int &Matrix::operator()(int r, int c)
{ // element can be modified through this reference
    return matrix[r][c];
};
const int &Matrix::operator()(int r, int c) const
{ // element cannot be modified through this reference
    return matrix[r][c];
};

int &Matrix::operator[](int r) // double parameters are giving error
{
    return matrix[r][r];
};
const int &Matrix::operator[](int r) const 
{
    return matrix[r][r]; // bcz double parameters are showing error so I am returning [r][r]
};
