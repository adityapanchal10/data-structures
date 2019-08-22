#include <iostream>
using namespace std;

class poly{
	private:
		struct polynode{
			float coeff;
			int exp;
			polynode *link;
		} *p;
	public:
		poly( );
		void poly_append ( float c, int e );
		void display_poly( ) ;
		void poly_add( poly &l1, poly &l2 );
		void poly_multiply ( poly &p1, poly &p2 );
		void padd ( float c, int e );
		~poly( ) ;
} ;
poly :: poly( ){
	p = NULL;
}
void poly :: poly_append ( float c, int e ){
	polynode *temp = p ;
	if ( temp == NULL ){
		temp = new polynode ;
		p = temp ;
	}
	else{
		while ( temp -> link != NULL )
			temp = temp -> link ;
		temp -> link = new polynode ;
		temp = temp -> link ;
	}
	temp -> coeff = c ;
	temp -> exp = e ;
	temp -> link = NULL ;
}
void poly :: display_poly( ){
	polynode *temp = p ;
	int f = 0 ;
	cout << endl ;
	while ( temp != NULL ){
		if ( f != 0 ){
			if ( temp -> coeff > 0 )
				cout << " + " ;
			else
				cout << " " ;
		}
		if ( temp -> exp != 0 )
			cout << temp -> coeff << "x^" << temp -> exp ;
		else
			cout << temp -> coeff ;
		temp = temp -> link ;
		f = 1 ;
	}
}
void poly :: poly_add ( poly &l1, poly &l2 ){
	polynode *z ;
	if ( l1.p == NULL && l2.p == NULL )
		return ;
	polynode *temp1, *temp2 ;
	temp1 = l1.p ;
	temp2 = l2.p ;
	while ( temp1 != NULL && temp2 != NULL ){
		if ( p == NULL ){
			p = new polynode ;
			z = p ;
		}
		else{
			z -> link = new polynode ;
			z = z -> link ;
		}
		if ( temp1 -> exp < temp2 -> exp ){
			z -> coeff = temp2 -> coeff ;
			z -> exp = temp2 -> exp ;
			temp2 = temp2 -> link ;
		}
		else{
			if ( temp1 -> exp > temp2 -> exp ){
				z -> coeff = temp1 -> coeff ;
				z -> exp = temp1 -> exp ;
				temp1 = temp1 -> link ;
			}
			else{
				if ( temp1 -> exp == temp2 -> exp ){
					z -> coeff = temp1 -> coeff + temp2 -> coeff ;
					z -> exp = temp1 -> exp ;
					temp1 = temp1 -> link ;
					temp2 = temp2 -> link ;
				}
			}
		}
	}
	while ( temp1 != NULL ){
		if ( p == NULL ){
			p = new polynode ;
			z = p ;
		}
		else{
			z -> link = new polynode ;
			z = z -> link ;
		}
		z -> coeff = temp1 -> coeff ;
		z -> exp = temp1 -> exp ;
		temp1 = temp1 -> link ;
	}
	while ( temp2 != NULL ){
		if ( p == NULL ){
			p = new polynode ;
			z = p ;
		}
		else{
			z -> link = new  polynode ;
			z = z -> link ;
		}
		z -> coeff = temp2 -> coeff ;
		z -> exp = temp2 -> exp ;
		temp2 = temp2 -> link ;
	}
	z -> link = NULL ;
}
void poly :: poly_multiply ( poly &p1, poly &p2 ){
	polynode *temp1, *temp2 ;
	float coeff1, exp1 ;
	temp1 = p1.p ;
	temp2 = p2.p ;
	if ( temp1 == NULL && temp2 == NULL )
		return ;
	if ( temp1 == NULL )
		p = p2.p ;
	else{
		if ( temp2 == NULL )
			p = temp1 ;
		else{
			while ( temp1 != NULL ){
				while ( temp2 != NULL ){
					coeff1 = temp1 -> coeff * temp2 -> coeff ;
					exp1 = temp1 -> exp + temp2 -> exp ;
					temp2 = temp2 -> link ;
					padd ( coeff1, exp1 ) ;
				}
				temp2 = p2.p ;
				temp1 = temp1 -> link ;
			}
		}
	}
}
void poly :: padd ( float c, int e ){
	polynode *r, *temp ;
	temp = p ;
	if ( temp == NULL || c > temp -> exp ){
		r = new polynode ;
		r -> coeff = c ;
		r -> exp = e ;
		if ( p == NULL ){
			r -> link = NULL ;
			p = r ;
		}
		else{
			r -> link = temp ;
			p = r ;
		}
	}
	else{
		while ( temp != NULL ){
			if ( temp -> exp == e ){
				temp -> coeff += c ;
				return ;
			}
			if ( temp -> exp > c && ( temp -> link -> exp < c || temp -> link == NULL ) ){
				r = new polynode ;
				r -> coeff = c;
				r -> exp = e ;
				r -> link = NULL ;
				temp -> link = r ;
				return ;
			}
			temp = temp -> link ;
		}
		r -> link = NULL ;
		temp -> link = r ;
	}
}
poly :: ~poly( ){
	polynode *q ;
	while ( p != NULL ){
		q = p -> link ;
		delete p ;
		p = q ;
	}
}

int main( ){
	poly p1 ;
	int cof, pow; 
	cout << "For first polynomial: (-1 to exit)" << endl;
	while(1){
		cout << "Co-efficient: ";
		cin >> cof;
		cout << "Power: ";
		cin >> pow;
		if(cof == -1 && pow == -1)
			break;
		p1.poly_append(cof, pow);
	}
	cout << "\n";
	poly p2 ;
	cout << "For second polynomial: (-1 to exit)" << endl;
	while(1){
		cout << "Co-efficient: ";
		cin >> cof;
		cout << "Power: ";
		cin >> pow;
		if(cof == -1 && pow == -1)
			break;
		p2.poly_append(cof, pow);
	}
	cout << "\nFirst polynomial: " ;
	p1.display_poly( );
	cout << "\n";
	cout << "\nSecond polynomial: ";
	p2.display_poly( );
	cout << "\n";
	poly p3 ;
	p3.poly_add ( p1, p2 ) ;
	cout << "\nAdded polynomial: ";
	p3.display_poly( );
	cout << "\n";
	poly p4;
	p4.poly_multiply(p1, p2);
	cout << "\nMultiplied polynomial: ";
	p4.display_poly( );
	cout << "\n";
}