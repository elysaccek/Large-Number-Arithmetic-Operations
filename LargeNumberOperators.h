#ifndef LARGENUMBEROPERATORS_H
#define LARGENUMBEROPERATORS_H

#include <iostream>
#include <cstring>

namespace lno{
    void _removeLeadingZero(std::string& _in);
    void Addition(std::string _fc, std::string _sc, std::string& _rc);
    void Subtraction(std::string _fc, std::string _sc, std::string& _rc);

    /**
     * Removes all leading zeros from numbers.
    */
    void _removeLeadingZero(std::string& _in){
        if(_in[0] == '0'){
            int _size = _in.length();
            std::string _new = "";
            for(int i = 0; i < _size-1; i++)
                _new += _in[i+1];
            _in = _new;
            _removeLeadingZero(_in);
        }
    }

    /** 
    * _fc first number, _sc second number, _rc result number
    * !!! The result number is resized inside the function and its content is classified.
    * !!! The result number is returned.

    * Usage:
    * firstNumber, secondNumber and resultNumber data types (string)
    * lno::Addition(firstNumber, secondNumber, resultNumber);
    */
    void Addition(std::string _fc, std::string _sc, std::string& _rc){
        if((_fc[0] == '-' && _sc[0] == '-') || (_fc[0] != '-' && _sc[0] != '-')){
            int _lf = _fc.length(), _ls = _sc.length(), _max;

            // Check for negative result
            bool _negative = false;
            if(_fc[0] == '-' && _sc[0] == '-'){
                _negative = true;
                _fc[0] = '0';
                _sc[0] = '0';
            }
            // _max lenght => 999 (3 lenght) + 9999 (4 lenght) = 10998 **(4+1 lenght)**
            if(_lf > _ls)
                _max = _lf+1;
            else
                _max = _ls+1;

            // String => Integer Pointer
            // Resize and Clear
            int _f[_lf],_s[_ls],_r[_max];

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
            _rc = "";
            for(int i = 0; i<_max ;i++)
                _rc.append(std::to_string(_r[i]));
            
            _removeLeadingZero(_rc);

            if(_negative)
                _rc.insert(0,"-");
        }
        // Subtraction function
        else{
            _rc = "";
            if(_fc[0] == '-'){
                _fc[0] = '0';
                Subtraction(_sc,_fc,_rc);
            }else{
                _sc[0] = '0';
                Subtraction(_fc,_sc,_rc);
            }
        }
    }

    /** 
    * _fc first number, _sc second number, _rc result number
    * !!! The result number is resized inside the function and its content is classified.
    * !!! The result number is returned.

    * Usage:
    * firstNumber, secondNumber and resultNumber data types (string)
    * lno::Subtraction(firstNumber, secondNumber, resultNumber);
    */
    void Subtraction(std::string _fc, std::string _sc, std::string& _rc){
        if((_fc[0] == '-' && _sc[0] == '-') || (_fc[0] != '-' && _sc[0] != '-')){
            int _neg = 0;
            if(_fc[0] == '-' && _sc[0] == '-'){
                _neg = 1;
                _fc[0] = '0';
                _sc[0] = '0';
            }
            
            _removeLeadingZero(_fc);
            _removeLeadingZero(_sc);

            int _lf = _fc.length(), _ls = _sc.length(), _max;
            
            // String => Integer Pointer
            // Resize and Clear
            int _f[_lf], _s[_ls];

            for(int i = 0;i < _lf; i++)
                _f[i] = int(_fc[i]) - 48;
            for(int i = 0;i < _ls; i++)
                _s[i] = int(_sc[i]) - 48;
            
            // first > second _fs = 0
            // first < seconf _fs = 1
            int _fs = 0;
            if(_lf > _ls){
                _max = _lf;
                _fs = 0;
            }
            else if(_lf == _ls){
                _max = _ls;
                for(int i = 0; i<_max; i++){
                    if(_f[i] > _s[i]){
                        _fs = 0;
                        break;
                    }else if(_f[i] < _s[i]){
                        _fs = 1;
                        break;
                    }
                }
            }else{
                _max = _ls;
                _fs = 1;
            }

            int _r[_max];
            for(int i = 0; i <= _max; i++)
                _r[i] = 0;

            // Math
            int _z = 0, _k = 0, _residual = 0;
            int _first, _second;
            for(int i = _max-1 ;i >= 0 ;i--){
                if(_ls-_z-1 >= 0){
                    _second = _s[_ls-_z-1];
                }else{
                    _second = 0;
                }
                if(_lf-_z-1 >= 0){
                    _first = _f[_lf-_z-1];
                }else{
                    _first = 0;
                }
                if(_fs == 0){
                    if(_first - _residual < _second){
                        _k = 10 + _first - _second - _residual;
                        _residual = 1;
                    }else{
                        _k = _first - _second - _residual;
                        _residual = 0;                   
                    }
                }else{
                    if(_second - _residual < _first){
                        _k = 10 + _second - _first - _residual;
                        _residual = 1;
                    }else{
                        _k = _second - _first - _residual;
                        _residual = 0;                   
                    }                
                }
                _r[i] = abs(_k);
                _z++;
            }

            /*
            * Removes leading zeros.
            */
            int _remove = 0;
            while (_r[_remove] == 0)
                _remove++;

            _rc = "";
            if(_fs == 1 && _neg != 1)
                _rc.append("-");
            else if(_fs != 1 && _neg == 1)
                _rc.append("-");
            for(int i = _remove; i<_max ;i++)
                _rc.append(std::to_string(_r[i]));               
        }
        // Addition function
        else{
            _rc = "";
            if(_fc[0] == '-'){
                _sc.insert(0,"-");
                Addition(_sc,_fc,_rc);
            }else{
                _sc[0] = '0';
                Addition(_fc,_sc,_rc);
            }
        }
    }

    /** 
    * _fc first number, _sc second number, _rc result number
    * !!! The result number is resized inside the function and its content is classified.
    * !!! The result number is returned.

    * Usage:
    * firstNumber, secondNumber and resultNumber data types (string)
    * lno::Multiplication(firstNumber, secondNumber, resultNumber);
    */
    void Multiplication(std::string _fc, std::string _sc, std::string& _rc){
        int _stage = 0, _residual = 0, _z = 0;

        // Check for negative result
        bool _negative = false;
        if((_fc[0] == '-' && _sc[0] != '-') || (_fc[0] != '-' && _sc[0] == '-')){
            _negative = true;
        }

        if(_fc[0] == '-')
            _fc[0] = '0';
        if(_sc[0] == '-')
            _sc[0] = '0';

        _removeLeadingZero(_fc);
        _removeLeadingZero(_sc);
        
        int _lf = _fc.length(), _ls = _sc.length();
        int _max = _lf + _ls;

        // String => Integer Pointer
        int _f[_lf],_s[_ls],_r[_max];
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
                _negative = false;
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
            if(_negative && i == 0)
                _rc.append("-");
            _rc.append(std::to_string(_r[i]));
        }
    }
}

#endif /* LARGENUMBEROPERATORS_H */