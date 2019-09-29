#include <iostream>
#include<fstream> 
using namespace std; 

#define SIZE 10

void pause(); 
template<class T>

class Queue { 
    private: 
    T q[SIZE]; 
    int in, out; 
    bool is_empty, is_full; 

    // circular increment 
    int inc(int val);

    public: 
    Queue(); 
    void enqueue(T val);
    T dequeue();           

    void print_queue(); 
};
template <class T>

 Queue<T>::Queue() { 
    for (int i = 0; i < SIZE; i++) { 
        q[i] = " "; 
    }
    in = out = 0; 
    is_empty = true; 
    is_full = false; 
}


template <class T>
int Queue<T>::inc(int val) { 
    if (val + 1 == SIZE)         // loop around 
        val = 0; 
    else 
        val += 1; 
    return val;} 
template<class T>

void Queue<T>::enqueue(T val) { 
    if (is_full) {
        throw "Queue full. Cannot enqueue ... "; 
        // cout << "Nahi kerta!" ; 
        // return; 
    } 

    // put where in is and increment in 
    q[in] = val; 
    in = inc(in); 

    // check if we are now full 
    if (in == out) 
        is_full = true;
    
    // definitely not empty any more 
    is_empty = false;       
}
template <class T>
T Queue<T>::dequeue() { 
    if (is_empty) {
        throw "Queue empty. Cannot dequeue ... "; 
    } 

    // get from where out is and inc out 
    T ret = q[out]; 
    out = inc(out); 

    // see if we are now empty 
    if (in == out) 
        is_empty = true; 

    // definitely not full any more 
    is_full = false;       

    return ret; 
}

template <class T>
void Queue<T>::print_queue() { 
    cout << "[\t"; 
    for (int i = 0; i < SIZE; i++)
        cout << q[i] << "\t"; 
    cout << "]" << endl; 

    cout << " \t"; 
    for (int i = 0; i < SIZE; i++) 
        cout << i << "\t"; 
    cout << " " << endl; 

    cout << " "; 
    for (int i = 0; i <= in ; i++) 
        cout << "\t"; 
    cout << "^in" << endl;

    cout << " "; 
    for (int i = 0; i <= out; i++) 
        cout << "\t"; 
    cout << "^out" << endl;

    pause(); 
}

// stuff from Queue lecture goes here ... then apply template on it 


//
//
class Writer { 

	public:
	void process_file(string filename, Queue<string> *q);    // fill stuff here 
}; 
//// method definitions for Writer class here 


void Writer::process_file(string filename, Queue<string> *q){
	fstream out; 
	out.open(filename.c_str());
	string l;
	while(!out.eof())
	{
	getline(out,l);
	q->enqueue(l);
	}
}
class Reader { 
	public:
		void process_queue(Queue<string> *q);
//    // fill stuff  here 
};
//// method definitions for Reader class here 

void Reader::process_queue(Queue<string>*q){
	for(int i=0;i<SIZE;i++){
		string l=q->dequeue();
		cout<<l.length()<<endl;
	}
}


int main() { 
    Queue<string> *que; 
    que = new Queue<string>; 

    string filename = "string-collection.txt"; 

    Writer first_writer; 
    Reader first_reader; 

    first_writer.process_file(filename, que); 
    first_reader.process_queue(que); 

    return 0;    try { 


        // let's dequeue a few 
        cout << endl << "Now dequeue ... " << endl; 
        cout << "Got val: " << que.dequeue() << endl;   que.print_queue(); 
        cout << "Got val: " << que.dequeue() << endl;   que.print_queue(); 
        cout << "Got val: " << que.dequeue() << endl;   que.print_queue(); 
        cout << "Got val: " << que.dequeue() << endl;   que.print_queue(); 

        cout << "Got val: " << que.dequeue() << endl;    que.print_queue(); 
     //   cout << "Got val: " << que.dequeue() << endl;    que.print_queue();      // doesn't work 


    } catch (const char *msg) { 
        cout << msg << endl; ; 
    }
}
