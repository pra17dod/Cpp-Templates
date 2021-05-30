#include <bits/stdc++.h>

class BigInteger{
    private:
        std::vector <unsigned long long int> integer;
    public:
        BigInteger(unsigned long long int n){
            addToBigInteger(n);
        }

        std::vector <unsigned long long int> & addToBigInteger(unsigned long long int n){
            while(n){
                int t = n%10;
                integer.push_back(t);
                n /= 10;
            }
            return integer;
        }

        std::vector <unsigned long long int> & multiply(unsigned long long int n){
            int carry=0;
            for_each(integer.begin(), integer.end(), [&](unsigned long long int &x){
                unsigned long long int temp = x*n + carry;
                x = temp%10;
                carry = temp/10;
            });
            return addToBigInteger(carry);
        };

        unsigned long long int size(){
            return integer.size();
        };
        std::vector<unsigned long long int>::iterator begin(){
            return integer.begin();
        };
        std::vector<unsigned long long int>::iterator end(){
            return integer.end();
        };

        unsigned long long int & at(unsigned long long int &n){
            return integer[n];
        }

        void print(){
            for (auto i= integer.end()-1; i >= integer.begin(); i--){
                std::cout << *i;
            }
            std::cout << std::endl;
        }
};

BigInteger Addition(BigInteger integer1,BigInteger integer2){
            int carry=0;
            BigInteger result = (integer1.size()>=integer2.size())?integer1:integer2;
            BigInteger to_add = (!(integer1.size()>=integer2.size()))?integer1:integer2;
            unsigned long long int count=0;
            for_each(to_add.begin(), to_add.end(), [&](unsigned long long int &x){
                unsigned long long int temp = x + result.at(count)+ carry;
                result.at(count) = temp%10;
                carry = temp/10;
                count++;
            });
            while(carry){
                if(count > result.size()){
                    result.at(count)=0;
                }
                unsigned long long int temp = result.at(count)+ carry;
                result.at(count) = temp%10;
                carry = temp/10;
                count++;
            }

            return result;
        };

BigInteger Difference(BigInteger integer1,BigInteger integer2){
            int carry=0;
            BigInteger result = (integer1.size()>=integer2.size())?integer1:integer2;
            BigInteger to_add = (!(integer1.size()>=integer2.size()))?integer1:integer2;
            unsigned long long int count=0;
            for_each(to_add.begin(), to_add.end(), [&](unsigned long long int &x){
                unsigned long long int temp = x + result.at(count)+ carry;
                result.at(count) = temp%10;
                carry = temp/10;
                count++;
            });
            while(carry){
                if(count > result.size()){
                    result.at(count)=0;
                }
                unsigned long long int temp = result.at(count)+ carry;
                result.at(count) = temp%10;
                carry = temp/10;
                count++;
            }

            return result;
        };


int main(){

    //Implementing basic mathematical operations
    unsigned long long int number = 11111111111;
    BigInteger myno(number);
    myno.print();
    BigInteger shyno(2222222222);
    shyno.print();
    // BigInteger sum = Addition(myno,shyno);
    for(int i=1; i<=100; i++ ){
        myno.multiply(i);
    }
    myno.print();

    return 0;
}