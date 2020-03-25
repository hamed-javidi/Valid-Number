class Solution {
public:
    char state;
    
    bool isNumber(string s) {
        state=0;
        bool valid;
        for(auto const &i : s){
            valid=0;
            switch(state){
                case 0:
                    if(i=='+'|| i=='-' )
                        state=8;
                    else if(i=='e' )
                        return 0;
                    else if(i==' ')
                        state=0;
                    else if( i=='.')
                        state=10;
                    else if(i >= 48 && i<=57)
                    {
                        state=1;
                        valid=1;
                    }
                    else
                        return 0;
                    break;
                case 1:
                    if(i=='.')
                    {
                        state=6;
                        valid=1;
                    }
                    else if(i=='e')
                        state=2;
                    else if(i=='+' || i=='-' )
                        return 0;
                    else if(i==' ')
                    {
                        state=9;
                        valid=1;
                    }
                    else if(i >= 48 && i<=57)
                    {
                        state=1;
                        valid=1;
                    }
                    else
                        return 0;
                    break;
                
                case 2:
                    if( i==' ' || i=='e' || i=='.')
                        return 0;
                    else if(i >= 48 && i<=57)
                    {
                        state=3;
                        valid=1;
                    }
                    else if(i=='+' || i=='-')
                        state=3;
                    else
                        return 0;  
                    break;
                case 3:
                    if(i=='.')
                        return 0;                   
                    else if(i=='+' || i=='-'  || i=='e')
                        return 0;
                    else if(i >= 48 && i<=57)
                    {
                        state=3;
                        valid=1;
                    }
                    else if( i==' ')
                    {
                        state=9;
                        valid=1;
                    }
                    else
                        return 0;
                    break;
                case 4:
                     if(i=='+' || i=='-'  || i=='e' || i=='.')
                        return 0;
                     else if( i==' ')
                    {
                        state=9;
                        valid=1;
                    }
                    else if(i >= 48 && i<=57)
                    {
                        state=5;
                        valid=1;
                    }
                    else
                        return 0;
                    break;
                case 5:
                    if(i=='+' || i=='-' || i==' ' || i=='e' || i=='.')
                        return 0;
                    else if(i >= 48 && i<=57)
                    {
                        state=5;
                        valid=1;
                    }
                    else
                        return 0;
                    break;
                case 6:
                    if(i=='+' || i=='-'  || i=='.')
                        return 0;
                    else if( i==' ')
                    {
                        state=9;
                        valid=1;
                    }
                    else if(i >= 48 && i<=57)
                    {
                        state=7;
                        valid=1;
                    }
                    else if( i=='e' )
                        state=2;
                    else
                        return 0;
                    break;
                case 7:
                    if(i=='+' || i=='-'  || i=='.')
                        return 0;
                    else if(i=='e')
                        state=2;
                    else if(i==' ')
                    {
                        state=9;
                        valid=1;
                    }
                    else if(i >= 48 && i<=57)
                    {
                        state=7;
                        valid=1;
                    }
                    else
                        return 0;
                    break;
                case 8:
                    if(i=='+' || i=='-' || i==' ' || i=='e' )
                        return 0;
                    else if(i >= 48 && i<=57)
                    {
                        state=1;
                        valid=1;
                    }
                    else if(i=='.')
                        state=10;
                    else
                        return 0;  
                    break;
                case 9:
                    if(i==' ')
                    {
                        state=9;
                        valid=1;
                    }
                    else
                        return 0;
                    break;
                case 10:
                     if(i=='+' || i=='-' || i==' ' || i=='e' || i=='.')
                        return 0;
                     else if(i >= 48 && i<=57)
                     {
                        state=7;
                         valid=1;
                     }
                    else
                        return 0;
                    break;
            }
        }
        return valid;
    }
};
