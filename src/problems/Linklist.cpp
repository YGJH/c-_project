#include <bits/stdc++.h>
using namespace std;
#define mmax(a, b) (a > b) ? a : b
#define mmin(a, b) (a < b) ? a : b
vector<int> v;
int len;
class Number {
private:
  int number;

public:
  Number(int n) { number = n; }
  int getNumber();
  shared_ptr<Number> next;
  shared_ptr<Number> previous;
};

int Number::getNumber() { return number; }

void printDLLNumber();
shared_ptr<Number> head;
shared_ptr<Number> tail;

void sortDLL() {
  auto tt = head;
  while (tt->next != nullptr) {
    auto hh = head;
    auto now = tt->next;
    while (hh->getNumber() < now->getNumber() && hh != tt) {
      hh = hh->next;
    }
    if (now->getNumber() > hh->getNumber()) {
      now->previous = hh;
      tt = now;
      hh->next = now;
      tail = now;
    } else {
      now->previous = hh->previous;
      if (now->previous != nullptr)
        now->previous->next = now;
      else
        head = now;
      hh->previous = now;
      tt->next = now->next;
      now->next = hh;
    }
    hh.reset();
    now.reset();
  }
}

void printDLLNumber() {
  auto i = head;
  while (i != nullptr) {
    cout << i->getNumber();
    if (i->next != nullptr)
      cout << ' ';
    i = i->next;
  }
  cout << endl;
}

void readInput(vector<int> &v) {
  string line, token;

  getline(cin, line);
  stringstream ss(line);

  int count = 0;
  while (getline(ss, token, ' ')) {
    v.push_back(stoi(token));
  }
}

void makeDLL(vector<int> v) {
  head = make_shared<Number>(v[0]);
  shared_ptr<Number> last = head;
  for (int i = 1; i < len; i++) {
    shared_ptr<Number> tmp = make_shared<Number>(v[i]);
    last->next = tmp;
    tmp->previous = last;
    last = tmp;
    tmp->next = nullptr;
  }
  tail = last;
  head->previous = nullptr;
  return;
}

int main(int argc, char *argv[]) {
  srand(time(NULL));
  readInput(v);
  len = v.size();
  if (len == 0) {
    cout << endl;
    return 0;
  }
  makeDLL(v);
  sortDLL();
  printDLLNumber();
}
