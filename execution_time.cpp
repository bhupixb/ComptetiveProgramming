using namespace chrono;

auto start1 = high_resolution_clock::now();   

// Here comes the code 
// This will only calculate the time to execute current block of code

auto stop1 = high_resolution_clock::now(); 
cout << setw(20) << "Estimated Time: " << duration_cast<microseconds>(stop1 - start1).count() / 1000000.0    << " uS\n";
