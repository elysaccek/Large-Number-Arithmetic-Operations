#ifndef LARGENUMBEROPERATORS_H
#define LARGENUMBEROPERATORS_H

#include <iostream>

namespace lno{
    /** 
    * _fc first number, _sc second number, _rc result number
    * !!! IT ONLY WORKS ON POSITIVE NUMBERS.
    * !!! The result number is resized inside the function and its content is classified.
    * !!! The result number is returned.

    * Usage:
    * firstNumber, secondNumber and resultNumber data types (string)
    * lno::Addition(firstNumber, secondNumber, resultNumber);
    */
    void Addition(std::string _fc, std::string _sc, std::string& _rc){
        int _lf = _fc.length(), _ls = _sc.length(), _max;

        // _max lenght => 999 (3 lenght) + 9999 (4 lenght) = 10998 **(4+1 lenght)**
        if(_lf > _ls)
            _max = _lf+1;
        else
            _max = _ls+1;

        // String => Integer Pointer
        // Resize and Clear
        int* _f = (int*)malloc(sizeof(int) * _lf);
        int* _s = (int*)malloc(sizeof(int) * _ls);
        int* _r = (int*)malloc(sizeof(int) * _max);
        for(int i = 0; i <= _max; i++)
            _r[i] = 0;
        for(int i = 0;i < _lf; i++)
            _f[i] = int(_fc[i]) - 48;
        for(int i = 0;i < _ls; i++)
            _s[i] = int(_sc[i]) - 48;

        /*
        * Integer pointers are used in the operations here.
        */
        int _z = 0, _k = 0, _residual = 0;
        for(int i = _max-1 ;i >= 0 ;i--){
            _k = _residual;
            if(_z <_lf){
                _k += _f[_lf-_z-1];
            }
            if(_z < _ls){
                _k += _s[_ls-_z-1];
            }
            _r[i] = _k%10;
            _residual = _k/10;

            _z++;
        }
        /*
        * Removes leading zeros.
        */
        if(_r[0] == 0){
            for(int i = 0; i < _max - 1; i++)
                _r[i] = _r[i+1];
            _max --;
        }
        _rc = "";
        for(int i = 0; i<_max ;i++){
            _rc.append(std::to_string(_r[i]));
        }
        delete _f;
        delete _s;
        delete _r;
    }

    /** 
    * _fc first number, _sc second number, _rc result number
    * !!! IT ONLY WORKS ON POSITIVE NUMBERS.
    * !!! The result number is resized inside the function and its content is classified.
    * !!! The result number is returned.

    * Usage:
    * firstNumber, secondNumber and resultNumber data types (string)
    * lno::Multiplication(firstNumber, secondNumber, resultNumber);
    */
    void Multiplication(std::string _fc, std::string _sc, std::string& _rc){
        int _stage = 0, _residual = 0, _z = 0;
        int _lf = _fc.length(), _ls = _sc.length();
        int _max = _lf + _ls;

        // String => Integer Pointer
        int* _f = (int*)malloc(sizeof(int) * _lf);
        int* _s = (int*)malloc(sizeof(int) * _ls);
        int* _r = (int*)malloc(sizeof(int) * _max);
        for(int i = 0; i <= _max; i++)
            _r[i] = 0;
        for(int i = 0;i < _lf; i++)
            _f[i] = int(_fc[i]) - 48;
        for(int i = 0;i < _ls; i++)
            _s[i] = int(_sc[i]) - 48;

        /*
                10
            x   10
            ---------
                00      _stage =>   1 0     _z =>   1 0
            +  10       _stage => 2 1 0     _z => 1 0
            ---------
            100
        */

        /*
        * Integer pointers are used in the operations here.
        */
        for(int i = _ls-1 ;i >= 0 ;i--){
            _z = 0;
            for(int j = _lf-1 ;j >= 0 ;j--){
                int k = _residual + _f[j]*_s[i] + _r[_max - 1 - _stage - _z];
                _r[_max - 1 - _stage - _z] = k%10;
                _residual = k/10;
                _z++;
                if(j == 0){
                    _r[_max - 1 - _stage - _z] = _residual;
                    _residual = 0;
                }
            }
            _stage ++;
        }
        /*
        * Removes leading zeros.
        */
        if(_r[0] == 0){
            if(_r[1] == 0){
                _max = 1;
            }else{
                for(int i = 0; i < _max - 1; i++){
                    _r[i] = _r[i+1];
                }
                _max --;
            }
        }
        _rc = "";
        for(int i = 0; i<_max ;i++){
            _rc.append(std::to_string(_r[i]));
        }
        delete _f;
        delete _s;
        delete _r;
    }
}

#endif /* LARGENUMBEROPERATORS_H */