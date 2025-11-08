#include <iostream>
using namespace std;
class Term {
public:
    int coefficient;
    int exponent;
    Term* next;

    Term(int c, int e) {
        coefficient = c;
        exponent = e;
        next = NULL;
    }
};
void appendTerm(Term*& head, Term*& tail, int c, int e) {
    Term* newTerm = new Term(c, e);

    if (!tail) {  
        head = tail = newTerm;
        return;
    }

    tail->next = newTerm;
    tail = newTerm;
}
void printPolynomial(Term* head) {
    Term* current = head;
    while (current) {
        cout << "[" << current->coefficient << ", " << current->exponent << "]";
        current = current->next;
        if (current) cout << " + ";
    }
    cout << endl;
}
Term* addPolynomials(Term* poly1, Term* poly2) {
    Term* resultHead = NULL;
    Term* resultTail = NULL;

    Term* t1 = poly1;
    Term* t2 = poly2;

    while (t1 && t2) {
        if (t1->exponent > t2->exponent) {
            appendTerm(resultHead, resultTail, t1->coefficient, t1->exponent);
            t1 = t1->next;
        }
        else if (t2->exponent > t1->exponent) {
            appendTerm(resultHead, resultTail, t2->coefficient, t2->exponent);
            t2 = t2->next;
        }
        else {  
            appendTerm(resultHead, resultTail, t1->coefficient + t2->coefficient, t1->exponent);
            t1 = t1->next;
            t2 = t2->next;
        }
    }
    while (t1) {
        appendTerm(resultHead, resultTail, t1->coefficient, t1->exponent);
        t1 = t1->next;
    }

    while (t2) {
        appendTerm(resultHead, resultTail, t2->coefficient, t2->exponent);
        t2 = t2->next;
    }
    return resultHead;
}
int main() {
    Term* poly1 = NULL;
    Term* tail1 = NULL;
    Term* poly2 = NULL;
    Term* tail2 = NULL;
    appendTerm(poly1, tail1, 5, 2);
    appendTerm(poly1, tail1, 4, 1);
    appendTerm(poly1, tail1, 2, 0);
    appendTerm(poly2, tail2, 5, 1);
    appendTerm(poly2, tail2, 5, 0);

    Term* sum = addPolynomials(poly1, poly2);

    cout << "Sum of Polynomials: ";
    printPolynomial(sum);

    return 0;
}