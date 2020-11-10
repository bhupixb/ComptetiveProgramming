const int maxn = 1e3 + 5;
struct BIT{
	// choose one of array or vector
    int arr[maxn][maxn];
    // vector<vector<int>> arr;
    public :
    BIT() { 
    	// arr.assign(maxn, vector<int>(maxn)); 
    }
    void validate(int r, int c) {
    	assert(r >= 0 and r < maxn);
    	assert(c >= 0 and c < maxn);
    }
    void add( int x, int y, int val ){
		validate(x, y);
	    while(x < maxn) {
	        int yy = y;
            while(yy < maxn) {
                arr[x][yy] += val;
                yy += (yy & -yy);
            }
            x += (x & -x) ;
        }
    }
    int getFromTopLeft(int x, int y) {
    	validate(x, y);
        int sum = 0;
        while(x > 0) {
            int yy = y;
                while( yy > 0) {
                    sum += arr[x][yy];
                    yy -= (yy & -yy);
                }
            x -= (x & -x);
        }
	    return sum;
    }
    int sumOfRectangle(int r1, int c1, int r2, int c2) {
        assert(r1 <= r2 and c1 <= c2);
        int sum = getFromTopLeft(r2, c2);
	    sum += getFromTopLeft(r1 - 1, c1 - 1);
        sum -= getFromTopLeft(r1 - 1, c2);
        sum -= getFromTopLeft(r2, c1 - 1);
        return sum;
    }
};

