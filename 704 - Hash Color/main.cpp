//
//  main.cpp
//  704 - Hash Color
//
//  Created by Dalai Ribeiro on 24/04/17.
//  Copyright © 2017 Dalai Ribeiro. All rights reserved.
//

//
//  main.cpp
//  704 - Hash Colour
//
//  Created by Dalai Ribeiro on 23/04/17.
//  Copyright © 2017 Dalai Ribeiro. All rights reserved.
//

#include <iostream>
#include <map>
#include <queue>

using namespace std;


char temp1, temp2;
map<string, string>m;

string sol;

string move_1(string s)
{
    temp1 = s[10];
    temp2 = s[11];
    for (int i = 11; i >= 2; i--) s[i] = s[i-2];
    s[0] = temp1;
    s[1] = temp2;
    
    s[21] = s[9];
    s[22] = s[10];
    s[23] = s[11];
    return s;
}

string move_2(string s  )
{
    temp1 = s[12];
    temp2 = s[13];
    for (int i = 14; i <= 23; i++) s[i-2] = s[i];
    s[22] = temp1;
    s[23] = temp2;
    
    s[9] = s[21];
    s[10] = s[22];
    s[11] = s[23];
    return s;
}

string move_3(string s)
{
    temp1 = s[0];
    temp2 = s[1];
    for (int i = 2; i <= 11; i++) s[i-2] = s[i];
    s[10] = temp1;
    s[11] = temp2;
    
    s[21] = s[9];
    s[22] = s[10];
    s[23] = s[11];
    return s;
}

string move_4(string s)
{
    temp1 = s[22];
    temp2 = s[23];
    for (int i = 23; i >= 14; i--) s[i] = s[i-2];
    s[12] = temp1;
    s[13] = temp2;
    
    s[9] = s[21];
    s[10] = s[22];
    s[11] = s[23];
    return s;
}




int main()
{
    int c, i;
    string s, sol;
    
    std::queue<string> wheel;
    std::queue<string> seq;
    std::queue<int> prev;
    
    scanf("%d",&c); // Lê os quantos casos testes
    
    for (i = 0; i < c; i++) // Repete o programa c vezes
    {
        for (int j=0; j<wheel.size(); j++){
            wheel.pop();
            seq.pop();
            prev.pop();
        }
        string s = "";  //Esvazia
        sol = "";
        
        for (int i = 0; i < 24; i++)
        {
            int a=-1;
            scanf("%d",&a);
            if(a == 10)    //Transforma o numero dez em a para melhor representação em string
                s += 'a';
            else
                s += '0' + a; // Transforma inteiros em string
        }
        
        if(s == "034305650121078709a90121"){
            cout << "PUZZLE ALREADY SOLVED" << endl;
        }
        else
        {
            
            wheel.push(s);
            seq.push("");
            prev.push(0);
            
            while(true){
                
                
                if ((prev.front() != 3) || seq.front() != "11111"){
                    seq.push(seq.front()+'1');                                  // Coloca nova sequencia na lista + movimento 1
                    prev.push(1);                                               // Salva o prev pra cortar a arvore
                    wheel.push(move_1(wheel.front()));                          // Movimenta a wheel
                    if ((move_1(wheel.front()) == "034305650121078709a90121")){
                        sol = seq.front()+'1';                                  //Verifica se wheel esta na posiçao desejada
                        cout << sol << endl;                                    //Imprime soluçao
                        break;
                    }
                }
                
                if ((prev.front() != 4)|| seq.front() != "22222"){
                    seq.push(seq.front()+'2');                                  // Coloca nova sequencia na lista + movimento 2
                    prev.push(2);                                               // Salva o prev pra cortar a arvore
                    wheel.push(move_2(wheel.front()));                          // Movimenta a wheel
                    if ((move_2(wheel.front()) == "034305650121078709a90121")){
                        sol = seq.front()+'2';                                  //Verifica se wheel esta na posiçao desejada
                        cout << sol << endl;                                    //Imprime soluçao
                        break;
                    }
                }
                
                if ((prev.front() != 1) || seq.front() != "33333"){
                    seq.push(seq.front()+'3');                                  // Coloca nova sequencia na lista + movimento 3
                    prev.push(3);                                               // Salva o prev pra cortar a arvore
                    wheel.push(move_3(wheel.front()));                          // Movimenta a wheel
                    if ((move_3(wheel.front()) == "034305650121078709a90121")){
                        sol = seq.front()+'3';                                  //Verifica se wheel esta na posiçao desejada
                        cout << sol << endl;                                    //Imprime soluçao
                        break;
                    }
                }
                
                
                if ((prev.front() != 2) || seq.front() != "44444"){
                    seq.push(seq.front()+'4');                                  // Coloca nova sequencia na lista + movimento 4
                    prev.push(4);                                               // Salva o prev pra cortar a arvore
                    wheel.push(move_4(wheel.front()));                          // Movimenta a wheel
                    if ((move_4(wheel.front()) == "034305650121078709a90121")){
                        sol = seq.front()+'4';                                  //Verifica se wheel esta na posiçao desejada
                        cout << sol << endl;                                    //Imprime soluçao
                        break;
                    }
                }
                prev.pop();
                seq.pop();
                wheel.pop();
                
                long int size;
                sol = seq.front()+'4';
                
                size = sol.size();
                
                if (size > 16){
                    cout << "NO SOLUTION WAS FOUND IN 16 STEPS" << endl;
                    break;
                }
                
                
            }
            
        }
        
    }
    
    return 1;
    
}


