#include <iostream> 
#include <map> 
using namespace std; 


void output_map(map<int, int> m); 
int get_val(map<int, int> m, int k);  


int main() { 
  
    // empty map container 
    map<int, int> m_ex;             // a map is essentially python's dictionary 
  
    // insert elements in random order 
    m_ex.insert(      pair<int, int>(1, 40)   ); 
    m_ex.insert(pair<int, int>(3, 60)); 
    m_ex.insert(pair<int, int>(6, 50)); 
    m_ex.insert(pair<int, int>(7, 10)); 
    m_ex.insert(pair<int, int>(6, 88));       // insert ignores already existing keys 
     
  
    output_map(m_ex);

    // return 0; 

    m_ex.erase(6); 

    output_map(m_ex);

    cout << "Value for key: 7:  " << m_ex[7] << endl;
    cout << "Value for key: 17: " << m_ex[17] << endl;


    output_map(m_ex);

    // return 0; 
    
    // cout << "Count for 170: " << m_ex.count(170) << endl; 
    // return 0;

    if (m_ex.count(170) > 0) { 
        cout << "Value for key: 170:  " << m_ex[170] << endl; 
    } 
   

    
    return 0; 
} 


void output_map(map<int, int> m) { 
    // map<int, int>::iterator itr;   // specific type returned by m.begin()

    cout << "{" << endl; 
    for (auto itr = m.begin(); itr != m.end(); itr++) { 
        cout << "  " << itr->first << ": " << itr->second << ", " << endl;  
    } 
    cout << "}" << endl; 
}
