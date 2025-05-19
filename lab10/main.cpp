#include <iostream>
#include <exception>
using namespace std;

// main() la randul 305

class Compare
{
public:
    virtual int CompareElements(void* e1, void* e2) = 0;
};


template <class T>
class Array;

template<class T>
class ArrayIterator
{
private:
    int Current;
    Array  <T> A();
    // mai adaugati si alte date si functii necesare pentru iterator
public:
    ArrayIterator(){
        Current = 0;
    }
    ArrayIterator& operator ++ (){
        Current++;
        return *this;
    }
    ArrayIterator& operator -- (){
        Current--;
        return *this;
    }
    bool operator==(ArrayIterator<T>&otherArrayIterator){
        if (A == otherArrayIterator.A && Current == otherArrayIterator.Current)
            return true;
        return false;
    }
    bool operator!=(ArrayIterator<T>& otherArrayIterator){
        if (A == otherArrayIterator.A && Current == otherArrayIterator.Current)
            return false;
        return true;
    }
    T* GetElement(){
        if (Current < 0 || Current >= A.GetSize())
            return nullptr;

        return A[Current];
    }
};


template<class T>
class Array
{
private:
    T** List; // lista cu pointeri la obiecte de tipul T*
    int Capacity; // dimensiunea listei de pointeri
    int Size; // cate elemente sunt in lista
public:
    Array() {               // Lista nu e alocata, Capacity si Size = 0
        Capacity=0;
        Size=0;
        List = new T * [Capacity]; 
    } 

    ~Array() {              // destructor
        delete [] List;
        Capacity=0;
        Size=0;
    } 

    Array(int capacity) {       // Lista e alocata cu 'capacity' elemente
        T List = new T * [capacity]; 
        Capacity=capacity;
        Size=0;
    } 

    Array(const Array<T>& otherArray) { // constructor de copiere
        this->Capacity = otherArray.Capacity;
        this->Size = otherArray.Size;
        for (int i = 0; i < this->Size; i++)
            List[i] = otherArray.List[i];
    }

    T& operator[] (int index) { // arunca exceptie daca index este out of range
        try{
            if (index > this->Capacity || index < 0)
                throw  out_of_range("Index out of range");
        }
        catch (exception& e){
            cout << "Exceptie: " << e.what() << endl;
            exit(1);
        }
        return *List[index];
    }

    const Array<T>& operator+=(const T& newElem) { // adauga un element de tipul T la sfarsitul listei si returneaza this
        if (Size >= Capacity)
            Capacity++;

        List[Size] = new T(newElem);
        Size++;
        return *this;
    }

    const Array<T>& Insert(int index, const T& newElem) { // adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
        try
        {
            if (index > this->Capacity || index < 0)
                throw  out_of_range("Index out of range la inserare elem");
        }
        catch (exception& e)
        {
            cout << "Exceptie: " << e.what() << endl;
            exit(1);
        }

        if (index < Size)
        {
            for (int i = Size; i >= index; i--)
                List[i] = List[i - 1];
            List[index] = new T(newElem);
            Size++;
        }
        else if (index == Size)
        {
            List[index] = new T(newElem);
            Size++;
        }
        else if (index > Size)
        {
            for (int i = Size; i < index; i++)
                List[i] = new T();
            List[index] = new T(newElem);
            Size = index + 1;
        }
        return *this;
    }

    const Array<T>& Insert(int index, const Array<T> otherArray) { // adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
        try
        {
            if (index > this->Capacity || index < 0)
                throw  out_of_range("Index out of range la inserare Array");
            if (index + otherArray.Size > this->Capacity)
                throw out_of_range("Index out of range la inserare Array, dim otherArray prea mare");
        }
        catch (exception& e)
        {
            cout << "Exceptie: " << e.what() << endl;
            exit(1);
        }

        for (int i = 0; i < otherArray.Size; i++)
            Insert(index + i, *otherArray.List[i]);
        return *this;
    }

    const Array<T>& Delete(int index) { // sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie
         try
        {
            if (index > this->Capacity || index < 0)
                throw  out_of_range("Index out of range la stergere");

        }
        catch (exception& e)
        {
            cout << "Exceptie: " << e.what() << endl;
            exit(1);
        }
        for (int i = index; i < Size - 1; i++)
            List[i] = List[i + 1];
        Size--;
        return *this;
    }

    bool operator=(const Array<T>& otherArray) {
        Size = otherArray.Size;
        Capacity = otherArray.Capacity;
        for (int i = 0; i < Size; i++)
            List[i] = otherArray.List[i];
    }

    void Sort() { // sorteaza folosind comparatia intre elementele din T
         for (int i = 0; i < Size; i++)
            for (int j = i + 1; j < Size; j++)
                if (*List[i] > *List[j])
                    swap(List[i], List[j]);
    }
        
    void Sort(int(*compare)(const T&, const T&)) { // sorteaza folosind o functie de comparatie
        for (int i = 0; i < Size; i++)
            for (int j = i + 1; j < Size; j++)
                if (compare(*List[i],*List[j])>0)
                    swap(List[i], List[j]);
    }

    void Sort(Compare* comparator) { // sorteaza folosind un obiect de comparatie
        for (int i = 0; i < Size; i++)
            for (int j = i + 1; j < Size; j++)
                if (comparator->CompareElements(List[i],List[j]))
                    swap(List[i], List[j]);
    }

    // functii de cautare - returneaza pozitia elementului sau -1 daca nu exista
    int BinarySearch(const T& elem){ // cauta un element folosind binary search in Array
        int st=0, dr=Size-1,mid=0;
        while (st <= dr){
            mid = st + (dr-st)/ 2;
            if (*List[mid] == elem)
                return mid;
            if (*List[mid] < elem)
                st = mid + 1;
            else
                dr = mid - 1;
        }
        return -1;
    }
    
    int BinarySearch(const T& elem, int(*compare)(const T&, const T&)){//  cauta un element folosind binary search si o functie de comparatie
        int st = 0, dr = Size - 1, mid = 0;
        while (st <= dr){
            mid = st + (dr - st) / 2;
            if (compare(*List[mid], elem)==0)
                return mid;
            if (compare(*List[mid], elem)<0)
                st = mid + 1;
            else
                dr = mid - 1;
        }
        return -1;
    }
        
    int BinarySearch(const T& elem, Compare *comparator){//  cauta un element folosind binary search si un comparator
        int st = 0, dr = Size - 1, mid = 0;
        while (st <= dr){
            mid = st + (dr - st) / 2;
            if (comparator->CompareElements(List[mid], (void*)&elem)==0)
                return mid;
            if (comparator->CompareElements(List[mid], (void*) & elem)<0)
                st = mid + 1;
            else
                dr = mid - 1;
        }
        return -1;
    }

    int Find(const T& elem) { // cauta un element in Array
        for(int i=0;i<Size;i++)
            if(*List[i]==elem) return i;
        return -1;
    }

    int Find(const T& elem, int(*compare)(const T&, const T&)){//  cauta un element folosind o functie de comparatie
        for (int i = 0; i < Size; i++)
            if (compare(*List[i],elem)==0) return i;
        return -1;
    }
        
    int Find(const T& elem, Compare *comparator){//  cauta un element folosind un comparator
        for (int i = 0; i < Size; i++)
            if (comparator->CompareElements(List[i], (void*)&elem) == 0)
                return i;
        return -1;
    }

    int GetSize(){ return this->Size; }
    int GetCapacity() { return this-> Capacity; }

    ArrayIterator<T> GetBeginIterator(){
        ArrayIterator<T> start;
        start.Current = 0;
        return start;
    }
    ArrayIterator<T> GetEndIterator(){
        ArrayIterator<T> finish;
        finish.Current = Size;
        return finish;
    }
};

#include <iostream>
#include <exception>
using namespace std;

class exceptie1 : public exception
{
    virtual const char* what() const throw()
    {
        return "Impartire la 0!";
    }
};

class exceptie2 : public exception
{
    virtual const char* what() const throw()
    {
        return "Indexul este inafara domeniului!";
    }
};

int main() 
{
    int z=-1, x = 50, y = 0;  // y=5
    int arr[4] = { 0 };
    int i = 10;               // i=2
    exceptie1 divide0;
    exceptie2 index_out_of_bounds;

    try
    {
        if (y==0)
            throw divide0;
        z = x / y;
        cout << "Fara exceptie: z=" << z << endl;
    }
    catch (exception& e)
    {
        cout << "Exceptie: " << e.what() << endl;
    }

    try
    {
        if (i > 3)
            throw index_out_of_bounds;
        arr[i] = z;
        for (i = 0; i < 4; i++)
            cout << "arr[" << i << "] = " << arr[i] << endl;
    }
    catch (exception& e)
    {
        cout << "Exceptie: " << e.what() << endl;
    }

    return 0;
}
