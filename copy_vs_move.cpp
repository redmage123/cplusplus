vector<int> getvec() 
{ 
	vector<int> a, b; 
	if( some_condition ) { a.push_back(123); return a; } 
	else { b.push_back(456); return b; } 
} 
 
int main() {
    vector<int> foo = getvec(); 
}
