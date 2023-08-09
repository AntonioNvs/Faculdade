#define MAXN 101010

struct No {
	long value;
	No *father;
	int rank;

	No(long value, int rank){
		this->value = value;
		this->father = this;
		this->rank = rank;
	}
};

class ConjuntoDisjunto {
	private:
		No * conj[MAXN];

	public:	
		ConjuntoDisjunto();
		~ConjuntoDisjunto();
		void makeSet(long x);
		void unionSet(long x, long y);
		long findSet(long x);
};
