using namespace std;

//checking does type A object belong to certain vector
template<class A>
inline bool presentIn(vector<A> vect,A value)
{
    return find(vect.begin(), vect.end(), value) != vect.end();
}

//choice one elemnt of A type vector and return it
template<class A>
inline A choiceRandOf(vector<A> inArr)
{
    auto size = inArr.size(); 
    return inArr[rand()%size];
}

//time in milliseconds for generate random seed
uint64_t timeSinceEpochMillisec() {
  using namespace std::chrono;
  return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}
